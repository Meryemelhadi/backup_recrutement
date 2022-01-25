<?php 

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');
include_once(NX_LIB.'ds/email/NxMail_MIME.inc');
include_once(dirname(dirname(dirname(dirname(__FILE__)))).'/email/NxRecruitment_Email.inc');

class lib_recruitment_vacancies_services_message
{
	var $ctxt;
	
	function lib_recruitment_vacancies_services_message($ctxt) {
		$this->ctxt = $ctxt;
		Framework::setContext($this->ctxt = $ctxt);
	}
	
	function interviewRequestEmail($interviewOids) {
	
		$ctxt = $this->ctxt;
		
		foreach($interviewOids as $interviewOid) {

			$ctxt->setProperty("interview_oid",$interviewOid[0]);
			$message = $ctxt->getRecord('rct_interview.request_email_data@recruitment','page.record','db',false,null,null);
			if( trim($message->manager_oid->db) == '' ) {
				return false;
			}

			$message->subject->db = $ctxt->getString("request_interview_email_subject").$message->name->db;
			// Récupération de la liste des emails des utilisateurs à notifier
			$ctxt->setProperty("user_oids",implode(',', explode('|', trim($message->manager_oid->db, '|'))));
			$usersMails = $ctxt->getRecords('user.get_emails@recruitment','page.records','db',false,null,null);	
			
			// Envoi à chaque candidat
			for ( $nx_iterRec = $usersMails->getRecordIterator(); $nx_iterRec->isValid(); $nx_iterRec->next()) {
				$userEmail=&$nx_iterRec->getCurrent();
				
				$message->first_name->db = ucwords($userEmail->first_name->db);		
				$message->body->db = $this->getEmailBody('request_interview_email_view');
				$message->to->db = $userEmail->email->db;
				
				$this->send($message);
			}
		}

	}

	/** Gestion des feedback et des warning en cron */
	function cronaction() {
		
		$ctxt = $this->ctxt;
		
		$delayedFeedbacks = $ctxt->getRecords('rct_delayed_feedback.email_data@recruitment','page.records','db',false,null,null);
		if( $delayedFeedbacks ) {
			for ( $nx_iterRec = $delayedFeedbacks->getRecordIterator(); $nx_iterRec->isValid(); $nx_iterRec->next()) {
				$message=&$nx_iterRec->getCurrent();
				$ctxt->setProperty("page.record",$message);
				$message->subject->db = $ctxt->getString("delayed_feedback_email_subject").$message->candidate_name->db;
				$message->body->db = $this->getEmailBody('cron_delayed_feedback_view');
				$this->send($message);			
			}
			$ctxt->putRecord($null=null,'rct_delayed_feedback.change_notification_state@recruitment','update','db','Object',null);
		}
		
			
		$warnings = $ctxt->getRecords('rct_warning.email_data@recruitment','page.records','db',false,null,null);
		if( $warnings ) {
			for ( $nx_iterRec = $warnings->getRecordIterator(); $nx_iterRec->isValid(); $nx_iterRec->next()) {
				$message=&$nx_iterRec->getCurrent();
				$ctxt->setProperty("page.record",$message);
				$message->subject->db = $ctxt->getString("warning_title").$message->notification_subject->db;
				$message->body->db = $this->getEmailBody("cron_warning_view");
				
				$ctxt->setProperty("user_oids",str_replace('|', ',', trim($message->concerned_people->db, '|')));
				$usersMails = $ctxt->getRecords('user.get_emails@recruitment','page.records','db',false,null,null);
				
				if( $usersMails ) {
					for ( $nx_iterRec2 = $usersMails->getRecordIterator(); $nx_iterRec2->isValid(); $nx_iterRec2->next()) {
						$userMail=&$nx_iterRec2->getCurrent();
						$message->to->db = $userMail->email->db;						
						$this->send($message);
					}
				}	
			}
			$ctxt->putRecord($null=null,'rct_warning.change_notification_state@recruitment','update','db','Object',null);
		}
		
		
		
	}

	function getEmailBody($view) {
		ob_start();
		$this->ctxt->runView($view,array('fmethod' => 'toHTML',),null);
		$_nx_ret0=ob_get_contents();
		ob_end_clean();
		return $_nx_ret0;
	}
	
