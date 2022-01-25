<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/


class Workflow_Task_edit_integration_date extends Workflow_Task
{

	function run($workflow,$user)
	{
        $this->ctxt->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
        $this->ctxt->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
        $this->ctxt->setProperty('previous_operation.url',PORTAL_URL_PREFIX.'/recruitment/candidates/coid-'.$_REQUEST["candidate_oid"].'/directory.php?nxo=edit&oid=14663&tab=vacancies');
        $this->ctxt->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=edit_integration_date_process&amp;nxs=&amp;vacancy_oid='.$this->ctxt->getProperty("vacancy_oid","").'&amp;candidate_oid='.$this->ctxt->getProperty("candidate_oid",""));
        $this->ctxt->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
        $this->ctxt->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
		$this->ctxt->getRecord('rct_candidate_vacancy.edit_integration_date@recruitment','page.record','db',false,null,null);
        $this->ctxt->runView('/recruitment/vacancies/components/modalbox_form_bs',array('fmethod' => 'toHTML'),null);
        return true;
    }
}
?>