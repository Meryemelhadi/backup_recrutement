<?php $properties["query"]="INSERT INTO _rct_interview_comment(_interview_oid,_user_oid,_date,_comment) VALUES('".$this->getParamValue("oid","","request",",")."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
$record->getFieldValue("comment","DB","NULL").")"; ?>