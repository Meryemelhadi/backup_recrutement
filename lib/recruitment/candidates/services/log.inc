<?php
require_once(NX_LIB.'framework.inc');
class lib_recruitment_candidates_services_log
{
    var $ctxt;

    function __construct($ctxt)
    {
        $this->ctxt = $ctxt;
        Framework::setContext($this->ctxt = $ctxt);
    }

    /*
     * Add log
     */
    function addLog($candidate_oid , $user_oid , $action_oid , $ref_oid, $additional_infos ,  $vacancy_oid = null , $date = null)
    {
        $entry = new PersistentObject('rct_candidate_action_add_record@recruitment','empty');
        $entry->candidate_oid = $candidate_oid;
        $entry->user_oid = $user_oid;
        $entry->action_oid = $action_oid;
        $entry->ref_oid = $ref_oid;
		$entry->vacancy_oid = $vacancy_oid;
        $entry->additional_infos = $additional_infos;
		if($date != null)
			$entry->date->db = $date;
        $entry->store('rct_candidate_action.record@recruitment','insert');
    }

    /*
     * Add log for edit candidate information
     */
    function addEditLogs($candidate_oid , $user_oid , $action_oid , $ref_oid, $additional_infos , $vacancy_oid = null){
        $log = new PersistentObject('rct_candidate_action.get_today_edit_action@recruitment','db');
        if(!$log->isOk()){
            $this->addLog($candidate_oid , $user_oid , $action_oid , $ref_oid, $additional_infos , $vacancy_oid);
        }
    }
	
	/*
     * Add log vacancy candidate
     */
    function addLogVacancy_Candidat($candidate_oid , $vacancy_oid , $user_oid , $action_oid , $ref_oid, $additional_infos )
    {
        $entry = new PersistentObject('rct_candidate_vacancy_action.record@recruitment','empty');
        $entry->candidate_oid = $candidate_oid;
		$entry->vacancy_oid = $vacancy_oid;
        $entry->user_oid = $user_oid;
        $entry->action_oid = $action_oid;
        $entry->ref_oid = $ref_oid;
        $entry->additional_infos = $additional_infos;
        $entry->store('rct_candidate_vacancy_action.record@recruitment','insert');
    }
	
	/*
     * Delete log
     */
    function deleteCandidateLogs($candidate_oid)
    {	
		$actions = new PersistentCollection('rct_candidate_action.by_candidate','db',array('candidate_oid'=>$candidate_oid));
		if($actions->count())
			$actions->delete('rct_candidate_action.by_candidate','db',array('candidate_oid'=>$candidate_oid));
    }
}