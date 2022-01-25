<?php

class Workflow_Task_list_interviews extends Workflow_Task
{
    function setFilterKey($searchData)
    {
        $searchDataVar='searchData';
        $_searchKey_=(($_nx_rec2=${$searchDataVar})!=null?$_nx_rec2->getUrlKey(true):'');
        if((isset($_REQUEST["page"])?$_REQUEST["page"]:""))
        {
            $_searchKey_ = preg_replace("/page=[^&]+(&(amp;)?)?/",'',$_searchKey_);
            $_searchKey_=$_searchKey_.'&amp;page='.(isset($_REQUEST["page"])?$_REQUEST["page"]:"");
        }
        $this->ctxt->setProperty("filterKey",$filterKey = $_searchKey_);

        if(isset($_GET['nxs']))
            $_searchKey_ = 'nxs='.$_GET['nxs'].'&'.$_searchKey_;

        if(isset($_GET['nxo']))
            $_searchKey_ = 'nxo='.$_GET['nxo'].'&'.$_searchKey_;

        if(isset($_GET['wao']))
            $_searchKey_ = 'wao='.$_GET['wao'].'&'.$_searchKey_;
			
        $GLOBALS["NX_CURRENT_URL"] ='?'.$_searchKey_;

        return $filterKey;
    }

