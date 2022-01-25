<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxApplication.inc');
class recruitment_vacancies_manager_directory_ extends NxApplication
{
	function recruitment_vacancies_manager_directory_($props,&$parentDesc,$aspect)
	{
		$this->NxApplication('recruitment.vacancies.manager.directory_',$props,$parentDesc,$aspect);
	}

	function run()
	{
		switch ($this->operation)
		{    // operation: ics_export
		case 'ics_export':
		switch($this->step)
		{
		
         // step ics_export    
		 case 'ics_export':
		 default:
			$this->operation='ics_export';
			$this->step='ics_export';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.manager.directory_.ics_export.ics_export',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: my_interviews_list
		case 'my_interviews_list':
		switch($this->step)
		{
		
         // step interviews_list    
		 case 'interviews_list':
		 default:
			$this->operation='my_interviews_list';
			$this->step='interviews_list';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.manager.directory_.my_interviews_list.interviews_list',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: preview
		case 'preview':
		switch($this->step)
		{
		
         // step preview    
		 case 'preview':
		 default:
			$this->operation='preview';
			$this->step='preview';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.manager.directory_.preview.preview',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: my_calendar
		case 'my_calendar':
	default:
		$this->operation='my_calendar';

		switch($this->step)
		{
		
         // step my_calendar    
		 case 'my_calendar':
		 default:
			$this->operation='my_calendar';
			$this->step='my_calendar';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.manager.directory_.my_calendar.my_calendar',
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