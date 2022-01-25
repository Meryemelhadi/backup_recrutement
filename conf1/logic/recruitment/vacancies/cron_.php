<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxApplication.inc');
class recruitment_vacancies_cron_ extends NxApplication
{
	function recruitment_vacancies_cron_($props,&$parentDesc,$aspect)
	{
		$this->NxApplication('recruitment.vacancies.cron_',$props,$parentDesc,$aspect);
	}

	function run()
	{
		switch ($this->operation)
		{    // operation: testmail
		case 'testmail':
		switch($this->step)
		{
		
         // step testmail    
		 case 'testmail':
		 default:
			$this->operation='testmail';
			$this->step='testmail';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.cron_.testmail.testmail',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step testmailprocess    
		 case 'testmailprocess':
			if ($this->runLogic('recruitment.vacancies.cron_.testmail.testmailprocess',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: main
		case 'main':
	default:
		$this->operation='main';

		switch($this->step)
		{
		
         // step main    
		 case 'main':
		 default:
			$this->operation='main';
			$this->step='main';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.cron_.main.main',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;

		}		
		$this->saveState();
		return true;
	}
}
?>