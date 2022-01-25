<?php $properties["query"]="SELECT _oid,_name,_key FROM _rct_keyword WHERE ".$this->getWhereClause("_name",$this->getFieldParam("name","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." ORDER BY _name ASC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'10';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>