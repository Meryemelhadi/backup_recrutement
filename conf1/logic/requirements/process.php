<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class requirements_process extends NxPage
{
	function requirements_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->putRecord(
								$this->getRecord('','page.record','post',false,null,null),'','update','db','Object',null);
							$this->putRecord(
								$_nx_record_data59=array(
										'vacancy_oid'=>(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""),
										'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
										'action_oid'=>'2',
										'ref_oid'=>'',
										'additional_infos'=>'',),'rct_vacancy_action.record@recruitment','insert','db','Object',null);
		return true;
	}
}
?>