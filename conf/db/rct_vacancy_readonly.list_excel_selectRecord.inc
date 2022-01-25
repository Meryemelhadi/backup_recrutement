<?php $properties["query"]="SELECT _rct_vacancy_readonly._oid AS rct_vacancy_readonly_oid,_rct_vacancy_readonly._name AS rct_vacancy_readonly_name,_rct_vacancy_readonly._number AS rct_vacancy_readonly_number,_rct_vacancy_readonly._code AS rct_vacancy_readonly_code,_rct_vacancy_readonly._category_oid AS rct_vacancy_readonly_category_oid,_rct_vacancy_readonly._contract_type_oid AS rct_vacancy_readonly_contract_type_oid,_rct_vacancy_readonly._subsidiary_oid AS rct_vacancy_readonly_subsidiary_oid,_rct_vacancy_readonly._establishment AS rct_vacancy_readonly_establishment,_rct_vacancy_readonly._service_oid AS rct_vacancy_readonly_service_oid,_rct_vacancy_readonly._duty_station_oid AS rct_vacancy_readonly_duty_station_oid,_rct_vacancy_readonly._current_step AS rct_vacancy_readonly_current_step,_rct_vacancy_readonly._progress_level AS rct_vacancy_readonly_progress_level,_rct_vacancy_readonly._application_type AS rct_vacancy_readonly_application_type,_rct_vacancy_readonly._opening_date AS rct_vacancy_readonly_opening_date,_rct_vacancy_readonly._closing_date AS rct_vacancy_readonly_closing_date,_rct_vacancy_readonly._creator AS rct_vacancy_readonly_creator FROM _rct_vacancy_readonly,_rct_vacancy,_rct_vacancy_total_control WHERE ((_rct_vacancy._creator='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."')  OR (_rct_vacancy_total_control._key=_rct_vacancy._oid AND _rct_vacancy_total_control._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."')  OR (_rct_vacancy_readonly._key=_rct_vacancy._oid AND _rct_vacancy_readonly._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."') )  AND ".$this->getWhereClause("_rct_vacancy_readonly._name",$this->getFieldParam("name","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND ".$this->getWhereClause("_rct_vacancy_readonly._code",$this->getFieldParam("code","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND ".$this->getWhereClause("_rct_vacancy_readonly._category_oid",$this->getFieldParam("category_oid","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND ".$this->getWhereClause("_rct_vacancy_readonly._subsidiary_oid",$this->getFieldParam("subsidiary_oid","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND ".$this->getWhereClause("_rct_vacancy_readonly._service_oid",$this->getFieldParam("service_oid","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND ".$this->getWhereClause("_rct_vacancy_readonly._duty_station_oid",$this->getFieldParam("duty_station_oid","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND ".$this->getWhereClause("_rct_vacancy_readonly._current_step",$this->getFieldParam("current_step","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND ".$this->getWhereClause("_rct_vacancy_readonly._progress_level",$this->getFieldParam("progress_level","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND ".$this->getWhereClause("_rct_vacancy_readonly._application_type",$this->getFieldParam("application_type","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND ".$this->getWhereClause("_rct_vacancy_readonly._opening_date",$this->getFieldParam("opening_date","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND ".$this->getWhereClause("_rct_vacancy_readonly._closing_date",$this->getFieldParam("closing_date","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND _rct_vacancy_readonly._workflow_state='2' AND ".$this->getWhereClause("_rct_vacancy_readonly._archive_state",$this->getFieldParam("archive_state","null","|",$record,""),'=','OR','','',true,false,'|','false')." GROUP BY _rct_vacancy_readonly._oid  ORDER BY _rct_vacancy_readonly._name ASC,_rct_vacancy_readonly._code ASC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'20';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>