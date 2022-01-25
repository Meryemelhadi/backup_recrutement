<?php $properties["query"]="
					SELECT _rct_candidate.* ,
					_rct_vacancy._name as _vacancy_name,
					_rct_vacancy._contract_type_oid
					FROM _rct_candidate 
					LEFT JOIN _rct_candidate_vacancy ON _rct_candidate_vacancy ._candidate_oid = _rct_candidate._oid
					LEFT JOIN _rct_vacancy ON _rct_candidate_vacancy._vacancy_oid = _rct_vacancy._oid
					
					
					WHERE _rct_candidate._oid='".$props->getProperty('candidate')."'
				"; ?>