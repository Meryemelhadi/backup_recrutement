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

class Workflow_Task_add_interview extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
	}

	function run($workflow, $user)
	{
		if((isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""))
		{
			$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
			//Get vacancies associate to candidat
			$vacancies = new PersistentCollection('rct_candidate_vacancy.candidate_vacancies@recruitment','db',array('candidate_oid', $_REQUEST["candidate_oid"]));
			if($vacancies->isOk() && $vacancies->count() > 0){
				$data = $vacancies->array;
				$this->setProperty("vacancy",$data[0]->vacancy_oid->object);
			}
		}

		$this->setProperty('show_config' , true);
		if($GLOBALS['_NX_user']->checkPerm('?-rhmanager'))
			$this->setProperty('show_config' , false);
		
		
		
        if(isset($_REQUEST["t"]) && $_REQUEST["t"] == "minimal" ){
            $mode = "&pagemode=minimal&src=newcvt";
        }
		$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
		
		//Source la nouvelle cvthèque => retour en frame
		$src = "";
		$fram = "";
		if(isset($_REQUEST["src"]) && $_REQUEST["src"] == "newcvt"){
			$this->setProperty("src" , "newcvt");
			$src = '&src=newcvt';
			$fram = "/fram";
		}	
		
		 $this->setProperty('previous_operation.url',$fram.'/recruitment/candidates/directory.php?nxo=edit&amp;nxs=&amp;oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"").$mode.$src);
		$this->setProperty('previous_operation_ajax.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"").'&mode=ajax');
		
		
		if(isset($_REQUEST["from_vac"]) && $_REQUEST["from_vac"] == 1){
			$record = $this->getRecord('rct_interview.add_to_vacancy@recruitment','page.record','empty',false,null,null);
		}else if (isset($_REQUEST["from"]) &&  $_REQUEST["from"] == 'home'){
			if(isset($_REQUEST['vacancy_oid']) && $_REQUEST['vacancy_oid'] != '' ){
				$this->setProperty("vacancy_oid",$_REQUEST["vacancy_oid"]);
				$record = $this->getRecord('rct_interview.add_to_vacancy@recruitment','page.record','empty',false,null,null);
				$this->setProperty('previous_operation.url',PORTAL_URL_PREFIX.'/recruitment3/#/homepage/job/'.$_REQUEST['vacancy_oid'].'/');
			}else{
				$record = $this->getRecord('rct_interview.add_to_candidate_vacancy@recruitment','page.record','empty',false,null,null);
				$this->setProperty('previous_operation.url',PORTAL_URL_PREFIX.'/recruitment3/');
			}
			$this->setProperty("from_home" , 1);
			
		}else if(isset($_REQUEST['type']) && $_REQUEST['type'] == "new"){
			$record = $this->getRecord('rct_interview.add_to_candidate_vacancy@recruitment','page.record','empty',false,null,null);
			$this->setProperty('previous_operation.url',PORTAL_URL_PREFIX.'/recruitment/interview/directory.php');
			$this->setProperty("from_calendar" , 1);
		}else{
			$record = $this->getRecord('rct_interview.add_to_candidate@recruitment','page.record','empty',false,null,null);
			if(isset($_REQUEST["from"]) &&  $_REQUEST["from"] == 'cvtq'){
				$this->setProperty('previous_operation.url',PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo=list&'.$this->lien_cleaner('from'));
				$this->setProperty("from_cvtq" , 1);
			}
		}
		
		$this->setProperty("previous_op_label",$this->getString("back_to_candidate"));
		$this->setProperty('get_email_sample.url',$_SERVER["PHP_SELF"].'?nxo=get_email_sample&amp;nxs=');

		
		
		if(isset($_REQUEST["from_vac"]) && $_REQUEST["from_vac"] == 1){
			$this->setProperty("from_vac" , 1);
			$this->setProperty("previous_op_label",$this->getString("back_to_vacancy"));
			$this->setProperty('previous_operation.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$_REQUEST['vacancy_oid'].'/directory.php?nxo=calendar_vacancy&nxs=&oid='.$_REQUEST['vacancy_oid'].'&from_vac=1&vacancy_oid='.$_REQUEST['vacancy_oid'].'&mode=page');
		}

		$this->setProperty("user_oid",$GLOBALS["_NX_user"]->getProperty("oid",""));
		
		$this->setProperty('preview_cv.url',$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cv&amp;candidate_oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
		
		$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
		
		$this->getRecord('rct_candidate.manage_cv_etat','candidate.record','db',false,null,null);

		$this->getRecords('rct_interview.by_user_day_now','interviews.records','db',false,null,null);
		
		$this->setProperty('submit.url',PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=add_interview_process&amp;nxs='.$mode.'&candidate_oid='.$_REQUEST["candidate_oid"].$src."&from=".$_REQUEST["from"]."&type=".$_REQUEST['type']."&".$this->lien_cleaner());
		$this->setProperty('interviews.url', PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=list_by_interviewer&nxs=&mode=ajax');
		$this->setProperty('meeting_rooms.url',PORTAL_URL_PREFIX.'/recruitment/admin/meeting_rooms.php');
		$this->setProperty('email_samples.url',PORTAL_URL_PREFIX.'/recruitment/admin/manage_email_samples.php');
		$this->setProperty('attached_files.url',PORTAL_URL_PREFIX.'/recruitment/admin/email_docs.php');
		
		$this->runView('recruitment.candidates.components.interview_add',array(
			'fmethod' => 'toHTML',

			),null);
		
		return true;
	}
	
	function lien_cleaner ($param1=null)
	{
		$arg = explode('&', $_SERVER['QUERY_STRING']);
		$chaine_final = '';
		foreach( $arg as $value )
		{
			$arg2 = explode('=', $value);  
			if ($arg2[0]!= 'nxo' && $arg2[0]!= 'nxs' && $arg2[0]!= 'oid' && $arg2[0]!= 'candidate_oid' && $arg2[0]!= $param1) {$chaine_final .= $value.'&';}   
		}
		return $chaine_final ;
	}
}
?>