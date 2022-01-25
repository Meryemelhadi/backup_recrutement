<?php

require_once(NX_LIB.'module/NxPage.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_associate_to_etat_process extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run($workflow,$user)
	{

		if(!isset($_REQUEST["candidate_oid"]) ||$_REQUEST["candidate_oid"] == '') return true ;
		if(!isset($_REQUEST["etat_oid"]) ||$_REQUEST["etat_oid"] == '') return true ;
		
		$this->setProperty("etat_oid",(isset($_REQUEST["etat_oid"])?$_REQUEST["etat_oid"]:""));
		$candidate_oid = $_REQUEST["candidates_oid"];

		/** update candidate etat **/
		$this->ctxt->setProperty("candidate_oid",$candidate_oid);
		
		$record = new PersistentObject("rct_candidate.edit_etat@recruitment",'db', array('candidate_oid'=>$candidate_oid));
			if($_REQUEST['etat_oid'] == '0')
				$record->etat_oid->object = '';
			else $record->etat_oid->object = $_REQUEST['etat_oid'];
			$record->store('rct_candidate.edit_etat@recruitment','update','db', array('candidate_oid'=>$value));

			/** add candidate etat **/
			$log= new lib_recruitment_candidates_services_log($this->ctxt);
			if($_REQUEST['etat_oid'] != '0'){
				$v = new PersistentObject("rct_candidate_vacancy.get_last_vacancy_for_candidate" ,'db' , array('candidate_oid' => $value ));
				$vacancy_oid =  $v->vacancy_oid->object;
				$record_etat = new PersistentObject('rct_candidate_etat.record_name', 'db' , array('etat_oid'=>$_REQUEST['etat_oid']));
				$log->addLog($value , $user->oid->object, 8 , '' , '(Nouvel état: '.$record_etat->name->html.' )' , $vacancy_oid);
			}else $log->addLog($value , $user->oid->object, 8 , '' , 'Etat supprimé' , NULL);
			
		
			
		}
		header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=list&nxs='.preg_replace(array('%&amp;%','%[+]%'),array('&','%2B'),urldecode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""))).'&mode=ajax&is_search=true'));
		nxLog('redirect to '.$u,'redirect');
		return true;
	}
	
}
?>