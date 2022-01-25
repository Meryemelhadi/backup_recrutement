<?php $properties["query"]="
					SELECT
						_oid,
						_first_name,
						_last_name,
						CONCAT_WS(' ', _first_name, _last_name) AS _full_name,
						_email
					FROM
						_user
					WHERE
						_oid IN (".$this->getProperty("user_oids").")
				"; ?>