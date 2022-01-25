<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/
class NxControl_progress_level
{
	function NxControl_progress_level()
	{
	}
	
	function toHTML($value,&$f)
	{	
		$fname = $f->desc->getProperty('field', NULL, false);
		$actionOid = $f->record->$fname->object;
		
		$fname = $f->desc->getProperty('key', NULL, false);
		$vacancyOid = $f->record->$fname->object;
		
		nxLog('Nadir: '.$actionOid);
		
		switch($actionOid) {
			case '2':
				// Liste des cabinets de recrutement
				return $this->getProvidersList($vacancyOid,$f);
				break;
			case '3':
				// Liste des candidats associés au dossier
				return $this->getCandidatesList(0,$vacancyOid,$f); // depuis l'historique
				break;
			case '4':
				// Liste des candidats envoyés aux clients internes
				return $this->getCandidatesList(2,$vacancyOid,$f); // depuis l'historique
				break;
			case '6':
				// Liste des candidats pour lesquels on a planifié un entretien
				return $this->getCandidatesList(4,$vacancyOid,$f);
				break;
			case '7':
				// Liste des candidats ayant accepté la proposition
				return $this->getCandidatesListFromAssoc(1, 'proposal_acceptance_state',$vacancyOid,$f); // depuis la table rct_candidate_vacancy
				break;
			case '8':
				// Liste des candidats ayant refusé la proposition
				return $this->getCandidatesListFromAssoc(2, 'proposal_acceptance_state',$vacancyOid,$f); // depuis la table rct_candidate_vacancy
				break;
			case '9':
				// Liste des candidats retenus pour le poste
				return $this->getCandidatesListFromAssoc(1, 'job_acceptance_state',$vacancyOid,$f); // depuis la table rct_candidate_vacancy
				break;
			case '10':
				// Liste des candidats désélectionnés du le poste
				return $this->getCandidatesList(18,$vacancyOid,$f);
				break;
			case '11':
				// Liste des candidats désélectionnés du le poste
				return $this->getCandidatesList(9,$vacancyOid,$f);
				break;
			
		}
		
		return '';
	}
	
	
	function getProvidersList($vacancyOid,$f) {
		
			$query = <<<QUERY
		
	SELECT
		GROUP_CONCAT(_rct_provider._name SEPARATOR ', ') as _providers
	FROM
		_rct_vacancy_provider
	LEFT JOIN 
		_rct_provider ON _rct_provider._oid = _rct_vacancy_provider._provider_oid
	WHERE
		_rct_vacancy_provider._vacancy_oid = $vacancyOid
	GROUP BY
		_rct_vacancy_provider._vacancy_oid
		
QUERY;
	
			$db = $f->desc->getDB($this->error);
			$res = $db->queryWithData($query);
			if ($res) {
				return $res[0]['_providers'];
			}
			return '';
		}
		
		
	function getCandidatesListFromAssoc($statusOid, $field, $vacancyOid,$f) {
		
		
		
		$query = <<<QUERY
		
		SELECT
			GROUP_CONCAT(CONCAT_WS(' ',_rct_candidate._first_name, _rct_candidate._last_name) SEPARATOR ', ') as _concerned_people
		FROM
			_rct_candidate_vacancy
		LEFT JOIN
			_rct_candidate ON _rct_candidate_vacancy._candidate_oid = _rct_candidate._oid
		WHERE
			_rct_candidate_vacancy._$field = $statusOid
			AND
			_rct_candidate_vacancy._vacancy_oid = $vacancyOid
		GROUP BY 
			_rct_candidate_vacancy._vacancy_oid
		
QUERY;

		
	
		$candidatesList = '';
		$errorCB=new NxErrorCB();
		$db = $f->desc->getDB($errorCB);
		$res = $db->queryWithData($query);
		if ($res) {
			$candidatesList = $res[0]['_concerned_people'];
		}
	
		return $candidatesList;
	}
	
	
	
	
	
	
	function getCandidatesList($actionOid, $vacancyOid,$f) {
	
		$query = <<<QUERY
	
SELECT
	GROUP_CONCAT(_concerned_people SEPARATOR ', ') as _concerned_people
FROM
	(SELECT
		_rct_candidate_vacancy_action._vacancy_oid,
		CONCAT_WS(' ',_rct_candidate._first_name, _rct_candidate._last_name) as _concerned_people
	FROM
		_rct_candidate_vacancy_action
	LEFT JOIN
		_rct_candidate ON _rct_candidate_vacancy_action._candidate_oid = _rct_candidate._oid
	WHERE 
		_action_oid = $actionOid AND 
		_vacancy_oid = $vacancyOid AND 
		_date > (
			SELECT 
				COALESCE(MAX(_date),'1970-01-01 00:00:00') 
			FROM 
				_rct_candidate_vacancy_action 
			WHERE 
				_action_oid <> $actionOid AND 
				_vacancy_oid = $vacancyOid AND 
				_date < (
					SELECT 
						MAX(_date) 
					FROM 
						_rct_candidate_vacancy_action 
					WHERE 
						_action_oid = $actionOid AND 
						_vacancy_oid = $vacancyOid))
	GROUP BY 
		_rct_candidate._oid) AS _temp_table
GROUP BY _vacancy_oid
	
QUERY;



		$candidatesList = '';
		
		
		
		$errorCB=new NxErrorCB();
		$db = $f->desc->getDB($errorCB);
		$res = $db->queryWithData($query);
		if ($res) {
			
			$candidatesList = $res[0]['_concerned_people'];
		}
	
		return $candidatesList;
	}
}

?>