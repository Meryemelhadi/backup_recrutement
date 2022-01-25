<?php $properties["query"]="
					SELECT COUNT(DISTINCT _rct_candidate._oid) as _count_recrute
					from _rct_candidate
					Right JOIN _rct_candidate_vacancy AS VC ON VC._candidate_oid = _rct_candidate._oid
					LEFT JOIN _rct_vacancy ON VC._vacancy_oid = _rct_vacancy._oid
					LEFT JOIN _rct_candidate_etat ON _rct_candidate_etat._oid = _rct_candidate._etat_oid
					
					where  _rct_candidate._archive_state = '0' AND  (_rct_candidate._relevance <> '1' OR _rct_candidate._relevance IS NULL)  AND  _rct_candidate._archive_state = '0' AND VC._vacancy_oid = '".(isset($_REQUEST['vacancy_id'])?$_REQUEST['vacancy_id']:0)."' AND _rct_candidate_etat._vacancy_status = 10
				"; ?>