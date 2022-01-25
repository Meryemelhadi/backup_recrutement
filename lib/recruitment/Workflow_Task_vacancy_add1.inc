<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_vacancy_add extends NxPage
{
	function Workflow_Task_vacancy_add($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
		$this->ctxt = $this;
	}

	function run()
	{
		
		$this->getRecord('','','empty',false,null,null);
							
			
		$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
							
			
		$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process&amp;redirect=list');
							
			
		$this->setProperty('submit_continue.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process&amp;redirect=edit');
		
		$this->runView('_add',array(
					'fmethod' => 'toForm',

					),null);
		return true;
	}
}
?>