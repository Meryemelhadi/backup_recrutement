<?php

require_once(NX_XLIB.'lib/framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_candidates_records_list
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}

	function getRecords($recDesc,$errorCB,$data,$props) 
	{
		// get key record
		$searchRecord = $this->ctxt->getRecord('rct_candidate.search',null,'request',false,null);
		
		$countKey = '';
		$key = '';
		
		$firstName = $searchRecord->first_name->object;
		if( trim($firstName) != '' ) {
			$key .= " _rct_candidate._first_name LIKE '%$firstName%' AND ";
		}
		
		$lastName = $searchRecord->last_name->object;
		if( trim($lastName) != '' ) {
			$key .= " _rct_candidate._last_name LIKE '%$lastName%' AND ";
		}
		
		$age = $searchRecord->age->object;
		if( trim($age) != '' ) {
			$age = (int)$age;
			$key .= ' _rct_candidate._date_of_birth BETWEEN ';
			$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.($age+1).' YEAR), INTERVAL - 1 DAY) AND ';
			$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.$age.' YEAR), INTERVAL + 1 DAY) AND ';
		}
		
		$zip = $searchRecord->zip->object;
		if( trim($zip) != '' ) {
			$key .= " _rct_candidate._zip LIKE '%$zip%' AND ";
		}

		$townOid = $searchRecord->town_oid->object;
		if( trim($townOid) != '' ) {
			$towns = explode('|', $townOid);
			$key .= ' ( ';
			foreach($towns as $town) {
				$key .= " _rct_candidate._town_oid LIKE '".$town."' OR ";
			}
			$key .= ' 0=1 ) AND ';
		}

		$studiesLevel = $searchRecord->studies_level->object;
		if( trim($studiesLevel) != '' ) {
			$key .= " _rct_candidate._studies_level LIKE '%$studiesLevel%' AND ";
		}		
		
		$yearsOfPractice = $searchRecord->years_of_practice->object;
		if( trim($yearsOfPractice) != '' ) {
			$yearsOfPractice = explode('|', $yearsOfPractice);
			$min = trim($yearsOfPractice[0]);
			$max = trim($yearsOfPractice[1]);
			
			if( $min != '' ) {
				$key .= " _rct_candidate._years_of_practice >= '$min' AND ";
			}
			
			if( $max != '' ) {
				$key .= " _rct_candidate._years_of_practice <= '$max' AND ";
			}
		}
		
		$diploma = $searchRecord->diploma->object;
		if( trim($diploma) != '' ) {
			
			$key .= " _education_temp._diploma_type LIKE '%$diploma%' AND ";
		}
		
		
		$school = $searchRecord->school->object;
		if( trim($diploma) != '' ) {
			
			$key .= " _education_temp._institution LIKE '%$school%' AND ";
		}
		
		// @todo : Rechercher avec match against et gérer le degré de pertinence.
		
		$keywords = $searchRecord->match_keywords->object;
		if( trim($keywords) != '' ) {
			
			$sKeywords = '';
			$aKeywords = explode(' ', $keywords);
			for($i=0; $i<count($aKeywords); $i++) {
				$sKeywords .= "_rct_candidate._keywords LIKE '%".$aKeywords[$i]."%' " . ((count($aKeywords)>($i+1))?' OR ':'');
			}
			
			$key .= " ( ".$sKeywords." )  AND ";
		}
		
		
		$profile = $searchRecord->profile->object;
		if( trim($profile) != '' ) {
			$profiles = explode('|', trim($profile, '|'));
			$key .= " ( ";
			for($i=0; $i<count($profiles); $i++) {
				$key .= "_rct_candidate._profile LIKE '%|".$profiles[$i]."|%' ";
				if( count($profiles) > $i+1 ) {
					$key .= ' OR ';
				}		
			}
			$key .= " ) AND ";
		}
		
		$full_text_search = $searchRecord->full_text_search->object;
		if( trim($full_text_search) != '' ) {
			$kWords = explode(' ', $full_text_search);
			$skWords = '';
			for($i=0; $i<count($kWords);$i++) {
				$skWords .= $kWords[$i].'* ';
			}
			$key .= " MATCH (_rct_candidate._src_text) AGAINST ('$skWords' IN BOOLEAN MODE) AND ";
		}
		
		$vacancy = $searchRecord->vacancy->object;
		if( trim($vacancy) != '' ) {
			$key .= " _rct_vacancy._oid = '$vacancy' AND ";
		}
		
		$archiveState = $searchRecord->archive_state->object;
		if( trim($archiveState) != '' ) {
			$key .= " _rct_candidate._archive_state = '$archiveState' AND ";
		}
		
		$relevance = $searchRecord->relevance->object;
		if( trim($relevance) != '' ) {
			if( $relevance == '3' ) { // On exclue les CV non pertinents de la recherche
				$key .= " (_rct_candidate._relevance <> '1' OR _rct_candidate._relevance IS NULL) AND ";
			} else {
				$key .= " _rct_candidate._relevance = '$relevance' AND ";
			}
		}

		// gestion de la pagination
		$pageAlias 		= 'page';
		$pageOffset 	= isset($_GET[$pageAlias])? $_GET[$pageAlias] : 0;
		$recordsPerPage = 10;
		$indexFirst 	= $pageOffset * $recordsPerPage;
		$limit 			= "LIMIT $indexFirst,$recordsPerPage";
		
		/*
			Notes :
				- L'age renvoyé est de quand c'est null afin de faciliter le test au niveau tpl...
		*/

		$fields = <<<QUERY
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
			_rct_vacancy._code as _vacancy_code
QUERY;
		
		$sqlClause = <<<QUERY
	
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
				
			WHERE
				$key
				1=1
				AND
				_vacancy_temp1._candidate_oid IS NULL
		
QUERY;
		
		
		

		$queryCount = <<<QUERY
SELECT 
COUNT(*) as nbrecords
$sqlClause
QUERY;

		$query = <<<QUERY
SELECT 
$fields
$sqlClause
ORDER BY
	_rct_candidate._add_date DESC,
	_rct_candidate._first_name ASC,
	_rct_candidate._last_name ASC
$limit
QUERY;

		$db = &$this->ctxt->getDB($this->error);
		$res = $db->queryWithData($query);
		if (!$res) {
			return null;
		}

		$records =  new NxData_ArrayRecords($res, $recDesc,'db');

		//$totalRecords = count($res);
		//if ($totalRecords >= $recordsPerPage) {
			$resCount = $db->queryWithData($queryCount);
			if ($resCount) {
				$totalRecords=$resCount[0]['nbrecords'];
			}
		//}

		$records->setPageCounters($totalRecords,$pageOffset,$recordsPerPage,$pageAlias);

		return $records;
	}

	function countRecords($recDesc,$errorCB)    {}
}

?>