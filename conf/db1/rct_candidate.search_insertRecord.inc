<?php $properties["query"]="INSERT INTO _rct_candidate(_first_name,_last_name,_gender,_town_oid,_diploma,_school,_studies_level,_years_of_practice,_profile,_relevance,_category_oid,_archive_state,_sort_by,_update_date_min,_update_date_max) VALUES(".$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("gender","DB","NULL").",".
$record->getFieldValue("town_oid","DB","NULL").",".
$record->getFieldValue("diploma","DB","NULL").",".
$record->getFieldValue("school","DB","NULL").",".
$record->getFieldValue("studies_level","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("profile","DB","NULL").",".
"'".$this->getParamValue("relevance","3","request",",")."',".
$record->getFieldValue("category_oid","DB","NULL").",".
"'".$this->getParamValue("archive_state","0","request",",")."',".
$record->getFieldValue("sort_by","DB","NULL").",".
$record->getFieldValue("update_date_min","DB","NOW()").",".
$record->getFieldValue("update_date_max","DB","NOW()").")"; ?>