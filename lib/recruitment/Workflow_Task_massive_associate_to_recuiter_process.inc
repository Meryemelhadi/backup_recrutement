<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_massive_associate_to_recuiter_process extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run()
	{
					
		$candidateOids = explode('|',trim($_REQUEST['candidates_oid'],'|'));
		$candidates = $_REQUEST['candidates_oid'];
		foreach($candidateOids as $c) {
			$this->setProperty('candidate_oid' , $c);
			$this->putRecord(
				$this->getRecord('rct_candidate.set_massive_hr_manager','page.record','post',false,null,null),'rct_candidate.set_massive_hr_manager','update','db','Object',null);
		}
		return true;
	}
}
?>