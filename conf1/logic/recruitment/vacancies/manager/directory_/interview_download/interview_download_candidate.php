<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__interview_download_interview_download_candidate extends NxPage
{
	function recruitment_vacancies_manager_directory__interview_download_interview_download_candidate($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$path='interviews';
					$handler='rct_interview_attached_file_candidate.get_record@recruitment';
					$oidField='interview_oid';
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->download((isset($_REQUEST["oid"])?$_REQUEST["oid"]:""),(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:""),$path,$handler,$oidField) : null))!=null?$this->addProperties($tmp):null;
		return true;
	}
}
?>