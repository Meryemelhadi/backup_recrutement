<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class delete_description_process extends NxPage
{
	function delete_description_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{

							/* load empty record for form  */
							$this->deleteRecords('',$this->getRecords('',null,'db'),'db',true);
							header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=list_description&nxs=&mode=ajax'));
							nxLog('redirect to '.$u,'redirect');
							return true;

		return true;
	}
}
?>