<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxApplication.inc');
class recruitment_dashboards_integrations_synthesis_ extends NxApplication
{
	function recruitment_dashboards_integrations_synthesis_($props,&$parentDesc,$aspect)
	{
		$this->NxApplication('recruitment.dashboards.integrations_synthesis_',$props,$parentDesc,$aspect);
	}

	function run()
	{
		switch ($this->operation)
		{    // operation: statistics
		case 'statistics':
		switch($this->step)
		{
		
         // step statistics    
		 case 'statistics':
		 default:
			$this->operation='statistics';
			$this->step='statistics';
			$this->startOp();

			if ($this->runLogic('recruitment.dashboards.integrations_synthesis_.statistics.statistics',
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

			if ($this->runLogic('recruitment.dashboards.integrations_synthesis_.xls_export.xls_export',
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

			if ($this->runLogic('recruitment.dashboards.integrations_synthesis_.list.display',
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