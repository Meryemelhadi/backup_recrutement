SELECT 
	_rct_candidate._oid as _oid,

	_rct_candidate._read_state as _read_state,
	_rct_candidate._user_read_state as _user_read_state,
	
	_rct_candidate_category._name AS _category_oid,
	_rct_candidate._first_name as _first_name,
	_rct_candidate._last_name as _last_name,
	_rct_candidate._studies_level AS _studies_level,
	_rct_candidate._cv_path as _cv_path,

	_rct_candidate._age as _age, -- temp
	
	_rct_candidate._zip as _zip,
	_rct_candidate._creation_date as _creation_date,
	_rct_candidate._update_date as _update_date,
	
	_rct_candidate._town_name as _town_name, -- temp

	_rct_candidate._years_of_practice as _years_of_practice,
	_rct_candidate._keywords as _keywords,
	_rct_candidate._reading_state as _reading_state,
	_rct_candidate._relevance as _relevance,
	_rct_candidate._profile AS _profile,
	_rct_candidate._add_date AS _add_date,

	_education._diploma_type as _diploma_type,
	_rct_diploma._label as _diploma,
	_rct_school._label as _institution,
	_rct_vacancy._oid as _vacancy_oid,
	_rct_vacancy._name as _vacancy_name,
	_rct_vacancy._code as _vacancy_code,
	
	_employment._salary_min_exp AS _salary_min_exp,
	_employment._salary_max_exp AS _salary_max_exp,

	_employment._employment_start_date AS _last_employment_start_date,
	_employment._employment_end_date AS _last_employment_end_date,
	_employment._employment_content AS _last_employment,
	_training._employment_start_date AS _last_training_start_date,
	_training._employment_end_date AS _last_training_end_date,
	_training._employment_content AS _last_training,

	_rct_candidate._hr_manager AS _hr_manager,
	_rct_provider._name as _provider,

	_rct_candidate_etat._name as _etat_oid
		
	FROM
	(
		SELECT 
			_rct_candidate._oid as _oid,
			
			(CASE WHEN rs._candidate_oid > 0 THEN 1 ELSE 0 END) AS _read_state,
			(CASE WHEN rs1._candidate_oid > 0 THEN 1 ELSE 0 END) AS _user_read_state,
			
			_rct_candidate._first_name as _first_name,
			_rct_candidate._last_name as _last_name,
			_rct_candidate._studies_level AS _studies_level,
			_rct_candidate._cv_path as _cv_path,
			COALESCE(FLOOR((TO_DAYS(NOW())-TO_DAYS(_rct_candidate._date_of_birth)) / 365.25),0) as _age,
			_rct_candidate._zip as _zip,
			_rct_candidate._creation_date as _creation_date,
			_rct_candidate._update_date as _update_date,
			_rct_candidate._town_oid as _town_name,
			_rct_candidate._years_of_practice as _years_of_practice,
			_rct_candidate._keywords as _keywords,
			_rct_candidate._reading_state as _reading_state,
			_rct_candidate._relevance as _relevance,
			_rct_candidate._profile AS _profile,
			_rct_candidate._add_date AS _add_date,

			_rct_candidate._hr_manager AS _hr_manager,

			_rct_candidate._etat_oid as _etat_oid
		FROM 
		 _rct_candidate

		-- Récupération état de lecture		
		LEFT JOIN _rct_candidate_read_state AS rs ON rs._candidate_oid = _rct_candidate._oid
		LEFT JOIN (SELECT * FROM _rct_candidate_read_state rs1 WHERE rs1._user_oid = '4624') AS rs1 ON rs1._candidate_oid = _rct_candidate._oid


		WHERE
			 _rct_candidate._archive_state = '0' AND  (_rct_candidate._relevance <> '1' OR _rct_candidate._relevance IS NULL)  AND  (rs._candidate_oid IS NULL)
			
		GROUP BY _rct_candidate._oid
		ORDER BY  _rct_candidate._update_date DESC, _rct_candidate._first_name ASC, _rct_candidate._last_name ASC 
		LIMIT 0,10
	) 

	AS _rct_candidate

	LEFT JOIN
		_rct_employment as _employment
		ON _employment._candidate_oid = _rct_candidate._oid AND _employment._type=1

	LEFT JOIN
		_rct_employment as _training
		ON _training._candidate_oid = _rct_candidate._oid AND _training._type=0

	LEFT JOIN
		_rct_education as _education
		ON _education._candidate_oid = _rct_candidate._oid

	LEFT JOIN
		_rct_candidate_vacancy as _vacancy_temp
		ON _vacancy_temp._candidate_oid = _rct_candidate._oid
	
	LEFT JOIN 
		_rct_vacancy ON _vacancy_temp._vacancy_oid = _rct_vacancy._oid
		
	LEFT JOIN
		_rct_diploma ON _education._diploma = _rct_diploma._code
		
		
	LEFT JOIN
		_rct_school ON _education._institution = _rct_school._code
			
	-- Récupération de la catégorie
	LEFT JOIN _rct_candidate_category_assoc ON _rct_candidate._oid = _rct_candidate_category_assoc._key
	LEFT JOIN _rct_candidate_category ON _rct_candidate_category_assoc._val = _rct_candidate_category._oid
	LEFT JOIN _rct_provider ON _rct_provider._oid = _vacancy_temp._cv_source_oid
	LEFT JOIN _rct_candidate_etat ON _rct_candidate_etat._oid = _rct_candidate._etat_oid

	GROUP BY _rct_candidate._oid
