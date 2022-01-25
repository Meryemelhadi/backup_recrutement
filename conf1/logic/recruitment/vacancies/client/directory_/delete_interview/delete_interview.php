<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__delete_interview_delete_interview extends NxPage
{
	function recruitment_vacancies_client_directory__delete_interview_delete_interview($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("interview_oid",(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:""));
					$this->deleteRecords('rct_interview_synthesis.delete@recruitment',$this->getRecords('rct_interview_synthesis.delete@recruitment',null,'db'),'db',true);
					$this->deleteRecords('rct_interview.delete@recruitment',$this->getRecords('rct_interview.delete@recruitment',null,'db'),'db',true);
					<card_lib:addlog/>
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=edit&nxs=&oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"")));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>