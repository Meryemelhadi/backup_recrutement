<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_vacancies_records_candidates_rated_list
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}

	function getRecords($recDesc,$errorCB,$data,$props) 
	{		
		include 'query.inc';
		$query = $query 
			. ' AND _rct_candidate_vacancy._rating >= 1 '
			. " AND COALESCE(_rct_candidate_vacancy._status,0) <> '8' "
            . ' GROUP BY _rct_candidate._oid'
			. ' ORDER BY _rct_candidate_vacancy._rating DESC';

		$errorCB=new NxErrorCB();
		$db = &$this->ctxt->getDB($errorCB);
		$res = $db->queryWithData($query);
		if (!$res) {
			return null;
		}

		return new NxData_ArrayRecords($res, $recDesc,'db');
	}

	function countRecords($recDesc,$errorCB) {}

}

?>