<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_delete_candidate extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run($workflow,$user)
	{

		$this->setProperty('candidate_oid' , (isset($_REQUEST['oid'])?$_REQUEST['oid']:$_REQUEST['candidate_oid']));
		
		$candidatesRecords = $this->getRecords('rct_candidate.delete',null,'db');
		$this->deleteRecords('rct_candidate.delete',$candidatesRecords,'db',true);
		
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


		//DebugBreak();
        if(isset($_REQUEST['from_vacancy']) && $_REQUEST['from_vacancy']==1 ){
            // redirect to candidates list in vacancies
            $url = PORTAL_URL_PREFIX .'/recruitment/vacancies/admin/void-'.$_REQUEST['vacancy_oid'].'/directory.php?nxo=candidates&nxs=&oid='.$_REQUEST['vacancy_oid'].'&vacancy_oid='.$_REQUEST['vacancy_oid'].'&from_vac=1&mode=page' ;
        }else {
			if(isset($_REQUEST["src"]) && $_REQUEST["src"] ===  'newcvt'){
				$url = PORTAL_URL_PREFIX .'/recruitment3/home.php';
			}else{
				// redirect to list
				//$url = PORTAL_URL_PREFIX .'/recruitment/candidates/directory.php?nxo=list&nxs=' . preg_replace(array('%&amp;%', '%[+]%'), array('&', '%2B'), urldecode((isset($_REQUEST["filterKey"]) ? $_REQUEST["filterKey"] : "")));
				$url = PORTAL_URL_PREFIX .'/recruitment/candidates/directory.php?nxo=list&'.$this->getFilterKey();
			}
            
        }
		$this->setProperty('redirect_url.url',$url);
		$this->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);
		
		nxLog('redirect to '.$u,'redirect');
		return true;
	}
	
	function getFilterKey ()
	{
		$arg = explode('&', $_SERVER['QUERY_STRING']);
		$chaine_final = '';
		foreach( $arg as $value )
		{
			$arg2 = explode('=', $value);  
			if ($arg2[0]!= 'nxo' && $arg2[0]!= 'nxs' && $arg2[0]!= 'oid') {$chaine_final .= $value.'&';}   
		}
		return $chaine_final ;
	}
}
?>