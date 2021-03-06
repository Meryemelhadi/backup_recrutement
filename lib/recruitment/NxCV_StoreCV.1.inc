<?php

/*

 CALLED FROM SOAP SERVER 
 for submitting a cv to local DB.

*/

require_once(NX_XLIB.'lib/framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');
require_once(GENERIS_ROOT.'nx/conf/packages/recruitment/lib/email/NxRecruitment_Email.inc');


/* application */
class NxCV_StoreCV
{
	function NxCV_StoreCV($config,$fs) {
		$this->config = $config;
		$this->fs = $fs;
	}

	// obsolete
	function storeCV($cv)
	{
		$oCV = $cv->object;
		$files['cv'] = $cv->message->fpathPDF;

		$method = $this->config->getProperty('cv_store.mode','local');
		if ($method=='local')
		{
			$oid=null;$isNew=null;
			return $this->storeCVObject($oCV,$files,null,$oid,$isNew);
		}
		else
			return $this->storeRemoteCV($oCV,$files);
	}
	
	function newCandidateNotification($candidate_oid) {
		
		$ctxt = Framework::getContext();
		
		
		$ctxt->setProperty('page.strings','recruitment_candidates_directory_fr@recruitment');
		
		//Framework::getString($str,'fr','recruitment_candidates_directory_fr@recruitment');
		$ctxt->setProperty("candidate_oid",$candidate_oid);
		$message = $ctxt->getRecord('rct_candidate.email_notification@recruitment','page.record','db',false,null,null);
		
		

		$emails = explode(';', $message->email->db);
		if( $emails[0] == '' ) {
			return false;
		}
		
		$email = new NxRecruitment_Email($ctxt);		
		for($i=0; $i<count($emails);$i++) {
			$message->to->db = $emails[$i];
			$message->subject->db = $ctxt->getString("new_candidate_email_subject");
			$message->body->db = $email->getEmailBody('new_candidate_email_notification@recruitment');
			$email->send($message);
		}
	}
	
	function associateWithVacancy($candidate_oid, $subject) {

		$ctxt = Framework::getContext();
		if( ! preg_match('/\[(.+)-(.+)\]/is', $subject, $matches) ) {
			return false;
		}
		
		$providerCode = $matches[1];
		$vacancyCode = $matches[2];
		
		$ctxt->setProperty("provider_code",$providerCode);
		$ctxt->setProperty("vacancy_code",$vacancyCode);	
		
		// On recherche l'association dossier/fournisseur
		$relationRecord = $ctxt->getRecord('rct_vacancy_provider.find_relation@recruitment','page.record','db',false,null,null);
		
		// On cr�e la relation si elle n'existe pas
		if( ! $relationRecord ) {			
			// R�cup�ration de l'oid du dossier
			$vacancyRecord = $ctxt->getRecord('rct_vacancy.find_by_code@recruitment','page.record','db',false,null,null);
			if( ! $vacancyRecord ) {
				return false;
			}
			$ctxt->setProperty("vacancy_oid",$vacancyRecord->oid->db);
			
			// r�cup�ration de l'oid du provider
			$providerRecord = $ctxt->getRecord('rct_provider.find_by_code@recruitment','page.record','db',false,null,null);
			if( ! $providerRecord ) {
				return false;
			}
			$ctxt->setProperty("provider_oid",$providerRecord->oid->db);
			// New relation record
			$relationRecord = new PersistentObject('rct_vacancy_provider.cron_add@recruitment','empty');
			$relationRecord->provider_oid = $providerRecord->oid->db;
			$relationRecord->store('rct_vacancy_provider.cron_add@recruitment','insert','db');
			
			
		} else {
			$ctxt->setProperty("vacancy_oid",$relationRecord->vacancy_oid->db);
			$ctxt->setProperty("provider_oid",$relationRecord->provider_oid->db);
		}
				
		// V�rifie si le candidat n'est pas d�j� associ� au dossier
		$ctxt->setProperty("candidate_oid",$candidate_oid);

		
		// Tentative de r�cup�ration de l'association dossier/candidat
		$candidateVacancyRecord = $ctxt->getRecord('rct_candidate_vacancy.get_assoc@recruitment','page.record','db',false,null,null);
		// On cr�e l'association si elle n'existe pas
		if( ! $candidateVacancyRecord ) {
			$candidateVacancyRecord = new PersistentObject('rct_candidate_vacancy.add_assoc@recruitment','empty');	
			$candidateVacancyRecord->store('rct_candidate_vacancy.add_assoc@recruitment','insert','db');
		}
		
		// On met � jour l'association en indiquant la provenance du CV avec l'oid du fournisseur	
		$ctxt->putRecord($null=null,'rct_candidate_vacancy.update_provider@recruitment','update','db','Object',null);
	}

