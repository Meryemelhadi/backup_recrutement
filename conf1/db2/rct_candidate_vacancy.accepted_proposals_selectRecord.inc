<?php $properties["query"]="

					SELECT
						_rct_candidate_vacancy._proposal_acceptance_date, CONCAT_WS(' ', _rct_candidate._first_name,_rct_candidate._last_name) as _full_name

					FROM 
						_rct_candidate_vacancy

					LEFT JOIN 
						_rct_candidate ON _rct_candidate._oid = _rct_candidate_vacancy._candidate_oid

					WHERE 
						_rct_candidate_vacancy._vacancy_oid = '".$this->getProperty("vacancy_oid")."' 

					AND 
						_rct_candidate_vacancy._proposal_acceptance_state = '1' 

					AND 
						_rct_candidate_vacancy._proposal_acceptance_date IS NOT NULL

					ORDER BY 

						_rct_candidate_vacancy._proposal_acceptance_date DESC					

				"; ?>