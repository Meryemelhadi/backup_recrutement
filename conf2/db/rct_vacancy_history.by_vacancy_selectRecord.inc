<?php $properties["query"]="

					SELECT a.*

					FROM _rct_vacancy_history AS a

					LEFT JOIN _rct_vacancy_history AS c ON (

					    SELECT MIN(_oid) FROM _rct_vacancy_history AS b WHERE b._oid > a._oid

					) = c._oid

					WHERE (a._progress_level <> c._progress_level OR c._progress_level IS NULL) AND a._vacancy_oid = '".$_REQUEST['oid']."'

					ORDER BY a._date DESC

				"; ?>