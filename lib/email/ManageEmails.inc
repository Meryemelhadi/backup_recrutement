<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');
include_once(NX_LIB.'ds/email/NxMail_MIME.inc');
include_once('NxRecruitment_Email.inc');

class ManageEmails
{
	const EMAIL_NOT_SENT = '0';
	const EMAIL_NOT_SEND = '0';
	const EMAIL_ALREADY_SENT = '2';
	const EMAIL_SEND = '1';

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

	function sendInterviewEmailCandidate($candidate_oid,$interviewRecord,$user,$files,$timeUpdated=false,$locationUpdated=false) 
	{
		$ctxt = $this->ctxt;
			
		// Récupération du message type à envoyer
		$interview_oid = $interviewRecord->oid->object;
		$ctxt->setProperty('interview_oid',$interview_oid);
		
		// Chemin des fichiers attachés
		//$baseDir = $this->ctxt->getProperty('pathUpload').'packages/recruitment/interviews/';
		//$filesPath_candidate = $baseDir.$interview_oid.'_candidate/';
		//$filesPath_interviewers = $baseDir.$interview_oid.'_interviewers/';
		
		
		// get information for the interview : candidate name, interview, files
        //$ap=array('interview_oid'=>$interview_oid);
		//$props = new NxProperties($ap,$this->ctxt);
		// $messages = $ctxt->getRecords('rct_interview.email_data@recruitment','page.records','db',false,null,$props);
		$messageObject = new PersistentObject('rct_interview.email_data@recruitment','db',array('interview_oid'=>$interview_oid));
		$message = $messageObject->record;
		
		// get interviewer info
		$proposed_to_oid = $message->user_oid->object;
		if($proposed_to_oid)
			$proposed_to = new PersistentObject('user.get_email@recruitment','db',array("user_oid"=>$proposed_to_oid));
		else
			$proposed_to = null;

		// Emails des candidats si pas déjà envoyé
		$emailAction = $interviewRecord->candidate_email_not->object;
		if( $emailAction == self::EMAIL_SEND || ($emailAction == self::EMAIL_ALREADY_SENT && $timeUpdated)) 
		{               
			// Récupération de la liste des emails des candidats à notifier
			$ctxt->setProperty("candidate_oids",$candidate_oid);
			
			//$candidatesMails = $ctxt->getRecords('rct_candidate.get_emails@recruitment','emails.records','db',false,null,null);
			$candidateEmail = new PersistentObject('rct_candidate.get_emails@recruitment','db', array('candidate_oids'=>$candidate_oid));
			
			// Corps de l'email		
			$message->body->object = $this->getEmailBody('recruitment.emails.email_interview',$message);

			// Envoi à chaque candidat		
			$message->to->db = $candidateEmail->email->db;
            $filesPath_candidate=null;
			
			$success = $this->sendToCandidate($message, $filesPath_candidate,$interviewRecord,$user,$proposed_to,$files);
			return $success;
		}
		return true;
	}

	function getRecruiters($messages)
	{
		// get recruiters list
		$recruiters=array();
		for ( $nx_iterRec = $messages->getRecordIterator(); $nx_iterRec->isValid(); $nx_iterRec->next())
		{
			$message=&$nx_iterRec->getCurrent();

			// get interviewer info
			$recruiters[] = array
			(
				'name'=>$message->user_full_name->object,
				'email'=>$message->user_email->object,
			);
		}
		return $recruiters;
	}

