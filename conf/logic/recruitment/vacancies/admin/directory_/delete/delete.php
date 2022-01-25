<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__delete_delete extends NxPage
{
	function recruitment_vacancies_admin_directory__delete_delete($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->deleteRecords('rct_vacancy.delete',$this->getRecords('rct_vacancy.delete',null,'db'),'db',true);
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=list&nxs=&mode=page'));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>