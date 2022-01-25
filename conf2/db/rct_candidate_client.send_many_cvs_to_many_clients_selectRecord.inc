<?php $properties["query"]="
					SELECT
						CONCAT_WS(' ', u1._first_name, u1._last_name ) AS _sender,
						u1._email as _sender_email,
						_rct_candidate_client._comment,
						_rct_candidate_client._proposed_to,
						_rct_candidate_client._candidate_oid
					FROM
					_rct_candidate_client
					LEFT JOIN _user u1 ON u1._oid = _rct_candidate_client._proposed_by
					WHERE _rct_candidate_client._oid = '".$props->getProperty("relation_oid")."'
				"; ?>