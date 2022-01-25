<?php $properties["query"]="SELECT _oid,_candidate_oid,_file FROM _rct_candidate_files WHERE _candidate_oid='".$this->getParamValue("oid","","request",",")."'";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'50';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>