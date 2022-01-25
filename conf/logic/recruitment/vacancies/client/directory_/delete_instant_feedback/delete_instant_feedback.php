<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_client_directory__delete_instant_feedback_delete_instant_feedback extends NxPage
{
	function recruitment_vacancies_client_directory__delete_instant_feedback_delete_instant_feedback($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->deleteRecords('rct_instant_feedback.record@recruitment',$this->getRecords('rct_instant_feedback.record@recruitment',null,'db'),'db',true);
					$this->putRecord(
						$_nx_record_data28=array(
								'vacancy_oid'=>(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'20',
								'ref_oid'=>'',
								'additional_infos'=>'',),'rct_vacancy_action.record@recruitment','insert','db','Object',null);
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=feedback&nxs=&oid='.(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:"")));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>