	function sendInterviewEmailRecruiter($interviewRecord,$user,$files,$timeUpdated=false,$locationUpdated=false)
	{
		$ctxt = $this->ctxt;
				//DebugBreak();
		// Récupération du message type à envoyer
		$interview_oid = $interviewRecord->oid->object;
		$test = $interviewRecord->video_link->object;
		$ctxt->setProperty('interview_oid',$interview_oid);
					
		// get information for the interview : candidate name, interview, files
		$messages = new PersistentCollection('rct_interview.email_data@recruitment','db',array('interview_oid'=>$interview_oid));
		if(!$messages->isOk())
			return false;

		$user_names = '';
		$aMessages = $messages->array;

		// get recruiters list
		$recruiters=$this->getRecruiters($messages->records);

		foreach($aMessages as $message)
		{
			// get interviewer info
			$proposed_to_oid = $message->user_oid->object;
			if($proposed_to_oid)
				$proposed_to = new PersistentObject('user.get_email@recruitment','db',array("user_oid"=>$proposed_to_oid));
			else
				$proposed_to = null;

			$uid=$message->ical_uid->object;
			if(!$uid)
			{
				$uid = $message->ical_uid->object = md5($message->oid->object);
			}

			// check action
			$emailAction = $interviewRecord->interviewer_email_not->object;
			if( $emailAction == self::EMAIL_ALREADY_SENT && ($timeUpdated||$locationUpdated))
			{
				$message->to->db = $message->user_email->db;
				$message->subject = $message->user_subject->object;
				$message->body = $message->user_body;
				$message->body->object = $this->getEmailBody('recruitment.emails.email_invite',$message);

				if($user_names)
					$user_names .= ', ';
				$user_names .= $message->user_full_name->object;

				$message->files->string = '';

				$this->sendUpdateInviteToRecruiter($uid,$message,$interviewRecord,$user,$proposed_to,$recruiters);
				
			}

			// emails interviewers
			elseif( $emailAction == self::EMAIL_SEND ) 
			{
				$message->to->db = $message->user_email->db;
				$message->subject = $message->user_subject;
				$message->body = $message->user_body;
				$message->body->object = $this->getEmailBody('recruitment.emails.email_invite',$message);
				if($user_names)
					$user_names .= ', ';
				$user_names .= $message->user_full_name->object;

				$message->files->string = '';
				$message->ical_seq->object = 0;
				$success = $this->sendInviteToRecruiter($uid,$message,$filesPath_interviewers=null,$interviewRecord,$user,$proposed_to,$recruiters,$files);     
				return $success;
			}
		}

		/*
			if($user_names)
				$this->ctxt->msgOk(__('invite sent to').' '.$user_names);
		*/

		return true;
	}

	function sendInterviewCancelRecruiter($interviewRecord,$user)
	{
		$ctxt = $this->ctxt;
				
		// Récupération du message type à envoyer
		$interview_oid = $interviewRecord->oid->object;
		$ctxt->setProperty('interview_oid',$interview_oid);
					
		// get information for the interview : candidate name, interview
		$messages = new PersistentCollection('rct_interview.email_data@recruitment','db',array('interview_oid'=>$interview_oid));
		if(!$messages->isOk())
			return false;

		$user_names = '';

		// get recruiters list
		$recruiters=$this->getRecruiters($messages->records);

		$aMessages = $messages->array;
		foreach($aMessages as $message)
		{
			// get interviewer info
			$proposed_to_oid = $message->user_oid->object;
			if($proposed_to_oid)
				$proposed_to = new PersistentObject('user.get_email@recruitment','db',array("user_oid"=>$proposed_to_oid));
			else
				$proposed_to = null;

			// emails interviewers
			$emailAction = $interviewRecord->interviewer_email_not->db;
			if( $emailAction == self::EMAIL_SEND || $emailAction == self::EMAIL_ALREADY_SENT) 
			{
				$uid = $message->ical_uid->object;
				if(!$uid)
				{
					$uid = $message->ical_uid->object = md5($message->oid->object);
				}

				$message->ical_seq->object = "".((int)$message->ical_seq->object + 1);

				$message->to->db = $message->user_email->db;
				$message->subject = $message->user_subject;
				$message->body = $message->user_body;
				$message->body->object = $this->getEmailBody('recruitment.emails.email_invite',$message);
				if($user_names)
					$user_names .= ', ';
				$user_names .= $message->user_full_name->object;

				$message->files->string = '';
				$this->sendCancelToRecruiter($uid,$message,$interviewRecord,$user,$proposed_to,$recruiters);
			}
		}

		if($user_names)
			$this->ctxt->msgOkBs(__('invite cancel sent to').' '.$user_names);
	}

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
		$baseDir = $this->ctxt->getProperty('pathUpload').'packages/recruitment/interviews/';
		$filesPath_candidate = $baseDir.$interview_oid.'_candidate/';
		$filesPath_interviewers = $baseDir.$interview_oid.'_interviewers/';
		
