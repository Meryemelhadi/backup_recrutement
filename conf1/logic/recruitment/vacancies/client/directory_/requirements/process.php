<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_client_directory__requirements_process extends NxPage
{
	function recruitment_vacancies_client_directory__requirements_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->putRecord(
						$this->getRecord('rct_vacancy.edit_fib','page.records','post',false,null,null),'rct_vacancy.edit_fib','update','db','Object',null);
					$this->putRecord(
						$_nx_record_data3=array(
								'vacancy_oid'=>(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'2',
								'ref_oid'=>'',
								'additional_infos'=>'',),'rct_vacancy_action.record','insert','db','Object',null);
					$this->setProperty("redirect",(isset($_REQUEST["redirect"])?$_REQUEST["redirect"]:""));
					$this->setProperty('redirect_url.url',$_SERVER["PHP_SELF"].'?nxo=requirements&amp;nxs=&amp;oid='.(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->runView('/recruitment/vacancies/client/directory__redirect',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>