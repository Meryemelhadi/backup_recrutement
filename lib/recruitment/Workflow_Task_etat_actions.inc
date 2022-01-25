<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_etat_actions extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
	}
	

	function run()
	{ 
	
		if(!isset($_REQUEST['candidate_oid']))return true;
		if(isset($_REQUEST['etat_oid']) && $_REQUEST['etat_oid'] != ''){
			$this->setProperty('candidate_oid' , $_REQUEST['candidate_oid']);
			$this->getRecords('actions_candidate_etat.by_etat@recruitment','page.records','db',false,null,null);
			$this->runView('recruitment.candidates.components/actions_button',array('fmethod' => 'toHTML'),null);
			
		}

		return true;
	}
}
?>