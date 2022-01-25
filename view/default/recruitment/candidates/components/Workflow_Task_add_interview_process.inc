<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/
include_once(GENERIS_PACKAGES.'recruitment/lib/email/ManageEmails.inc');
require_once(NX_LIB.'module/NxPage.inc');


require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');
include_once(NX_LIB.'ds/email/NxMail_MIME.inc');
include_once(GENERIS_PACKAGES.'recruitment/lib/email/NxRecruitment_Email.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');


class Workflow_Task_add_interview_process extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->ctxt = $ctxt;
		$this->NxPage($params,$ctxt,null);

		$this->interview = new ManageEmails($ctxt);
	}

	function setProgress($vacancyOid , $progress_level_meta = '6') 
	{

		// set progress level
		$vacancyLevel = new PersistentObject('rct_vacancy.get_current_progress_level@recruitment','empty');
		$vacancyLevel->oid->object = $vacancyOid;
		$vacancyLevel->progress_level->object = '6';
		$vacancyLevel->progress_level_meta->object = '6';
		$vacancyLevel->store('rct_vacancy.change_progress_level@recruitment','update','db',
			array('vacancy_oid' =>$vacancyOid,'progress_level'=>'6'));
		
		// add history entry
		$historyEntry = new PersistentObject('rct_vacancy_history.record@recruitment','empty');
		$historyEntry->vacancy_oid->object = $vacancyOid;
		$historyEntry->progress_level->object = $vacancyLevel->progress_level->object;	
		$historyEntry->progress_level_meta->db = $progress_level_meta;
		$historyEntry->store('rct_vacancy_history.record@recruitment','insert','db');
	}

	function run($workflow, $user)
	{
		
		$this->setProperty("vacancy_oid",$vacancyOid = (isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));

		// load interview record
		$interviewRecordO = new PersistentObject(
				'rct_interview.add_to_candidate@recruitment',
				'post',array('vacancy_oid'=>$vacancyOid));

		$interviewRecord = $interviewRecordO->record;
		
		$this->ctxt->setProperty('page.record',$interviewRecord);


		$candidate_oid = $interviewRecord->candidate_oid->object;
		$candidates_oids = explode('|', $candidate_oid);
		if(sizeOf($candidates_oids) == 1)
			$candidates_oids = explode(',' , $candidate_oid);
			
		$interviews_oid = array();

		foreach($candidates_oids as $i=>$coid)
		{
			$this->setProperty("candidate_oid",$coid);
			$_REQUEST['candidate_oid'] = $coid;
			$interviewRecord->candidate_oid->object = $coid;
			$interviewRecord->oid->object = null;

			// save interview record for candidate
			$this->putRecord(
				$interviewRecord,'rct_interview.add_to_candidate@recruitment','insert','db','Object',null);
				
			nxLog('insert interviewers','test');
			
			$lastOid=$this->getLastInsertID('db');
			$interviewRecord->oid->object = $lastOid;
			$interviews_oid[] = array($lastOid, $coid);
			$this->setProperty("interview_oid",$lastOid);
			
			//Video conference link
			if($interviewRecord->interview_type->object == 3){
				$link = $this->generate_video_link($lastOid , $interviewRecord->candidate_oid->object );
				$i_object = new PersistentObject('rct_interview.update_video_link','db',array('interview_oid'=>$lastOid));
				if($i_object->isOk())
				{
					$i_object->video_link->object = $link;
					$i_object->store('rct_interview.update_video_link','update','db',array('interview_oid' => $lastOid));
					$interviewRecord->video_link->object = $link;
				}
			}
            //Add log
            $log= new lib_recruitment_candidates_services_log($this->ctxt);
            $log->addLog($coid , $user->oid->object, 4 , '' , "(Date de l\'entretien: ".$interviewRecord->date." )");

			// save ical uid and seq
			
			$interviewRecord->ical_uid->object = md5($lastOid);
			$interviewRecord->ical_seq->object = 0;
			$this->putRecord(
				$interviewRecord,'rct_interview.edit@recruitment','update','db','Object',null);

			// update state of candidate
			if(!$interviewRecord->interview_etat->isEmpty())
			{
                $candidate_etat = new PersistentObject('rct_candidate.edit_etat','db',array('candidate_oid'=>$coid));
                $candidate_etat->store('rct_candidate.edit_etat','update','db',array('candidate_oid'=>$coid,'etat_oid'=>$_POST['etat_oid']));

				if($_POST['etat_oid'] != '?'){
					$record_etat = new PersistentObject('rct_candidate_etat.record_name', 'db' , array('etat_oid'=>$_POST['etat_oid']));
					//Add log
					$log= new lib_recruitment_candidates_services_log($this->ctxt);
					$log->addLog($coid , $user->oid->object, 8 , '' , '(Nouvel état: '.$record_etat->name->html.' )');
				}
                

				/*$candidate_etat = new PersistentObject('rct_candidate.edit_etat','db',array('candidate_oid'=>$coid));
				if($candidate_etat->isOk())
				{
					$etatOid = $candidate_etat->etat_oid->object = $interviewRecord->interview_etat->object;
					$candidate_etat->store('rct_candidate.edit_etat','update','db',
						array('candidate_oid'=>$coid,'etat_oid'=>$etatOid));


                    $record_etat = new PersistentObject('rct_candidate_etat.record_name', 'db' , array('etat_oid'=>$etatOid));
                    //Add log
                    $log= new lib_recruitment_candidates_services_log($this->ctxt);
                    $log->addLog($coid , $user->oid->object, 8 , '' , '(Nouvel état: '.$record_etat->name->html.' )');

				}*/
			}
		}
		var_dump('tttt');
var_dump(interviewRecord->video_link-object); die;


		// send invite to recruiter
		// $this->interview->sendInterviewEmail($interviews_oid,$interviewRecord,$user,$files);
		$success_recruiter = $this->interview->sendInterviewEmailRecruiter($interviewRecord,$user,$files);
		$success_candidate = $this->interview->sendInterviewEmailCandidate($coid,$interviewRecord,$user,$files);
		if(!$success_candidate){
			$i = new PersistentObject('rct_interview.edit_candidate_email_not@recruitment','empty');
			$i->candidate_email_not->object = 0;
			$i->store('rct_interview.edit_candidate_email_not@recruitment','update','db',array('interview_oid' =>$interviewRecord->oid->object));
		}
		if(!$success_recruiter){
			$i = new PersistentObject('rct_interview.edit_interviewer_email_not@recruitment','empty');
			$i->interviewer_email_not->object = 0;
			$i->store('rct_interview.edit_interviewer_email_not@recruitment','update','db',array('interview_oid' =>$interviewRecord->oid->object));
		}
		
		
		if($vacancyOid)
		{
			$this->setProgress($vacancyOid , $interviewRecord->candidate_oid->html);
		}
		
		//nouvelle cvthèque : appel ifram
		$src="";
		$fram="";
		if(isset($_REQUEST["src"]) && $_REQUEST["src"] == "newcvt"){
			$src="newcvt";
			$fram ="/fram";
		}
		
		$url = $fram.PORTAL_URL_PREFIX.'/recruitment/candidates/coid-'.(isset($_REQUEST["coid"])?$_REQUEST["coid"]:$candidate_oid).'/directory.php?nxo=edit&nxs=&oid='.(isset($_REQUEST["coid"])?$_REQUEST["coid"]:$candidate_oid).'&candidate_oid='.(isset($_REQUEST["coid"])?$_REQUEST["coid"]:$candidate_oid).'&tab=recruitement_card&src='.$src;
		if(isset($_REQUEST['void'])){
			$url = PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$_REQUEST["void"].'/directory.php?nxo=candidates&nxs=&oid='.$_REQUEST['void'].'&vacancy_oid='.$_REQUEST["void"].'&mode=page';
		}else if(isset($_REQUEST['from']) && $_REQUEST['from'] == "home"){
			$url = PORTAL_URL_PREFIX.'/recruitment3/';
		}else if(isset($_REQUEST['type']) && $_REQUEST['type'] == "new"){
			$url = PORTAL_URL_PREFIX.'/recruitment/interview/directory.php';
		}
		
		$this->setProperty('redirect_url.url',$url);
		$this->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);
		
		
		return true;
	}

	/**
		Fonction utilisée pour la programmation d'interviews et l'envoi de mails de manière massive
		L'upload se fait pour le premier élément et on copie le dossier créé pour le reste des items
	*/
	function uploadNCopyInterview($interview_oid,$candidateOid,$indexCandidate) 
	{
		$path='interviews';
		$handler_candidate='rct_interview_attached_file_candidate.add_record@recruitment';
		$handler_interviewer='rct_interview_attached_file_interviewers.add_record@recruitment';

		$stack = array(); // Liste des fichiers pour enregistrement dans la base de donnÃ©es  
		$folderToCopy = ''; // Chemin du dossier à  dupliquer
			
		if( $indexCandidate == 0 ) 
		{
			// first candidate : upload files
			$stack = $this->uploadInterviewFiles($interview_oid, $handler_candidate, $handler_interviewer, $path);
			//$folderToCopy = $this->getFilesUploadPath($dbOid, $path);
		} 
		else 
		{
			// other candidates : duplicatefiles

			// Nomenclature du dossier créé
			$newFolder = $this->getFilesUploadPath($interview_oid, $path);

			// duplicate dir
			$fs = new NxPlug_FileSys($this->ctxt);	
			$fs->copyDir($folderToCopy,$newFolder,$mode=0777);

			// Enregistrement dans la base de données
			$this->ctxt->setProperty('object_oid', $interview_oid);

			for($j=0; $j<count($stack); $j++) 
			{
				$this->ctxt->setProperty('file_name', $stack[$j]);
				$this->ctxt->putRecord($null=null, $handler, 'insert', 'db', 'Object', null);	
			}
		}			

		return $stack;
	}

	/*
		GÃ¨re l'upload des fichiers attachÃ©s au dossiers
	*/	
	function uploadFiles($objectOid, $handler, $path) {

		$uploadPath = $this->getFilesUploadPath($objectOid, $path);

		$fieldName = 'file_attachement';
				
		$stack = array();

		foreach($_FILES[$fieldName]['name'] as $key=>$value) {
			
			if( empty($_FILES[$fieldName]['name'][$key]) ) {
				continue;
			}
			
			$fileName 		= $_FILES[$fieldName]['name'][$key];
			$tempFileName 	= $_FILES[$fieldName]['tmp_name'][$key];
			// Clear upload path
			$completePath	= $uploadPath_candidate.$fileName;
						
			move_uploaded_file($tempFileName, $completePath);
			chmod($completePath,0644);
			
			$this->ctxt->setProperty('object_oid', $objectOid);
			$this->ctxt->setProperty('file_name', addslashes($fileName));
			
			$this->ctxt->putRecord($null=null, $handler, 'insert', 'db', 'Object', null);	
			
		}
		
		return $stack;
	}

	/*
		GÃ¨re l'upload des fichiers attachÃ©s aux interviews
	*/
	function uploadInterviewFiles($objectOid, $handler_candidate, $handler_interviewer, $path) 
	{
		$uploadPath_candidate = $this->getFilesUploadPath($objectOid."_candidate", $path);
		$uploadPath_interviewers = $this->getFilesUploadPath($objectOid."_interviewers", $path);

		$fieldName_array = array('_candidate'=>'file_attachement_candidate','_interviewers'=>'file_attachement_interviewers');
		$stack = array();
        foreach($fieldName_array as $key_array=>$fieldName)
		{
			if(count($_FILES[$fieldName])>0) 
				foreach($_FILES[$fieldName]['name'] as $key=>$value) 
				{
					if( empty($_FILES[$fieldName]['name'][$key]) ) 
					{
						continue;
					}
					
					$fileName 		= $_FILES[$fieldName]['name'][$key];
					$tempFileName 	= $_FILES[$fieldName]['tmp_name'][$key];
					
					// Clear upload path
					$completePath	= ${'uploadPath'.$key_array}.$fileName;
					move_uploaded_file($tempFileName, $completePath);
					chmod($completePath,0644);
					
					// register attachment
					include_once(NX_LIB.'orm/persistence.inc');
					$fileName = addslashes($fileName);
					$ds = "rct_interview_attached_file{$key_array}.add_record";
					$recordAttachment = new PersistentObject($ds,'empty');
					$recordAttachment->store($ds,'insert','db',array('object_oid'=>$objectOid, 'file_name'=>$fileName));				
					
					$stack[$fieldName][]=$fileName;
					// array_push($stack, array($fieldName ,$fileName));				
				}
		}
		
		return $stack;
	}
	
	function getFilesUploadPath($objectOid, $path) {
			
		$path = $this->ctxt->getProperty('pathUpload').'packages/recruitment/'.$path.'/'.$objectOid;

		if( !is_dir($path))
		{
			$fs = new NxPlug_FileSys($this->ctxt);
			$fs->createTree($path);
		}
		return $path .'/';
	}
	
	// Generate video link 
	function generate_video_link($interview_oid ,  $candidate_oid){
		if($this->getProperty('recruitment.code_client'))
			$code_client = $this->getProperty('recruitment.code_client');
		else $code_client = 'interview';
		return 'https://appear.in/'.$code_client.'-'.$interview_oid.substr(md5(microtime()),rand(0,26),5).$candidate_oid;
	}
}
?>