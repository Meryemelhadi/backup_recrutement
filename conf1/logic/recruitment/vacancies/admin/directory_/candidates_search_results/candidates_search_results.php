<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__candidates_search_results_candidates_search_results extends NxPage
{
	function recruitment_vacancies_admin_directory__candidates_search_results_candidates_search_results($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("current_operation",'candidates');
					if($this->getProperty("current_operation","") != 'recruitment_providers')
					{
						$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					}
					$this->getRecord('rct_vacancy.get_title','vacancy_title_record','db',false,null,null);
					$this->setProperty('add_candidate_comment.url',$_SERVER["PHP_SELF"].'?nxo=add_candidate_comment&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('requirements.url',$_SERVER["PHP_SELF"].'?nxo=requirements&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('calendar.url',$_SERVER["PHP_SELF"].'?nxo=calendar_vacancy&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('shorts_list.url',$_SERVER["PHP_SELF"].'?nxo=shorts_list&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('associated_candidate.url',$_SERVER["PHP_SELF"].'?nxo=associated_candidate&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('rated.url',$_SERVER["PHP_SELF"].'?nxo=rated_candidate&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('candidates.url',$_SERVER["PHP_SELF"].'?nxo=candidates&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('refused_candidate.url',$_SERVER["PHP_SELF"].'?nxo=refused_candidate&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('recruitment_providers.url',$_SERVER["PHP_SELF"].'?nxo=list_prest&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('synthesis.url',$_SERVER["PHP_SELF"].'?nxo=synthesis&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('feedback.url',$_SERVER["PHP_SELF"].'?nxo=feedback&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('warning.url',$_SERVER["PHP_SELF"].'?nxo=warning&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('history.url',$_SERVER["PHP_SELF"].'?nxo=history&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('announcement.url',$_SERVER["PHP_SELF"].'?nxo=announcement&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					if(!(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""))
					{
						$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					}
					$this->setProperty("vacancy_oid",$this->getProperty("vacancy_oid",""));
					$this->setProperty('search.url',$_SERVER["PHP_SELF"].'?nxo=candidates_search_results&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('candidates_list.url',$_SERVER["PHP_SELF"].'?nxo=candidates&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('rate_candidate.url',$_SERVER["PHP_SELF"].'?nxo=rate_candidate&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('add_interview.url',$_SERVER["PHP_SELF"].'?nxo=candidate_add_interview&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;void='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('send_to_ic.url',$_SERVER["PHP_SELF"].'?nxo=send_to_ic&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('unlink_candidate.url',$_SERVER["PHP_SELF"].'?nxo=unlink_candidate&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('unlink_candidate_sl.url',$_SERVER["PHP_SELF"].'?nxo=unlink_candidate_sl&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('add_short_list.url',$_SERVER["PHP_SELF"].'?nxo=add_short_list&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('edit_short_list.url',$_SERVER["PHP_SELF"].'?nxo=edit_short_list&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('send_sl_to_ic.url',$_SERVER["PHP_SELF"].'?nxo=send_sl_to_ic&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('delete_sl.url',$_SERVER["PHP_SELF"].'?nxo=delete_sl&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('view_mail.url',$_SERVER["PHP_SELF"].'?nxo=view_mail&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('add_to_short_list.url',$_SERVER["PHP_SELF"].'?nxo=add_to_short_list&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('move_to_short_list.url',$_SERVER["PHP_SELF"].'?nxo=move_to_short_list&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('add_candidate_comment.url',$_SERVER["PHP_SELF"].'?nxo=add_candidate_comment&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('preview_cv.url',$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;type=cv');
					$this->setProperty('candidate_details.url',$_SERVER["PHP_SELF"].'?nxo=candidate_details&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('add_email.url',$_SERVER["PHP_SELF"].'?nxo=add_email&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('accepted_proposal.url',$_SERVER["PHP_SELF"].'?nxo=handle_proposal&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=10');
					$this->setProperty('refused_proposal.url',$_SERVER["PHP_SELF"].'?nxo=handle_proposal&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=11');
					$this->setProperty('accepted_for_job.url',$_SERVER["PHP_SELF"].'?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=7');
					$this->setProperty('refuse_candidate.url',$_SERVER["PHP_SELF"].'?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=8');
					$this->setProperty('reinit_status.url',$_SERVER["PHP_SELF"].'?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=0');
					$this->setProperty('cancel_accepted_for_job.url',$_SERVER["PHP_SELF"].'?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=18');
					$this->setProperty('accept_by_client.url',$_SERVER["PHP_SELF"].'?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=5');
					$this->setProperty('refuse_by_client.url',$_SERVER["PHP_SELF"].'?nxo=change_candidate_status&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;status_value=6');
					$searchData=
						$this->getRecord('rct_candidate.vacancy_search@recruitment','page.search','request',false,null,null);
					$this->getRecords('handler:recruitment.candidates.search_list@recruitment','page.records','db',false,$searchData,null);
					$this->runView('/recruitment/vacancies/admin/directory__candidates_search_results',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>