<?php $properties["query"]="
					SELECT
						_rct_candidate_vacancy_client._proposed_by AS _proposed_by,
						_rct_candidate_vacancy_client._proposal_date AS _proposal_date,
						_rct_candidate_vacancy_client._comment AS _comment,

						_rct_vacancy._name AS _vacancy_name,
						_rct_vacancy._client_oid AS _client_oid,

						CONCAT_WS(' ', _rct_candidate._first_name, _rct_candidate._last_name ) AS _candidate,
						_rct_candidate._cv_path as _cv_path,
						_rct_candidate._oid AS _candidate_oid

					FROM
						_rct_candidate_vacancy_client

					LEFT JOIN _rct_vacancy   ON _rct_vacancy._oid   = _rct_candidate_vacancy_client._vacancy_oid				
					LEFT JOIN _rct_candidate ON _rct_candidate._oid = _rct_candidate_vacancy_client._candidate_oid 

					WHERE
						_rct_candidate_vacancy_client._oid = '".$this->getProperty("record_oid")."'

					ORDER BY
						_rct_candidate_vacancy_client._proposal_date DESC

				"; ?>