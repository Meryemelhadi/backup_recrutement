<?php $properties["query"]="UPDATE _rct_vacancy SET _oid=".$record->getFieldValue("oid","DB","NULL").",_name=".$record->getFieldValue("name","DB","NULL").",_number=".$record->getFieldValue("number","DB","NULL").",_service_name=".$record->getFieldValue("service_name","DB","NULL").",_years_of_practice=".$record->getFieldValue("years_of_practice","DB","NULL").",_suited_diplomas=".$record->getFieldValue("suited_diplomas","DB","NULL").",_opening_date=".$record->getFieldValue("opening_date","DB","NOW()").",_application_type=".$record->getFieldValue("application_type","DB","'0'").",_providers=".$record->getFieldValue("providers","DB","NULL").",_current_step=".$record->getFieldValue("current_step","DB","NULL").",_progress_level=".$record->getFieldValue("progress_level","DB","NULL"); ?>