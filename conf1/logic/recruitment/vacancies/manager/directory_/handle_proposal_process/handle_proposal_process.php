<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_manager_directory__handle_proposal_process_handle_proposal_process extends NxPage
{
	function recruitment_vacancies_manager_directory__handle_proposal_process_handle_proposal_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$cRecord=
						$this->getRecord('rct_candidate_vacancy.handle_proposal@recruitment','page.record','request',false,null,null);
					$date=
						$cRecord->getProperty('date','',false,'object','');

				$rawdate = $date['year'].'-'.$date['month'].'-'.$date['day'];
				$date = strftime ( "%d %B %Y", strtotime($rawdate) ); // Pour affichage dans le log
			

					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty("status_value",(isset($_REQUEST["status_value"])?$_REQUEST["status_value"]:""));
					$this->setProperty("rawdate",$rawdate);
					$this->setProperty("proposal_acceptance_state",'1');
					if($this->getProperty("status_value","") == '11')
					{
						$this->setProperty("proposal_acceptance_state",'2');
					}
					$this->putRecord($null=null,'rct_candidate_vacancy.change_proposal_status@recruitment','update','db','Object',null);
					$this->putRecord(
						$_nx_record_data20=array(
								'candidate_oid'=>(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""),
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>(isset($_REQUEST["status_value"])?$_REQUEST["status_value"]:""),
								'ref_oid'=>'',
								'additional_infos'=>$date,),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
					$progress_level_value='7';
					if($this->getProperty("status_value","") == '11')
					{
						$progress_level_value='8';
					}
					$this->setProperty("vacancy_oid",$this->getProperty("vacancy_oid",""));
					$this->setProperty("progress_level",$progress_level_value);
					$this->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
					$cRecord=
						$this->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
					$progress_level=
						$cRecord->getProperty('progress_level','',false,'object','');
					$progress_level_meta=
						$cRecord->getProperty('progress_level_meta','',false,'html','');
					$this->putRecord(
						$_nx_record_data21=array(
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'progress_level'=>$this->getProperty("progress_level",""),
								'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
		return true;
	}
}
?>