	// obsolete
	// CALL SOAP SERVER FOR STORING CV
	function storeRemoteCV($oCV,$files)
	{

		// get CV files and encode them in B64
		foreach($files as $key=>$filePath) {
			$fileContent=$this->fs->file_get_contents($filePath,'rb');
			$b64fileContent=base64_encode($fileContent);
			$filesB64[$key] = $b64fileContent;
		}

		// call server storeCV()
		include_once(NX_DIS.'nusoap/lib/nusoap.php');
		$soap_url = $this->config->getProperty('cv_store.remote.soap.url');
		$client = new nusoap_client($soap_url,false);

		// if(!isset($_COOKIE['DBGSESSID']))	$client->setCookie('DBGSESSID', '335639@clienthost:7869;d=1,p=0,c=0');

		$parametres = array(
			'cvJSON'=>json_encode($oCV),
			'filesJSON'=>json_encode($filesB64)
			);
		$res = $client->call('storeCV', $parametres,true);

		if ($res)
			$res = json_decode($res);

		echo nl2br(htmlentities($client->responseData));

		if ($res=='ok')
			return true;
		else
			return false;

	}


	// ======================== STORE to DB =======================

	function storeCVObject($oCV,$files,$filesContent,&$oid,&$isNew)
	{
		$package = '@recruitment';

		//recuperer le subject pour gerer les dossiers
		$subject = $oCV->message->headers->subject;

		// renvoyer un email

		// doublons : email, telephone, nom, prenom
		$oid = $this->getCVRecord($oCV);

		if ($oid === null)
		{
			$cvRec = $this->storeNewCV($oCV);
			$isNew = true;
			
			// Notification du candidat par email
			$this->newCandidateNotification($cvRec->oid->object);
		}
		else
		{
			$cvRec = $this->storeExistingCV($oid,$oCV);
			$isNew = false;
		}

		$oid = $cvRec->oid->object;
		$this->associateWithVacancy($oid,$subject);

		if ($filesContent)
			$this->storeCVFile($oCV,$files['cv'],$cvRec,$filesContent['cv']);

		return true;
	}


	function getCVRecord($oCV) {
		$package = '@recruitment';

		// doublons : email, telephone, nom, prenom
		$cvRec = new PersistentObject('rct_candidate.searchRecords'.$package,'db',
			array(
				'firstName'=>$oCV->person->firstName,
				'lastName'=>$oCV->person->lastName,
				'email'=>$oCV->person->emails[0],
			)
		);

		if ($cvRec->isOk())
			return $cvRec->oid->object;
		else
			return null;
	}

	function storeCVFile($oCV,$fpath,$cvRec,$fileContent=null)
	{
		$package = '@recruitment';

		if (!$fpath)
			$fpath = 'cv.pdf';

		$fromPath  = $fpath;
		$oid = $cvRec->oid->object;
		$toDir = "packages/recruitment/candidates/directory/{$oid}/cv/";
		if ($fileContent)
			$cvRec->cv_path->readFromFile($fromPath,$toDir,false,$fileContent);

		// update CV
		$cvRec->store('rct_candidate.import.record'.$package,'update','db',array('oid'=>$oid));

		$path = $cvRec->cv_path->path;
		$folderPath=dirname($path).'/';
		$fileName=basename($path);

		$this->convertToSwf($folderPath, $fileName);
	}

