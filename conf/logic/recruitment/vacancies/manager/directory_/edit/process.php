<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_manager_directory__edit_process extends NxPage
{
	function recruitment_vacancies_manager_directory__edit_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->putRecord(
						$this->getRecord('rct_vacancy.edit_'.$this->getProperty("recruitement_profile","default"),'page.record','post',false,null,null),'rct_vacancy.edit_'.$this->getProperty("recruitement_profile","default"),'update','db','Object',null);
					$path='vacancies/directory';
					$handler='rct_vacancy_attached_file.add_record';
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->uploadFiles((isset($_REQUEST["oid"])?$_REQUEST["oid"]:""),$handler,$path) : null))!=null?$this->addProperties($tmp):null;
					$handler='rct_vacancy_attached_file.get_record';
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->removeFiles((isset($_REQUEST["oid"])?$_REQUEST["oid"]:""),$handler,$path) : null))!=null?$this->addProperties($tmp):null;
					$this->putRecord(
						$_nx_record_data8=array(
								'vacancy_oid'=>(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'2',
								'ref_oid'=>'',
								'additional_infos'=>'',),'rct_vacancy_action.record','insert','db','Object',null);
		return true;
	}
}
?>