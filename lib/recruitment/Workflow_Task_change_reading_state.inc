<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_change_reading_state extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function insertReadState($userOid, $candidateOid) {
		
		$db = &$this->ctxt->getDB($this->ctxt->error);

		// insert read state
		$db->query("INSERT INTO _rct_candidate_read_state (_user_oid, _candidate_oid, _read_time) SELECT '$userOid','$candidateOid' , NOW() FROM DUAL WHERE NOT EXISTS (SELECT * FROM _rct_candidate_read_state WHERE _user_oid='$userOid' AND _candidate_oid='$candidateOid')");		
		// get flag state
		
	}
	

	function run()
	{		
		if((isset($_REQUEST["reading_state"])?$_REQUEST["reading_state"]:"") == '1')
		{

			// remove read state
			$this->deleteRecords('rct_candidate_read_state.delete@recruitment',$this->getRecords('rct_candidate_read_state.delete@recruitment',null,'db'),'db',true);
		}
						
		else 
		{


			// add read state
			$this->insertReadState($GLOBALS["_NX_user"]->getProperty("oid",""),(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
		}
		return true;
	}
}
?>