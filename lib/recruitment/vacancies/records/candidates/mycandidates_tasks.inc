<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_vacancies_records_candidates_mycandidates_tasks
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}

	function getRecords($recDesc,$errorCB,$data,$props) 
	{	
		include 'query_by_state_task.inc';
		
		/*
			Règles:
				- Le candidat ne doit pas être noté ou le score est égal à 0
				- Le statut du candidat ne doit pas être 'rejeté' ou 'sélectionné pour le poste' (7,8)
		*/
		
		/*$query = $query
			. ' AND (_rct_candidate_vacancy._rating IS NULL OR _rct_candidate_vacancy._rating = 0) '
			. " AND COALESCE(_rct_candidate_vacancy._status,0) <> '8' ";*/


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