<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__my_interviews_list_interviews_list extends NxPage
{
	function recruitment_vacancies_manager_directory__my_interviews_list_interviews_list($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecords('rct_interview.my_list','page.records','db',false,null,null);
					$this->setProperty("edit_interview.url",
				PORTAL_URL_PREFIX.'/recruitement2/interview_manager.php?nxo=interview_evaluation:edit_by_interview'
			);
					$this->runView('/recruitment/vacancies/manager/directory__interviews_list',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>