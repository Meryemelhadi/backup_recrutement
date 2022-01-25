<?php $properties["query"]="
					SELECT 
						_oid, _name, _code
					FROM 
						_rct_vacancy 

					WHERE 
						_oid NOT IN (SELECT _vacancy_oid from _rct_candidate_vacancy where _candidate_oid = ".$_GET['candidate_oid'].")

						AND _archive_state <> 1
						AND _current_step = 0

					ORDER BY _name, _code
				"; ?>