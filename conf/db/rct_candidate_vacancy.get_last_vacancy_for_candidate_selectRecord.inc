<?php $properties["query"]="   
                    SELECT _rct_candidate_vacancy._vacancy_oid as _vacancy_oid
					FROM _rct_candidate_vacancy Left Join _rct_vacancy ON _rct_candidate_vacancy._vacancy_oid = _rct_vacancy._oid
					WHERE _rct_candidate_vacancy._candidate_oid = '".$props->getProperty("candidate_oid")."' 
					AND _rct_vacancy._current_step = 0
					AND `_add_date` = (
						SELECT MAX(`_add_date`)
						FROM _rct_candidate_vacancy
						WHERE _rct_candidate_vacancy._candidate_oid ='".$props->getProperty("candidate_oid")."' 
					)    
                "; ?>