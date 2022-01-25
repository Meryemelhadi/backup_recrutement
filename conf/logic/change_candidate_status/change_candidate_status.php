<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class change_candidate_status_change_candidate_status extends NxPage
{
	function change_candidate_status_change_candidate_status($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
							$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));
							$this->setProperty("status_value",(isset($_REQUEST["status_value"])?$_REQUEST["status_value"]:""));
							$this->putRecord($null=null,'rct_candidate_vacancy.change_status@recruitment','update','db','Object',null);
								if($this->getProperty("status_value","") == '5')
								{
									$this->setProperty("acceptance_status",'1');
									$this->putRecord($null=null,'rct_candidate_vacancy.change_ci_acceptance@recruitment','update','db','Object',null);
								}
								elseif($this->getProperty("status_value","") == '6')
								{
									$this->setProperty("acceptance_status",'2');
									$this->putRecord($null=null,'rct_candidate_vacancy.change_ci_acceptance@recruitment','update','db','Object',null);
								}
								elseif($this->getProperty("status_value","") == '7')
								{
									$this->setProperty("acceptance_status",'1');
									$this->putRecord($null=null,'rct_candidate_vacancy.change_job_acceptance@recruitment','update','db','Object',null);
								}
								elseif($this->getProperty("status_value","") == '8')
								{
									$this->setProperty("acceptance_status",'0');
									$this->putRecord($null=null,'rct_candidate_vacancy.change_job_acceptance@recruitment','update','db','Object',null);
								}
								elseif($this->getProperty("status_value","") == '18')
								{
									$this->setProperty("acceptance_status",'2');
									$this->putRecord($null=null,'rct_candidate_vacancy.change_job_acceptance@recruitment','update','db','Object',null);
								}
							$this->putRecord($null=null,'rct_vacancy.close_vacancy@recruitment','update','db','Object',null);

				$candidates_oids = explode('|', $this->getProperty("candidate_oid",""));
			

							foreach($candidates_oids as $i=>$value)
							{
								$this->putRecord(
									$_nx_record_data67=array(
											'candidate_oid'=>$value,
											'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
											'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
											'action_oid'=>(isset($_REQUEST["status_value"])?$_REQUEST["status_value"]:""),
											'ref_oid'=>'',
											'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
							}
							if($this->getProperty("status_value","") == '7')
							{
								$this->setProperty("vacancy_oid",$this->getProperty("vacancy_oid",""));
								$this->setProperty("progress_level",'9');
								$this->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
								$cRecord=
									$this->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
								$progress_level=
									$cRecord->getProperty('progress_level','',false,'object','');
								$progress_level_meta=
									$cRecord->getProperty('progress_level_meta','',false,'html','');
								$this->putRecord(
									$_nx_record_data68=array(
											'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
											'progress_level'=>$this->getProperty("progress_level",""),
											'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
							}
							if($this->getProperty("status_value","") == '18')
							{
								$this->setProperty("vacancy_oid",$this->getProperty("vacancy_oid",""));
								$this->setProperty("progress_level",'10');
								$this->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
								$cRecord=
									$this->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
								$progress_level=
									$cRecord->getProperty('progress_level','',false,'object','');
								$progress_level_meta=
									$cRecord->getProperty('progress_level_meta','',false,'html','');
								$this->putRecord(
									$_nx_record_data69=array(
											'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
											'progress_level'=>$this->getProperty("progress_level",""),
											'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
							}
							header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=candidates&nxs=&oid='.$this->getProperty("vacancy_oid","")));
							nxLog('redirect to '.$u,'redirect');
							return true;

		return true;
	}
}
?>