<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_candidates_directory__send_cvs_to_many_client_process extends NxPage
{
	function recruitment_candidates_directory__send_cvs_to_many_client_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->putRecord(
						$this->getRecord('rct_candidate_client.add_many','page.record','post',false,null,null),'rct_candidate_client.add_many','insert','db','Object',null);
					$relationOid=
						$this->getLastInsertID('db');
					$this->putRecord(
						$_nx_record_data11=array(
								'candidate_oid'=>'',
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'5',
								'ref_oid'=>'',
								'additional_infos'=>'',),'rct_candidate_action.record','insert','db','Object',null);
					(($__o=$this->getHandler('lib.recruitment.candidates.services.message','')) ? $__o->sendManyCvsToManyClients($relationOid) : null);
		return true;
	}
}
?>