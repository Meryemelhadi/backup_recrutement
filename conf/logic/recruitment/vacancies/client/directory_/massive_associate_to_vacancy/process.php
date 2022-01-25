<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_client_directory__massive_associate_to_vacancy_process extends NxPage
{
	function recruitment_vacancies_client_directory__massive_associate_to_vacancy_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$candidates_oids=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->saveAssociations((isset($_REQUEST["candidates_oid"])?$_REQUEST["candidates_oid"]:""),(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:"")) : null);
					if(count($candidates_oids) > 0)
					{
						$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
						$this->setProperty("application_type",'0');
						$this->putRecord($null=null,'rct_vacancy.change_application_type@recruitment','update','db','Object',null);
					}
					foreach($candidates_oids as $i=>$value)
					{
						$this->putRecord(
							$_nx_record_data65=array(
									'candidate_oid'=>$value,
									'vacancy_oid'=>(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""),
									'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
									'action_oid'=>'0',
									'ref_oid'=>'',
									'additional_infos'=>'',),'rct_candidate_vacancy_action.record@recruitment','insert','db','Object',null);
					}
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("progress_level",'3');
					$this->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
					$cRecord=
						$this->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
					$progress_level=
						$cRecord->getProperty('progress_level','',false,'object','');
					$progress_level_meta=
						$cRecord->getProperty('progress_level_meta','',false,'html','');
					$this->putRecord(
						$_nx_record_data66=array(
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'progress_level'=>$this->getProperty("progress_level",""),
								'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=list&nxs='.preg_replace(array('%&amp;%','%[+]%'),array('&','%2B'),urldecode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""))).'&mode=ajax'));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>