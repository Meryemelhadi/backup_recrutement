<?php $properties["query"]="

					SELECT

						_rct_interview._oid,

						_rct_interview._ical_uid,
						_rct_interview._ical_seq,

						_rct_interview._date,

						_rct_interview._time_start,

						_rct_interview._time_end,

						_rct_interview._vacancy_oid,

						_rct_vacancy._manager_oid AS _manager_oid,

						_rct_vacancy._name AS _vacancy_name,

						_rct_vacancy._code AS _vacancy_code,

						CONCAT_WS(' ', u1._first_name, u1._last_name) AS _creator_full_name,

						CONCAT_WS(' ',_rct_candidate._first_name, _rct_candidate._last_name) AS _candidate_full_name

					FROM

						_rct_interview

					LEFT JOIN

						_rct_vacancy ON _rct_vacancy._oid = _rct_interview._vacancy_oid

					LEFT JOIN

						_user u1 ON u1._oid = _rct_interview._created_by

					LEFT JOIN 

						_rct_candidate ON _rct_candidate._oid = _rct_interview._candidate_oid

					WHERE

						_rct_interview._oid = '".$this->getProperty("interview_oid")."'

				"; ?>