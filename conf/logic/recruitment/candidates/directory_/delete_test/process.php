<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__delete_test_process extends NxPage
{
	function recruitment_candidates_directory__delete_test_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty("test_oid",(isset($_REQUEST["test_oid"])?$_REQUEST["test_oid"]:""));
					$this->deleteRecords('rct_candidate_test_assoc.delete',$this->getRecords('rct_candidate_test_assoc.delete',null,'db'),'db',true);
		return true;
	}
}
?>