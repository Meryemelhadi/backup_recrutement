<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__add_candidate_comment_add_candidate_comment extends NxPage
{
	function recruitment_vacancies_manager_directory__add_candidate_comment_add_candidate_comment($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->putRecord(
						$this->getRecord('rct_candidate_vacancy_comment.add@recruitment','page.record','post',false,null,null),'rct_candidate_vacancy_comment.add@recruitment','insert','db','Object',null);
					$this->setProperty("comment_oid",
						$this->getLastInsertID('db'));
					$this->getRecord('rct_candidate_vacancy_comment.get_record@recruitment','page.record','db',false,null,null);
					$this->runView('/recruitment/vacancies/manager/directory__comment',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>