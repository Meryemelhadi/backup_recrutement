<?php

class Workflow_Task_list_interview_calendar extends Workflow_Task
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
		$vacancy_oid = (isset($_REQUEST["void"])?$_REQUEST["void"]:$_REQUEST["vacancy_oid"]);

		//Permission DRH
		$drh = "";
		if($GLOBALS['_NX_user']->checkPerm('?-drh')) $drh = "-drh";
		
        // buttons
        $this->ctxt->setProperty('edit.url',PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=edit_interview&operation=my_calendar&mode=page&oid=');
		
		$this->ctxt->setProperty('edit_interview.url',PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=edit_interview&operation=my_calendar&mode=page&oid=');
		$fvac = "";
		if(isset($_REQUEST["from_vac"]) && $_REQUEST["from_vac"] == 1){
			$this->ctxt->setProperty('edit_interview.url',PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=edit_interview&operation=my_calendar&from_vac=1&vacancy_oid='.$vacancy_oid.'&oid=');
			$this->ctxt->setProperty('from_vac' , true );
			$fvac = '&from_vac=1';
		}

        $this->ctxt->setProperty('edit_candidate.url',PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo=edit&mode=page&operation=my_calendar'.$fvac.'&vacancy_oid='.$vacancy_oid.'&oid=');
        $this->ctxt->setProperty('eval.url',PORTAL_URL_PREFIX.'/recruitement2/interview_evaluation.php?nxo=edit_by_interview&operation=my_calendar'.$fvac.'&vacancy_oid='.$vacancy_oid.'&oid=');

        // set toolbar buttons
        $props=$this->setButtons();


        // display list
        $view = $this->getParam('view','list');
        $view = $model->getDisplayView($view);
        $view_type = $this->getParam('view_type','HTML');

        if(($listOperations = $this->getParam('list_operations')) ||
            ($listOperations = $workflow->getListOperations()))

            $this->ctxt->setProperty('list_operations',$listOperations);
        $dsList = $this->ctxt->getRecords('handler:rct_interview.ds_calendar_list_realised','page.records','db',false,null,null);
        $dsListFutur = $this->ctxt->getRecords('handler:rct_interview.ds_calendar_list_futur','page.records','db',false,null,null);
        $osearch = new PersistentObject();
        $osearch->load('rct_interview.search'.$drh,'request');
        $data = $osearch->record;
        $this->ctxt->setProperty('page.search',$data);
        $filterKey = $this->setFilterKey($data);
        $filterKeyUrl = '&amp;filterKey='.urlencode($filterKey);
        $this->ctxt->setProperty('filterKeyUrl',$filterKeyUrl);
        $showSearch = $this->getParam('showSearch','no');
        $this->ctxt->setProperty('search.url','?nxo=my_calendar'.$filterKeyUrl);
        $this->ctxt->setProperty('list.url','?nxo=my_calendar'.$filterKeyUrl.'&vacancy_oid'.$vacancy_oid);
		$this->ctxt->setProperty('l.url','?nxo=calendar_vacancy&candidate_oid='.$_REQUEST['candidate_oid'].'&vacancy_oid='.$_REQUEST['vacancy_oid'].'&oid='.$_REQUEST['vacancy_oid'].'&from_vac=1');
        $this->ctxt->setProperty("current_operation",'calendar');
        $vacancy_param = '&amp;vacancy_oid='.$vacancy_oid.'&amp;void='.$vacancy_oid.'&amp;oid='.$vacancy_oid;
		if(isset($_REQUEST['from_vac']) && $_REQUEST['from_vac']==1){
			$vacancy_param .= '&from_vac=1';
			$this->ctxt->setProperty('old_calendar.url' ,  $pself.'?nxo=calendar&amp;nxs=&vacancy_oid='.$vacancy_oid.'&mode=ajax&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")).'&from_vac='.$_REQUEST['from_vac']);
			$this->ctxt->setProperty('oldCalendar' , true);
		}
        $pself = PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$vacancy_oid.'/directory.php';
		
        $this->ctxt->addProperties(array(
            'list.url'=> $pself.'?nxo=list&amp;nxs='.$filterKey.'&amp;mode=ajax',
            'edit.url'=> $pself.'?nxo=edit&amp;nxs=&amp;oid='.$vacancy_oid.$vacancy_param,
            'requirements.url'=> $pself.'?nxo=requirements&amp;nxs='.$vacancy_param,
            'calendar.url'=>  PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$vacancy_oid.'/directory.php?nxo=calendar_vacancy&amp;nxs='.$vacancy_param,
            'shorts_list.url'=> $pself.'?nxo=shorts_list&amp;nxs='.$vacancy_param,
            'associated_candidate.url'=> $pself.'?nxo=associated_candidate&amp;nxs='.$vacancy_param,
            'rated.url'=> $pself.'?nxo=rated_candidate&amp;nxs='.$vacancy_param,
            'candidates.url'=> $pself.'?nxo=candidates&amp;nxs='.$vacancy_param,
            'refused_candidate.url'=> $pself.'?nxo=refused_candidate&amp;nxs='.$vacancy_param,
            'recruitment_providers.url'=> $pself.'?nxo=list_prest&amp;nxs='.$vacancy_param,
            'synthesis.url'=> $pself.'?nxo=synthesis&amp;nxs='.$vacancy_param,
            'feedback.url'=> $pself.'?nxo=feedback&amp;nxs='.$vacancy_param,
            'warning.url'=> $pself.'?nxo=warning&amp;nxs='.$vacancy_param,
            'history.url'=> $pself.'?nxo=history&amp;nxs='.$vacancy_param,
            'announcement.url'=> $pself.'?nxo=announcement&amp;nxs='.$vacancy_param,
			'add_interview.url' => PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=add_interview&amp;nxs='.$vacancy_param,
            'vacancy_oid'=>$vacancy_oid

        ));
		
		$this->ctxt->getRecord('rct_vacancy.get_title','vacancy_title_record','db',false,null,null);

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

