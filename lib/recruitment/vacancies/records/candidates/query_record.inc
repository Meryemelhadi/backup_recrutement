<?php

	$vacancyOid = $this->ctxt->getProperty('vacancy_oid');
	$candidate_oid = $this->ctxt->getProperty('candidate_oid');

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
	
	COALESCE(_rct_candidate_vacancy._ci_acceptance_state, 0) as _ci_acceptance_state,
	COALESCE(_rct_candidate_vacancy._job_acceptance_state, 0) as _job_acceptance_state,
	COALESCE(_rct_candidate_vacancy._proposal_acceptance_state, 0) as _proposal_acceptance_state,
	_rct_candidate_vacancy._proposal_acceptance_date AS _proposal_acceptance_date,
	
	COALESCE(_rct_candidate_vacancy._status, 0) as _status,
	COALESCE(_rct_candidate_vacancy._rating, 0) as _rating,
	COALESCE(_rct_candidate_vacancy._is_visible, 0) as _is_visible
FROM
	_rct_candidate
LEFT JOIN
	_rct_candidate_vacancy
ON
	_rct_candidate._oid = _rct_candidate_vacancy._candidate_oid

WHERE
	_rct_candidate_vacancy._vacancy_oid = $vacancyOid AND
	_rct_candidate._oid = $candidate_oid

	
QUERY;
?>