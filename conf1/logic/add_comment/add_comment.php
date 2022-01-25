<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class add_comment_add_comment extends NxPage
{
	function add_comment_add_comment($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->putRecord(
								$this->getRecord('','page.record','post',false,null,null),'','insert','db','Object',null);
							$this->setProperty("comment_oid",
								$this->getLastInsertID('db'));
							$this->getRecord('','','db',false,null,null);
							$this->runView('_comment',array(
								'fmethod' => 'toHTML',

								),null);
		return true;
	}
}
?>