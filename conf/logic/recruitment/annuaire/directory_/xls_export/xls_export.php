<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_annuaire_directory__xls_export_xls_export extends NxPage
{
	function recruitment_annuaire_directory__xls_export_xls_export($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecords('rct_client.excel','page.records','db',true,null,null);global $NX_MIME;
$NX_MIME='text/html';

					$this->runView('/recruitment/annuaire/directory__xls',array(
						'fmethod' => 'toHTML',
						'view.type' => 'XLS',

						),null);
		return true;
	}
}
?>