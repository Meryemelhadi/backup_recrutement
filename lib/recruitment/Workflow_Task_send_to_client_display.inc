<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_send_to_client_display extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run()
	{
					
		$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->getRecord('rct_candidate_client.add','page.record','empty',false,null,null);
	
						
		$this->setProperty('edit.url',
			$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"").'&src='.$_REQUEST['src']);
		
		$this->setProperty('submit.url',
			$_SERVER["PHP_SELF"].'?nxo=send_to_client_process');

		$this->runView('recruitment.candidates.components.send_to_client',array(
						'fmethod' => 'toForm',
						),null);
	/*
		$this->runView('/recruitment/candidates/directory__send_to_client',array(
						'fmethod' => 'toForm',
						),null);
	*/
		return true;
	}
}
?>