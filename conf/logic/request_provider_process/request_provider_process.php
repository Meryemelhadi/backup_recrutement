<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class request_provider_process_request_provider_process extends NxPage
{
	function request_provider_process_request_provider_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
							$this->putRecord(
								$this->getRecord('rct_vacancy_provider.add@recruitment','page.record','post',false,null,null),'rct_vacancy_provider.add@recruitment','insert','db','Object',null);
							$oid=
								$this->getLastInsertID('db');
							$this->setProperty("application_type",'1');
							$this->putRecord($null=null,'rct_vacancy.change_application_type@recruitment','update','db','Object',null);
							$path='vacancy_providers';
							$handler='rct_vacancy_provider_attached_file.add_record@recruitment';
							($tmp=
								(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->uploadFiles($oid,$handler,$path) : null))!=null?$this->addProperties($tmp):null;
							(($__o=$this->getHandler('lib.recruitment.vacancies.services.message','')) ? $__o->requireProvider($oid) : null);
							$this->setProperty("vacancy_oid",$this->getProperty("vacancy_oid",""));
							$this->setProperty("progress_level",'2');
							$this->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
							$cRecord=
								$this->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
							$progress_level=
								$cRecord->getProperty('progress_level','',false,'object','');
							$progress_level_meta=
								$cRecord->getProperty('progress_level_meta','',false,'html','');
							$this->putRecord(
								$_nx_record_data87=array(
										'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
										'progress_level'=>$this->getProperty("progress_level",""),
										'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
		return true;
	}
}
?>