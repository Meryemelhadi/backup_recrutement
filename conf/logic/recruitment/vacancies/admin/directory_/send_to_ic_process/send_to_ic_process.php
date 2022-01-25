<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_admin_directory__send_to_ic_process_send_to_ic_process extends NxPage
{
	function recruitment_vacancies_admin_directory__send_to_ic_process_send_to_ic_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->putRecord(
						$this->getRecord('rct_candidate_vacancy_client.add@recruitment','page.record','post',false,null,null),'rct_candidate_vacancy_client.add@recruitment','insert','db','Object',null);
					$assocOid=
						$this->getLastInsertID('db');

				$candidates_oids = explode('|', $this->getProperty("candidate_oid",""));
			

					foreach($candidates_oids as $i=>$value)
					{
						$this->putRecord(
							$_nx_record_data23=array(
									'candidate_oid'=>$value,
									'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
									'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
									'action_oid'=>'2',
									'ref_oid'=>'',
									'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
					}
					(($__o=$this->getHandler('lib.recruitment.vacancies.services.message','')) ? $__o->sendCandidateNotificationEmail($assocOid) : null);
					$this->setProperty("vacancy_oid",$this->getProperty("vacancy_oid",""));
					$this->setProperty("progress_level",'4');
					$this->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
					$cRecord=
						$this->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
					$progress_level=
						$cRecord->getProperty('progress_level','',false,'object','');
					$progress_level_meta=
						$cRecord->getProperty('progress_level_meta','',false,'html','');
					$this->putRecord(
						$_nx_record_data24=array(
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'progress_level'=>$this->getProperty("progress_level",""),
								'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
		return true;
	}
}
?>