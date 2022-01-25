<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class edit_short_list_edit_short_list_process extends NxPage
{
	function edit_short_list_edit_short_list_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
							$this->setProperty("sl_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
							$this->putRecord(
								$_nx_record_data79=array(
										'short_list_oid'=>$this->getProperty("sl_oid",""),
										'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
										'action_oid'=>'2',
										'ref_oid'=>'',
										'additional_infos'=>(isset($_REQUEST["name"])?$_REQUEST["name"]:""),),'rct_short_list_action.record@recruitment','insert','db','Object',null);
							$this->putRecord(
								$this->getRecord('rct_short_list.edit@recruitment','page.record','post',false,null,null),'rct_short_list.edit@recruitment','update','db','Object',null);
		return true;
	}
}
?>