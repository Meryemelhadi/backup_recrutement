<?php $properties["query"]="UPDATE _rct_candidate SET _oid=".$record->getFieldValue("oid","DB","NULL").",_first_name=".$record->getFieldValue("first_name","DB","NULL").",_last_name=".$record->getFieldValue("last_name","DB","NULL").",_civility=".$record->getFieldValue("civility","DB","NULL").",_gender=".$record->getFieldValue("gender","DB","NULL").",_date_of_birth=".$record->getFieldValue("date_of_birth","DB","NOW()").",_nationality=".$record->getFieldValue("nationality","DB","NULL").",_email=".$record->getFieldValue("email","DB","NULL").",_phone_1=".$record->getFieldValue("phone_1","DB","NULL").",_phone_2=".$record->getFieldValue("phone_2","DB","NULL").",_mobile=".$record->getFieldValue("mobile","DB","NULL").",_address=".$record->getFieldValue("address","DB","NULL").",_zip=".$record->getFieldValue("zip","DB","NULL").",_studies_level=".$record->getFieldValue("studies_level","DB","NULL").",_country_oid=".$record->getFieldValue("country_oid","DB","NULL").",_town_oid=".$record->getFieldValue("town_oid","DB","NULL").",_mobility_town_oid=".$record->getFieldValue("mobility_town_oid","DB","NULL").",_hr_manager=".$record->getFieldValue("hr_manager","DB","NULL").",_category_oid=".$record->getFieldValue("category_oid","DB","NULL").",_establishment=".$record->getFieldValue("establishment","DB","NULL").",_years_of_practice=".$record->getFieldValue("years_of_practice","DB","NULL").",_available_from=".$record->getFieldValue("available_from","DB","NOW()").",_available_delai=".$record->getFieldValue("available_delai","DB","NULL").",_salary_min=".$record->getFieldValue("salary_min","DB","NULL").",_salary_max=".$record->getFieldValue("salary_max","DB","NULL").",_salary_package=".$record->getFieldValue("salary_package","DB","NULL").",_application_type=".$record->getFieldValue("application_type","DB","NULL").",_profile=".$record->getFieldValue("profile","DB","NULL").",_tag=".$record->getFieldValue("tag","DB","NULL").",_bachelor_title=".$record->getFieldValue("bachelor_title","DB","NULL").",_bachelor_school=".$record->getFieldValue("bachelor_school","DB","NULL").",_bachelor_year=".$record->getFieldValue("bachelor_year","DB","NOW()").",_cv_path=".$record->getFieldValue("cv_path","DB","NULL").",_cl_path=".$record->getFieldValue("cl_path","DB","NULL").",_update_date=".$record->getFieldValue("update_date","DB","NOW()").",_update_info_date=NOW(),_archive_state=".$record->getFieldValue("archive_state","DB","'0'").",_relevance=".$record->getFieldValue("relevance","DB","NULL")." WHERE _oid='".$props->getProperty("candidate_oid","",true)."'"; ?>