<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_candidates_directory__unlink_from_all_unlink_unlink_from_all extends NxPage
{
	function recruitment_candidates_directory__unlink_from_all_unlink_unlink_from_all($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					if($this->getProperty("candidate_oid",""))
					{
						$this->deleteRecords('rct_candidate_vacancy.unlink_from_all@recruitment',$this->getRecords('rct_candidate_vacancy.unlink_from_all@recruitment',null,'db'),'db',true);
						$this->putRecord(
							$_nx_record_data1=array(
									'candidate_oid'=>$this->getProperty("candidate_oid",""),
									'vacancy_oid'=>'',
									'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
									'action_oid'=>'31',
									'ref_oid'=>'',
									'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
					}
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=edit&nxs=&filterKey='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"")));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>