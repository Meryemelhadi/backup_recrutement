<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__list_list extends NxPage
{
	function recruitment_candidates_directory__list_list($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$searchData=
						$this->getRecord('rct_candidate.search','page.search','request',false,null,null);
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
					$this->getRecords('handler:recruitment.candidates.list','page.records','db',false,$searchData,null);
					$this->getRecords('rct_vacancy.ds_list_all','page.vacancies_records','db',false,null,null);
					$this->getRecords('rct_candidate_category.ds_list','candidate_categories.records','db',false,null,null);
					$this->getRecords('recruitment.tri','tri.records','db',false,null,null);
					$this->setProperty('add.url',$_SERVER["PHP_SELF"].'?nxo=add&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('archive.url',$_SERVER["PHP_SELF"].'?nxo=archive&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('delete.url',$_SERVER["PHP_SELF"].'?nxo=delete&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('preview_cv.url',$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cv');
					$this->setProperty('massive_associate_to_vacancy.url',$_SERVER["PHP_SELF"].'?nxo=massive_associate_to_vacancy&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('massive_associate_to_vacancy_process.url',$_SERVER["PHP_SELF"].'?nxo=massive_associate_to_vacancy&amp;nxs=process&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('massive_relevance_process.url',$_SERVER["PHP_SELF"].'?nxo=relevance&amp;nxs=process&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('relevance.url',$_SERVER["PHP_SELF"].'?nxo=relevance&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('send_cvs_to_many_client.url',$_SERVER["PHP_SELF"].'?nxo=send_cvs_to_many_client&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('category.url',$_SERVER["PHP_SELF"].'?nxo=category&amp;nxs=process&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('statistics.url',$_SERVER["PHP_SELF"].'?nxo=statistics&amp;nxs='.$this->getProperty("filterKey",""));
					$this->setProperty('change_reading_state.url',$_SERVER["PHP_SELF"].'?nxo=change_reading_state&amp;nxs=');
					$this->setProperty('search.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")).'&amp;mode=ajax&amp;search_in_archive=0&amp;is_search=true');
					$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=ajax&amp;cancel=true');
					$this->setProperty('list_cancel_search.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=ajax&amp;cancel=true');
					if((isset($_REQUEST["is_search"])?$_REQUEST["is_search"]:"") == 'true')
					{
						$this->setProperty("is_search",'true');
					}
					$this->setProperty('search_in_archive.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=ajax&amp;search_in_archive=1');
					$this->setProperty('xls_export.url',$_SERVER["PHP_SELF"].'?nxo=xls_export&amp;nxs='.$this->getProperty("filterKey",""));
					$viewMode='page';
					if(in_array((isset($_GET["mode"])?$_GET["mode"]:""),array('page','ajax')))
					{
						$viewMode=(isset($_GET["mode"])?$_GET["mode"]:"");
					}
						if($viewMode == 'page')
						{
							$this->runView('/recruitment/candidates/directory__list',array(
								'fmethod' => 'toHTML',

								),null);
						}
						else {
							$this->runView('/recruitment/candidates/directory__list_ajax',array(
								'fmethod' => 'toHTML',

								),null);
						}
		return true;
	}
}
?>