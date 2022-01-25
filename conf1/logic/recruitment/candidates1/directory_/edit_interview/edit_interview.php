<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__edit_interview_edit_interview extends NxPage
{
	function recruitment_candidates_directory__edit_interview_edit_interview($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty("interview_oid",(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:""));
					$this->getRecord('rct_interview.edit_to_candidate@recruitment','page.record','db',false,null,null);
					$this->getRecords('rct_interview_synthesis.by_interview@recruitment','interview_synthesis.records','db',false,null,null);
					$this->getRecords('rct_interview_attached_file.by_interview@recruitment','attached_files.records','db',false,null,null);
					$this->setProperty('get_email_sample.url',$_SERVER["PHP_SELF"].'?nxo=get_email_sample&amp;nxs=');
					$this->setProperty('download.url',$_SERVER["PHP_SELF"].'?nxo=interview_download&amp;nxs=');
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty('delete_interview.url',$_SERVER["PHP_SELF"].'?nxo=delete_interview&amp;nxs=&amp;candidate_oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"").'&amp;interview_oid='.$this->getProperty("interview_oid",""));
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=edit_interview_process&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('add_interview_synthesis.url',$_SERVER["PHP_SELF"].'?nxo=add_interview_synthesis&amp;nxs=&amp;candidate_oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"").'&amp;interview_oid='.$this->getProperty("interview_oid",""));
					$this->setProperty('edit_interview_synthesis.url',$_SERVER["PHP_SELF"].'?nxo=edit_interview_synthesis&amp;nxs=&amp;candidate_oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"").'&amp;interview_oid='.$this->getProperty("interview_oid",""));
					$this->setProperty('pdf_export.url',$_SERVER["PHP_SELF"].'?nxo=pdf_export&amp;nxs=&amp;candidate_oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"").'&amp;interview_oid='.$this->getProperty("interview_oid",""));
					$this->setProperty('view_interview_synthesis.url',$_SERVER["PHP_SELF"].'?nxo=view_interview_synthesis&amp;nxs=&amp;candidate_oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"").'&amp;interview_oid='.$this->getProperty("interview_oid",""));
					$this->runView('/recruitment/candidates/directory__interview_edit',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>