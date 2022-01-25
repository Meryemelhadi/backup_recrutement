<?php $properties["query"]="SELECT _oid,_name,_is_default FROM _rct_search_params WHERE ".$this->getWhereClause("_name",$this->getFieldParam("name","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND ".$this->getWhereClause("_is_default",$this->getFieldParam("is_default","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." ORDER BY _name ASC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'15';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>