<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_vacancies_admin_list extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
	}

	function run()
	{
		if(!isset($_REQUEST['current_step']) || $_REQUEST['current_step']==='')
		{
			$defaultState = true;
			$_POST['current_step']=$_GET['current_step']=$_REQUEST['current_step']='0';
		}
		else
			$defaultState = false;

		// search context
		$searchData=
			$this->getRecord('rct_vacancy.search','page.search','request',false,null,null);

		// load vacancies
		$vacanciesList=$this->getRecords('rct_vacancy.list','page.records','db',false,$searchData,null);

		if($defaultState)
		{
			// reset state
			$searchData->current_step->object='';
		}

		$searchDataVar='searchData';
		$_searchKey_=(($_nx_rec64=${$searchDataVar})!=null?$_nx_rec64->getUrlKey(true):'');
		
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
		if(isset($_GET['wao']))
			$_searchKey_ = 'wao='.$_GET['wao'].'&'.$_searchKey_;

		$GLOBALS["NX_CURRENT_URL"] ='?'.$_searchKey_;
	
		$this->setProperty("alphabet_filter",(isset($_REQUEST["alphabet_filter"])?$_REQUEST["alphabet_filter"]:""));


		if($_nx_records69=$vacanciesList) 
		{
			for (	$_nx_iterRec68 = $vacanciesList->getRecordIterator(); 
				$_nx_iterRec68->isValid(); 
				$_nx_iterRec68->next())
			{
			
				$vacancy=&$_nx_iterRec68->getCurrent();
				$this->setProperty('vacancy_id',
					$vacancy->getProperty('oid','',false,'object',''));
				
				$candidatesList=
					$this->getRecords('rct_candidate_vacancy.vacancy_candidates','','db',false,null,null);
				
				$candidatescount=
					(($_nx_records65=$candidatesList)!=null?$_nx_records65->count():0);
				
				if(($_nx_rec66=&$vacancy)!=null) $_nx_rec66->setField('candidates_count',$candidatescount);
			}
		}

		$pself = $_SERVER["PHP_SELF"];
		$fkey = '&amp;filterKey='.urlencode($this->getProperty("filterKey",""));
		
		$this->getRecords('rct_vacancy.pending_list','page_pending.records','db',false,null,null);

		$this->addProperties(
			array(
				'add.url'=>$pself.'?nxo=add&amp;nxs='.$fkey,
				'edit.url'=>$pself.'?nxo=edit&amp;nxs='.$fkey,
				'xls_export.url'=>$pself.'?nxo=xls_export_'.$this->getProperty("recruitement_profile","default").'&amp;nxs='.$this->getProperty("filterKey",""),
				'archive.url'=>$pself.'?nxo=archive&amp;nxs='.$fkey,
				'delete.url'=>$pself.'?nxo=delete&amp;nxs='.$fkey,
				'validate.url'=>$pself.'?nxo=validate&amp;nxs='.$fkey,
				'search.url'=>$pself.'?nxo=list&amp;nxs=&amp;is_search=true',

				'back_list.url'=>PORTAL_URL_PREFIX.'/recruitment/vacancies/directory.php?nxo=list&amp;nxs='.$_searchKey_,

				'list.url'=>$pself.'?nxo=list&amp;nxs=',
			)
		);
				
		if((isset($_REQUEST["is_search"])?$_REQUEST["is_search"]:"") == 'true')
		{
			$this->setProperty("is_search",'true');
		}

		$this->runView('recruitment.vacancies.list',array('fmethod' => 'toHTML',),null);
		return true;
	}
}
?>