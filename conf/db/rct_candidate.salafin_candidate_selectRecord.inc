<?php $properties["query"]="
					SELECT SQL_CALC_FOUND_ROWS
	
						C._oid as _oid
					
							FROM

								
								_rct_candidate AS C

							-- RÃ©cupÃ©ration des dossiers
							LEFT JOIN _rct_candidate_comment
								ON _rct_candidate_comment._candidate_oid = C._oid
								
							LEFT JOIN _rct_candidate_vacancy
								ON _rct_candidate_vacancy ._candidate_oid = C._oid
							LEFT JOIN
								_rct_vacancy ON _rct_candidate_vacancy._vacancy_oid = _rct_vacancy._oid

							-- RÃ©cupÃ©ration Ã©tat de lecture
							 LEFT JOIN _rct_candidate_provider ON _rct_candidate_provider._candidate_oid = C._oid 
							LEFT JOIN _rct_candidate_read_state AS rs ON rs._candidate_oid = C._oid AND  rs._user_oid <> '470'
							LEFT JOIN _rct_candidate_read_state AS rs1 ON rs1._candidate_oid = C._oid AND  rs1._user_oid = '470'
						
							
							-- RÃ©cupÃ©ration de la catÃ©gorie
							LEFT JOIN _rct_candidate_category_assoc ON C._oid = _rct_candidate_category_assoc._key
							LEFT JOIN _rct_candidate_category ON _rct_candidate_category_assoc._val = _rct_candidate_category._oid
							LEFT JOIN
									_rct_education as _education
									ON _education._candidate_oid = C._oid
							LEFT JOIN
									_rct_diploma ON _education._diploma = _rct_diploma._code
							LEFT JOIN _rct_candidate_etat ON _rct_candidate_etat._oid = C._etat_oid

							WHERE
								 _rct_vacancy._oid != '9' AND  _rct_vacancy._oid != '19' AND C._archive_state = '0' AND  (C._relevance <> '1' OR C._relevance IS NULL)  AND  _rct_candidate_provider._provider= 419 AND  C._archive_state = '0' AND 1=1
					GROUP BY C._first_name, C._last_name, C._email
					ORDER BY  C._update_date DESC, C._first_name ASC, C._last_name ASC 
				"; ?>