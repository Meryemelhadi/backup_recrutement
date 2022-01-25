<?php $properties["query"]="

					SELECT *
					FROM _rct_vacancy_history AS a WHERE a._vacancy_oid =".$props->getProperty("vacancy_oid")." AND a._progress_level !=3 AND _progress_level_meta IS NOT NULL AND _progress_level_meta != ''
					UNION SELECT * FROM _rct_vacancy_history AS b
					WHERE _oid = (
						SELECT MAX( _oid )
						FROM _rct_vacancy_history AS b
						WHERE b._vacancy_oid =".$props->getProperty("vacancy_oid")."
						AND b._progress_level =3
						AND _progress_level_meta IS NOT NULL
						AND _progress_level_meta != '' )
					ORDER BY _date DESC

				"; ?>