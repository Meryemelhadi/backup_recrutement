<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__get_description_sample_get_description_sample extends NxPage
{
	function recruitment_vacancies_admin_directory__get_description_sample_get_description_sample($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecord('rct_entreprise_description_rekrute.record','page.record','db',false,null,null);
					$this->runView('/recruitment/vacancies/admin/directory__description_sample',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>