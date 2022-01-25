<?php $properties["query"]="
					SELECT
						_rct_interview._oid AS _interview_oid,
						_rct_interview._date AS _date,		
						_rct_interview_synthesis._oid AS _synthesis_oid,
						_rct_interview_synthesis._date AS _date_eval
					FROM
						_rct_interview 
						LEFT JOIN _rct_candidate ON _rct_interview._candidate_oid=_rct_candidate._oid
						LEFT JOIN _rct_interview_synthesis ON _rct_interview._oid = _rct_interview_synthesis._interview_oid
					WHERE _rct_candidate._oid = '".$props->getProperty("candidate_oid")."' and _rct_interview_synthesis._oid IS NOT NULL
					GROUP BY _interview_oid
				"; ?>