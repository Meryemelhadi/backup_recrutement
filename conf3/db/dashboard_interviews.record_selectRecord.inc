<?php $properties["query"]="SELECT _oid,_candidate_oid,_vacancy_oid,_created_by,_validated_by,_interview_by_oid,_creation_date,_validation_date,_date,_time_start,_time_end,_validation_state,_interview_type,_interview_etat,_interview_feedback,_comment FROM _rct_interview WHERE _oid='".$this->getParamValue("oid","","request",",")."'"; ?>