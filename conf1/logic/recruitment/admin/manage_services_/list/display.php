<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_admin_manage_services__list_display extends NxPage
{
	function recruitment_admin_manage_services__list_display($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$searchData=
						$this->getRecord('rct_service.search','page.search','request',false,null,null);
					$searchDataVar='searchData';
					$this->setProperty("filterKey",(($_nx_rec0=${$searchDataVar})!=null?$_nx_rec0->getUrlKey(true):''));
					$this->getRecords('rct_service.list','page.records','db',false,$searchData,null);
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
							$this->runView('/recruitment/admin/manage_services__list',array(
								'fmethod' => 'toHTML',

								),null);
						}
						else {
							$this->runView('/recruitment/admin/manage_services__list_ajax',array(
								'fmethod' => 'toHTML',

								),null);
						}
		return true;
	}
}
?>