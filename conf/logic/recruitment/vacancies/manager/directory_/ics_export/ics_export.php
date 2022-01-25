<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__ics_export_ics_export extends NxPage
{
	function recruitment_vacancies_manager_directory__ics_export_ics_export($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->ics_export() : null))!=null?$this->addProperties($tmp):null;
		return true;
	}
}
?>