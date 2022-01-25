<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__edit_interview_process_edit_interview_process extends NxPage
{
	function recruitment_vacancies_manager_directory__edit_interview_process_edit_interview_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("interview_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->putRecord(
						$this->getRecord('rct_interview.edit@recruitment','page.record','post',false,null,null),'rct_interview.edit@recruitment','update','db','Object',null);
					$oid=$this->getProperty("interview_oid","");
					$path='interviews';
					$handler_candidate='rct_interview_attached_file_candidate.add_record@recruitment';
					$handler_interviewers='rct_interview_attached_file_interviewers.add_record@recruitment';
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->uploadInterviewFiles($oid,$handler_candidate,$handler_interviewers,$path) : null))!=null?$this->addProperties($tmp):null;
					$handler='rct_interview_attached_file_interviewers.get_record@recruitment';
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->removeFiles($oid,$handler,$path) : null))!=null?$this->addProperties($tmp):null;
					$handler='rct_interview_attached_file_candidate.get_record@recruitment';
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->removeFiles($oid,$handler,$path) : null))!=null?$this->addProperties($tmp):null;
					$candidate_oid=(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"");

				$lastOids = array(array($oid, $candidate_oid));
			

					(($__o=$this->getHandler('lib.recruitment.vacancies.services.message','')) ? $__o->sendInterviewEmail($lastOids) : null);
		return true;
	}
}
?>