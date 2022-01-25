<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__add_etat_add_etat extends NxPage
{
	function recruitment_vacancies_client_directory__add_etat_add_etat($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty("etat_oid",(isset($_REQUEST["test_oid"])?$_REQUEST["test_oid"]:""));
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->putRecord($null=null,'',(isset($_REQUEST["mode"])?$_REQUEST["mode"]:""),'db','Object',null);
					$this->getRecord('','page.record','db',false,null,null);
					$this->setProperty('delete_etat.url',$_SERVER["PHP_SELF"].'?nxo=delete_etat&amp;nxs=');
					$this->runView('/recruitment/vacancies/client/directory__etat_assoc',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>