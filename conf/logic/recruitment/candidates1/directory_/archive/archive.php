<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_candidates_directory__archive_archive extends NxPage
{
	function recruitment_candidates_directory__archive_archive($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->putRecord($null=null,'rct_candidate.archive','update','db','Object',null);
					$oids=(isset($_REQUEST["oid"])?$_REQUEST["oid"]:"");

								$oids = explode('|', $oids);
							

					foreach($oids as $i=>$value)
					{
						$this->putRecord(
							$_nx_record_data11=array(
									'candidate_oid'=>$value,
									'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
									'action_oid'=>'2',
									'ref_oid'=>'',
									'additional_infos'=>'',),'rct_candidate_action.record','insert','db','Object',null);
					}
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=list&nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&mode=ajax'));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>