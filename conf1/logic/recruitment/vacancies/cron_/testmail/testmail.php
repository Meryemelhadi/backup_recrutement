<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_cron__testmail_testmail extends NxPage
{
	function recruitment_vacancies_cron__testmail_testmail($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecord('sendtestmail','page.record','empty',false,null,null);
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=testmailprocess');
					$this->runView('/recruitment/vacancies/cron__viewform',array(
						'fmethod' => 'toForm',

						),null);
		return true;
	}
}
?>