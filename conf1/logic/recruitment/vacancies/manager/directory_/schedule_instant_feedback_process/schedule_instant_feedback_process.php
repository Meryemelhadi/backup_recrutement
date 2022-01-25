<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_manager_directory__schedule_instant_feedback_process_schedule_instant_feedback_process extends NxPage
{
	function recruitment_vacancies_manager_directory__schedule_instant_feedback_process_schedule_instant_feedback_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->putRecord(
						$this->getRecord('rct_instant_feedback.schedule@recruitment','page.record','post',false,null,null),'rct_instant_feedback.schedule@recruitment','insert','db','Object',null);
					$ds='rct_instant_feedback.schedule@recruitment';
					if(preg_match('/instant/', $ds))
					{
						$objectOid=
							$this->getLastInsertID('db');
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.message','')) ? $__o->sendInstantFeedackEmail($objectOid) : null);
					}
					$oid=
						$this->getLastInsertID('db');
					$this->putRecord(
						$_nx_record_data38=array(
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'18',
								'ref_oid'=>$oid,
								'additional_infos'=>'',),'rct_vacancy_action.record@recruitment','insert','db','Object',null);
		return true;
	}
}
?>