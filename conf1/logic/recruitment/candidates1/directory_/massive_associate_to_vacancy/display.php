<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__massive_associate_to_vacancy_display extends NxPage
{
	function recruitment_candidates_directory__massive_associate_to_vacancy_display($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("candidates_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->getRecords('rct_vacancy.ds_list_all','page.records','db',false,null,null);
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process');
					$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					$this->runView('/recruitment/candidates/directory__vacancy_massive_assoc',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>