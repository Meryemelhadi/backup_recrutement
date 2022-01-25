<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__edit_process extends NxPage
{
	function recruitment_vacancies_client_directory__edit_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					<card_edit:process/>
					(($__o=$this->getHandler('','')) ? $__o->partial($this->getProperty("candidate_oid","")) : null);
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$this->getProperty("candidate_oid","").'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->runView('/recruitment/vacancies/client/directory__redirect',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>