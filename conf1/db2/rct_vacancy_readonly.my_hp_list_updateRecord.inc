<?php $properties["query"]="UPDATE _rct_vacancy_readonly SET _oid=".$record->getFieldValue("oid","DB","NULL").",_progress_level=".$record->getFieldValue("progress_level","DB","NULL").",_client_oid=".$record->getFieldValue("client_oid","DB","NULL").",_archive_state='0',_manager_oid=".$record->getFieldValue("manager_oid","DB","NULL").",_name=".$record->getFieldValue("name","DB","NULL").",_number=".$record->getFieldValue("number","DB","NULL").",_code=".$record->getFieldValue("code","DB","NULL").",_creator=".$record->getFieldValue("creator","DB","NULL").",_count=".$record->getFieldValue("count","DB","NULL")." WHERE _current_step='0' AND ".$this->getWhereClause("_archive_state","'0'",'=','OR','','',true,false,'|','false')." AND (_manager_oid='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR _creator='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."')  AND (_workflow_state='1' OR _workflow_state='2') "; ?>