<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__send_sl_to_ic_send_sl_to_ic extends NxPage
{
	function recruitment_vacancies_admin_directory__send_sl_to_ic_send_sl_to_ic($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("short_list_oid",(isset($_REQUEST["short_list_oid"])?$_REQUEST["short_list_oid"]:""));
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=shorts_list&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=send_sl_to_ic_process&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;short_list_oid='.$this->getProperty("short_list_oid",""));
					$this->getRecord('rct_short_list_vacancy_client.add@recruitment','page.record','empty',false,null,null);
					$this->runView('/recruitment/vacancies/admin/directory__send_sl_to_ic',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>