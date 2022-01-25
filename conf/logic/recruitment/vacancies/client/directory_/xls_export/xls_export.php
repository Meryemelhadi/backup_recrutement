<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_client_directory__xls_export_xls_export extends NxPage
{
	function recruitment_vacancies_client_directory__xls_export_xls_export($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$searchData=
						$this->getRecord('rct_vacancy.search','page.search','request',false,null,null);
					$this->getRecords('rct_vacancy.client_list','page.records','handler',true,$searchData,null);
 
								$gen_file = 'liste_candidats_'.date('jmyHd').'.xls';
							

					$this->setProperty("file.name",$gen_file);global $NX_MIME;
$NX_MIME='text/html';

					$this->runView('/recruitment/vacancies/client/directory__xls',array(
						'fmethod' => 'toHTML',
						'view.type' => 'XLS',

						),null);
		return true;
	}
}
?>