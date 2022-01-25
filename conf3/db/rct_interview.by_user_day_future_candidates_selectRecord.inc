<?php $properties["query"]="
                    SELECT
                        _rct_interview._time_start AS _time_start,
                        _rct_interview._time_end AS _time_end,
                        _rct_interview._candidate_oid AS _candidate_oid,
                        _rct_interview._date AS _date,
                        _rct_candidate._first_name as _first_name,
                        _rct_candidate._last_name as _last_name,
                        _rct_candidate._update_date as _update_date,
                        _rct_candidate._zip as _zip,
                        _rct_candidate._town_oid as _town_name,
                        _rct_candidate._creation_date as _creation_date,
                        _rct_candidate._update_info_date AS _update_info_date,
                        _rct_interview_synthesis._oid as _synthesis_oid,
                        _rct_interview._oid as _interview_oid

                    FROM

                        _rct_interview join _rct_interview_by
                        LEFT JOIN _rct_candidate ON _rct_candidate._oid = _rct_interview._candidate_oid
                        LEFT JOIN _rct_interview_synthesis ON _rct_interview_synthesis._interview_oid = _rct_interview._oid

                    WHERE

                        (_rct_interview_by._key=_rct_interview._oid AND _rct_interview_by._val='".$this->getProperty("user_oid")."' and _rct_interview._date >= DATE(NOW( )) )

					group by _rct_interview._oid
                    order by _rct_interview._date ASC , _rct_candidate._first_name ASC , _rct_candidate._last_name ASC

                "; ?>