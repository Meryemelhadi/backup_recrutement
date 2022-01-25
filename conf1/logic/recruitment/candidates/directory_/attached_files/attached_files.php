<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__attached_files_attached_files extends NxPage
{
	function recruitment_candidates_directory__attached_files_attached_files($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecord('rct_candidate_files.record','attached_file.new.record','empty',false,null,null);
					$this->getRecords('rct_candidate_files.list','attached_files.records','db',false,null,null);
					$this->runView('recruitment.candidates.components.panel_files',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>