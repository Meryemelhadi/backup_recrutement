<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class add_email_process_add_email_process extends NxPage
{
	function add_email_process_add_email_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
							$this->setProperty("candidate_oid",(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""));

				$candidates_oids = explode('|', $this->getProperty("candidate_oid",""));
				$lastOids = array();
			

							$action_oid='3';
							if((isset($_REQUEST["email_type"])?$_REQUEST["email_type"]:"") == '2')
							{
								$action_oid='9';
							}
							foreach($candidates_oids as $i=>$value)
							{
								$this->setProperty("candidate_oid",$value);
								$this->putRecord(
									$this->getRecord('rct_email.add@recruitment','page.record','post',false,null,null),'rct_email.add@recruitment','insert','db','Object',null);
								$lastOid=
									$this->getLastInsertID('db');

					$lastOids[] = array($lastOid, $value);
				

								$this->putRecord(
									$_nx_record_data85=array(
											'candidate_oid'=>$this->getProperty("candidate_oid",""),
											'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
											'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
											'action_oid'=>$action_oid,
											'ref_oid'=>$lastOid,
											'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
							}
							$path='emails';
							$handler='rct_email_attached_file.add_record@recruitment';
							($tmp=
								(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->uploadNCopy($lastOids,$handler,$path) : null))!=null?$this->addProperties($tmp):null;
							(($__o=$this->getHandler('lib.recruitment.vacancies.services.message','')) ? $__o->sendEmail($lastOids) : null);
							if((isset($_REQUEST["email_type"])?$_REQUEST["email_type"]:"") == '2')
							{
								$this->setProperty("vacancy_oid",$this->getProperty("vacancy_oid",""));
								$this->setProperty("progress_level",'11');
								$this->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
								$cRecord=
									$this->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
								$progress_level=
									$cRecord->getProperty('progress_level','',false,'object','');
								$progress_level_meta=
									$cRecord->getProperty('progress_level_meta','',false,'html','');
								$this->putRecord(
									$_nx_record_data86=array(
											'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
											'progress_level'=>$this->getProperty("progress_level",""),
											'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
							}
		return true;
	}
}
?>