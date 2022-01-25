<?php $properties["query"]="
                    SELECT

						_rct_interview._oid AS _oid,
                        _rct_interview._time_start AS _time_start,
                        _rct_interview._time_end AS _time_end,
                        CONCAT(_rct_candidate._first_name,' ',_rct_candidate._last_name) AS _candidate,
                        CONCAT(_rct_candidate._first_name,' ',_rct_candidate._last_name) AS _candidate_oid,
                        _rct_interview._date AS _date,		
						
						_rct_vacancy._oid AS _vacancy_oid,
						_rct_vacancy._name AS _vacancy_name

                    FROM

                        _rct_interview join _rct_interview_by 
						LEFT JOIN _rct_candidate ON _rct_interview._candidate_oid = _rct_candidate._oid
						LEFT JOIN _rct_vacancy ON _rct_vacancy._oid = _rct_interview._vacancy_oid

                    WHERE
						_rct_interview._interview_by_oid like '%|".$GLOBALS["_NX_user"]->getProperty("oid","")."|%'
                        and _rct_interview._date >= DATE(NOW( ))

					GROUP BY 
						_rct_interview._oid

                    ORDER BY 
						_rct_interview._date ASC , _rct_candidate._first_name ASC , _rct_candidate._last_name ASC

                "; ?>