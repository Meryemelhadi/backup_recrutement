<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__feedback_feedback extends NxPage
{
	function recruitment_vacancies_client_directory__feedback_feedback($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->getRecord('rct_vacancy.get_title','vacancy_title_record','db',false,null,null);
					$this->setProperty("current_operation",'feedback');
					$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('requirements.url',$_SERVER["PHP_SELF"].'?nxo=requirements&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('calendar.url',$_SERVER["PHP_SELF"].'?nxo=calendar&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('shorts_list.url',$_SERVER["PHP_SELF"].'?nxo=shorts_list&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('associated_candidate.url',$_SERVER["PHP_SELF"].'?nxo=associated_candidate&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('rated.url',$_SERVER["PHP_SELF"].'?nxo=rated_candidate&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('candidates.url',$_SERVER["PHP_SELF"].'?nxo=candidates&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('refused_candidate.url',$_SERVER["PHP_SELF"].'?nxo=refused_candidate&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('recruitment_providers.url',$_SERVER["PHP_SELF"].'?nxo=recruitment_providers&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('synthesis.url',$_SERVER["PHP_SELF"].'?nxo=synthesis&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('feedback.url',$_SERVER["PHP_SELF"].'?nxo=feedback&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('warning.url',$_SERVER["PHP_SELF"].'?nxo=warning&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('history.url',$_SERVER["PHP_SELF"].'?nxo=history&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('announcement.url',$_SERVER["PHP_SELF"].'?nxo=announcement&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty('schedule_instant_feedback.url',$_SERVER["PHP_SELF"].'?nxo=schedule_instant_feedback&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('schedule_delayed_feedback.url',$_SERVER["PHP_SELF"].'?nxo=schedule_delayed_feedback&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('delete_instant_feedback.url',$_SERVER["PHP_SELF"].'?nxo=delete_instant_feedback&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('delete_delayed_feedback.url',$_SERVER["PHP_SELF"].'?nxo=delete_delayed_feedback&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('complete_instant_feedback.url',$_SERVER["PHP_SELF"].'?nxo=complete_instant_feedback&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('complete_delayed_feedback.url',$_SERVER["PHP_SELF"].'?nxo=complete_delayed_feedback&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('view_instant_feedback.url',$_SERVER["PHP_SELF"].'?nxo=view_instant_feedback&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('view_delayed_feedback.url',$_SERVER["PHP_SELF"].'?nxo=view_delayed_feedback&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->getRecords('rct_instant_feedback.client_list@recruitment','instant_feedback.records','db',false,null,null);
					$this->getRecords('rct_delayed_feedback.client_list@recruitment','delayed_feedback.records','db',false,null,null);
					$this->runView('/recruitment/vacancies/client/directory__feedback',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>