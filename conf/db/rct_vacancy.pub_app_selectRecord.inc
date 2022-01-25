<?php $properties["query"]="
					SELECT 
						V._oid AS _oid,
						V._cand_channel AS _cand_channel,
						V._name AS _name,
						V._email AS _email,
						V._number AS _number,
						V._code AS _code,
						V._opening_date AS _opening_date,
						V._contract_type_oid AS _contract_type_oid,
						V._duty_station_oid AS _duty_station_oid,

						V._mission_definitions AS _mission_definitions,
						V._organisme_definitions AS _organisme_definitions,
						V._descriptionProfil AS _descriptionProfil,
						V._technical_qualifications AS _technical_qualifications,
						V._behavioral_qualifications AS _behavioral_qualifications,
						
						
						V._work_schedule AS _work_schedule,
						V._suited_diplomas AS _suited_diplomas,
						V._companies_having_same_profile AS _companies_having_same_profile,
						V._mission_means AS _mission_means,
						V._years_of_practice AS _years_of_practice,
						CA._url AS _url,
						CA._description As _description

					FROM 
						_rct_vacancy AS V 
						RIGHT JOIN _rct_app_connected as CA ON  V._app_connected like CONCAT('%|', CA._oid ,'|%')

					WHERE 
						V._current_step='0' AND (V._closing_announce_date IS NULL OR V._closing_announce_date > NOW() ) AND
						(V._archive_state = '0') AND 
						(V._workflow_state='1' OR V._workflow_state='2') AND 
						V._app_connected IS NOT NULL
						AND CA._url like '%".$_REQUEST['origine']."%'
						-- AND CA._key = '".$_REQUEST['key']."'
						
					GROUP BY 
						V._oid  

					ORDER BY 
						V._opening_date DESC,
						V._name ASC,
						V._code ASC
				"; ?>