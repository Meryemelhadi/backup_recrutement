<?php $properties["query"]="UPDATE _rct_interview SET _oid=".$record->getFieldValue("oid","DB","NULL").",_vacancy_oid=".$record->getFieldValue("vacancy_oid","DB","NULL").",_date=".$record->getFieldValue("date","DB","NOW()").",_time_start=".$record->getFieldValue("time_start","DB","NOW()").",_time_end=".$record->getFieldValue("time_end","DB","NOW()").",_ical_uid=".$record->getFieldValue("ical_uid","DB","NULL").",_ical_seq=".$record->getFieldValue("ical_seq","DB","'0'"); ?>