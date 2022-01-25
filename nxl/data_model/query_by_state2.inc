<?php

	$vacancyOid = $this->ctxt->getProperty('vacancy_oid','');
	$query = <<<QUERY
	
SELECT
	_rct_candidate._oid as _oid,
	_rct_candidate._first_name as _first_name,
	_rct_candidate._last_name as _last_name,
	_rct_candidate._age as _age,
	_rct_candidate._town_oid as _town_name,
	_rct_candidate._years_of_practice as _years_of_practice,
	_rct_candidate._keywords as _keywords,
	_rct_candidate._diploma_type as _diploma_type,
	_rct_candidate._institution as _institution,
	_rct_candidate._cv_path as _cv_path,
	_rct_candidate_vacancy._oid as _assoc_oid,
	_rct_candidate._add_date AS _add_date,
	_rct_candidate._profile AS _profile,
	_rct_candidate._update_date AS _update_date,
	_rct_candidate._studies_level AS _studies_level,
	_rct_candidate._last_employment_start_date AS _last_employment_start_date,
	_rct_candidate._last_employment_end_date AS _last_employment_end_date,
	_rct_candidate. _last_employment AS _last_employment,
	_rct_candidate._last_training_start_date AS _last_training_start_date,
	_rct_candidate._last_training_end_date AS _last_training_end_date,
	_rct_candidate._last_training AS _last_training,
	_rct_candidate._relevance as _relevance,
	_rct_candidate._read_state as _read_state,
	_rct_candidate._user_read_state as _user_read_state,

	_rct_provider._name as _provider,
	
	COALESCE(_rct_candidate_etat._name,'Non classé') as _etat_oid,
	COALESCE(_rct_candidate_etat._index,'ZZZZZZZ') as _etat_index,

	_rct_candidate_etat._color as _etat_color,
	
	COALESCE(_rct_candidate_vacancy._ci_acceptance_state, 0) as _ci_acceptance_state,
	COALESCE(_rct_candidate_vacancy._job_acceptance_state, 0) as _job_acceptance_state,
	COALESCE(_rct_candidate_vacancy._proposal_acceptance_state, 0) as _proposal_acceptance_state,
	_rct_candidate_vacancy._proposal_acceptance_date AS _proposal_acceptance_date,
	
	COALESCE(_rct_candidate_vacancy._status, 0) as _status,
	COALESCE(_rct_candidate_vacancy._rating, 0) as _rating,
	COALESCE(_rct_candidate_vacancy._is_visible, 0) as _is_visible

FROM
_rct_candidate_vacancy 
LEFT JOIN _rct_candidate ON _rct_candidate._oid = _rct_candidate_vacancy._candidate_oid
LEFT JOIN _rct_candidate_etat ON _rct_candidate_etat._oid = _rct_candidate._etat_oid
LEFT JOIN _rct_provider ON _rct_provider._oid = _rct_candidate_vacancy._cv_source_oid

WHERE
	_rct_candidate_vacancy._vacancy_oid = $vacancyOid
	AND _rct_candidate._oid IS NOT NULL
	{$where}

ORDER BY 
	_etat_index ASC, _etat_oid ASC,
	_first_name ASC,_last_name ASC
	
QUERY;
?>