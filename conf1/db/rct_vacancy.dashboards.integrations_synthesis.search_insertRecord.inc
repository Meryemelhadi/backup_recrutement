<?php $properties["query"]="INSERT INTO _rct_vacancy(_first_name,_last_name,_category_oid,_contract_type_oid,_hire_date_start,_hire_date_end,_hire_date_3_month_start,_hire_date_3_month_end,_hire_date_6_month_start,_hire_date_6_month_end,_subsidiary_oid,_contrat_signing,_integration_plan,_integration_note,_instant_feedback,_delayed_feedback,_internship_title,_executive_committee_presentation,_internship_start_start,_internship_start_end,_internship_end_start,_internship_end_end) VALUES(".$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("category_oid","DB","NULL").",".
$record->getFieldValue("contract_type_oid","DB","NULL").",".
$record->getFieldValue("hire_date_start","DB","NOW()").",".
$record->getFieldValue("hire_date_end","DB","NOW()").",".
$record->getFieldValue("hire_date_3_month_start","DB","NOW()").",".
$record->getFieldValue("hire_date_3_month_end","DB","NOW()").",".
$record->getFieldValue("hire_date_6_month_start","DB","NOW()").",".
$record->getFieldValue("hire_date_6_month_end","DB","NOW()").",".
$record->getFieldValue("subsidiary_oid","DB","NULL").",".
$record->getFieldValue("contrat_signing","DB","NULL").",".
$record->getFieldValue("integration_plan","DB","NULL").",".
$record->getFieldValue("integration_note","DB","NULL").",".
$record->getFieldValue("instant_feedback","DB","NULL").",".
$record->getFieldValue("delayed_feedback","DB","NULL").",".
$record->getFieldValue("internship_title","DB","NULL").",".
$record->getFieldValue("executive_committee_presentation","DB","NULL").",".
$record->getFieldValue("internship_start_start","DB","NOW()").",".
$record->getFieldValue("internship_start_end","DB","NOW()").",".
$record->getFieldValue("internship_end_start","DB","NOW()").",".
$record->getFieldValue("internship_end_end","DB","NOW()").")"; ?>