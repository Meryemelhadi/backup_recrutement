<?php $properties["query"]="SELECT _oid,_creation_date,_candidate_oid,_created_by,_email_type,_email_title FROM _rct_email WHERE _candidate_oid='".$this->getParamValue("coid","","request",",")."' ORDER BY _creation_date DESC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'15';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>