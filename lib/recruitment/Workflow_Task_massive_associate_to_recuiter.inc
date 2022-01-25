<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_massive_associate_to_recuiter extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run()
	{
	
		$this->setProperty("candidates_oid",(isset($_REQUEST["candidates_oid"])?$_REQUEST["candidates_oid"]:""));
		$this->getRecord('rct_candidate.set_massive_hr_manager','page.record','empty',false,null,null);
		$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
		$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=massive_associate_to_recuiter_process&amp;candidates_oid='.(isset($_REQUEST["candidates_oid"])?$_REQUEST["candidates_oid"]:""));
					
					
		$this->runView('recruitment.candidates.components.massive_associate_to_recuiter',array(
						'fmethod' => 'toForm',
						),null);

		return true;
	}
}
?>