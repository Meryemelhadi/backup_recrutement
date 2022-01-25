<?php $properties["query"]="

					SELECT 
						V._oid AS rct_vacancy_oid,
						RO._key AS rct_vacancy_readonly_key,
						TC._key AS rct_vacancy_total_control_key,
						V._progress_level AS rct_vacancy_progress_level,
						V._client_oid AS rct_vacancy_client_oid,
						V._archive_state AS rct_vacancy_archive_state,
						V._manager_oid AS rct_vacancy_manager_oid,
						V._name AS rct_vacancy_name,
						V._number AS rct_vacancy_number,
						V._code AS rct_vacancy_code,
						V._creator AS rct_vacancy_creator, 
						count(*) as rct_vacancy_count

					FROM 
						_rct_vacancy AS V
						LEFT JOIN _rct_vacancy_total_control AS TC ON TC._key=V._oid
						LEFT JOIN _rct_vacancy_readonly AS RO ON RO._key=V._oid
						LEFT JOIN _rct_candidate_vacancy AS CAND ON CAND._vacancy_oid=V._oid
						LEFT JOIN _rct_candidate ON _rct_candidate._oid = CAND._candidate_oid

					WHERE 
						V._manager_oid<>'".($U=$GLOBALS["_NX_user"]->getProperty("user.oid","",true))."' AND 
						V._current_step='0' AND 
						(V._archive_state = '0') AND 
						(V._workflow_state='1' OR V._workflow_state='2')  AND 

						(
							(V._client_oid='".$U."')  OR (TC._val='".$U."')  OR (RO._val='".$U."') 
						)
						AND _rct_candidate._oid IS NOT NULL

					GROUP BY 
						V._oid  

					ORDER BY 
						V._progress_level ASC,
						V._name ASC,
						V._code ASC

				"; ?>