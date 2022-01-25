<?php $properties["query"]="SELECT _oid,_name FROM _rct_candidate_category WHERE (".$this->getWhereClause("_name",$this->getFieldParam("name","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." OR ".$this->getWhereClause("_name","'".$props->getProperty("input","",true)."'",'LIKE','OR','%','%',true,false,'|','false')." OR ".$this->getWhereClause("_name","'".$props->getProperty("input2","",true)."'",'LIKE','OR','%','%',true,false,'|','false').")  ORDER BY _name ASC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'50';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>