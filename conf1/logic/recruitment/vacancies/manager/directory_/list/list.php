<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__list_list extends NxPage
{
	function recruitment_vacancies_manager_directory__list_list($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$searchData=
						$this->getRecord('rct_vacancy.search','page.search','request',false,null,null);
					$searchDataVar='searchData';
					$_searchKey_=(($_nx_rec44=${$searchDataVar})!=null?$_nx_rec44->getUrlKey(true):'');
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

			if(isset($_GET['ltr']))
				$_searchKey_ = 'ltr='.$_GET['ltr'].'&'.$_searchKey_;
			if(isset($_GET['nxs']))
				$_searchKey_ = 'nxs='.$_GET['nxs'].'&'.$_searchKey_;
			if(isset($_GET['nxo']))
				$_searchKey_ = 'nxo='.$_GET['nxo'].'&'.$_searchKey_;
			if(isset($_GET['wao']))
				$_searchKey_ = 'wao='.$_GET['wao'].'&'.$_searchKey_;

			$GLOBALS["NX_CURRENT_URL"] ='?'.$_searchKey_;

			
					$this->setProperty("filterKey",$_searchKey_);
					$this->setProperty("alphabet_filter",(isset($_REQUEST["alphabet_filter"])?$_REQUEST["alphabet_filter"]:""));
					$vacanciesList=
						$this->getRecords('rct_vacancy.list','page.records','db',false,$searchData,null);
					if($_nx_records49=$vacanciesList) {
					for (	$_nx_iterRec48 = $vacanciesList->getRecordIterator(); 
						$_nx_iterRec48->isValid(); 
						$_nx_iterRec48->next())
					{
					$vacancy=&$_nx_iterRec48->getCurrent();
						$this->setProperty("vacancy_id",
							$vacancy->getProperty('oid','',false,'object',''));
						$candidatesList=
							$this->getRecords('rct_candidate_vacancy.vacancy_candidates','','db',false,null,null);
						$candidatescount=
							(($_nx_records45=$candidatesList)!=null?$_nx_records45->count():0);
						if(($_nx_rec46=&$vacancy)!=null) $_nx_rec46->setField('candidates_count',$candidatescount);
					}}
					$this->getRecords('rct_vacancy.pending_list','page_pending.records','db',false,null,null);
					$this->setProperty('add.url',$_SERVER["PHP_SELF"].'?nxo=add&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('xls_export.url',$_SERVER["PHP_SELF"].'?nxo=xls_export_'.$this->getProperty("recruitement_profile","default").'&amp;nxs='.$this->getProperty("filterKey",""));
					$this->setProperty('archive.url',$_SERVER["PHP_SELF"].'?nxo=archive&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('delete.url',$_SERVER["PHP_SELF"].'?nxo=delete&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('validate.url',$_SERVER["PHP_SELF"].'?nxo=validate&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('search.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;is_search=true&amp;mode=ajax');
					$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=ajax');
					if((isset($_REQUEST["is_search"])?$_REQUEST["is_search"]:"") == 'true')
					{
						$this->setProperty("is_search",'true');
					}
					$viewMode='page';
					if(in_array((isset($_GET["mode"])?$_GET["mode"]:""),array('page','ajax')))
					{
						$viewMode=(isset($_GET["mode"])?$_GET["mode"]:"");
					}
						if($viewMode == 'page')
						{
							$this->runView('/recruitment/vacancies/manager/directory__list',array(
								'fmethod' => 'toHTML',

								),null);
						}
						else {
							$this->runView('/recruitment/vacancies/manager/directory__list_ajax',array(
								'fmethod' => 'toHTML',

								),null);
						}
		return true;
	}
}
?>