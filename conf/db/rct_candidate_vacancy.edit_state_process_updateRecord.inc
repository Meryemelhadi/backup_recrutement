<?php $properties["query"]="UPDATE _rct_candidate_vacancy SET _vacancy_oid=".$record->getFieldValue("vacancy_oid","DB","NULL").",_etat_oid=".$record->getFieldValue("etat_oid","DB","NULL")." WHERE _candidate_oid='".$props->getProperty("candidate_oid","",true)."' AND _vacancy_oid='".$props->getProperty("vacancy_oid","",true)."'"; ?>