<?php $properties["query"]="

					SELECT

						_rct_candidate_vacancy._oid as _oid,
						_rct_candidate_vacancy._vacancy_oid as _vacancy_oid,
						COALESCE(_rct_candidate_vacancy._contrat_signing,0) as _contrat_signing,
						COALESCE(_rct_candidate_vacancy._integration_plan,0) as _integration_plan,
						COALESCE(_rct_candidate_vacancy._integration_note,0) as _integration_note,
						_rct_candidate_vacancy._hire_date as _hire_date,
						_rct_candidate_vacancy._hire_date as _hire_date_raw,
						CONCAT_WS(' ', _rct_candidate._first_name,_rct_candidate._last_name) as _full_name

					FROM 
						_rct_candidate_vacancy

					LEFT JOIN 
						_rct_candidate ON _rct_candidate._oid = _rct_candidate_vacancy._candidate_oid

					WHERE 
						_rct_candidate_vacancy._vacancy_oid = '".$this->getProperty("vacancy_oid")."'
						

					AND 
						_rct_candidate_vacancy._job_acceptance_state = '1'

					ORDER BY _full_name ASC

				"; ?>