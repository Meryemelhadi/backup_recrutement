<?php

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_associated_candidate extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run()
	{
		$this->setProperty("current_operation",'candidates');
		if($this->getProperty("current_operation","") != 'recruitment_providers')
		{
			$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
		}
		$this->getRecord('rct_vacancy.get_title','vacancy_title_record','db',false,null,null);
		$this->setProperty('add_candidate_comment.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=add_candidate_comment&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('list.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
		$this->setProperty('edit.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=edit&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('requirements.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=requirements&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('calendar.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=calendar_vacancy&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('shorts_list.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=shorts_list&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('associated_candidate.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=associated_candidate&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('rated.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=rated_candidate&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('candidates.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=candidates&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('refused_candidate.url', PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=refused_candidate&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('recruitment_providers.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=list_prest&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('synthesis.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=synthesis&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('feedback.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=feedback&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('warning.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=warning&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('history.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=history&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('announcement.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=announcement&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->setProperty('candidate_record.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=associated_candidate&amp;nxs=associated_candidate_record&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty("delete_candidate.url",
					PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo=delete_form_vacancies'
				);
		$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
		if(!(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""))
		{
			$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
		}
		$this->setProperty("vacancy_oid",$this->getProperty("vacancy_oid",""));
		$this->setProperty('search.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=associated_candidate&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('candidates_list.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=candidates&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('rate_candidate.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=rate_candidate&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('add_interview.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=candidate_add_interview&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;void='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('send_to_ic.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=send_to_ic&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('unlink_candidate.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=unlink_candidate&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('unlink_candidate_sl.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=unlink_candidate_sl&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('add_short_list.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=add_short_list&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('edit_short_list.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=edit_short_list&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('send_sl_to_ic.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=send_sl_to_ic&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('delete_sl.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=delete_sl&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('view_mail.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=view_mail&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('add_to_short_list.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=add_to_short_list&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('move_to_short_list.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=move_to_short_list&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('add_candidate_comment.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=add_candidate_comment&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('preview_cv.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=preview&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;type=cv');
		$this->setProperty('candidate_details.url',$_SERVER["PHP_SELF"].'?nxo=candidate_details&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('add_email.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=add_email&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
		$this->setProperty('accepted_proposal.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=handle_proposal&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=10');
		$this->setProperty('refused_proposal.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=handle_proposal&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=11');
		$this->setProperty('accepted_for_job.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=7');
		$this->setProperty('refuse_candidate.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=8');
		$this->setProperty('reinit_status.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=0');
		$this->setProperty('cancel_accepted_for_job.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=18');
		$this->setProperty('accept_by_client.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=5');
		$this->setProperty('refuse_by_client.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("vacancy_oid","").'/directory.php?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=6');
		$searchData=
			$this->getRecord('rct_candidate.vacancy_search@recruitment','page.search','request',false,null,null);
		$this->getRecords('handler:recruitment.candidates.associated@recruitment','candidates_associated.records','db',false,$searchData,null);
		$this->runView('/recruitment/vacancies/admin/directory__associated_candidate',array(
			'fmethod' => 'toHTML',

			),null);
		return true;
	}
}
?>