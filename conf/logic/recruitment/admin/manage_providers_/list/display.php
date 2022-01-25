<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_admin_manage_providers__list_display extends NxPage
{
	function recruitment_admin_manage_providers__list_display($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$searchData=
						$this->getRecord('rct_provider.search','page.search','request',false,null,null);
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
					$this->getRecords('rct_provider.list','page.records','db',false,$searchData,null);
					$this->setProperty('add_ajax.url',$_SERVER["PHP_SELF"].'?nxo=new_ajax&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('add.url',$_SERVER["PHP_SELF"].'?nxo=new_ajax&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('delete.url',$_SERVER["PHP_SELF"].'?nxo=delete&amp;nxs=');
					$this->setProperty('edit_ajax.url',$_SERVER["PHP_SELF"].'?nxo=edit_ajax&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit_ajax&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=page');
					$this->setProperty('search.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")).'&amp;mode=ajax');
					$this->setProperty('view.url',$_SERVER["PHP_SELF"].'?nxo=details&amp;nxs=&amp;filterKey='.urlencode($this->getProperty("filterKey","")));
					$viewMode='page';
					if(in_array((isset($_GET["mode"])?$_GET["mode"]:""),array('page','ajax')))
					{
						$viewMode=(isset($_GET["mode"])?$_GET["mode"]:"");
					}
						if($viewMode == 'page')
						{
							$this->runView('/recruitment/admin/manage_providers__list',array(
								'fmethod' => 'toHTML',

								),null);
						}
						else {
							$this->runView('/recruitment/admin/manage_providers__list_ajax',array(
								'fmethod' => 'toHTML',

								),null);
						}
		return true;
	}
}
?>