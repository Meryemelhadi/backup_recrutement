<?php $properties["query"]="
				
					SELECT COUNT( distinct _rct_candidate._first_name , _rct_candidate._last_name , _rct_candidate._email ) AS _count
					FROM  
						_rct_candidate
						Right JOIN _rct_candidate_vacancy AS VC ON VC._candidate_oid = _rct_candidate._oid
						Left Join _rct_candidate_provider AS CP ON CP._candidate_oid = _rct_candidate._oid

					WHERE 
						CP ._provider =  ".$props->getProperty('provider_oid')."
						AND VC._vacancy_oid = ".$props->getProperty('vacancy_oid')."
					
				"; ?>