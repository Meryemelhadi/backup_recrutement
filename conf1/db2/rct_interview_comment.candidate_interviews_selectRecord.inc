<?php $properties["query"]="SELECT _oid,_candidate_oid,_interview_by_oid,_location,_interview_etat,_interview_feedback,_vacancy_oid,_date,_time_start FROM _rct_interview_comment WHERE _candidate_oid='".$props->getProperty("candidate_oid","",true)."' ORDER BY _date DESC "; ?>