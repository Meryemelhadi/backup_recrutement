<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_shortlist_candidates_by_state extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
	}

	function run($workflow, $user)
	{
		$curOp = $this->setProperty("current_operation",'vacancy_shortlists@recruitment:list_by_state');
//		$curOp = $this->getProperty("app.operation","");
//		$curOp = $workflow->getState();

		if($this->getProperty("current_operation","") != 'recruitment_providers')
		{
			$vacancyOid = $this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
		}
		else
			$vacancyOid = '';

		$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
		$this->setProperty("vacancy_oid",$vacancyOid);

		$this->getRecord('rct_vacancy.get_title','vacancy_title_record','db',false,null,null);
		$filterKey = urlencode ((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""));

		
		$this->addProperties(array
		(
		'add_candidate_comment.url'=>$_SERVER["PHP_SELF"].'?nxo=add_candidate_comment&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'list.url'=>$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax',
		'edit.url'=>$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'requirements.url'=>$_SERVER["PHP_SELF"].'?nxo=requirements&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'calendar.url'=>$_SERVER["PHP_SELF"].'?nxo=calendar_vacancy&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'shorts_list.url'=>$_SERVER["PHP_SELF"].'?nxo=shorts_list&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'associated_candidate.url'=>$_SERVER["PHP_SELF"].'?nxo=associated_candidate&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'rated.url'=>$_SERVER["PHP_SELF"].'?nxo=rated_candidate&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'candidates.url'=>$_SERVER["PHP_SELF"].'?nxo=candidates&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'refused_candidate.url'=>$_SERVER["PHP_SELF"].'?nxo=refused_candidate&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'recruitment_providers.url'=>$_SERVER["PHP_SELF"].'?nxo=list_prest&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'synthesis.url'=>$_SERVER["PHP_SELF"].'?nxo=synthesis&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'feedback.url'=>$_SERVER["PHP_SELF"].'?nxo=feedback&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'warning.url'=>$_SERVER["PHP_SELF"].'?nxo=warning&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'history.url'=>$_SERVER["PHP_SELF"].'?nxo=history&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'announcement.url'=>$_SERVER["PHP_SELF"].'?nxo=announcement&amp;nxs=&amp;oid='.$vacancyOid.'&amp;filterKey='.$filterKey,
		'search.url'=>$_SERVER["PHP_SELF"].'?nxo=candidates_search_results&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'candidates_list.url'=>$_SERVER["PHP_SELF"].'?nxo=candidates&amp;nxs=&amp;oid='.$vacancyOid,
		'rate_candidate.url'=>$_SERVER["PHP_SELF"].'?nxo=rate_candidate&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'add_interview.url'=>$_SERVER["PHP_SELF"].'?nxo=candidate_add_interview&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'send_to_ic.url'=>$_SERVER["PHP_SELF"].'?nxo=send_to_ic&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'unlink_candidate.url'=>$_SERVER["PHP_SELF"].'?nxo=unlink_candidate&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'unlink_candidate_sl.url'=>$_SERVER["PHP_SELF"].'?nxo=unlink_candidate_sl&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'add_short_list.url'=>$_SERVER["PHP_SELF"].'?nxo=add_short_list&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'edit_short_list.url'=>$_SERVER["PHP_SELF"].'?nxo=edit_short_list&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'send_sl_to_ic.url'=>$_SERVER["PHP_SELF"].'?nxo=send_sl_to_ic&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'delete_sl.url'=>$_SERVER["PHP_SELF"].'?nxo=delete_sl&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'view_mail.url'=>$_SERVER["PHP_SELF"].'?nxo=view_mail&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'add_to_short_list.url'=>$_SERVER["PHP_SELF"].'?nxo=add_to_short_list&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'add_candidate_comment.url'=>$_SERVER["PHP_SELF"].'?nxo=add_candidate_comment&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'preview_cv.url'=>$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;vacancy_oid='.$vacancyOid.'&amp;type=cv',
		'candidate_details.url'=>$_SERVER["PHP_SELF"].'?nxo=candidate_details&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'add_email.url'=>$_SERVER["PHP_SELF"].'?nxo=add_email&amp;nxs=&amp;vacancy_oid='.$vacancyOid,
		'accepted_proposal.url'=>$_SERVER["PHP_SELF"].'?nxo=handle_proposal&amp;nxs=&amp;vacancy_oid='.$vacancyOid.'&amp;status_value=10',
		'refused_proposal.url'=>$_SERVER["PHP_SELF"].'?nxo=handle_proposal&amp;nxs=&amp;vacancy_oid='.$vacancyOid.'&amp;status_value=11',
		'accepted_for_job.url'=>$_SERVER["PHP_SELF"].'?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$vacancyOid.'&amp;status_value=7',
		'refuse_candidate.url'=>$_SERVER["PHP_SELF"].'?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$vacancyOid.'&amp;status_value=8',
		'reinit_status.url'=>$_SERVER["PHP_SELF"].'?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$vacancyOid.'&amp;status_value=0',
		'cancel_accepted_for_job.url'=>$_SERVER["PHP_SELF"].'?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$vacancyOid.'&amp;status_value=18',
		'accept_by_client.url'=>$_SERVER["PHP_SELF"].'?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$vacancyOid.'&amp;status_value=5',
		'refuse_by_client.url'=>$_SERVER["PHP_SELF"].'?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$vacancyOid.'&amp;status_value=6',
		'candidate_record.url'=>$_SERVER["PHP_SELF"].'?nxo='.$curOp.'&amp;nxs=candidate_record&amp;vacancy_oid='.$vacancyOid,
		'short_list_record.url'=>$_SERVER["PHP_SELF"].'?nxo=shorts_list&amp;nxs=short_list_record&amp;vacancy_oid='.$vacancyOid,
		));

		$this->getRecords('handler:recruitment.candidates.associated@recruitment','candidates_associated.records','db',false,null,null);
		$this->getRecords('rct_short_list.by_vacancy_with_candidates@recruitment','short_lists.records','db',false,null,null);
		$this->getRecord('rct_candidate.vacancy_search@recruitment','page.search','empty',false,null,null);
		$this->getRecords('handler:recruitment.candidates.selected@recruitment','candidates_selected.records','db',false,null,null);

		$this->runView('/recruitment/vacancies/admin/directory__candidates',array(
			'fmethod' => 'toHTML',

			),null);
		return true;
	}
}
?>