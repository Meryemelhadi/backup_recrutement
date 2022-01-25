<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__handle_proposal_handle_proposal extends NxPage
{
	function recruitment_vacancies_admin_directory__handle_proposal_handle_proposal($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty("status_value",(isset($_REQUEST["status_value"])?$_REQUEST["status_value"]:""));
					$this->setProperty("status_value",(isset($_REQUEST["status_value"])?$_REQUEST["status_value"]:""));
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=candidates&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=handle_proposal_process&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;candidate_oid='.$this->getProperty("candidate_oid","").'&amp;status_value='.$this->getProperty("status_value","").'&amp;status_value='.$this->getProperty("status_value",""));
					$this->getRecord('rct_candidate_vacancy.handle_proposal@recruitment','page.record','empty',false,null,null);
					$this->runView('/recruitment/vacancies/admin/directory__handle_proposal',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>