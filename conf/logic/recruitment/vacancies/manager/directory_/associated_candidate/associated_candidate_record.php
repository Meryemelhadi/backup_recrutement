<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__associated_candidate_associated_candidate_record extends NxPage
{
	function recruitment_vacancies_manager_directory__associated_candidate_associated_candidate_record($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("candidate_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty('add_candidate_comment.url',$_SERVER["PHP_SELF"].'?nxo=add_candidate_comment&amp;nxs=&amp;vacancy_oid='.(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->getRecord('handler:recruitment.candidates.associated.record@recruitment','candidate.record','db',false,null,null);
					$this->runView('/recruitment/vacancies/manager/directory__candidate_record_ajax',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>