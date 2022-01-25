<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class edit_edit extends NxPage
{
	function edit_edit($props,&$parentDesc,$aspect)
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
							$this->getRecord('','vacancy_title_record','db',false,null,null);
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
							$vacancy=
								$this->getRecord('','','db',false,null,null);
							$this->setProperty("vacancy_id",
								$vacancy->getProperty('oid','',false,'object',''));
							$permission_control=
								$this->getRecords('','','db',false,null,null);
							$verif_permission_control=
								(($_nx_records56=$permission_control)!=null?$_nx_records56->count():0);
							$permission_manager=
								$this->getRecords('','','db',false,null,null);
							$verif_permission_manager=
								(($_nx_records57=$permission_manager)!=null?$_nx_records57->count():0);
							$this->getRecords('','','db',false,null,null);
							$this->getRecords('','','db',false,null,null);
							$this->getRecords('','','db',false,null,null);
							$this->getRecords('','','db',false,null,null);
							$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
							$this->getRecords('','','db',false,null,null);
							$this->getRecords('','','db',false,null,null);
							$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
							$this->setProperty('add_comment.url',$_SERVER["PHP_SELF"].'?nxo=add_comment&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
							$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
							$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process');
							$this->setProperty('download.url',$_SERVER["PHP_SELF"].'?nxo=download&amp;nxs=');
							$this->setProperty('change_contrat_signing.url',$_SERVER["PHP_SELF"].'?nxo=change_contrat_signing&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
							$this->setProperty('change_hire_date.url',$_SERVER["PHP_SELF"].'?nxo=change_hire_date&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
							$this->setProperty('change_integration_plan.url',$_SERVER["PHP_SELF"].'?nxo=change_integration_plan&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
							$this->setProperty('change_integration_note.url',$_SERVER["PHP_SELF"].'?nxo=change_integration_note&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
							$viewMode='ajax';
							if(in_array((isset($_GET["mode"])?$_GET["mode"]:""),array('page','ajax')))
							{
								$viewMode=(isset($_GET["mode"])?$_GET["mode"]:"");
							}
							$creator=
								$vacancy->getProperty('creator','',false,'object','');
								if($verif_permission_control == '1' or $creator == $GLOBALS["_NX_user"]->getProperty("oid","") or $verif_permission_manager=='1')
								{
									$this->runView('_edit',array(
										'fmethod' => 'toHTML',

										),null);
								}
								else {
									$this->runView('_readonly',array(
										'fmethod' => 'toHTML',

										),null);
								}
		return true;
	}
}
?>