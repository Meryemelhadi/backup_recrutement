<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxApplication.inc');
class recruitment_vacancies_client_directory_ extends NxApplication
{
	function recruitment_vacancies_client_directory_($props,&$parentDesc,$aspect)
	{
		$this->NxApplication('recruitment.vacancies.client.directory_',$props,$parentDesc,$aspect);
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

			if ($this->runLogic('recruitment.vacancies.client.directory_.statistics.statistics',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add_test
		case 'add_test':
		switch($this->step)
		{
		
         // step add_test    
		 case 'add_test':
		 default:
			$this->operation='add_test';
			$this->step='add_test';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.add_test.add_test',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add_etat
		case 'add_etat':
		switch($this->step)
		{
		
         // step add_etat    
		 case 'add_etat':
		 default:
			$this->operation='add_etat';
			$this->step='add_etat';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.add_etat.add_etat',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: delete_etat
		case 'delete_etat':
		switch($this->step)
		{
		
         // step process    
		 case 'process':
		 default:
			$this->operation='delete_etat';
			$this->step='process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.delete_etat.process',
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

			if ($this->runLogic('recruitment.vacancies.client.directory_.add.add',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.client.directory_.add.process',
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

			if ($this->runLogic('recruitment.vacancies.client.directory_.xls_export.xls_export',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: delete_test
		case 'delete_test':
		switch($this->step)
		{
		
         // step process    
		 case 'process':
		 default:
			$this->operation='delete_test';
			$this->step='process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.delete_test.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add_etat
		case 'add_etat':
		switch($this->step)
		{
		
         // step add_etat    
		 case 'add_etat':
		 default:
			$this->operation='add_etat';
			$this->step='add_etat';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.add_etat.add_etat',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: send_to_client
		case 'send_to_client':
		switch($this->step)
		{
		
         // step display    
		 case 'display':
		 default:
			$this->operation='send_to_client';
			$this->step='display';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.send_to_client.display',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.client.directory_.send_to_client.process',
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

			if ($this->runLogic('recruitment.vacancies.client.directory_.edit.edit',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.client.directory_.edit.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: edit_request
		case 'edit_request':
		switch($this->step)
		{
		
         // step edit_request    
		 case 'edit_request':
		 default:
			$this->operation='edit_request';
			$this->step='edit_request';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.edit_request.edit_request',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.client.directory_.edit_request.process',
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

			if ($this->runLogic('recruitment.vacancies.client.directory_.preview.preview',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: download
		case 'download':
		switch($this->step)
		{
		
         // step download    
		 case 'download':
		 default:
			$this->operation='download';
			$this->step='download';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.download.download',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: associate_to_vacancy
		case 'associate_to_vacancy':
		switch($this->step)
		{
		
         // step associate_to_vacancy    
		 case 'associate_to_vacancy':
		 default:
			$this->operation='associate_to_vacancy';
			$this->step='associate_to_vacancy';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.associate_to_vacancy.associate_to_vacancy',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add_interview
		case 'add_interview':
		switch($this->step)
		{
		
         // step add_interview    
		 case 'add_interview':
		 default:
			$this->operation='add_interview';
			$this->step='add_interview';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.add_interview.add_interview',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add_interview_process
		case 'add_interview_process':
		switch($this->step)
		{
		
         // step add_interview_process    
		 case 'add_interview_process':
		 default:
			$this->operation='add_interview_process';
			$this->step='add_interview_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.add_interview_process.add_interview_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: delete_interview
		case 'delete_interview':
		switch($this->step)
		{
		
         // step delete_interview    
		 case 'delete_interview':
		 default:
			$this->operation='delete_interview';
			$this->step='delete_interview';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.delete_interview.delete_interview',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: edit_interview
		case 'edit_interview':
		switch($this->step)
		{
		
         // step edit_interview    
		 case 'edit_interview':
		 default:
			$this->operation='edit_interview';
			$this->step='edit_interview';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.edit_interview.edit_interview',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: edit_interview_process
		case 'edit_interview_process':
		switch($this->step)
		{
		
         // step edit_interview_process    
		 case 'edit_interview_process':
		 default:
			$this->operation='edit_interview_process';
			$this->step='edit_interview_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.edit_interview_process.edit_interview_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: interview_download
		case 'interview_download':
		switch($this->step)
		{
		
         // step interview_download    
		 case 'interview_download':
		 default:
			$this->operation='interview_download';
			$this->step='interview_download';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.interview_download.interview_download',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step interview_download_candidate    
		 case 'interview_download_candidate':
			if ($this->runLogic('recruitment.vacancies.client.directory_.interview_download.interview_download_candidate',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step interview_download_interviewers    
		 case 'interview_download_interviewers':
			if ($this->runLogic('recruitment.vacancies.client.directory_.interview_download.interview_download_interviewers',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add_interview_synthesis
		case 'add_interview_synthesis':
		switch($this->step)
		{
		
         // step add_interview_synthesis    
		 case 'add_interview_synthesis':
		 default:
			$this->operation='add_interview_synthesis';
			$this->step='add_interview_synthesis';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.add_interview_synthesis.add_interview_synthesis',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add_interview_synthesis_process
		case 'add_interview_synthesis_process':
		switch($this->step)
		{
		
         // step add_interview_synthesis_process    
		 case 'add_interview_synthesis_process':
		 default:
			$this->operation='add_interview_synthesis_process';
			$this->step='add_interview_synthesis_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.add_interview_synthesis_process.add_interview_synthesis_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: edit_interview_synthesis
		case 'edit_interview_synthesis':
		switch($this->step)
		{
		
         // step edit_interview_synthesis    
		 case 'edit_interview_synthesis':
		 default:
			$this->operation='edit_interview_synthesis';
			$this->step='edit_interview_synthesis';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.edit_interview_synthesis.edit_interview_synthesis',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: edit_interview_synthesis_process
		case 'edit_interview_synthesis_process':
		switch($this->step)
		{
		
         // step edit_interview_synthesis_process    
		 case 'edit_interview_synthesis_process':
		 default:
			$this->operation='edit_interview_synthesis_process';
			$this->step='edit_interview_synthesis_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.edit_interview_synthesis_process.edit_interview_synthesis_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: view_interview_synthesis
		case 'view_interview_synthesis':
		switch($this->step)
		{
		
         // step view_interview_synthesis    
		 case 'view_interview_synthesis':
		 default:
			$this->operation='view_interview_synthesis';
			$this->step='view_interview_synthesis';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.view_interview_synthesis.view_interview_synthesis',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: massive_associate_to_vacancy
		case 'massive_associate_to_vacancy':
		switch($this->step)
		{
		
         // step display    
		 case 'display':
		 default:
			$this->operation='massive_associate_to_vacancy';
			$this->step='display';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.massive_associate_to_vacancy.display',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.client.directory_.massive_associate_to_vacancy.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: category
		case 'category':
		switch($this->step)
		{
		
         // step process    
		 case 'process':
		 default:
			$this->operation='category';
			$this->step='process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.category.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: relevance
		case 'relevance':
		switch($this->step)
		{
		
         // step display    
		 case 'display':
		 default:
			$this->operation='relevance';
			$this->step='display';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.relevance.display',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.client.directory_.relevance.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: change_reading_state
		case 'change_reading_state':
		switch($this->step)
		{
		
         // step change_reading_state    
		 case 'change_reading_state':
		 default:
			$this->operation='change_reading_state';
			$this->step='change_reading_state';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.change_reading_state.change_reading_state',
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

			if ($this->runLogic('recruitment.vacancies.client.directory_.delete.delete',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: send_cvs_to_many_client
		case 'send_cvs_to_many_client':
		switch($this->step)
		{
		
         // step display    
		 case 'display':
		 default:
			$this->operation='send_cvs_to_many_client';
			$this->step='display';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.send_cvs_to_many_client.display',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.client.directory_.send_cvs_to_many_client.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: archive
		case 'archive':
		switch($this->step)
		{
		
         // step archive    
		 case 'archive':
		 default:
			$this->operation='archive';
			$this->step='archive';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.client.directory_.archive.archive',
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

			if ($this->runLogic('recruitment.vacancies.client.directory_.list.list',
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