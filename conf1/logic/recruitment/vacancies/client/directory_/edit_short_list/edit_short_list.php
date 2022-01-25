<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__edit_short_list_edit_short_list extends NxPage
{
	function recruitment_vacancies_client_directory__edit_short_list_edit_short_list($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("sl_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->getRecord('rct_short_list.edit@recruitment','page.record','db',false,null,null);
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=candidates&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=edit_short_list_process&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->runView('/recruitment/vacancies/client/directory__short_list_edit',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>