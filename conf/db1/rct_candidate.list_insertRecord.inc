<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_date_of_birth,_town_oid,_years_of_practice,_keywords,_reading_state) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("date_of_birth","DB","NOW()").",".
$record->getFieldValue("town_oid","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("keywords","DB","NULL").",".
$record->getFieldValue("reading_state","DB","1").")"; ?>