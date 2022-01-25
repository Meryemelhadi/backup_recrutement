<?php $properties["query"]="
					SELECT 
						_oid, _name, _code
					FROM 
						`_rct_vacancy` 
					WHERE 
						_oid NOT IN (SELECT _vacancy_oid from _rct_candidate_vacancy where _candidate_oid = '".$this->getProperty("candidate_oid")."')
				"; ?>