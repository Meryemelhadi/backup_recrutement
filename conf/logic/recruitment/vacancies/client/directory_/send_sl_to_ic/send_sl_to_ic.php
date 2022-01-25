<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_client_directory__send_sl_to_ic_send_sl_to_ic extends NxPage
{
	function recruitment_vacancies_client_directory__send_sl_to_ic_send_sl_to_ic($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$this->setProperty("short_list_oid",(isset($_REQUEST["short_list_oid"])?$_REQUEST["short_list_oid"]:""));
					$this->setProperty('previous_operation.url',$_SERVER["PHP_SELF"].'?nxo=candidates&amp;nxs=&amp;oid='.$this->getProperty("vacancy_oid",""));
					$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=send_sl_to_ic_process&amp;nxs=&amp;vacancy_oid='.$this->getProperty("vacancy_oid","").'&amp;short_list_oid='.$this->getProperty("short_list_oid",""));
					$this->getRecord('rct_short_list_vacancy_client.add@recruitment','page.record','empty',false,null,null);
					$this->setProperty("vacancy_oid",$this->getProperty("vacancy_oid",""));
					$this->setProperty("progress_level",'5');
					$this->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
					$cRecord=
						$this->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
					$progress_level=
						$cRecord->getProperty('progress_level','',false,'object','');
					$progress_level_meta=
						$cRecord->getProperty('progress_level_meta','',false,'html','');
					$this->putRecord(
						$_nx_record_data16=array(
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'progress_level'=>$this->getProperty("progress_level",""),
								'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
					header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=candidates&nxs=&oid='.$this->getProperty("vacancy_oid","")));
					nxLog('redirect to '.$u,'redirect');
					return true;

		return true;
	}
}
?>