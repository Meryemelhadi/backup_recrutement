<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory_client__candidate_details_candidate_details extends NxPage
{
	function recruitment_candidates_directory_client__candidate_details_candidate_details($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=ajax');
					$this->setProperty("previous_op_label",$this->getString("back_to_candidates"));
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->getRecord('rct_candidate.details@recruitment','page.record','db',false,null,null);
					$this->runView('/recruitment/candidates/directory_client__candidate_details',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>