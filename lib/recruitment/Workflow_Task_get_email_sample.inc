<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_get_email_sample extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
	}

	function run($workflow, $user)
	{
		
		$this->getRecord('rct_email_sample.record','page.record','db',false,null,null);
		$this->runView('recruitment.vacancies.components.email_sample',array(
			'fmethod' => 'toHTML',

			),null);
		return true;
	}
}
?>