		$ctxt->setProperty('interview_oid',$interview_oid);
		
		// get information for the interview : candidate name, interview, files
        $ap=array('interview_oid'=>$interview_oid);
		$props = new NxProperties($ap,$this->ctxt);
		$messages = $ctxt->getRecords('rct_interview.email_data@recruitment','page.records','db',false,null,$props);

		// get recruiters list
		$recruiters=$this->getRecruiters($messages->records);

		// send invites
		for ( $nx_iterRec = $messages->getRecordIterator(); $nx_iterRec->isValid(); $nx_iterRec->next())
		{
			$message=&$nx_iterRec->getCurrent();

			$uid=$message->ical_uid->object;
			if(!$uid)
			{
				$uid = $message->ical_uid->object = md5($interview_oid);
			}
			
			$proposed_to_oid = $message->user_oid->object;
			if($proposed_to_oid)
				$proposed_to = new PersistentObject('user.get_email@recruitment','db',array("user_oid"=>$proposed_to_oid));
			else
				$proposed_to = null;

			// Emails des candidats si pas déjà envoyé
			if( $message->candidate_email_not->db == self::EMAIL_SEND ) 
			{               
				// Récupération de la liste des emails des candidats à notifier
				$candidates = array();
				for($i=0; $i<count($inseredOids); $i++) {
					array_push($candidates, $inseredOids[$i][1]);
				}
				$ctxt->setProperty("candidate_oids",implode(',', $candidates));

				$candidatesMails = $ctxt->getRecords('rct_candidate.get_emails@recruitment','emails.records','db',false,null,null);
				
				// Corps de l'email		
				$message->body->object = $this->getEmailBody('recruitment.emails.email_interview',$message);

				// Envoi à chaque candidat		
				for ( $nx_iterRec = $candidatesMails->getRecordIterator(); $nx_iterRec->isValid(); $nx_iterRec->next()) 
				{
					$candidateEmail=&$nx_iterRec->getCurrent();
					$message->to->db = $candidateEmail->email->db;
					$this->sendToCandidate($message, $filesPath_candidate,$interviewRecord,$user,$proposed_to,$files);
				}
			}
					
			// emails interviewers
			if( $message->interviewer_email_not->db == self::EMAIL_SEND ) 
			{
				$message->to->db = $message->user_email->db;
				$message->subject = $message->user_subject;
				$message->body = $message->user_body;
				$message->body->object = $this->getEmailBody('recruitment.emails.email_invite',$message);

				$message->files->string = '';
				$this->sendInviteToRecruiter($uid,$message,$filesPath_interviewers,$interviewRecord,$user,$proposed_to,$recruiters,$recruiters,$files);
			}
		}
	}

	function getEmailBody($view,$messageRecord=null) {
		$props = array('fmethod' => 'toHTML');
		if($messageRecord)
			$props['message.record'] = $messageRecord;

		ob_start();
			$this->ctxt->runView($view,$props,null);
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
		//DebugBreak();
		$dateStr = $interviewRecord->date->toHTML('%Y%m%d');
		$startDateTime = $interviewRecord->time_start->toTime();
		$endDateTime = $interviewRecord->time_end->toTime();
		$cname = $message->candidate_full_name->object;
		$subject = $message->user_subject->object;
		$video_link = $interviewRecord->video_link->object;
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

		// files from library
		$libFiles = $this->getAttachedDocs($interviewRecord->email_docs);

		// additional files
		$files2 = $this->getAdditionalFiles($interviewRecord->attached_files_candidate);
		foreach($files2 as $name=>$path)
		{
			if(isset($libFiles[$name]))
				$name = "{$name}_1";

			$libFiles[$name] = $path;
		}

		$msgTo = ' '.$cname.'&lt;'.$message->to->string.'&gt;';
		$success =  true;
		if($message->to->string && $email->sendInvite($message, $meetingRequest, $filesPath, $dsID, $cname,$proposed_to,$libFiles,$video_link))
			$this->ctxt->msgOkBs(__('email sent to candidate').$msgTo);
		else{
			$this->ctxt->msgErrorBs(__('failure sending email to candidate').$msgTo);
			$success= false;
		}
		
		return $success;
	}

	function getAttachedDocs($docsField) {
		$files = array();
		if($docsField->isEmpty())
			return $files;

		$aDocsOid = $docsField->toArray();
		foreach($aDocsOid as $docOid)
		{
			if(!$docOid)
				continue;

			$doc = new PersistentObject('email_docs.by_oid@recruitment','db',array('oid'=>$docOid));
			if($doc->isOk())
			{
				$filePath = $doc->file->getPath(true);
				if(!$filePath)
					continue;
				$name = $doc->name->string;
				if(!$name)
					$name = basename($filePath);
				$files[$name] = $filePath;
			}
		}

		return $files;
	}

	function getAdditionalFiles($filesField) {
		$files = array();

		$fileRecords = $filesField->toRecords();

		for($itRec=$fileRecords->getRecordIterator();$itRec->isValid();$itRec->next())
		{
			$rec = $itRec->getCurrent();
			$ffile = $rec->file;
			if($ffile->isOk())
			{
				$filePath = $ffile->getPath(true);
				if(!$filePath)
					continue;
				$name = basename($filePath);
				$files[$name] = $filePath;
			}
		}

		return $files;
	}

	function sendInviteToRecruiter($uid,$message, $filesPath = '', $interviewRecord,$user, $proposed_to,$recruiters,$files, $dsID='register_email') 
	{
		$dateStr = $interviewRecord->date->toHTML('%Y%m%d');
		$startDateTime = $interviewRecord->time_start->toTime();
		$endDateTime = $interviewRecord->time_end->toTime();
		$video_link = $interviewRecord->video_link->object;
		$evaluation_url = (isset($_SERVER['HTTPS']) ? "https" : "http") . "://$_SERVER[HTTP_HOST]/recruitement2/interview_evaluation.php?nxo=edit_by_interview&operation=my_calendar&oid=".$interviewRecord->oid->object;
		$evaluation_url = "<a href='$evaluation_url'>Accédez à la fiche d'évaluation</a>";
		$entretien_url = (isset($_SERVER['HTTPS']) ? "https" : "http") . "://$_SERVER[HTTP_HOST]/recruitment/interview/directory.php?nxo=edit_interview&operation=my_calendar&mode=page&oid=".$interviewRecord->oid->object;
		$entretien_url = "<a href='$entretien_url'>Accédez à la fiche d'entretien</a>";
		$cname = $message->candidate_full_name->object;
		$subject = $message->user_subject->object;
		$description='';

		$location=$interviewRecord->location->html;

		$user_name=$message->user_full_name->object;
		$user_email=$message->user_email->object;

		$meetingRequest = array
		(
			'name' => $cname,
			'date' => $dateStr,
			'date_str' => $interviewRecord->date->toHTML('%d/%m/%Y'),
			'startDateTime' => $startDateTime,
			'endDateTime' => $endDateTime,
			'video_link' => $video_link,
			'evaluation_url' => $evaluation_url,
			'entretien_url' => $entretien_url,
			

			'summary' => $subject,
			'description' => $description,
			'location' => $location,

			'uid' => $message->ical_uid->object,
			'seq' => 0,

			'organiser' => array(
				'name'=>$user->first_name->object.' '.$user->last_name->object,
				'email'=>$user->email->object
				// 'name'=>$user_name,'email'=>$user_email
			),
			/*
			'attendees' => array
			(
				array('name'=>$user_name,'email'=>$user_email)
			),
			*/

			'recruiter' => array('name'=>$user_name,'email'=>$user_email),
			'candidateName' => $interviewRecord->candidate_oid->string,
			'candidateOid' => $interviewRecord->candidate_oid->object,
		);

		// add all recruiters as attendees
		foreach($recruiters as $attendee)
		{
			$meetingRequest['attendees'][] = array('name'=>$attendee['name'],'email'=>$attendee['email']);
		}

		$email = new NxRecruitment_Email($this->ctxt);
		if(isset($files['file_attachement_interviewers']))
			$message->files->string = implode('|||',$files['file_attachement_interviewers']);

		// files from library
		$libFiles = $this->getAttachedDocs($interviewRecord->user_email_docs);

		// additional files
		$files2 = $this->getAdditionalFiles($interviewRecord->attached_files_interviewer);
		foreach($files2 as $name=>$path)
		{
			if(isset($libFiles[$name]))
				$name = "{$name}_1";

			$libFiles[$name] = $path;
		}

        $toMsg = $proposed_to->first_name->html.' '.$proposed_to->last_name->html.'&lt;'.$proposed_to->email->html.'&gt;';
		$success = true;
		
		if($email->sendMeetingRequest($uid,$message, $meetingRequest, $filesPath, $proposed_to, $dsID,$cname,$libFiles)){
			 $this->ctxt->msgOkBs(__('invite sent to').' '.$toMsg);
		}
           
        else{
			$this->ctxt->msgErrorBs(__('failure sending invite to').' '.$toMsg);
			$success = false;
		}
        
		return $success;
			
	}

	function sendUpdateInviteToRecruiter($uid,$message, $interviewRecord, $user, $proposed_to, $recruiters, $dsID='register_email') 
	{
		$dateStr = $interviewRecord->date->toHTML('%Y%m%d');
		$startDateTime = $interviewRecord->time_start->toTime();
		$endDateTime = $interviewRecord->time_end->toTime();
		$video_link = $interviewRecord->video_link->object;
		$evaluation_url = (isset($_SERVER['HTTPS']) ? "https" : "http") . "://$_SERVER[HTTP_HOST]/recruitement2/interview_evaluation.php?nxo=edit_by_interview&operation=my_calendar&oid=".$interviewRecord->oid->object;
		$entretien_url = (isset($_SERVER['HTTPS']) ? "https" : "http") . "://$_SERVER[HTTP_HOST]//recruitment/interview/directory.php?nxo=edit_interview&operation=my_calendar&mode=page&oid=".$interviewRecord->oid->object;
		
		
		$cname = $message->candidate_full_name->object;
		$subject = $message->user_subject->object;
		$description='';

		$location=$interviewRecord->location->html;
		$user_name=$message->user_full_name->object;
		$user_email=$message->user_email->object;

		$meetingRequest = array
		(
			'name' => $cname,
			'date' => $dateStr,
			'date_str' => $interviewRecord->date->toHTML('%d/%m/%Y'),
			'startDateTime' => $startDateTime,
			'endDateTime' => $endDateTime,
			'video_link' => $video_link,
			'evaluation_url' => $evaluation_url,
			'entretien_url' => $entretien_url,

			'summary' => $subject,
			'description' => $description,
			'location' => $location,

			'uid' => $message->ical_uid->object,
			'seq' => $message->ical_seq->object,
			
			'organiser' => array(
				'name'=>$user->first_name->object.' '.$user->last_name->object,
				'email'=>$user->email->object
				// 'name'=>$user_name,'email'=>$user_email
			),
			/*
			'attendees' => array
			(
				array('name'=>$user_name,'email'=>$user_email)
			),
			*/

			'recruiter' => array('name'=>$user_name,'email'=>$user_email),
			'candidateName' => $interviewRecord->candidate_oid->string,
			'candidateOid' => $interviewRecord->candidate_oid->object,
		);

		// add all recruiters as attendees
		foreach($recruiters as $attendee)
		{
			$meetingRequest['attendees'][] = array('name'=>$attendee['name'],'email'=>$attendee['email']);
		}

		$email = new NxRecruitment_Email($this->ctxt);
        $toMsg = $proposed_to->first_name->html.' '.$proposed_to->last_name->html.'&lt;'.$proposed_to->email->html.'&gt;';

		if($email->sendMeetingUpdate($uid,$message, $meetingRequest, $proposed_to, $dsID,$cname))
            $this->ctxt->msgOkBs(__('invite update sent to').' '.$toMsg);
        else
            $this->ctxt->msgErrorBs(__('failure sending invite update to').' '.$toMsg);

		return true;
	}

	function sendCancelToRecruiter($uid,$message, $interviewRecord, $user, $proposed_to, $recruiters, $dsID='register_email') 
	{
		$dateStr = $interviewRecord->date->toHTML('%Y%m%d');
		$startDateTime = $interviewRecord->time_start->toTime();
		$endDateTime = $interviewRecord->time_end->toTime();
		$cname = $message->candidate_full_name->object;
		$subject = $message->user_subject->object;
		$description='';

		$location=$interviewRecord->location->html;
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

			'uid' => $message->ical_uid,
			'seq' => $message->ical_seq+1,
			
			'organiser' => array(
				'name'=>$user->first_name->object.' '.$user->last_name->object,
				'email'=>$user->email->object
				// 'name'=>$user_name,'email'=>$user_email
			),
			/*
			'attendees' => array
			(
				array('name'=>$user_name,'email'=>$user_email)
			),
			*/

			'recruiter' => array('name'=>$user_name,'email'=>$user_email),
			'candidateName' => $interviewRecord->candidate_oid->string,
			'candidateOid' => $interviewRecord->candidate_oid->object,
		);

		// add all recruiters as attendees
		foreach($recruiters as $attendee)
		{
			$meetingRequest['attendees'][] = array('name'=>$attendee['name'],'email'=>$attendee['email']);
		}

		$email = new NxRecruitment_Email($this->ctxt);
		$email->sendMeetingCancel($uid,$message, $meetingRequest, $proposed_to, $dsID,$cname);
		return true;
	}
	
	/**
		Fonction utilisée pour la programmation d'interviews et l'envoi de mails de manière massive
		L'upload se fait pour le premier élément et on copie le dossier créé pour le reste des items
	*/
	function uploadNCopyInterview($inseredOids, $handler_candidate, $handler_interviewer , $path) 
	{
		$stack = array(); // Liste des fichiers pour enregistrement dans la base de donnÃ©es  
		$folderToCopy = ''; // Chemin du dossier à  dupliquer

		for($i=0; $i<count($inseredOids); $i++)
		{
			$dbOid = $inseredOids[$i][0]; // Liste des oids des entretiens ou des emails
			$candidateOid = $inseredOids[$i][1]; // pas besoin pour l'instant ...
				
			if( $i == 0 ) 
			{
				// first candidate : upload files
				$stack = $this->uploadInterviewFiles($dbOid, $handler_candidate, $handler_interviewer, $path);
				//$folderToCopy = $this->getFilesUploadPath($dbOid, $path);
			} 
			else 
			{
				// other candidates : duplicatefiles

				// Nomenclature du dossier créé
				$newFolder = $this->getFilesUploadPath($dbOid, $path);

				// duplicate dir
				$fs = new NxPlug_FileSys($this->ctxt);	
				$fs->copyDir($folderToCopy,$newFolder,$mode=0777);

				// Enregistrement dans la base de données
				$this->ctxt->setProperty('object_oid', $dbOid);

				for($j=0; $j<count($stack); $j++) 
				{
					$this->ctxt->setProperty('file_name', $stack[$j]);
					$this->ctxt->putRecord($null=null, $handler, 'insert', 'db', 'Object', null);	
				}
			}			
		}

		return $stack;
	}
}

?>