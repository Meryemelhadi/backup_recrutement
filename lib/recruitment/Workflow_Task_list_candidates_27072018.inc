<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_list_candidates extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
	}

	// change fields properties in record desc (edit, no_edit, hide, show)
	function customiseRecordFields($record,$workflow,$view=null)
	{
		$fields = $workflow->model->getDS('fields',$workflow->getState());

		if(isset($fields[$view]))
		{
			$fields = $fields[$view];
		}

		if($fields)
		{
			foreach($fields as $action => $fnames)
			{
				if($action == 'no_edit')
					$workflow->setFieldsProperty($fnames, 'isEdit' , false,$record);
				elseif($action == 'edit')
					$workflow->setFieldsProperty($fnames, 'isEdit' , true,$record);
				elseif($action == 'hide')
					$workflow->setFieldsProperty($fnames, 'show' , false,$record);
				elseif($action == 'show')
					$workflow->setFieldsProperty($fnames, 'show' , true,$record);
			}
		}
	}

	function run($workflow, $user)
	{
	
		//Permission DRH
		$drh = "";
		if($GLOBALS['_NX_user']->checkPerm('?-drh')) $drh = ".drh";
		

		if($GLOBALS['_NX_user']->checkPerm('?-drh'))
			$searchData=$this->getRecord('rct_candidate.search-drh','page.search','request',false,null,null);
		else $searchData=$this->getRecord('rct_candidate.search','page.search','request',false,null,null);
        //var_dump($this->getProperty('page.search'));die;

		$this->customiseRecordFields($searchData,$workflow,'search');

		$searchDataVar='searchData';
		$_searchKey_=(($_nx_rec13=${$searchDataVar})!=null?$_nx_rec13->getUrlKey(true):'');
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
		$this->setProperty("filterKey",$_searchKey_);

		if(isset($_GET['nxs']))
			$_searchKey_ = 'nxs='.$_GET['nxs'].'&'.$_searchKey_;

		if(isset($_GET['nxo']))
			$_searchKey_ = 'nxo='.$_GET['nxo'].'&'.$_searchKey_;

		$GLOBALS["NX_CURRENT_URL"] ='?'.$_searchKey_;

		$filterKey = $this->getProperty("filterKey","");
		$ufilterKey = urlencode($filterKey);
		
		$this->setProperty('saved_search',0);
		if(isset($_REQUEST['search_oid']) && $_REQUEST['search_oid']!=''){
			$this->setProperty('saved_search',1);
		}

		// $this->setProperty("alphabet_filter",(isset($_REQUEST["alphabet_filter"])?$_REQUEST["alphabet_filter"]:""));

		$this->getRecords('handler:recruitment.candidates.list','page.records','db',false,$searchData,null);
		$this->getRecords('handler:recruitment.vacancy.list'.$drh,'page.vacancies_records','db',false,null,null);
		$this->getRecords('rct_candidate_category.ds_list','candidate_categories.records','db',false,null,null);
		$this->getRecord('rct_candidate.saved_search','saved_search.record','empty',false,null,null);
		// $this->getRecords('recruitment.tri','tri.records','db',false,null,null);

		$this->setProperty('add.url',$_SERVER["PHP_SELF"].'?nxo=add&amp;nxs=&amp;filterKey='.$ufilterKey);
		$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;filterKey='.$ufilterKey);
		//$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;filterKey='.$ufilterKey);
		$this->setProperty('archive.url',$_SERVER["PHP_SELF"].'?nxo=archive_cvs&amp;nxs=&amp;filterKey='.$ufilterKey);
		$this->setProperty('delete.url',$_SERVER["PHP_SELF"].'?nxo=delete&amp;nxs=&amp;filterKey='.$ufilterKey);
		$this->setProperty('delete_cvs.url',$_SERVER["PHP_SELF"].'?nxo=delete_cvs&amp;nxs=&amp;filterKey='.$ufilterKey);
		$this->setProperty('preview_cv.url',$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cv');
		$this->setProperty('get_search.url',$_SERVER["PHP_SELF"].'?nxo=saved_search:get_search_ajax&amp;nxs=&amp;');
		$this->setProperty('delete_search.url',$_SERVER["PHP_SELF"].'?nxo=saved_search:delete_ajax&amp;nxs=&amp;');
		$this->setProperty('massive_associate_to_vacancy.url',$_SERVER["PHP_SELF"].'?nxo=massive_associate_to_vacancy&amp;nxs=&amp;filterKey='.$ufilterKey);
		$this->setProperty('massive_associate_to_vacancy_process.url',$_SERVER["PHP_SELF"].'?nxo=massive_associate_to_vacancy_process&amp;nxs=&amp;filterKey='.$ufilterKey);
		$this->setProperty('massive_relevance_process.url',$_SERVER["PHP_SELF"].'?nxo=massive_relevance_process&amp;nxs=&amp;filterKey='.$ufilterKey);
		$this->setProperty('massive_interviews.url',PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=add_interview&nxs=&from=cvtq&'.$this->lien_cleaner().'&candidate_oid=');
		$this->setProperty('relevance.url',$_SERVER["PHP_SELF"].'?nxo=relevance&amp;nxs=&amp;filterKey='.$ufilterKey);
		$this->setProperty('send_cvs_to_many_client.url',$_SERVER["PHP_SELF"].'?nxo=send_cvs_to_many_client&amp;nxs=&amp;filterKey='.$ufilterKey);
		$this->setProperty('massive_associate_to_recuiter.url',$_SERVER["PHP_SELF"].'?nxo=massive_associate_to_recuiter&amp;nxs=&amp;filterKey='.$ufilterKey);
		$this->setProperty('category.url',$_SERVER["PHP_SELF"].'?nxo=category&amp;nxs=process&amp;filterKey='.$ufilterKey);
		$this->setProperty('statistics.url',$_SERVER["PHP_SELF"].'?nxo=statistics&amp;nxs='.$filterKey);
		$this->setProperty('change_reading_state.url',$_SERVER["PHP_SELF"].'?nxo=change_reading_state&amp;nxs=');
		$this->setProperty('add_interview.url',PORTAL_URL_PREFIX.'/recruitment/interview/directory.php?nxo=add_interview&amp;nxs=&amp;candidate_oid=');
		
		//Config Url
		$this->setProperty('search_params.url',PORTAL_URL_PREFIX.'/recruitment/search_params.php');
		$this->setProperty('manage_keywords.url',PORTAL_URL_PREFIX.'/recruitment/admin/manage_keywords.php');
		$this->setProperty('manage_candidates_categories.url',PORTAL_URL_PREFIX.'/recruitment/admin/manage_candidate_categories.php');
		$this->setProperty('manage_schools.url',PORTAL_URL_PREFIX.'/recruitment/admin/manage_schools.php');
		$this->setProperty('manage_diplomas.url',PORTAL_URL_PREFIX.'/recruitment/admin/manage_diplomas.php');
		$this->setProperty('profiling_rules.url',PORTAL_URL_PREFIX.'/recruitment/candidates/profiling_rules.php');

//		$this->setProperty('search.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;filterKey='.$ufilterKey.'&amp;mode=ajax&amp;search_in_archive=0&amp;is_search=true');
		$this->setProperty('search.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;filterKey='.$ufilterKey);
		$this->setProperty('list_ajax.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;filterKey='.$ufilterKey.'&mode=ajax');
		$this->setProperty('add_saved_search.url',$_SERVER["PHP_SELF"].'?nxo=saved_search:add_process_ajax&mode=ajax');
		
        $this->setProperty('page.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;filterKey='.$ufilterKey.'&amp;is_search=true');

        $this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=ajax&amp;cancel=true');
		$this->setProperty('list_cancel_search.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=ajax&amp;cancel=true');

		if((isset($_REQUEST["is_search"])?$_REQUEST["is_search"]:"") == 'true')
		{
			$this->setProperty("is_search",'true');
		}
		
		//appel depuis la fiche de poste
		if(isset($_REQUEST['from_vac']) && $_REQUEST['from_vac'] == 1){
			$this->setProperty('from_vacancy' , true);
			$this->setProperty('vacancy.url' , PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$_REQUEST['vacancy'].'/directory.php?nxo=edit&mode=page&oid='.$_REQUEST['vacancy']);
			$v =  new PersistentObject('rct_vacancy.find_name_by_oid' , 'db' , array('vacancy_oid'=> $_REQUEST['vacancy']));
			$this->setProperty('vacancy_name' , $v->name->html);
		}
		
		$this->setProperty('search_in_archive.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=ajax&amp;search_in_archive=1');
		$this->setProperty('xls_export.url',$_SERVER["PHP_SELF"].'?nxo=xls_export&amp;nxs='.$filterKey);
		$this->runView('recruitment.candidates.list_bs',array('fmethod' => 'toHTML'),null);
		
		/*$viewMode='page';
		
		if(in_array((isset($_GET["mode"])?$_GET["mode"]:""),array('page','ajax')))
		{
			$viewMode=(isset($_GET["mode"])?$_GET["mode"]:"");
		}
		if($viewMode == 'page')
		{
			$this->runView('recruitment.candidates.list_bs',array('fmethod' => 'toHTML'),null);
		}
		else
		{
			$this->runView('recruitment.candidates.list_bs',array('fmethod' => 'toHTML',),null);
		}*/

		return true;
	}
	
	function lien_cleaner ()
	{
		$arg = explode('&', $_SERVER['QUERY_STRING']);
		$chaine_final = '';
		foreach( $arg as $value )
		{
			$arg2 = explode('=', $value);  
			if ($arg2[0]!= 'nxo' && $arg2[0]!= 'nxs') {$chaine_final .= $value.'&';}   
		}
		return $chaine_final ;
	}
}
?>