<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_admin_manage_recruitment_reasons__edit_ajax_input extends NxPage
{
	function recruitment_admin_manage_recruitment_reasons__edit_ajax_input($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecord('rct_recruitment_reason.record','page.record','db',false,null,null);
					$this->setProperty("page_message",$this->getString("page_message_edit"));
					$this->setProperty('back.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process');
					$this->runView('/recruitment/admin/manage_recruitment_reasons__edit',array(
						'fmethod' => 'toForm',

						),null);
		return true;
	}
}
?>