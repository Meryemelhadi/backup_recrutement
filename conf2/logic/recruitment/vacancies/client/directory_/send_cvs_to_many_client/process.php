<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__send_cvs_to_many_client_process extends NxPage
{
	function recruitment_vacancies_client_directory__send_cvs_to_many_client_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->putRecord(
						$this->getRecord('','page.record','post',false,null,null),'','insert','db','Object',null);
					$relationOid=
						$this->getLastInsertID('db');
					<card_lib:addlog/>
					(($__o=$this->getHandler('','')) ? $__o->sendManyCvsToManyClients($relationOid) : null);
		return true;
	}
}
?>