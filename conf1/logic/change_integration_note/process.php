<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class change_integration_note_process extends NxPage
{
	function change_integration_note_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
							$this->setProperty("assoc_oid",(isset($_REQUEST["assoc_oid"])?$_REQUEST["assoc_oid"]:""));
							$this->putRecord(
								$this->getRecord('','page.record','post',false,null,null),'','update','db','Object',null);
		return true;
	}
}
?>