<?php $properties["query"]="UPDATE _rct_email SET _oid=".$record->getFieldValue("oid","DB","NULL").",_creation_date=".$record->getFieldValue("creation_date","DB","NOW()")." WHERE _candidate_oid='".$props->getProperty("candidate_oid","",true)."'"; ?>