	function convertToSwf($folderPath, $fileName) {
		
		if( is_file($filePath.'.swf') ) {
			@unlink($filePath.'.swf');
		}

		$filePath = $folderPath.$fileName;
		$pathParts = pathinfo($filePath);
		if( $pathParts['extension'] == 'pdf' ) {

			// Chemin de l'ex�cutable (@todo : � mettre en property syst�me)
			$pPath = '/opt/local/bin/pdf2swf';

			if (!is_file($pPath))
				return false;
						
			// Options de conversion (Par d�faut)
			$options = '-q -t -T 9 -G -f';
			// On essaye de convertir le fichier en gardant un rendu optimal
			exec($pPath .' '.$options.' "'. $filePath .'" -o "'.$filePath.'.swf"');
			
			if( ! is_file($filePath.'.swf') ) {
				// Le fichier n'a pas �t� cr�� (Probl�me sous Mac/Linux). On essaye de le recr�er en convertissant texte et images en bitmap
				$fOptions = $options . ' -O 2';
				exec($pPath .' '.$fOptions.' "'. $filePath .'" -o "'.$filePath.'.swf"');
			}
						
		}
				
	}

	function storeNewCV($oCV)
	{
		$package = '@recruitment';

		// stocker les fichers candidats dans le repertoire cible

		// create CV
		$cvRec = new PersistentObject('rct_candidate.import.record'.$package,'empty');

		if (isset($oCV->message->date))
		{
			$cvRec->add_date->db = $oCV->message->date;
			$cvRec->update_date->db = $oCV->message->date;
		}
 
		$this->fillCVRec($cvRec,$oCV);

		// store the CV and get its oid
		$cvRec->store('rct_candidate'.$package,'insert','db',null);
		$cvRec->oid = $cvRec->getLastInsertId('db');


		// add languages
		foreach($oCV->languages as $item) 
		{
			$itemRec = new PersistentObject('rct_candidate_language.record'.$package,'empty');
			$this->fillLang($cvRec,$oCV,$itemRec,$item);
			$itemRec->store('rct_candidate_language.record'.$package,'insert','db',null);
		}

		// create experiences
		foreach($oCV->jobs as $item) 
		{
			$itemRec = new PersistentObject('rct_employment.employment_record'.$package,'empty');
			$this->fillExperience($cvRec,$oCV,$itemRec,$item);
			$itemRec->store('rct_employment.employment_record'.$package,'insert','db',null);
		}

		// create training
		foreach($oCV->trainings as $item) 
		{
			$itemRec = new PersistentObject('rct_employment.training_record'.$package,'empty');
			$this->fillTraining($cvRec,$oCV,$itemRec,$item);
			$itemRec->store('rct_employment.training_record'.$package,'insert','db',null);
		}

		// create education
		foreach($oCV->courses as $course) 
		{
			$itemRec = new PersistentObject('rct_education.record'.$package,'empty');
			$this->fillEducation($cvRec,$oCV,$itemRec,$course);
			$itemRec->store('rct_education.record'.$package,'insert','db',null);
		}

		// update CV
		$cvRec->store('rct_candidate.import.record'.$package,'update','db',null);

		return $cvRec;
	}

	function storeExistingCV($oid,$oCV)
	{
		$package = '@recruitment';

		// stocker les fichers candidats dans le repertoire cible

		// get CV Record
		$cvRec = new PersistentObject('rct_candidate.import.record'.$package,'db',array('oid'=>$oid));

		if (isset($oCV->message->date))
		{
			$cvRec->update_date->db = $oCV->message->date;

			if ($cvRec->add_date->time > $cvRec->update_date->time)
				$cvRec->add_date->db = $oCV->message->date;
		}

		$this->fillCVRec($cvRec,$oCV);

		// cleanup sub records
		$this->deleteSubRecords($oid,$oCV);

		// add languages
		foreach($oCV->languages as $item) 
		{
			$itemRec = new PersistentObject('rct_candidate_language.record'.$package,'empty');
			$this->fillLang($cvRec,$oCV,$itemRec,$item);
			$itemRec->store('rct_candidate_language.record'.$package,'insert','db',null);
		}

		// create experiences
		foreach($oCV->jobs as $item) 
		{
			$itemRec = new PersistentObject('rct_employment.employment_record'.$package,'empty');
			$this->fillExperience($cvRec,$oCV,$itemRec,$item);
			$itemRec->store('rct_employment.employment_record'.$package,'insert','db',null);
		}

		// create training
		foreach($oCV->trainings as $item) 
		{
			$itemRec = new PersistentObject('rct_employment.training_record'.$package,'empty');
			$this->fillTraining($cvRec,$oCV,$itemRec,$item);
			$itemRec->store('rct_employment.training_record'.$package,'insert','db',null);
		}

		// create education
		foreach($oCV->courses as $course) 
		{
			$itemRec = new PersistentObject('rct_education.record'.$package,'empty');
			$this->fillEducation($cvRec,$oCV,$itemRec,$course);
			$itemRec->store('rct_education.record'.$package,'insert','db',null);
		}

		// update CV
		$cvRec->store('rct_candidate.import.record'.$package,'update','db',array('oid'=>$oid));

		return $cvRec;
	}

