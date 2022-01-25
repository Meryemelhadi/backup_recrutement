<?php

require_once(NX_LIB.'module/NxPage.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/vacancies/services/log.inc');

class Workflow_Task_edit_process_vacancy extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run()
	{
	
		$o = $this->getRecord('rct_vacancy.edit_'.$this->getProperty("recruitement_profile","default"),'page.record','post',false,null,null);
		$modifiedFields = $this->getModifiedFields($o);
		$this->putRecord(
			$o,'rct_vacancy.edit_'.$this->getProperty("recruitement_profile","default"),'update','db','Object',null);

		$path='vacancies/directory';

		$handler='rct_vacancy_attached_file.add_record';
		($tmp=
			(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->uploadFiles((isset($_REQUEST["oid"])?$_REQUEST["oid"]:""),$handler,$path) : null))!=null?$this->addProperties($tmp):null;

		$handler='rct_vacancy_attached_file.get_record';
		($tmp=
			(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->removeFiles((isset($_REQUEST["oid"])?$_REQUEST["oid"]:""),$handler,$path) : null))!=null?$this->addProperties($tmp):null;

			
		//Add log
        $log= new lib_recruitment_vacancies_services_log($this->ctxt);
        $log->addLog((isset($_REQUEST["oid"])?$_REQUEST["oid"]:"") , $GLOBALS["_NX_user"]->getProperty("oid",""), 2 , '' , '('.$modifiedFields.')');
		
		/*$this->putRecord(
			$_nx_record_data28=array(
					'vacancy_oid'=>(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""),
					'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
					'action_oid'=>'2',
					'ref_oid'=>'',
					'additional_infos'=>'('.$modifiedFields.')',),'rct_vacancy_action.record','insert','db','Object',null);*/
					
		$vacancy_oid = (isset($_REQUEST["void"])?$_REQUEST["void"]:"");
        if($vacancy_oid == "")
            $vacancy_oid = (isset($_REQUEST["oid"])?$_REQUEST["oid"]:"");
        header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=edit&void='.$vacancy_oid.'&oid='.$vacancy_oid.'&mode=ajax&modepage=minimal'));			

		return true;
	}
	
	function getModifiedFields($o){
		$o2 = $this->getRecord('rct_vacancy.edit_'.$this->getProperty("recruitement_profile","default"),'page.record','db',false,null,null);
	    foreach($o2->fields as $fname=>$field2)
		{
            if($field2->desc->type == 'records' || $field2->desc->props['is_transient']){ 
                continue;
            }
			// new value
			$v2 = $field2->value;

			// old value
			$field1 = $o->$fname;
			$v1 = ($field2->desc->type == 'text_choice' && ($field1->string == '' || $field1->string == '?'))?0:$field1->value;
			
			if($v1 != $v2)
				$changes_arr[$fname]=$field1;
	    }
		

        $changedFields='';
		

		if(!empty($changes_arr)){
		
			foreach($changes_arr as $name=>$field)
		    {
				//FY
				$flabel=$field->desc->label;
				if($changedFields)
					$changedFields=$changedFields.",".$flabel;
				else
					$changedFields=$flabel;
			}
		
		}
		return $changedFields;

	
	}
}
?>