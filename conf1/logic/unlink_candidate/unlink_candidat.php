<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class unlink_candidate_unlink_candidat extends NxPage
{
	function unlink_candidate_unlink_candidat($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
							$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
							$this->deleteRecords('rct_candidate_vacancy.unlink_candidate@recruitment',$this->getRecords('rct_candidate_vacancy.unlink_candidate@recruitment',null,'db'),'db',true);

				$candidates_oids = explode('|', $this->getProperty("candidate_oid",""));
			

							foreach($candidates_oids as $i=>$value)
							{
								$this->putRecord(
									$_nx_record_data72=array(
											'candidate_oid'=>$value,
											'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
											'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
											'action_oid'=>'15',
											'ref_oid'=>'',
											'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
							}
							header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=associated_candidate&nxs=&oid='.$this->getProperty("vacancy_oid","")));
							nxLog('redirect to '.$u,'redirect');
							return true;

		return true;
	}
}
?>