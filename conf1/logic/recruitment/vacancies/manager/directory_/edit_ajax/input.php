<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__edit_ajax_input extends NxPage
{
	function recruitment_vacancies_manager_directory__edit_ajax_input($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecord('rct_entreprise_description_rekrute.record','page.record','db',false,null,null);
					$this->setProperty("page_message",$this->getString("page_message_edit"));
					$this->setProperty('back.url',$_SERVER["PHP_SELF"].'?nxo=list_description&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process');
					$this->runView('/recruitment/vacancies/manager/directory__edit_description',array(
						'fmethod' => 'toForm',

						),null);
		return true;
	}
}
?>