<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');
include_once(NX_LIB.'ds/email/NxMail_MIME.inc');
include_once(GENERIS_PACKAGES.'recruitment/lib/email/NxRecruitment_Email.inc');

class ManageEmails
{
	function __construct($ctxt)
	{
		$this->ctxt = $ctxt;
	}

	/*
		Gère l'upload des fichiers attachés aux interviews
	*/
	function uploadInterviewFiles($objectOid, $handler_candidate, $handler_interviewer, $path) 
	{
		$uploadPath_candidate = $this->getFilesUploadPath($objectOid."_candidate", $path);
		$uploadPath_interviewers = $this->getFilesUploadPath($objectOid."_interviewers", $path);

		$fieldName_array = array('_candidate'=>'file_attachement_candidate','_interviewer'=>'file_attachement_interviewers');
		$stack = array();
		$test=$_FILES;
        foreach($fieldName_array as $key_array=>$fieldName)
		{
			if(isset($_FILES[$fieldName]['name']))
				foreach($_FILES[$fieldName]['name'] as $key=>$value)
				{
					if( empty($_FILES[$fieldName]['name'][$key]) ) 
						continue;
					
					$fileName 		= $_FILES[$fieldName]['name'][$key];
					$tempFileName 	= $_FILES[$fieldName]['tmp_name'][$key];
					// Clear upload path
					$completePath	= ${'uploadPath'.$key_array}.$fileName;
								
					move_uploaded_file($tempFileName, $completePath);

					chmod($completePath,0644);
					
					$this->ctxt->setProperty('object_oid', $objectOid);
					$this->ctxt->setProperty('file_name', addslashes($fileName));
					
					$this->ctxt->putRecord($null=null, $test=${'handler'.$key_array}, 'insert', 'db', 'Object', null);
					
					array_push($stack, array($fieldName ,addslashes($fileName)));					
				}
		}
		
		return $stack;
	}

	function getFilesUploadPath($objectOid, $path) {
			
		$path = $this->ctxt->getProperty('pathUpload').'packages/recruitment/'.$path.'/'.$objectOid;
		if( ! is_dir($path) ) {
			$fs = new NxPlug_FileSys($this->ctxt);
			$fs->createTree($path);
		}
		return $path .'/';
	}

	// remove deleted files
	function removeFilesToDelete($objectOid, $handler, $path) 
	{
		if(!isset($_REQUEST['files_to_delete']))
			return;
		
		$uploadPath = $this->getFilesUploadPath($objectOid, $path);
		foreach($_REQUEST['files_to_delete'] as $key=>$value)
		{
			$this->ctxt->setProperty('oid', $value);
			$fileRecord = $this->ctxt->getRecord($handler,null,'db',false,null,null);
			@unlink($uploadPath.$fileRecord->file_name);			
			$this->ctxt->deleteRecords($handler,$this->ctxt->getRecords($handler,null,'db'),'db',true);
		}
	}	


	/** ===================== Notification d'interview ======================== */

	function sendInterviewEmail($inseredOids,$interviewRecord,$user,$files) 
	{
		$ctxt = $this->ctxt;
		
		// Envoi de l'email aux candidats
		if( count($inseredOids) == 0 ) {
			return;
		}
		
		// Récupération du message type à envoyer
		$interview_oid = $inseredOids[0][0];
		
		// Chemin des fichiers attachés		
		$filesPath_candidate = $this->ctxt->getProperty('pathUpload').'packages/recruitment/interviews/'.$interview_oid.'_candidate/';
		
		$filesPath_interviewers = $this->ctxt->getProperty('pathUpload').'packages/recruitment/interviews/'.$interview_oid.'_interviwers/';

		$ctxt->setProperty("interview_oid",$interview_oid);
		
		$messages = $ctxt->getRecords('rct_interview.email_data@recruitment','page.records','db',false,null,null);

		for ( $nx_iterRec = $messages->getRecordIterator(); $nx_iterRec->isValid(); $nx_iterRec->next())
		{
			$message=&$nx_iterRec->getCurrent();
			
			$proposed_to_oid = $message->user_oid->object;
			if($proposed_to_oid)
				$proposed_to = new PersistentObject('user.get_email@recruitment','db',array("user_oid"=>$proposed_to_oid));
			else
				$proposed_to = null;

			// Emails des candidats
			if( $message->candidate_email_not->db == '1' ) 
			{		
				// Récupération de la liste des emails des candidats à notifier
				$candidates = array();
				for($i=0; $i<count($inseredOids); $i++) {
					array_push($candidates, $inseredOids[$i][1]);
				}
				$ctxt->setProperty("candidate_oids",implode(',', $candidates));

				$candidatesMails = $ctxt->getRecords('rct_candidate.get_emails@recruitment','emails.records','db',false,null,null);
				
				// Corps de l'email		
				$message->body->object = $this->getEmailBody('interview_email_view');

				// Envoi à chaque candidat		
				for ( $nx_iterRec = $candidatesMails->getRecordIterator(); $nx_iterRec->isValid(); $nx_iterRec->next()) 
				{
					$candidateEmail=&$nx_iterRec->getCurrent();
					$message->to->db = $candidateEmail->email->db;
					$this->sendToCandidate($message, $filesPath_candidate,$interviewRecord,$user,$proposed_to,$files);
				}
			}
					
			if( $message->interviewer_email_not->db == '1' ) 
			{
				$message->to->db = $message->user_email->db;
				$message->subject = $message->user_subject;
				$message->body = $message->user_body;
				
				$message->body->object = $this->getEmailBody('interview_email_view');

				$message->files->string = '';
				$this->sendInviteToRecruiter($message,$filesPath_interviewers,$interviewRecord,$user,$proposed_to,$files);
			}
		}
	}

