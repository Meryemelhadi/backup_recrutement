<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_vacancies_client_list extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
	}

	function run()
	{
		
		(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->init_list_search() : null);
					$searchData=
						$this->getRecord('rct_vacancy.search','page.search','request',false,null,null);
					$searchDataVar='searchData';
					$_searchKey_=(($_nx_rec31=${$searchDataVar})!=null?$_nx_rec31->getUrlKey(true):'');
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

			$GLOBALS["NX_CURRENT_URL"] ='?'.$_searchKey_;

			
					$this->setProperty("filterKey",$_searchKey_);
					$this->setProperty("alphabet_filter",(isset($_REQUEST["alphabet_filter"])?$_REQUEST["alphabet_filter"]:""));
					$this->getRecords('rct_vacancy.client_list','page.records','db',false,$searchData,null);
					$this->getRecords('rct_vacancy.pending_client_list','page_pending.records','db',false,null,null);
					$this->setProperty('add.url',$_SERVER["PHP_SELF"].'?nxo=add&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('archive.url',$_SERVER["PHP_SELF"].'?nxo=archive&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('delete.url',$_SERVER["PHP_SELF"].'?nxo=delete&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('edit_request.url',$_SERVER["PHP_SELF"].'?nxo=edit_request&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('search.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;is_search=true&amp;mode=ajax');
					$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=ajax');
					if((isset($_REQUEST["is_search"])?$_REQUEST["is_search"]:"") == 'true')
					{
						$this->setProperty("is_search",'true');
					}
					$this->runView('recruitment.vacancies_client.list@recruitment',array('fmethod' => 'toHTML',),null);
		
		return true;
	}
}
?>