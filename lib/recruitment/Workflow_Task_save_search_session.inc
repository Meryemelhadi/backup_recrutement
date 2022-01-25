<?php


include_once(NX_LIB.'framework.inc');

class Workflow_Task_save_search_session extends Workflow_Task
{
    function run($workflow, $user)
    {
        $dml = $this->getParam('get_default_search', 'search_params.default@recruitment');
        $search = new PersistentObject();
        $search->load($dml, 'db');
		session_start();
        $_SESSION["recruitment_default_search"] = explode('|', $search->getField('fields')->value);
    }
}

?>