<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_date_of_birth,_town_oid,_mobility_town_oid,_years_of_practice,_keywords,_reading_state,_hr_manager,_cand_channel) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("date_of_birth","DB","NOW()").",".
$record->getFieldValue("town_oid","DB","NULL").",".
$record->getFieldValue("mobility_town_oid","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("keywords","DB","NULL").",".
$record->getFieldValue("reading_state","DB","1").",".
$record->getFieldValue("hr_manager","DB","NULL").",".
$record->getFieldValue("cand_channel","DB","NULL").")"; ?>