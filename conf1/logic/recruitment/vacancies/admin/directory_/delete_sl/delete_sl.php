<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_admin_directory__delete_sl_delete_sl extends NxPage
{
	function recruitment_vacancies_admin_directory__delete_sl_delete_sl($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("short_list_oid",(isset($_REQUEST["short_list_oid"])?$_REQUEST["short_list_oid"]:""));
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->deleteRecords('rct_short_list.delete@recruitment',$this->getRecords('rct_short_list.delete@recruitment',null,'db'),'db',true);
					$this->deleteRecords('rct_short_list_vacancy_client.by_sl@recruitment',$this->getRecords('rct_short_list_vacancy_client.by_sl@recruitment',null,'db'),'db',true);
					$this->deleteRecords('rct_candidate_short_list.by_sl@recruitment',$this->getRecords('rct_candidate_short_list.by_sl@recruitment',null,'db'),'db',true);
					$this->deleteRecords('rct_short_list_action.by_sl@recruitment',$this->getRecords('rct_short_list_action.by_sl@recruitment',null,'db'),'db',true);
					$this->putRecord(
						$_nx_record_data36=array(
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'31',
								'ref_oid'=>'',
								'additional_infos'=>'',),'rct_vacancy_action.record@recruitment','insert','db','Object',null);
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=candidates&nxs=&oid='.$this->getProperty("vacancy_oid","")));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>