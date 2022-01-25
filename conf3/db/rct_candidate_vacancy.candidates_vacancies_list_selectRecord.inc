<?php $properties["query"]="
                    SELECT
                       _rct_vacancy._oid as _oid,
                       _rct_vacancy._manager_oid as _manager_oid,
                       _rct_vacancy._name as _name,
                       _rct_vacancy._number as _number,
                       _rct_vacancy._code as _code,
                       _rct_vacancy._manager_oid as _manager_oid,
                       _rct_vacancy._contract_type_oid as _contract_type_oid,
                       _rct_vacancy._subsidiary_oid as _subsidiary_oid,
                       _rct_vacancy._service_oid as _service_oid,
                       _rct_vacancy._duty_station_oid as _duty_station_oid,
                       _rct_vacancy._establishment as _establishment,
                       _rct_vacancy._current_step as _current_step,
                       _rct_vacancy._progress_level as _progress_level,
                       _rct_vacancy._application_type as _application_type,
                       _rct_vacancy._opening_date as _opening_date,
                       _rct_vacancy._closing_date as _closing_date,
                       _rct_candidate_vacancy._candidate_oid as _candidate_oid,
                       _rct_candidate_vacancy._job_acceptance_state as _job_acceptance_state,
                       _rct_candidate_vacancy._status as _status,
					   _rct_candidate_vacancy._oid as _assoc_oid,
	
					   COALESCE(_rct_candidate_vacancy._ci_acceptance_state, 0) as _ci_acceptance_state,
					   COALESCE(_rct_candidate_vacancy._job_acceptance_state, 0) as _job_acceptance_state,
					   COALESCE(_rct_candidate_vacancy._proposal_acceptance_state, 0) as _proposal_acceptance_state,
					   _rct_candidate_vacancy._proposal_acceptance_date AS _proposal_acceptance_date,
	
					   COALESCE(_rct_candidate_vacancy._status, 0) as _status,
					   COALESCE(_rct_candidate_vacancy._rating, 0) as _rating,
					   COALESCE(_rct_candidate_vacancy._is_visible, 0) as _is_visible


                    FROM
                        _rct_vacancy

                    LEFT JOIN

                        _rct_candidate_vacancy ON _rct_candidate_vacancy._vacancy_oid = _rct_vacancy._oid

                    LEFT JOIN
                        _rct_candidate ON _rct_candidate._oid = _rct_candidate_vacancy._candidate_oid

                    WHERE
                        _rct_candidate_vacancy._candidate_oid = '".$props->getProperty("candidate_oid")."'

                    ORDER BY _name ASC
                "; ?>