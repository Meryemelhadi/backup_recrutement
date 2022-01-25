<?php $properties["query"]="
					SELECT 
						_rct_vacancy._oid AS rct_vacancy_oid,
						R_CTRL._key AS rct_vacancy_readonly_key,
						T_CTRL._key AS rct_vacancy_total_control_key,
						_rct_vacancy._manager_oid AS rct_vacancy_manager_oid,
						_rct_vacancy._name AS rct_vacancy_name,
						_rct_vacancy._number AS rct_vacancy_number,
						_rct_vacancy._code AS rct_vacancy_code,
						_rct_vacancy._email AS rct_vacancy_email,
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
						LEFT JOIN _rct_vacancy_total_control AS T_CTRL ON T_CTRL._key = _rct_vacancy._oid 
						LEFT JOIN _rct_vacancy_readonly		 AS R_CTRL ON R_CTRL._key = _rct_vacancy._oid
						 
					WHERE 
						
							".$this->getWhereClause("_rct_vacancy._name",$this->getFieldParam("name","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND
							".$this->getWhereClause("_rct_vacancy._code",$this->getFieldParam("code","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND 
							".$this->getWhereClause("_rct_vacancy._category_oid",$this->getFieldParam("category_oid","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND 
							".$this->getWhereClause("_rct_vacancy._vacancy_project",$this->getFieldParam("vacancy_project","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND 
							".$this->getWhereClause("_rct_vacancy._app_connected",$this->getFieldParam("app_connected","0","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND 
							".$this->getWhereClause("_rct_vacancy._establishment",$this->getFieldParam("establishment","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND 
							".$this->getWhereClause("_rct_vacancy._subsidiary_oid",$this->getFieldParam("subsidiary_oid","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND 
							".$this->getWhereClause("_rct_vacancy._service_oid",$this->getFieldParam("service_oid","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND 
							".$this->getWhereClause("_rct_vacancy._duty_station_oid",$this->getFieldParam("duty_station_oid","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND 
							".$this->getWhereClause("_rct_vacancy._current_step",$this->getFieldParam("current_step","0","|",$record,""),'=','OR','','',true,false,'|','false')." AND 
							".$this->getWhereClause("_rct_vacancy._progress_level",$this->getFieldParam("progress_level","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND 
							".$this->getWhereClause("_rct_vacancy._application_type",$this->getFieldParam("application_type","0","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND 
							".$this->getWhereClause("_rct_vacancy._opening_date",$this->getFieldParam("opening_date","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND 
							".$this->getWhereClause("_rct_vacancy._closing_date",$this->getFieldParam("closing_date","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND 
							_rct_vacancy._workflow_state='2' AND 
							".$this->getWhereClause("_rct_vacancy._archive_state",$this->getFieldParam("archive_state","null","|",$record,""),'=','OR','','',true,false,'|','false')." 
							
						GROUP BY 
							_rct_vacancy._oid  

						ORDER BY 
							_rct_vacancy._vacancy_project DESC,
							_rct_vacancy._opening_date DESC,
							_rct_vacancy._name ASC,
							_rct_vacancy._code ASC 
				"; ?>