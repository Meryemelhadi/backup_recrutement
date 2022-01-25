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
				
		if( isset( $_REQUEST['alphabet_filter'] ) ) {
			if( trim($_REQUEST['alphabet_filter']) != '' ) {
				$key = "_rct_candidate._first_name LIKE '".$_REQUEST['alphabet_filter']."%'";
			}
		}
		
		$firstName = $searchRecord->first_name->object;
		if( trim($firstName) != '' ) {
			$key .= (trim($key) == '')?'':' AND ';
			$key .= " _rct_candidate._first_name LIKE '%$firstName%' ";
		}
		
		$lastName = $searchRecord->last_name->object;
		if( trim($lastName) != '' ) {
			$key .= (trim($key) == '')?'':' AND ';
			$key .= " _rct_candidate._last_name LIKE '%$lastName%' ";
		}
		
		$age = $searchRecord->age->object;
		if( trim($age) != '' ) {
			$age = (int)$age;
			$key .= (trim($key) == '')?'':' AND ';
			$key .= ' _rct_candidate._date_of_birth BETWEEN ';
			$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.($age+1).' YEAR), INTERVAL - 1 DAY) AND ';
			$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.$age.' YEAR), INTERVAL + 1 DAY) ';
		}
		
		$townOid = $searchRecord->town_oid->object;
		if( trim($townOid) != '' ) {
			$key .= (trim($key) == '')?'':' AND ';
			$townOid = str_replace('|', ',', trim($townOid, '|'));
			$key .= " _rct_candidate._town_oid IN ($townOid) ";
		}
		
		$studiesLevel = $searchRecord->studies_level->object;
		if( trim($studiesLevel) != '' ) {
			$key .= (trim($key) == '')?'':' AND ';
			$key .= " _rct_candidate._studies_level LIKE '%$studiesLevel%' ";
		}		
		
		$yearsOfPractice = $searchRecord->years_of_practice->object;
		if( trim($yearsOfPractice) != '' ) {
			$yearsOfPractice = explode('|', $yearsOfPractice);
			$min = trim($yearsOfPractice[0]);
			$max = trim($yearsOfPractice[1]);
			
			if( $min != '' ) {
				$key .= (trim($key) == '')?'':' AND ';
				$key .= " _rct_candidate._years_of_practice >= '$min' ";
			}
			
			if( $max != '' ) {
				$key .= (trim($key) == '')?'':' AND ';
				$key .= " _rct_candidate._years_of_practice <= '$max' ";
			}
		}
		
		$diploma = $searchRecord->diploma->object;
		if( trim($diploma) != '' ) {
			$key .= (trim($key) == '')?'':' AND ';
			$key .= " _education_temp._diploma_type LIKE '%$diploma%' ";
		}
		
		$school = $searchRecord->school->object;
		if( trim($diploma) != '' ) {
			$key .= (trim($key) == '')?'':' AND ';
			$key .= " _education_temp._institution LIKE '%$school%' ";
		}
		
		// @todo : Rechercher avec match against et gérer le degré de pertinence.
		
		$keywords = $searchRecord->match_keywords->object;
		if( trim($keywords) != '' ) {
			$key .= (trim($key) == '')?'':' AND ';
			$sKeywords = '';
			$aKeywords = explode(' ', $keywords);
			for($i=0; $i<count($aKeywords); $i++) {
				$sKeywords .= "_rct_candidate._keywords LIKE '%".$aKeywords[$i]."%' " . ((count($aKeywords)>($i+1))?' OR ':'');
			}
			
			$key .= " ( ".$sKeywords." ) ";
		}
		
		
		$profile = $searchRecord->profile->object;
		if( trim($profile) != '' ) {
			$key .= (trim($key) == '')?'':' AND ';
			$profiles = explode('|', trim($profile, '|'));
			$key .= " ( ";
			for($i=0; $i<count($profiles); $i++) {
				$key .= "_rct_candidate._profile LIKE '%|".$profiles[$i]."|%' ";
				if( count($profiles) > $i+1 ) {
					$key .= ' OR ';
				}		
			}
			$key .= " ) ";
		}
		
		
		$full_text_search = $searchRecord->full_text_search->object;
		if( trim($full_text_search) != '' ) {
			$key .= (trim($key) == '')?'':' AND ';
			
			$kWords = explode(' ', $full_text_search);
			$skWords = '';
			for($i=0; $i<count($kWords);$i++) {
//				 $skWords .= $kWords[$i].'* ';
				 $skWords .= $kWords[$i].' ';
			}

			// manage accents
			$skWords = preg_replace('/éàçèêô/i','*',utf8_decode($skWords));
			
			$key .= " MATCH (_rct_candidate._src_text) AGAINST ('$skWords' IN BOOLEAN MODE)";
		}
		
		
		
		
		
		
		
		
		
		
		
		
		$vacancy = $searchRecord->vacancy->object;
		if( trim($vacancy) != '' ) {
			$key .= (trim($key) == '')?'':' AND ';
			$key .= " _rct_vacancy._oid = '$vacancy' ";
		}
		
		$archiveState = $searchRecord->archive_state->object;
		if( trim($archiveState) != '' ) {
			$key .= (trim($key) == '')?'':' AND ';
			$key .= " _rct_candidate._archive_state = '$archiveState' ";
		}
		
		$relevance = $searchRecord->relevance->object;
		if( trim($relevance) != '' ) {
			$key .= (trim($key) == '')?'':' AND ';
			if( $relevance == '3' ) { // On exclue les CV non pertinents de la recherche
				$key .= " (_rct_candidate._relevance <> '1' OR _rct_candidate._relevance IS NULL) ";
			} else {
				$key .= " _rct_candidate._relevance = '$relevance' ";
			}
		}
		
		if($key != '') {
			$key .= ' AND ';
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
			_rct_candidate._town_oid as _town_oid,
			_rct_candidate._years_of_practice as _years_of_practice,
			_rct_candidate._keywords as _keywords,
			_rct_candidate._reading_state as _reading_state,
			_rct_candidate._relevance as _relevance,
			_rct_candidate._profile AS _profile,
			
			_education_temp._diploma_type as _diploma_type,
			_education_temp._institution as _institution,
			
			_directory_town._town_name as _town_name,
			_rct_vacancy._oid as _vacancy_oid,
			_rct_vacancy._name as _vacancy_name,
			_rct_vacancy._code as _vacancy_code
QUERY;
		
		$sqlClause = <<<QUERY
	
			FROM 
				_rct_candidate
			LEFT JOIN
				_rct_education as _education_temp
				ON _education_temp._candidate_oid = _rct_candidate._oid
			LEFT JOIN
				_rct_education as _education_temp1
				ON _education_temp._candidate_oid = _education_temp1._candidate_oid
				AND _education_temp._date < _education_temp1._date
			
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
				_directory_town ON _directory_town._oid = _rct_candidate._town_oid
			WHERE
				$key
				_vacancy_temp1._candidate_oid IS NULL
				AND
				_education_temp1._candidate_oid IS NULL
		
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
		$errorCB=new NxErrorCB();
		$db = &$this->ctxt->getDB($errorCB);
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