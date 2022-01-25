<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxApplication.inc');
class recruitment_annuaire_directory_ extends NxApplication
{
	function recruitment_annuaire_directory_($props,&$parentDesc,$aspect)
	{
		$this->NxApplication('recruitment.annuaire.directory_',$props,$parentDesc,$aspect);
	}

	function run()
	{
		switch ($this->operation)
		{    // operation: view
		case 'view':
		switch($this->step)
		{
		
         // step view    
		 case 'view':
		 default:
			$this->operation='view';
			$this->step='view';
			$this->startOp();

			if ($this->runLogic('recruitment.annuaire.directory_.view.view',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: edit
		case 'edit':
		switch($this->step)
		{
		
         // step edit    
		 case 'edit':
		 default:
			$this->operation='edit';
			$this->step='edit';
			$this->startOp();

			if ($this->runLogic('recruitment.annuaire.directory_.edit.edit',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step edit_process    
		 case 'edit_process':
			if ($this->runLogic('recruitment.annuaire.directory_.edit.edit_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add
		case 'add':
		switch($this->step)
		{
		
         // step add    
		 case 'add':
		 default:
			$this->operation='add';
			$this->step='add';
			$this->startOp();

			if ($this->runLogic('recruitment.annuaire.directory_.add.add',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step add_process    
		 case 'add_process':
			if ($this->runLogic('recruitment.annuaire.directory_.add.add_process',
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
		
         // step delete    
		 case 'delete':
		 default:
			$this->operation='delete';
			$this->step='delete';
			$this->startOp();

			if ($this->runLogic('recruitment.annuaire.directory_.delete.delete',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: xls_export
		case 'xls_export':
		switch($this->step)
		{
		
         // step xls_export    
		 case 'xls_export':
		 default:
			$this->operation='xls_export';
			$this->step='xls_export';
			$this->startOp();

			if ($this->runLogic('recruitment.annuaire.directory_.xls_export.xls_export',
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
		
         // step list    
		 case 'list':
		 default:
			$this->operation='list';
			$this->step='list';
			$this->startOp();

			if ($this->runLogic('recruitment.annuaire.directory_.list.list',
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