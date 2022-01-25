<?php

require_once(NX_XLIB.'lib/framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_dashboards_records_recruitments_synthesis
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}
	
	function getDateClause($field, $fieldName, $tableName, $relation) {
		if( $field->toStatus() == 'ok' ) {
			$val = $field->db;
			return " AND _$tableName._$fieldName >= '$val'";
		}
		return '';
	}
	
	function getClause($field, $fieldName, $tableName) {
		
		$val = $field->object;
		if( trim($val) != '' ) {
			return " AND _$tableName._$fieldName = $val";
		}
		return '';
	}
	
	function getKeywordClause($field, $fieldName, $tableName) {
		
		$keywords = $field->object;
		if( trim($keywords) != '' ) {
			$sKeywords = '';
			$aKeywords = explode(' ', $keywords);
			for($i=0; $i<count($aKeywords); $i++) {
				$sKeywords .= "_$tableName._$fieldName LIKE '%".$aKeywords[$i]."%' " . ((count($aKeywords)>($i+1))?' OR ':'');
			}
			return " AND ($sKeywords) ";
		}
		return '';
	}

	function getRecords($recDesc,$errorCB,$data,$props) 
	{
		// get key record
		$searchRecord = $this->ctxt->getRecord('rct_vacancy.dashboards.recruitments_synthesis.search',null,'request',false,null);
		
		$countKey = '';
		$key = '';
			
		$key .= $this->getKeywordClause($searchRecord->name, 'name', 'temp_table');
		$key .= $this->getClause($searchRecord->service_oid, 'service_oid', 'temp_table');
		$key .= $this->getDateClause($searchRecord->opening_date_start, 'opening_date', 'temp_table', '>=');
		$key .= $this->getDateClause($searchRecord->opening_date_end, 'opening_date', 'temp_table', '<=');
		
		$key .= $this->getClause($searchRecord->application_type, 'application_type', 'temp_table');
		$key .= $this->getClause($searchRecord->current_step, 'current_step', 'temp_table');
		$key .= $this->getClause($searchRecord->progress_level, 'progress_level', 'temp_table');


		// gestion de la pagination
		$pageAlias 		= 'page';
		$pageOffset 	= isset($_GET[$pageAlias])? $_GET[$pageAlias] : 0;
		$recordsPerPage = 10;
		$indexFirst 	= $pageOffset * $recordsPerPage;
		
		$limit = "";
		if( (isset($_REQUEST['nxo'])?$_REQUEST['nxo']:"") != 'xls_export' and $_REQUEST['nxo']!='statistics') {
			$limit = "LIMIT $indexFirst,$recordsPerPage";
		}

		$subQuery = <<<QUERY
						
			SELECT
				_rct_vacancy._oid AS _oid,
				_rct_vacancy._name AS _name,
				_rct_vacancy._number AS _number,
				_rct_service._oid AS _service_oid,
				_rct_service._name as _service_name,
				_rct_vacancy._mission_start_date AS _mission_start_date,
				
				(
					SELECT GROUP_CONCAT(_rct_provider._name SEPARATOR ', ') as _providers
					FROM _rct_vacancy_provider
					LEFT JOIN _rct_provider ON _rct_provider._oid = _rct_vacancy_provider._provider_oid
					WHERE _rct_vacancy_provider._vacancy_oid = _rct_vacancy._oid
					GROUP BY _rct_vacancy_provider._vacancy_oid
				) AS _providers,

				_rct_vacancy._client_oid as _client_oid,
				_rct_vacancy._application_type as _application_type,
				_rct_vacancy._current_step AS _current_step,
				_rct_vacancy._suited_diplomas AS _suited_diplomas,
				_rct_vacancy._years_of_practice AS _years_of_practice,
				_rct_vacancy._workflow_state AS _workflow_state,
				_rct_vacancy._progress_level AS _progress_level,
				_rct_vacancy._manager_oid AS _manager_oid,
				(
					SELECT 
						count(*) 
					FROM 
						_rct_candidate_vacancy 
					WHERE 
						_rct_candidate_vacancy._vacancy_oid=_rct_vacancy._oid
				) AS _nb_candidates

			FROM
				_rct_vacancy

			LEFT JOIN
				_rct_service ON _rct_service._oid = _rct_vacancy._service_oid
	
QUERY;
		
		
		$query = <<<QUERY
		
		SELECT * FROM
		($subQuery) AS _temp_table
		WHERE _temp_table._workflow_state = 2
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

		//$totalRecords = count($res);
		//if ($totalRecords >= $recordsPerPage) {
			$resCount = $db->queryWithData($queryCount);
			if ($resCount) {
				$totalRecords=$resCount[0]['nbrecords'];
			}
		//}

		$records->setPageCounters($totalRecords,$pageOffset,$recordsPerPage,$pageAlias);

		return $records;
	}

	function countRecords($recDesc,$errorCB)    {}
}

?>