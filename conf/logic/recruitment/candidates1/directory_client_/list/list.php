<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_candidates_directory_client__list_list extends NxPage
{
	function recruitment_candidates_directory_client__list_list($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->getRecords('rct_candidate_client.user_list','page.records','db',false,null,null);
					$this->setProperty('preview_cv.url',$_SERVER["PHP_SELF"].'?nxo=preview_cv&amp;nxs=&amp;type=cv');
					$this->setProperty('candidate_details.url',$_SERVER["PHP_SELF"].'?nxo=candidate_details&amp;nxs=');
					$viewMode='page';
					if(in_array((isset($_GET["mode"])?$_GET["mode"]:""),array('page','ajax')))
					{
						$viewMode=(isset($_GET["mode"])?$_GET["mode"]:"");
					}
						if($viewMode == 'page')
						{
							$this->runView('/recruitment/candidates/directory_client__list',array(
								'fmethod' => 'toHTML',

								),null);
						}
						else {
							$this->runView('/recruitment/candidates/directory_client__list_ajax',array(
								'fmethod' => 'toHTML',

								),null);
						}
		return true;
	}
}
?>