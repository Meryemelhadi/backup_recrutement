<?php


require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_send_cvs_to_many_client_display extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}
	
	function run($workflow,$user)
	{
	
		$this->setProperty("candidates_oid",(isset($_REQUEST["candidates_oid"])?$_REQUEST["candidates_oid"]:""));
		$this->getRecord('rct_candidate_client.add_many','page.record','empty',false,null,null);
		$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
		$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=send_cvs_to_many_client&amp;nxs=process&amp;candidates_oid='.(isset($_REQUEST["candidates_oid"])?$_REQUEST["candidates_oid"]:""));
		$this->runView('recruitment/candidates/components/send_cvs_to_client',array('fmethod' => 'toForm',),null);
		return true;
	}
	
	
}
?>