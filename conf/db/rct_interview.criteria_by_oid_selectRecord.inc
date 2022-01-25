<?php $properties["query"]="
					SELECT _evaluation_criteria
					FROM _rct_interview LEFT JOIN _rct_vacancy ON _rct_interview._vacancy_oid = _rct_vacancy._oid
					WHERE _rct_interview._oid = '".$_REQUEST["oid"]."'
				"; ?>