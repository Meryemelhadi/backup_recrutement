<?php $properties["query"]="SELECT _oid,_date,_interview_type,_vacancy_oid,_candidate_oid,_interview_by_oid,_validation_state,_interview_feedback,_comment FROM _rct_interview WHERE _candidate_oid=".$this->getFieldParam("candidate_oid","null",",",$record,"")." AND _vacancy_oid=".$this->getFieldParam("vacancy_oid","null",",",$record,"")." AND _interview_by_oid=".$this->getFieldParam("interview_by_oid","null",",",$record,"")." AND _date=".$this->getFieldParam("date","null",",",$record,"")." ORDER BY _name ASC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'15';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>