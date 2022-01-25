<?php $properties["query"]="SELECT _oid,_date_of_birth,_town_oid,_years_of_practice,_keywords,_reading_state FROM _rct_candidate";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'10';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>