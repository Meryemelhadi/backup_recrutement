<?php $properties["query"]="
					SELECT 
						_oid, _name, _index
					FROM 
						`_rct_candidate_etat` 
					WHERE 
						_oid NOT IN (SELECT _etat_oid from _rct_candidate_etat_assoc where _candidate_oid = '".$this->getProperty("candidate_oid")."')
					ORDER BY _index, _oid
				"; ?>