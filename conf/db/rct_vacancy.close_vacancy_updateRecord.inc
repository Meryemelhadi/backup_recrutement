<?php $properties["query"]="

					UPDATE 
						_rct_vacancy 

					SET 
						_closing_date=NOW(), _current_step = 2 

					WHERE 
						_oid = '".$this->getProperty("vacancy_oid")."' 

					AND 
						_number <= (SELECT COUNT(*) FROM _rct_candidate_vacancy WHERE _vacancy_oid = '".$this->getProperty("vacancy_oid")."' AND _job_acceptance_state = '1')

				"; ?>