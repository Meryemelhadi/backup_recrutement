<?php $properties["query"]="UPDATE _rct_interview SET _oid=".$record->getFieldValue("oid","DB","NULL").",_candidate_oid=".$record->getFieldValue("candidate_oid","DB","NULL").",_interview_by_oid=".$record->getFieldValue("interview_by_oid","DB","NULL").",_vacancy_oid=".$record->getFieldValue("vacancy_oid","DB","NULL").",_date=".$record->getFieldValue("date","DB","NOW()").",_time_start=".$record->getFieldValue("time_start","DB","NOW()").",_time_end=".$record->getFieldValue("time_end","DB","NOW()").",_validation_state=".$record->getFieldValue("validation_state","DB","NULL")." WHERE ((_key=_rct_interview._oid AND _val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."')  OR (_created_by='".$GLOBALS["_NX_user"]->getProperty("oid","",true)."') ) "; ?>