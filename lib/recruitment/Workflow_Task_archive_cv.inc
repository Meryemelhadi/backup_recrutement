<?php

require_once(NX_LIB.'module/NxPage.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_archive_cv extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run()
	{
		$this->putRecord($null=null,'rct_candidate.archive','update','db','Object',null);
		$oid=(isset($_REQUEST["oid"])?$_REQUEST["oid"]:"");
		$log= new lib_recruitment_candidates_services_log($this->ctxt);
		$log->addLog($oid , $GLOBALS["_NX_user"]->getProperty("oid","") , 2 , '' , '');

		/*$this->putRecord(
				$_nx_record_data12=array(
						'candidate_oid'=>$oid,
						'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
						'action_oid'=>'2',
						'ref_oid'=>'',
						'additional_infos'=>'',),'rct_candidate_action.record','insert','db','Object',null);*/
		if(isset($_REQUEST["src"]) && $_REQUEST["src"] ===  'newcvt'){
			$this->setProperty('redirect_url.url',PORTAL_URL_PREFIX .'/recruitment3/home.php');
		}else{
			$this->setProperty('redirect_url.url',PORTAL_URL_PREFIX .'/recruitment/candidates/directory.php?nxo=list&nxs=' . preg_replace(array('%&amp;%', '%[+]%'), array('&', '%2B'), urldecode((isset($_REQUEST["filterKey"]) ? $_REQUEST["filterKey"] : ""))));
		}
		$this->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);

		
		return true;

	}
}
?>