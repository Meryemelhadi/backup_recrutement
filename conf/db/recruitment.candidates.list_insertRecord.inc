<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_studies_level,_relevance_rate,_first_name,_last_name,_vacancies,_cv_path,_years_of_practice,_profile,_tag,_read_state,_user_read_state,_establishment,_relevance,_provider,_creation_date,_update_info_date,_hr_manager,_comments_cache,_etat_color) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("studies_level","DB","NULL").",".
$record->getFieldValue("relevance_rate","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("vacancies","DB","NULL").",".
$record->getFieldValue("cv_path","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("profile","DB","NULL").",".
$record->getFieldValue("tag","DB","NULL").",".
$record->getFieldValue("read_state","DB","NULL").",".
$record->getFieldValue("user_read_state","DB","NULL").",".
$record->getFieldValue("establishment","DB","NULL").",".
$record->getFieldValue("relevance","DB","NULL").",".
$record->getFieldValue("provider","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").",".
$record->getFieldValue("update_info_date","DB","NOW()").",".
$record->getFieldValue("hr_manager","DB","NULL").",".
$record->getFieldValue("comments_cache","DB","NULL").",".
$record->getFieldValue("etat_color","DB","NULL").")"; ?>