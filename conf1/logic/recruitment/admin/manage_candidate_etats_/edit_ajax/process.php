<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_admin_manage_candidate_etats__edit_ajax_process extends NxPage
{
	function recruitment_admin_manage_candidate_etats__edit_ajax_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->putRecord(
						$this->getRecord('rct_candidate_etat.record','page.record','post',false,null,null),'rct_candidate_etat.record','update','db','Object',null);
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=list&nxs=&mode=page'));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>