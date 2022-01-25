<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_client_directory__archive_archive extends NxPage
{
	function recruitment_vacancies_client_directory__archive_archive($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->putRecord($null=null,'rct_vacancy.archive','update','db','Object',null);
					$oids=(isset($_REQUEST["oid"])?$_REQUEST["oid"]:"");

								$oids = explode('|', $oids);
							

					foreach($oids as $i=>$value)
					{
						$this->putRecord(
							$_nx_record_data68=array(
									'candidate_oid'=>$value,
									'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
									'action_oid'=>'2',
									'ref_oid'=>'',
									'additional_infos'=>'',),'rct_vacancy_action.record','insert','db','Object',null);
					}

									$this->setProperty('redirect_url.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/client/directory.php?nxo=list&filterKey='.$_REQUEST['filterKey']);
									$this->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);
								

		return true;
	}
}
?>