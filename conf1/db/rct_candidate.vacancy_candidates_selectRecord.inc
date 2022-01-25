<?php $properties["query"]="
					SELECT
						_oid,
						_first_name,
						_last_name
					FROM
						_rct_candidate
					WHERE
						_oid IN ( SELECT _candidate_oid FROM _rct_candidate_vacancy WHERE _vacancy_oid = '".$props->getProperty("vacancy_oid")."' )
				"; ?>