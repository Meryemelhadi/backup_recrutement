<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxApplication.inc');
class recruitment_admin_manage_schools_ extends NxApplication
{
	function recruitment_admin_manage_schools_($props,&$parentDesc,$aspect)
	{
		$this->NxApplication('recruitment.admin.manage_schools_',$props,$parentDesc,$aspect);
	}

	function run()
	{
		switch ($this->operation)
		{    // operation: details
		case 'details':
		switch($this->step)
		{
		
         // step input    
		 case 'input':
		 default:
			$this->operation='details';
			$this->step='input';
			$this->startOp();

			if ($this->runLogic('recruitment.admin.manage_schools_.details.input',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: edit_ajax
		case 'edit_ajax':
		switch($this->step)
		{
		
         // step input    
		 case 'input':
		 default:
			$this->operation='edit_ajax';
			$this->step='input';
			$this->startOp();

			if ($this->runLogic('recruitment.admin.manage_schools_.edit_ajax.input',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.admin.manage_schools_.edit_ajax.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: delete
		case 'delete':
		switch($this->step)
		{
		
         // step process    
		 case 'process':
		 default:
			$this->operation='delete';
			$this->step='process';
			$this->startOp();

			if ($this->runLogic('recruitment.admin.manage_schools_.delete.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: new_ajax
		case 'new_ajax':
		switch($this->step)
		{
		
         // step input    
		 case 'input':
		 default:
			$this->operation='new_ajax';
			$this->step='input';
			$this->startOp();

			if ($this->runLogic('recruitment.admin.manage_schools_.new_ajax.input',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.admin.manage_schools_.new_ajax.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: list
		case 'list':
	default:
		$this->operation='list';

		switch($this->step)
		{
		
         // step display    
		 case 'display':
		 default:
			$this->operation='list';
			$this->step='display';
			$this->startOp();

			if ($this->runLogic('recruitment.admin.manage_schools_.list.display',
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