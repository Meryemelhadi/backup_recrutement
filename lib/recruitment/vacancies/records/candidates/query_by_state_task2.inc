<?php

	$user = $GLOBALS['_NX_user']->getProperty('oid');

	$query = <<<QUERY
	
SELECT
	_rct_candidate._oid as _oid,
	_rct_candidate._first_name as _first_name,
	UPPER(_rct_candidate._last_name) as _last_name,
	_rct_candidate._update_date AS _update_date,
	_rct_candidate._hr_manager AS _hr_manager,
	_rct_candidate._archive_state AS _hr_manager,

	_rct_candidate_etat._oid as _etat_oid2,
	_rct_candidate_etat._name as _etat_oid,
	_rct_candidate_etat._index as _etat_index,
	_rct_candidate_etat._taskType as _etat_taskType
	
FROM
	_rct_candidate_etat

LEFT JOIN _rct_candidate ON _rct_candidate_etat._oid = _rct_candidate._etat_oid

WHERE
	_rct_candidate._hr_manager = $user AND
	_rct_candidate_etat._in_home <> '0' AND 
	_rct_candidate._archive_state <> '1'

UNION

SELECT
	_rct_candidate._oid as _oid,
	_rct_candidate._first_name as _first_name,
	_rct_candidate._last_name as _last_name,
	_rct_candidate._update_date AS _update_date,
	_rct_candidate._hr_manager AS _hr_manager,
	_rct_candidate._archive_state AS _hr_manager,

	0 as _etat_oid2,
	'(Etat non défini)' as _etat_oid,
	'ZZZ' as _etat_index,
	'' as _etat_taskType
	
FROM
	_rct_candidate
WHERE
	_rct_candidate._hr_manager = $user AND
	_rct_candidate._etat_oid = 0 AND
	_rct_candidate._archive_state <> '1'

ORDER BY 
	_etat_index ASC, _etat_oid2 ASC,
	_last_name, _first_name
	
QUERY;

?>