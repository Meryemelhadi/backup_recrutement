<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_candidates_directory__add_process extends NxPage
{
	function recruitment_candidates_directory__add_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$candidateOid=
						(($__o=$this->getHandler('lib.recruitment.candidates.services.directory','')) ? $__o->saveNewCV() : null);
					$this->putRecord(
						$_nx_record_data1=array(
								'candidate_oid'=>$candidateOid,
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'0',
								'ref_oid'=>'',
								'additional_infos'=>'',),'rct_candidate_action.record','insert','db','Object',null);
					(($__o=$this->getHandler('lib.recruitment.candidates.services.denormalisation','')) ? $__o->partial($candidateOid) : null);
					$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$candidateOid.'&amp;filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"")));
					$this->runView('/recruitment/candidates/directory__redirect',array(
						'fmethod' => 'toHTML',

						),null);
		return true;
	}
}
?>