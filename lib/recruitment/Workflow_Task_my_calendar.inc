<?php

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_my_calendar extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run()
	{
		
		$this->getRecords('rct_interview.ds_calendar_list@recruitment','page.records','db',false,null,null);
		$this->setProperty('edit_interview.url',$_SERVER["PHP_SELF"].'?nxo=edit_interview&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:"").'&amp;operation=');
		$this->setProperty('validate_interview.url',$_SERVER["PHP_SELF"].'?nxo=validate_interview&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
		$this->runView('_interviews_list',array(
							'fmethod' => 'toHTML',	),null);$this->setProperty('interviews_list.url',$_SERVER["PHP_SELF"].'?nxo=my_interviews_list&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
		$this->runView('/recruitment/vacancies/my_calendar_list',array('fmethod' => 'toHTML'),null);
		return true;
	}
}
?>