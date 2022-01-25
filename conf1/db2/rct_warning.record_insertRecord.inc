<?php $properties["query"]="INSERT INTO _rct_warning(_oid,_vacancy_oid,_scheduled_by,_scheduled_on,_date,_concerned_people,_subject,_notification_content,_notification_state) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("scheduled_by","DB","NULL").",".
$record->getFieldValue("scheduled_on","DB","NOW()").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("concerned_people","DB","NULL").",".
$record->getFieldValue("subject","DB","NULL").",".
$record->getFieldValue("notification_content","DB","NULL").",".
$record->getFieldValue("notification_state","DB","NULL").")"; ?>