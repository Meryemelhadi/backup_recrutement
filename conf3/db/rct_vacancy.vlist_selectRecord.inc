<?php $properties["query"]="
				    SELECT distinct
                      IFNULL(_rct_interview._vacancy_oid,IFNULL(VAC2._oid,0)) as _oid,
                      IFNULL(VAC._name,IFNULL(VAC2._name,0)) as _name
                    FROM _rct_interview JOIN _rct_interview_by
                    LEFT JOIN _rct_candidate ON _rct_candidate._oid = _rct_interview._candidate_oid
			        LEFT JOIN _rct_vacancy AS VAC ON VAC._oid = _rct_interview._vacancy_oid
                    LEFT JOIN (
                        SELECT
                            _candidate_oid,_vacancy_oid as _v_oid
                        FROM
                            _rct_candidate_vacancy
                        GROUP BY _rct_candidate_vacancy._candidate_oid
                        ORDER BY _add_date DESC
                    ) AS CAND_VAC ON CAND_VAC._candidate_oid = _rct_candidate._oid
                    --  LEFT JOIN _rct_candidate_vacancy AS CAND_VAC ON CAND_VAC._candidate_oid = CAND._oid
			        LEFT JOIN _rct_vacancy AS VAC2 ON VAC2._oid = CAND_VAC._v_oid
                    WHERE (_rct_interview_by._key=_rct_interview._oid
                            AND (_rct_interview_by._val=".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."
                            OR _rct_interview._created_by=".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."
							OR _rct_interview_by._val in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."')
							OR _rct_interview._created_by in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."')
							) 
							AND IFNULL(_rct_interview._vacancy_oid,IFNULL(VAC2._oid,0)) != 0)
                    ORDER BY _name DESC
				"; ?>