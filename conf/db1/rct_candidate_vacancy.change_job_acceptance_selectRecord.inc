<?php $properties["query"]="SELECT _job_acceptance_state,_job_acceptance_date FROM _rct_candidate_vacancy WHERE ".$this->getWhereClause("_candidate_oid","'".$props->getProperty("candidate_oid","",true)."'",'=','OR','','',true,false,'|')." AND _vacancy_oid='".$props->getProperty("vacancy_oid","",true)."'"; ?>