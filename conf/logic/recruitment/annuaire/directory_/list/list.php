<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_annuaire_directory__list_list extends NxPage
{
	function recruitment_annuaire_directory__list_list($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$searchData=
						$this->getRecord('rct_client.search','page.search','request',false,null,null);
					$searchDataVar='searchData';
					$_searchKey_=(($_nx_rec0=${$searchDataVar})!=null?$_nx_rec0->getUrlKey(true):'');
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
					$this->getRecords('rct_client.list','page.records','db',false,$searchData,null);
					$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=ajax');
					$this->setProperty('search.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;filterKey='.$this->getProperty("filterKey","").'&amp;mode=ajax');
					$this->setProperty('view.url',$_SERVER["PHP_SELF"].'?nxo=view&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('add.url',$_SERVER["PHP_SELF"].'?nxo=add&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('xls.url',$_SERVER["PHP_SELF"].'?nxo=xls_export&amp;nxs='.$this->getProperty("filterKey",""));
					$viewMode='page';
					if(in_array((isset($_GET["mode"])?$_GET["mode"]:""),array('page','ajax')))
					{
						$viewMode=(isset($_GET["mode"])?$_GET["mode"]:"");
					}
						if($viewMode == 'page')
						{
							$this->runView('/recruitment/annuaire/directory__listpage',array(
								'fmethod' => 'toHTML',

								),null);
						}
						else {
							$this->runView('/recruitment/annuaire/directory__listajax',array(
								'fmethod' => 'toHTML',

								),null);
						}
		return true;
	}
}
?>