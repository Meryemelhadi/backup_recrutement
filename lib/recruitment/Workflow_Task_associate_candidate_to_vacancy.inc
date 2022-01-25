<?php

require_once(NX_LIB.'module/NxPage.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_associate_candidate_to_vacancy extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
	}


	function run($workflow, $user)
	{
		$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
		$this->setProperty("oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
		$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
		$this->putRecord($null=null,'rct_candidate_vacancy.add_assoc@recruitment','insert','db','Object',null);
		$candidate =  new PersistentObject('rct_candidate.set_hr_manager','db',array('oid' => (isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"")));
		$vacancy = $this->getRecord('rct_vacancy.record_manager' , '' , 'db' , false , null , null);
		if($candidate->hr_manager->object == null || $candidate->hr_manager->object == '' || $candidate->hr_manager->object == 0){
			if($vacancy->manager_oid->object != null && $vacancy->manager_oid->object != '' && $vacancy->manager_oid->object != 0){
				$candidate->setFieldValue('hr_manager' , $vacancy->manager_oid->object);
			}else{
				$candidate->setFieldValue('hr_manager' , $vacancy->creator->object);
			}
			$candidate->store('rct_candidate.set_hr_manager', 'update' , 'db' , array('oid'=>(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"")));
		}
		
		$log= new lib_recruitment_candidates_services_log($this->ctxt);
		$log->addLog($this->getProperty("candidate_oid","") , $GLOBALS["_NX_user"]->getProperty("oid","") , 3 , $this->getProperty("vacancy_oid","") , '');
		/*$this->putRecord(
			$_nx_record_data5=array(
					'candidate_oid'=>$this->getProperty("candidate_oid",""),
					'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
					'action_oid'=>'3',
					'ref_oid'=>$this->getProperty("vacancy_oid",""),
					'additional_infos'=>'',),'rct_candidate_action.record@recruitment','insert','db','Object',null);*/
					
		$log->addLogVacancy_Candidat($this->getProperty("candidate_oid",""), $this->getProperty("vacancy_oid","") , $GLOBALS["_NX_user"]->getProperty("oid",""), 0 , '' , '');;
		
		/*$this->putRecord(
			$_nx_record_data6=array(
					'candidate_oid'=>$this->getProperty("candidate_oid",""),
					'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
					'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
					'action_oid'=>'0',
					'ref_oid'=>'',
					'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);*/
		$this->setProperty("application_type",'0');
		$this->putRecord($null=null,'rct_vacancy.change_application_type@recruitment','update','db','Object',null);
		$this->setProperty('unlink_candidate.url',$_SERVER["PHP_SELF"].'?nxo=unlink_candidate&amp;nxs=&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
		$this->getRecord('rct_candidate_vacancy.get_assoc@recruitment','page.record','db',false,null,null);
		$this->runView('/recruitment/candidates/directory__vacancy_assoc',array(
			'fmethod' => 'toHTML',
			),null);
		$this->setProperty("vacancy_oid",$this->getProperty("vacancy_oid",""));
		$this->setProperty("progress_level",'3');
		$this->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
		$cRecord=
			$this->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
		$progress_level=
			$cRecord->getProperty('progress_level','',false,'object','');
		$progress_level_meta=
			$cRecord->getProperty('progress_level_meta','',false,'html','');
		$this->putRecord(
			$_nx_record_data7=array(
					'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
					'progress_level'=>$this->getProperty("progress_level",""),
					'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
		return true;
		
	}
}
?>