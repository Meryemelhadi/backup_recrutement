<?php $properties["query"]="UPDATE _rct_vacancy_action SET _oid=".$record->getFieldValue("oid","DB","NULL").",_name=".$record->getFieldValue("name","DB","NULL").",_number=".$record->getFieldValue("number","DB","NULL").",_category_oid=".$record->getFieldValue("category_oid","DB","NULL").",_contract_type_oid=".$record->getFieldValue("contract_type_oid","DB","NULL").",_mission_start_date=".$record->getFieldValue("mission_start_date","DB","NOW()").",_suited_recruitment_date=".$record->getFieldValue("suited_recruitment_date","DB","NOW()").",_taking_office_date=".$record->getFieldValue("taking_office_date","DB","NOW()").",_code=".$record->getFieldValue("code","DB","NULL").",_archive_state=".$record->getFieldValue("archive_state","DB","NULL").",_manager_oid=".$record->getFieldValue("manager_oid","DB","NULL").",_client_oid=".$record->getFieldValue("client_oid","DB","NULL").",_current_step=".$record->getFieldValue("current_step","DB","NULL").",_progress_level=".$record->getFieldValue("progress_level","DB","NULL").",_closing_date=".$record->getFieldValue("closing_date","DB","NOW()").",_duty_station_oid=".$record->getFieldValue("duty_station_oid","DB","NULL").",_service_oid=".$record->getFieldValue("service_oid","DB","NULL").",_subsidiary_oid=".$record->getFieldValue("subsidiary_oid","DB","NULL").",_application_type=".$record->getFieldValue("application_type","DB","NULL").",_opening_date=".$record->getFieldValue("opening_date","DB","NOW()").",_internship_title=".$record->getFieldValue("internship_title","DB","NULL").",_internship_start=".$record->getFieldValue("internship_start","DB","NOW()").",_internship_end=".$record->getFieldValue("internship_end","DB","NOW()").",_executive_committee_presentation=".$record->getFieldValue("executive_committee_presentation","DB","'0'")." WHERE _oid=".$this->getFieldParam("oid","null",",",$record,""); ?>