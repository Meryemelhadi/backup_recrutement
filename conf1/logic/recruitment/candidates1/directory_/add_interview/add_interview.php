<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__add_interview_add_interview extends NxPage
{
	function recruitment_candidates_directory__add_interview_add_interview($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					if((isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""))
					{
						$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					}
					$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->getRecord('rct_interview.add_to_candidate@recruitment','page.record','empty',false,null,null);
					$this->setProperty("previous_op_label",$this->getString("back_to_candidate"));
					$this->setProperty('get_email_sample.url',$_SERVER["PHP_SELF"].'?nxo=get_email_sample&amp;nxs=');
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=add_interview_process&amp;nxs=');
					$this->runView('/recruitment/candidates/directory__interview_add',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>