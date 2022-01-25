<?php $properties["query"]="INSERT INTO _rct_candidate(_current_state,_years_of_practice,_application_type,_town_oid,_short_list_oid) VALUES(".$record->getFieldValue("current_state","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("application_type","DB","NULL").",".
$record->getFieldValue("town_oid","DB","NULL").",".
$record->getFieldValue("short_list_oid","DB","NULL").")"; ?>