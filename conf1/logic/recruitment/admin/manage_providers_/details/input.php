<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_admin_manage_providers__details_input extends NxPage
{
	function recruitment_admin_manage_providers__details_input($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecord('rct_provider.record','page.record','db',false,null,null);
					$this->setProperty("page_message",$this->getString("page_message_show"));
					$this->setProperty('back.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					$this->runView('/recruitment/admin/manage_providers__show',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>