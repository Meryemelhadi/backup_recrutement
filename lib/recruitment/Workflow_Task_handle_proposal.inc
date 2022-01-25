<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/


class Workflow_Task_handle_proposal extends Workflow_Task
{

	function run($workflow,$user)
	{
        if(isset($_REQUEST["status_value"])){
            if($_REQUEST["status_value"] == 10){
                $workflow->title = __('accepted_proposal_title');
            }else if($_REQUEST["status_value"] == 11){
                $workflow->title = __('refused_proposal_title');
            }
            $this->ctxt->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
            $this->ctxt->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
            $this->ctxt->setProperty("status_value",(isset($_REQUEST["status_value"])?$_REQUEST["status_value"]:""));
            if($this->getParam('previous_operation')!=null){
                $this->ctxt->setProperty('previous_operation.url',PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo='.$this->getParam('previous_operation'));
            }else{
                $this->ctxt->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=associated_candidate&amp;nxs=&amp;oid='.$this->ctxt->getProperty("vacancy_oid",""));
            }
            $this->ctxt->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=handle_proposal_process&amp;nxs=&amp;vacancy_oid='.$this->ctxt->getProperty("vacancy_oid","").'&amp;candidate_oid='.$this->ctxt->getProperty("candidate_oid","").'&amp;status_value='.$this->ctxt->getProperty("status_value","").'&amp;status_value='.$this->ctxt->getProperty("status_value",""));
            $this->ctxt->getRecord('rct_candidate_vacancy.handle_proposal@recruitment','page.record','empty',false,null,null);
            $this->ctxt->runView('/recruitment/vacancies/components/handle_proposal_bs',array('fmethod' => 'toHTML'),null);

        }
        return true;
    }
}
?>