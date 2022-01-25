<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_delete_vacancy extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run($workflow,$user)
	{
		$this->setProperty("oid",$_REQUEST['oid']);
		$this->deleteRecords('rct_vacancy.delete',$this->getRecords('rct_vacancy.delete',null,'db'),'db',true);
		$this->deleteRecords('rct_candidate_vacancy.unlink_candidate_poste',$this->getRecords('rct_candidate_vacancy.unlink_candidate_poste',null,'db'),'db',true);
		$this->deleteRecords('rct_vacancy_provider.unlink_provider_poste',$this->getRecords('rct_vacancy_provider.unlink_provider_poste',null,'db'),'db',true);
		
		$this->deleteRecords('rct_vacancy_comment.delete_by_poste',$this->getRecords('rct_vacancy_comment.delete_by_poste',null,'db'),'db',true);
		$this->deleteRecords('rct_short_list.delete_by_poste',$this->getRecords('rct_short_list.delete_by_poste',null,'db'),'db',true);
		$this->deleteRecords('rct_vacancy_action.delete_by_poste',$this->getRecords('rct_vacancy_action.delete_by_poste',null,'db'),'db',true);
		$this->deleteRecords('rct_vacancy_attached_file.delete_by_poste',$this->getRecords('rct_vacancy_attached_file.delete_by_poste',null,'db'),'db',true);
		$this->deleteRecords('rct_vacancy_comment.delete_by_poste',$this->getRecords('rct_vacancy_comment.delete_by_poste',null,'db'),'db',true);
		$this->deleteRecords('rct_vacancy_total_control.delete_by_poste',$this->getRecords('rct_vacancy_total_control.delete_by_poste',null,'db'),'db',true);
		$this->deleteRecords('rct_vacancy_readonly.delete_by_poste',$this->getRecords('rct_vacancy_readonly.delete_by_poste',null,'db'),'db',true);
		$this->deleteRecords('rct_vacancy_history.delete_by_poste',$this->getRecords('rct_vacancy_history.delete_by_poste',null,'db'),'db',true);
		
		
		//header('Location:'.($u=PORTAL_URL_PREFIX .$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=list&nxs=&mode=ajax'));
		$url = PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php'; 
		$this->setProperty('redirect_url.url',$url);
		$this->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);
		
		return true;
		
	}
}
?>