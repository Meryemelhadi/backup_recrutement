<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__change_contrat_signing_process extends NxPage
{
	function recruitment_vacancies_admin_directory__change_contrat_signing_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("assoc_oid",(isset($_REQUEST["assoc_oid"])?$_REQUEST["assoc_oid"]:""));
					$this->putRecord(
						$this->getRecord('rct_candidate_vacancy.change_contrat_signing','page.record','post',false,null,null),'rct_candidate_vacancy.change_contrat_signing','update','db','Object',null);
		return true;
	}
}
?>