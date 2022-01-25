<?php $properties["query"]="INSERT INTO _rct_candidate_comment(_candidate_oid,_user_oid,_date,_comment,_type_comment) VALUES('".$this->getParamValue("oid","","request",",")."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
$record->getFieldValue("comment","DB","NULL").",".
"'1')"; ?>