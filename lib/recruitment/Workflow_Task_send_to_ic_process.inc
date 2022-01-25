<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');
class Workflow_Task_send_to_ic_process extends Workflow_Task
{

	function run($workflow,$user)
	{
        $this->ctxt->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
        $this->ctxt->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
        $this->ctxt->putRecord(
            $this->ctxt->getRecord('rct_candidate_vacancy_client.add@recruitment','page.record','post',false,null,null),'rct_candidate_vacancy_client.add@recruitment','insert','db','Object',null);
        $assocOid=
            $this->ctxt->getLastInsertID('db');

        $candidates_oids = explode('|', $this->ctxt->getProperty("candidate_oid",""));


        foreach($candidates_oids as $i=>$value)
        {
			$log= new lib_recruitment_candidates_services_log($this->ctxt);
			$log->addLogVacancy_Candidat($value, $this->ctxt->getProperty("vacancy_oid","") , $GLOBALS["_NX_user"]->getProperty("oid",""), 2 , '' , '');
		
            /*$this->ctxt->putRecord(
                $_nx_record_data73=array(
                    'candidate_oid'=>$value,
                    'vacancy_oid'=>$this->ctxt->getProperty("vacancy_oid",""),
                    'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
                    'action_oid'=>'2',
                    'ref_oid'=>'',
                    'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);*/
        }
        (($__o=$this->ctxt->getHandler('lib.recruitment.vacancies.services.message','')) ? $__o->sendCandidateNotificationEmail($assocOid) : null);
        $this->ctxt->setProperty("vacancy_oid",$this->ctxt->getProperty("vacancy_oid",""));
        $this->ctxt->setProperty("progress_level",'4');
        $this->ctxt->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
        $cRecord=
            $this->ctxt->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
        $progress_level=
            $cRecord->getProperty('progress_level','',false,'object','');
        $progress_level_meta=
            $cRecord->getProperty('progress_level_meta','',false,'html','');
        $this->ctxt->putRecord(
            $_nx_record_data74=array(
                'vacancy_oid'=>$this->ctxt->getProperty("vacancy_oid",""),
                'progress_level'=>$this->ctxt->getProperty("progress_level",""),
                'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
        return true;
    }
}
?>