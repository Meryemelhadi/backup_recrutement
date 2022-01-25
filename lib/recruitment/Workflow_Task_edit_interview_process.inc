<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

include_once(GENERIS_PACKAGES.'recruitment/lib/email/ManageEmails.inc');
require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_edit_interview_process extends NxPage
{

	var $interview;

	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $ctxt;
		$this->params = $params;

		$this->interview = new ManageEmails($ctxt);
	}

	function run($workflow, $user)
	{
		
		$this->setProperty("interview_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
		$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
		$candidate_oid=(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"");

		// reload from db to chck if date/time have changed
		$prevRecord = $this->getRecord('rct_interview.edit_to_candidate@recruitment',null,'db',false,null,null);
		
		// load modified record for interview
		$interviewRecord = $this->getRecord('rct_interview.edit_to_candidate@recruitment','page.record','post',false,null,null);

		//Video conference link
		if($interviewRecord->interview_type->object == 3 && ($interviewRecord->video_link->object == NULL || $interviewRecord->video_link->object != '')){
			$link = $this->generate_video_link($interviewRecord->oid->object , $interviewRecord->candidate_oid->object );
			$i_object = new PersistentObject('rct_interview.update_video_link','db',array('interview_oid'=>$interviewRecord->oid->object));
			if($i_object->isOk())
			{
				$i_object->video_link->object = $link;
				$i_object->store('rct_interview.update_video_link','update','db',array('interview_oid' => $interviewRecord->oid->object));
				$interviewRecord->video_link->object = $link;
				
			}
		}
		
		// check if time changed
		if( $prevRecord->date->toTime() != $interviewRecord->date->toTime() ||
			$prevRecord->time_start->toTime() != $interviewRecord->time_start->toTime() ||
			$prevRecord->time_end->toTime() != $interviewRecord->time_end->toTime())
			$timeUpdated=true;
		else
			$timeUpdated=false;

		// check if location changed
		if( $prevRecord->location->object != $interviewRecord->location->object)
			$locationUpdated=true;
		else
			$locationUpdated=false;

		if($timeUpdated || $locationUpdated)
		{
			// change ical sequence number
			$interviewRecord->ical_seq->db = ((int)$prevRecord->ical_seq->object + 1);
		}
		// save record (even if not modified)
		$this->putRecord(
			$interviewRecord,'rct_interview.edit@recruitment','update','db','Object',null);
		
		// upload files
		$oid=$this->getProperty('interview_oid','');
		
		$path='interviews';
		$handler_candidate='rct_interview_attached_file_candidate.add_record@recruitment';
		$handler_interviewers='rct_interview_attached_file_interviewers.add_record@recruitment';	
		
		$files = $this->interview->uploadInterviewFiles($oid,$handler_candidate,$handler_interviewers,$path);
		$this->addProperties($files);

		// remove files to delete for interviewers
		$handler='rct_interview_attached_file_interviewers.get_record@recruitment';		
		$this->interview->removeFilesToDelete($oid,$handler,$path);
			
		// remove files to delete for candidates
		$handler='rct_interview_attached_file_candidate.get_record@recruitment';		
		$this->interview->removeFilesToDelete($oid,$handler,$path);
		
		// update state of candidate (if needed)
		if($candidate_oid && isset($_REQUEST['etat_oid']) && $_REQUEST['etat_oid'])
		{
			$candidate_etat = new PersistentObject('rct_candidate.edit_etat','db',array('candidate_oid'=>$candidate_oid));
			if($candidate_etat->isOk() && ($candidate_etat->etat_oid->object != $_REQUEST['etat_oid']))
			{
				$candidate_etat->etat_oid->object = $_REQUEST['etat_oid'];
				$candidate_etat->store('rct_candidate.edit_etat','update','db',array('candidate_oid'=>$candidate_oid,'etat_oid'=>$_REQUEST['etat_oid']));
			}
		}

		$interviews_oid = array(array($oid, $candidate_oid));

		// send invite to recruiter
		// $this->interview->sendInterviewEmail($interviews_oid,$interviewRecord,$user,$files);

		
		$success_recruiter = $this->interview->sendInterviewEmailRecruiter($interviewRecord,$user,$files,$timeUpdated,$locationUpdated);
	
		$success_candidate = $this->interview->sendInterviewEmailCandidate($candidate_oid,$interviewRecord,$user,$files,$timeUpdated,$locationUpdated);
		if(!$success_candidate){
			$i = new PersistentObject('rct_interview.edit_candidate_email_not@recruitment','empty');
			$i->candidate_email_not->object = 0;
			$i->store('rct_interview.edit_candidate_email_not@recruitment','update','db',array('interview_oid' =>$interviewRecord->oid->object));
		}elseif($success_candidate && $interviewRecord->candidate_email_not->object == 1) {
			$i = new PersistentObject('rct_interview.edit_candidate_email_not@recruitment','empty');
			$i->candidate_email_not->object = 2;
			$i->store('rct_interview.edit_candidate_email_not@recruitment','update','db',array('interview_oid' =>$interviewRecord->oid->object));
		}
		
		if(!$success_recruiter){
			$i = new PersistentObject('rct_interview.edit_interviewer_email_not@recruitment','empty');
			$i->interviewer_email_not->object = 0;
			$i->store('rct_interview.edit_interviewer_email_not@recruitment','update','db',array('interview_oid' =>$interviewRecord->oid->object));
		}elseif($success_recruiter && $interviewRecord->interviewer_email_not->object == 1){
			$i = new PersistentObject('rct_interview.edit_interviewer_email_not@recruitment','empty');
			$i->interviewer_email_not->object = 2;
			$i->store('rct_interview.edit_interviewer_email_not@recruitment','update','db',array('interview_oid' =>$interviewRecord->oid->object));
		
		}
		/** Source d'appel : La nouvelle cvthèque => Traiter les liens et le mode d'affichage des pages dans le frame **/
		$src = "";
		$fram = "";
		if(isset($_REQUEST["src"]) && $_REQUEST["src"] ===  'newcvt'){
			$src = "&src=newcvt";
			$fram = "/fram";
		}
		/** End **/
		
		if(isset($_REQUEST['coid'])){
			if($GLOBALS['_NX_user']->checkPerm('?-rhmanager')) 
				$url = PORTAL_URL_PREFIX.$fram.'/recruitment/manager_candidates/coid-'.$_REQUEST["coid"].'/index.php?nxo=edit&mode=page&oid='.$_REQUEST["coid"].'&candidate_oid='.$_REQUEST["coid"].'&tab=recruitement_card'.$src;
			else $url = PORTAL_URL_PREFIX.$fram.'/recruitment/candidates/coid-'.$_REQUEST["coid"].'/directory.php?nxo=edit&nxs=&candidate_oid='.$_REQUEST["coid"].'&oid='.$_REQUEST["coid"].'&candidate_oid='.$_REQUEST["coid"].'&tab=recruitement_card'.$src;
			$this->setProperty('redirect_url.url',$url);
			
			$this->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);
		}else if(isset($_REQUEST['operation']) && $_REQUEST['operation'] == 'homepage'){
			$url = PORTAL_URL_PREFIX.'/recruitment3';
			$this->setProperty('redirect_url.url',$url);
			
			$this->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);
		}elseif(isset($_REQUEST[from_vac]) && $_REQUEST[from_vac] == 1){
			$url = PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$_REQUEST['vacancy_oid'].'/directory.php?nxo=calendar_vacancy&nxs=&oid='.$_REQUEST['vacancy_oid'].'&from_vac=1&mode=page';
			$this->setProperty('redirect_url.url',$url);
			$this->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);
		}else{
			$url = PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory_2.php?nxo=my_calendar';
			$this->setProperty('redirect_url.url',$url);
			
			$this->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);
		}

		return true;
	}
	
	// Generate video link 
	function generate_video_link($interview_oid ,  $candidate_oid){
		if($this->getProperty('recruitment.code_client'))
			$code_client = $this->getProperty('recruitment.code_client');
		else $code_client = 'interview';
		return 'https://appear.in/'.$code_client.'-'.$interview_oid.substr(md5(microtime()),rand(0,26),5).$candidate_oid;
	}
}
?>