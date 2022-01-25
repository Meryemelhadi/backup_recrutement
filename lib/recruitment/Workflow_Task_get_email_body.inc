<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_get_email_body  extends Workflow_Task
{
	
	function run($workflow, $user)
	{
		if(!isset($_REQUEST['oid']) )
		{
			return true;
		}

		// get applicants
		$this->ctxt->getRecord('rct_candidate_email.get_email_content@recruitment','email.record','db',false,null,null);
		$this->ctxt->runView('/recruitment/candidates/components/email_content',array('fmethod' => 'toHTML',),null);
		
		return true;
	}
}
?>