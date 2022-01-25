<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_admin_directory__add_process extends NxPage
{
	function recruitment_vacancies_admin_directory__add_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->putRecord(
						$this->getRecord('rct_vacancy.add_'.$this->getProperty("recruitement_profile","default"),'page.record','post',false,null,null),'rct_vacancy.add_'.$this->getProperty("recruitement_profile","default"),'insert','db','Object',null);
					$last_oid_record=
						$this->getRecord('rct_vacancy.max_oid','page.record','db',false,null,null);
					$this->setProperty("lastInsertId",
						$last_oid_record->getProperty('oid','',false,'object',''));
					$this->setProperty("redirect",(isset($_REQUEST["redirect"])?$_REQUEST["redirect"]:""));
					$this->setProperty('redirect_url.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$this->getProperty("lastInsertId",""));
					$this->putRecord(
						$_nx_record_data1=array(
								'vacancy_oid'=>$this->getProperty("lastInsertId",""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'0',
								'ref_oid'=>'',
								'additional_infos'=>'',),'rct_vacancy_action.record','insert','db','Object',null);
					$this->runView('/recruitment/vacancies/admin/directory__redirect',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>