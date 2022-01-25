<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');
require_once('candidates/services/message.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_send_to_client_process extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}	

	function run()
	{
		$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					
			
		$this->putRecord($this->getRecord('rct_candidate_client.add','page.record','post',false,null,null),'rct_candidate_client.add','insert','db','Object',null);
					
		$relationOid=$this->getLastInsertID('db');

        //Add log
        $proposed_to = new PersistentObject('user.get_full_name@recruitment','db',array("user_oid"=>$_REQUEST['proposed_to']));
        $log= new lib_recruitment_candidates_services_log($this->ctxt);
        $log->addLog((isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"") , $GLOBALS["_NX_user"]->getProperty("oid",""), 5 , '' , "(Client interne: ".$proposed_to->first_name->html." ".$proposed_to->last_name->html." )");

		$messageLib = new lib_recruitment_candidates_services_message($this->ctxt);
		$messageLib->sendToManyClients($relationOid);

		return true;
	}
}
?>