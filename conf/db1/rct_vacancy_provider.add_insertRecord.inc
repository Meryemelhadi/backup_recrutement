<?php $properties["query"]="INSERT INTO _rct_vacancy_provider(_provider_oid,_vacancy_oid,_requested_by,_request_date,_email_title,_email_content) VALUES(".$record->getFieldValue("provider_oid","DB","NULL").",".
"'".$props->getProperty("vacancy_oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").")"; ?>