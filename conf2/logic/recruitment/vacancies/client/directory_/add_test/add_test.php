<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__add_test_add_test extends NxPage
{
	function recruitment_vacancies_client_directory__add_test_add_test($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty("test_oid",(isset($_REQUEST["test_oid"])?$_REQUEST["test_oid"]:""));
					$this->setProperty("pourcentage",(isset($_REQUEST["pourcentage"])?$_REQUEST["pourcentage"]:""));
					$this->putRecord($null=null,'',(isset($_REQUEST["mode"])?$_REQUEST["mode"]:""),'db','Object',null);
					$this->getRecord('','page.record','db',false,null,null);
					$this->runView('/recruitment/vacancies/client/directory__test_assoc',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>