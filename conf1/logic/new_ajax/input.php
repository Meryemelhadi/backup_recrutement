<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class new_ajax_input extends NxPage
{
	function new_ajax_input($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->getRecord('','','empty',false,null,null);
							$this->setProperty("page_message",$this->getString("page_message_add"));
							$this->setProperty('back.url',$_SERVER["PHP_SELF"].'?nxo=list_description&amp;nxs=&amp;mode=ajax');
							$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo='.$this->getProperty("app.operation","").'&amp;nxs=process');
							$this->runView('_add_description',array(
								'fmethod' => 'toForm',

								),null);
		return true;
	}
}
?>