<?php $properties["query"]="UPDATE _rct_vacancy_readonly SET _oid=".$record->getFieldValue("oid","DB","NULL")." WHERE ".$this->getWhereClause("_code","'".$props->getProperty("vacancy_code","",true)."'",'LIKE','OR','%','%',true,false,'|','false'); ?>