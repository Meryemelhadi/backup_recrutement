<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_dashboards_records_integrations_synthesis
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
		$searchRecord = $this->ctxt->getRecord('rct_vacancy.dashboards.integrations_synthesis.search',null,'request',false,null);	
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
		
		$key .= $this->getClause($searchRecord->category_oid, 'category_oid', 'temp_table');
		$key .= $this->getClause($searchRecord->contract_type_oid, 'contract_type_oid', 'temp_table');
		
		$key .= $this->getKeywordClause($searchRecord->first_name, 'first_name', 'temp_table');
		$key .= $this->getKeywordClause($searchRecord->last_name, 'last_name', 'temp_table');
		
		$key .= $this->getDateClause($searchRecord->hire_date_start, 'hire_date', 'temp_table', '>=');
		$key .= $this->getDateClause($searchRecord->hire_date_end, 'hire_date', 'temp_table', '<=');
		
		$key .= $this->getDateClause($searchRecord->hire_date_3_month_start, 'hire_date_3_month', 'temp_table', '>=');
		$key .= $this->getDateClause($searchRecord->hire_date_3_month_end, 'hire_date_3_month', 'temp_table', '<=');
		
		$key .= $this->getDateClause($searchRecord->hire_date_6_month_start, 'hire_date_6_month', 'temp_table', '>=');
		$key .= $this->getDateClause($searchRecord->hire_date_6_month_end, 'hire_date_6_month', 'temp_table', '<=');
		
		$key .= $this->getClause($searchRecord->subsidiary_oid, 'subsidiary_oid', 'temp_table');
		$key .= $this->getClause($searchRecord->contrat_signing, 'contrat_signing', 'temp_table');

		$key .= $this->getClause($searchRecord->integration_plan, 'integration_plan', 'temp_table');
		$key .= $this->getClause($searchRecord->integration_note, 'integration_note', 'temp_table');
		$key .= $this->getClause($searchRecord->instant_feedback, 'instant_feedback', 'temp_table');
		$key .= $this->getClause($searchRecord->delayed_feedback, 'delayed_feedback', 'temp_table');
		
		$key .= $this->getKeywordClause($searchRecord->internship_title, 'internship_title', 'temp_table');
		
		$key .= $this->getClause($searchRecord->executive_committee_presentation, 'executive_committee_presentation', 'temp_table');
		$key .= $this->getDateClause($searchRecord->internship_start_start, 'internship_start', 'temp_table', '>=');
		$key .= $this->getDateClause($searchRecord->internship_start_end, 'internship_start', 'temp_table', '<=');
		$key .= $this->getDateClause($searchRecord->internship_end_start, 'internship_end', 'temp_table', '>=');
		$key .= $this->getDateClause($searchRecord->internship_end_end, 'internship_end', 'temp_table', '<=');
		

		$subQuery = <<<QUERY
						
				_rct_candidate._oid AS _candidate_oid,
				_rct_candidate._first_name AS _first_name,
				_rct_candidate._last_name AS _last_name,
				_rct_vacancy_category._oid AS _category_oid,
				_rct_vacancy_category._name AS _category,
				_rct_contract_type._oid AS _contract_type_oid,
				_rct_contract_type._name AS _contract_type,
				_rct_subsidiary._oid AS _subsidiary_oid,
				_rct_subsidiary._name AS _subsidiary,
				COALESCE(_rct_candidate_vacancy._contrat_signing,0) AS _contrat_signing,
				_rct_candidate_vacancy._hire_date,
				DATE_ADD(_rct_candidate_vacancy._hire_date, INTERVAL 3 MONTH) AS _hire_date_3_month,
				DATE_ADD(_rct_candidate_vacancy._hire_date, INTERVAL 6 MONTH) AS _hire_date_6_month,
				COALESCE(_rct_candidate_vacancy._integration_plan,0) AS _integration_plan,
				COALESCE(_rct_candidate_vacancy._integration_note,0) AS _integration_note,
				(SELECT(SELECT COUNT(*) FROM _rct_instant_feedback 
					WHERE _rct_instant_feedback._candidate_oid = _rct_candidate_vacancy._candidate_oid 
					AND _rct_instant_feedback._vacancy_oid = _rct_candidate_vacancy._vacancy_oid
					AND _rct_instant_feedback._fill_state = 1) > 0) AS _instant_feedback,
				(SELECT(SELECT COUNT(*) FROM _rct_delayed_feedback 
					WHERE _rct_delayed_feedback._candidate_oid = _rct_candidate_vacancy._candidate_oid 
					AND _rct_delayed_feedback._vacancy_oid = _rct_candidate_vacancy._vacancy_oid
					AND _rct_delayed_feedback._fill_state = 1) > 0) AS _delayed_feedback,
				_rct_vacancy._internship_title,
				_rct_vacancy._internship_start,
				_rct_vacancy._internship_end,
				COALESCE(_rct_vacancy._executive_committee_presentation,0) AS _executive_committee_presentation
			FROM
				_rct_candidate_vacancy
			LEFT JOIN 
				_rct_candidate ON _rct_candidate_vacancy._candidate_oid = _rct_candidate._oid
			LEFT JOIN 
				_rct_vacancy ON _rct_candidate_vacancy._vacancy_oid = _rct_vacancy._oid
			LEFT JOIN 
				_rct_vacancy_category ON _rct_vacancy._category_oid = _rct_vacancy_category._oid
			LEFT JOIN 
				_rct_contract_type ON _rct_vacancy._contract_type_oid = _rct_contract_type._oid
			LEFT JOIN 
				_rct_subsidiary ON _rct_vacancy._subsidiary_oid = _rct_subsidiary._oid
			WHERE
				_rct_candidate_vacancy._job_acceptance_state='1'
QUERY;
	
		
		$query = <<<QUERY
		
		SELECT SQL_CALC_FOUND_ROWS * FROM
		(SELECT $subQuery) AS _temp_table
		WHERE 1=1
		$key
		GROUP BY _temp_table._candidate_oid
		$limit
		
QUERY;
	
		$queryCount = 'SELECT FOUND_ROWS() as nbrecords';

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

/*		
		$query = <<<QUERY
		
		SELECT * FROM
		($subQuery) AS _temp_table
		WHERE 1=1
		$key
		GROUP BY _temp_table._candidate_oid
		$limit
		
QUERY;
	
		$queryCount = <<<QUERY
		SELECT COUNT(*) as nbrecords FROM
		($subQuery) AS _temp_table
		WHERE 1=1
		$key
		GROUP BY _temp_table._candidate_oid
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

*/
/*
		$query = <<<QUERY
		SELECT SQL_CALC_FOUND_ROWS
		$subQuery	
		$key
		GROUP BY _rct_candidate._oid
		$limit
		
QUERY;

		$queryCount = 'SELECT FOUND_ROWS() as nbrecords';

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
*/
	}

	function countRecords($recDesc,$errorCB)    {}
}

?>