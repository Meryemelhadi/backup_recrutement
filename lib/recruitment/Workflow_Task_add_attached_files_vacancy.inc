<?php
require_once(NX_LIB.'module/NxPage.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/vacancies/services/log.inc');

class Workflow_Task_add_attached_files_vacancy extends NxPage
{
    function __construct($ctxt,$params,$taskID)
    {
        $this->NxPage($params,$ctxt,null);
        $this->ctxt = $this;
    }

    function run($workflow,$user)
    {
		//$this->ctxt->setProperty('vacancy_oid' , $_REQUEST['oid']);
        $this->putRecord($this->getRecord('rct_vacancy_attached_file.record@recruitment','page.record','request',false,null,null),'rct_vacancy_attached_file.record@recruitment','insert','db','Object',null);
        //Add log
		$log= new lib_recruitment_vacancies_services_log($this->ctxt);
        $log->addLog((isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:"") , $GLOBALS["_NX_user"]->getProperty("oid",""), 2 , '' , '(Ajout de Fichier attaché)');
		
        /*$this->putRecord(
				$_nx_record_data28=array(
						'vacancy_oid'=>(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""),
						'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
						'action_oid'=>'2',
						'ref_oid'=>'',
						'additional_infos'=>'(Ajout de Fichier attaché)',),'rct_vacancy_action.record','insert','db','Object',null);*/

		header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=edit&nxs=&mode=page&oid='.$_REQUEST['vacancy_oid']));
        nxLog('redirect to '.$u,'redirect');
        return true;
    }

}

?>