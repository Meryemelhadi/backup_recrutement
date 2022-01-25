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
					$this->getRecord('rct_candidate.edit@recruitment','page.record','db',false,null,null);
					$this->setProperty("candidate_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->getRecords('rct_candidate_vacancy.candidate_vacancies@recruitment','candidate_vacancies.records','db',false,null,null);
					$this->getRecords('rct_interview.candidate_interviews@recruitment','candidate_interviews.records','db',false,null,null);
					$this->getRecords('rct_candidate_action.by_candidate_oid@recruitment','candidate_log.records','db',false,null,null);
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					$this->setProperty('associate_to_vacancy.url',$_SERVER["PHP_SELF"].'?nxo=associate_to_vacancy&amp;nxs=&amp;candidate_oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty('download_cv.url',$_SERVER["PHP_SELF"].'?nxo=download&amp;nxs=&amp;type=cv&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('download_cl.url',$_SERVER["PHP_SELF"].'?nxo=download&amp;nxs=&amp;type=cl&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('preview_cv.url',$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cv&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('preview_cl.url',$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cl&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('send_to_client.url',$_SERVER["PHP_SELF"].'?nxo=send_to_client&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('add_interview.url',$_SERVER["PHP_SELF"].'?nxo=add_interview&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->setProperty('edit_interview.url',$_SERVER["PHP_SELF"].'?nxo=edit_interview&amp;nxs=');
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->runView('/recruitment/candidates/directory__edit',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>