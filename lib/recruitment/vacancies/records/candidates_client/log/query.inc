<?php

	$vacancyOid = $this->ctxt->getProperty('vacancy_oid');
	$query = <<<QUERY
	
SELECT 
	join_table._oid,
	join_table._candidate_oid as _candidate_oid,
	join_table._vacancy_oid as _vacancy_oid,
	join_table._user_oid as _user_oid,
	join_table._date as _date,
	join_table._action_oid as _action_oid,
	join_table._ref_oid as _ref_oid,
	join_table._additional_infos as _additional_infos,
	CONCAT_WS(' ', _rct_candidate._first_name, _rct_candidate._last_name) as _candidate_full_name,
	CONCAT_WS(' ', _user._first_name, _user._last_name) as _user_full_name,
	_rct_short_list._name as _short_list_name,
	_rct_interview._date as _interview_date,
	_rct_interview._time_start as _interview_time_start
FROM 
	_rct_candidate_vacancy_action AS join_table
LEFT JOIN
	_rct_interview
	ON _rct_interview._oid = join_table._ref_oid	
LEFT JOIN
	_rct_candidate
	ON _rct_candidate._oid = join_table._candidate_oid
LEFT JOIN
	_user
	ON _user._oid = join_table._user_oid
LEFT JOIN
	_rct_short_list
	ON _rct_short_list._oid = join_table._ref_oid
WHERE
	join_table._vacancy_oid = $vacancyOid
	
QUERY;
?>