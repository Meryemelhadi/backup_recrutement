<?php $properties["query"]="
					SELECT
						_rct_short_list._oid AS _oid,
						_rct_short_list._name AS _name,
						_rct_short_list._vacancy_oid AS _vacancy_oid,
						_rct_short_list_vacancy_client._proposed_by AS _proposed_by,
						_rct_short_list_vacancy_client._proposal_date AS _proposal_date,
						_rct_short_list_vacancy_client._comment AS _comment
					FROM
						_rct_short_list_vacancy_client
					LEFT JOIN 
						_rct_short_list ON _rct_short_list_vacancy_client._short_list_oid = _rct_short_list._oid
					WHERE
						_rct_short_list_vacancy_client._vacancy_oid = '".$this->getProperty("vacancy_oid")."'
					ORDER BY
						_rct_short_list_vacancy_client._proposal_date DESC
				"; ?>