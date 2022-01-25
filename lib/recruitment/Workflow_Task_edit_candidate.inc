<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once('candidates/services/directory.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/denormalisation.inc');

class Workflow_Task_edit_candidate extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}
	
	function run($workflow,$user)
	{
		/** check if candidate exists **/
		$model = $workflow->model;
        $state = $workflow->getState();
        $dml = $model->getDS('record',$state);
        $candidate = new PersistentObject();
        $candidate->load($dml,'db');
        if(!$candidate->isOk()){
                header('Location:'.PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo=list&nxs='.preg_replace(array('%&amp;%','%[+]%'),array('&','%2B'),urldecode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""))));
                return true;
        }
		/** end **/

		$userOid = $user->oid->object;
		//$filterKey = (isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"");
		$filterKey =  $this->getFilterKey();

		$candidateOid = $oid = (isset($_REQUEST["coid"])?$_REQUEST["coid"]:'');
		if(!$candidateOid)
		{
			$candidateOid = $oid = (isset($_REQUEST['oid'])?$_REQUEST['oid']:'');

		}
		$_REQUEST['oid']=$_GET['oid']=$_GET['coid']=$_REQUEST['coid']=$candidateOid;
		
		
		/** Source d'appel : La nouvelle cvthèque => Traiter les liens et le mode d'affichage des pages dans le frame **/
		$this->setProperty('not_hide_back' , true);
		$this->setProperty('from_new_cvt' , false);
		$src = "&src=cvt";
		$fram = "";
		if(isset($_REQUEST["src"]) && $_REQUEST["src"] ===  'newcvt'){
			$this->setProperty('not_hide_back' , false);
			$this->setProperty('from_new_cvt' , true);
			$this->setProperty('src' , "newcvt");
			$src = "&src=newcvt";
			$fram = "/fram";
		}
		/** End **/
		
		// Mark CV as read
		$directory = new lib_recruitment_candidates_services_directory($this->ctxt);
		$directory->insertReadState($userOid,$oid);

		// Mark CV as read
		$this->putRecord($null=null,'rct_candidate.mark_as_read@recruitment','update','db','Object',null);

		// Load data
		$this->setProperty("candidate_oid",$oid);
		$this->getRecord('rct_candidate.edit@recruitment','page.record','db',false,null,null);
		
		$this->getRecords('rct_candidate_vacancy.candidate_vacancies@recruitment','candidate_vacancies.records','db',false,null,null);

        //Load vacancies
		$this->ctxt->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
        $this->ctxt->setProperty("candidate_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
        $vacanciesList=$this->getRecords('rct_candidate_vacancy.candidates_vacancies_list@recruitment','page.records','db',false,null,null);

		$logs = array();
        for (	$vacancy = $vacanciesList->getRecordIterator(); $vacancy->isValid(); $vacancy->next())
        {
            $v=&$vacancy->getCurrent();
            $this->setProperty('vacancy_id', $v->getProperty('oid','',false,'object',''));

            $candidatesList= $this->getRecords('rct_candidate_vacancy.vacancy_candidates@recruitment','','db',false,null,null);

            $candidatescount= (($cl=$candidatesList)!=null?$cl->count():0);
			
			$this->ctxt->setProperty("vacancy_oid",$v->getProperty('oid','',false,'object',''));
			$this->ctxt->setProperty("candidate_oid",$oid);
			$log =  $this->getRecord('recruitment.candidates.associated.log@recruitment','','db',false,null,null);
			if(($vacancy_field=&$v)!=null) {
				$vacancy_field->setField('candidates_count',$candidatescount);
			}
			array_push ( $logs , $log->candidate_log->html );
			
        }
        $this->setProperty('logs' , $logs);
        $this->setProperty('candidates_vacancies_list.records' , $vacanciesList);
		$this->getRecords('rct_candidate_etat.ds_list','candidate_etats_all.records','db',false,null,null);
		$this->setProperty('associate_to_etat_process.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=edit_state_process&amp;nxs=');
        
		
        $this->getRecords('rct_candidate_files.list','attached_files.records','db',false,null,null);
		$this->getRecords('rct_candidate_test_assoc.candidate_tests@recruitment','candidate_tests.records','db',false,null,null);
		$this->getRecords('rct_candidate_etat_assoc.candidate_etats@recruitment','candidate_etats.records','db',false,null,null);
		$this->getRecord('rct_candidate_test_assoc.add@recruitment','candidate_tests.record','empty',false,null,null);
		$this->getRecords('rct_interview.candidate_interviews_planified@recruitment','candidate_interviews.records','db',false,null,null);
		$this->getRecords('rct_interview.candidate_interviews_realised@recruitment','candidate_interviews_realised.records','db',false,null,null);
		$this->getRecords('rct_interview_synthesis.list_by_candidate@recruitment','candidate_evaluations.records','db',false,null,null);
		$this->getRecords('rct_candidate_action.by_candidate_oid@recruitment','candidate_log.records','db',false,null,null);
		$this->getRecord('rct_candidate_etat_assoc.add@recruitment','candidate_etats.record','empty',false,null,null);
		$this->getRecords('rct_candidate_comment.record','comments.records','db',false,null,null);

		// set buttons
		$this->setProperty('add_attached_files.url',$_SERVER["PHP_SELF"].'?nxo=add_attached_files&amp;nxs=&amp;candidate_oid='.$oid.$src);
		$this->setProperty('archive.url',PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo=archive_cv&amp;nxs=&amp;oid='.$oid.$src);
		$this->setProperty('eval.url',$fram.PORTAL_URL_PREFIX.'/recruitement2/interview_evaluation.php?nxo=edit_by_interview&operation=my_calendar'.$src);
		
		// link without oid
        $void= (isset($_REQUEST["from_void"])?$_REQUEST["from_void"]:"");
		$from_vac= (isset($_REQUEST["from_vac"])?$_REQUEST["from_vac"]:"");
		$from_vac_calendar= (isset($_REQUEST["from_vac_calendar"])?$_REQUEST["from_vac_calendar"]:"");
		$from_mes_candidats = (isset($_REQUEST["from_mes_candidats"])?$_REQUEST["from_mes_candidats"]:"");
		$from_eval = (isset($_REQUEST["from_eval"])?$_REQUEST["from_eval"]:"");
		$from_homepage = (isset($_REQUEST["src"]) && $_REQUEST["src"] == 'homepage');
		$calendar = (isset($_REQUEST["operation"])?$_REQUEST["operation"]:"");
        if($void == "" && $calendar == "" && $from_vac == "" && $from_vac_calendar == "" && $from_eval == "" && !$from_homepage ){
            $this->setProperty('previous_operation_link.url',PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo=list&amp;nxs='.$filterKey.'&amp;mode=page');
            $this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$candidateOid.'&candidate_oid='.$candidateOid.$src.'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
        }else if($void !="" && !$from_homepage){
            $this->setProperty('previous_operation_link.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$void.'/directory.php?nxo=candidates&mode=page&oid='.$void.'#candidate_'.$oid);
            $this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&from_void='.$void.'&amp;oid='.$candidateOid.'&candidate_oid='.$candidateOid.$src.'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
            $this->setProperty('from_vacancy' , true);
        }else if($from_vac !=""){
		    $this->setProperty('previous_operation_link.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$_REQUEST['vacancy_oid'].'/directory.php?nxo=calendar_vacancy&nxs=&oid='.$_REQUEST['vacancy_oid'].'&from_vac=1&mode=page');
            $this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&from_void='.$void.'&amp;oid='.$candidateOid.'&candidate_oid='.$candidateOid.$src.'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
			$this->setProperty('from_vacancy' , true);
		}else if($from_vac_calendar !=""){
		    $this->setProperty('previous_operation_link.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$_REQUEST['vacancy_oid'].'/directory.php?nxo=calendar_vacancy&nxs=&oid='.$_REQUEST['vacancy_oid'].'&from_vac=1&mode=page');
            $this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&from_void='.$void.'&amp;oid='.$candidateOid.'&candidate_oid='.$candidateOid.$src.'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
			$this->setProperty('from_vacancy_calendar' , true);
		}else if($from_mes_candidats !=""){
		    $this->setProperty('previous_operation_link.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$_REQUEST['vacancy_oid'].'/directory.php?nxo=calendar_vacancy&nxs=&oid='.$_REQUEST['vacancy_oid'].'&from_vac=1&mode=page');
            $this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&from_mes_candidats=1&amp;oid='.$candidateOid.'&candidate_oid='.$candidateOid.'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
			$this->setProperty('from_mes_candidats' , true);
		}else if($from_eval !=""){																			
		    $this->setProperty('previous_operation_link.url',PORTAL_URL_PREFIX.'/recruitement2/interview_evaluation.php?nxo=edit_by_interview&operation=my_calendar&oid='.$_REQUEST['interview_oid'].'&synthesis_oid='.$_REQUEST['synthesis_oid'].'&mode=page');
            $this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&from_eval=1&amp;oid='.$candidateOid.'&candidate_oid='.$candidateOid.'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
			$this->setProperty('from_eval' , true);
		}else if($from_homepage){

			if(isset($_REQUEST["void"]) && $_REQUEST["void"] !=  '')
				$this->ctxt->setProperty('previous_operation_link.url' , PORTAL_URL_PREFIX.'/recruitment3/#/homepage/job/'.$_REQUEST["void"].'/');
			else $this->ctxt->setProperty('previous_operation_link.url' , PORTAL_URL_PREFIX.'/recruitment3/');																											
		    $this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&src=homepage&amp;oid='.$candidateOid.'&candidate_oid='.$candidateOid.'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
			$this->setProperty('from_homepage' , true);
		}
		else{
			$this->setProperty('my_calendar' , true);
			$this->setProperty('previous_operation_link.url',PORTAL_URL_PREFIX.'/recruitment/interview/directory.php');
			$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&operation=my_calendar&amp;oid='.$candidateOid.'&candidate_oid='.$candidateOid.$src);
		}
		$this->setProperty('unlink_candidate.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=unlink_candidate&amp;nxs=&amp;filterKey='.urlencode($filterKey));
		$this->setProperty('associate_to_vacancy.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=associate_to_vacancy&nxs=&candidate_oid='.$oid);
		$this->setProperty('add_comment.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=add_comment&amp;nxs=&amp;oid='.$oid);
		$this->setProperty('delete_comment.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=delete_comment&amp;nxs=&amp;candidate_oid='.$candidateOid);
		$this->setProperty('download_cv.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=download&amp;nxs=&amp;type=cv&amp;candidate_oid='.$candidateOid);
		$this->setProperty('download_cl.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=download&amp;nxs=&amp;type=cl&amp;candidate_oid='.$candidateOid);
		$this->setProperty('preview_cv.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cv&amp;candidate_oid='.$candidateOid);
		//$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$candidateOid.'&candidate_oid='.$candidateOid);
		$this->setProperty('preview_cl.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cl&amp;candidate_oid='.$candidateOid);
		$this->setProperty('add_etat.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=add_etat&amp;nxs=&amp;candidate_oid='.$candidateOid);
		$this->setProperty('delete_etat.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=delete_etat&amp;nxs=');
		$this->setProperty('send_to_client.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=send_to_client&amp;nxs=&amp;candidate_oid='.$candidateOid.'&mode=ajax'.$src);
		
		$this->setProperty('add_interview.url',$fram.PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=add_interview&amp;nxs=&amp;candidate_oid='.$candidateOid.'&mode=page'.$src);
		
		$this->setProperty('add_test.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=add_test&amp;nxs=&amp;candidate_oid='.$candidateOid);
		$this->setProperty('attached_files.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=attached_files&amp;nxs=&amp;candidate_oid='.$candidateOid);
		$this->setProperty('delete_attached_file.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=delete_attached_file&amp;nxs=&amp;candidate_oid='.$candidateOid);
		$this->setProperty('edit_etat.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=edit_etat&amp;nxs=&amp;candidate_oid='.$candidateOid);
		$this->setProperty('delete_comment.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=delete_comment&amp;nxs=&amp;candidate_oid='.$candidateOid);
		$this->setProperty('delete_test.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=delete_test&amp;nxs=&amp;candidate_oid='.$candidateOid);
		$this->setProperty('edit_interview.url',$fram.PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=edit_interview&amp;nxs='.$src);
		$this->setProperty('email.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=get_email_body&oid=');

        $this->setProperty('send_to_ic.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=send_to_ic_from_candidate&nxs=&candidate_oid='.$candidateOid.'&vacancy_oid=');
        $this->setProperty('edit_integration_date.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=edit_integration_date&nxs=&candidate_oid='.$candidateOid.'&vacancy_oid=');
        $this->setProperty('edit_state.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=edit_state&nxs=&candidate_oid='.$candidateOid.'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")).'&vacancy_oid=');
        
		$this->setProperty('refused_proposal.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=handle_proposal_from_candidate&nxs=&status_value=11&candidate_oid='.$candidateOid.'&vacancy_oid=');
        $this->setProperty('accepted_proposal.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=handle_proposal_from_candidate&nxs=&status_value=10&candidate_oid='.$candidateOid.'&vacancy_oid=');
        $this->setProperty('accepted_for_job.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=change_candidate_status_from_candidate&nxs=&status_value=7&is_visible=0&candidate_oid='.$candidateOid.'&vacancy_oid=');
        $this->setProperty('cancel_accepted_for_job.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=change_candidate_status_from_candidate&nxs=&status_value=18&is_visible=0&candidate_oid='.$candidateOid.'&vacancy_oid=');
        $this->setProperty('refuse_candidate.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=change_candidate_status_from_candidate&nxs=&status_value=8&is_visible=0&candidate_oid='.$candidateOid.'&vacancy_oid=');
        $this->setProperty('unlink_candidate.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=unlink_candidate_from_candidate&nxs=&oid='.$candidateOid.'&candidate_oid='.$candidateOid.'&filterKey='.urlencode($filterKey).'&vacancy_oid=');
        $this->setProperty('unlink_from_all.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=unlink_from_all_from_candidate&nxs=&oid='.$candidateOid.'&candidate_oid='.$candidateOid.'&filterKey='.urlencode($filterKey).'&vacancy_oid=');
        $this->setProperty('candidate_record.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=associated_candidate_poste&mode=ajax&oid='.$candidateOid.'&candidate_oid='.$candidateOid.'&vacancy_oid=');
        $this->setProperty('reinit_status.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=change_candidate_status_from_candidate&nxs=&status_value=0&is_visible=0&candidate_oid='.$candidateOid.'&vacancy_oid=');
		

        $this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=edit_process&amp;filterKey='.urlencode($filterKey).$src.(isset($_REQUEST["vacancy_oid"])?'&vacancy_oid='.$_REQUEST["vacancy_oid"]:""));
		$this->setProperty('delete.url',PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo=delete&oid='.$candidateOid.$src.'&filterKey='.$filterKey);
		//print PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo=delete&oid='.$candidateOid.$src.'&filterKey='.urlencode($filterKey);
		$this->setProperty('update_cv.url',$_SERVER["PHP_SELF"].'?nxo=update_cv'.$src);


		/*$viewMode='ajax';
		if(in_array((isset($_GET["mode"])?$_GET["mode"]:""),array('page','ajax')))
		{
			$viewMode=(isset($_GET["mode"])?$_GET["mode"]:"");
		}
			if($viewMode == 'page')
			{
				$this->runView('/recruitment/candidates/directory__edit',array(
					'fmethod' => 'toHTML',

					),null);
			}
			else {
				$this->runView('/recruitment/candidates/directory__edit_ajax',array(
					'fmethod' => 'toHTML',

					),null);
			}*/

        // get form def if any

        $this->runView('/recruitment/candidates/edit_bs',array(
            'fmethod' => 'toHTML',

        ),null);
			return true;
	}
	
	function getFilterKey(){
		$get_parameters = array();
		if (isset($_SERVER['QUERY_STRING'])) {
  			$pairs = explode('&', $_SERVER['QUERY_STRING']);
  			foreach($pairs as $pair) {
    			$part = explode('=', $pair);
    			$get_parameters[$part[0]] = sizeof($part)>1 ? urldecode($part[1]) : "";
    		}
  		} 
  		return $get_parameters['filterKey'];
	}
}
?>