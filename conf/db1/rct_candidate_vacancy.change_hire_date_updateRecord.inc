<?php $properties["query"]="UPDATE _rct_candidate_vacancy SET _oid=".$record->getFieldValue("oid","DB","NULL").",_hire_date=".$record->getFieldValue("hire_date","DB","NOW()")." WHERE _oid='".$props->getProperty("assoc_oid","",true)."'"; ?>