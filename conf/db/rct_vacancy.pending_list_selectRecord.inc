<?php $properties["query"]="
					SELECT distinct _rct_vacancy._oid AS rct_vacancy_oid,
									_rct_vacancy._code AS rct_vacancy_code,
									_rct_vacancy._name AS rct_vacancy_name,
									_rct_vacancy._number AS rct_vacancy_number,
									_rct_vacancy._progress_level AS rct_vacancy_progress_level,
									_rct_vacancy._workflow_state AS rct_vacancy_workflow_state,
									_rct_vacancy._request_date AS rct_vacancy_request_date,
									_rct_vacancy._requested_by AS rct_vacancy_requested_by,
									_rct_vacancy._manager_oid AS rct_vacancy_manager_oid 
					FROM _rct_vacancy
					LEFT JOIN _rct_vacancy_total_control ON _rct_vacancy._oid = _rct_vacancy_total_control._key
					LEFT JOIN _rct_vacancy_readonly ON _rct_vacancy._oid = _rct_vacancy_readonly._key
					WHERE _rct_vacancy._workflow_state='1' 
						  AND _rct_vacancy._current_step='0' 
						  AND ((_rct_vacancy._creator='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."')  OR (_rct_vacancy_total_control._key=_rct_vacancy._oid 
						  AND _rct_vacancy_total_control._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."')  OR (_rct_vacancy_readonly._key=_rct_vacancy._oid 
						  AND _rct_vacancy_readonly._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."')  OR (_rct_vacancy._manager_oid='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."') OR (_rct_vacancy._manager_oid IS NULL OR _rct_vacancy._manager_oid ='?') )  
					ORDER BY _rct_vacancy._name ASC,_rct_vacancy._code ASC 
				"; ?>