<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class list_description_display extends NxPage
{
	function list_description_display($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->getRecords('','','db',false,null,null);
							$this->setProperty('add_ajax.url',$_SERVER["PHP_SELF"].'?nxo=new_ajax&amp;nxs=');
							$this->setProperty('add.url',$_SERVER["PHP_SELF"].'?nxo=new_ajax&amp;nxs=');
							$this->setProperty('delete.url',$_SERVER["PHP_SELF"].'?nxo=delete_description&amp;nxs=');
							$this->setProperty('edit_ajax.url',$_SERVER["PHP_SELF"].'?nxo=edit_ajax&amp;nxs=');
							$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit_ajax&amp;nxs=');
							$this->setProperty('back.url',$_SERVER["PHP_SELF"].'?nxo=announcement_add_internet&amp;nxs=');
							$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=list_description&amp;nxs=&amp;mode=page');
							$this->setProperty('view.url',$_SERVER["PHP_SELF"].'?nxo=details_description&amp;nxs=');
							$this->runView('_list_description_ajax',array(
								'fmethod' => 'toHTML',

								),null);
		return true;
	}
}
?>