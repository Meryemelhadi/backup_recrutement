<?php $properties["query"]="SELECT _oid,_candidate_oid,_created_by,_date,_time_start,_time_end,_validation_state FROM _rct_announcement_lydec WHERE _vacancy_oid='".$this->getParamValue("oid","","request",",")."' AND _validation_state='0'"; ?>