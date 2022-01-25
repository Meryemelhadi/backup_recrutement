<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/


class Workflow_Task_send_to_ic extends Workflow_Task
{
	/*function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}*/

	function run($workflow,$user)
	{
        $this->ctxt->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
        $this->ctxt->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
        if($this->getParam('previous_operation')!=null){
            $this->ctxt->setProperty('previous_operation.url',PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo='.$this->getParam('previous_operation'));
        }else{
            $this->ctxt->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=associated_candidate&amp;nxs=&amp;oid='.$this->ctxt->getProperty("vacancy_oid",""));
        }
        $this->ctxt->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=send_to_ic_process&amp;nxs=&amp;vacancy_oid='.$this->ctxt->getProperty("vacancy_oid","").'&amp;candidate_oid='.$this->ctxt->getProperty("candidate_oid",""));
        $this->ctxt->getRecord('rct_candidate_vacancy_client.add@recruitment','page.record','empty',false,null,null);
        $this->ctxt->runView('/recruitment/vacancies/components/modalbox_form_bs',array('fmethod' => 'toHTML'),null);
        return true;
    }
}
?>