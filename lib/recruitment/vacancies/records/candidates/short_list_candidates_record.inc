<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_vacancies_records_candidates_short_list_candidates_record
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}

	function getRecords($recDesc,$errorCB,$data,$props) 
	{	
		
		$parentRecord = $recDesc->parent->getProperty('parentRecord');
		//$shortListOid = $parentRecord->oid->object;
		$shortListOid = $this->ctxt->getProperty('short_list_oid');
			
		include 'query_record.inc';
		$query = $query 
			. " AND _rct_candidate._oid IN"
			. " (SELECT _candidate_oid FROM _rct_candidate_short_list WHERE _short_list_oid = $shortListOid) ";

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