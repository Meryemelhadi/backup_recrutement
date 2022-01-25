<?php $properties["query"]="INSERT INTO _rct_warning(_oid,_vacancy_oid,_scheduled_by,_scheduled_on,_date,_subject,_notification_content,_concerned_people) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("scheduled_by","DB","NULL").",".
$record->getFieldValue("scheduled_on","DB","NOW()").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("subject","DB","NULL").",".
$record->getFieldValue("notification_content","DB","NULL").",".
$record->getFieldValue("concerned_people","DB","NULL").")"; ?>