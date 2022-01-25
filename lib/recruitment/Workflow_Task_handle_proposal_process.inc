<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_handle_proposal_process extends Workflow_Task
{

	function run($workflow,$user)
	{
        $cRecord= $this->ctxt->getRecord('rct_candidate_vacancy.handle_proposal@recruitment','page.record','request',false,null,null);
        $date= $cRecord->getProperty('date','',false,'object','');

        $rawdate = $date['year'].'-'.$date['month'].'-'.$date['day'];
        $date = strftime ( "%d %B %Y", strtotime($rawdate) ); // Pour affichage dans le log

        $this->ctxt->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
        $this->ctxt->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
        $this->ctxt->setProperty("status_value",(isset($_REQUEST["status_value"])?$_REQUEST["status_value"]:""));
        $this->ctxt->setProperty("rawdate",$rawdate);
        $this->ctxt->setProperty("proposal_acceptance_state",'1');
        if($this->ctxt->getProperty("status_value","") == '11')
        {
            $this->ctxt->setProperty("proposal_acceptance_state",'2');
        }
        $this->ctxt->putRecord($null=null,'rct_candidate_vacancy.change_proposal_status@recruitment','update','db','Object',null);
		$log= new lib_recruitment_candidates_services_log($this->ctxt);
		$log->addLogVacancy_Candidat((isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""), $this->ctxt->getProperty("vacancy_oid","") , $GLOBALS["_NX_user"]->getProperty("oid",""), (isset($_REQUEST["status_value"])?$_REQUEST["status_value"]:"") , '' , $date);
		
        /*$this->ctxt->putRecord(
            $_nx_record_data70=array(
                'candidate_oid'=>(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""),
                'vacancy_oid'=>$this->ctxt->getProperty("vacancy_oid",""),
                'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
                'action_oid'=>(isset($_REQUEST["status_value"])?$_REQUEST["status_value"]:""),
                'ref_oid'=>'',
                'additional_infos'=>$date,),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);*/

        $progress_level_value='7';
        if($this->ctxt->getProperty("status_value","") == '11')
        {
            $progress_level_value='8';
        }
        $this->ctxt->setProperty("vacancy_oid",$this->ctxt->getProperty("vacancy_oid",""));
        $this->ctxt->setProperty("progress_level",$progress_level_value);
        $this->ctxt->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
        $cRecord=
            $this->ctxt->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
        $progress_level=
            $cRecord->getProperty('progress_level','',false,'object','');
        $progress_level_meta=
            $cRecord->getProperty('progress_level_meta','',false,'html','');
			
		//Get Candidate state
		$candidate_state= $this->ctxt->getRecord('rct_candidate_etat.by_vacancy_status@recruitment',null,'db',false,null,null);
	
		if($candidate_state != null && $candidate_state->getProperty('oid' , '',false,'object','')){
			$this->ctxt->setProperty("etat_oid",$candidate_state->getProperty('oid' , '',false,'object',''));
			$this->ctxt->putRecord($null=null,'rct_candidate.edit_etat@recruitment','update','db','Object',null);
			$vacancy_name = $this->ctxt->getRecord('rct_vacancy.find_name_by_oid@recruitment',null,'db',false,null,null);
			$log= new lib_recruitment_candidates_services_log($this->ctxt);
			//$log->addLog($this->ctxt->getProperty("candidate_oid","") , $user->oid->object, 8 , '' , '(Nouvel état: '.$candidate_state->getProperty('name' , '',false,'object','').' ) ('.$candidate_state->getProperty('vacancy_status', '' , false , 'string' , '').' : '.$vacancy_name->getProperty('name', '' , false , 'string' , '').')');
			if($this->ctxt->getProperty("vacancy_oid","") !=  null && $this->ctxt->getProperty("vacancy_oid","") != ""){
				$v = $this->ctxt->getProperty("vacancy_oid","");
			}else{
				$v_object = new PersistentObject("rct_candidate_vacancy.get_last_vacancy_for_candidate" ,'db' , array('candidate_oid' => $this->ctxt->getProperty("candidate_oid","") ));
				$v = $v->vacancy_oid->object;
			}
			$log->addLog($this->ctxt->getProperty("candidate_oid","") , $user->oid->object, 8 , '' , '(Nouvel Ã©tat: '.$candidate_state->getProperty('name' , '',false,'object','').' ) ('.$candidate_state->getProperty('vacancy_status', '' , false , 'string' , '').' : '.$vacancy_name->getProperty('name', '' , false , 'string' , '').')' , $v);
		
		}
			
			
		//Change candidate status
		
        $this->ctxt->putRecord(
            $_nx_record_data71=array(
                'vacancy_oid'=>$this->ctxt->getProperty("vacancy_oid",""),
                'progress_level'=>$this->ctxt->getProperty("progress_level",""),
                'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);

        return true;
    }
}
?>