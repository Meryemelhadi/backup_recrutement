<?php $properties["query"]="UPDATE _rct_candidate_vacancy SET _job_acceptance_state='".$props->getProperty("acceptance_status","",true)."',_job_acceptance_date=NOW() WHERE ".$this->getWhereClause("_candidate_oid","'".$props->getProperty("candidate_oid","",true)."'",'=','OR','','',true,false,'|')." AND _vacancy_oid='".$props->getProperty("vacancy_oid","",true)."'"; ?>