<?php $properties["query"]="SELECT _oid,_logo,_nom_societe,_tel,_fax,_email,_site_web,_rep_first_name,_rep_last_name,_rep_fonction,_rep_tel_fixe,_rep_tel_mobile,_rep_fax,_rep_email,_adresse,_ville FROM _rct_client WHERE _oid='".$this->getParamValue("oid","","request",",")."'";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'10';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>