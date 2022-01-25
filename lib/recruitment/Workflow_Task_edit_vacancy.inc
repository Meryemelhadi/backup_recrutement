<?php

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_edit_vacancy extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run($workflow,$user)
	{
		//Multiposting config
		if(defined("NX_RECRUITMENT_MULTIPOSTING") && NX_RECRUITMENT_MULTIPOSTING ==  true){
			$this->setProperty("use_multiposting",NX_RECRUITMENT_MULTIPOSTING);
		}else{
			$this->setProperty("use_multiposting",false);
		}
		//Check if user is drh
		$this->setProperty('is_drh' , $GLOBALS['_NX_user']->checkPerm('?-drh'));
		$filterKey = (isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"");
		
		$vacancy_oid = (isset($_REQUEST["void"])?$_REQUEST["void"]:"");
        
		$vacancy_object = new PersistentObject('rct_vacancy.edit_'.$this->getProperty("recruitement_profile","default"),'db');
		$vacancy = $vacancy_object->record;
		//Afficher recruteur en mode no-edit true
		$vacancy->rh_oid->object = $vacancy->getProperty('manager_oid','',false,'html','');
		
		$this->setProperty("vacancy_id",$vacancy->getProperty('oid','',false,'object',''));
		$permission_control= $this->getRecords('rct_vacancy_total_control.permission','','db',false,null,null);
		$verif_permission_control=(($_nx_records26=$permission_control)!=null?$_nx_records26->count():0);
		$permission_readonly= $this->getRecords('rct_vacancy_readonly.permission','','db',false,null,null);
		$verif_permission_readonly=(($_nx_records28=$permission_readonly)!=null?$_nx_records28->count():0);

		$permission_manager=$this->getRecords('rct_vacancy.manager_permission','','db',false,null,null);
		$verif_permission_manager=(($_nx_records27=$permission_manager)!=null?$_nx_records27->count():0);
		
		$creator= $vacancy->getProperty('creator','',false,'object','');
		$interimObject = new PersistentObject('user.get_interim','db', array('user_oid'=>$creator));
		$interim = $interimObject->interim->object;
			
		if( $verif_permission_control == '1' ||
			$creator == $GLOBALS["_NX_user"]->getProperty("oid","") ||
			$interim == $GLOBALS["_NX_user"]->getProperty("oid","") ||
			$verif_permission_manager=='1' || $GLOBALS['_NX_user']->checkPerm('?-drh'))
		{
			$this->setProperty("mode_readonly",false);
		}
		elseif($verif_permission_readonly == '1')
		{
			$this->setProperty("mode_readonly",true);
			$vacancy=$this->getRecord('rct_vacancy.edit_readonly_'.$this->getProperty("recruitement_profile","default"),'page.record','db',false,null,null);
	
		}else{
			header('Location:'.PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=list&amp;nxs='.$filterKey.'&amp;mode=page');
            return true;
		}
		
		
		$ufilterKey = urlencode($filterKey);
		$vacancy_param = '&amp;oid='.$vacancy_oid.'&amp;filterKey='.$ufilterKey.'&from_vac=1&vacancy_oid='.$vacancy_oid;
		$pself = PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$vacancy_oid.'/directory.php';

		//From home
		if(isset($_REQUEST['from']) && $_REQUEST['from'] == 'home'){
			$this->setProperty('from_home',true);
			$this->setProperty("back_to_home.url" , PORTAL_URL_PREFIX.'/recruitment3/#/homepage/job/'.$_REQUEST['oid'].'/');
		}
		$this->setProperty("current_operation",'edit');
		if($this->getProperty("current_operation","") != 'recruitment_providers')
		{
			$this->setProperty("vacancy_oid",$vacancy_oid);
		}
		
	

		//$this->getRecord('rct_vacancy.get_title','vacancy_title_record','db',false,null,null);
		$this->setProperty('add_candidate_comment.url',$pself.'?nxo=add_candidate_comment&amp;nxs=&amp;vacancy_oid='.$vacancy_oid);
		$this->setProperty('back_list.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=list&amp;nxs='.$filterKey.'&amp;mode=page');

		$this->addProperties(array(
			'list.url'=> $pself.'?nxo=list&amp;nxs='.$filterKey.'&amp;mode=ajax',
			'edit.url'=> $pself.'?nxo=edit&amp;nxs=&amp;oid='.$vacancy_oid.'&amp;filterKey='.$ufilterKey,
			'delete.url'=>$pself.'?nxo=delete&amp;nxs=&amp;oid='.$vacancy_oid.'&amp;filterKey='.$ufilterKey,
			'requirements.url'=> $pself.'?nxo=requirements&amp;nxs='.$vacancy_param,
			'calendar.url'=> PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=my_calendar&mode=page&vacancy_oid='.$vacancy_oid.'&from_vacancy=1',
			'shorts_list.url'=> $pself.'?nxo=shorts_list&amp;nxs='.$vacancy_param,
			'associated_candidate.url'=> $pself.'?nxo=associated_candidate&amp;nxs='.$vacancy_param,
			'rated.url'=> $pself.'?nxo=rated_candidate&amp;nxs='.$vacancy_param,
			'candidates.url'=> PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo=list&nxs=&vacancy='.$vacancy_oid,
			'refused_candidate.url'=> $pself.'?nxo=refused_candidate&amp;nxs='.$vacancy_param,
			'recruitment_providers.url'=> $pself.'?nxo=list_prest&amp;nxs='.$vacancy_param,
			'synthesis.url'=> $pself.'?nxo=synthesis&amp;nxs='.$vacancy_param,
			'feedback.url'=> $pself.'?nxo=feedback&amp;nxs='.$vacancy_param,
			'warning.url'=> $pself.'?nxo=warning&amp;nxs='.$vacancy_param,
			'history.url'=> $pself.'?nxo=history&amp;nxs='.$vacancy_param,
			'announcement.url'=> $pself.'?nxo=announcement&amp;nxs='.$vacancy_param,
			'archive.url'=>$pself.'?nxo=archive&amp;nxs='.$vacancy_param,
			'vacancy_oid'=>$vacancy_oid,
			'vacancy_id' => $vacancy_oid
	 
		));

		

		// load records
		$this->getRecords('rct_candidate_vacancy.accepted_proposals','accepted_proposals.records','db',false,null,null);
		$this->getRecords('rct_vacancy_action.by_vacancy_oid','candidate_log.records','db',false,null,null);
		$this->getRecords('rct_candidate_vacancy.selected_candidates','selected_candidates.records','db',false,null,null);
		$this->getRecords('rct_instant_feedback.completed_count','instant_feedback_count.records','db',false,null,null);
		$this->getRecords('rct_delayed_feedback.completed_count','delayed_feedback_count.records','db',false,null,null);
		$this->setProperty("vacancy_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
		$this->getRecords('rct_vacancy_attached_file.by_vacancy','attached_files.records','db',false,null,null);
		$this->getRecords('rct_vacancy_comment.ds_list','comments.records','db',false,null,null);

		$backList = preg_replace('%void-[0-9]+/%','',$pself);

		$this->addProperties(array(
			'list.url' => $backList.'?nxo=list&amp;nxs='.$filterKey,
			'add_comment.url' => $pself.'?nxo=add_comment&amp;nxs=&amp;oid='.$vacancy_oid,
			'edit.url' => $pself.'?nxo=edit&amp;nxs=&amp;oid='.$vacancy_oid,
			'submit.url' => $pself.'?nxo=edit_process',
			'download.url' => $pself.'?nxo=download&amp;nxs=',
			'delete_attached_file.url'=> PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=delete_attached_file&amp;nxs=&amp;vacancy_oid='.$vacancy_oid,
			'add_attached_files.url' => PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=add_attached_files_vacancy&amp;nxs=&amp;vacancy_oid='.$vacancy_oid.$filterKey,
		
			'change_contrat_signing.url' => $pself.'?nxo=change_contrat_signing&amp;nxs=&amp;oid='.$vacancy_oid,
			'change_hire_date.url' => $pself.'?nxo=change_hire_date&amp;nxs=&amp;oid='.$vacancy_oid,
			'change_integration_plan.url' => $pself.'?nxo=change_integration_plan&amp;nxs=&amp;oid='.$vacancy_oid,
			'change_integration_note.url' => $pself.'?nxo=change_integration_note&amp;nxs=&amp;oid='.$vacancy_oid,
			'applicant.url' => PORTAL_URL_PREFIX.'/recruitment3/home.php#/cvtheque/job/'.$vacancy_oid.'/',
			//'calendar.url' => PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=list&vacancy_oid='.$vacancy_oid,
			'candidate_add.url' => PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo=add&nxs=&from=vacancy&vacancy_oid='.$vacancy_oid
			
		));
		
		
		$this->getRecords('rct_vacancy_history.by_vacancy_resume','vacancy_history.records','db',false,null,null);
		

		$viewMode='ajax';
		if(in_array((isset($_GET["mode"])?$_GET["mode"]:""),array('page','ajax')))
		{
			$viewMode=(isset($_GET["mode"])?$_GET["mode"]:"");
		}

		
		
		//titre de la fiche poste
		
		$title = $vacancy_object->name->html.($vacancy_object->code->object != '' ?' (N° '.$vacancy_object->code->html.')':"");
		$step ='';
		
		/*if($vacancy_object->current_step->object != 0 || $vacancy_object->progress_level->object != 0){
			$step = $vacancy_object->current_step->object !=0 ? $vacancy_object->current_step->label.': '.$vacancy_object->current_step->html.',' : '';
			$step.= $vacancy_object->progress_level->object !=0 ? $vacancy_object->progress_level->label.': '.$vacancy_object->progress_level->html.',' : '';
		}*/
		$step = $vacancy_object->current_step->label.': '.$vacancy_object->current_step->html ;
		//$step.= $vacancy_object->progress_level->label.': '.$vacancy_object->progress_level->html;
		$this->setProperty('title' , addslashes ($title));
		$this->setProperty('step' , addslashes ($step));
		$offer= $this->getRecord('posting.by_vacancy@recruitmentmp','multiposting.record','db',false,null,null);

		if($offer != null) {
			//Calculer nombre de click
			$this->setProperty('offer_oid' , $offer->oid->object);
			$jobboardList= $this->ctxt->getRecords('posting.provider_list_vacancy@recruitmentmp','','db',false,null,null);
			$nbrClics = 0;
			$countJobboard= 0;
			for (	$_nx_iterRec69 = $jobboardList->getRecordIterator();
					 $_nx_iterRec69->isValid();
					 $_nx_iterRec69->next())
			{
				$countJobboard++;
				$jobboard=&$_nx_iterRec69->getCurrent();
				$nbrClics+= $jobboard->clicks->value;
			}

			$offer->setField('nbr_clics',$nbrClics);
			$offer->setField('nbr_jobboard',$countJobboard);

		
			$this->setProperty("multiposting_url",PORTAL_URL_PREFIX.'/recruitmentmp/posting.php?nxo=edit&from_void=1&oid='.$offer->oid->object);
		}else{
			$this->setProperty("multiposting_url",false);
			$this->setProperty("multiposting_url",PORTAL_URL_PREFIX.'/recruitmentmp/posting.php?nxo=add&from_void=1&vacancy='.$vacancy_oid);
		}
		 
        $this->runView('/recruitment/vacancies/edit_bs',array(
            'fmethod' => 'toHTML' , 'page.record' => $vacancy

        ),null);


		return true;
	}
	
}
?>