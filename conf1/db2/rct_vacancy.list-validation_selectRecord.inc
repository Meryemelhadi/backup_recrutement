<?php $properties["query"]="
					SELECT 
						_rct_vacancy._oid AS rct_vacancy_oid,
						_rct_vacancy._manager_oid AS rct_vacancy_manager_oid,
						_rct_vacancy._name AS rct_vacancy_name,
						_rct_vacancy._number AS rct_vacancy_number,
						_rct_vacancy._code AS rct_vacancy_code,
						_rct_vacancy._category_oid AS rct_vacancy_category_oid,
						_rct_vacancy._contract_type_oid AS rct_vacancy_contract_type_oid,
						_rct_vacancy._subsidiary_oid AS rct_vacancy_subsidiary_oid,
						_rct_vacancy._establishment AS rct_vacancy_establishment,
						_rct_vacancy._service_oid AS rct_vacancy_service_oid,
						_rct_vacancy._duty_station_oid AS rct_vacancy_duty_station_oid,
						_rct_vacancy._current_step AS rct_vacancy_current_step,
						_rct_vacancy._progress_level AS rct_vacancy_progress_level,
						_rct_vacancy._application_type AS rct_vacancy_application_type,
						_rct_vacancy._opening_date AS rct_vacancy_opening_date,
						_rct_vacancy._closing_date AS rct_vacancy_closing_date,
						_rct_vacancy._creator AS rct_vacancy_creator,
						_rct_vacancy._vacancy_project AS rct_vacancy_vacancy_project

					FROM 
						_rct_vacancy
						 
					WHERE 
							_rct_vacancy._workflow_state='1' 
						GROUP BY 
							_rct_vacancy._oid  

						ORDER BY 
							_rct_vacancy._opening_date DESC,
							_rct_vacancy._name ASC,
							_rct_vacancy._code ASC 
				"; ?>