<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxApplication.inc');
class recruitment_candidates_directory_client_ extends NxApplication
{
	function recruitment_candidates_directory_client_($props,&$parentDesc,$aspect)
	{
		$this->NxApplication('recruitment.candidates.directory_client_',$props,$parentDesc,$aspect);
	}

	function run()
	{
		switch ($this->operation)
		{    // operation: preview_cv
		case 'preview_cv':
		switch($this->step)
		{
		
         // step preview_cv    
		 case 'preview_cv':
		 default:
			$this->operation='preview_cv';
			$this->step='preview_cv';
			$this->startOp();

			if ($this->runLogic('recruitment.candidates.directory_client_.preview_cv.preview_cv',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: candidate_details
		case 'candidate_details':
		switch($this->step)
		{
		
         // step candidate_details    
		 case 'candidate_details':
		 default:
			$this->operation='candidate_details';
			$this->step='candidate_details';
			$this->startOp();

			if ($this->runLogic('recruitment.candidates.directory_client_.candidate_details.candidate_details',
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

			if ($this->runLogic('recruitment.candidates.directory_client_.list.list',
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