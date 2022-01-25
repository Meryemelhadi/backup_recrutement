<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_admin_directory__unlink_candidate_sl_unlink_candidate_sl extends NxPage
{
	function recruitment_vacancies_admin_directory__unlink_candidate_sl_unlink_candidate_sl($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("short_list_oid",(isset($_REQUEST["short_list_oid"])?$_REQUEST["short_list_oid"]:""));
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->deleteRecords('rct_candidate_short_list.unlink_candidate@recruitment',$this->getRecords('rct_candidate_short_list.unlink_candidate@recruitment',null,'db'),'db',true);
					$this->putRecord(
						$_nx_record_data34=array(
								'candidate_oid'=>$this->getProperty("candidate_oid",""),
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'15',
								'ref_oid'=>$this->getProperty("short_list_oid",""),
								'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
					$this->putRecord(
						$_nx_record_data35=array(
								'short_list_oid'=>$this->getProperty("short_list_oid",""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'4',
								'ref_oid'=>$this->getProperty("candidate_oid",""),
								'additional_infos'=>'',),'rct_short_list_action.record@recruitment','insert','db','Object',null);
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=shorts_list&nxs=&oid='.$this->getProperty("vacancy_oid","")));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>