<?php

require_once(NX_LIB.'module/NxPage.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_delete_cvs extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run()
	{
		
		$candidates_oid=(isset($_REQUEST["candidates_oid"])?$_REQUEST["candidates_oid"]:"");
		$candidates_oids = explode('|', $candidates_oid);

		foreach($candidates_oids as $i=>$oid)
		{
			if($oid != ''){
				$_REQUEST['oid'] = $oid;
				$candidatesRecords = $this->getRecords('rct_candidate.delete_cv',null,'db');
				$this->deleteRecords('rct_candidate.delete_cv',$candidatesRecords,'db',true);

				//delete related records : actions
				$log= new lib_recruitment_candidates_services_log($this->ctxt);
				$log->deleteCandidateLogs($oid);
				/*$actions = new PersistentCollection('rct_candidate_action.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));
				if($actions->count())
					$actions->delete('rct_candidate_action.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));*/

				//delete related records : clients
				$clients = new PersistentCollection('rct_candidate_client.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));
				if($clients->count())
					$clients->delete('rct_candidate_client.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));

				//delete related records : comments
				$comments = new PersistentCollection('rct_candidate_comment.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));
				if($comments->count())
					$comments->delete('rct_candidate_comment.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));

				//delete related records : etats
				$etats = new PersistentCollection('rct_candidate_etat_assoc.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));
				if($etats->count())
					$etats->delete('rct_candidate_etat_assoc.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));

				//delete related records : keywords
				$keywords = new PersistentCollection('rct_candidate_keywords.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));
				if($keywords->count())
					$keywords->delete('rct_candidate_keywords.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));
			
				//delete related records : short_lists
				$short_lists = new PersistentCollection('rct_candidate_short_list.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));
				if($short_lists->count())
					$short_lists->delete('rct_candidate_short_list.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));

				//delete related records : read_states
				$read_state = new PersistentCollection('rct_candidate_read_state.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));
				if($read_state->count())
					$read_state->delete('rct_candidate_read_state.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));


				// delete related records : emails
				$emails = new PersistentCollection('rct_candidate_email.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));
				if($emails->count())
					$emails->delete('rct_candidate_email.by_candidate','db',array('candidate_oid'=>$_REQUEST['oid']));

				// delete related records : interviews
				$interviews = new PersistentCollection('rct_interview.candidate_interviews','db',array('candidate_oid'=>$_REQUEST['oid']));
				if($interviews->count())
					$interviews->delete('rct_interview.candidate_interviews','db',array('candidate_oid'=>$_REQUEST['oid']));

				// delete related records : vacancies
				$vacancies = new PersistentCollection('rct_candidate_vacancy.candidate_vacancies','db', array('candidate_oid'=>$_REQUEST['oid']));
				if($vacancies->count())
					$vacancies->delete('rct_candidate_vacancy.candidate_vacancies','db',array('candidate_oid'=>$_REQUEST['oid']));
			}
			
		}
		
		$this->setProperty("filterKey",(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""));
		header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=list&nxs='.preg_replace(array('%&amp;%','%[+]%'),array('&','%2B'),urldecode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""))).'&mode=ajax'));
		nxLog('redirect to '.$u,'redirect');
		
		return true;

	}
}
?>