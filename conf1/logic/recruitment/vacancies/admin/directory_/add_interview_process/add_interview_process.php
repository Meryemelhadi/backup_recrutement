<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_admin_directory__add_interview_process_add_interview_process extends NxPage
{
	function recruitment_vacancies_admin_directory__add_interview_process_add_interview_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));

				$candidates_oids = explode('|', $this->getProperty("candidate_oid",""));
				$lastOids = array();
			

					foreach($candidates_oids as $i=>$value)
					{
						$this->setProperty("candidate_oid",$value);
						$this->putRecord(
							$this->getRecord('rct_interview.add@recruitment','page.record','post',false,null,null),'rct_interview.add@recruitment','insert','db','Object',null);
						$lastOid=
							$this->getLastInsertID('db');

					$lastOids[] = array($lastOid, $value);
				

					}
					$path='interviews';
					$handler_candidate='rct_interview_attached_file_candidate.add_record@recruitment';
					$handler_interviewers='rct_interview_attached_file_interviewers.add_record@recruitment';
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->uploadNCopyInterview($lastOids,$handler_candidate,$handler_interviewers,$path) : null))!=null?$this->addProperties($tmp):null;
					$email_mode='send';
					if($email_mode == 'send')
					{
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.message','')) ? $__o->sendInterviewEmail($lastOids) : null);
					}
					foreach($lastOids as $i=>$value)
					{

									$lastOid = $value[0];
									$candidateOid = $value[1];
								

						$this->putRecord(
							$_nx_record_data10=array(
									'candidate_oid'=>$candidateOid,
									'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
									'user_oid'=>(isset($_POST["interview_by_oid"])?$_POST["interview_by_oid"]:""),
									'action_oid'=>'4',
									'ref_oid'=>$lastOid,
									'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
					}
					$this->setProperty("vacancy_oid",$this->getProperty("vacancy_oid",""));
					$this->setProperty("progress_level",'6');
					$this->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
					$cRecord=
						$this->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
					$progress_level=
						$cRecord->getProperty('progress_level','',false,'object','');
					$progress_level_meta=
						$cRecord->getProperty('progress_level_meta','',false,'html','');
					$this->putRecord(
						$_nx_record_data11=array(
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'progress_level'=>$this->getProperty("progress_level",""),
								'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
		return true;
	}
}
?>