<?php $properties["query"]="SELECT _oid,_name FROM _rct_saved_search WHERE ".$this->getWhereClause("_name",$this->getFieldParam("name","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND _user_oid='".$GLOBALS["_NX_user"]->getProperty("oid","",true)."' ORDER BY _name ASC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'15';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>