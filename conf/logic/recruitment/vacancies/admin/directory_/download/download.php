<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__download_download extends NxPage
{
	function recruitment_vacancies_admin_directory__download_download($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$path='vacancies/directory';
					$handler='rct_vacancy_attached_file.get_record';
					$oidField='vacancy_oid';
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->download((isset($_REQUEST["oid"])?$_REQUEST["oid"]:""),(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""),$path,$handler,$oidField) : null))!=null?$this->addProperties($tmp):null;
		return true;
	}
}
?>