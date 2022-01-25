<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_manager_directory__rate_candidate_rate_candidate extends NxPage
{
	function recruitment_vacancies_manager_directory__rate_candidate_rate_candidate($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty("rating_value",(isset($_REQUEST["rating_value"])?$_REQUEST["rating_value"]:""));
					$this->putRecord($null=null,'rct_candidate_vacancy.rate@recruitment','update','db','Object',null);
					$this->putRecord(
						$_nx_record_data16=array(
								'candidate_oid'=>$this->getProperty("candidate_oid",""),
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'12',
								'ref_oid'=>'',
								'additional_infos'=>$this->getProperty("rating_value",""),),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=rated_candidate&nxs=&oid='.$this->getProperty("vacancy_oid","")));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>