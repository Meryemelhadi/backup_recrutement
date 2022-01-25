<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__my_calendar_my_calendar extends NxPage
{
	function recruitment_vacancies_admin_directory__my_calendar_my_calendar($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty('interviews_list.url',$_SERVER["PHP_SELF"].'?nxo=my_interviews_list&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty("ics_export.url",
								PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=ics_export'
							);
					$this->runView('/recruitment/vacancies/admin/directory__my_calendar',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>