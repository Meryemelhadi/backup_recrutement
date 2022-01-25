<?php $properties["query"]="
					SELECT

						_rct_interview._time_start AS _time_start,
						_rct_interview._time_end AS _time_end,
						_rct_interview._interview_type AS _interview_type,
						_rct_interview._candidate_oid AS _candidate_oid,
						_rct_interview_by._val AS _interviewer_oid,
						_rct_interview._date AS _date

					FROM

						_rct_interview,_rct_interview_by

					WHERE
						
						(_rct_interview_by._key=_rct_interview._oid AND _rct_interview_by._val in (".$_REQUEST["interviewers"]."))

						and _rct_interview._date = '".$_REQUEST["date_interview"]."'
						and _rct_interview._oid != '".$_REQUEST["interview_oid"]."'
						and _rct_interview_by._val != '0' and _rct_interview._candidate_oid != '0'

				"; ?>