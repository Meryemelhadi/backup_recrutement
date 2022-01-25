<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__schedule_delayed_feedback_schedule_delayed_feedback extends NxPage
{
	function recruitment_vacancies_manager_directory__schedule_delayed_feedback_schedule_delayed_feedback($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->getRecord('rct_delayed_feedback.schedule@recruitment','page.record','empty',false,null,null);
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=feedback&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=schedule_delayed_feedback_process&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->runView('/recruitment/vacancies/manager/directory__feedback_schedule',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>