<?php $properties["query"]="UPDATE _rct_candidate_vacancy SET _oid=".$record->getFieldValue("oid","DB","NULL").",_integration_note=".$record->getFieldValue("integration_note","DB","'0'")." WHERE _oid='".$props->getProperty("assoc_oid","",true)."'"; ?>