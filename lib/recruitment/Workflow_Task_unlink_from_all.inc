<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_unlink_from_all extends Workflow_Task
{

	function run($workflow,$user)
	{
        
        $this->ctxt->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
        $this->ctxt->deleteRecords('rct_candidate_vacancy.unlink_from_all@recruitment',$this->ctxt->getRecords('rct_candidate_vacancy.unlink_from_all@recruitment',null,'db'),'db',true);

		//Add log
		$log= new lib_recruitment_candidates_services_log($this->ctxt);
		$log->addLog($this->ctxt->getProperty("candidate_oid","") , $GLOBALS["_NX_user"]->getProperty("oid",""), 17 , "" , "");

        
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