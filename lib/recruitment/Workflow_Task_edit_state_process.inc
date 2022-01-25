<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');
class Workflow_Task_edit_state_process extends Workflow_Task
{

	function run($workflow,$user)
	{ 
        $this->ctxt->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
        $this->ctxt->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
		$record =  new PersistentObject('rct_candidate_vacancy.edit_state@recruitment' , 'db');
		$record->setFieldValue('etat_oid' , $_REQUEST['etat_oid'] );
		$record->store('rct_candidate_vacancy.edit_state@recruitment', 'update' , 'db');
			
		/** Edit field etat_oid : table rct_candidate ***/
		$o =  new PersistentObject('rct_candidate.set_etat_oid@recruitment' , 'db');
		$o->setFieldValue('etat_oid' , $_REQUEST['etat_oid'] );
		$o->store('rct_candidate.set_etat_oid@recruitment', 'update' , 'db');
		
		/** Historique **/
		$log= new lib_recruitment_candidates_services_log($this->ctxt);
		$vacancy= new PersistentObject('rct_vacancy.find_name_by_oid@recruitment' , 'db');
		$log->addLog($_REQUEST["candidate_oid"] , $user->oid->object, 8 , '' , '(Nouvel état: '.$o->etat_oid->html.' pour le poste '.$vacancy->name->object.'  )');
		$log->addLog($_REQUEST["candidate_oid"] , $user->oid->object, 8 , '' , '(Nouvel état: '.$o->etat_oid->html.' )');
		
		if($this->getParam('previous_operation')!=null){
			header('Location:'.($u=PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo='.$this->getParam('previous_operation')."&candidate_oid=".$_REQUEST['candidate_oid']));
		}else{
			//header('Location:'.($u=$this->ctxt->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=candidates&nxs=&oid='.$this->ctxt->getProperty("vacancy_oid","")."&candidate_oid=".$_REQUEST['candidate_oid']));
		}
		nxLog('redirect to '.$u,'redirect');
		return true;
        return true;
    }
}
?>