<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__move_to_short_list_move_to_short_list extends NxPage
{
	function recruitment_vacancies_admin_directory__move_to_short_list_move_to_short_list($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->getRecords('rct_short_list.by_vacancy@recruitment','page.records','db',false,null,null);
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=move_to_short_list_process&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=shorts_list&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid",""));
					$this->runView('/recruitment/vacancies/admin/directory__short_list_add_candidates',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>