<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

include_once(GENERIS_PACKAGES.'recruitment/lib/email/ManageEmails.inc');
require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_edit_interview_cancel extends NxPage
{
	var $interview;

	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $ctxt;
		$this->params = $params;

		$this->interview = new ManageEmails($ctxt);
	}

	function run($workflow, $user)
	{
		$this->setProperty("interview_oid",$oid=(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
		$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
		$candidate_oid=(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"");

		// load record interview
		$interviewRecord = $this->getRecord('rct_interview.edit@recruitment','page.record','db',false,null,null);
		
		// change ical sequence number (no need to save it because the record will be deleted right after sending...)
		$interviewRecord->ical_seq->db = ((int)$interviewRecord->ical_seq->object + 1);

		// update state of candidate
		if($candidate_oid && isset($_REQUEST['etat_oid']) && $_REQUEST['etat_oid'])
		{
			$candidate_etat = new PersistentObject('rct_candidate.edit_etat','db',array('candidate_oid'=>$candidate_oid));
			if($candidate_etat->isOk())
			{
				$candidate_etat->etat_oid = $_REQUEST['etat_oid'];
				$candidate_etat->store('rct_candidate.edit_etat','update','db',array('candidate_oid'=>$candidate_oid,'etat_oid'=>$_REQUEST['etat_oid']));
			}
		}

		// send invite cancel to recruiter
		$this->interview->sendInterviewCancelRecruiter($interviewRecord,$user);

		return true;
	}
}
?>