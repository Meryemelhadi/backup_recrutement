<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/vacancies/services/log.inc');

class Workflow_Task_vacancy_add_process extends NxPage
{
    function __construct($ctxt,$params,$taskID)
    {
        $this->NxPage($params,$ctxt,null);
    }

	

	/*function run()
	{
							$this->putRecord(
								$this->getRecord('','page.record','post',false,null,null),'','insert','db','Object',null);
							$last_oid_record=
								$this->getRecord('','page.record','db',false,null,null);
							$this->setProperty("lastInsertId",
								$last_oid_record->getProperty('oid','',false,'object',''));
							$this->setProperty("redirect",(isset($_REQUEST["redirect"])?$_REQUEST["redirect"]:""));
							$this->setProperty('redirect_url.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=edit&amp;nxs=&amp;oid='.$this->getProperty("lastInsertId",""));
							$this->putRecord(
								$_nx_record_data51=array(
										'vacancy_oid'=>$this->getProperty("lastInsertId",""),
										'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
										'action_oid'=>'0',
										'ref_oid'=>'',
										'additional_infos'=>'',),'rct_vacancy_action.record@recruitment','insert','db','Object',null);
							$this->runView('_redirect',array(
								'fmethod' => 'toHTML',

								),null);
		return true;
	}*/

    function run()
    {
        //Empty manager
        $_POST['manager_oid'] = $GLOBALS["_NX_user"]->getProperty("oid","");
        $this->putRecord($this->getRecord('rct_vacancy.add_'.$this->getProperty("recruitement_profile","default").'@recruitment','page.record','post',false,null,null),'rct_vacancy.add_'.$this->getProperty("recruitement_profile","default").'@recruitment','insert','db','Object',null);
        $last_oid_record= $this->getRecord('rct_vacancy.max_oid@recruitment','page.record','db',false,null,null);
        $this->setProperty("lastInsertId", $last_oid_record->getProperty('oid','',false,'object',''));
		//Generate email
		$oid = $last_oid_record->getProperty('oid','',false,'object','');
        $suffix='';

        $code_client = $this->getProperty('recruitment.code_client');
        if(!$code_client)
        {
			$a = explode('.',strtolower($_SERVER['SERVER_NAME']));
			if($a[1]=='presencesoft'||$a[1]=='presencerecrute')
				$code_client = $a[0];
			else
				$code_client = $a[1];
        }

        if($code_client)
        {
			$year = '15';
			$oidpad = str_pad($oid, 3, '0', STR_PAD_LEFT);
			$check = ($year * $oid)%100;
			if($check < 10){
				$check = '0'.$check;
			}
			$email = $code_client.'_'.$year.$oidpad.$check.$suffix.'@pourcandidature.com';
        }
        else $email = '';
		$_POST['email'] = $email;
		$_POST['oid'] = $oid;
		$this->putRecord($this->getRecord('rct_vacancy.edit_email@recruitment','','post',false,null,null),'rct_vacancy.edit_email@recruitment','update','db','Object',null);
		
		
        $this->setProperty("redirect",(isset($_REQUEST["redirect"])?$_REQUEST["redirect"]:""));
        $this->setProperty('redirect_url.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$this->getProperty("lastInsertId","").'/directory.php?nxo=edit&amp;nxs=&mode=page&oid='.$this->getProperty("lastInsertId",""));
		
		//Add log
        $log= new lib_recruitment_vacancies_services_log($this->ctxt);
        $log->addLog($this->getProperty("lastInsertId","") , $GLOBALS["_NX_user"]->getProperty("oid",""), 0 , '' , '');
		
        /*$this->putRecord(
            $_nx_record_data51=array(
                'vacancy_oid'=>$this->getProperty("lastInsertId",""),
                'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
                'action_oid'=>'0',
                'ref_oid'=>'',
                'additional_infos'=>'',),'rct_vacancy_action.record@recruitment','insert','db','Object',null);*/
		
        //$this->runView('/recruitment/vacancies/admin/directory__redirect@recruitment',array('fmethod' => 'toHTML',),null);
		$this->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);
        return true;
    }
}
?>