<?php $properties["query"]="UPDATE _rct_candidate_vacancy SET _status='".$props->getProperty("status_value","",true)."' WHERE ".$this->getWhereClause("_candidate_oid","'".$props->getProperty("candidate_oid","",true)."'",'=','OR','','',true,false,'|','false')." AND _vacancy_oid='".$props->getProperty("vacancy_oid","",true)."'"; ?>