	/** Notification de feedback */
	function sendInstantFeedackEmail($record_oid) {	
		$ctxt = $this->ctxt;
		$ctxt->setProperty("record_oid",$record_oid);
		$message = $ctxt->getRecord('rct_instant_feedback.email_data@recruitment','page.record','db',false,null,null);
		$message->subject->db = $ctxt->getString("instant_feedback_email_subject").$message->vacancy_name->db;
		$message->body->db = $this->getEmailBody('instant_feedback_email_view');
		$this->send($message);
	}

	/** Proposition d'un candidat au client interne */
	function sendCandidateNotificationEmail($record_oid) {
		
		$ctxt = $this->ctxt;
		
		$ctxt->setProperty("record_oid",$record_oid);
		
		$message = $ctxt->getRecord('rct_candidate_vacancy_client.email_data@recruitment','page.record','db',false,null,null);
		
		$message->subject->db = $ctxt->getString("mail_candidate_subject");
		$message->body->db = $this->getEmailBody('send_candidate_email_view');
		
		$ctxt->setProperty("user_oids",str_replace('|', ',', trim($message->client_oid->db, '|')));
		
		
		$usersMails = $ctxt->getRecords('user.get_emails@recruitment','page.records','db',false,null,null);
		
		if( ! $usersMails ) { return false; }
		
		for ( $nx_iterRec = $usersMails->getRecordIterator(); $nx_iterRec->isValid(); $nx_iterRec->next()) {
			$userMail=&$nx_iterRec->getCurrent();
			$message->to->db = $userMail->email->db;
			$this->send($message);
		}		
	}

	/** Proposition d'une short-list au client interne */
	function sendShortListNotificationEmail($record_oid) {
		
		$ctxt = $this->ctxt;
		
		$ctxt->setProperty("record_oid",$record_oid);
		$message = $ctxt->getRecord('rct_short_list_vacancy_client.email_data@recruitment','page.record','db',false,null,null);
		
		$message->subject->db = $ctxt->getString("mail_short_list_subject");
		$message->body->db = $this->getEmailBody('short_list_email_view');
		
		$ctxt->setProperty("user_oids",str_replace('|', ',', trim($message->client_oid->db, '|')));
		
		
		$usersMails = $ctxt->getRecords('user.get_emails@recruitment','page.records','db',false,null,null);
		
		if( ! $usersMails ) { return false; }
		
		for ( $nx_iterRec = $usersMails->getRecordIterator(); $nx_iterRec->isValid(); $nx_iterRec->next()) {
			$userMail=&$nx_iterRec->getCurrent();
			$message->to->db = $userMail->email->db;
			$this->send($message);
		}		
	}

	/** Sollicitation d'un prestataire de recrutement */
	function requireProvider($record_oid) {
		
		$ctxt = $this->ctxt;
		// Chemin des fichiers attachés		
		$filesPath = $this->ctxt->getProperty('pathUpload').'packages/recruitment/vacancy_providers/'.$record_oid.'/';
		
		$ctxt->setProperty("vacancy_provider_oid",$record_oid);
		$message = $ctxt->getRecord('rct_vacancy_provider.email_data@recruitment','page.record','db',false,null,null);
		$message->body->db = $this->getEmailBody('provider_email_view');
		$this->send($message, $filesPath);
	}

	/** Envoi d'email aux candidats */
	function sendEmail($inseredOids) {
		
		$ctxt = $this->ctxt;
		
		// Envoi de l'email aux candidats
		if( count($inseredOids) == 0 ) {
			return;
		}
		
		// Récupération du message type à envoyer
		$record_oid = $inseredOids[0][0];
		
		// Chemin des fichiers attachés		
		$filesPath = $this->ctxt->getProperty('pathUpload').'packages/recruitment/emails/'.$record_oid.'/';
		
		$ctxt->setProperty("email_oid",$record_oid);
		$message = $ctxt->getRecord('rct_email.email_data@recruitment','page.record','db',false,null,null);
		// Récupération de la liste des emails des candidats à notifier
		$candidates = array();
		for($i=0; $i<count($inseredOids); $i++) {
			array_push($candidates, $inseredOids[$i][1]);
		}
		$ctxt->setProperty("candidate_oids",implode(',', $candidates));
		$candidatesMails = $ctxt->getRecords('rct_candidate.get_emails@recruitment','page.records','db',false,null,null);
		// Corps de l'email		
		$message->body->db = $this->getEmailBody('email_view');
		// Envoi à chaque candidat		
		for ( $nx_iterRec = $candidatesMails->getRecordIterator(); $nx_iterRec->isValid(); $nx_iterRec->next()) {
			$candidateEmail=&$nx_iterRec->getCurrent();
			$message->to->db = $candidateEmail->email->db;
			$this->send($message, $filesPath);
		}
		
	}	
	
