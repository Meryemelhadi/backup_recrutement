<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__edit_interview_synthesis_edit_interview_synthesis extends NxPage
{
	function recruitment_candidates_directory__edit_interview_synthesis_edit_interview_synthesis($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecord('rct_candidate.find','candidate.record','db',false,null,null);
					$this->setProperty("synthesis_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty("interview_oid",(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:""));
					$this->getRecord('rct_interview_synthesis.edit@recruitment','page.record','db',false,null,null);
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=edit_interview&amp;nxs=&amp;interview_oid='.(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:"").'&amp;candidate_oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=edit_interview_synthesis_process&amp;nxs=');
					$this->runView('/recruitment/candidates/directory__interview_synthesis_edit',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>