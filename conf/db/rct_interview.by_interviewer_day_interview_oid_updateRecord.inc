<?php $properties["query"]="UPDATE _rct_interview SET _time_start=".$record->getFieldValue("time_start","DB","NOW()").",_time_end=".$record->getFieldValue("time_end","DB","NOW()").",_interview_type=".$record->getFieldValue("interview_type","DB","NULL").",_candidate_oid=".$record->getFieldValue("candidate_oid","DB","NULL").",_date=".$record->getFieldValue("date","DB","NOW()"); ?>