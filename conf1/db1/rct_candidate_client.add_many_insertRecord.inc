<?php $properties["query"]="INSERT INTO _rct_candidate_client(_date,_proposed_by,_proposed_to,_comment,_candidate_oid) VALUES(NOW(),".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
$record->getFieldValue("proposed_to","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").",".
"'".$this->getParamValue("candidates_oid","","request",",")."')"; ?>