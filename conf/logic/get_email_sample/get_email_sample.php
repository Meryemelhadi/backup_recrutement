<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class get_email_sample_get_email_sample extends NxPage
{
	function get_email_sample_get_email_sample($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->getRecord('','','db',false,null,null);
							$this->runView('_email_sample',array(
								'fmethod' => 'toHTML',

								),null);
		return true;
	}
}
?>