<?php $properties["query"]="
                    /*SELECT
                        _rct_candidate._oid as _candidate_oid,
                        _rct_candidate_vacancy._oid as _oid
                    FROM

                        (select _oid from _rct_candidate group by _first_name , _last_name , _email) _rct_candidate
                        LEFT JOIN _rct_candidate_vacancy ON _rct_candidate._oid = _rct_candidate_vacancy._candidate_oid
                    WHERE
                        _rct_candidate_vacancy._vacancy_oid = '".$_REQUEST['vacancy_id']."'
                        AND _rct_candidate._oid IS NOT NULL */
                        
                    SELECT _rct_candidate._oid as _candidate_oid , _rct_vacancy._oid as _oid
					FROM _rct_candidate
					LEFT JOIN _rct_candidate_vacancy ON _rct_candidate_vacancy ._candidate_oid = _rct_candidate._oid
					LEFT JOIN _rct_vacancy ON _rct_candidate_vacancy._vacancy_oid = _rct_vacancy._oid
					WHERE _rct_vacancy._oid = '".$_REQUEST['vacancy_id']."' 
					GROUP BY _rct_candidate._first_name, _rct_candidate._last_name, _rct_candidate._email
                        
                "; ?>