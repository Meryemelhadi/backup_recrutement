<?php $properties["query"]="

					SELECT
						_rct_short_list._name AS _short_list_name,
						_rct_short_list_vacancy_client._proposed_by AS _proposed_by,
						_rct_short_list_vacancy_client._proposal_date AS _proposal_date,
						_rct_short_list_vacancy_client._comment AS _comment,
						_rct_vacancy._name AS _vacancy_name,
						_rct_vacancy._client_oid AS _client_oid

					FROM
						_rct_short_list_vacancy_client

					LEFT JOIN
						_rct_vacancy ON _rct_vacancy._oid = _rct_short_list_vacancy_client._vacancy_oid

					LEFT JOIN
						_rct_short_list ON _rct_short_list_vacancy_client._short_list_oid = _rct_short_list._oid

					WHERE
						_rct_short_list_vacancy_client._oid = '".$this->getProperty("record_oid")."'

					ORDER BY
						_rct_short_list_vacancy_client._proposal_date DESC

				"; ?>