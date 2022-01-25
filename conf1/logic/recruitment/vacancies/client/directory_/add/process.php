<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__add_process extends NxPage
{
	function recruitment_vacancies_client_directory__add_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$candidateOid=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->saveNewCV() : null);
					<card_lib:addlog/>
					(($__o=$this->getHandler('','')) ? $__o->partial($candidateOid) : null);
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$candidateOid.'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->runView('/recruitment/vacancies/client/directory__redirect',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>