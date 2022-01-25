<?php $properties["query"]="SELECT _oid,_candidate_oid,_date,_email_from_name,_email_from,_email_title,_email_content,_cv,_lm FROM _rct_candidate_email WHERE _candidate_oid='".$this->getParamValue("oid","","request",",")."' ORDER BY _date DESC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'50';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>