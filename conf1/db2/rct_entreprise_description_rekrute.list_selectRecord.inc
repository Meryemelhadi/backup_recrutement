<?php $properties["query"]="SELECT _oid,_name_description FROM _rct_entreprise_description_rekrute WHERE ".$this->getWhereClause("_name_description",$this->getFieldParam("name_description","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false');
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'10';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>