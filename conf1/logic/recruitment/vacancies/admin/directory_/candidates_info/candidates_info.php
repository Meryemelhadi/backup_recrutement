<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__candidates_info_candidates_info extends NxPage
{
	function recruitment_vacancies_admin_directory__candidates_info_candidates_info($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecord('recruitment.candidates.selected.info@recruitment','candidates_info.records','db',false,null,null);
					$this->runView('/recruitment/vacancies/admin/directory__candidates_history',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>