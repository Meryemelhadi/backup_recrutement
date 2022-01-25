<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class add_to_short_list_add_to_short_list_process extends NxPage
{
	function add_to_short_list_add_to_short_list_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->setProperty("short_list_oid",(isset($_REQUEST["short_list_oid"])?$_REQUEST["short_list_oid"]:""));
							$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
							$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
							$insered_candidates=
								(($__o=$this->getHandler('lib.recruitment.short_lists.services.directory','')) ? $__o->saveAssociations($this->getProperty("candidate_oid",""),$this->getProperty("short_list_oid","")) : null);

				$insered_candidates_str = implode('|',$insered_candidates);
			

							if($insered_candidates_str != '')
							{
								$this->putRecord(
									$_nx_record_data80=array(
											'short_list_oid'=>$this->getProperty("short_list_oid",""),
											'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
											'action_oid'=>'5',
											'ref_oid'=>$insered_candidates_str,
											'additional_infos'=>'',),'rct_short_list_action.record@recruitment','insert','db','Object',null);
							}
							foreach($insered_candidates as $i=>$value)
							{
								$this->putRecord(
									$_nx_record_data81=array(
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