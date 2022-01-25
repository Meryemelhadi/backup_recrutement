<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_studies_level,_first_name,_last_name,_cv_path,_years_of_practice,_profile,_reading_state,_relevance,_candidate_client_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("studies_level","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("cv_path","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("profile","DB","NULL").",".
$record->getFieldValue("reading_state","DB","1").",".
$record->getFieldValue("relevance","DB","NULL").",".
$record->getFieldValue("candidate_client_oid","DB","NULL").")"; ?>