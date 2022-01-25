<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_manager_directory__preview_preview extends NxPage
{
	function recruitment_vacancies_manager_directory__preview_preview($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.candidates.services.directory','')) ? $__o->preview((isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""),(isset($_REQUEST["type"])?$_REQUEST["type"]:"")) : null))!=null?$this->addProperties($tmp):null;
					$this->runView('/recruitment/vacancies/manager/directory__preview',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>