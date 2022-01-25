<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class new_ajax_prest_process extends NxPage
{
	function new_ajax_prest_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
							$this->putRecord(
								$this->getRecord('','page.record','post',false,null,null),'','insert','db','Object',null);
							header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=list&nxs=&mode=ajax&amp;oid='.(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:"")));
							nxLog('redirect to '.$u,'redirect');
							return true;

		return true;
	}
}
?>