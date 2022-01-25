<?php $properties["query"]="INSERT INTO _rct_vacancy(_name,_recruitment_motivation,_announcement,_instant_feedback,_delayed_feedback,_current_step,_opening_date,_closing_date,_open_close_delay,_close_taking_office_delay,_selected_people,_providers,_contract_type,_category,_application_type,_proposal_acceptance_date) VALUES(".$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("recruitment_motivation","DB","NULL").",".
$record->getFieldValue("announcement","DB","NULL").",".
$record->getFieldValue("instant_feedback","DB","NULL").",".
$record->getFieldValue("delayed_feedback","DB","NULL").",".
$record->getFieldValue("current_step","DB","NULL").",".
$record->getFieldValue("opening_date","DB","NOW()").",".
$record->getFieldValue("closing_date","DB","NOW()").",".
$record->getFieldValue("open_close_delay","DB","NULL").",".
$record->getFieldValue("close_taking_office_delay","DB","NULL").",".
$record->getFieldValue("selected_people","DB","NULL").",".
$record->getFieldValue("providers","DB","NULL").",".
$record->getFieldValue("contract_type","DB","NULL").",".
$record->getFieldValue("category","DB","NULL").",".
$record->getFieldValue("application_type","DB","0").",".
$record->getFieldValue("proposal_acceptance_date","DB","NOW()").")"; ?>