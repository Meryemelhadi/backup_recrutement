<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class schedule_warning_process_schedule_warning_process extends NxPage
{
	function schedule_warning_process_schedule_warning_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
							$this->putRecord(
								$this->getRecord('rct_warning.schedule@recruitment','page.record','post',false,null,null),'rct_warning.schedule@recruitment','insert','db','Object',null);
		return true;
	}
}
?>