<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_annuaire_directory__add_add extends NxPage
{
	function recruitment_annuaire_directory__add_add($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecord('rct_client','page.record','empty',false,null,null);
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=add_process');
					$this->setProperty("page_message",$this->getString("page_message_add"));
					$this->setProperty('back.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					$this->runView('/recruitment/annuaire/directory__add',array(
						'fmethod' => 'toForm',

						),null);
		return true;
	}
}
?>