<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__xls_export_lydec_xls_plan_export extends NxPage
{
	function recruitment_vacancies_manager_directory__xls_export_lydec_xls_plan_export($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$searchData=
						$this->getRecord('rct_vacancy.search','page.search','request',false,null,null);
					$this->getRecords('rct_vacancy.plan_excel','page.records','handler',true,$searchData,null);global $NX_MIME;
$NX_MIME='text/html';

					$this->runView('/recruitment/vacancies/manager/directory__xls',array(
						'fmethod' => 'toHTML',
						'view.type' => 'XLS',

						),null);
		return true;
	}
}
?>