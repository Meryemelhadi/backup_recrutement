<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxApplication.inc');
class recruitment_vacancies_admin_directory_ extends NxApplication
{
	function recruitment_vacancies_admin_directory_($props,&$parentDesc,$aspect)
	{
		$this->NxApplication('recruitment.vacancies.admin.directory_',$props,$parentDesc,$aspect);
	}

	function run()
	{
		switch ($this->operation)
		{    // operation: xls_export_default
		case 'xls_export_default':
		switch($this->step)
		{
		
         // step xls_export    
		 case 'xls_export':
		 default:
			$this->operation='xls_export_default';
			$this->step='xls_export';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.xls_export_default.xls_export',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: xls_export_lydec
		case 'xls_export_lydec':
		switch($this->step)
		{
		
         // step xls_plan_export    
		 case 'xls_plan_export':
		 default:
			$this->operation='xls_export_lydec';
			$this->step='xls_plan_export';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.xls_export_lydec.xls_plan_export',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: validate
		case 'validate':
		switch($this->step)
		{
		
         // step validate    
		 case 'validate':
		 default:
			$this->operation='validate';
			$this->step='validate';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.validate.validate',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.validate.process',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.add.add',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.add.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: announcement_add_intranet
		case 'announcement_add_intranet':
		switch($this->step)
		{
		
         // step announcement_add_intranet    
		 case 'announcement_add_intranet':
		 default:
			$this->operation='announcement_add_intranet';
			$this->step='announcement_add_intranet';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.announcement_add_intranet.announcement_add_intranet',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.announcement_add_intranet.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: announcement_add_internet
		case 'announcement_add_internet':
		switch($this->step)
		{
		
         // step announcement_add_internet    
		 case 'announcement_add_internet':
		 default:
			$this->operation='announcement_add_internet';
			$this->step='announcement_add_internet';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.announcement_add_internet.announcement_add_internet',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.announcement_add_internet.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: list_description
		case 'list_description':
		switch($this->step)
		{
		
         // step display    
		 case 'display':
		 default:
			$this->operation='list_description';
			$this->step='display';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.list_description.display',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: details_description
		case 'details_description':
		switch($this->step)
		{
		
         // step input    
		 case 'input':
		 default:
			$this->operation='details_description';
			$this->step='input';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.details_description.input',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit_ajax.input',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit_ajax.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: delete_description
		case 'delete_description':
		switch($this->step)
		{
		
         // step process    
		 case 'process':
		 default:
			$this->operation='delete_description';
			$this->step='process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.delete_description.process',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.new_ajax.input',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.new_ajax.process',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit.edit',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: delete_attached_file
		case 'delete_attached_file':
		switch($this->step)
		{
		
         // step process    
		 case 'process':
		 default:
			$this->operation='delete_attached_file';
			$this->step='process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.delete_attached_file.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: change_contrat_signing
		case 'change_contrat_signing':
		switch($this->step)
		{
		
         // step change_contrat_signing    
		 case 'change_contrat_signing':
		 default:
			$this->operation='change_contrat_signing';
			$this->step='change_contrat_signing';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.change_contrat_signing.change_contrat_signing',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.change_contrat_signing.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: change_hire_date
		case 'change_hire_date':
		switch($this->step)
		{
		
         // step change_hire_date    
		 case 'change_hire_date':
		 default:
			$this->operation='change_hire_date';
			$this->step='change_hire_date';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.change_hire_date.change_hire_date',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.change_hire_date.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: change_integration_note
		case 'change_integration_note':
		switch($this->step)
		{
		
         // step change_contrat_signing    
		 case 'change_contrat_signing':
		 default:
			$this->operation='change_integration_note';
			$this->step='change_contrat_signing';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.change_integration_note.change_contrat_signing',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.change_integration_note.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: change_integration_plan
		case 'change_integration_plan':
		switch($this->step)
		{
		
         // step change_integration_plan    
		 case 'change_integration_plan':
		 default:
			$this->operation='change_integration_plan';
			$this->step='change_integration_plan';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.change_integration_plan.change_integration_plan',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.change_integration_plan.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: requirements
		case 'requirements':
		switch($this->step)
		{
		
         // step requirements    
		 case 'requirements':
		 default:
			$this->operation='requirements';
			$this->step='requirements';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.requirements.requirements',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.requirements.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: calendar
		case 'calendar':
		switch($this->step)
		{
		
         // step calendar    
		 case 'calendar':
		 default:
			$this->operation='calendar';
			$this->step='calendar';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.calendar.calendar',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: interviews_list
		case 'interviews_list':
		switch($this->step)
		{
		
         // step interviews_list    
		 case 'interviews_list':
		 default:
			$this->operation='interviews_list';
			$this->step='interviews_list';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.interviews_list.interviews_list',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.add_interview.add_interview',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.add_interview_process.add_interview_process',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.delete_interview.delete_interview',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit_interview.edit_interview',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit_interview_process.edit_interview_process',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.interview_download.interview_download',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step interview_download_candidate    
		 case 'interview_download_candidate':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.interview_download.interview_download_candidate',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step interview_download_interviewers    
		 case 'interview_download_interviewers':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.interview_download.interview_download_interviewers',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: validate_interview
		case 'validate_interview':
		switch($this->step)
		{
		
         // step validate_interview    
		 case 'validate_interview':
		 default:
			$this->operation='validate_interview';
			$this->step='validate_interview';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.validate_interview.validate_interview',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step validate_interview_process    
		 case 'validate_interview_process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.validate_interview.validate_interview_process',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.add_interview_synthesis.add_interview_synthesis',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.add_interview_synthesis_process.add_interview_synthesis_process',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit_interview_synthesis.edit_interview_synthesis',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit_interview_synthesis_process.edit_interview_synthesis_process',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.view_interview_synthesis.view_interview_synthesis',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: pdf_interview_synthesis
		case 'pdf_interview_synthesis':
		switch($this->step)
		{
		
         // step pdf_interview_synthesis    
		 case 'pdf_interview_synthesis':
		 default:
			$this->operation='pdf_interview_synthesis';
			$this->step='pdf_interview_synthesis';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.pdf_interview_synthesis.pdf_interview_synthesis',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: pdf_export
		case 'pdf_export':
		switch($this->step)
		{
		
         // step pdf_export    
		 case 'pdf_export':
		 default:
			$this->operation='pdf_export';
			$this->step='pdf_export';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.pdf_export.pdf_export',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: candidates
		case 'candidates':
		switch($this->step)
		{
		
         // step candidates    
		 case 'candidates':
		 default:
			$this->operation='candidates';
			$this->step='candidates';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.candidates.candidates',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step candidate_record    
		 case 'candidate_record':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.candidates.candidate_record',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: associated_candidate
		case 'associated_candidate':
		switch($this->step)
		{
		
         // step associated_candidate    
		 case 'associated_candidate':
		 default:
			$this->operation='associated_candidate';
			$this->step='associated_candidate';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.associated_candidate.associated_candidate',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step associated_candidate_record    
		 case 'associated_candidate_record':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.associated_candidate.associated_candidate_record',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: shorts_list
		case 'shorts_list':
		switch($this->step)
		{
		
         // step shorts_list    
		 case 'shorts_list':
		 default:
			$this->operation='shorts_list';
			$this->step='shorts_list';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.shorts_list.shorts_list',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step short_list_record    
		 case 'short_list_record':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.shorts_list.short_list_record',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: rated_candidate
		case 'rated_candidate':
		switch($this->step)
		{
		
         // step rated_candidate    
		 case 'rated_candidate':
		 default:
			$this->operation='rated_candidate';
			$this->step='rated_candidate';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.rated_candidate.rated_candidate',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step rated_record    
		 case 'rated_record':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.rated_candidate.rated_record',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: refused_candidate
		case 'refused_candidate':
		switch($this->step)
		{
		
         // step refused_candidate    
		 case 'refused_candidate':
		 default:
			$this->operation='refused_candidate';
			$this->step='refused_candidate';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.refused_candidate.refused_candidate',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step refused_record    
		 case 'refused_record':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.refused_candidate.refused_record',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: candidates_search_results
		case 'candidates_search_results':
		switch($this->step)
		{
		
         // step candidates_search_results    
		 case 'candidates_search_results':
		 default:
			$this->operation='candidates_search_results';
			$this->step='candidates_search_results';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.candidates_search_results.candidates_search_results',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: candidate_add_interview
		case 'candidate_add_interview':
		switch($this->step)
		{
		
         // step candidate_add_interview    
		 case 'candidate_add_interview':
		 default:
			$this->operation='candidate_add_interview';
			$this->step='candidate_add_interview';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.candidate_add_interview.candidate_add_interview',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: candidate_add_interview_process
		case 'candidate_add_interview_process':
		switch($this->step)
		{
		
         // step candidate_add_interview_process    
		 case 'candidate_add_interview_process':
		 default:
			$this->operation='candidate_add_interview_process';
			$this->step='candidate_add_interview_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.candidate_add_interview_process.candidate_add_interview_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: rate_candidate
		case 'rate_candidate':
		switch($this->step)
		{
		
         // step rate_candidate    
		 case 'rate_candidate':
		 default:
			$this->operation='rate_candidate';
			$this->step='rate_candidate';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.rate_candidate.rate_candidate',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: change_candidate_status
		case 'change_candidate_status':
		switch($this->step)
		{
		
         // step change_candidate_status    
		 case 'change_candidate_status':
		 default:
			$this->operation='change_candidate_status';
			$this->step='change_candidate_status';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.change_candidate_status.change_candidate_status',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: handle_proposal
		case 'handle_proposal':
		switch($this->step)
		{
		
         // step handle_proposal    
		 case 'handle_proposal':
		 default:
			$this->operation='handle_proposal';
			$this->step='handle_proposal';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.handle_proposal.handle_proposal',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: handle_proposal_from_candidate
		case 'handle_proposal_from_candidate':
		switch($this->step)
		{
		
         // step handle_proposal    
		 case 'handle_proposal':
		 default:
			$this->operation='handle_proposal_from_candidate';
			$this->step='handle_proposal';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.handle_proposal_from_candidate.handle_proposal',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: handle_proposal_process
		case 'handle_proposal_process':
		switch($this->step)
		{
		
         // step handle_proposal_process    
		 case 'handle_proposal_process':
		 default:
			$this->operation='handle_proposal_process';
			$this->step='handle_proposal_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.handle_proposal_process.handle_proposal_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: unlink_candidate
		case 'unlink_candidate':
		switch($this->step)
		{
		
         // step unlink_candidat    
		 case 'unlink_candidat':
		 default:
			$this->operation='unlink_candidate';
			$this->step='unlink_candidat';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.unlink_candidate.unlink_candidat',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: send_to_ic
		case 'send_to_ic':
		switch($this->step)
		{
		
         // step send_to_ic    
		 case 'send_to_ic':
		 default:
			$this->operation='send_to_ic';
			$this->step='send_to_ic';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.send_to_ic.send_to_ic',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: send_to_ic_from_candidate
		case 'send_to_ic_from_candidate':
		switch($this->step)
		{
		
         // step send_to_ic_from_candidate    
		 case 'send_to_ic_from_candidate':
		 default:
			$this->operation='send_to_ic_from_candidate';
			$this->step='send_to_ic_from_candidate';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.send_to_ic_from_candidate.send_to_ic_from_candidate',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: send_to_ic_process
		case 'send_to_ic_process':
		switch($this->step)
		{
		
         // step send_to_ic_process    
		 case 'send_to_ic_process':
		 default:
			$this->operation='send_to_ic_process';
			$this->step='send_to_ic_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.send_to_ic_process.send_to_ic_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: send_sl_to_ic
		case 'send_sl_to_ic':
		switch($this->step)
		{
		
         // step send_sl_to_ic    
		 case 'send_sl_to_ic':
		 default:
			$this->operation='send_sl_to_ic';
			$this->step='send_sl_to_ic';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.send_sl_to_ic.send_sl_to_ic',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: send_sl_to_ic_process
		case 'send_sl_to_ic_process':
		switch($this->step)
		{
		
         // step send_sl_to_ic_process    
		 case 'send_sl_to_ic_process':
		 default:
			$this->operation='send_sl_to_ic_process';
			$this->step='send_sl_to_ic_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.send_sl_to_ic_process.send_sl_to_ic_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add_short_list
		case 'add_short_list':
		switch($this->step)
		{
		
         // step add_short_list    
		 case 'add_short_list':
		 default:
			$this->operation='add_short_list';
			$this->step='add_short_list';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.add_short_list.add_short_list',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step add_short_list_process    
		 case 'add_short_list_process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.add_short_list.add_short_list_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: edit_short_list
		case 'edit_short_list':
		switch($this->step)
		{
		
         // step edit_short_list    
		 case 'edit_short_list':
		 default:
			$this->operation='edit_short_list';
			$this->step='edit_short_list';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit_short_list.edit_short_list',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step edit_short_list_process    
		 case 'edit_short_list_process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit_short_list.edit_short_list_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add_to_short_list
		case 'add_to_short_list':
		switch($this->step)
		{
		
         // step add_to_short_list    
		 case 'add_to_short_list':
		 default:
			$this->operation='add_to_short_list';
			$this->step='add_to_short_list';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.add_to_short_list.add_to_short_list',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step add_to_short_list_process    
		 case 'add_to_short_list_process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.add_to_short_list.add_to_short_list_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: move_to_short_list
		case 'move_to_short_list':
		switch($this->step)
		{
		
         // step move_to_short_list    
		 case 'move_to_short_list':
		 default:
			$this->operation='move_to_short_list';
			$this->step='move_to_short_list';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.move_to_short_list.move_to_short_list',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step move_to_short_list_process    
		 case 'move_to_short_list_process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.move_to_short_list.move_to_short_list_process',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.preview.preview',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.candidate_details.candidate_details',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: unlink_candidate_sl
		case 'unlink_candidate_sl':
		switch($this->step)
		{
		
         // step unlink_candidate_sl    
		 case 'unlink_candidate_sl':
		 default:
			$this->operation='unlink_candidate_sl';
			$this->step='unlink_candidate_sl';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.unlink_candidate_sl.unlink_candidate_sl',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: delete_sl
		case 'delete_sl':
		switch($this->step)
		{
		
         // step delete_sl    
		 case 'delete_sl':
		 default:
			$this->operation='delete_sl';
			$this->step='delete_sl';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.delete_sl.delete_sl',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add_email
		case 'add_email':
		switch($this->step)
		{
		
         // step add_email    
		 case 'add_email':
		 default:
			$this->operation='add_email';
			$this->step='add_email';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.add_email.add_email',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add_email_process
		case 'add_email_process':
		switch($this->step)
		{
		
         // step add_email_process    
		 case 'add_email_process':
		 default:
			$this->operation='add_email_process';
			$this->step='add_email_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.add_email_process.add_email_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: view_mail
		case 'view_mail':
		switch($this->step)
		{
		
         // step view_mail    
		 case 'view_mail':
		 default:
			$this->operation='view_mail';
			$this->step='view_mail';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.view_mail.view_mail',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: email_download
		case 'email_download':
		switch($this->step)
		{
		
         // step email_download    
		 case 'email_download':
		 default:
			$this->operation='email_download';
			$this->step='email_download';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.email_download.email_download',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: get_email_sample
		case 'get_email_sample':
		switch($this->step)
		{
		
         // step get_email_sample    
		 case 'get_email_sample':
		 default:
			$this->operation='get_email_sample';
			$this->step='get_email_sample';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.get_email_sample.get_email_sample',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: get_description_sample
		case 'get_description_sample':
		switch($this->step)
		{
		
         // step get_description_sample    
		 case 'get_description_sample':
		 default:
			$this->operation='get_description_sample';
			$this->step='get_description_sample';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.get_description_sample.get_description_sample',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: recruitment_providers
		case 'recruitment_providers':
		switch($this->step)
		{
		
         // step recruitment_providers    
		 case 'recruitment_providers':
		 default:
			$this->operation='recruitment_providers';
			$this->step='recruitment_providers';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.recruitment_providers.recruitment_providers',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: request_provider
		case 'request_provider':
		switch($this->step)
		{
		
         // step request_provider    
		 case 'request_provider':
		 default:
			$this->operation='request_provider';
			$this->step='request_provider';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.request_provider.request_provider',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: request_provider_process
		case 'request_provider_process':
		switch($this->step)
		{
		
         // step request_provider_process    
		 case 'request_provider_process':
		 default:
			$this->operation='request_provider_process';
			$this->step='request_provider_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.request_provider_process.request_provider_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: view_provider
		case 'view_provider':
		switch($this->step)
		{
		
         // step view_provider    
		 case 'view_provider':
		 default:
			$this->operation='view_provider';
			$this->step='view_provider';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.view_provider.view_provider',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: provider_download
		case 'provider_download':
		switch($this->step)
		{
		
         // step provider_download    
		 case 'provider_download':
		 default:
			$this->operation='provider_download';
			$this->step='provider_download';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.provider_download.provider_download',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: feedback
		case 'feedback':
		switch($this->step)
		{
		
         // step feedback    
		 case 'feedback':
		 default:
			$this->operation='feedback';
			$this->step='feedback';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.feedback.feedback',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: schedule_instant_feedback
		case 'schedule_instant_feedback':
		switch($this->step)
		{
		
         // step schedule_instant_feedback    
		 case 'schedule_instant_feedback':
		 default:
			$this->operation='schedule_instant_feedback';
			$this->step='schedule_instant_feedback';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.schedule_instant_feedback.schedule_instant_feedback',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: schedule_instant_feedback_process
		case 'schedule_instant_feedback_process':
		switch($this->step)
		{
		
         // step schedule_instant_feedback_process    
		 case 'schedule_instant_feedback_process':
		 default:
			$this->operation='schedule_instant_feedback_process';
			$this->step='schedule_instant_feedback_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.schedule_instant_feedback_process.schedule_instant_feedback_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: schedule_delayed_feedback
		case 'schedule_delayed_feedback':
		switch($this->step)
		{
		
         // step schedule_delayed_feedback    
		 case 'schedule_delayed_feedback':
		 default:
			$this->operation='schedule_delayed_feedback';
			$this->step='schedule_delayed_feedback';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.schedule_delayed_feedback.schedule_delayed_feedback',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: schedule_delayed_feedback_process
		case 'schedule_delayed_feedback_process':
		switch($this->step)
		{
		
         // step schedule_delayed_feedback_process    
		 case 'schedule_delayed_feedback_process':
		 default:
			$this->operation='schedule_delayed_feedback_process';
			$this->step='schedule_delayed_feedback_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.schedule_delayed_feedback_process.schedule_delayed_feedback_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: delete_instant_feedback
		case 'delete_instant_feedback':
		switch($this->step)
		{
		
         // step delete_instant_feedback    
		 case 'delete_instant_feedback':
		 default:
			$this->operation='delete_instant_feedback';
			$this->step='delete_instant_feedback';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.delete_instant_feedback.delete_instant_feedback',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: delete_delayed_feedback
		case 'delete_delayed_feedback':
		switch($this->step)
		{
		
         // step delete_delayed_feedback    
		 case 'delete_delayed_feedback':
		 default:
			$this->operation='delete_delayed_feedback';
			$this->step='delete_delayed_feedback';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.delete_delayed_feedback.delete_delayed_feedback',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: complete_instant_feedback
		case 'complete_instant_feedback':
		switch($this->step)
		{
		
         // step complete_instant_feedback    
		 case 'complete_instant_feedback':
		 default:
			$this->operation='complete_instant_feedback';
			$this->step='complete_instant_feedback';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.complete_instant_feedback.complete_instant_feedback',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: complete_instant_feedback_process
		case 'complete_instant_feedback_process':
		switch($this->step)
		{
		
         // step complete_instant_feedback_process    
		 case 'complete_instant_feedback_process':
		 default:
			$this->operation='complete_instant_feedback_process';
			$this->step='complete_instant_feedback_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.complete_instant_feedback_process.complete_instant_feedback_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: view_delayed_feedback
		case 'view_delayed_feedback':
		switch($this->step)
		{
		
         // step view_delayed_feedback    
		 case 'view_delayed_feedback':
		 default:
			$this->operation='view_delayed_feedback';
			$this->step='view_delayed_feedback';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.view_delayed_feedback.view_delayed_feedback',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: warning
		case 'warning':
		switch($this->step)
		{
		
         // step warning    
		 case 'warning':
		 default:
			$this->operation='warning';
			$this->step='warning';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.warning.warning',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: history
		case 'history':
		switch($this->step)
		{
		
         // step history    
		 case 'history':
		 default:
			$this->operation='history';
			$this->step='history';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.history.history',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: announcement
		case 'announcement':
		switch($this->step)
		{
		
         // step announcement    
		 case 'announcement':
		 default:
			$this->operation='announcement';
			$this->step='announcement';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.announcement.announcement',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: schedule_warning
		case 'schedule_warning':
		switch($this->step)
		{
		
         // step schedule_warning    
		 case 'schedule_warning':
		 default:
			$this->operation='schedule_warning';
			$this->step='schedule_warning';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.schedule_warning.schedule_warning',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: schedule_warning_process
		case 'schedule_warning_process':
		switch($this->step)
		{
		
         // step schedule_warning_process    
		 case 'schedule_warning_process':
		 default:
			$this->operation='schedule_warning_process';
			$this->step='schedule_warning_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.schedule_warning_process.schedule_warning_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: edit_warning
		case 'edit_warning':
		switch($this->step)
		{
		
         // step edit_warning    
		 case 'edit_warning':
		 default:
			$this->operation='edit_warning';
			$this->step='edit_warning';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit_warning.edit_warning',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: edit_warning_process
		case 'edit_warning_process':
		switch($this->step)
		{
		
         // step edit_warning_process    
		 case 'edit_warning_process':
		 default:
			$this->operation='edit_warning_process';
			$this->step='edit_warning_process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit_warning_process.edit_warning_process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: delete_warning
		case 'delete_warning':
		switch($this->step)
		{
		
         // step delete_warning    
		 case 'delete_warning':
		 default:
			$this->operation='delete_warning';
			$this->step='delete_warning';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.delete_warning.delete_warning',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add_candidate_comment
		case 'add_candidate_comment':
		switch($this->step)
		{
		
         // step add_candidate_comment    
		 case 'add_candidate_comment':
		 default:
			$this->operation='add_candidate_comment';
			$this->step='add_candidate_comment';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.add_candidate_comment.add_candidate_comment',
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
		switch($this->step)
		{
		
         // step my_calendar    
		 case 'my_calendar':
		 default:
			$this->operation='my_calendar';
			$this->step='my_calendar';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.my_calendar.my_calendar',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: ics_export
		case 'ics_export':
		switch($this->step)
		{
		
         // step ics_export    
		 case 'ics_export':
		 default:
			$this->operation='ics_export';
			$this->step='ics_export';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.ics_export.ics_export',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.my_interviews_list.interviews_list',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: add_comment
		case 'add_comment':
		switch($this->step)
		{
		
         // step add_comment    
		 case 'add_comment':
		 default:
			$this->operation='add_comment';
			$this->step='add_comment';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.add_comment.add_comment',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.download.download',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.delete.delete',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.archive.archive',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: list_prest
		case 'list_prest':
		switch($this->step)
		{
		
         // step display    
		 case 'display':
		 default:
			$this->operation='list_prest';
			$this->step='display';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.list_prest.display',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: details_prest
		case 'details_prest':
		switch($this->step)
		{
		
         // step input    
		 case 'input':
		 default:
			$this->operation='details_prest';
			$this->step='input';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.details_prest.input',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: edit_ajax_prest
		case 'edit_ajax_prest':
		switch($this->step)
		{
		
         // step input    
		 case 'input':
		 default:
			$this->operation='edit_ajax_prest';
			$this->step='input';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit_ajax_prest.input',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.edit_ajax_prest.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: delete_prest
		case 'delete_prest':
		switch($this->step)
		{
		
         // step process    
		 case 'process':
		 default:
			$this->operation='delete_prest';
			$this->step='process';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.delete_prest.process',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
				$this->finish();
			}
            break;

		}
        break;
    // operation: new_ajax_prest
		case 'new_ajax_prest':
		switch($this->step)
		{
		
         // step input    
		 case 'input':
		 default:
			$this->operation='new_ajax_prest';
			$this->step='input';
			$this->startOp();

			if ($this->runLogic('recruitment.vacancies.admin.directory_.new_ajax_prest.input',
				array(
					'cancel.url'=>$this->getProperty('back.url'),)))
			{
			}
            break;

         // step process    
		 case 'process':
			if ($this->runLogic('recruitment.vacancies.admin.directory_.new_ajax_prest.process',
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

			if ($this->runLogic('recruitment.vacancies.admin.directory_.list.list',
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