	function getEmailBody($view) 
	{
		ob_start();
		$this->ctxt->runView($view,array('fmethod' => 'toHTML',),null);
		$_nx_ret0=ob_get_contents();
		ob_end_clean();
		return $_nx_ret0;
	}

	function send($message, $filesPath = '', $dsID='register_email') 
	{
		$email = new NxRecruitment_Email($this->ctxt);
		return $email->send($message, $filesPath, $dsID);
	}

	function sendToCandidate($message, $filesPath = '', $interviewRecord,$user,$proposed_to=null,$files,$dsID='register_email') 
	{
		$dateStr = $interviewRecord->date->toHTML('%Y%m%d');
		$startDateTime = $interviewRecord->time_start->toTime();
		$endDateTime = $interviewRecord->time_end->toTime();
		$cname = $message->candidate_full_name->object;
		$subject = $message->user_subject->object;
		$description='';
		$location='';
		$user_name=$message->user_full_name->object;
		$user_email=$message->user_email->object;

		$meetingRequest = array
		(
			'name' => $cname,
			'date' => $dateStr,
			'date_str' => $interviewRecord->date->toHTML('%d/%m/%Y'),
			'startDateTime' => $startDateTime,
			'endDateTime' => $endDateTime,
			'summary' => $subject,
			'description' => $description,
			'location' => $location,
			'organiser' => array(
				// 'name'=>$user->firstName->object.' '.$user->lastName->object,
				'name'=>$user->email->object,
				'email'=>$user->email->object
			),

			'attendees' => array
			(
				// recruiter or manager
				array('name'=>$user_name,'email'=>$user_email)
			),

			'recruiter' => array('name'=>$proposed_to->first_name->string.' '.$proposed_to->last_name->string,'email'=>$proposed_to->email->object),

			'candidateName' => $cname
		);
		
		$email = new NxRecruitment_Email($this->ctxt);
		if(isset($files['file_attachement_candidate']))
			$message->files->string = implode('|||',$files['file_attachement_candidate']);

		return $email->sendInvite($message, $meetingRequest, $filesPath, $dsID, $cname,$proposed_to);
	}

	function sendInviteToRecruiter($message, $filesPath = '', $interviewRecord,$user, $proposed_to=null,$files, $dsID='register_email') 
	{
		$dateStr = $interviewRecord->date->toHTML('%Y%m%d');
		$startDateTime = $interviewRecord->time_start->toTime();
		$endDateTime = $interviewRecord->time_end->toTime();
		$cname = $message->candidate_full_name->object;
		$subject = $message->user_subject->object;
		$description='';
		$location='';

		$user_name=$message->user_full_name->object;
		$user_email=$message->user_email->object;

		$meetingRequest = array
		(
			'name' => $cname,
			'date' => $dateStr,
			'date_str' => $interviewRecord->date->toHTML('%d/%m/%Y'),
			'startDateTime' => $startDateTime,
			'endDateTime' => $endDateTime,

			'summary' => $subject,
			'description' => $description,
			'location' => $location,
			
			'organiser' => array(
				'name'=>$user->firstName->object.' '.$user->lastName->object,
				'email'=>$user->email->object
				// 'name'=>$user_name,'email'=>$user_email
			),
			'attendees' => array
			(
				array('name'=>$user_name,'email'=>$user_email)
			),

			'recruiter' => array('name'=>$user_name,'email'=>$user_email),
			'candidateName' => $interviewRecord->candidate_oid->string,
			'candidateOid' => $interviewRecord->candidate_oid->object,
		);

		$email = new NxRecruitment_Email($this->ctxt);
		if(isset($files['file_attachement_interviewers']))
			$message->files->string = implode('|||',$files['file_attachement_interviewers']);

		return $email->sendMeetingRequest($message, $meetingRequest, $filesPath, $proposed_to, $dsID,$cname);
	}
}

?>