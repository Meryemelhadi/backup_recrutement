<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__delete_comment_process extends NxPage
{
	function recruitment_candidates_directory__delete_comment_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->deleteRecords('rct_candidate_comment.delete',$this->getRecords('rct_candidate_comment.delete',null,'db'),'db',true);
		return true;
	}
}
?>