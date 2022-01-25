<?php $properties["query"]="SELECT _oid,_town_name,_country_oid,_cp FROM _directory_town WHERE _country_oid in('".$props->getProperty("portal.recruitement.country","",true)."') AND ".$this->getWhereClause("_town_name","'".$this->getParamValue("keyword","","request","|")."'",'LIKE','OR','%','%',true,false,'|','false')." ORDER BY _town_name ASC ";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'10';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>