<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/


class Workflow_Task_edit_integration_date_process extends Workflow_Task
{

	function run($workflow,$user)
	{
        $this->ctxt->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
        $this->ctxt->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
        $this->ctxt->putRecord(
            $this->ctxt->getRecord('rct_candidate_vacancy.edit_integration_date@recruitment','page.record','post',false,null,null),'rct_candidate_vacancy.edit_integration_date@recruitment','update','db','Object',null);
			
		/** Edit field integration_date : table rct_candidate ***/
		$o =  new PersistentObject('rct_candidate.set_integration_date@recruitment' , 'db');
		$o->setFieldValue('integration_date' , $_POST['integration_date'] );
		$o->store('rct_candidate.set_integration_date@recruitment', 'update' , 'db');
		
		
        return true;
    }
}
?>