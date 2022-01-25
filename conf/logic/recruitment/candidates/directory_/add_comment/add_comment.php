<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__add_comment_add_comment extends NxPage
{
	function recruitment_candidates_directory__add_comment_add_comment($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->putRecord(
						$this->getRecord('rct_candidate_comment.record','page.record','post',false,null,null),'rct_candidate_comment.add','insert','db','Object',null);
					$this->setProperty("comment_oid",
						$this->getLastInsertID('db'));
					$this->setProperty('delete_comment.url',$_SERVER["PHP_SELF"].'?nxo=delete_comment&amp;nxs=&amp;candidate_oid='.$this->getProperty("candidate_oid",""));
					$this->getRecord('rct_candidate_comment.get_record','page.record','db',false,null,null);
					$this->runView('/recruitment/candidates/directory__comment',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>