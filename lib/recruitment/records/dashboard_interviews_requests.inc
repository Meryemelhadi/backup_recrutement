<?php
require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_records_dashboard_interviews_requests
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}

	function getRecords($recDesc,$errorCB,$data,$props) 
	{
		$searchRecord = $this->ctxt->getProperty('page.search');

		if($searchRecord)
		{
			$kWords = $searchRecord->name->db;
		}
		else
			$kWords = '';


		$countKey = '';
		$key = '';

		// gestion de la pagination
		$pageAlias 		= 'page';
		$pageOffset 	= isset($_GET[$pageAlias])? $_GET[$pageAlias] : 0;
		$recordsPerPage = 10;
		$indexFirst 	= $pageOffset * $recordsPerPage;

		$limit = "";
		if(
				((isset($_REQUEST['nxo'])?$_REQUEST['nxo']:"") != 'export_excel' ) &&
				((isset($_REQUEST['nopage'])?$_REQUEST['nopage']:"") != '1' )
			) 
		{
			$limit = "LIMIT $indexFirst,$recordsPerPage";
		}

// DebugBreak();
				
		$query = <<<QUERY
		
		SELECT SQL_CALC_FOUND_ROWS 
			INTERV.*,
			CAND._oid AS _candidate_oid,
			CONCAT_WS(' ',CAND._first_name,CAND._last_name) AS _candidate,		
			
			IFNULL(VAC._name,IFNULL(VAC2._name,'')) as _vacancy,
			VAC._name as _vacancy1,
			VAC._oid as _vacancy1_oid,

			VAC2._name as _vacancy2,
			VAC2._oid as _vacancy2_oid,

			IFNULL(VAC._oid,IFNULL(VAC2._oid,'')) as _vacancy_oid,

			CAND_VAC.*

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

		ORDER BY INTERV._date DESC

		$limit		
QUERY;

		// exec query
		$errorCB=new NxErrorCB();
		$db = &$this->ctxt->getDB($errorCB);
		$res = $db->queryWithData($query);
		if (!$res) {

		}
		$records =  new NxData_ArrayRecords($res, $recDesc,'db');
			
		// count records for pagination
		$queryCount = 'SELECT FOUND_ROWS() as nbrecords';
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