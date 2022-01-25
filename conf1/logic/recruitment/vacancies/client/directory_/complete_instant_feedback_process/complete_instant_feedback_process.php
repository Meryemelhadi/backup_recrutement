<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__complete_instant_feedback_process_complete_instant_feedback_process extends NxPage
{
	function recruitment_vacancies_client_directory__complete_instant_feedback_process_complete_instant_feedback_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->putRecord(
						$this->getRecord('rct_instant_feedback.complete_client@recruitment','page.records','post',false,null,null),'rct_instant_feedback.complete_client@recruitment','update','db','Object',null);
		return true;
	}
}
?>