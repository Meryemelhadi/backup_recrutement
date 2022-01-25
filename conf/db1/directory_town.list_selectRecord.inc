<?php $properties["query"]="SELECT _oid,_town_name,_country_oid FROM _directory_town WHERE ".$this->getWhereClause("_town_name",$this->getFieldParam("town_name","null","|",$record,""),'LIKE','OR','%','%',true,false,'|')." ORDER BY _town_name ASC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'10';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>