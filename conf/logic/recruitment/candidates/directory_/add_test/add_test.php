<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__add_test_add_test extends NxPage
{
	function recruitment_candidates_directory__add_test_add_test($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty("test_oid",(isset($_REQUEST["test_oid"])?$_REQUEST["test_oid"]:""));
					$this->setProperty("pourcentage",(isset($_REQUEST["pourcentage"])?$_REQUEST["pourcentage"]:""));
					$this->putRecord($null=null,'rct_candidate_test_assoc.add@recruitment',(isset($_REQUEST["mode"])?$_REQUEST["mode"]:""),'db','Object',null);
					$this->getRecord('rct_candidate_test_assoc.candidate_test@recruitment','page.record','db',false,null,null);
					$this->setProperty('delete_test.url',$_SERVER["PHP_SELF"].'?nxo=delete_test&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->runView('/recruitment/candidates/directory__test_assoc',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>