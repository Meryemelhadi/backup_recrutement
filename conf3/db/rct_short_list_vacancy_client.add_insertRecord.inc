<?php $properties["query"]="INSERT INTO _rct_short_list_vacancy_client(_short_list_oid,_vacancy_oid,_proposed_by,_proposal_date,_comment) VALUES('".$props->getProperty("short_list_oid","",true)."',".
"'".$props->getProperty("vacancy_oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
$record->getFieldValue("comment","DB","NULL").")"; ?>