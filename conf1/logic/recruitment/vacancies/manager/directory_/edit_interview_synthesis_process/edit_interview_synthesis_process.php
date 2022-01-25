<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__edit_interview_synthesis_process_edit_interview_synthesis_process extends NxPage
{
	function recruitment_vacancies_manager_directory__edit_interview_synthesis_process_edit_interview_synthesis_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("synthesis_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty("interview_oid",(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:""));
					$this->putRecord(
						$this->getRecord('rct_interview_synthesis.edit@recruitment','page.record','post',false,null,null),'rct_interview_synthesis.edit_process@recruitment','update','db','Object',null);
		return true;
	}
}
?>