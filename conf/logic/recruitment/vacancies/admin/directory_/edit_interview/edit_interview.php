<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__edit_interview_edit_interview extends NxPage
{
	function recruitment_vacancies_admin_directory__edit_interview_edit_interview($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("current_operation",'calendar');
					if($this->getProperty("current_operation","") != 'recruitment_providers')
					{
						$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
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
					$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty("interview_oid",(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:""));
					$this->setProperty("operation",(isset($_REQUEST["operation"])?$_REQUEST["operation"]:""));
					$this->getRecord('rct_interview.edit@recruitment','page.record','db',false,null,null);
					$this->getRecords('rct_interview_synthesis.by_interview@recruitment','interview_synthesis.records','db',false,null,null);
					$this->getRecords('rct_interview_attached_file_candidate.by_interview@recruitment','attached_files_candidate.records','db',false,null,null);
					$this->getRecords('rct_interview_attached_file_interviewers.by_interview@recruitment','attached_files_interviewers.records','db',false,null,null);
					$this->setProperty('get_email_sample.url',$_SERVER["PHP_SELF"].'?nxo=get_email_sample&amp;nxs=');
					$this->setProperty('download_candidate.url',$_SERVER["PHP_SELF"].'?nxo=interview_download&amp;nxs=interview_download_candidate');
					$this->setProperty('download_interviewers.url',$_SERVER["PHP_SELF"].'?nxo=interview_download&amp;nxs=interview_download_interviewers');
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=calendar&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('delete_interview.url',$_SERVER["PHP_SELF"].'?nxo=delete_interview&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;interview_oid='.$this->getProperty("interview_oid",""));
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=edit_interview_process&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('add_interview_synthesis.url',$_SERVER["PHP_SELF"].'?nxo=add_interview_synthesis&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;interview_oid='.$this->getProperty("interview_oid",""));
					$this->setProperty('edit_interview_synthesis.url',$_SERVER["PHP_SELF"].'?nxo=edit_interview_synthesis&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;interview_oid='.$this->getProperty("interview_oid",""));
					$this->setProperty('pdf_export.url',$_SERVER["PHP_SELF"].'?nxo=pdf_export&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;interview_oid='.$this->getProperty("interview_oid",""));
					$this->setProperty('view_interview_synthesis.url',$_SERVER["PHP_SELF"].'?nxo=view_interview_synthesis&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;interview_oid='.$this->getProperty("interview_oid",""));
					$this->setProperty("user_oid",$GLOBALS["_NX_user"]->getProperty("oid",""));
					$this->getRecords('rct_interview.by_user_day_now','interviews.records','db',false,null,null);
					$this->setProperty('preview_cv.url',$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cv&amp;candidate_oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->getRecords('rct_interview.by_user_day_now','interviews.records','db',false,null,null);
					$viewMode='ajax';
					if(in_array((isset($_GET["mode"])?$_GET["mode"]:""),array('page','ajax')))
					{
						$viewMode=(isset($_GET["mode"])?$_GET["mode"]:"");
					}
						if($this->getProperty("operation","") == 'my_calendar')
						{
								if($viewMode == 'page')
								{
									$this->runView('/recruitment/vacancies/admin/directory__interview_edit_page',array(
										'fmethod' => 'toHTML',

										),null);
								}
								else {
									$this->runView('/recruitment/vacancies/admin/directory__my_interview_edit',array(
										'fmethod' => 'toHTML',

										),null);
								}
						}
						else {
							$this->runView('/recruitment/vacancies/admin/directory__interview_edit',array(
								'fmethod' => 'toHTML',

								),null);
						}
		return true;
	}
}
?>