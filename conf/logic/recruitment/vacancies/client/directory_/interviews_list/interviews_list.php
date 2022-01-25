<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__interviews_list_interviews_list extends NxPage
{
	function recruitment_vacancies_client_directory__interviews_list_interviews_list($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecords('rct_interview.ds_calendar_list@recruitment','page.records','db',false,null,null);
					$this->setProperty('edit_interview.url',$_SERVER["PHP_SELF"].'?nxo=edit_interview&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty('validate_interview.url',$_SERVER["PHP_SELF"].'?nxo=validate_interview&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->runView('/recruitment/vacancies/client/directory__interviews_list',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>