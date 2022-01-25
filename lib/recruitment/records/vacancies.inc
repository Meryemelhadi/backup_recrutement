<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_records_vacancies
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}

	function getRecords($recDesc,$errorCB,$data,$props) 
	{	
		debugBreak();
		$parentRecord = $recDesc->parent->getProperty('parentRecord');
		$parentOid = $parentRecord->oid->object;
		$query = <<<QUERY SELECT _rct_vacancy._oid,
						_rct_vacancy._name,
						_rct_vacancy._code
						FROM _rct_vacancy  
						Left join _rct_candidate_vacancy ON _rct_candidate_vacancy._vacancy_oid = _rct_vacancy._oid
						WHERE _rct_candidate_vacancy._candidate_oid = '91'
					QUERY;

		$errorCB=new NxErrorCB();
		$db = &$this->ctxt->getDB($errorCB);
		$res = $db->queryWithData($query);
		if (!$res) {
			$query = <<<QUERY SELECT _rct_vacancy._oid , _rct_vacancy._name,
						_rct_vacancy._code FROM _rct_vacancy QUERY;
			$errorCB=new NxErrorCB();
			$db = &$this->ctxt->getDB($errorCB);
			$res = $db->queryWithData($query);
			if (!$res) {
				return null;
			}
		}

		return new NxData_ArrayRecords($res, $recDesc,'db');
	}

}

?>