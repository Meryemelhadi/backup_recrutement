<?php $properties["query"]="SELECT _rct_interview._time_start AS rct_interview_time_start,_rct_interview._time_end AS rct_interview_time_end,_rct_interview._candidate_oid AS rct_interview_candidate_oid FROM _rct_interview,_rct_interview_by WHERE (_rct_interview_by._key=_rct_interview._oid AND _rct_interview_by._val='".$this->getParamValue("interview_by_oid","","request",",")."')  AND _rct_interview._date='".$this->getParamValue("date","","request",",")."'"; ?>