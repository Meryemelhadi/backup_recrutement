<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__edit_edit extends NxPage
{
	function recruitment_candidates_directory__edit_edit($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.candidates.services.directory','')) ? $__o->insertReadState($GLOBALS["_NX_user"]->getProperty("oid",""),(isset($_REQUEST["oid"])?$_REQUEST["oid"]:"")) : null))!=null?$this->addProperties($tmp):null;
					$this->putRecord($null=null,'rct_candidate.mark_as_read@recruitment','update','db','Object',null);
					$this->setProperty("candidate_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->getRecord('rct_candidate.edit@recruitment','page.record','db',false,null,null);
					$this->getRecords('rct_candidate_vacancy.candidate_vacancies@recruitment','candidate_vacancies.records','db',false,null,null);
					$this->getRecords('rct_candidate_files.list','attached_files.records','db',false,null,null);
					$this->setProperty('add_attached_files.url',$_SERVER["PHP_SELF"].'?nxo=add_attached_files&amp;nxs=&amp;candidate_oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->getRecords('rct_candidate_test_assoc.candidate_tests@recruitment','candidate_tests.records','db',false,null,null);
					$this->getRecords('rct_candidate_etat_assoc.candidate_etats@recruitment','candidate_etats.records','db',false,null,null);
					$this->getRecord('rct_candidate_test_assoc.add@recruitment','candidate_tests.record','empty',false,null,null);
					$this->getRecords('rct_interview.candidate_interviews@recruitment','candidate_interviews.records','db',false,null,null);
					$this->getRecords('rct_candidate_action.by_candidate_oid@recruitment','candidate_log.records','db',false,null,null);
					$this->getRecord('rct_candidate_etat_assoc.add@recruitment','candidate_etats.record','empty',false,null,null);
					$this->getRecords('rct_candidate_comment.record','comments.records','db',false,null,null);
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					$this->setProperty('unlink_candidate.url',$_SERVER["PHP_SELF"].'?nxo=unlink_candidate&amp;nxs=&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->setProperty('associate_to_vacancy.url',$_SERVER["PHP_SELF"].'?nxo=associate_to_vacancy&amp;nxs=&amp;candidate_oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty('add_comment.url',$_SERVER["PHP_SELF"].'?nxo=add_comment&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty('delete_comment.url',$_SERVER["PHP_SELF"].'?nxo=delete_comment&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('download_cv.url',$_SERVER["PHP_SELF"].'?nxo=download&amp;nxs=&amp;type=cv&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('download_cl.url',$_SERVER["PHP_SELF"].'?nxo=download&amp;nxs=&amp;type=cl&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('preview_cv.url',$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cv&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('preview_cl.url',$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cl&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('add_etat.url',$_SERVER["PHP_SELF"].'?nxo=add_etat&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('delete_etat.url',$_SERVER["PHP_SELF"].'?nxo=delete_etat&amp;nxs=');
					$this->setProperty('send_to_client.url',$_SERVER["PHP_SELF"].'?nxo=send_to_client&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('add_interview.url',$_SERVER["PHP_SELF"].'?nxo=interview@recruitment:add_interview&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('add_test.url',$_SERVER["PHP_SELF"].'?nxo=add_test&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('attached_files.url',$_SERVER["PHP_SELF"].'?nxo=attached_files&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('delete_attached_file.url',$_SERVER["PHP_SELF"].'?nxo=delete_attached_file&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('edit_etat.url',$_SERVER["PHP_SELF"].'?nxo=edit_etat&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('delete_comment.url',$_SERVER["PHP_SELF"].'?nxo=delete_comment&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('delete_test.url',$_SERVER["PHP_SELF"].'?nxo=delete_test&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('edit_interview.url',$_SERVER["PHP_SELF"].'?nxo=interview@recruitment:edit_interview&amp;nxs=');
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$viewMode='ajax';
					if(in_array((isset($_GET["mode"])?$_GET["mode"]:""),array('page','ajax')))
					{
						$viewMode=(isset($_GET["mode"])?$_GET["mode"]:"");
					}
						if($viewMode == 'page')
						{
							$this->runView('/recruitment/candidates/directory__edit',array(
								'fmethod' => 'toHTML',

								),null);
						}
						else {
							$this->runView('/recruitment/candidates/directory__edit_ajax',array(
								'fmethod' => 'toHTML',

								),null);
						}
		return true;
	}
}
?>