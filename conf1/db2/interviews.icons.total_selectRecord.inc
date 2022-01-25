<?php $properties["query"]="
                    SELECT count(*) as _count
                    FROM
                        _rct_interview 
                        LEFT JOIN _rct_vacancy ON _rct_vacancy._oid = _rct_interview._vacancy_oid
						LEFT JOIN _rct_vacancy_total_control AS T_CTRL ON T_CTRL._key = _rct_vacancy._oid
						LEFT JOIN _rct_vacancy_readonly		 AS R_CTRL ON R_CTRL._key = _rct_vacancy._oid
                    WHERE
                        _rct_interview._interview_by_oid like '%|".$GLOBALS["_NX_user"]->getProperty("oid","")."|%'
                        and _rct_interview._date >= DATE(NOW( ))
                        and _rct_vacancy._current_step = 0 and _rct_vacancy._oid IS NOT NULL
						AND (
							_rct_vacancy._creator='".$GLOBALS["_NX_user"]->getProperty("oid","")."' OR
							T_CTRL._val='".$GLOBALS["_NX_user"]->getProperty("oid","")."' OR
							R_CTRL._val='".$GLOBALS["_NX_user"]->getProperty("oid","")."' OR
							_rct_vacancy._manager_oid='".$GLOBALS["_NX_user"]->getProperty("oid","")."'
						)
                "; ?>