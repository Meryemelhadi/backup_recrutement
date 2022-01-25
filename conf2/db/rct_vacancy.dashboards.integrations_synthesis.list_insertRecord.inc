<?php $properties["query"]="INSERT INTO _rct_vacancy(_first_name,_last_name,_category,_contract_type,_subsidiary,_contrat_signing,_hire_date,_hire_date_3_month,_hire_date_6_month,_integration_plan,_integration_note,_instant_feedback,_delayed_feedback,_internship_title,_internship_start,_internship_end,_executive_committee_presentation) VALUES(".$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("category","DB","NULL").",".
$record->getFieldValue("contract_type","DB","NULL").",".
$record->getFieldValue("subsidiary","DB","NULL").",".
$record->getFieldValue("contrat_signing","DB","NULL").",".
$record->getFieldValue("hire_date","DB","NOW()").",".
$record->getFieldValue("hire_date_3_month","DB","NOW()").",".
$record->getFieldValue("hire_date_6_month","DB","NOW()").",".
$record->getFieldValue("integration_plan","DB","NULL").",".
$record->getFieldValue("integration_note","DB","NULL").",".
$record->getFieldValue("instant_feedback","DB","NULL").",".
$record->getFieldValue("delayed_feedback","DB","NULL").",".
$record->getFieldValue("internship_title","DB","NULL").",".
$record->getFieldValue("internship_start","DB","NOW()").",".
$record->getFieldValue("internship_end","DB","NOW()").",".
$record->getFieldValue("executive_committee_presentation","DB","NULL").")"; ?>