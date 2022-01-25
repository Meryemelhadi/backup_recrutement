<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__add_add extends NxPage
{
	function recruitment_vacancies_admin_directory__add_add($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecord('rct_vacancy.add_'.$this->getProperty("recruitement_profile","default"),'page.record','empty',false,null,null);
					$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					$this->setProperty("back_list.url",
								PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=page'
							);
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process&amp;redirect=list');
					$this->setProperty('submit_continue.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process&amp;redirect=edit');
					$this->runView('/recruitment/vacancies/admin/directory__add',array(
						'fmethod' => 'toForm',

						),null);
		return true;
	}
}
?>