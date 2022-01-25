<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_annuaire_directory__edit_edit_process extends NxPage
{
	function recruitment_annuaire_directory__edit_edit_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$loadedRecord=
						$this->getRecord('rct_client.edit','page.record','post',false,null,null);
					$this->putRecord($loadedRecord,'rct_client.edit','update','db','Object',null);
		return true;
	}
}
?>