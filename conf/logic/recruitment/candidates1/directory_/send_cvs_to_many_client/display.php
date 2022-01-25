<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory__send_cvs_to_many_client_display extends NxPage
{
	function recruitment_candidates_directory__send_cvs_to_many_client_display($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("candidates_oid",(isset($_REQUEST["candidates_oid"])?$_REQUEST["candidates_oid"]:""));
					$this->getRecord('rct_candidate_client.add_many','page.record','empty',false,null,null);
					$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=send_cvs_to_many_client&amp;nxs=process&amp;candidates_oid='.(isset($_REQUEST["candidates_oid"])?$_REQUEST["candidates_oid"]:""));
					$this->runView('/recruitment/candidates/directory__send_cvs_to_client',array(
						'fmethod' => 'toForm',

						),null);
		return true;
	}
}
?>