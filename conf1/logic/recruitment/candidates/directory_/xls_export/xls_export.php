<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__xls_export_xls_export extends NxPage
{
	function recruitment_candidates_directory__xls_export_xls_export($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$searchData=
						$this->getRecord('rct_candidate.search','page.search','request',false,null,null);
					$this->getRecords('rct_candidate.xls_export','page.records','handler',true,$searchData,null);
 
								$gen_file = 'liste_candidats_'.date('jmyHd');
							

					$this->setProperty("file.name",$gen_file);global $NX_MIME;
$NX_MIME='text/html';

					$this->runView('/recruitment/candidates/directory__xls',array(
						'fmethod' => 'toHTML',
						'view.type' => 'XLS',

						),null);
		return true;
	}
}
?>