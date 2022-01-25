<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_client_directory__associate_to_vacancy_associate_to_vacancy extends NxPage
{
	function recruitment_vacancies_client_directory__associate_to_vacancy_associate_to_vacancy($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					<card_lib:associate_to_vacancy/>
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
						$_nx_record_data1=array(
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'progress_level'=>$this->getProperty("progress_level",""),
								'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);
		return true;
	}
}
?>