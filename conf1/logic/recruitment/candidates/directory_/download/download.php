<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__download_download extends NxPage
{
	function recruitment_candidates_directory__download_download($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.candidates.services.directory','')) ? $__o->download((isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""),(isset($_REQUEST["type"])?$_REQUEST["type"]:"")) : null))!=null?$this->addProperties($tmp):null;
		return true;
	}
}
?>