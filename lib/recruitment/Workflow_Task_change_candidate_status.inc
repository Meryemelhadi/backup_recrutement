<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');
class Workflow_Task_change_candidate_status extends Workflow_Task
{

	function run($workflow,$user)
	{
        if(isset($_REQUEST["status_value"])){
            $this->ctxt->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
            $this->ctxt->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
            $this->ctxt->setProperty("status_value",(isset($_REQUEST["status_value"])?$_REQUEST["status_value"]:""));
            $this->ctxt->putRecord($null=null,'rct_candidate_vacancy.change_status@recruitment','update','db','Object',null);
            if($this->ctxt->getProperty("status_value","") == '5')
            {
                $this->ctxt->setProperty("acceptance_status",'1');
                $this->ctxt->putRecord($null=null,'rct_candidate_vacancy.change_ci_acceptance@recruitment','update','db','Object',null);
            }
            elseif($this->ctxt->getProperty("status_value","") == '6')
            {
                $this->ctxt->setProperty("acceptance_status",'2');
                $this->ctxt->putRecord($null=null,'rct_candidate_vacancy.change_ci_acceptance@recruitment','update','db','Object',null);
            }
            elseif($this->ctxt->getProperty("status_value","") == '7')
            {
                $this->ctxt->setProperty("acceptance_status",'1');
                $this->ctxt->putRecord($null=null,'rct_candidate_vacancy.change_job_acceptance@recruitment','update','db','Object',null);
            }
            elseif($this->ctxt->getProperty("status_value","") == '8')
            {
                $this->ctxt->setProperty("acceptance_status",'0');
                $this->ctxt->putRecord($null=null,'rct_candidate_vacancy.change_job_acceptance@recruitment','update','db','Object',null);
            }
            elseif($this->ctxt->getProperty("status_value","") == '18')
            {
                $this->ctxt->setProperty("acceptance_status",'2');
                $this->ctxt->putRecord($null=null,'rct_candidate_vacancy.change_job_acceptance@recruitment','update','db','Object',null);
            }
            $this->ctxt->putRecord($null=null,'rct_vacancy.close_vacancy@recruitment','update','db','Object',null);
			
			//Get Candidate state
			$candidate_state= $this->ctxt->getRecord('rct_candidate_etat.by_vacancy_status@recruitment',null,'db',false,null,null);

            $candidates_oids = explode('|', $this->ctxt->getProperty("candidate_oid",""));

            foreach($candidates_oids as $i=>$value)
            {
				if($candidate_state != null && $candidate_state->getProperty('oid' , '',false,'object','')){
					$this->ctxt->setProperty("candidate_oid",$value);
					$this->ctxt->setProperty("etat_oid",$candidate_state->getProperty('oid' , '',false,'object',''));
					
					$this->ctxt->putRecord($null=null,'rct_candidate.edit_etat@recruitment','update','db','Object',null);
					$vacancy_name = $this->ctxt->getRecord('rct_vacancy.find_name_by_oid@recruitment',null,'db',false,null,null);
					$log= new lib_recruitment_candidates_services_log($this->ctxt);
					$log->addLog($this->ctxt->getProperty("candidate_oid","") , $user->oid->object, 8 , '' , '(Nouvel état: '.$candidate_state->getProperty('name' , '',false,'object','').' )('.$candidate_state->getProperty('vacancy_status', '' , false , 'string' , '').' : '.$vacancy_name->getProperty('name', '' , false , 'string' , '').')');
				}

				$log= new lib_recruitment_candidates_services_log($this->ctxt);
				$log->addLogVacancy_Candidat($value, $this->ctxt->getProperty("vacancy_oid","") , $GLOBALS["_NX_user"]->getProperty("oid",""), (isset($_REQUEST["status_value"])?$_REQUEST["status_value"]:"") , '' , '');
		
                /*$this->ctxt->putRecord(
                    $_nx_record_data67=array(
                        'candidate_oid'=>$value,
                        'vacancy_oid'=>$this->ctxt->getProperty("vacancy_oid",""),
                        'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
                        'action_oid'=>(isset($_REQUEST["status_value"])?$_REQUEST["status_value"]:""),
                        'ref_oid'=>'',
                        'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);*/
            }

            if($this->ctxt->getProperty("status_value","") == '7')
            {
                $this->ctxt->setProperty("vacancy_oid",$this->ctxt->getProperty("vacancy_oid",""));
                $this->ctxt->setProperty("progress_level",'9');
                $this->ctxt->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
                $cRecord=
                    $this->ctxt->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
                $progress_level=
                    $cRecord->getProperty('progress_level','',false,'object','');
                $progress_level_meta=
                    $cRecord->getProperty('progress_level_meta','',false,'html','');
                $this->ctxt->putRecord(
                    $_nx_record_data68=array(
                        'vacancy_oid'=>$this->ctxt->getProperty("vacancy_oid",""),
                        'progress_level'=>$this->ctxt->getProperty("progress_level",""),
                        'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
            }
            if($this->ctxt->getProperty("status_value","") == '18')
            {
                $this->ctxt->setProperty("vacancy_oid",$this->ctxt->getProperty("vacancy_oid",""));
                $this->ctxt->setProperty("progress_level",'10');
                $this->ctxt->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
                $cRecord=
                    $this->ctxt->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
                $progress_level=
                    $cRecord->getProperty('progress_level','',false,'object','');
                $progress_level_meta=
                    $cRecord->getProperty('progress_level_meta','',false,'html','');
                $this->ctxt->putRecord(
                    $_nx_record_data69=array(
                        'vacancy_oid'=>$this->ctxt->getProperty("vacancy_oid",""),
                        'progress_level'=>$this->ctxt->getProperty("progress_level",""),
                        'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
            }

            if($this->getParam('previous_operation')!=null){
                header('Location:'.($u=PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo='.$this->getParam('previous_operation')."&candidate_oid=".$_REQUEST['candidate_oid']));
            }else{
                header('Location:'.($u=$this->ctxt->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=candidates&nxs=&oid='.$this->ctxt->getProperty("vacancy_oid","")."&candidate_oid=".$_REQUEST['candidate_oid']));
            }
            nxLog('redirect to '.$u,'redirect');
            return true;

        }
        return true;
    }
}
?>