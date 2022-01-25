<?php $properties["query"]="SELECT _oid,_code,_label FROM _rct_school ORDER BY _label ASC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+$this->getProperty("newsletter.users.nbRecordsPerPage","30");
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>