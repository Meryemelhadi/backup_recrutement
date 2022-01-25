<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class add_process extends NxPage
{
	function add_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->putRecord(
								$this->getRecord('','page.record','post',false,null,null),'','insert','db','Object',null);
							$last_oid_record=
								$this->getRecord('','page.record','db',false,null,null);
							$this->setProperty("lastInsertId",
								$last_oid_record->getProperty('oid','',false,'object',''));
							$this->setProperty("redirect",(isset($_REQUEST["redirect"])?$_REQUEST["redirect"]:""));
							$this->setProperty('redirect_url.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$this->getProperty("lastInsertId",""));
							$this->putRecord(
								$_nx_record_data51=array(
										'vacancy_oid'=>$this->getProperty("lastInsertId",""),
										'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
										'action_oid'=>'0',
										'ref_oid'=>'',
										'additional_infos'=>'',),'rct_vacancy_action.record@recruitment','insert','db','Object',null);
							$this->runView('_redirect',array(
								'fmethod' => 'toHTML',

								),null);
		return true;
	}
}
?>