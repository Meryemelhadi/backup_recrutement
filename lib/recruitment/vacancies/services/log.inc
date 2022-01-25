<?php
require_once(NX_LIB.'framework.inc');
class lib_recruitment_vacancies_services_log
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
    function addLog($vacancy_oid , $user_oid , $action_oid , $ref_oid, $additional_infos )
    {
        $entry = new PersistentObject('rct_vacancy_action.record@recruitment','empty');
        $entry->vacancy_oid = $vacancy_oid;
        $entry->user_oid = $user_oid;
        $entry->action_oid = $action_oid;
        $entry->ref_oid = $ref_oid;
        $entry->additional_infos = $additional_infos;
        $entry->store('rct_vacancy_action.record@recruitment','insert');
    }

    /*
     * Add log for edit vacancy information
     */
    function addEditLogs($vacancy_oid , $user_oid , $action_oid , $ref_oid, $additional_infos){
        $log = new PersistentObject('rct_vacancy_action.get_today_edit_action@recruitment','db');
        if(!$log->isOk()){
            $this->addLog($vacancy_oid , $user_oid , $action_oid , $ref_oid, $additional_infos);
        }
    }
	
	/*
     * Delete log
     */
    function deleteVacancyLogs($vacancy_oid)
    {	
		$actions = new PersistentCollection('rct_vacancy_action.by_vacancy_oid','db',array('vacancy_oid'=>$vacancy_oid));
		if($actions->count())
			$actions->delete('rct_vacancy_action.by_vacancy_oid','db',array('vacancy_oid'=>$vacancy_oid));
    }
}