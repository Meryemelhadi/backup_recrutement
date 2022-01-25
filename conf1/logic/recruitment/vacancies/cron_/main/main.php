<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_cron__main_main extends NxPage
{
	function recruitment_vacancies_cron__main_main($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					(($__o=$this->getHandler('lib.recruitment.vacancies.services.message','')) ? $__o->cronaction() : null);
		return true;
	}
}
?>