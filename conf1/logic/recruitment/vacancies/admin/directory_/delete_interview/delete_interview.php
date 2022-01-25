<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_admin_directory__delete_interview_delete_interview extends NxPage
{
	function recruitment_vacancies_admin_directory__delete_interview_delete_interview($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("interview_oid",(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:""));
					$this->deleteRecords('rct_interview_synthesis.delete@recruitment',$this->getRecords('rct_interview_synthesis.delete@recruitment',null,'db'),'db',true);
					$this->deleteRecords('rct_interview.delete@recruitment',$this->getRecords('rct_interview.delete@recruitment',null,'db'),'db',true);
					$this->putRecord(
						$_nx_record_data12=array(
								'vacancy_oid'=>(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'22',
								'ref_oid'=>'',
								'additional_infos'=>'',),'rct_vacancy_action.record@recruitment','insert','db','Object',null);
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=calendar&nxs=&oid='.$this->getProperty("vacancy_oid","")));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>