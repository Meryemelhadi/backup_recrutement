<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__view_interview_synthesis_view_interview_synthesis extends NxPage
{
	function recruitment_vacancies_client_directory__view_interview_synthesis_view_interview_synthesis($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("synthesis_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->setProperty("interview_oid",(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:""));
					$this->getRecord('rct_interview_synthesis.view@recruitment','page.record','db',false,null,null);
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=edit_interview&amp;nxs=&amp;interview_oid='.(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:"").'&amp;candidate_oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->runView('/recruitment/vacancies/client/directory__interview_synthesis_view',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>