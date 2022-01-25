<?php $properties["query"]="
					 SELECT _oid ,
						CONCAT_WS(' ', _first_name, _last_name) AS _full_name
					 FROM _rct_candidate 
					 WHERE
						_rct_candidate._archive_state = '0' AND  (_rct_candidate._relevance <> '1' OR _rct_candidate._relevance IS NULL)  AND _rct_candidate._first_name IS NOT NULL AND _rct_candidate._last_name IS NOT NULL AND _rct_candidate._first_name != '' AND _rct_candidate._last_name != ''
					 GROUP BY _rct_candidate._first_name , _rct_candidate._last_name , _rct_candidate._email
					 ORDER BY   _rct_candidate._first_name ASC, _rct_candidate._last_name ASC , _rct_candidate._update_date DESC
				
				"; ?>