    function run($workflow, $user)
    {	
        $model = $workflow->model;
        $this->ctxt->setProperty('workflow',$workflow);
        $description = $model->description;
		//Permission DRH
		$drh = "";
		if($GLOBALS['_NX_user']->checkPerm('?-drh')) $drh = "-drh";

        // buttons
		$rhmanager = ($GLOBALS['_NX_user']->checkPerm('?-rhmanager'));
        $this->ctxt->setProperty('show_config' , true);
        if(!$rhmanager) {
			$this->ctxt->setProperty('edit.url',PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=edit_interview&operation=my_calendar&mode=page&oid=');
			$this->ctxt->setProperty('edit_candidate.url',PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo=edit&mode=page&operation=my_calendar&oid=');
		}else{
			$this->ctxt->setProperty('show_config' , false);
			$this->ctxt->setProperty('edit.url',PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=edit_interview&operation=my_calendar&mode=page&oid=');
			$this->ctxt->setProperty('edit_candidate.url',PORTAL_URL_PREFIX.'/recruitment/manager_candidates/index.php?nxo=edit&mode=page&operation=my_calendar&oid=');
		}
		
		
        $this->ctxt->setProperty('eval.url',PORTAL_URL_PREFIX.'/recruitement2/interview_evaluation.php?nxo=edit_by_interview&operation=my_calendar&oid=');

        // set toolbar buttons
        $props=$this->setButtons();


        // display list
        $view = $this->getParam('view','list');
        $view = $model->getDisplayView($view);
        $view_type = $this->getParam('view_type','HTML');

        if(($listOperations = $this->getParam('list_operations')) ||
        ($listOperations = $workflow->getListOperations()))

        $this->ctxt->setProperty('list_operations',$listOperations);
		$osearch = new PersistentObject('rct_interview.search'.$drh.'@recruitment','db');
		$data = $osearch->record;
		if(isset($_REQUEST['vacancy_oid']) && (array_key_exists($_REQUEST['vacancy_oid'] , $data->vacancy_oid->list) || $_REQUEST['vacancy_oid'] == -2)){
			$this->ctxt->setProperty('search_vacancy' , $_REQUEST['vacancy_oid']);
		}else{
			$_REQUEST['vacancy_oid'] = "";
		}
            
        $dsList = $this->ctxt->getRecords('handler:rct_interview.ds_calendar_list_realised','page.records','db',false,null,null);
        $dsListFutur = $this->ctxt->getRecords('handler:rct_interview.ds_calendar_list_futur','page.records','db',false,null,null);
		
		$synthesis_r = array();
		
		foreach($dsList->records as $key => $interview){
			$this->ctxt->setProperty('interview_oid', $interview['_oid']);
			//$interviewers = array_diff(explode("|" , $interview['_interview_by_oid']) , array("" , $GLOBALS['_NX_user']->getProperty("oid" ,"" , true))) ;
			$interviewers = array_filter(explode("|" , $interview['_interview_by_oid'])) ;
			
			$synthesis_r[$interview['_oid']] =  array();
			if(sizeOf($interviewers) > 0){
				foreach($interviewers as $i){
					$this->ctxt->setProperty('interview_by_oid', $i);
					$s =  new PersistentObject('rct_interview_synthesis.by_interview_interviewer' , 'db');
					if($s->record != null){
						array_push($synthesis_r[$interview['_oid']] ,  array($s->record->user_oid->html , $s->record->oid->object));
					}
				}
			};
		}
		
		$synthesis_f = array();
		
		foreach($dsListFutur->records as $key => $interview){
			$this->ctxt->setProperty('interview_oid', $interview['_oid']);
			//$interviewers = array_diff(explode("|" , $interview['_interview_by_oid']) , array("" , $GLOBALS['_NX_user']->getProperty("oid" ,"" , true))) ;
			$interviewers = explode("|" , $interview['_interview_by_oid']) ;
			$synthesis_f[$interview['_oid']] =  array();
			if(sizeOf($interviewers) > 0){
				foreach($interviewers as $i){
					$this->ctxt->setProperty('interview_by_oid', $i);
					$s =  new PersistentObject('rct_interview_synthesis.by_interview_interviewer' , 'db');
					if($s->record != null){
						array_push($synthesis_f[$interview['_oid']] ,  array($s->record->user_oid->html , $s->record->oid->object));
					}
				}
			};
		}
		$this->ctxt->setProperty("synthesis_r" , $synthesis_r);
		$this->ctxt->setProperty("synthesis_f" , $synthesis_f);
		
		
		$this->ctxt->setProperty('page.search',$data);
        $filterKey = $this->setFilterKey($data);
        $filterKeyUrl = '&amp;filterKey='.urlencode($filterKey);
        $this->ctxt->setProperty('filterKeyUrl',$filterKeyUrl);
        $showSearch = $this->getParam('showSearch','no');
        $this->ctxt->setProperty('search.url','?nxo=my_calendar'.$filterKeyUrl);
        $this->ctxt->setProperty('list.url','?nxo=my_calendar'.$filterKeyUrl);
		$this->ctxt->setProperty('l.url','?nxo=my_calendar&candidate_oid='.$_REQUEST['candidate_oid'].'&vacancy_oid='.$_REQUEST['vacancy_oid']);
		$this->ctxt->setProperty('new_interview.url',PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=add_interview&nxs=&type=new&mode=page');
		
		$this->ctxt->setProperty('manage_email_samples.url',PORTAL_URL_PREFIX.'/recruitment/admin/manage_email_samples.php');
		$this->ctxt->setProperty('email_docs.url',PORTAL_URL_PREFIX.'/recruitment/admin/email_docs.php');
		$this->ctxt->setProperty('manage_interview_default_criterias.url',PORTAL_URL_PREFIX.'/recruitment/admin/manage_interview_default_criterias.php');
		$this->ctxt->setProperty('meeting_rooms.url',PORTAL_URL_PREFIX.'/recruitment/admin/meeting_rooms.php');

		if(isset($_REQUEST['candidate_oid']))
            $this->ctxt->setProperty('search_candidate' , $_REQUEST['candidate_oid']);
		
		if(isset($_REQUEST['interview_type']))
            $this->ctxt->setProperty('search_type' , $_REQUEST['interview_type']);
			
		//appel depuis la fiche de poste
		if(isset($_REQUEST['from_vacancy']) && $_REQUEST['from_vacancy'] == 1){
			$this->ctxt->setProperty('from_vacancy' , true);
			$this->ctxt->setProperty('vacancy.url' , PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$_REQUEST['vacancy_oid'].'/directory.php?nxo=edit&mode=page&oid='.$_REQUEST['vacancy_oid']);
			$v =  new PersistentObject('rct_vacancy.find_name_by_oid' , 'db' , array('vacancy_oid'=> $_REQUEST['vacancy_oid']));
			$this->ctxt->setProperty('vacancy_name' , $v->name->html);
			
		}

        $this->ctxt->runView($view,array(
        'lastInterviews.records' => $dsList,
        'futurInterviews.records' => $dsListFutur,
        'fmethod' => 'toHTML',
        'view.type' => $view_type,
        'forceDisplay'=>$showSearch
        ),null);

        return true;
    }
}

