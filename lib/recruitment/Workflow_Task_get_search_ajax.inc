<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_get_search_ajax extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run($workflow,$user)
	{
		$searchRecord = $this->getRecord('saved_search.record',null,'db');
		echo $searchRecord->url->object.'&search_oid='.$searchRecord->oid->object;
	}
}
?>