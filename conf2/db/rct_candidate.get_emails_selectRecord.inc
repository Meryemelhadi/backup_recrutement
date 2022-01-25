<?php $properties["query"]="
					SELECT
						_oid,
						_first_name,
						_last_name,
						CONCAT_WS(' ', _first_name, _last_name) AS _full_name,
						_email
					FROM
						_rct_candidate
					WHERE
						_oid IN (".$props->getProperty("candidate_oids").")
				"; ?>