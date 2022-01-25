<?php $properties["query"]="SELECT _oid,_name,_url,_key,_comment,_auth_type FROM _rct_services_web WHERE ".$this->getWhereClause("_name",$this->getFieldParam("name","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND ".$this->getWhereClause("_url",$this->getFieldParam("url","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND ".$this->getWhereClause("_identifiant",$this->getFieldParam("identifiant","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND ".$this->getWhereClause("_key",$this->getFieldParam("key","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." ORDER BY _name ASC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'15';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>