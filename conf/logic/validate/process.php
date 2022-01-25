<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class validate_process extends NxPage
{
	function validate_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->putRecord($null=null,'','update','db','Object',null);
							$validation_state='28';
							if((isset($_REQUEST["validation_key"])?$_REQUEST["validation_key"]:"") == '3')
							{
								$validation_state='29';
							}
							$this->putRecord(
								$_nx_record_data50=array(
										'vacancy_oid'=>(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""),
										'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
										'action_oid'=>$validation_state,
										'ref_oid'=>'',
										'additional_infos'=>'',),'rct_vacancy_action.record@recruitment','insert','db','Object',null);
		return true;
	}
}
?>