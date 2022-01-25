<?php $properties["query"]="INSERT INTO _rct_warning(_oid,_vacancy_oid,_scheduled_by,_scheduled_on,_date,_subject,_notification_content,_concerned_people,_notification_state) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
"'".$props->getProperty("vacancy_oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
$record->getFieldValue("date","DB","now+5 days").",".
$record->getFieldValue("subject","DB","NULL").",".
$record->getFieldValue("notification_content","DB","NULL").",".
$record->getFieldValue("concerned_people","DB","NULL").",".
"'0')"; ?>