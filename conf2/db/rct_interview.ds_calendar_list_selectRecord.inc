<?php $properties["query"]="SELECT _rct_interview._oid AS rct_interview_oid,_rct_interview._candidate_oid AS rct_interview_candidate_oid,_rct_interview._interview_by_oid AS rct_interview_interview_by_oid,_rct_interview._vacancy_oid AS rct_interview_vacancy_oid,_rct_interview._date AS rct_interview_date,_rct_interview._time_start AS rct_interview_time_start,_rct_interview._time_end AS rct_interview_time_end,_rct_interview._validation_state AS rct_interview_validation_state FROM _rct_interview,_rct_interview_by WHERE ((_rct_interview_by._key=_rct_interview._oid AND _rct_interview_by._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."')  OR (_rct_interview._created_by='".$GLOBALS["_NX_user"]->getProperty("oid","",true)."') )  GROUP BY _rct_interview._oid  ORDER BY _rct_interview._date DESC "; ?>