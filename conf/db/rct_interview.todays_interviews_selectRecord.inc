<?php $properties["query"]="
					SELECT
						  _rct_interview._oid AS _oid,
						  CONCAT_WS(' ',_rct_candidate._first_name, _rct_candidate._last_name) AS _candidate_name,
						  _rct_interview._time_start AS _time_start
						FROM _rct_interview JOIN _rct_interview_by
						LEFT JOIN _rct_candidate ON _rct_candidate._oid = _rct_interview._candidate_oid
						WHERE (_rct_interview_by._key=_rct_interview._oid
								AND (_rct_interview_by._val='".$GLOBALS["_NX_user"]->getProperty("oid","")."'
								OR _rct_interview._created_by='".$GLOBALS["_NX_user"]->getProperty("oid","")."'
								OR _rct_interview_by._val in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."')
								OR _rct_interview._created_by in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."')
								)
								AND _rct_interview._date =DATE(NOW()))
						GROUP BY _rct_interview._oid
						ORDER BY _rct_interview._time_start DESC
				"; ?>