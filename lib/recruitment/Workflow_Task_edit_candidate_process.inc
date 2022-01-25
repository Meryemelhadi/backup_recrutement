<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once('candidates/services/directory.inc');
require_once('candidates/services/denormalisation.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_edit_candidate_process extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run($workflow,$user)
	{

		// save CV information
		$directory = new lib_recruitment_candidates_services_directory($this->ctxt);
		$candidateOid = $directory->saveExistingCV();
		$this->setProperty("candidate_oid",$candidateOid);

        $this->setProperty('tonight', date("Y-m-d 0:0:0"));

        $log= new lib_recruitment_candidates_services_log($this->ctxt);
        //cas modification de l'etat
        if(isset($_GET['record']) && $_GET['record'] == 'etat_oid'){
            $record_etat = new PersistentObject('rct_candidate_etat.record_name', 'db' , array('etat_oid'=>$_POST['etat_oid']));
            //$log->addLog($candidateOid , $user->oid->object, 8 , '' , '(Nouvel état: '.$record_etat->name->html.' )');
			if(isset($_REQUEST["vacancy_oid"]) && $_REQUEST["vacancy_oid"]!= null && $_REQUEST["vacancy_oid"] != "" && $_REQUEST["vacancy_oid"] != "?"){
				$vacancy_oid = $_REQUEST["vacancy_oid"];
			}else{
				$v = new PersistentObject("rct_candidate_vacancy.get_last_vacancy_for_candidate" ,'db' , array('candidate_oid' => $candidateOid ));
				$vacancy_oid =  $v->vacancy_oid->object;
			}
            $log->addLog($candidateOid , $user->oid->object, 8 , '' , '(Nouvel état: '.$record_etat->name->html.' )' , $vacancy_oid);

        }else {
            $log->addEditLogs($candidateOid, $user->oid->object, 1, '', "");
        }

		// denormalisation of database
		$denormalisation = new lib_recruitment_candidates_services_denormalisation($this->ctxt);
		$denormalisation->partial($candidateOid);

		// set buttons
		//$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$candidateOid.'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));

		$this->runView(
			'/recruitment/candidates/directory__redirect',
			array('fmethod' => 'toHTML'),null);

		return true;

	}
}
?>