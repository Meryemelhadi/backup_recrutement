<?php $properties["query"]="SELECT _oid,_country_name FROM _directory_country WHERE ".$this->getWhereClause("_country_name",$this->getFieldParam("country_name","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." GROUP BY _country_name  ORDER BY _country_name ASC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'10';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>