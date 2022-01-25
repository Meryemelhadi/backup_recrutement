<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__add_attached_files_add_attached_files extends NxPage
{
	function recruitment_candidates_directory__add_attached_files_add_attached_files($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->putRecord(
						$this->getRecord('rct_candidate_files.record','page.record','request',false,null,null),'rct_candidate_files.record','insert','db','Object',null);
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=edit&nxs=&mode=page&tab=recruitement_card&oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"").'&candidate_oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"")));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>