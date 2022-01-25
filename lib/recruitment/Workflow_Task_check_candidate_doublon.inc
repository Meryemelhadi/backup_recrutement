<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once('candidates/services/directory.inc');

class Workflow_Task_check_candidate_doublon extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run($workflow,$user)
	{
	
        $candidate = new PersistentObject();
        $candidate->load('recruitment.candidates.getCandidate_by_name','db');
        if($candidate->isOk()){
			$editUrl = dirname($_SERVER["PHP_SELF"]).'/coid-'.$candidate->oid->object.'/directory.php?nxo=edit&nxs=&oid='.$candidate->oid->object.'&candidate_oid='.$candidate->oid->object.'&filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""));
			echo $editUrl;
        }
		
	}
}
?>