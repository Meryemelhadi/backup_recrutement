<?php 

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');
include_once(NX_LIB.'ds/email/NxMail_MIME.inc');

include_once(GENERIS_PACKAGES.'recruitment/lib/email/NxRecruitment_Email.inc');
include_once(GENERIS_PACKAGES.'recruitment/lib/email/ManageEmails.inc');

class lib_recruitment_candidates_services_message
{
	var $ctxt;
	
	function __construct($ctxt) {
		$this->ctxt = $ctxt;
		Framework::setContext($this->ctxt = $ctxt);
	}

	function getEmailBody($view) {
		ob_start();
		$this->ctxt->runView($view,array('fmethod' => 'toHTML',),null);
		$_nx_ret0=ob_get_contents();
		ob_end_clean();
		return $_nx_ret0;
	}
	
	function sendToClient($relationOid) {

		$this->ctxt->setProperty("relation_oid",$relationOid);
		$message = $this->ctxt->getRecord('rct_candidate_client.send_to_client@recruitment','page.record','db',false,null,null);
		$proposedToOid = $message->proposed_to->object;	
		if( trim($message->to->db) == '' ) {
			return false;
		}

		$filesPath = dirname($message->cv_path->path).'/';

		$message->subject->db = $this->ctxt->getString("new_candidate_proposal_notification");
		$message->files->db = basename($message->cv_path->path);
		
		$email = new NxRecruitment_Email($this->ctxt);
		$message->body->db = $email->getEmailBody('send_to_client_email_view');

		$proposed_to = new PersistentObject('user.get_email@recruitment','db',array("user_oid"=>$proposedToOid));
		$cvname = $message->candidate->string;

		$email->sendWithCV($message, $filesPath,$cvname,$proposed_to);
	}


	function sendToManyClients($relationOid) {
		
		$this->ctxt->setProperty("relation_oid",$relationOid);
		$m=new PersistentObject('rct_candidate_client.send_to_client@recruitment@recruitment','db',null);
		$this->ctxt->setProperty('page.record',$m->record);
		$messages = new PersistentCollection('rct_candidate_client.send_to_clients@recruitment','db',null);

		foreach($messages->array as $message) 
		{
			$filesPath = dirname($message->cv_path->path).'/';
			$message->subject->db = $this->ctxt->getString("new_candidate_proposal_notification");
			// $message->files->db = basename($message->cv_path->path);

			$email = new NxRecruitment_Email($this->ctxt);
			$mail=explode("|", $message->to->db);
			if($mail[1] == ""){return false;}
			
			$cvnames = $message->candidate->string;
			$proposed_to = new PersistentObject('user.get_email@recruitment','db',array("user_oid"=>$mail[1]));
			
			$message->to->db = $proposed_to->email->db;
			$message->body->db = $email->getEmailBody('send_to_client_email_view');
			
			$email->sendWithCV($message, $filesPath,$cvnames,$proposed_to);
		}		
	}

	function sendManyCvsToManyClients($relationOid) {

        $message = new PersistentObject(
            'rct_candidate_client.send_to_many_clients@recruitment','db',
            array("relation_oid"=>$relationOid)
        );
		$this->ctxt->setProperty('page.record',$message->record);

		if( trim($message->proposed_to->db) == '' ) {
			return false;
		}

		// get files
        if(!isset($_REQUEST['candidates_oid']))
            return false;

		$candidateOids = explode('|',trim($_REQUEST['candidates_oid'],'|'));
            
        // candidate list
        $message->candidate_oid->db = $_REQUEST['candidates_oid'];

        // get names and cv files            
        $candidates = new PersistentCollection('candidates.list@recruitment','db',
            array("candidates_oid"=>$_REQUEST['candidates_oid']));
		$filesPath='|';
		$files = array();
		$cvnames = array();
		$first = true;
		foreach($candidates->array as $c) {
			$files[] = $c->cv_path->path;
			$cvnames[]="{$c->first_name->string}_{$c->last_name->string}";
			if(!$first) $message->candidate->db .= " et ";
			else{
				$first = false;
				$message->candidate->db="";
			}
			$message->candidate->db .= " {$c->first_name->string} {$c->last_name->string}";
		}
		$message->files->db = $filesPaths=implode('|||',$files);

        // email subject
		$message->subject->db = $this->ctxt->getString("new_candidate_proposal_notification");
        
        // email sendee
		$emails= explode(',', $message->proposed_to->string);	

        // email body
		$email = new NxRecruitment_Email($this->ctxt);
		$message->body->db = $email->getEmailBody('send_to_client_email_view');

        // send message to each client
		for($i=0; $i<count($emails);$i++) 
		{
			$proposed_to = new PersistentObject('user.get_email@recruitment','db',array("user_oid"=>$emails[$i]));
				$message->to->db = $proposed_to->email->db;
			$email->sendWithManyCV($message,'','register_email',$cvnames,$files,$candidateOids,$proposed_to);
		}
	}

