<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_vacancies_records_candidates_client_proposed_list
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}

	function getRecords($recDesc,$errorCB,$data,$props) 
	{	
		include 'query.inc';
		$parent = $recDesc->getProperty('parentRecord');
		$candidateOids = $parent->candidate_oid->object;
		
		if( trim($candidateOids) == '' ) {
			return null;
		}
		
		
		
		$query = $query . ' AND _rct_candidate_vacancy._candidate_oid IN ('.str_replace('|',',',trim($candidateOids,'|')).')';
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