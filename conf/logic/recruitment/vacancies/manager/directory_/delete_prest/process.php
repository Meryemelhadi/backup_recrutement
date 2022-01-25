<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__delete_prest_process extends NxPage
{
	function recruitment_vacancies_manager_directory__delete_prest_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));

					/* load empty record for form  */
					$this->deleteRecords('rct_prestataire_vacancy.record',$this->getRecords('rct_prestataire_vacancy.record',null,'db'),'db',true);
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=list_prest&nxs=&mode=ajax&mode=ajax&oid='.(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:"")));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>