<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class add_short_list_add_short_list_process extends NxPage
{
	function add_short_list_add_short_list_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
							$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
							$this->putRecord(
								$this->getRecord('rct_short_list.add@recruitment','page.record','post',false,null,null),'rct_short_list.add@recruitment','insert','db','Object',null);
							$this->setProperty("short_list_oid",
								$this->getLastInsertID('db'));
							$this->putRecord(
								$_nx_record_data77=array(
										'short_list_oid'=>$this->getProperty("short_list_oid",""),
										'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
										'action_oid'=>'1',
										'ref_oid'=>'',
										'additional_infos'=>(isset($_REQUEST["name"])?$_REQUEST["name"]:""),),'rct_short_list_action.record@recruitment','insert','db','Object',null);
							$insered_candidates=
								(($__o=$this->getHandler('lib.recruitment.short_lists.services.directory','')) ? $__o->saveAssociations($this->getProperty("candidate_oid",""),$this->getProperty("short_list_oid","")) : null);
							foreach($insered_candidates as $i=>$value)
							{
								$this->putRecord(
									$_nx_record_data78=array(
											'candidate_oid'=>$value,
											'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
											'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
											'action_oid'=>'1',
											'ref_oid'=>$this->getProperty("short_list_oid",""),
											'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
							}
		return true;
	}
}
?>