	function deleteSubRecords($coid,$oCV)
	{
		$package = '@recruitment';
		$col = new PersistentCollection();
		$col->delete('rct_candidate_language.list'.$package,'db',array('oid'=>$coid));
		$col->delete('rct_employment.employment_list'.$package,'db',array('oid'=>$coid));
		$col->delete('rct_employment.training_list'.$package,'db',array('oid'=>$coid));
		$col->delete('rct_education.list'.$package,'db',array('oid'=>$coid));
	}
	
	function replaceAccents($str) {
		return str_replace( array('�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�', '�','�','�','�','�','�','�','�','�','�','�'), array('a','a','a','a','a','c','e','e','e','e','i','i','i','i','n','o','o','o','o','o','u','u','u','u','y','y','a','a','a','a','a','c','e','e','e','e','e','i','i','i','i','n','o','o','o','o','o','u','u','u','u','y'), $str);
	}

	function fillCVRec($cvRec,$oCV) 
	{
		$cvRec->first_name = $oCV->person->firstName;
		$cvRec->last_name = $oCV->person->lastName;
		//$cvRec->civility = ''; // pas recuper?
		//$cvRec->gender = '';   // pas encore recuper?
		$cvRec->date_of_birth = $oCV->person->dob;
		$cvRec->nationality = $oCV->nationality;

		// plusieurs emails possibles
		if (count($oCV->person->emails) > 0)
			$cvRec->email = implode(';',$oCV->person->emails);
		else
			$cvRec->email = '';

		// telephones : a revoir les regles pour d?cider que c'est un mobila?
		if (count($oCV->person->phones) > 0)
			$cvRec->phone_1 = $oCV->person->phones[0];
		else
			$cvRec->phone_1 = '';

		if (count($oCV->person->phones) > 1)
			$cvRec->phone_2 = $oCV->person->phones[1];
		else
			$cvRec->phone_2 = '';

		// $cvRec->mobile = '';

		$cvRec->address = $oCV->person->address;
		$cvRec->zip = $oCV->person->zip;
		
		// $cvRec->country_oid = $oCV->person->;
		
		$cvRec->town_oid->object = $oCV->person->town;

		// $cvRec->category_oid = $oCV->person->;

		if($oCV->experience->nbYearsEst > $oCV->experience->nbYears)
			$cvRec->years_of_practice = $oCV->experience->nbYearsEst;
		else
			$cvRec->years_of_practice = $oCV->experience->nbYears;

		// object -> array (json reverse)
		if (is_object($oCV->profile))
			$oCV->profile = get_object_vars($oCV->profile);

		$profile = implode(',',array_keys($oCV->profile));
		if( trim($profile) != '' )
			$profile = ','.$profile.',';
		$cvRec->profile = $profile;
		
		
		
		$cvRec->studies_level = $oCV->school_level;

		$cvRec->src_text->db = $this->replaceAccents($oCV->src_text);

//		$cvRec->cv_path = utf8_encode($oCV->message->getResumeFile());
//		$cvRec->cl_path = utf8_encode($oCV->message->getLetterFile());
	}

	function fillLang($cvRec,$oCV,$itemRec,$item) {
		$itemRec->candidate_oid->object = $cvRec->oid->object;
		$itemRec->lang->object = $item->code;

		switch($item->level)
		{
			case 'excellent' : $level='4'; break;
			case 'bien' : $level='3'; break;
			case 'moyen' : $level='2'; break;
			case 'niveau moyen' : $level='2'; break;
			case 'notions' : $level='1'; break;
			default : $level='0'; break;
		}
		$itemRec->language_level->object = $level;	
	}

