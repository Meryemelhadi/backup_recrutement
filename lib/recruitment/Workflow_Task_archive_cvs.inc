<?php

require_once(NX_LIB.'module/NxPage.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_archive_cvs extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run()
	{
		
		$candidates_oid=(isset($_REQUEST["candidates_oid"])?$_REQUEST["candidates_oid"]:"");
		$candidates_oids = explode('|', $candidates_oid);

		foreach($candidates_oids as $i=>$oid)
		{
			if($oid != ''){
				$_REQUEST['oid'] = $oid;
				$this->putRecord($null=null,'rct_candidate.archive_cv','update','db','Object',null);
				$log= new lib_recruitment_candidates_services_log($this->ctxt);
				$log->addLog($oid , $GLOBALS["_NX_user"]->getProperty("oid","") , 2 , '' , '');
				/*$this->putRecord(
					$_nx_record_data12=array(
							'candidate_oid'=>$oid,
							'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
							'action_oid'=>'2',
							'ref_oid'=>'',
							'additional_infos'=>'',),'rct_candidate_action.record','insert','db','Object',null);*/
			}
			
		}
		$this->setProperty("filterKey",(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""));
		header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=list&nxs='.preg_replace(array('%&amp;%','%[+]%'),array('&','%2B'),urldecode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""))).'&mode=ajax'));
		nxLog('redirect to '.$u,'redirect');
		
		return true;

	}
}
?>