<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');
include_once(NX_LIB.'ds/email/NxMail_MIME.inc');
include_once(GENERIS_PACKAGES.'recruitment/lib/email/NxRecruitment_Email.inc');

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_edit_interview extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
	}

	function run($workflow, $user)
	{
		$rhmanager = ($GLOBALS['_NX_user']->checkPerm('?-rhmanager'));
		$this->setProperty('show_config' , true);
		if($rhmanager) $this->setProperty('show_config' , false);
        
		$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
		$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:$_REQUEST["oid"]));
		$this->setProperty("interview_oid",$interview_oid=(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:$_REQUEST["oid"]));

		
		/** Source d'appel : La nouvelle cvthèque => Traiter les liens et le mode d'affichage des pages dans le frame **/
		$src = "";
		$fram = "";
		if(isset($_REQUEST["src"]) && $_REQUEST["src"] ===  'newcvt'){
			$src = "&src=newcvt";
			$fram = "/fram";
		}
		/** End **/
		
		$this->setProperty("operation",$operation=(isset($_REQUEST["operation"])?$_REQUEST["operation"]:""));
		$fvcancy="";
		$fcalendar="";
		if(!$rhmanager) {
			$interview_record = $this->getRecord('rct_interview.edit_to_candidate@recruitment','page.record','db',false,null,null);
			//Redirection vers la liste des entretiens si l'interview n'existe pas
			if(!$interview_record->oid->object){
				header('Location:'.PORTAL_URL_PREFIX.'/recruitment/interview/directory.php');
			}
			
			$this->setProperty("date_interview" , $interview_record->date->html);
			$candidate_oid=isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:$interview_record->candidate_oid->object;
			$this->setProperty('back_to_calendar.url',PORTAL_URL_PREFIX.'/recruitment/interview/directory.php');
			
			if(isset($_REQUEST['from_vac']) && $_REQUEST[from_vac] == 1){
				$interview_record = $this->getRecord('rct_interview.edit_to_candidate_vacancy@recruitment','page.record','db',false,null,null);
				$this->setProperty('back_to_calendar.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$_REQUEST['vacancy_oid'].'/directory.php?nxo=calendar_vacancy&nxs=&oid='.$_REQUEST['vacancy_oid'].'&from_vac=1&mode=page');
				$this->setProperty('from_vac', true);
				$fvacancy= '&vacancy_oid='.$_REQUEST['vacancy_oid'].'&from_vac=1';
				$fcalendar= '&vacancy_oid='.$_REQUEST['vacancy_oid'].'&from_vac_calendar=1';
			}else{
				$interview_record = $this->getRecord('rct_interview.edit_to_candidate@recruitment','page.record','db',false,null,null);
			}
			$this->setProperty('candidate.url',$fram.PORTAL_URL_PREFIX.'/recruitment/candidates/coid-'.$candidate_oid.'/directory.php?nxo=edit&oid='.$candidate_oid.'&mode=page'.$fcalendar.'&candidate_oid='.$candidate_oid.$src);
		}else{
			$interview_record = $this->getRecord('rct_interview.edit_to_candidate_manager@recruitment','page.record','db',false,null,null);
			//Redirection vers la liste des entretiens si l'interview n'existe pas
			if(!$interview_record->oid->object){
				header('Location:'.PORTAL_URL_PREFIX.'/recruitment/interview/directory.php');
			}
			$candidate_oid=isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:$interview_record->candidate_oid->object;
			$this->setProperty('back_to_calendar.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/manager/directory.php?nxo=my_calendar');
			$this->setProperty('isManager',true);	$this->setProperty('candidate.url',PORTAL_URL_PREFIX.'/recruitment/manager_candidates/coid-'.$candidate_oid.'/index.php?nxo=edit&oid='.$candidate_oid.'&mode=page');
			$this->setProperty("date_interview" , $interview_record->date->html);
			$candidate_oid=isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:$interview_record->candidate_oid->object;
			$this->setProperty('back_to_calendar.url',PORTAL_URL_PREFIX.'/recruitment/interview/directory.php');
			
			$interview_record = $this->getRecord('rct_interview.edit_to_candidate@recruitment','page.record','db',false,null,null);
			
			$this->setProperty('candidate.url',$fram.PORTAL_URL_PREFIX.'/recruitment/candidates/coid-'.$candidate_oid.'/directory.php?nxo=edit&oid='.$candidate_oid.'&mode=page'.$fcalendar.'&candidate_oid='.$candidate_oid.$src);
		}

		$this->getRecords('rct_interview_synthesis.by_interview@recruitment','interview_synthesis.records','db',false,null,null);
		$this->getRecords('rct_interview_attached_file_candidate.by_interview@recruitment','attached_files_candidate.records','db',false,null,null);
		$this->getRecords('rct_interview_attached_file_interviewers.by_interview@recruitment','attached_files_interviewers.records','db',false,null,null);
		
		

		$this->setProperty('get_email_sample.url',$_SERVER["PHP_SELF"].'?nxo=get_email_sample&amp;nxs=');
		$this->setProperty('download_candidate.url',$_SERVER["PHP_SELF"].'?nxo=interview_download&amp;nxs=interview_download_candidate');
		$this->setProperty('download_interviewers.url',$_SERVER["PHP_SELF"].'?nxo=interview_download&amp;nxs=interview_download_interviewers');
		
		if($operation =='my_calendar'){
			if(!$rhmanager) {
				if(isset($_REQUEST['from_vac']) && $_REQUEST[from_vac] == 1){
					$this->setProperty('previous_operation.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$_REQUEST['vacancy_oid'].'/directory.php?nxo=calendar_vacancy&nxs=&oid='.$_REQUEST['vacancy_oid'].'&from_vac=1&mode=page');
				}else{
					$this->setProperty('previous_operation.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory_2.php?nxo=my_calendar');
				}
			}else{
				$this->setProperty('previous_operation.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/manager/directory.php?nxo=my_calendar');
			}
		}else{
			if(!$rhmanager) {
				$this->setProperty('previous_operation.url',PORTAL_URL_PREFIX.'/recruitment/candidates/coid-'.$candidate_oid.'/directory.php?nxo=edit&amp;nxs=&amp;oid='.($candidate_oid).'&candidate_oid='.$candidate_oid);
			}else{
				$this->setProperty('previous_operation.url',PORTAL_URL_PREFIX.'/recruitment/manager_candidates/coid-'.$candidate_oid.'/index.php?nxo=edit&amp;nxs=&amp;oid='.($candidate_oid).'&candidate_oid='.$candidate_oid);
			}
		}
		
		if(isset($_REQUEST['from_vac']) && $_REQUEST[from_vac] == 1){
			$this->setProperty('eval_add.url',$fram.PORTAL_URL_PREFIX.'/recruitement2/interview_evaluation.php?nxo=edit_by_interview&operation=my_calendar&oid='.$interview_oid.'&from_vac_calendar=1&interview_oid='.$interview_oid.'&vacancy_oid='.$this->getProperty("vacancy_oid","").$src);
			$this->setProperty('delete_interview.url',$_SERVER["PHP_SELF"].'?nxo=delete_interview&amp;nxs=&amp;candidate_oid='. ($candidate_oid) .'&amp;interview_oid='.$interview_oid.'&operation='.$operation.'&from_vac=1&vacancy_oid='.$this->getProperty("vacancy_oid",""));
		}else{
			$this->setProperty('eval_add.url',$fram.PORTAL_URL_PREFIX.'/recruitement2/interview_evaluation.php?nxo=edit_by_interview&operation=my_calendar&oid='.$interview_oid."&src=".$src);
			$this->setProperty('delete_interview.url',$_SERVER["PHP_SELF"].'?nxo=delete_interview&amp;nxs=&amp;candidate_oid='. ($candidate_oid) .'&amp;interview_oid='.$interview_oid.'&operation='.$operation."&src=".$src);
		}
		
		$this->setProperty('back_to_home.url',PORTAL_URL_PREFIX.'/recruitment3/');
	
		$this->setProperty('cancel_interview.url',$_SERVER["PHP_SELF"].'?nxo=cancel_interview&amp;nxs=&amp;candidate_oid='.($candidate_oid).'&amp;interview_oid='.$interview_oid);
		$this->setProperty('add_interview_synthesis.url',$_SERVER["PHP_SELF"].'?nxo=add_interview_synthesis&amp;nxs=&amp;candidate_oid='.($candidate_oid).'&amp;interview_oid='.$interview_oid);
		$this->setProperty('edit_interview_synthesis.url',$_SERVER["PHP_SELF"].'?nxo=edit_interview_synthesis&amp;nxs=&amp;candidate_oid='.($candidate_oid).'&amp;interview_oid='.$interview_oid);
		$this->setProperty('pdf_export.url',$_SERVER["PHP_SELF"].'?nxo=pdf_export&amp;nxs=&amp;candidate_oid='.($candidate_oid).'&amp;interview_oid='.$interview_oid);
		$this->setProperty('view_interview_synthesis.url',$_SERVER["PHP_SELF"].'?nxo=view_interview_synthesis&amp;nxs=&amp;candidate_oid='.($candidate_oid).'&amp;interview_oid='.$interview_oid);
		
		$this->setProperty('export_pdf.url',PORTAL_URL_PREFIX.'/recruitement2/interview_evaluation.php?nxo=export_pdf&interview_oid='.$interview_oid.'&name='.urlencode(str_replace(' ', '_', $interview_record->candidate_oid->string)));
		$this->setProperty('print_evaluation.url',PORTAL_URL_PREFIX.'/recruitement2/interview_evaluation.php?nxo=print&media=db&oid='.$interview_oid);
		$this->setProperty('meeting_rooms.url',PORTAL_URL_PREFIX.'/recruitment/admin/meeting_rooms.php');
		$this->setProperty('email_samples.url',PORTAL_URL_PREFIX.'/recruitment/admin/manage_email_samples.php');
		$this->setProperty('attached_files.url',PORTAL_URL_PREFIX.'/recruitment/admin/email_docs.php');
		
		$this->setProperty("user_oid",$GLOBALS["_NX_user"]->getProperty("oid",""));
		$this->setProperty('preview_cv.url',$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cv&amp;candidate_oid='.($candidate_oid));
		$this->setProperty("candidate_oid",($candidate_oid));
		if(!$rhmanager) {
			$this->getRecord('rct_candidate.manage_cv_etat@recruitment','candidate.record','db',false,null,null);
		}else{
			$this->getRecord('rct_candidate.manage_cv_etat_no_edit@recruitment','candidate.record','db',false,null,null);
		}
		$this->getRecords('rct_interview.by_interviewer_day@recruitment','interviews.records','db',false,null,null);
		$this->getRecords('rct_candidate_comment.ds_list@recruitment','comments.records','db',false,null,null);
		$this->getRecord('rct_interview_synthesis.view_by_interview@recruitment','eval.record','db',false,null,null);
		$this->setProperty('check_eval' , $this->checkEvaluation());
		
		$this->setProperty('interviews.url', PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=list_by_interviewer&nxs=&interview_oid='.$interview_oid.'&candidate_oid='.$_REQUEST["candidate_oid"].'&mode=ajax');

		//from homepage
		$operation = "";
		if(isset($_REQUEST['operation']) && $_REQUEST['operation']=='homepage'){
			$operation ="&operation=homepage";
		}
		if(isset($_REQUEST['from_vac']) && $_REQUEST['from_vac']==1){
			$operation .= "&from_vac=1";
		}
		$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=edit_interview_process&mode=ajax&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&coid='.$candidate_oid.'&candidate_oid='.$candidate_oid.$operation.$src);
		
		
		$this->runView('recruitment.candidates.components.interview_edit',array(
			'fmethod' => 'toHTML',

			),null);
		
		return true;
	}
	/**** Check if evaluation exists ****/
	function checkEvaluation(){
		// ========= LOAD evaluation data ========== 
		$evaluation = null;
	
		// load interview
		$dml = $this->getParam('edit_by_interview','rct_interview_synthesis.view_by_interview@recruitment');
		$evaluation = new PersistentObject();
		$evaluation->load($dml,'db');
		if($evaluation->isOk()){
			$this->setProperty('synthesis_oid',$evaluation->oid);
			return $evaluation->oid;
		}
		return false;
	}
}
?>