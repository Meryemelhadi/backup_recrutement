<?php $properties["query"]="
					SELECT 
						count(distinct _rct_candidate._first_name, _rct_candidate._last_name, _rct_candidate._email) as _count
					FROM
					_rct_candidate

					LEFT JOIN _rct_candidate_read_state AS rs ON rs._candidate_oid = _rct_candidate._oid AND  rs._user_oid <> '".$GLOBALS["_NX_user"]->getProperty("oid","")."'
					LEFT JOIN _rct_candidate_read_state AS rs1 ON rs1._candidate_oid = _rct_candidate._oid AND  rs1._user_oid = '".$GLOBALS["_NX_user"]->getProperty("oid","")."'

					LEFT JOIN _rct_candidate_vacancy
						ON _rct_candidate_vacancy ._candidate_oid = _rct_candidate._oid
					LEFT JOIN
						_rct_vacancy ON _rct_candidate_vacancy._vacancy_oid = _rct_vacancy._oid

			
					LEFT JOIN _rct_candidate_category_assoc ON _rct_candidate._oid = _rct_candidate_category_assoc._key
					LEFT JOIN _rct_candidate_category ON _rct_candidate_category_assoc._val = _rct_candidate_category._oid
					LEFT JOIN _rct_candidate_etat ON _rct_candidate_etat._oid = _rct_candidate._etat_oid

				WHERE
					 _rct_candidate._archive_state = '0' AND  (_rct_candidate._relevance <> '1' OR _rct_candidate._relevance IS NULL)  AND  _rct_candidate._archive_state = '0' AND 1=1

				"; ?>