<?php $properties["query"]="
					SELECT 
						_oid, _name
					FROM 
						`_rct_candidate_test` 
					WHERE 
						_oid NOT IN (SELECT _test_oid from _rct_candidate_test_assoc where _candidate_oid = '".$this->getProperty("candidate_oid")."')
				"; ?>