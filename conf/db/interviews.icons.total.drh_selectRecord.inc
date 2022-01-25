<?php $properties["query"]="
                    SELECT count(distinct _rct_interview._oid) as _count
                    FROM
                        _rct_interview 
                        LEFT JOIN _rct_vacancy ON _rct_vacancy._oid = _rct_interview._vacancy_oid
						LEFT JOIN _rct_vacancy_total_control AS T_CTRL ON T_CTRL._key = _rct_vacancy._oid
						LEFT JOIN _rct_vacancy_readonly		 AS R_CTRL ON R_CTRL._key = _rct_vacancy._oid
                    WHERE
                         _rct_interview._date >= DATE(NOW( ))
                        and _rct_vacancy._current_step = 0 and _rct_vacancy._oid IS NOT NULL
						
                "; ?>