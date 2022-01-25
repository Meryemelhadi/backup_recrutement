<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__details_description_input extends NxPage
{
	function recruitment_vacancies_admin_directory__details_description_input($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecord('rct_entreprise_description_rekrute.record','page.record','db',false,null,null);
					$this->setProperty("page_message",$this->getString("page_message_show"));
					$this->setProperty('back.url',$_SERVER["PHP_SELF"].'?nxo=list_description&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""));
					$this->runView('/recruitment/vacancies/admin/directory__show',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>