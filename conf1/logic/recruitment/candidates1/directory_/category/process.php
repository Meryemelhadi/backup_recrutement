<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__category_process extends NxPage
{
	function recruitment_candidates_directory__category_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					(($__o=$this->getHandler('lib.recruitment.candidates.services.directory','')) ? $__o->saveCategoryAssociations((isset($_REQUEST["candidates_oid"])?$_REQUEST["candidates_oid"]:""),(isset($_REQUEST["category_oid"])?$_REQUEST["category_oid"]:"")) : null);
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=list&nxs='.preg_replace('%&amp;%','&',urldecode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""))).'&mode=ajax'));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>