<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__edit_request_edit_request extends NxPage
{
	function recruitment_vacancies_client_directory__edit_request_edit_request($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty("back_list.url",
								PORTAL_URL_PREFIX.'/recruitment/vacancies/client/directory.php?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=page'
							);
					$this->setProperty("delete.url",
								PORTAL_URL_PREFIX.'/recruitment/vacancies/client/directory.php?nxo=delete&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid").'&amp;filterKey='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")
							);
					$vacancy=
						$this->getRecord('rct_vacancy.edit-validate-request','page.record','db',false,null,null);
					$this->setProperty("vacancy_id",
						$vacancy->getProperty('oid','',false,'object',''));
					$permission_control=
						$this->getRecords('rct_vacancy_total_control.permission','','db',false,null,null);
					$verif_permission_control=
						(($_nx_records58=$permission_control)!=null?$_nx_records58->count():0);
					$permission_manager=
						$this->getRecords('rct_vacancy.manager_permission','','db',false,null,null);
					$verif_permission_manager=
						(($_nx_records59=$permission_manager)!=null?$_nx_records59->count():0);
					$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->getRecords('rct_vacancy_attached_file.by_vacancy','','db',false,null,null);
					$this->getRecords('rct_vacancy_comment.ds_list','','db',false,null,null);
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
					$viewMode='page';
					if(in_array((isset($_GET["mode"])?$_GET["mode"]:""),array('page','ajax')))
					{
						$viewMode=(isset($_GET["mode"])?$_GET["mode"]:"");
					}
						if($viewMode == 'page')
						{
							$this->runView('/recruitment/vacancies/client/directory__edit_request',array(
								'fmethod' => 'toHTML',

								),null);
						}
						else {
							$this->runView('/recruitment/vacancies/client/directory__edit_request',array(
								'fmethod' => 'toHTML',

								),null);
						}
		return true;
	}
}
?>