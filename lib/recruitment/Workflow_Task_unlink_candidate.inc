<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_unlink_candidate extends Workflow_Task
{

	function run($workflow,$user)
	{
        $this->ctxt->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
        $this->ctxt->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
        $this->ctxt->deleteRecords('rct_candidate_vacancy.unlink_candidate@recruitment',$this->ctxt->getRecords('rct_candidate_vacancy.unlink_candidate@recruitment',null,'db'),'db',true);

        $candidates_oids = explode('|', $this->ctxt->getProperty("candidate_oid",""));


       
	   foreach($candidates_oids as $i=>$value)
        {
            //Add log
            $log= new lib_recruitment_candidates_services_log($this->ctxt);
            $log->addLog($value , $GLOBALS["_NX_user"]->getProperty("oid",""), 14 , $this->ctxt->getProperty("vacancy_oid","") , "");

        }
        if($this->getParam('previous_operation')!=null){
            header('Location:'.($u=PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo='.$this->getParam('previous_operation').'&candidate_oid='.$_REQUEST['candidate_oid'].'&'.$this->getFilterKey()));
        }else {
            header('Location:' . ($u = $this->ctxt->getProperty('site.url.noprefix', '') . $_SERVER["PHP_SELF"] . '?nxo=associated_candidate&nxs=&oid=' . $this->ctxt->getProperty("vacancy_oid", "").'&candidate_oid='.$_REQUEST['candidate_oid']));
        }
        nxLog('redirect to '.$u,'redirect');
        return true;
    }
	
	function getFilterKey ()
	{
		$arg = explode('&', $_SERVER['QUERY_STRING']);
		$chaine_final = '';
		foreach( $arg as $value )
		{
			$arg2 = explode('=', $value);  
			if ($arg2[0]== 'filterKey') {$chaine_final .= $value.'&';}   
		}
		return $chaine_final ;
	}
}
?>