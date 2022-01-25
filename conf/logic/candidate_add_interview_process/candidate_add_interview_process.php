<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class candidate_add_interview_process_candidate_add_interview_process extends NxPage
{
	function candidate_add_interview_process_candidate_add_interview_process($props,&$parentDesc,$aspect)
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
							$this->putRecord(
								$_nx_record_data65=array(
										'candidate_oid'=>$this->getProperty("candidate_oid",""),
										'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
										'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
										'action_oid'=>'4',
										'ref_oid'=>$oid,
										'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
		return true;
	}
}
?>