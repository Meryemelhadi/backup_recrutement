<?php $properties["query"]="SELECT _oid,_first_name,_last_name,_civility,_gender,_date_of_birth,_nationality,_email,_phone_1,_phone_2,_mobile,_address,_zip,_country_oid,_town_oid,_mobility_town_oid,_hr_manager,_category_oid,_years_of_practice,_application_type,_keywords,_src_text,_profile,_tag,_bachelor_title,_bachelor_school,_bachelor_year,_add_date,_studies_level,_creation_date,_update_date,_update_info_date,_reading_state,_archive_state,_relevance,_diploma_type,_institution,_diploma,_last_employment_start_date,_last_employment_end_date,_last_employment,_last_training_start_date,_last_training_end_date,_last_training,_age,_establishment FROM _rct_candidate";
	$properties["pageOffset"]=0+(isset($_GET["page"])?$_GET["page"]:"0");
	$properties["pageAlias"]='page';
	$properties["nbRecords"]=0+'100';
	$properties["query"] .= " LIMIT ".(string)($properties["nbRecords"]*$properties["pageOffset"]).",".$properties['nbRecords'];
; ?>