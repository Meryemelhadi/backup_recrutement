<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_add_candidate extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run()
	{
		//Permission DRH
		$drh = "";
		if($GLOBALS['_NX_user']->checkPerm('?-drh')) $drh = "-drh";
		
		$this->getRecord('rct_candidate.add'.$drh,'page.record','empty',false,null,null);
		
		$this->setProperty('list.url',
				$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					
		
		$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=add_process&amp;filterKey='.urlencode($_REQUEST["filterKey"]));

		$this->runView('/recruitment/candidates/add',array('fmethod' => 'toHTML',),null);

		return true;
	}
}
?>