	/** Notification de feedback */
	function newCandidateNotification($candidate_oid) {
		
		$ctxt = $this->ctxt;
		$ctxt->setProperty("candidate_oid",$candidate_oid);
		$message = $ctxt->getRecord('rct_candidate.email_notification@recruitment','page.record','db',false,null,null);
		
		$emails = explode(';', $message->email->db);
		if( $emails[0] == '' ) {
			return false;
		}
		for($i=0; $i<count($emails);$i++) {
			$message->to->db = $emails[$i];
			$message->subject->db = $ctxt->getString("new_candidate_email_subject");
			$message->body->db = $this->getEmailBody('new_candidate_email_notification');
			$this->send($message);
		}
 		
	}
	
	function associateWithVacancy($candidate_oid, $subject) {
		
		$ctxt = $this->ctxt;
		if( ! preg_match('/\[(.+)-(.+)\]/is', $subject, $matches) ) {
			return false;
		}
		
		$providerCode = $matches[1];
		$vacancyCode = $matches[2];
		
		$ctxt->setProperty("provider_code",$providerCode);
		$ctxt->setProperty("vacancy_code",$vacancyCode);	
		
		// On recherche l'association dossier/fournisseur
		$relationRecord = $ctxt->getRecord('rct_vacancy_provider.find_relation@recruitment','page.record','db',false,null,null);
		
		// On crée la relation si elle n'existe pas
		if( ! $relationRecord ) {
			
			// Récupération de l'oid du dossier
			$vacancyRecord = $ctxt->getRecord('rct_vacancy.find_by_code@recruitment','page.record','db',false,null,null);
			if( ! $vacancyRecord ) {
				return false;
			}
			$ctxt->setProperty("vacancy_oid",$vacancyRecord->oid->db);
			
			
			// récupération de l'oid du provider
			$providerRecord = $ctxt->getRecord('rct_provider.find_by_code@recruitment','page.record','db',false,null,null);
			if( ! $providerRecord ) {
				return false;
			}
			$ctxt->setProperty("provider_oid",$providerRecord->oid->db);
			
			// New relation record
			$relationRecord = new PersistentObject('rct_vacancy_provider.add@recruitment','empty');
			$relationRecord->provider_oid = $providerRecord->oid->db;
			$relationRecord->store('rct_vacancy_provider.add@recruitment','insert','db');	
		} else {
			$ctxt->setProperty("vacancy_oid",$relationRecord->vacancy_oid->db);
			$ctxt->setProperty("provider_oid",$relationRecord->provider_oid->db);
		}
				
		// Vérifie si le candidat n'est pas déjà associé au dossier
		$ctxt->setProperty("candidate_oid",$candidate_oid);

		
		// Tentative de récupération de l'association dossier/candidat
		$candidateVacancyRecord = $ctxt->getRecord('rct_candidate_vacancy.get_assoc@recruitment','page.record','db',false,null,null);
		// On crée l'association si elle n'existe pas
		if( ! $candidateVacancyRecord ) {
			$candidateVacancyRecord = new PersistentObject('rct_candidate_vacancy.add_assoc@recruitment','empty');	
			$candidateVacancyRecord->store('rct_candidate_vacancy.add_assoc@recruitment','insert','db');
		}
		
		// On met à jour l'association en indiquant la provenance du CV avec l'oid du fournisseur	
		$ctxt->putRecord($null=null,'rct_candidate_vacancy.update_provider@recruitment','update','db','Object',null);
	}

	function send($message, $filesPath = '', $dsID='register_email') {
		$email = new NxRecruitment_Email($this->ctxt);
		$email->send($message, $filesPath, $dsID);
	}

}

?>