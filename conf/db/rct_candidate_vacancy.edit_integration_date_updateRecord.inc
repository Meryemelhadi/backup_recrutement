<?php $properties["query"]="UPDATE _rct_candidate_vacancy SET _candidate_oid='".$props->getProperty("candidate_oid","",true)."',_vacancy_oid='".$props->getProperty("vacancy_oid","",true)."',_integration_date=".$record->getFieldValue("integration_date","DB","NOW()")." WHERE _candidate_oid='".$props->getProperty("candidate_oid","",true)."' AND _vacancy_oid='".$props->getProperty("vacancy_oid","",true)."'"; ?>