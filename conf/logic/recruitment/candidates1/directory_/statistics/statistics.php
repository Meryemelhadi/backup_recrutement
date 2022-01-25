<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__statistics_statistics extends NxPage
{
	function recruitment_candidates_directory__statistics_statistics($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$searchData=
						$this->getRecord('rct_candidate.search','page.search','request',false,null,null);
					$searchDataVar='searchData';
					$this->setProperty("filterKey",(($_nx_rec0=${$searchDataVar})!=null?$_nx_rec0->getUrlKey(true):''));
					$this->setProperty("alphabet_filter",(isset($_REQUEST["alphabet_filter"])?$_REQUEST["alphabet_filter"]:""));
					$this->setProperty("stats_page",'true');
					$records=
						$this->getRecords('handler:recruitment.candidates.list','page.records','db',false,$searchData,null);
					(($__o=$this->getHandler('lib.recruitment.candidates.services.dashboard','')) ? $__o->load_stats($records) : null);
					$this->getRecords('rct_vacancy.ds_list_all','page.vacancies_records','db',false,null,null);
					$this->getRecords('rct_candidate_category.ds_list','candidate_categories.records','db',false,null,null);
					$this->setProperty('search.url',$_SERVER["PHP_SELF"].'?nxo=statistics&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")).'&amp;mode=ajax&amp;search_in_archive=0&amp;is_search=true');
					$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.$this->getProperty("filterKey",""));
					if((isset($_REQUEST["is_search"])?$_REQUEST["is_search"]:"") == 'true')
					{
						$this->setProperty("is_search",'true');
					}
					$this->setProperty('search_in_archive.url',$_SERVER["PHP_SELF"].'?nxo=statistics&amp;nxs=&amp;mode=ajax&amp;search_in_archive=1');
					$viewMode='page';
					if(in_array((isset($_GET["mode"])?$_GET["mode"]:""),array('page','ajax')))
					{
						$viewMode=(isset($_GET["mode"])?$_GET["mode"]:"");
					}
						if($viewMode == 'page')
						{
							$this->runView('/recruitment/candidates/directory__stat',array(
								'fmethod' => 'toHTML',

								),null);
						}
						else {
							$this->runView('/recruitment/candidates/directory__stat_ajax',array(
								'fmethod' => 'toHTML',

								),null);
						}
		return true;
	}
}
?>