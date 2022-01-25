<?php $properties["query"]="INSERT INTO _rct_candidate(_first_name,_last_name,_gender,_town_oid,_diploma,_school,_studies_level,_years_of_practice,_available_from,_profile,_archive_state,_relevance,_category_oid,_etat_oid,_provider,_update_date_min,_update_date_max,_sort_by,_read_by,_hr_manager,_cand_channel,_establishment) VALUES(".$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("gender","DB","NULL").",".
$record->getFieldValue("town_oid","DB","NULL").",".
$record->getFieldValue("diploma","DB","NULL").",".
$record->getFieldValue("school","DB","NULL").",".
$record->getFieldValue("studies_level","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("available_from","DB","NOW()").",".
$record->getFieldValue("profile","DB","NULL").",".
"'".$this->getParamValue("archive_state","0","request",",")."',".
"'".$this->getParamValue("relevance","-1","request",",")."',".
$record->getFieldValue("category_oid","DB","NULL").",".
$record->getFieldValue("etat_oid","DB","NULL").",".
$record->getFieldValue("provider","DB","NULL").",".
$record->getFieldValue("update_date_min","DB","NOW()").",".
$record->getFieldValue("update_date_max","DB","NOW()").",".
$record->getFieldValue("sort_by","DB","NULL").",".
$record->getFieldValue("read_by","DB","NULL").",".
$record->getFieldValue("hr_manager","DB","NULL").",".
$record->getFieldValue("cand_channel","DB","NULL").",".
$record->getFieldValue("establishment","DB","NULL").")"; ?>