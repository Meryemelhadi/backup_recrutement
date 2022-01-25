<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__pdf_export_pdf_export extends NxPage
{
	function recruitment_vacancies_admin_directory__pdf_export_pdf_export($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->pdf_export((isset($_REQUEST["oid"])?$_REQUEST["oid"]:""),(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""),(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:""),(isset($_REQUEST["user_oid"])?$_REQUEST["user_oid"]:"")) : null))!=null?$this->addProperties($tmp):null;
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=edit_interview&nxs=&oid='.(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:"").'&interview_oid='.(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:"")));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>