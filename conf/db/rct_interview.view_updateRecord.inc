<?php $properties["query"]="UPDATE _rct_interview SET _candidate_oid=".$record->getFieldValue("candidate_oid","DB","NULL").",_interview_type=".$record->getFieldValue("interview_type","DB","NULL").",_interview_etat=".$record->getFieldValue("interview_etat","DB","'1'").",_interview_feedback=".$record->getFieldValue("interview_feedback","DB","'1'").",_date=".$record->getFieldValue("date","DB","NOW()").",_time_start=".$record->getFieldValue("time_start","DB","NOW()").",_time_end=".$record->getFieldValue("time_end","DB","'".strftime('%Y-%m-%d %H:%M:%S',strtotime('now+10min',time()))."'").",_interview_by_oid=".$record->getFieldValue("interview_by_oid","DB","NULL").",_location=".$record->getFieldValue("location","DB","NULL").",_comment=".$record->getFieldValue("comment","DB","NULL").",_oid=".$record->getFieldValue("oid","DB","NULL").",_created_by=".$record->getFieldValue("created_by","DB","NULL").",_validated_by=".$record->getFieldValue("validated_by","DB","NULL")." WHERE _oid='".$props->getProperty("interview_oid","",true)."'"; ?>