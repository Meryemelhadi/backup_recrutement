<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_cron__testmail_testmailprocess extends NxPage
{
	function recruitment_vacancies_cron__testmail_testmailprocess($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$record=
						$this->getRecord('sendtestmail','page.record','post',false,null,null);
					(($__o=$this->getHandler('lib.recruitment.vacancies.services.message','')) ? $__o->testEmail($record) : null);
					$this->setProperty("page.record",$record);
					$this->setProperty('back.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=testmail');
					$this->runView('/recruitment/vacancies/cron__resultform',array(
						'fmethod' => 'toForm',

						),null);
		return true;
	}
}
?>