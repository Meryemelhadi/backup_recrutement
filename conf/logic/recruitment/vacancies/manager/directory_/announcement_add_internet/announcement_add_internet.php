<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__announcement_add_internet_announcement_add_internet extends NxPage
{
	function recruitment_vacancies_manager_directory__announcement_add_internet_announcement_add_internet($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("current_operation",'edit');
					if($this->getProperty("current_operation","") != 'recruitment_providers')
					{
						$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					}
					$this->getRecord('rct_vacancy.get_title','vacancy_title_record','db',false,null,null);
					$this->setProperty('add_candidate_comment.url',$_SERVER["PHP_SELF"].'?nxo=add_candidate_comment&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('requirements.url',$_SERVER["PHP_SELF"].'?nxo=requirements&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('calendar.url',$_SERVER["PHP_SELF"].'?nxo=calendar&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
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
					$this->getRecord('rct_announcement_rekrute.add@recruitment','page.record','empty',false,null,null);
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=announcement&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('default_description.url',$_SERVER["PHP_SELF"].'?nxo=list_description&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process&amp;vacancy_oid='.$this->getProperty("vacancy_oid",""));
					$this->runView('/recruitment/vacancies/manager/directory__announcement_add_internet',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>