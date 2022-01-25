<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_studies_level,_relevance_rate,_first_name,_last_name,_cv_path,_years_of_practice,_profile,_read_state,_user_read_state,_relevance) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("studies_level","DB","NULL").",".
$record->getFieldValue("relevance_rate","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("cv_path","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("profile","DB","NULL").",".
$record->getFieldValue("read_state","DB","NULL").",".
$record->getFieldValue("user_read_state","DB","NULL").",".
$record->getFieldValue("relevance","DB","NULL").")"; ?>