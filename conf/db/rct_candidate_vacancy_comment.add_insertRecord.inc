<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy_comment(_vacancy_oid,_candidate_oid,_user_oid,_date,_comment) VALUES('".$props->getProperty("vacancy_oid","",true)."',".
"'".$props->getProperty("candidate_oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
$record->getFieldValue("comment","DB","NULL").")"; ?>