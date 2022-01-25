<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__edit_request_edit_request extends NxPage
{
	function recruitment_vacancies_client_directory__edit_request_edit_request($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecord('rct_vacancy.request','page.record','db',false,null,null);
					$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=edit_request_process');
					$this->runView('/recruitment/vacancies/client/directory__edit_request',array(
						'fmethod' => 'toForm',

						),null);
		return true;
	}
}
?>