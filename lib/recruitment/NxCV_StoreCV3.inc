<?php

/*

 CALLED FROM SOAP SERVER 
 for submitting a cv to local DB.

*/

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/email/NxRecruitment_Email.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/denormalisation.inc');

/* application */
class NxCV_StoreCV
{
    var $configMails = null;
	function NxCV_StoreCV($config,$fs) {
		$this->config = $config;
		$this->fs = $fs;
		$this->ctxt = Framework::getContext();
	}

	function getConfig() {
		if ($this->configMails)
			return $this->configMails;
		include_once(NX_LIB.'NxConfig.inc');
		return $this->configMails = NxConfig::getConfig($this->ctxt,'recruitment','clients','recruitment');	
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
	
	function newCandidateNotification($candidate_oid,$bindToVacancy,$isNew,&$log) {
		$ctxt = $this->ctxt;
		
		// client domain
		global $NX_DOMAIN;
		$clientID = $NX_DOMAIN;

		// get config section for our client
		$mainConf = $this->getConfig();
		if (!($cltConf = $mainConf->getSection($clientID))) {
			$log .= "Cant find config for notification<br/>";
			return false;
		}

		// check if account allows email sending
		if (!$cltConf->getProperty('send.notifications',true))
		{
			$log .= "Notification disabled for that account<br/>";
			return false;
		}

		// set properties to be used in email view
		$ctxt->setProperty('page.strings','recruitment_candidates_directory_fr@recruitment');
		$subject    = $cltConf->getString("new_candidate_email_subject",'Accusé de réception de candidature');

		$emailview  = $cltConf->getProperty('email_view','new_candidate_email_notification_default@recruitment');

		$emailview  = $cltConf->getProperty('jobs_board.files.tmp_path',$emailview); // obsolete ?

		$ctxt->setProperty('RECRUITMENT_MAILTITLE',$cltConf->getProperty('RECRUITMENT_MAILTITLE',$GLOBALS['RECRUITMENT_MAILTITLE']));
		$ctxt->setProperty('RECRUITMENT_MAILSUBTITLE',$cltConf->getProperty('RECRUITMENT_MAILSUBTITLE',$GLOBALS['RECRUITMENT_MAILSUBTITLE']));
		$ctxt->setProperty('RECRUITMENT_MAILHTML',$cltConf->getProperty('RECRUITMENT_MAILHTML',''));
		$ctxt->setProperty('email.from',$cltConf->getProperty('email.from',''));
		

		//Framework::getString($str,'fr','recruitment_candidates_directory_fr@recruitment');
		$ctxt->setProperty("candidate_oid",$candidate_oid);
		$message = $ctxt->getRecord('rct_candidate.email_notification@recruitment','page.record','db',false,null,null);

		// get email list
		$emails = explode(';', $message->email->db);
		if( $emails[0] == '' ) {
			$log .= "Cant find email for notification<br/>";
			return false;
		}

		// send emails
		$emailSender = new NxRecruitment_Email($ctxt);		
		for($i=0; $i<count($emails);$i++)
		{
			$email = $emails[$i];
			$log .= "sending email for to $email<br/>";
			$message->to->db = $emails[$i];
			$message->subject->db = $subject;
			$message->body->db = $emailSender->getEmailBody($emailview);
			$emailSender->send($message);
			$log .= "email sent...<br/>";
		}

		return true;
	}

	function getProviderVacancyRecord_byEmail($candidate_oid, $subject, &$log,$oCV) {

		$ctxt = Framework::getContext();

		// On recherche l'association dossier/fournisseur by email
		if(!isset($oCV->message->headers->to))
			return false;

		$toEmail = trim($oCV->message->headers->to);
		if(!$toEmail)
			return false;

		$ctxt->setProperty('email',$toEmail);
		if($relationRecord = $ctxt->getRecord('rct_prestataire_vacancy.search_by_email@recruitment','page.record','db',false,null,null))
		{
			nxLog('getProviderVacancyRecord_byEmail : assoc found','CV');
			return $relationRecord;
		}

		nxLog('getProviderVacancyRecord_byEmail : assoc not found','CV');
	}

	function checksum($year,$oid) {

		return ($year * $oid)%100;
	}

	function getVacancyRecord_byEmail($candidate_oid, $subject, &$log,$oCV) {
		nxLog("getVacancyRecord_byEmail : ...",'CV');

		$ctxt = Framework::getContext();

		// On recherche l'association dossier/fournisseur by email
		if(!isset($oCV->message->headers->to))
			return false;

		$toEmail = trim($oCV->message->headers->to);
		if(!$toEmail)
			return false;

		$ctxt->setProperty('email',$toEmail);

		nxLog("getVacancyRecord_byEmail : check email $toEmail",'CV');

		$code_client = $ctxt->getProperty('recruitment.code_client');
		if(!$code_client)
		{
			$a = explode('.',strtolower($_SERVER['SERVER_NAME']));
			if($a[1]=='presencesoft'||$a[1]=='presencerecrute')
				// editialis.presencerecrute.com
				$code_client = $a[0];
			else
				// xx.editialis.fr
				$code_client = $a[1];
		}
		if(!$code_client)
		{
			$log .= "getVacancyRecord_byEmail : no client code, fallback on any code... !!..<br/>";
			nxError("getVacancyRecord_byEmail : no client code, fallback on any code... !!",'CV');
			$code_client = '^[a-z]+';
			//return false;
		}

		$found = false;

		// editialis_1500690 : year, oid = 006, check = 6*15/100 = 90
		if(
		preg_match("/{$code_client}_([0-9][0-9])([0-9][0-9][0-9])([0-9][0-9])(0[0-2])?@pourcandidature.com/i",$toEmail,$matches) ||
			
		preg_match("/{$code_client}_([0-9][0-9])([0-9][0-9])([0-9][0-9])(0[0-2])?@pourcandidature.com/i",$toEmail,$matches)
			)
		{
			$year = (int)$matches[1];
			$vacancy_oid  = (int)$matches[2];
			$check = (int)$matches[3];
			nxLog("getVacancyRecord_byEmail : match pattern oid={$vacancy_oid}",'CV');

			if($check == $this->checksum($year,$vacancy_oid))
			{
				nxLog("getVacancyRecord_byEmail : check sum ok",'CV');

				$_REQUEST['oid']=$_GET['oid']=$vacancy_oid;

				// Récupération de l'oid du dossier
				$vacancyRecord = $ctxt->getRecord('rct_vacancy.record@recruitment','page.record','db',false,null,null);
				if($vacancyRecord)
					$found = true;
				else
				{
					$log .= "getVacancyRecord_byEmail : vacancy match : vacancy oid :$vacancy_oid not found.. not binding <br/>";

					nxLog("getVacancyRecord_byEmail : vacancy match : vacancy oid :$vacancy_oid not found..",'CV');
					return false;
				}
			}
			else
				nxError('Email check failure, the email is corrupted? '.$toEmail);
		}

		if(!$found)
		{
			nxLog("getVacancyRecord_byEmail : pattern not matched, trying by code...",'CV');

			if(!preg_match("/{$code_client}_([^@]+)@pourcandidature.com/i",$toEmail,$matches))
			{
				$log .= "vacancy match : no binding by email..<br/>";
				nxLog("getVacancyRecord_byEmail : try bind by vancancy code, NO match ..",'CV');
				return false;
			}

			$vacancyCode = $match[1];
			$ctxt->setProperty("vacancy_code",$vacancyCode);	

			nxLog("getVacancyRecord_byEmail : matched by code : $vacancyCode",'CV');

			// Récupération de l'oid du dossier
			$vacancyRecord = $ctxt->getRecord('rct_vacancy.find_by_code@recruitment','page.record','db',false,null,null);
			if(!$vacancyRecord) 
			{
				nxLog("getVacancyRecord_byEmail : vacancy:$vacancyCode not found.. not binding  ..",'CV');
				$log .= "vacancy match : vacancy:$vacancyCode not found.. not binding <br/>";
				return false;
			}

			$vacancy_oid = $vacancyRecord->oid->object;

			$found = true;
		}

		$vacancyCode = $vacancyRecord->code->object;
		nxLog("getVacancyRecord_byEmail : vacancy match OK with $vacancyCode",'CV');

		$ctxt->setProperty("vacancy_oid",$vacancy_oid);
		$log .= "vacancy match : vacancy:{$vacancyRecord->name->object} ($vacancyCode) ok for binding <br/>";

		$this->attachVacancy($vacancy_oid,$candidate_oid,$log,$oCV);
		return true;
	}

	// try finding a reference and/or provider in subject, by trying known patterns used by providers
	// then search the reference in vancancy > reference/provider
	function getProviderVacancyRecord_byReferenceInSubject($candidate_oid, $subject, &$log,$oCV) {
		$ctxt = Framework::getContext();

		// code [VACANCY PROVIDER]
		if(preg_match_all('/\[([^]]+)\]\s*\[([^]]+)\]/is', $subject, $matches) ) {
			$vacancyCode = $matches[1][0];
			$providerCode = $matches[2][0];
			$mode='vacancy_provider';
			$log .= "Found ref pattern : vacancy:$vacancyCode Provider:$providerCode <br/>";

			$ctxt->setProperty("provider_code",$providerCode);
			$ctxt->setProperty("vacancy_code",$vacancyCode);	
			
			// On recherche l'association dossier/fournisseur
			$relationRecord = $ctxt->getRecord('rct_vacancy_provider.find_relation@recruitment','page.record','db',false,null,null);
			if($relationRecord)
				return $relationRecord;
		}

		// Region Jobs : code CO86RJ : CO86 : ref dossier, RJ: ref provider
		if(preg_match_all('/([a-z][a-z][0-9][0-9]?)([a-z][a-z]+)/i', $subject, $matches) ) {
			$vacancyCode = $matches[1][0];
			$providerCode = $matches[2][0];
			$mode='vacancy_provider';
			$log .= "Found ref pattern : vacancy:$vacancyCode Provider:$providerCode <br/>";

			$ctxt->setProperty("provider_code",$providerCode);
			$ctxt->setProperty("vacancy_code",$vacancyCode);	
			
			// On recherche l'association dossier/fournisseur
			$relationRecord = $ctxt->getRecord('rct_vacancy_provider.find_relation@recruitment','page.record','db',false,null,null);
			if($relationRecord)
				return $relationRecord;
		}

		// Region Jobs : code COM EVA RAJ : COM EVA : ref dossier, RAJ: ref provider
		if(preg_match_all('/COM\s+EVA\s+RAJ/i', $subject, $matches) ) {
			$ref = 'COM EVA RAJ';
			$mode='ref';

			$log .= "Found ref pattern : $ref <br/>";
			$ctxt->setProperty("ref",$ref);
			
			// On recherche l'association dossier/fournisseur
			$relationRecord = $ctxt->getRecord('rct_prestataire_vacancy.search_by_ref@recruitment','page.record','db',false,null,null);
			if($relationRecord)
				return $relationRecord;
		}

		// Region Jobs : code COM EVA RAJ : COM EVA : ref dossier, RAJ: ref provider
		if(preg_match_all('/(COM\s+EVA)\s+(RAJ|RJ[0-9][0-9])/i', $subject, $matches) ) {
			$vacancyCode = $matches[1][0];
			$providerCode = $matches[2][0];
			$mode='vacancy_provider';
			$log .= "Found ref pattern : vacancy:$vacancyCode Provider:$providerCode <br/>";

			$ctxt->setProperty("provider_code",$providerCode);
			$ctxt->setProperty("vacancy_code",$vacancyCode);	
			
			// On recherche l'association dossier/fournisseur
			$relationRecord = $ctxt->getRecord('rct_vacancy_provider.find_relation@recruitment','page.record','db',false,null,null);
			if($relationRecord)
				return $relationRecord;
		}

		// Indeed
		//Application from Claire Sevin for ASSISTANT CHEF DE PROJET EVENT (H/F), Boulogne Ile-de-France, France
		if(preg_match_all('/Application from (.*) for ([^,]+),/i', $subject, $matches) ) {
			$candidate = $matches[1][0];
			$vacancyCode = $matches[2][0];
			$providerCode = 'indeed';
			$mode='vacancy_provider';
			$log .= "Found ref pattern : vacancy:$vacancyCode Provider:$providerCode <br/>";

			$ctxt->setProperty("provider_code",$providerCode);
			$ctxt->setProperty("vacancy_code",$vacancyCode);	
			
			// On recherche l'association dossier/fournisseur
			$relationRecord = $ctxt->getRecord('rct_vacancy_provider.find_relation@recruitment','page.record','db',false,null,null);
			if($relationRecord)
				return $relationRecord;
                
            $ctxt->setProperty("provider_code",null);
            $ctxt->setProperty("vacancy_code",null);                
		}

		// iQuesta / Candidature ref. SI de Ahcene AIT ABDELMALEK
		if(preg_match_all('/iQuesta . Candidature ref\. (.*) de /i', $subject, $matches) ) {
			$candidate = $matches[2][0];
			$vacancyCode = $matches[1][0];
			$providerCode = 'iQuesta';
			$mode='vacancy_provider';
			$log .= "Found ref pattern : vacancy:$vacancyCode Provider:$providerCode <br/>";

			$ctxt->setProperty("provider_code",$providerCode);
			$ctxt->setProperty("vacancy_code",$vacancyCode);	
			
			// On recherche l'association dossier/fournisseur
			$relationRecord = $ctxt->getRecord('rct_vacancy_provider.find_relation@recruitment','page.record','db',false,null,null);
			if($relationRecord)
				return $relationRecord;

            $ctxt->setProperty("provider_code",null);
            $ctxt->setProperty("vacancy_code",null);                
		}

		// Viadeo Recruiter - Candidature à l'offre "ASSISTANT CHEF DE PROJET EVENT (H/F) " - EVENT2015
		if(preg_match_all('/Viadeo Recruiter - Candidature .* l.offre "([^"]+)\s*"/i', $subject, $matches) ) {

			$vacancyCode = trim($matches[1][0]);
			$providerCode = 'Viadeo Recruiter';
			$mode='vacancy_provider';
			$log .= "Found ref pattern : vacancy:$vacancyCode Provider:$providerCode <br/>";

			$ctxt->setProperty("provider_code",$providerCode);
			$ctxt->setProperty("vacancy_code",$vacancyCode);	
			
			// On recherche l'association dossier/fournisseur
			$relationRecord = $ctxt->getRecord('rct_vacancy_provider.find_relation@recruitment','page.record','db',false,null,null);
			if($relationRecord)
				return $relationRecord;
            $ctxt->setProperty("provider_code",null);
            $ctxt->setProperty("vacancy_code",null);                
		}
		// Apec 34962861W
		if(preg_match_all('/Apec\s+([0-9]+[A-Z])/i', $subject, $matches) ) {
			$ref = $matches[1][0];
			$mode='ref';
			$log .= "Found ref pattern : $ref <br/>";

			$ctxt->setProperty("ref",$ref);
			
			// On recherche l'association dossier/fournisseur
			$relationRecord = $ctxt->getRecord('rct_prestataire_vacancy.search_by_ref@recruitment','page.record','db',false,null,null);
			if($relationRecord)
				return $relationRecord;
            $ctxt->setProperty("provider_code",null);
            $ctxt->setProperty("vacancy_code",null);                
		}

		// site
		if( preg_match_all('/Formulaire de candidature \'(.*)\' www.evasol.fr/i', $subject, $matches) ) {
			$ref = $matches[1][0];
			$mode='ref';
			$log .= "Found ref pattern : $ref <br/>";

			$ctxt->setProperty("ref",$ref);
			
			// On recherche l'association dossier/fournisseur
			$relationRecord = $ctxt->getRecord('rct_prestataire_vacancy.search_by_ref@recruitment','page.record','db',false,null,null);
			if($relationRecord)
				return $relationRecord;
            $ctxt->setProperty("provider_code",null);
            $ctxt->setProperty("vacancy_code",null);                
		}
		// site
		if( preg_match_all('/candidature\s+spontan/i', $subject, $matches) ) {
			$ref = 'spontanée';
			$mode='ref';
			$log .= "Found ref pattern : $ref <br/>";

			$ctxt->setProperty("ref",$ref);
			
			// On recherche l'association dossier/fournisseur
			$relationRecord = $ctxt->getRecord('rct_prestataire_vacancy.search_by_ref@recruitment','page.record','db',false,null,null);
			if($relationRecord)
				return $relationRecord;
            $ctxt->setProperty("provider_code",null);
            $ctxt->setProperty("vacancy_code",null);                
		}

		// candidature spontanée
		if( preg_match_all('/spontan/i', $subject, $matches) ) {
			$ref = 'spontanée';
			$mode='ref';
			$log .= "Found ref pattern : $ref <br/>";

			$ctxt->setProperty("ref",$ref);
			
			// On recherche l'association dossier/fournisseur
			$relationRecord = $ctxt->getRecord('rct_prestataire_vacancy.search_by_ref@recruitment','page.record','db',false,null,null);
			if($relationRecord)
				return $relationRecord;
            $ctxt->setProperty("provider_code",null);
            $ctxt->setProperty("vacancy_code",null);                
		}

		// 107234067 Commercial débutant et confirmé H/F MO69 CV Monster
		if(preg_match_all('/([0-9]+)\s+.*(Monster|MO(?:[0-9][0-9]|LONG|PACA))/i', $subject, $matches) ) {
			$ref = $matches[1][0];
			$mode='ref';
			$log .= "Found ref pattern : $ref <br/>";

			$ctxt->setProperty("ref",$ref);
			
			// On recherche l'association dossier/fournisseur
			$relationRecord = $ctxt->getRecord('rct_prestataire_vacancy.search_by_ref@recruitment','page.record','db',false,null,null);
			if($relationRecord)
				return $relationRecord;
            $ctxt->setProperty("provider_code",null);
            $ctxt->setProperty("vacancy_code",null);                
		}

		// 107234067 Commercial débutant et confirmé H/F MO69 CV Monster
		if( preg_match_all('/([0-9]+)\s+.*(Monster|MO(?:[0-9][0-9]|LONG|PACA))/i', $subject, $matches) ) {
			$ref = $matches[1][0];
			$mode='ref';
			$log .= "Found ref pattern : $ref <br/>";

			$ctxt->setProperty("ref",$ref);
			
			// On recherche l'association dossier/fournisseur
			$relationRecord = $ctxt->getRecord('rct_prestataire_vacancy.search_by_ref@recruitment','page.record','db',false,null,null);
			if($relationRecord)
				return $relationRecord;
            $ctxt->setProperty("provider_code",null);
            $ctxt->setProperty("vacancy_code",null);                
		}

		return false;
	}

	function getProviderVacancyRecord_loopOnVacanciesRef($candidate_oid, $subject, &$log,$oCV) {
		$ctxt = Framework::getContext();

		$relationRecord=null;
		$relationRecords = $ctxt->getRecords('rct_prestataire_vacancy@recruitment','page.records','db',false,null,null);
		for ($iterRec = $relationRecords->getRecordIterator(); $iterRec->isValid(); $iterRec->next())
		{
			$relRec = $iterRec->getCurrent();
			$ref = $relRec->ref->string;
			$ref2 = trim(preg_replace('%\s*(\bOR\b|;|,)\s*%i','|',trim($ref)));
			$ref2 = trim($ref2,'|');
			if($ref2 && preg_match('%'.$ref2.'%i',$subject))
			{
				$relationRecord = $relRec;
				$log .= "Matched filters [$ref]<br/>";
				return $relationRecord;
			}
		}

		return false;
	}

	function applyRules($cvRec,$subject,&$log,$oCV)
	{
		$ctxt = Framework::getContext();

		$src = $oCV->src_text;
		if($subject)
			$src .= $subject;


		$candidate_oid = $cvRec->oid->object;

		$rules = new PersistentCollection('rct_profiling_rules.active_list@recruitment','db');
		$aRules = $rules->array;
		foreach($aRules as $rule)
		{
			// get type
			$profiling_on = $rule->profiling_on->object;
			$action = 'seek_kw_and_select_list';

			$content = '';
			if($profiling_on == 'subject')
			{
				$content = $oCV->message->subject;
			} 
			elseif($profiling_on == 'body')
			{
				$content = $oCV->message->body;
			}
			elseif($profiling_on == 'form_field_category'||$profiling_on == 'form_field_profile'||$profiling_on == 'form_field')
			{
				$form_field = trim($rule->form_field->object);
				if($form_field && isset($oCV->message->form))
					$form = $oCV->message->form;
				else
					// no form or no form field
					continue;

				if(isset($form->$form_field))
					$content = trim($form->$form_field);
				else
					// message without this field
					continue;

				$action = 'apply';
			}
			/*
			elseif($profiling_on == 'form_all_fields')
			{
				if(isset($oCV->message->form))
					$form = $oCV->message->form;
				else
					// no form in message
					continue;

				// all field values checked
				$content = implode(' ',$form);
			}
			*/
			else // if($profiling_on == 'cv')
			{
				$content = $src;
			}

			if($action == 'seek_kw_and_select_list')
			{
				// check keywords and if found, select value in list

				// match keywords
				$kw = trim($rule->keywords->object);
				if($kw)
				{
					$kwreg = preg_replace(
						array('%\s*,\s*%i','%\s+%','%^[*]$%'),
						array('|','\\s+','^.+$'),
							$kw);

					if(!preg_match("%{$kwreg}%i",$content))
						continue;
				}

				// avoid keywords 
				$notkw = trim($rule->not_keywords->object);
				if($notkw)
				{
					$kwreg = preg_replace(
						array('%\s*,\s*%i','%\s+%'),
						array('|','\\s+'),
							$notkw);
					if(preg_match("%{$kwreg}%i",$content))
						continue;
				}

				// apply rule

				// set vacancy
				if($rule->vacancy->object && $rule->vacancy->object!='?')
				{
					$this->attachVacancy($rule->vacancy->object,$candidate_oid,$log,$oCV);
				}

				// set category_oid
				if($rule->category_oid->object && $rule->category_oid->object!='?')
				{
					// set category if not already set
					if($cvRec->category_oid->object=='' || $cvRec->category_oid->object=='?')
						$cvRec->category_oid->object = $rule->category_oid->object;
				}

				// cand_channel
				if($rule->cand_channel->object && $rule->cand_channel->object!='?')
				{
					// set category if not already set
					if($cvRec->cand_channel->object=='' || $cvRec->cand_channel->object=='?')
						$cvRec->cand_channel->object = $rule->cand_channel->object;
				}

				// provider
				if($rule->provider->object && $rule->provider->object!='?')
				{
					$this->attachProvider($rule->provider->object,$candidate_oid,$log,$oCV);
				}

				// profile
				if($rule->profile->object && $rule->profile->object!='?')
				{
					$profile = preg_replace(
						array('%\s*,\s*%'),
						array('|'),
							$rule->profile->object);

					if( trim($profile) != '' )
					{
						$profile = ','.$profile.',';
						$cvRec->profile = $profile;
					}
				}

				// establishment
				if($rule->establishment->object && $rule->establishment->object!='?')
				{
					// set establishment if not already set
					if($cvRec->establishment->object=='' || $cvRec->establishment->object=='?')
						$cvRec->establishment->object = $rule->establishment->object;
				}
			}
			else
			{
				// apply field value
				if($profiling_on == 'form_field_category')
				{
					$this->setCategory($cvRec,$content);
				}

				if($profiling_on == 'form_field_profile')
				{
					$this->setProfile($cvRec,$content);
				}
			}
		}
	}

	function setCategory($cvRec,$value)
	{
		$cat = new PersistentObject('rct_candidate_category.by_value@recruitment','db',array('value'=>$value));
		if($cat->isOk())
		{
			$oid = $cat->oid->object;
		}
		else
		{
			$cat = new PersistentObject('rct_candidate_category.by_value@recruitment','empty');
			$cat->name->db = $value;
			$cat->store('rct_candidate_category.by_value@recruitment','insert');
			$oid = $cat->getLastInsertId(); 
		}

		$cvRec->category_oid->setValue($oid);
	}

	function setProfile($cvRec,$value)
	{
		$cat = new PersistentObject('rct_keyword.by_value@recruitment','db',array('value'=>$value));
		if($cat->isOk())
		{
			$oid = $cat->oid->object;
		}
		else
		{
			$cat = new PersistentObject('rct_keyword.by_value@recruitment','empty');
			$cat->key->db = $value;
			$cat->name->db = $value;
			$cat->store('rct_keyword.by_value@recruitment','insert');
			$oid = $cat->getLastInsertId(); 
		}

		$cvRec->profile->setValue($oid);
	}
	
	function getChannel($oCV,&$establishment)
	{
		$ctxt = Framework::getContext();

		// On recherche l'association dossier/fournisseur by email
		if(isset($oCV->message->headers->to))
		{
			$toEmail = trim($oCV->message->headers->to);
			$channel = new PersistentObject('rct_channel.by_email@recruitment','db',array('email'=>$toEmail));
			if($channel->isOk())
			{
				nxLog('Found channel by email','CV');
				// establishment
				if($channel->establishment->object && $channel->establishment->object!='?')
				{
					nxLog('Found channel with establishment : '.$channel->establishment->object,'CV');
					$establishment = $channel->establishment->object;
				}

				return $channel;
			}

			if(	preg_match("/_([0-9][0-9])([0-9][0-9])([0-9][0-9])(0[0-2])@pourcandidature.com/i",$toEmail,$matches)
			)
			{
				$oid = (int)ltrim($matches[4],'0');
				$channel = new PersistentObject('rct_channel.by_oid@recruitment','db',array('oid'=>$oid));
				if($channel->isOk())
				{
					nxLog('Found channel by oid from email pourcandidature.com','CV');
					// establishment
					if($channel->establishment->object && $channel->establishment->object!='?')
					{
						nxLog('Found channel with establishment : '.$channel->establishment->object,'CV');
						$establishment = $channel->establishment->object;
					}

					return $channel;
				}
			}

			nxLog('Channel not found','CV');
			return null;
		}
	}
	
	function associateWithVacancy($candidate_oid, $subject, &$log,$oCV)
	{
		$vacancy_oid=null;
		$relationRecord=null;

		$ctxt = Framework::getContext();
		
		// recherche par email
		$relationRecord = $this->getProviderVacancyRecord_byEmail($candidate_oid, $subject, $log,$oCV);

		if(!$relationRecord)
		{
			nxLog('getProviderVacancyRecord_byEmail : no match','CV');

			// search reference in subject using predefined patterns, then search vacancy>provider by ref
			$relationRecord = $this->getProviderVacancyRecord_byReferenceInSubject($candidate_oid, $subject, $log,$oCV);
		}
		
		if(!$relationRecord)
		{
			nxLog('getProviderVacancyRecord_byReferenceInSubject : no match','CV');

			// loop on all vacancies and try finding their reference in their subject
			$log .= "Couldn't match a reference pattern, no binding..Trying filters <br/>";
			$relationRecord = $this->getProviderVacancyRecord_loopOnVacanciesRef($candidate_oid, $subject, $log,$oCV);		
		}

		// check if searches were successful
		$provider_code = $ctxt->getProperty("provider_code");
		$vacancy_code = $ctxt->getProperty("vacancy_code");
		if(!$relationRecord && !$provider_code && !$vacancy_code)
		{
			nxLog('getProviderVacancyRecord_loopOnVacanciesRef : no match','CV');

			if(!$this->getVacancyRecord_byEmail($candidate_oid, $subject, $log,$oCV))
			{
				nxLog('getVacancyRecord_byEmail : no match ==> cant attach candidate','CV');

				// not found anything
				return false;
			}
			else
				return true;
		}
		
		// On crée la relation si elle n'existe pas
		if( ! $relationRecord ) 
		{			
			// Récupération de l'oid du dossier
			$vacancyRecord = $ctxt->getRecord('rct_vacancy.find_by_code@recruitment','page.record','db',false,null,null);
			if(!$vacancyRecord) 
			{
				$log .= "vacancy match : vacancy:$vacancyCode not found.. not binding <br/>";
				// return false;
			}
			else
			{
				$ctxt->setProperty("vacancy_oid",$vacancy_oid=$vacancyRecord->oid->db);
				$log .= "vacancy match : vacancy:$vacancyCode ok for binding <br/>";
			}
			
			// récupération de l'oid du provider
			$providerRecord = $ctxt->getRecord('rct_provider.find_by_code@recruitment','page.record','db',false,null,null);
			if(!$providerRecord ) 
			{
				$log .= "provider match : $providerCode not found.. not binding <br/>";
				//return false;
			}
			else
			{
				$log .= "provider match : $providerCode ok for binding <br/>";
				$ctxt->setProperty("provider_oid",$provider_oid= $providerRecord->oid->db);
			}

			// New relation record
			if($vacancyRecord && $providerRecord)
			{
				$relationRecord = new PersistentObject('rct_vacancy_provider.cron_add@recruitment','empty');
				$relationRecord->provider_oid = $provider_oid;
				$relationRecord->store('rct_vacancy_provider.cron_add@recruitment','insert','db');
			}
		} 
		else 
		{
			$ctxt->setProperty("vacancy_oid",$vacancy_oid=$relationRecord->vacancy_oid->db);
			$ctxt->setProperty("provider_oid",$provider_oid=$relationRecord->provider_oid->db);
		}
				
		// Vérifie si le candidat n'est pas déjà associé au dossier
		$ctxt->setProperty("candidate_oid",$candidate_oid);
	
		// Tentative de récupération de l'association dossier/candidat
		if($vacancy_oid) 
		{
			$this->attachVacancy($vacancy_oid,$candidate_oid,$log,$oCV);
		}

		if($provider_oid)
		{
			$this->attachProvider($provider_oid,$candidate_oid,$log,$oCV);
		}

		$log .= "candidate bindind successful! <br/>";
		return true;
	}

	function attachVacancy($vacancy_oid,$candidate_oid,&$log,$oCV) {
		
		$ctxt = Framework::getContext();

		$ctxt->setProperty('candidate_oid',$candidate_oid);
		$ctxt->setProperty('vacancy_oid',$vacancy_oid);

		$candidateVacancyRecord = $this->ctxt->getRecord('rct_candidate_vacancy.get_assoc@recruitment','page.record','db',false,null,null);

		// On crée l'association si elle n'existe pas
		if( !$candidateVacancyRecord) 
		{
			$log .= "candidate bound to vacancy <br/>";
			nxLog("candidate bound to vacancy",'CV');

			$candidateVacancyRecord = new PersistentObject('rct_candidate_vacancy.add_assoc@recruitment','empty');	
			$candidateVacancyRecord->store('rct_candidate_vacancy.add_assoc@recruitment','insert','db');
		}
		else 
		{
			nxLog("candidate already bound to vacancy...",'CV');
			$log .= "candidate already bound to vacancy... <br/>";
		}
	}

	function attachProvider($provider_oid,$candidate_oid,&$log,$oCV) {

		$ctxt = Framework::getContext();

		$ctxt->setProperty('candidate_oid',$candidate_oid);
		$ctxt->setProperty('provider_oid',$provider_oid);

		// On met à jour l'association en indiquant la provenance du CV avec l'oid du fournisseur	
		$ctxt->putRecord($null=null,'rct_candidate_vacancy.update_provider@recruitment','update','db','Object',null);

		// Tentative de récupération de l'association candidat/source
		if($candidate_oid && $provider_oid)
		{
			$candidateProviderRecord = $ctxt->getRecord('rct_candidate_provider.find_relation@recruitment','page.record','db',false,null,null);

			// On crée l'association si elle n'existe pas
			if( ! $candidateProviderRecord ) 
			{
				$log .= "candidate binding to provider source <br/>";
				$candidateProviderRecord = new PersistentObject('rct_candidate_provider@recruitment','empty');
				$candidateProviderRecord->candidate_oid->object = $candidate_oid;
				$candidateProviderRecord->provider->object = $provider_oid;
				$candidateProviderRecord->store('rct_candidate_provider@recruitment','insert','db');
			}
		}
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

	function storeCVObject($oCV,$filesDesc,&$oid,&$isNew,$alternateFilePath=null)
	{
		$package = '@recruitment';

		if($oid)
			$this->updateByUser = true;
		else
			$this->updateByUser = false;


	nxLog('Receiving CV','CV');

		// get name from form if any and overload name from analyser
		if(isset($oCV->message->form->firstName) && isset($oCV->message->form->lastName) && $oCV->message->form->firstName && $oCV->message->form->lastName)
		{
			$oCV->person->firstName = $oCV->message->form->firstName;
			$oCV->person->lastName = $oCV->message->form->lastName;
		}

	nxLog("CV name {$oCV->person->firstName} {$oCV->person->lastName} ",'CV');

		//recuperer le subject pour gerer les dossiers
		$subject = $oCV->message->headers->subject;
		$s = "Processing CV from message $subject<br/>"; 

		$establishment=null;
		nxLog($s,'CV');

		$channel = $this->getChannel($oCV,$establishment);
		nxLog("channel processed",'CV');

		// renvoyer un email

		nxLog("getCVRecord...",'CV');

		// doublons : email, telephone, nom, prenom
		if (!$oid)
		{
			// automatic mode : search for existing cv
			$oid = $this->getCVRecord($oCV);
		}

		if ($oid === null)
		{
			$s .= "received new CV for {$oCV->person->firstName} {$oCV->person->lastName}<br/>";
			nxLog("Is new CV",'CV');

			$cvRec = $this->storeNewCV($oCV,$channel,$establishment);
			$isNew = true;		
		}
		else
		{
			$s .= "Updated existing CV $subject for {$oCV->person->firstName} {$oCV->person->lastName}<br/>";
			nxLog("Is existing CV",'CV');
			$cvRec = $this->storeExistingCV($oid,$oCV,$channel,$establishment);
			$isNew = false;
		}

		nxLog("associateWithVacancy...",'CV');

		$oid = $cvRec->oid->object;
        
		$bindToVacancy = $this->associateWithVacancy($oid,$subject,$s,$oCV);
		// $this->bindChannel($oid,$subject,$s,$oCV);

		// apply rules
		nxLog("apply rules...",'CV');
		$this->applyRules($cvRec,$subject,$s,$oCV);

//		if (!$bindToVacancy && $isNew)
		if ($isNew)
		{
			// Notification du candidat par email (sauf si indication contraire)
			if (!preg_match('/(non?|pas)\s*e?mail/i',$subject))
			{
				$s .= "Sending notification for new CV $subject for {$oCV->person->firstName} {$oCV->person->lastName}<br/>";
				nxLog("sending notification",'CV');
				$this->newCandidateNotification($cvRec->oid->object,$bindToVacancy,true,$s);
			}
		}

		nxLog("store CV file",'CV');

		if($alternateFilePath)
		{
			$this->storeCVAltFile($oCV,$cvRec,$alternateFilePath);
		}
		elseif ($filesDesc)
		{
			// store cv
			if(isset($filesDesc['cv']->name) && $filesDesc['cv']->name)
				$fname = $filesDesc['cv']->name;
			else
				$fname = 'cv.pdf';
                
			$this->storeCVFile($oCV,$fname,$cvRec,$filesDesc['cv']->src);

			// add email, cv and lm in email history
			$this->storeCV_CVLM($oCV,$cvRec,$filesDesc);

		}
		elseif(count($_FILES))
		{
			$this->storeCVFile_post($oCV,$cvRec);
		}
		else
		{
			$s .= "NO FILE RECEIVED!<br/>";
			nxLog("no cv file received",'CV');
		}

		// Remplir le cache
		nxLog('dnormalisation/cache','CV');
		$cache= new lib_recruitment_candidates_services_denormalisation($this->ctxt);
		$cache->partial($oid);
		nxLog('dnormalisation/cache : ok','CV');

		$s .= "Added in DB ok<br/>";

		nxLog("CV file received",'CV');

		return $s;
	}

	function getCVRecord_old($oCV) {
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

	function getCVRecord($oCV) {

		$package = '@recruitment';

		// doublons : email, telephone, nom, prenom
		$cvRecs = new PersistentCollection('rct_candidate.searchRecords'.$package,'db',
			array(
				'firstName'=>$oCV->person->firstName,
				'lastName'=>$oCV->person->lastName,
				'email'=>$oCV->person->emails[0],
			)
		);

		// not found
		if (!$cvRecs->isOk())
			return null;

		$aCvRecs = $cvRecs->array;
		foreach($aCvRecs as $cvRec)
		{
			// same names or contact
			$smeN = $this->sameNames($oCV,$cvRec);
			$smeE = $this->sameEmail($oCV,$cvRec);
			$smeT = $this->samePhones($oCV,$cvRec);
			$noTE = $this->noPhoneOrEmail($oCV,$cvRec);

			if( ($smeN && $smeE) || // same name  and email
				($smeN && $smeT) || // same name  and phone
				($smeE && $smeT) ||   // same email and phone
				($smeN && $noTE) // same names, no email or telephone
			  )
				return $cvRec->oid->object;
		}

		return null;
	}

	function sameNames($oCV,$cvRec) {
		if(
			strtolower($oCV->person->firstName) == strtolower($cvRec->first_name->string) && 
			strtolower($oCV->person->lastName) == strtolower($cvRec->last_name->string)
			)
			return true;
		else
			return false;
	}

	function samePhones($oCV,$cvRec) {
		if(!isset($oCV->person->phones))
			return false;

		// registered phones
		$phones = array();
		if($cvRec->phone_1->object)
			$phones[] = $cvRec->phone_1->object;
		if($cvRec->phone_2->object)
			$phones[] = $cvRec->phone_2->object;
		if($cvRec->mobile->object)
			$phones[] = $cvRec->mobile->object;

		if (count(array_intersect($phones,$oCV->person->phones))>0)
			return true;

		return false;
	}

	function noPhoneOrEmail($oCV,$cvRec) {

		// count phones
		if(isset($oCV->person->phones) && count($oCV->person->phones))
			return false;

		if(trim($cvRec->phone_1->object) || trim($cvRec->phone_2->object) || trim($cvRec->mobile->object))
			return false;

		if (trim($cvRec->email->object))
			return false;

		if (isset($oCV->person->emails) && is_array($oCV->person->emails) && count($oCV->person->emails))
			return false;

		return true;
	}

	function sameEmail($oCV,$cvRec) {
		$email = $cvRec->email->object;
		if ($email && isset($oCV->person->emails) && is_array($oCV->person->emails) && in_array($email,$oCV->person->emails))
			return true;

		return false;
	}

	function storeCVFile($oCV,$fname,$cvRec,$fileContent=null)
	{
		nxLog("storeCVFile",'CV');

		$package = '@recruitment';

		if (!$fname)
			$fname = 'cv.pdf';

		$fromPath  = $fname;
		$oid = $cvRec->oid->object;
        //Add prefix to path
        $dvs = $this->ctxt->getProperty('recruitement.cv.org',10000);
        $prefix = '';
        if($oid >= $dvs){
            $prefix='/_'.intval($oid/$dvs)*$dvs;
        }
		$toDir = "packages/recruitment/candidates/directory".$prefix."/{$oid}/cv/";

		if ($fileContent)
			$cvRec->cv_path->readFromFile($fname,$toDir,false,$fileContent);

		// update CV
		$cvRec->store('rct_candidate.import.record'.$package,'update','db',array('oid'=>$oid));

		$path = $cvRec->cv_path->path;
		$folderPath=dirname($path).'/';
		$fileName=basename($path);

		nxLog("storeCVFile : lancer conversion convertToSwf($folderPath, $fileName): ",'CV');

		//$this->convertToSwf($folderPath, $fileName);
	}

	function storeCV_CVLM($oCV,$cvRec,$filesDesc)
	{
		nxLog("storeCVLMFile",'CV');

		// get CV and LM
		if(isset($filesDesc['cv_ori']))
			$fcv = $filesDesc['cv_ori'];
		else
			$fcv = $filesDesc['cv'];

		$fpathCV=$fcv->name;

		$CVfileContent=$fcv->src;
		$cv_key = md5($CVfileContent);

		if(isset($filesDesc['lm']))
		{
			$flm = $filesDesc['lm'];
			$LMfileContent = $flm->src;

			$fpathLM = $flm->name;
			$ds = 'rct_candidate_email.by_cv_or_lm_keys@recruitment';
			$lm_key = md5($LMfileContent);
		}
		else
		{
			$ds = 'rct_candidate_email.by_cv_key@recruitment';
			$lm_key = null;
		}

		// check if same files were already sent
		$email = new PersistentObject($ds,'db', array('cv_key'=>$cv_key,'lm_key'=>$lm_key));

		if($email->isOk())
			// no change (same cv and lm)
			return false;

		if (!$fpathCV)
			$fpathCV = 'cv.pdf';

		if (!$fpathLM)
			$fpathLM = 'lm.pdf';

		// add email with cv and lm
		$email = new PersistentObject('rct_candidate_email@recruitment','empty');
		$email->candidate_oid->object = $coid = $cvRec->oid->object;

		// get subject, from, to
		if(isset($oCV->message->headers->subject))
			$email->email_title->db = trim($oCV->message->headers->subject);

		if(isset($oCV->message->headers->from))
			$email->email_from->db = trim($oCV->message->headers->from);

		if(isset($oCV->message->headers->name))
			$email->email_from_name->db = trim($oCV->message->headers->name);

		// get BODY
		foreach($filesDesc as $k=>$part)
		{
			if($part->name=='body.text')
			{
				$email->email_content->db = $part->src;
			}
			elseif($part->name=='body.html')
			{
				$src = $part->src;
				$html = html_entity_decode($src);
				$html = preg_replace(array('%^.*<body[^>]*>%i','%</body>.*$%i',"%'%"),array('','','$1',"&#39;"),$html);			
				$email->email_content->object = $html;
			}
			else
			{
				// other files
			}
		}

		// add CV
		if ($CVfileContent)
		{
			$email->cvkey->object = $cv_key;
            //Add prefix to path
            $dvs = $this->ctxt->getProperty('recruitement.cv.org',10000);
            $prefix = '';
            if($coid >= $dvs){
                $prefix='/_'.intval($coid/$dvs)*$dvs;
            }
			$toDir = "packages/recruitment/candidates/directory".$prefix."/{$coid}/cv/";
			$email->cv->readFromFile($fpathCV,$toDir,false,$CVfileContent);
		}

		// add LM
		if ($LMfileContent)
		{
			$email->lmkey->object = $lm_key;
			$toDir = "packages/recruitment/candidates/directory/{$coid}/lm/";
			$email->lm->readFromFile($fpathLM,$toDir,false,$LMfileContent);
		}

		// add email record
		$email->store('rct_candidate_email.add@recruitment','insert','db');

		return true;
	}


	function storeCVAltFile($oCV,$cvRec,$fromPath)
	{
		nxLog("storeCVFile alternate image",'CV');

		$package = '@recruitment';
		$fpath = basename($fromPath);
		$fname = $fpath;

		// get uploaded file
		$tmp_name = $fromPath;
		$name = 'cv.pdf';

		$oid = $cvRec->oid->object;
        //Add prefix to path
        $dvs = $this->ctxt->getProperty('recruitement.cv.org',10000);
        $prefix = '';
        if($oid >= $dvs){
            $prefix='/_'.intval($oid/$dvs)*$dvs;
        }
		$toDir = "packages/recruitment/candidates/directory".$prefix."/{$oid}/cv/";

		$basePath = $this->ctxt->getProperty('pathUpload',NX_DOC_ROOT.'files/'). $toDir .'/';
		$fdest = $basePath . $fname;

		$this->fs->rename($fromPath,$fdest);

		$cvRec->cv_path->info =  array(
				'n' => $fname,
				'dir' => $toDir,
				);

		// update CV
		$cvRec->store('rct_candidate.import.record'.$package,'update','db',array('oid'=>$oid));

		// convert to swf
		$path = $cvRec->cv_path->path;
		$folderPath=dirname($path).'/';
		$fileName=basename($path);

		//nxLog("storeCVFile : lancer conversion convertToSwf($folderPath, $fileName): ",'CV');
		// $this->convertToSwf($folderPath, $fileName);
	}

	function storeCVFile_post($oCV,$cvRec)
	{
		if(!isset($_FILES['cv']["tmp_name"]))
			return false;

		nxLog("storeCVFile post",'CV');

		$package = '@recruitment';
		$fpath = 'cv.pdf';

		// get uploaded file
		$file = $_FILES['cv'];
		$tmp_name = $file["tmp_name"];
		$name = $file["name"];

		$oid = $cvRec->oid->object;
        //Add prefix to path
        $dvs = $this->ctxt->getProperty('recruitement.cv.org',10000);
        $prefix = '';
        if($oid >= $dvs){
            $prefix='/_'.intval($oid/$dvs)*$dvs;
        }
		$toDir = "packages/recruitment/candidates/directory".$prefix."/{$oid}/cv/";
		$fname = 'cv.pdf';

		$basePath = $this->ctxt->getProperty('pathUpload',NX_DOC_ROOT.'files/'). $toDir .'/';
		$fdest = $basePath . $fname;
		move_uploaded_file($tmp_name,$fdest);
		$cvRec->cv_path->info =  array(
				'n' => $fname,
				'dir' => $toDir,
				);

		// update CV
		$cvRec->store('rct_candidate.import.record'.$package,'update','db',array('oid'=>$oid));

		// convert to swf
		$path = $cvRec->cv_path->path;
		$folderPath=dirname($path).'/';
		$fileName=basename($path);

		//nxLog("storeCVFile : lancer conversion convertToSwf($folderPath, $fileName): ",'CV');
		//$this->convertToSwf($folderPath, $fileName);
	}

	function convertToSwf($folderPath, $fileName) {
		
		if( is_file($filePath.'.swf') ) {
			@unlink($filePath.'.swf');
		}

		$filePath = $folderPath.$fileName;
		$pathParts = pathinfo($filePath);
		nxLog("convertToSwf: $filePath ",'CV');

		if( $pathParts['extension'] == 'pdf' ) {

			nxLog("convertToSwf: $filePath PDF : ok ",'CV');

			// Chemin de l'exécutable (@todo : à mettre en property système)
			$pPath = '/usr/local/bin/pdf2swf';

			if (!is_file($pPath))
				return false;
						
			// Options de conversion (Par défaut)
			$options = '-q -t -T 9 -G -f';

			$cmd = $pPath .' '.$options.' "'. $filePath .'" -o "'.$filePath.'.swf"';
			nxLog("Conversion fichier vers swf :".$cmd,'CV');

			// On essaye de convertir le fichier en gardant un rendu optimal
			exec($cmd);
	
			if( ! is_file($filePath.'.swf') ) {
				// Le fichier n'a pas été créé (Problème sous Mac/Linux). On essaye de le recréer en convertissant texte et images en bitmap
				$fOptions = $options . ' -O 2';
		
				$cmd = $pPath .' '.$fOptions.' "'. $filePath .'" -o "'.$filePath.'.swf"';
				nxLog("Echec conversion => essai avec :".$cmd);
				exec($cmd);
			}

			if( ! is_file($filePath.'.swf') ) {
				nxLog("Echec conversion cv swf : ".$filePath,'CV');
			}
			else {
				nxLog("Conversion cv swf ok :".$filePath,'CV');
			}						
		}	
	}

	function storeNewCV($oCV,$channel,$establishment)
	{
		$package = '@recruitment';

		// stocker les fichers candidats dans le repertoire cible

		// create CV
		$cvRec = new PersistentObject('rct_candidate.import.record'.$package,'empty');
		$cvRec->cv_path->db='';
		$cvRec->cl_path->db='';

		// add channel : cooptation, stage, etc.
		$cvRec->cand_channel->object = $channel->oid->object;
		$cvRec->establishment->object = $establishment;

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

	function storeExistingCV($oid,$oCV,$channel,$establishment)
	{
		$package = '@recruitment';

		// stocker les fichers candidats dans le repertoire cible

		// get CV Record
		$cvRec = new PersistentObject('rct_candidate.import.record'.$package,'db',array('oid'=>$oid));

		// add channel : cooptation, stage, etc.
		$cvRec->cand_channel->object = $channel->oid->object;
		$cvRec->establishment->object = $establishment;

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
		return str_replace( array('à','á','â','ã','ä','ç','è','é','ê','ë','ì','í','î','ï','ñ','ò','ó','ô','õ','ö','ù','ú','û','ü','ý','ÿ','À','Á','Â','Ã','Ä','Ç','È','É','Ê','Ë','Ì','Í','Î','Ï', 'Ñ','Ò','Ó','Ô','Õ','Ö','Ù','Ú','Û','Ü','Ý'), array('a','a','a','a','a','c','e','e','e','e','i','i','i','i','n','o','o','o','o','o','u','u','u','u','y','y','a','a','a','a','a','c','e','e','e','e','e','i','i','i','i','n','o','o','o','o','o','u','u','u','u','y'), $str);
	}

	function fillCVRec($cvRec,$oCV) 
	{
		// check if current names are ok in current resume
		if($this->updateByUser==true && trim($cvRec->first_name->object) && trim($cvRec->first_name->object))
			// existing cv has already names ok (updated by recruiter)
			$namesOk = true;
		else
			// new cv, or current cv is incomplete, or automatic update
			$namesOk = false;

		if(!$namesOk)
		{
			// update names
			$cvRec->first_name = $oCV->person->firstName;
			$cvRec->last_name = $oCV->person->lastName;
		}

		if(isset($oCV->person->gender))
		{
			switch($oCV->person->gender) 
			{
				case 'M': $cvRec->gender->object = 0; break;
				case 'F': $cvRec->gender->object = 1; break;
				default : break;
			}
		}

		if(isset($oCV->person->title))
		{
			switch($oCV->person->title) 
			{
				case 'M.': $cvRec->civility->object = 0; break;
				case 'Mlle': $cvRec->civility->object = 1; break;
				case 'Mme': $cvRec->civility->object = 2; break;
				default : break;
			}
		}

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
		
		$cvRec->town_oid->object = $this->replaceAccents($oCV->person->town);

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
		$cvRec->src_text->db = $this->replaceAccents($oCV->person->firstName.' '.$oCV->person->lastName.' '.$oCV->src_text);

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

		$code = $this->rmCrLf($diploma->code);
		$itemRec = new PersistentObject('rct_diploma.by_code'.$package,'db',
			array(
				'code'=>$code,
			)
		);
		if ($itemRec->isOk())
			return $itemRec;


		$itemRec = new PersistentObject('rct_diploma'.$package,'empty');
		$itemRec->code=$code;
		$itemRec->label=$code;

		$itemRec->store('rct_diploma'.$package,'insert','db',null);
	}
	
	function rmCrLf($str) {
		return htmlspecialchars(str_replace(array(chr(10),chr(13)),array("",""),$str),ENT_QUOTES);
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

//			$itemRec->diploma->object = $this->rmCrLf($item->diplom->code);
			$itemRec->diploma->object = $item->diplom->code;
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