	/** Notification d'interview */
	function sendInterviewEmail($inseredOids) {
		
		$ctxt = $this->ctxt;
		
		// Envoi de l'email aux candidats
		if( count($inseredOids) == 0 ) {
			return;
		}
		
		// Récupération du message type à envoyer
		$interview_oid = $inseredOids[0][0];
		
		// Chemin des fichiers attachés		
		$filesPath = $this->ctxt->getProperty('pathUpload').'packages/recruitment/interviews/'.$interview_oid.'/';
		
		
		$ctxt->setProperty("interview_oid",$interview_oid);
		$message = $ctxt->getRecord('rct_interview.email_data@recruitment','page.record','db',false,null,null);
		
		// Emails des candidats
		if( $message->candidate_email_not->db == '1' ) {		
			// Récupération de la liste des emails des candidats à notifier
			$candidates = array();
			for($i=0; $i<count($inseredOids); $i++) {
				array_push($candidates, $inseredOids[$i][1]);
			}
			$ctxt->setProperty("candidate_oids",implode(',', $candidates));
			$candidatesMails = $ctxt->getRecords('rct_candidate.get_emails@recruitment','page.records','db',false,null,null);
			// Corps de l'email		
			$message->body->db = $this->getEmailBody('interview_email_view');
			// Envoi à chaque candidat		
			for ( $nx_iterRec = $candidatesMails->getRecordIterator(); $nx_iterRec->isValid(); $nx_iterRec->next()) {
				$candidateEmail=&$nx_iterRec->getCurrent();
				$message->to->db = $candidateEmail->email->db;
				$this->send($message, $filesPath);
			}
		}
				
		if( $message->interviewer_email_not->db == '1' ) {
					
			$message->to->db = $message->user_email->db;
			$message->subject = $message->user_subject;
			$message->body = $message->user_body;
			
			$message->body->db = $this->getEmailBody('interview_email_view');
			
			$message->files->string = '';
			$this->send($message, $filesPath);
		}
	}	
	
	/** Notification de la création d'un nouveau dossier */
	function vacancyRequest($vacancyOid) {
	
		$ctxt = $this->ctxt;
		
		$ctxt->setProperty("vacancy_oid",$vacancyOid);
		$message = $ctxt->getRecord('rct_vacancy.request_email_data@recruitment','page.record','db',false,null,null);
		$message->subject->db = $ctxt->getString("request_vacancy_email_subject").$message->name->db;
		
		if( trim($message->manager_oid->db) == '' ) {
			return false;
		}
		
		// Récupération de la liste des emails des utilisateurs à notifier
		$ctxt->setProperty("user_oids",implode(',', explode('|', trim($message->manager_oid->db, '|'))));
		$usersMails = $ctxt->getRecords('user.get_emails@recruitment','page.records','db',false,null,null);	
		
		
		// Envoi à chaque candidat
		for ( $nx_iterRec = $usersMails->getRecordIterator(); $nx_iterRec->isValid(); $nx_iterRec->next()) {
			$userEmail=&$nx_iterRec->getCurrent();
			
			$message->first_name->db = ucwords($userEmail->first_name->db);
			$message->body->db = $this->getEmailBody('request_vacancy_email_view');
			$message->to->db = $userEmail->email->db;
			
			$this->send($message);
		}
	}
	
	function send($message, $filesPath = '', $dsID='register_email') {
	
		$email = new NxRecruitment_Email($this->ctxt);
		return $email->send($message, $filesPath, $dsID);
	}
	
	function testEmail(&$record) {
		
		$message = $this->ctxt->getRecord('rct_vacancy.request_email_data@recruitment','page.record','empty',false,null,null);
		$message->subject->db = "Email de test";
		$message->body->db = "Email de test";
		
		$message->to->db = $record->email_one->db;
		$record->email_one_log->db = $this->send($message);
		
		$message->to->db = $record->email_two->db;
		$record->email_two_log->db = $this->send($message);

	}

}

?>