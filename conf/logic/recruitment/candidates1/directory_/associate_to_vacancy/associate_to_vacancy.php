<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_candidates_directory__associate_to_vacancy_associate_to_vacancy extends NxPage
{
	function recruitment_candidates_directory__associate_to_vacancy_associate_to_vacancy($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->putRecord($null=null,'rct_candidate_vacancy.add_assoc@recruitment','insert','db','Object',null);
					$this->putRecord(
						$_nx_record_data4=array(
								'candidate_oid'=>$this->getProperty("candidate_oid",""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'3',
								'ref_oid'=>$this->getProperty("vacancy_oid",""),
								'additional_infos'=>'',),'rct_candidate_action.record@recruitment','insert','db','Object',null);
					$this->putRecord(
						$_nx_record_data5=array(
								'candidate_oid'=>$this->getProperty("candidate_oid",""),
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'0',
								'ref_oid'=>'',
								'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
					$this->setProperty("application_type",'0');
					$this->putRecord($null=null,'rct_vacancy.change_application_type@recruitment','update','db','Object',null);
					$this->getRecord('rct_candidate_vacancy.get_assoc@recruitment','page.record','db',false,null,null);
					$this->runView('/recruitment/candidates/directory__vacancy_assoc',array(
						'fmethod' => 'toHTML',

						),null);
					$this->setProperty("vacancy_oid",$this->getProperty("vacancy_oid",""));
					$this->setProperty("progress_level",'3');
					$this->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
					$cRecord=
						$this->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
					$progress_level=
						$cRecord->getProperty('progress_level','',false,'object','');
					$progress_level_meta=
						$cRecord->getProperty('progress_level_meta','',false,'html','');
					$this->putRecord(
						$_nx_record_data6=array(
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'progress_level'=>$this->getProperty("progress_level",""),
								'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
		return true;
	}
}
?>