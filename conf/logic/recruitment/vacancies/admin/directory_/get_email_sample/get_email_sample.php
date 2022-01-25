<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__get_email_sample_get_email_sample extends NxPage
{
	function recruitment_vacancies_admin_directory__get_email_sample_get_email_sample($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecord('rct_email_sample.record','page.record','db',false,null,null);
					$this->runView('/recruitment/vacancies/admin/directory__email_sample',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>