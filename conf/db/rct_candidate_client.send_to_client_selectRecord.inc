<?php $properties["query"]="
					SELECT
						CONCAT_WS(' ', u1._first_name, u1._last_name ) AS _sender,
						u1._email as _sender_email,
						u2._first_name AS _receiver,
						u2._email as _to,
						CONCAT_WS(' ', _rct_candidate._first_name, _rct_candidate._last_name ) AS _candidate,
						_rct_candidate._cv_path as _cv_path,
						_rct_candidate_client._comment,
						_rct_candidate_client._email_title,
						_rct_candidate_client._email_content,
						_rct_candidate_client._email_docs,
						_rct_candidate_client._attached_files,
						_rct_candidate_client._proposed_to as _proposed_to,
						_rct_candidate._oid AS _candidate_oid
					FROM
					_rct_candidate_client
					LEFT JOIN _rct_candidate ON _rct_candidate._oid = _rct_candidate_client._candidate_oid
					LEFT JOIN _user u1 ON u1._oid = _rct_candidate_client._proposed_by
					LEFT JOIN _user u2 ON u2._oid = _rct_candidate_client._proposed_to
					WHERE _rct_candidate_client._oid = '".$props->getProperty("relation_oid")."'
				"; ?>