<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_candidates_records_client_list
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}

	function getRecords($recDesc,$errorCB,$data,$props) 
	{		
		$parentRecord = $recDesc->parent->getProperty('parentRecord');
		$parentOid = $parentRecord->oid->object;
		
		$query = <<<QUERY

			SELECT
			
			_rct_candidate._oid as _oid,
			_rct_candidate._studies_level AS _studies_level,
			_rct_candidate._cv_path as _cv_path,
			_rct_candidate._first_name as _first_name,
			_rct_candidate._last_name as _last_name,
			COALESCE(FLOOR((TO_DAYS(NOW())-TO_DAYS(_rct_candidate._date_of_birth)) / 365.25),0) as _age,
			_rct_candidate._town_oid as _town_name,
			_rct_candidate._years_of_practice as _years_of_practice,
			_rct_candidate._keywords as _keywords,
			_rct_candidate._reading_state as _reading_state,
			_rct_candidate._relevance as _relevance,
			_rct_candidate._profile AS _profile,
			
			_education_temp._diploma_type as _diploma_type,
			_education_temp._institution as _institution,
			
			_rct_vacancy._oid as _vacancy_oid,
			_rct_vacancy._name as _vacancy_name,
			_rct_vacancy._code as _vacancy_code,
			
			
			_rct_candidate_client._oid AS _candidate_client_oid
	
			FROM 
				_rct_candidate
			
			LEFT JOIN 
				(SELECT	education.* FROM _rct_education AS education
				LEFT JOIN _rct_education AS education1
				ON education._candidate_oid = education1._candidate_oid AND education._date < education1._date
				WHERE education1._candidate_oid IS NULL
				GROUP BY education._candidate_oid) AS _education_temp
				ON _education_temp._candidate_oid = _rct_candidate._oid
			
			LEFT JOIN
				_rct_candidate_vacancy as _vacancy_temp
				ON _vacancy_temp._candidate_oid = _rct_candidate._oid
			LEFT JOIN
				_rct_candidate_vacancy as _vacancy_temp1
				ON _vacancy_temp._candidate_oid = _vacancy_temp1._candidate_oid
				AND _vacancy_temp._add_date < _vacancy_temp1._add_date
			LEFT JOIN 
				_rct_vacancy ON _vacancy_temp._vacancy_oid = _rct_vacancy._oid
				
				
			LEFT JOIN
				_rct_candidate_client ON _rct_candidate_client._candidate_oid = _rct_candidate._oid
				
			WHERE
				_rct_candidate_client._oid = '$parentOid'
				AND
				_vacancy_temp1._candidate_oid IS NULL
	
QUERY;
			
			
			
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