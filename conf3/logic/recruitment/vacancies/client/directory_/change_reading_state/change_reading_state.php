<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__change_reading_state_change_reading_state extends NxPage
{
	function recruitment_vacancies_client_directory__change_reading_state_change_reading_state($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
						if((isset($_REQUEST["reading_state"])?$_REQUEST["reading_state"]:"") == '1')
						{
							$this->deleteRecords('',$this->getRecords('',null,'db'),'db',true);
						}
						else {
							($tmp=
								(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->insertReadState($GLOBALS["_NX_user"]->getProperty("oid",""),(isset($_REQUEST["oid"])?$_REQUEST["oid"]:"")) : null))!=null?$this->addProperties($tmp):null;
						}
		return true;
	}
}
?>