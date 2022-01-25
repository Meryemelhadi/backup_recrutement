<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class recruitment_vacancies_admin_directory__delete_attached_file_process extends NxPage
{
	function recruitment_vacancies_admin_directory__delete_attached_file_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
					$this->deleteRecords('rct_vacancy_attached_file.get_record',$this->getRecords('rct_vacancy_attached_file.get_record',null,'db'),'db',true);

								$this->putRecord(
									$_nx_record_data28=array(
											'vacancy_oid'=>(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""),
											'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
											'action_oid'=>'2',
											'ref_oid'=>'',
											'additional_infos'=>'(Suppression de fichier attaché)',),'rct_vacancy_action.record','insert','db','Object',null);
											
							

		return true;
	}
}
?>