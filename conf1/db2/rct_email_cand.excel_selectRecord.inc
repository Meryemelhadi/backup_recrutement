<?php $properties["query"]="SELECT _oid,_candidate_oid,_vacancy_oid,_created_by,_creation_date,_email_type,_email_title FROM _rct_email WHERE _candidate_oid='".$this->getParamValue("coid","","request",",")."' ORDER BY _name ASC "; ?>