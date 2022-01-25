<?php $properties["query"]="
					 SELECT _oid ,
						CONCAT_WS(' ', _first_name, _last_name) AS _full_name
					 FROM _rct_candidate 
					 WHERE
						_rct_candidate._archive_state = '0' AND  (_rct_candidate._relevance <> '1' OR _rct_candidate._relevance IS NULL)  AND  _rct_candidate._archive_state = '0'  AND (_first_name LIKE '".$props->getProperty('keyword')."%' OR _last_name LIKE '".$props->getProperty('keyword')."%')
					 /* GROUP BY _rct_candidate._first_name , _rct_candidate._last_name , _rct_candidate._email */
					 GROUP BY _rct_candidate._oid
					 ORDER BY  _rct_candidate._update_date DESC, _rct_candidate._first_name ASC, _rct_candidate._last_name ASC 
					 LIMIT 0, 50
				
				"; ?>