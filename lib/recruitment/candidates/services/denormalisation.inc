<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

class lib_recruitment_candidates_services_denormalisation
{
	var $ctxt;

	function lib_recruitment_candidates_services_denormalisation($ctxt)
	{
		$this->ctxt = $ctxt;
		Framework::setContext($this->ctxt = $ctxt);
	}

	public function total() 
	{
		$db = &$this->ctxt->getDB($this->ctxt->error);
		$res = $db->queryWithData('SELECT _oid FROM _rct_candidate');
		foreach ($res as $candidate)
		{
			$this->queries($candidate['_oid'],$db);
	   
		}
		
    }

	public function partial($candidate) 
	{
		$db = &$this->ctxt->getDB($this->ctxt->error);
		$this->queries($candidate,$db);
		
		
    }

	public function queries($candidate,$db)
	{
		   
		$res = $db->queryWithData('
SELECT 
	_date_of_birth ,
	_education._diploma_type as _diploma_type,
	_rct_diploma._label as _diploma,
	_rct_school._label as _institution,
	_employment._employment_start_date AS _last_employment_start_date,
	_employment._employment_end_date AS _last_employment_end_date,
	_employment._employment_content AS _last_employment,
	_training._employment_start_date AS _last_training_start_date,
	_training._employment_end_date AS _last_training_end_date,
	_training._employment_content AS _last_training,
	_rct_provider._oid as _provider
FROM  
	_rct_candidate 
	
	LEFT JOIN _rct_employment as _employment ON _employment._candidate_oid = _rct_candidate._oid AND _employment._type=1 
	
	LEFT JOIN _rct_employment as _employment1 ON _employment1._candidate_oid = _employment._candidate_oid  AND _employment1._type=1 AND _employment._employment_end_date < _employment1._employment_end_date 
	
	LEFT JOIN _rct_employment as _training ON _training._candidate_oid = _rct_candidate._oid AND _training._type=0 
	LEFT JOIN _rct_employment as _training1  ON _training1._candidate_oid = _training._candidate_oid  AND _training1._type=0 AND _training._employment_end_date < _training1._employment_end_date 
	
	LEFT JOIN _rct_education as _education ON _education._candidate_oid = _rct_candidate._oid 
	
	LEFT JOIN _rct_education as _education1 ON _education1._candidate_oid = _education._candidate_oid AND _education._date < _education1._date 
	LEFT JOIN _rct_diploma ON _education._diploma = _rct_diploma._code 
	LEFT JOIN _rct_school ON _education._institution = _rct_school._code 
	LEFT JOIN _rct_candidate_provider ON _rct_candidate_provider._candidate_oid = _rct_candidate._oid
	LEFT JOIN _rct_provider ON _rct_provider._oid = _rct_candidate_provider._provider

WHERE 
	_rct_candidate._archive_state = 0 AND  (_rct_candidate._relevance <> 1 OR _rct_candidate._relevance IS NULL)  AND 
	_employment1._candidate_oid IS NULL  AND 
	_training1._candidate_oid IS NULL  AND 
	_education1._candidate_oid IS NULL and _rct_candidate._oid='.$candidate);

		$diploma_type=htmlspecialchars($res[0]['_diploma_type'],ENT_QUOTES);
		$diploma=htmlspecialchars($res[0]['_diploma'],ENT_QUOTES);
		$institution=htmlspecialchars($res[0]['_institution'],ENT_QUOTES);
		$last_employment=htmlspecialchars($res[0]['_last_employment'],ENT_QUOTES);
		$last_training=htmlspecialchars($res[0]['_last_training'],ENT_QUOTES);
		$provider=htmlspecialchars($res[0]['_provider'],ENT_QUOTES);

	   $db->query('UPDATE `_rct_candidate` SET `_age`= COALESCE(FLOOR((TO_DAYS(NOW())-TO_DAYS("'.$res[0]['_date_of_birth'].'")) / 365.25),0), `_diploma_type` = "'.$diploma_type.'", `_diploma`="'.$diploma.'", `_institution`= "'.$institution.'" , `_last_employment_start_date` ="'.$res[0]['_last_employment_start_date'].'" , `_last_employment_end_date` ="'.$res[0]['_last_employment_end_date'].'" ,  `_last_employment`="'.$last_employment.'" , `_last_training_start_date`="'.$res[0]['_last_training_start_date'].'" , `_last_training_end_date`="'.$res[0]['_last_training_end_date'].'" , `_last_training`="'.$last_training.'", `_provider`="'.$provider.'"   where _rct_candidate._oid= '.$candidate);		   
		   
	}


	public function get_read_state($candidate, $user) 
	{
		
		 $res = $db->queryWithData('SELECT * from _rct_candidate_read_state WHERE _user_oid <> '.$user.' and _candidate_oid='.$candidate); if (!$res) {
			return null;
		}

		$records =  new NxData_ArrayRecords($res, $recDesc,'db');
		return $records;
		
    }

	public function get_user_read_state($candidate, $user) 
	{
		
		 $res = $db->queryWithData('SELECT * from _rct_candidate_read_state WHERE _user_oid ='.$user.' and _candidate_oid='.$candidate); if (!$res) {
			return null;
		}

		$records =  new NxData_ArrayRecords($res, $recDesc,'db');
		return $records;
		
    }
	
}



?>