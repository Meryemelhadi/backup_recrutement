<?php $properties["query"]="
					SELECT

						_rct_interview._time_start AS _time_start,
						_rct_interview._time_end AS _time_end,
						_rct_interview._candidate_oid AS _candidate_oid

					FROM

						_rct_interview,_rct_interview_by

					WHERE
						
						(_rct_interview_by._key=_rct_interview._oid AND _rct_interview_by._val='".$this->getProperty("user_oid")."')
						and _rct_interview._date = DATE(NOW())				

				"; ?>