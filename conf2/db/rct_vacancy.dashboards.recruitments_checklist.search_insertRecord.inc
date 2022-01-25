<?php $properties["query"]="INSERT INTO _rct_vacancy(_name,_instant_feedback,_delayed_feedback,_opening_date_start,_opening_date_end,_closing_date_start,_closing_date_end,_announcement,_contract_type_oid,_category_oid,_application_type,_current_step) VALUES(".$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("instant_feedback","DB","NULL").",".
$record->getFieldValue("delayed_feedback","DB","NULL").",".
$record->getFieldValue("opening_date_start","DB","NOW()").",".
$record->getFieldValue("opening_date_end","DB","NOW()").",".
$record->getFieldValue("closing_date_start","DB","NOW()").",".
$record->getFieldValue("closing_date_end","DB","NOW()").",".
$record->getFieldValue("announcement","DB","NULL").",".
$record->getFieldValue("contract_type_oid","DB","NULL").",".
$record->getFieldValue("category_oid","DB","NULL").",".
$record->getFieldValue("application_type","DB","NULL").",".
$record->getFieldValue("current_step","DB","NULL").")"; ?>