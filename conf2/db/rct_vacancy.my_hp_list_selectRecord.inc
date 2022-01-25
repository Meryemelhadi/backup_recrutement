<?php $properties["query"]="

					SELECT 
						V._oid AS _oid,
						V._progress_level AS _progress_level,
						V._client_oid AS _client_oid,
						V._archive_state AS _archive_state,
						V._manager_oid AS _manager_oid,
						V._name AS _name,
						V._number AS _number,
						V._code AS _code,
						V._creator AS _creator,
						count(*) as _count
					
					FROM 
						_rct_vacancy as V
						LEFT JOIN _rct_candidate_vacancy AS CAND ON CAND._vacancy_oid=V._oid
						LEFT JOIN _rct_candidate ON _rct_candidate._oid = CAND._candidate_oid
					
					WHERE 
						V._current_step='0' AND
						".$this->getWhereClause("V._archive_state","'0'",'=','OR','','',true,false,'|','false')." AND
						( V._manager_oid='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR V._creator = '".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."') AND (_workflow_state='1' OR _workflow_state='2')
						AND _rct_candidate._oid IS NOT NULL
					
					GROUP BY CAND._vacancy_oid

					ORDER BY _progress_level ASC,_name ASC,_code ASC

				"; ?>