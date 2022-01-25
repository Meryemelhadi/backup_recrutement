<?php $properties["query"]="
                    SELECT
                      _rct_candidate._oid as _oid,
                      _rct_candidate._first_name as _first_name,
                      _rct_candidate._last_name as _last_name,
                      _rct_candidate._cv_path as _cv_path,
                      _rct_candidate._email as _email
                    FROM _rct_interview JOIN _rct_interview_by
                    LEFT JOIN _rct_candidate ON _rct_candidate._oid = _rct_interview._candidate_oid
                    WHERE _rct_interview_by._key=_rct_interview._oid
							AND _rct_candidate._oid is not null
                    GROUP BY _rct_candidate._oid
                    ORDER BY  _rct_candidate._first_name ,  _rct_candidate._last_name DESC
                "; ?>