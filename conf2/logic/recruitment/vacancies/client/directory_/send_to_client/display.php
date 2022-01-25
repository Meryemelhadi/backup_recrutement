<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__send_to_client_display extends NxPage
{
	function recruitment_vacancies_client_directory__send_to_client_display($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->getRecord('','page.record','empty',false,null,null);
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process');
					$this->runView('/recruitment/vacancies/client/directory__send_to_client',array(
						'fmethod' => 'toForm',

						),null);
		return true;
	}
}
?>