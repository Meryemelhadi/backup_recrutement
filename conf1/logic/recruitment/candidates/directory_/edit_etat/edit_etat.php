<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__edit_etat_edit_etat extends NxPage
{
	function recruitment_candidates_directory__edit_etat_edit_etat($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty("etat_oid",(isset($_REQUEST["etat_oid"])?$_REQUEST["etat_oid"]:""));
					$this->putRecord($null=null,'rct_candidate.edit_etat','update','db','Object',null);
		return true;
	}
}
?>