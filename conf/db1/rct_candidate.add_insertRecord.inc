<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_first_name,_last_name,_civility,_gender,_date_of_birth,_nationality,_email,_phone_1,_phone_2,_mobile,_address,_zip,_country_oid,_town_oid,_category_oid,_years_of_practice,_application_type,_keywords,_profile,_add_date,_studies_level,_bachelor_title,_bachelor_school,_bachelor_year,_creation_date,_update_date,_reading_state,_archive_state,_relevance) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("civility","DB","NULL").",".
$record->getFieldValue("gender","DB","NULL").",".
$record->getFieldValue("date_of_birth","DB","NOW()").",".
$record->getFieldValue("nationality","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("phone_1","DB","NULL").",".
$record->getFieldValue("phone_2","DB","NULL").",".
$record->getFieldValue("mobile","DB","NULL").",".
$record->getFieldValue("address","DB","NULL").",".
$record->getFieldValue("zip","DB","NULL").",".
$record->getFieldValue("country_oid","DB","NULL").",".
$record->getFieldValue("town_oid","DB","NULL").",".
$record->getFieldValue("category_oid","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("application_type","DB","NULL").",".
$record->getFieldValue("keywords","DB","NULL").",".
$record->getFieldValue("profile","DB","NULL").",".
"NOW(),".
$record->getFieldValue("studies_level","DB","NULL").",".
$record->getFieldValue("bachelor_title","DB","NULL").",".
$record->getFieldValue("bachelor_school","DB","NULL").",".
$record->getFieldValue("bachelor_year","DB","NOW()").",".
"NOW(),".
"NOW(),".
"'1',".
$record->getFieldValue("archive_state","DB","0").",".
$record->getFieldValue("relevance","DB","NULL").")"; ?>