<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961.
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_permission_candidate extends NxPage
{
    function __construct($ctxt,$params,$taskID)
    {
        $this->NxPage($params,$ctxt,null);
        $this->ctxt = $this;
    }

    function run($workflow,$user)
    {
		$rhmanager = ($GLOBALS['_NX_user']->checkPerm('?-rhmanager'));
        if(isset($_REQUEST['from_eval']) && $_REQUEST['from_eval'] == 1){
            $_GET['oid']=$_REQUEST['interview_oid'];
			$_REQUEST['oid']=$_REQUEST['interview_oid'];
            if(!isset($_REQUEST['coid']) || $_REQUEST['coid'] ==''){
				$interview = new PersistentObject('interview_manager.record@recruitement2','db');
				$_REQUEST['oid'] = $interview->candidate_oid->object;
				$_REQUEST['coid'] = $interview->candidate_oid->object;
				$_GET['oid'] = $interview->candidate_oid->object;
				$_GET['coid'] = $interview->candidate_oid->object;
			}
			if(!$rhmanager) {
				header('Location:/recruitment/candidates/coid-'.$_REQUEST['coid'].'/directory.php?nxo=edit&nxs=&mode=page&oid='.$_REQUEST['coid'].'&candidate_oid='.$_REQUEST['coid'].'&from_eval=1&interview_oid='.$_REQUEST['interview_oid']);
			}else{
				header('Location:/recruitment/manager_candidates/coid-'.$_REQUEST['coid'].'/index.php?nxo=edit&nxs=&mode=page&oid='.$_REQUEST['coid'].'&candidate_oid='.$_REQUEST['coid'].'&interview_oid='.$_REQUEST['interview_oid']);
			}
			return false;
        }
		
		$src="";
		$fram="";
		if(isset($_REQUEST['src']) && $_REQUEST['src'] == 'newcvt'){
			$src='newcvt';
			$fram= '/fram';
		} 
		
        if(!$rhmanager) {
            
			if(isset($_REQUEST['from_eval']) && $_REQUEST['from_eval'] == 1)
			header('Location:'.$fram.'/recruitment/candidates/coid-'.$_REQUEST['oid'].'/directory.php?nxo=edit&nxs=&mode=page&oid='.$_REQUEST['oid'].'&candidate_oid='.$_REQUEST['oid'].'&from_mes_candidats=1&src='.$src);
        }
		
        $model = $workflow->model;
        $state = $workflow->getState();
        $interview = new PersistentObject();
        $interview->load('rct_interview.by_user_and_candidate@recruitment','db');
		$vacancy = new PersistentObject();
        $vacancy->load('rct_vacancy.by_user_and_candidate@recruitment','db');

        if(($interview != null && !$interview->isOk()) AND ($vacancy != null && !$vacancy->isOk())){
            header('Location:'.PORTAL_URL_PREFIX.'/recruitment/manager_candidates/index.php?nxo=list&nxs='.preg_replace(array('%&amp;%','%[+]%'),array('&','%2B'),urldecode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""))));
        }
        return true;
    }
}
?>