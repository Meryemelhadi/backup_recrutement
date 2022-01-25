<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__change_hire_date_change_hire_date extends NxPage
{
	function recruitment_vacancies_admin_directory__change_hire_date_change_hire_date($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("assoc_oid",(isset($_REQUEST["assoc_oid"])?$_REQUEST["assoc_oid"]:""));
					$this->getRecord('rct_candidate_vacancy.change_hire_date','page.record','db',false,null,null);
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;assoc_oid='.$this->getProperty("assoc_oid",""));
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid",""));
					$this->runView('/recruitment/vacancies/admin/directory__modalbox_form',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>