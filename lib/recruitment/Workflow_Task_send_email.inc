<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');
include_once(GENERIS_PACKAGES.'recruitment/lib/email/NxEmailBase.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_send_email  extends Workflow_Task
{
	function getEmailRecord($workflow) {
		return $workflow->record;
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
				//$name = $doc->name->string;
				$name = $doc->file->n;
				if(!$name)
					$name = basename($filePath);
				$files[$name] = $filePath;
			}
		}

		return $files;
	}

	/** Envoi d'email aux candidats */
	function sendEmail($workflow, $user, $fromUser,$aApplicants,$emailRecord,$dsID='register_email') {
			
		global $RECRUITMENT_MAILTITLE;
		global $RECRUITMENT_MAILSUBTITLE;

		// file system
		$fs = Framework::fs();

		$subjectTpl = $emailRecord->email_title->string;
		$contentTpl = $emailRecord->email_content->object;
		//DebugBreak();
		$this->ctxt->setProperty("register_email.cc" , $emailRecord->user_cc->string);
		$view = $workflow->model->getDisplayView('email_view');
		$from = $fromUser->email->object;

		
		// attach files
		$files = $this->getAttachedDocs($emailRecord->docs);

		// additional files
		$files2 = $this->getAdditionalFiles($emailRecord->attached_files);
		foreach($files2 as $name=>$path)
		{
			if(isset($files[$name]))
				$name = "{$name}_1";

			$files[$name] = $path;
		}

		foreach($aApplicants as $applicant)
		{
			$message = new NxEmailBase($this->ctxt);

			// create message object for sending by email
			$to		  = $applicant->email->object;
			$candidate_oid = $applicant->oid->object;

			$subject  = $message->mapMacros($subjectTpl,$user,$applicant);
			$content  = $message->mapMacros($contentTpl,$user,$applicant);

			$body	  = '';
			$mime = $message->getMimeMessage($from,$to,$subject,$body,$dsID);

			// attach HTML body
			// $content  = preg_replace('%\n%','<br/>',$content);
			$htmlBody = $message->getEmailBody($view,array(
				'email.title' => $RECRUITMENT_MAILTITLE,
				'email.baseline' => $RECRUITMENT_MAILSUBTITLE,

				'subject'=>$subject,
				'message' => $content,
				));
			$message->attachHTML($mime,$htmlBody);

			// attach files from doc library
			foreach($files as $fileName => $path)
			{
				$fileContent = $fs->file_get_contents($path);
				if($fileContent)
					$mime->attach($fileContent, 'file', OCTET, BASE64, "attachment; filename=\"$fileName\"");
			}

			if (!$mime->send_mail()) 
			{
				nxLog('Failed: LOG:<pre>'.$mime->getLog('html').'</pre>','EMAIL');
				$this->ctxt->msgErrorBs(__('Message non envoyé au candidat ('.$to.')'));
			}
			else
			{
				$emailRecord->email_title->object   = $subject;
				$emailRecord->email_content->object = $content;
				$dml = $workflow->model->getDS('record_by_oid',$workflow->getState());
				if($dml)
				{
					$emailO = new PersistentObject();
					$emailO->setRecord($emailRecord);
					$emailO->store($dml,'update','db',array('oid'=>$emailRecord->oid->object));
				}

				$this->addLog($candidate_oid,$user);
				$this->ctxt->msgOkBs(__('Message envoyé au candidat ('.$to.')'));
			}
		}

		return true;	
	}

	function getAdditionalFiles($filesField) {
		$files = array();

		$fileRecords = $filesField->toRecords();
		if(!$fileRecords)
			return $files;

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

	function getApplicantRecords($workflow,$oids) {

		$csvOids = implode(',', explode('|',trim($oids,'|')));

		$applicants = new PersistentCollection('rct_candidate.get_emails@recruitment','db',array('candidate_oids'=>$csvOids));

		if($applicants->isOk())
			return $applicants->array;

		return null;
	}

	function addLog($candidate_oid,$user) {

		$log= new lib_recruitment_candidates_services_log($this->ctxt);
		$log->addLog($candidate_oid , $user->oid->object , 7 , '' , '');
		
		/*$entry = new PersistentObject('rct_candidate_action.record@recruitment','empty');
		
		$entry->candidate_oid = $candidate_oid;
		$entry->user_oid = $user->oid->object;
		$entry->action_oid = 7;
		$entry->ref_oid = '';
		$entry->additional_infos = '';

		$entry->store('rct_candidate_action.record@recruitment','insert');*/
	}
	

	function run($workflow, $user)
	{
		if(!isset($_REQUEST['coid']) || !$_REQUEST['coid'] )
		{
			$this->ctxt->msgOk(__('Problème d\'envoi, pas de candidat sélectionné.'));
			return true;
		}

		// get applicants
		$candidate_oid = $_REQUEST['coid'];
		$aApplicants = $this->getApplicantRecords($workflow,$candidate_oid);

		// get email record from form
		$emailRecord = $workflow->record;
		$docs = $emailRecord->docs->object;
		if($emailRecord)
		{
			$this->sendEmail($workflow, $user, $from=$user,$aApplicants,$emailRecord,'register_email');
		}
		else
			$this->ctxt->msgOk(__('Message non envoyé.'));

		return true;
	}
}
?>