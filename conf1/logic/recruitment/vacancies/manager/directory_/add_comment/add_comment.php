<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__add_comment_add_comment extends NxPage
{
	function recruitment_vacancies_manager_directory__add_comment_add_comment($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->putRecord(
						$this->getRecord('rct_vacancy_comment.record','page.record','post',false,null,null),'rct_vacancy_comment.add','insert','db','Object',null);
					$this->setProperty("comment_oid",
						$this->getLastInsertID('db'));
					$this->getRecord('rct_vacancy_comment.get_record','page.record','db',false,null,null);
					$this->runView('/recruitment/vacancies/manager/directory__comment',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>