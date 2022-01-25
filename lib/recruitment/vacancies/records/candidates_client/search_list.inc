<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_vacancies_records_candidates_client_search_list
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}

	function getRecords($recDesc,$errorCB,$data,$props) 
	{	
		include 'query.inc';
		
		$searchRecord = $this->ctxt->getRecord('rct_candidate.vacancy_search',null,'request',false,null);
				
		$fullName = $searchRecord->full_name->object;
		if( trim($fullName) != '' ) {
			$fullName = '%'.str_replace(' ', '%', trim($fullName)).'%';
			$query = $query . 
				" AND ( " .
				"CONCAT_WS(' ', _rct_candidate._first_name, _rct_candidate._last_name) LIKE '$fullName' " .
				"OR " .
				"CONCAT_WS(' ', _rct_candidate._last_name, _rct_candidate._first_name) LIKE '$fullName' )";
		}		
		
		$currentState = $searchRecord->current_state->object;
		if( trim($currentState) != '' ) {
			$query = $query . " AND _rct_candidate_vacancy._status = '$currentState'";
		}
		
		$yearsOfPractice = $searchRecord->years_of_practice->object;
		if( trim($yearsOfPractice) != '' ) {
			$query = $query . " AND _rct_candidate._years_of_practice = '$yearsOfPractice'";
		}
				
		$appType = $searchRecord->application_type->object;
		if( trim($appType) != '' ) {
			if( $appType === '1' ) {	
				$query = $query . "AND (_rct_candidate_vacancy._cv_source_oid IS NOT NULL AND _rct_candidate_vacancy._cv_source_oid <> '0' AND _rct_candidate_vacancy._cv_source_oid <> '' )";
			} else {
				$query = $query . "AND (_rct_candidate_vacancy._cv_source_oid IS NULL OR _rct_candidate_vacancy._cv_source_oid = '0' OR _rct_candidate_vacancy._cv_source_oid = '' )";
			}
		}
		
//		$townOid = $searchRecord->town_oid->object;
//		if( trim($townOid) != '' ) {
//			$query = $query . " AND _directory_town._oid = '$townOid'";
//		}

			
			
		$townOid = $searchRecord->town_oid->object;
		if( trim($townOid) != '' ) {
			$towns = explode('|', $townOid);
			$key .= ' ( ';
			foreach($towns as $town) {
				$key .= " _rct_candidate._town_oid LIKE '".$town."' OR ";
			}
			$key .= ' 0=1 ) AND ';
		}




		
		$shortListOid = $searchRecord->short_list_oid->object;
		if( trim($shortListOid) != '' ) {
			$query = $query . 
				" AND _rct_candidate._oid IN (SELECT _candidate_oid FROM _rct_candidate_short_list WHERE _short_list_oid = '$shortListOid')";
		}		
		
		$diploma = $searchRecord->diploma->object;
		if( trim($diploma) != '' ) {
			$diploma = '%'.str_replace(' ', '%', trim($diploma)).'%';
			$query = $query . " AND _education_temp._diploma_type LIKE '$diploma'";
		}
		
		$query = $query . ' AND _rct_candidate_vacancy._is_visible = 1';

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