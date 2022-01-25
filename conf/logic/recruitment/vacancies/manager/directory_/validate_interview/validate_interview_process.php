<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_manager_directory__validate_interview_validate_interview_process extends NxPage
{
	function recruitment_vacancies_manager_directory__validate_interview_validate_interview_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty("interview_oid",(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:""));
					$this->setProperty("validation_state",(isset($_REQUEST["validation_oid"])?$_REQUEST["validation_oid"]:""));
					$this->putRecord($null=null,'rct_interview.validate_process','update','db','Object',null);
					$validation_state_log='17';
					if((isset($_REQUEST["validation_oid"])?$_REQUEST["validation_oid"]:"") == '1')
					{
						$validation_state_log='13';
					}
					$this->putRecord(
						$_nx_record_data13=array(
								'candidate_oid'=>$this->getProperty("candidate_oid",""),
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>$validation_state_log,
								'ref_oid'=>$this->getProperty("interview_oid",""),
								'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
					if((isset($_REQUEST["validation_oid"])?$_REQUEST["validation_oid"]:"") == '1')
					{
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
							$_nx_record_data14=array(
									'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
									'progress_level'=>$this->getProperty("progress_level",""),
									'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
					}
						if((isset($_REQUEST["validation_oid"])?$_REQUEST["validation_oid"]:"") == '1')
						{
							header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=edit_interview&nxs=&oid='.(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:"").'&interview_oid='.(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:"")));
							nxLog('redirect to '.$u,'redirect');
							return true;

						}
						else {
							header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=calendar&nxs=&oid='.(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:"")));
							nxLog('redirect to '.$u,'redirect');
							return true;

						}
		return true;
	}
}
?>