<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__add_interview_synthesis_process_add_interview_synthesis_process extends NxPage
{
	function recruitment_candidates_directory__add_interview_synthesis_process_add_interview_synthesis_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("interview_oid",(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:""));
					$this->putRecord(
						$this->getRecord('rct_interview_synthesis.add@recruitment','page.record','post',false,null,null),'rct_interview_synthesis.add_process@recruitment','insert','db','Object',null);
		return true;
	}
}
?>