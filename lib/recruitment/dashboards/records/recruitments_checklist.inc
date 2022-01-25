<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_dashboards_records_recruitments_checklist
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}

	function getRecords($recDesc,$errorCB,$data,$props) 
	{
		$searchRecord = $this->ctxt->getRecord('rct_vacancy.dashboards.recruitments_checklist.search',null,'request',false,null);	
		$countKey = '';
		$key = '';

		// gestion de la pagination
		$pageAlias 		= 'page';
		$pageOffset 	= isset($_GET[$pageAlias])? $_GET[$pageAlias] : 0;
		$recordsPerPage = 10;
		$indexFirst 	= $pageOffset * $recordsPerPage;

		$limit = "";
		if( (isset($_REQUEST['nxo'])?$_REQUEST['nxo']:"") != 'xls_export' ) {
			$limit = "LIMIT $indexFirst,$recordsPerPage";
		}

		$kWords = $searchRecord->name->object;
		if( trim($kWords) != '' ) {
			$kWords = explode(' ', $kWords);
			$skWords = '';
			for($i=0; $i<count($kWords);$i++) {
				$skWords .= $kWords[$i].'* ';
			}
			$key .= " AND MATCH (_temp_table._name) AGAINST ('$skWords' IN BOOLEAN MODE)";
		}
		
		$kWords = $searchRecord->recruitment_motivation->object;
		if( trim($kWords) != '' ) {
			$kWords = explode(' ', $kWords);
			$skWords = '';
			for($i=0; $i<count($kWords);$i++) {
				$skWords = $kWords[$i].'* ';
			}
			$key .= " AND MATCH (_temp_table._recruitment_motivation) AGAINST ('$skWords' IN BOOLEAN MODE)";
		}
		
		$val = $searchRecord->announcement->object;
		if( trim($val) != '' ) {
			$key .= " AND _temp_table._announcement = $val";
		}
		
		$val = $searchRecord->instant_feedback->object;
		if( trim($val) != '' ) {
			$key .= " AND _temp_table._instant_feedback = $val";
		}
		
		$val = $searchRecord->delayed_feedback->object;
		if( trim($val) != '' ) {
			$key .= " AND _temp_table._delayed_feedback = $val";
		}

		if( $searchRecord->opening_date_start->toStatus() == 'ok' ) {
			$val = $searchRecord->opening_date_start->db;
			$key .= " AND _temp_table._mission_start_date >= '$val'";
		}
		
		
		if( $searchRecord->opening_date_end->toStatus() == 'ok' ) {
			$val = $searchRecord->opening_date_end->db;
			$key .= " AND _temp_table._mission_start_date <= '$val'";
		}

		
		if( $searchRecord->closing_date_start->toStatus() == 'ok' ) {
			$val = $searchRecord->closing_date_start->db;
			$key .= " AND _temp_table._closing_date >= '$val'";
		}
		
		if( $searchRecord->closing_date_end->toStatus() == 'ok' ) {
			$val = $searchRecord->closing_date_end->db;
			$key .= " AND _temp_table._closing_date <= '$val'";
		}
		
		$val = $searchRecord->contract_type_oid->object;
		if( trim($val) != '' ) {
			$key .= " AND _temp_table._contract_type_oid = $val";
		}
		
		$val = $searchRecord->category_oid->object;
		if( trim($val) != '' ) {
			$key .= " AND _temp_table._category_oid = $val";
		}
		
		$val = $searchRecord->current_step->object;
		if( trim($val) != '' ) {
			$key .= " AND _temp_table._current_step = $val";
		}
		
		$val = $searchRecord->application_type->object;
		if( trim($val) != '' ) {
			$key .= " AND _temp_table._application_type = $val";
		}

		$subQuery = <<<QUERY
				
			SELECT
				_rct_vacancy._name AS _name,
				-- _rct_vacancy._recruitment_motivation AS _recruitment_motivation,
				(SELECT (SELECT COUNT(*) FROM _rct_announcement WHERE _rct_announcement._vacancy_oid = _rct_vacancy._oid) > 0) AS _announcement,
				(SELECT (SELECT COUNT(*) FROM _rct_instant_feedback WHERE _rct_instant_feedback._vacancy_oid = _rct_vacancy._oid AND _rct_instant_feedback._fill_state='1') > 0) AS _instant_feedback,
				(SELECT (SELECT COUNT(*) FROM _rct_delayed_feedback WHERE _rct_delayed_feedback._vacancy_oid = _rct_vacancy._oid AND _rct_delayed_feedback._fill_state='1') > 0) AS _delayed_feedback,
				_rct_vacancy._mission_start_date, -- Lancement
				_rct_vacancy._suited_recruitment_date, -- 
				_rct_vacancy._closing_date, -- 
				_rct_vacancy._taking_office_date, -- Démarrage
				ABS(DATEDIFF(_rct_vacancy._closing_date, _rct_vacancy._mission_start_date)) AS _open_close_delay,
				ABS(DATEDIFF(_rct_vacancy._taking_office_date, _rct_vacancy._closing_date)) AS _close_taking_office_delay,	
				(
					SELECT 
						GROUP_CONCAT(CONCAT_WS(' ',_rct_candidate._first_name, _rct_candidate._last_name) SEPARATOR ', ') as _concerned_people
					FROM 
						_rct_candidate_vacancy
					LEFT JOIN _rct_candidate ON _rct_candidate_vacancy._candidate_oid = _rct_candidate._oid
					WHERE 
						_rct_candidate_vacancy._job_acceptance_state = 1
						AND _rct_candidate_vacancy._vacancy_oid = _rct_vacancy._oid
				
					GROUP BY _rct_candidate_vacancy._vacancy_oid
				) AS _selected_people,
				
				(
					SELECT 
						GROUP_CONCAT(_rct_provider._name SEPARATOR ', ') as _providers				
					FROM 
						_rct_vacancy_provider
						LEFT JOIN _rct_provider ON _rct_provider._oid = _rct_vacancy_provider._provider_oid
				
					WHERE 
							_rct_vacancy_provider._vacancy_oid = _rct_vacancy._oid
			
					GROUP BY 
							_rct_vacancy_provider._vacancy_oid
				) AS _providers,

				_rct_contract_type._oid AS _contract_type_oid,
				_rct_contract_type._name AS _contract_type,
				_rct_vacancy_category._oid AS _category_oid,
				_rct_vacancy_category._name AS _category,
				_rct_vacancy._workflow_state AS _workflow_state,
				_rct_vacancy._current_step AS _current_step,
				_rct_vacancy._application_type as _application_type,
				_rct_vacancy._manager_oid AS _manager_oid,


				(
					SELECT 
						MIN(_proposal_acceptance_date) 
					FROM 
						_rct_candidate_vacancy 
					WHERE 
						_rct_candidate_vacancy._vacancy_oid=_rct_vacancy._oid
				) AS _proposal_acceptance_date,

				(
					SELECT 
						count(*) 
					FROM 
						_rct_candidate_vacancy 
					WHERE 
						_rct_candidate_vacancy._vacancy_oid=_rct_vacancy._oid
				) AS _nb_candidates,

				INTRVW._count as _nb_interviews


			FROM
				_rct_vacancy
				LEFT JOIN _rct_vacancy_category ON _rct_vacancy_category._oid = _rct_vacancy._category_oid				
				LEFT JOIN _rct_contract_type ON _rct_contract_type._oid = _rct_vacancy._contract_type_oid
				LEFT JOIN 
				(
					SELECT  
						
						IFNULL(VAC._name,IFNULL(VAC2._name,'')) as _vacancy,
						IFNULL(VAC._oid,IFNULL(VAC2._oid,'')) as _vacancy_oid,
						count(*) AS _count

					FROM 
						_rct_interview AS INTERV

						LEFT JOIN _rct_candidate AS CAND ON CAND._oid=INTERV._candidate_oid

						-- vacancy attached to the interview
						LEFT JOIN _rct_vacancy AS VAC ON VAC._oid = INTERV._vacancy_oid

						-- vacancy attached to the candidate
						LEFT JOIN (
							SELECT 
								_candidate_oid,_vacancy_oid, _add_date
							FROM 
								_rct_candidate_vacancy 
							GROUP BY _rct_candidate_vacancy._candidate_oid 
							ORDER BY _add_date DESC
						) AS CAND_VAC ON CAND_VAC._candidate_oid = CAND._oid

						--  LEFT JOIN _rct_candidate_vacancy AS CAND_VAC ON CAND_VAC._candidate_oid = CAND._oid
						LEFT JOIN _rct_vacancy AS VAC2 ON VAC2._oid = CAND_VAC._vacancy_oid

					WHERE
							INTERV._validation_state<>2 AND 
							CAND._oid IS NOT NULL

					GROUP BY _vacancy_oid

				) AS INTRVW ON INTRVW._vacancy_oid = _rct_vacancy._oid
	
QUERY;
		
		
		$query = <<<QUERY
		
		SELECT 
			* 
		FROM
			($subQuery) AS _temp_table

		WHERE 
			_temp_table._workflow_state = 2
		$key
		$limit
		
QUERY;
		
		
		
		$queryCount = <<<QUERY
		SELECT COUNT(*) as nbrecords FROM
		($subQuery) AS _temp_table
		WHERE _temp_table._workflow_state = 2
		$key
QUERY;

		$errorCB=new NxErrorCB();
		$db = &$this->ctxt->getDB($errorCB);
		$res = $db->queryWithData($query);
		if (!$res) {
			return null;
		}

		$records =  new NxData_ArrayRecords($res, $recDesc,'db');

		$resCount = $db->queryWithData($queryCount);
		if ($resCount) {
			$totalRecords=$resCount[0]['nbrecords'];
		}

		$records->setPageCounters($totalRecords,$pageOffset,$recordsPerPage,$pageAlias);

		return $records;
	}

	function countRecords($recDesc,$errorCB)    {}
}

?>