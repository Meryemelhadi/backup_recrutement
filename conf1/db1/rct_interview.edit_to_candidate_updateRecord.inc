<?php $properties["query"]="UPDATE _rct_interview SET _oid=".$record->getFieldValue("oid","DB","NULL").",_created_by=".$record->getFieldValue("created_by","DB","NULL").",_validated_by=".$record->getFieldValue("validated_by","DB","NULL").",_candidate_oid=".$record->getFieldValue("candidate_oid","DB","NULL").",_interview_by=".$record->getFieldValue("interview_by","DB","NULL").",_date=".$record->getFieldValue("date","DB","NOW()").",_time_start=".$record->getFieldValue("time_start","DB","'".strftime('%Y-%m-%d %H:%M:%S',strtotime('09:00',time()))."'").",_time_end=".$record->getFieldValue("time_end","DB","'".strftime('%Y-%m-%d %H:%M:%S',strtotime('11:00',time()))."'").",_email_title=".$record->getFieldValue("email_title","DB","NULL").",_email_content=".$record->getFieldValue("email_content","DB","NULL").",_user_email_title=".$record->getFieldValue("user_email_title","DB","NULL").",_user_email_content=".$record->getFieldValue("user_email_content","DB","NULL").",_candidate_email_not=".$record->getFieldValue("candidate_email_not","DB","'0'").",_interviewer_email_not=".$record->getFieldValue("interviewer_email_not","DB","'0'")." WHERE _oid='".$props->getProperty("interview_oid","",true)."'"; ?>