	function fillExperience($cvRec,$oCV,$itemRec,$item) {
		$itemRec->candidate_oid->object = $cvRec->oid->object;
		$itemRec->employment_end_date->db = $item->to;
		$itemRec->employment_start_date->db = $item->from;
		$itemRec->employment_content = $item->description;
		$itemRec->type = '1';
	}

	function fillTraining($cvRec,$oCV,$itemRec,$item) {
		$itemRec->candidate_oid->object = $cvRec->oid->object;
		$itemRec->employment_end_date->db = $item->to;
		$itemRec->employment_start_date->db = $item->from;
		$itemRec->employment_content = $item->description;
		$itemRec->type = '0';
	}

	function addSchool($school) {
		$package = '@recruitment';

		$itemRec = new PersistentObject('rct_school.by_code'.$package,'db',
			array(
				'code'=>$school->code,
			)
		);
		if ($itemRec->isOk())
			return $itemRec;

		$itemRec = new PersistentObject('rct_school'.$package,'empty');
		$itemRec->code= $this->rmCrLf($school->code);
		if ($school->label)
			$itemRec->label=$this->rmCrLf($school->label);
		else
			$itemRec->label=$this->rmCrLf($school->code);

		$itemRec->store('rct_school'.$package,'insert','db',null);
	}

	function addDiploma($diploma) {
		$package = '@recruitment';

		$itemRec = new PersistentObject('rct_diploma.by_code'.$package,'db',
			array(
				'code'=>$diploma->code,
			)
		);
		if ($itemRec->isOk())
			return $itemRec;

		$itemRec = new PersistentObject('rct_diploma'.$package,'empty');
		$itemRec->code=$this->rmCrLf($diploma->code);
		$itemRec->label=$this->rmCrLf($diploma->code);

		$itemRec->store('rct_diploma'.$package,'insert','db',null);
	}
	
	function rmCrLf($str) {
		$str = str_replace(chr(10),"",$str);
		return str_replace(chr(13),"",$str);
	}

	function fillEducation($cvRec,$oCV,$itemRec,$item) {

		// a revoir dans l'analyseur: liens entre diplomes et formations...
		// date debut/fin cot? cvtheque

		$itemRec->candidate_oid->object = $cvRec->oid->object;
		$school = '';
		if (isset($item->schools))
		{
			$itemRec->institution = $school = $this->rmCrLf(implode(',',$item->schools));
		}

		// complete school table
		if (isset($item->schoolsDesc))
		{
			foreach($item->schoolsDesc as $school)
				$this->addSchool($school);
		}

		if (isset($item->diplom))
		{
			$this->addDiploma($item->diplom);

			$itemRec->diploma = $this->rmCrLf($item->diplom->code);
			$level = $item->diplom->level;

			if($level=="0")
			{
				$cvRec->bachelor_year->db = $item->to;
				$cvRec->bachelor_school = $school;
				$itemRec->diploma_type = 'BAC';
			}
			elseif((float)$level < 0)
				$itemRec->diploma_type = 'BAC'.$item->diplom->level;
			else
				$itemRec->diploma_type = 'BAC+'.$item->diplom->level;
		}

		$itemRec->date->db = $item->to;
		$itemRec->description = $item->description;
	}
}

/*
class NxCV_StoreCV_soapClt
{
	function NxCV_StoreCV_soapClt($config,$fs) {
		$this->config = $config;
		$this->fs = $fs;
	}

	function storeCV($cv)
	{
		$oCV = $cv->object;
		$files['cv'] = $cv->fpath;

		foreach($files as $key=>$filePath) {
			$fileContent=$this->fs->file_get_contents($filePath);
			$b64fileContent=base64_encode($fileContent);
			$filesB64[$key] = $b64fileContent;
		}

		$soap_url = $this->config->getProperty('cv_store.remote.soap.url');
		$client = new nusoap_client($soap_url,false);
		$parametres = array(
			'cvJSON'=>json_encode($oCV),
			'filesJSON'=>json_encode($files)
			);
		$res = $client->call('storeCV', $parametres,true);

		if ($res)
			$res = json_decode($res);
	}
}
*/

?>