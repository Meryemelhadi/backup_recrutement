<?php

include_once(NX_LIB.'framework.inc');

class Workflow_Task_dashboard_interviews  extends Workflow_Task
{
	var $params;
	var $ctxt;

	function __construct($ctxt,$params=null) {
		$this->ctxt = $ctxt;
		$this->params = $params;
	}

	function run($workflow, $user)
	{
		$model = $workflow->model;
		$this->ctxt->setProperty('workflow',$workflow);

		// get List DML
        $data = $this->getParam('data','dashboard');
		$dsList = $model->getDS($data);
		if(!$dsList) 
			$dsList = $dataModel->getDS($data);

		if(!$dsList) 
			return false;

		// get Search DML
        $dsSearch = $this->getParam('search','search');
		$ds = $model->getDS($dsSearch);
		if(!$ds) 
			$ds=$dataModel->getDS($dsSearch);

		if($ds) 
		{
			// load search record
			$osearch = new PersistentObject();
			$osearch->load($ds,'request');
			$dataSearch = $osearch->record;
			$this->ctxt->setProperty('page.search',$dataSearch);

			// prepare the filter key (parameters of search used for pagination)
			$filterKey = $this->setFilterKey($dataSearch);
			$filterKeyUrl = '&amp;filterKey='.urlencode($filterKey);
			$this->ctxt->setProperty('filterKeyUrl',$filterKeyUrl);
		}
		else
		{
			$data=null;
			$filterKeyUrl = '';
		}

		// buttons
		$this->ctxt->setProperty('list.url','?nxo='.$_REQUEST['nxo'].$filterKeyUrl);

        // set toolbar buttons
        $props=$this->setButtons();

		// load record from request in create mode (with clone enabled if using models)
		$col = new PersistentCollection();
		$col->load($dsList,'handler',null,$dataSearch);
		if(!$col->isOk())
			return false;

		// display list
        $view = $this->getParam('view','dashboard');
		$view = $model->getDisplayView($view);
        $view_type = $this->getParam('view_type','HTML');
        $showSearch = $this->getParam('showSearch','yes');

		$this->ctxt->runView($view,array(
			'page.records' => $col->records,
			'fmethod' => 'toHTML',
			'view.type' => $view_type,
			'forceDisplay'=>$showSearch
			),null);

		return true;
	}

	function setFilterKey($searchData)
	{
		$searchDataVar='searchData';
		$_searchKey_=(($_nx_rec2=${$searchDataVar})!=null?$_nx_rec2->getUrlKey(true):'');
		if((isset($_REQUEST["page"])?$_REQUEST["page"]:""))
		{
			$_searchKey_ = preg_replace("/page=[^&]+(&(amp;)?)?/",'',$_searchKey_);  
			$_searchKey_=$_searchKey_.'&amp;page='.(isset($_REQUEST["page"])?$_REQUEST["page"]:"");
		}

		if((isset($_REQUEST["sort_by"])?$_REQUEST["sort_by"]:""))
		{
			$_searchKey_ = preg_replace("/sort_by=[^&]+(&(amp;)?)?/",'',$_searchKey_);  
			$_searchKey_=$_searchKey_.'&amp;sort_by='.(isset($_REQUEST["sort_by"])?$_REQUEST["sort_by"]:"");
		}

		if((isset($_REQUEST["sort_dir"])?$_REQUEST["sort_dir"]:""))
		{
			$_searchKey_ = preg_replace("/sort_dir=[^&]+(&(amp;)?)?/",'',$_searchKey_);  
			$_searchKey_=$_searchKey_.'&amp;sort_dir='.(isset($_REQUEST["sort_dir"])?$_REQUEST["sort_dir"]:"");
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

}
?>