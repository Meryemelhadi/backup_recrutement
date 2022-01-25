<?php $properties["query"]="SELECT _oid,_index,_name,_profiling_on,_keywords,_not_keywords,_vacancy,_cand_channel,_category_oid,_profile,_provider,_establishment FROM _rct_profiling_rules WHERE ".$this->getWhereClause("_name",$this->getFieldParam("name","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." ORDER BY _index ASC,_name ASC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'20';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>