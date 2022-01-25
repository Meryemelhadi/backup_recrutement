<?php $properties["query"]="INSERT INTO _rct_vacancy_comment(_vacancy_oid,_user_oid,_date,_comment) VALUES('".$this->getParamValue("oid","","request",",")."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
$record->getFieldValue("comment","DB","NULL").")"; ?>