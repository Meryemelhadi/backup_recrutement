<?php $properties["query"]="
					SELECT
						CONCAT_WS(' ', u1._first_name, u1._last_name ) AS _sender,
						u1._email as _sender_email,
						CONCAT_WS(' ', _rct_candidate._first_name, _rct_candidate._last_name ) AS _candidate,
						_rct_candidate._cv_path as _cv_path,
						_rct_candidate_client._comment,
						_rct_candidate_proposed_to._val as _proposed_to,
						_rct_candidate._oid AS candidate_oid
					FROM
					_rct_candidate_client
					LEFT JOIN _rct_candidate ON _rct_candidate._oid = _rct_candidate_client._candidate_oid
					LEFT JOIN _rct_candidate_proposed_to ON _rct_candidate_proposed_to._key= _rct_candidate_client._oid
					LEFT JOIN _user u1 ON u1._oid = _rct_candidate_client._proposed_by
					WHERE _rct_candidate_client._oid = '".$props->getProperty("relation_oid")."'
				"; ?>