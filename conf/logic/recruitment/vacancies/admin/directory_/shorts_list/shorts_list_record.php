<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__shorts_list_shorts_list_record extends NxPage
{
	function recruitment_vacancies_admin_directory__shorts_list_shorts_list_record($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("candidate_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->getRecord('handler:recruitment.short_lists.candidates.record@recruitment','candidate.record','db',false,null,null);
					$this->runView('/recruitment/vacancies/admin/directory__shorts_list_record_ajax',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>