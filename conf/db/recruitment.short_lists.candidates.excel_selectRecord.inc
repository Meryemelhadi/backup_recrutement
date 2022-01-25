<?php $properties["query"]="
				SELECT
					_rct_candidate._oid as _oid,
					_rct_candidate._first_name as _first_name,
					_rct_candidate._last_name as _last_name,
					_rct_candidate._age as _age,
					_rct_candidate._phone_1 as _phone_1,
					_rct_candidate._mobile as _mobile,
					_rct_candidate._email as _email,
					_rct_candidate._town_oid as _town_name,
					_rct_candidate._years_of_practice as _years_of_practice,
					_rct_candidate._diploma_type as _diploma_type,
					_rct_candidate._institution as _institution,
					_rct_candidate._cv_path as _cv_path,
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
					_rct_candidate._provider as _provider,
					_rct_candidate._etat_oid as _etat_oid
				FROM

					_rct_candidate
					LEFT JOIN _rct_candidate_vacancy ON _rct_candidate._oid = _rct_candidate_vacancy._candidate_oid
					LEFT JOIN _rct_provider ON _rct_provider._oid = _rct_candidate_vacancy._cv_source_oid
					LEFT JOIN _rct_candidate_etat ON _rct_candidate_etat._oid = _rct_candidate._etat_oid

				WHERE
					_rct_candidate_vacancy._vacancy_oid = '".$_REQUEST['vacancy_oid']."'
					AND _rct_candidate._oid IS NOT NULL
					 AND _rct_candidate._oid IN (SELECT _candidate_oid FROM _rct_candidate_short_list WHERE _short_list_oid = '".$_REQUEST['short_list_oid']."')
			"; ?>