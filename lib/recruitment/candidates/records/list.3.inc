<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_candidates_records_list
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}

	function catchMatchExpr($prefix,$exp,&$words) {
		$words[] = $prefix.'"'.$exp.'"';
		return '';
	}
	
	function replaceAccents($str) {
		return str_replace( array('à','á','â','ã','ä','ç','è','é','ê','ë','ì','í','î','ï','ñ','ò','ó','ô','õ','ö','ù','ú','û','ü','ý','ÿ','À','Á','Â','Ã','Ä','Ç','È','É','Ê','Ë','Ì','Í','Î','Ï', 'Ñ','Ò','Ó','Ô','Õ','Ö','Ù','Ú','Û','Ü','Ý'), array('a','a','a','a','a','c','e','e','e','e','i','i','i','i','n','o','o','o','o','o','u','u','u','u','y','y','a','a','a','a','a','c','e','e','e','e','e','i','i','i','i','n','o','o','o','o','o','u','u','u','u','y'), $str);
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
			$key .= " _rct_candidate._first_name LIKE '%$firstName%' AND ";
		}
		
		$lastName = $searchRecord->last_name->object;
		if( trim($lastName) != '' ) {
			$key .= " _rct_candidate._last_name LIKE '%$lastName%' AND ";
		}
		
		$gender = $searchRecord->gender->object;
		if( trim($gender) != '' ) {
			$key .= " _rct_candidate._gender = '$gender' AND ";
		}
		
		$age = $searchRecord->age->object;
		if( trim($age) != '' ) {
			$age = explode('|', $age);
			$min = trim($age[0]);
			$max = trim($age[1]);
			
			// Si le min et le max sont définis
			if( $min != '' && $max != '' ) {
				$min = (int)$min;
				$max = (int)$max;
				$key .= ' _rct_candidate._date_of_birth BETWEEN ';
				$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.($max+1).' YEAR), INTERVAL - 1 DAY) AND ';
				$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.$min.' YEAR), INTERVAL + 1 DAY) ';
				
			}
			
			// Si uniquement le min est défini
			if( $min != '' && $max == '' ) {
				$min = (int)$min;
				$key .= ' _rct_candidate._date_of_birth <= ';
				$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.$min.' YEAR), INTERVAL + 1 DAY) ';
			}
			
			// Si uniquement le max est défini
			// Si uniquement le min est défini
			if( $min == '' && $max != '' ) {
				$max = (int)$max;
				$key .= ' _rct_candidate._date_of_birth >= ';
				$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.($max+1).' YEAR), INTERVAL - 1 DAY) ';
			}
			
			$key .= ' AND ';
		}
		
		$townOid = $searchRecord->town_oid->object;
		if( trim($townOid) != '' ) {
			nxLog($townOid);
		
			$towns = explode('|', trim($townOid));
			$key .= ' ( ';
			foreach($towns as $town) {
				$key .= " _rct_candidate._town_oid LIKE '%".$town."%' OR ";
			}
			$key .= ' 0=1 ) AND ';
		}
		
		
		$studiesLevel = $searchRecord->studies_level->object;
		if( trim($studiesLevel) != '' ) {
			$key .= " _rct_candidate._studies_level LIKE '$studiesLevel' AND ";
		}
		
		$updateDateMin = $searchRecord->update_date_min->db;
		//echo $updateDate;
		if( trim($updateDateMin) != '' && $updateDateMin != 'NULL' ) {
			$key .= " CAST(_rct_candidate._update_date AS DATE) >= '$updateDateMin' AND ";
		}
		$updateDateMax = $searchRecord->update_date_max->db;
		//echo $updateDate;
		if( trim($updateDateMax) != '' && $updateDateMax != 'NULL' ) {
			$key .= " CAST(_rct_candidate._update_date AS DATE) <= '$updateDateMax' AND ";
		}
		$yearsOfPractice = $searchRecord->years_of_practice->object;
		if( trim($yearsOfPractice) != '' ) {
			$yearsOfPractice = explode('|', $yearsOfPractice);
			$min = trim($yearsOfPractice[0]);
			$max = trim($yearsOfPractice[1]);
			
			$yopClause = '';
			if( $min != '' ) {
				$yopClause = " _rct_candidate._years_of_practice >= '$min' ";
			}
			if( $max != '' ) {
				if( $min != '' ) {
					$yopClause .= ' AND ';
				}
				$yopClause .=  " _rct_candidate._years_of_practice <= '$max' ";
			}
			$key .= $yopClause. ' AND ';
		}

		$diploma = $searchRecord->diploma->object;
		if( trim($diploma) != '' ) {			
			$diplomas = explode(',', trim($diploma));
			$key .= " ( ";
			for($i=0; $i<count($diplomas); $i++) {
				$key .= "_education._diploma LIKE '".$diplomas[$i]."' ";
				if( count($schools) > $i+1 ) {
					$key .= ' OR ';
				}		
			}
			$key .= " ) AND ";
		}

		$school = $searchRecord->school->object;
		if( trim($school) != '' ) {
			$schools = explode(',', trim($school));
			$key .= " ( ";
			for($i=0; $i<count($schools); $i++) {
				$key .= "_education._institution LIKE '".$schools[$i]."' ";
				if( count($schools) > $i+1 ) {
					$key .= ' OR ';
				}		
			}
			$key .= " ) AND ";		
		}
		
		$category = $searchRecord->category_oid->object;
		if( trim($category) != '' ) {
			$key .= " _rct_candidate._category_oid LIKE '%|$category|%' AND ";
		}
		
		// @todo : Rechercher avec match against et gérer le degré de pertinence.
		$keywords = $searchRecord->match_keywords->object;

		if( trim($keywords) != '' ) {
			$sKeywords = '';
			$aKeywords = explode(' ', $keywords);
			for($i=0; $i<count($aKeywords); $i++) {
				$sKeywords .= "_rct_candidate._keywords LIKE '%".$aKeywords[$i]."%' " . ((count($aKeywords)>($i+1))?' OR ':'');
			}
			$key .= " ( ".$sKeywords." ) AND ";
		}

		$profile = $searchRecord->profile->object;
		
		
		
		if( trim($profile) != '' ) {
			$profiles = explode(',', trim($profile));
			$key .= " ( ";
			
			
			$clauseTpl = <<<EOH
			(CASE WHEN _rct_candidate._profile  REGEXP '^,%s,?' > 0 THEN 3 ELSE  0 END +
			CASE WHEN _rct_candidate._profile  REGEXP '.+,%s,.+' > 0 THEN 2 ELSE  0 END +
			CASE WHEN _rct_candidate._profile  REGEXP '.+,+%s,$' > 0 THEN 1 ELSE  0 END) +
EOH;
			
			$profileSql = '';
			$profileRelevance = '';
			foreach($profiles as $profile) {
				$profileSql .= " _rct_candidate._profile LIKE '%,".$profile.",%' AND";
				$profileRelevance .= str_replace("%s", $profile, $clauseTpl);

				
			}
			$key .= rtrim($profileSql, 'AND')." ) AND ";
			$profileRelevance = rtrim(trim($profileRelevance),'+'). ' AS _profile_relevance,';
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		}
		
		$relevanceField = '';
		$full_text_search = $searchRecord->full_text_search->object;
		
		
		if( trim($full_text_search) != '' ) {
		
			$full_text_search = $this->replaceAccents($full_text_search);
		
			$words=array();
			$full_text_search = preg_replace(
				array('/&quot;/','/\\\"/','/([+-]?)"([^"]+)"/e'),
				array('"','"','$this->catchMatchExpr("$1","$2",$words);'),
					$full_text_search);
			$kWords = array_merge(explode(' ', trim($full_text_search)),$words);
			
			//
			// Clause de recherche MATCH AGAINST
			//			
			$matchClause = " MATCH (_rct_candidate._src_text) AGAINST ('".implode(' ', $kWords)."' IN BOOLEAN MODE) ";
			$key .= " $matchClause AND "; // Ce qui va être mis dans le where 
			
			//
			// Pertinence de la recherche
			//
			foreach($kWords as $keyword) {
				$keyword = trim($keyword);
				if( ($fChar = substr ( $keyword, 0, 1)) != '-' && $keyword != '' ) {
					// Suppression des caractères spéciaux de la recherche booléenne
					if( in_array($fChar, array('<','>','+','-','~','*','"','(',')')) ) {
						$keyword = substr($keyword, 1);	
					}
					// Suppression des quotes pour les expressions exactes
					$keyword = str_replace( '"','',$keyword);
					// Ajout dans le tas
					$sqlExpression .= sprintf("(( length(lower(%s)) - length(replace(lower(%s),'%s','')) ) / length('%s')) +", '_rct_candidate._src_text', '_rct_candidate._src_text', $keyword, $keyword); 
				}	
			}
			
			if( trim($sqlExpression) != '' ) {
				$relevanceField = rtrim($sqlExpression, '+')." AS _relevance_rate, ";
			}	
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
				$key .= " (_rct_candidate._relevance <> '1' OR _rct_candidate._relevance IS NULL) ";
			} else {
				$key .= " _rct_candidate._relevance = '$relevance' ";
			}
			$key .= ' AND ';
		}	

                if($_REQUEST['nxo']=="list" || $_REQUEST['nxo']==NULL)
		{
		// gestion de la pagination
		$pageAlias 		= 'page';
		$pageOffset 	= isset($_GET[$pageAlias])? $_GET[$pageAlias] : 0;
		$recordsPerPage = 10;
		$indexFirst 	= $pageOffset * $recordsPerPage;
		$limit 			= "LIMIT $indexFirst,$recordsPerPage";
		}
        
$fields = <<<FIELDS
	_rct_candidate._oid as _oid,
	
	(CASE WHEN rs._candidate_oid > 0 THEN 1 ELSE 0 END) AS _read_state,
	(CASE WHEN rs1._candidate_oid > 0 THEN 1 ELSE 0 END) AS _user_read_state,
	
	$profileRelevance
	$relevanceField
	
	GROUP_CONCAT(_rct_candidate_category._name SEPARATOR ', ') AS _category_oid,
	_rct_candidate._first_name as _first_name,
	_rct_candidate._last_name as _last_name,
	_rct_candidate._studies_level AS _studies_level,
	_rct_candidate._cv_path as _cv_path,
	COALESCE(FLOOR((TO_DAYS(NOW())-TO_DAYS(_rct_candidate._date_of_birth)) / 365.25),0) as _age,
	_rct_candidate._creation_date as _creation_date,
	_rct_candidate._update_date as _update_date,
	_rct_candidate._town_oid as _town_name,
	_rct_candidate._years_of_practice as _years_of_practice,
	_rct_candidate._keywords as _keywords,
	_rct_candidate._reading_state as _reading_state,
	_rct_candidate._relevance as _relevance,
	_rct_candidate._profile AS _profile,
	_rct_candidate._add_date AS _add_date,
	_rct_candidate._update_date AS _update_date,
	_education._diploma_type as _diploma_type,
	_rct_diploma._label as _diploma,
	_rct_school._label as _institution,
	-- _education._institution as _institution,
	_rct_vacancy._oid as _vacancy_oid,
	_rct_vacancy._name as _vacancy_name,
	_rct_vacancy._code as _vacancy_code,
	_employment._employment_start_date AS _last_employment_start_date,
	_employment._employment_end_date AS _last_employment_end_date,
	_employment._employment_content AS _last_employment,
	_training._employment_start_date AS _last_training_start_date,
	_training._employment_end_date AS _last_training_end_date,
	_training._employment_content AS _last_training
FIELDS;

$userOid = $GLOBALS["_NX_user"]->getProperty("oid","",true);

$sqlClause = <<<WHERECLAUSE
	FROM 
		_rct_candidate
	
	LEFT JOIN
		_rct_employment as _employment
		ON _employment._candidate_oid = _rct_candidate._oid AND _employment._type=1
	LEFT JOIN
		_rct_employment as _employment1
		ON _employment1._candidate_oid = _employment._candidate_oid  AND _employment1._type=1
		AND _employment._employment_end_date < _employment1._employment_end_date
	
	LEFT JOIN
		_rct_employment as _training
		ON _training._candidate_oid = _rct_candidate._oid AND _training._type=0
	LEFT JOIN
		_rct_employment as _training1
		ON _training1._candidate_oid = _training._candidate_oid  AND _training1._type=0
		AND _training._employment_end_date < _training1._employment_end_date

	LEFT JOIN
		_rct_education as _education
		ON _education._candidate_oid = _rct_candidate._oid
	LEFT JOIN
		_rct_education as _education1
		ON _education1._candidate_oid = _education._candidate_oid
		AND _education._date < _education1._date

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
		_rct_diploma ON _education._diploma = _rct_diploma._code
		
		
	LEFT JOIN
		_rct_school ON _education._institution = _rct_school._code
	
	-- Récupération de l\'état de lecture	
	LEFT JOIN (SELECT * FROM _rct_candidate_read_state rs1 WHERE rs1._user_oid <> '$userOid') AS rs ON rs._candidate_oid = _rct_candidate._oid
	LEFT JOIN (SELECT * FROM _rct_candidate_read_state rs1 WHERE rs1._user_oid = '$userOid') AS rs1 ON rs1._candidate_oid = _rct_candidate._oid
		
	-- Récupération de la catégorie
	LEFT JOIN _rct_candidate_category_assoc ON _rct_candidate._oid = _rct_candidate_category_assoc._key
	LEFT JOIN _rct_candidate_category ON _rct_candidate_category_assoc._val = _rct_candidate_category._oid

	WHERE
		$key
		1=1
		AND _employment1._candidate_oid IS NULL 
		AND _training1._candidate_oid IS NULL 
		AND _education1._candidate_oid IS NULL
WHERECLAUSE;

$queryCount = <<<COUNTQUERY
	SELECT COUNT(*) as nbrecords FROM (SELECT	
	COUNT(*) as nbrecords
	$sqlClause
	GROUP BY _rct_candidate._oid) AS COUNTTBL
COUNTQUERY;

if( $relevanceField != '' || $profileRelevance != '' ) {
	if( $profileRelevance != '' ) {
		$order = ' _profile_relevance DESC,';
	}
	if( $relevanceField != '' ) {
		$order = ' _relevance_rate DESC';
	}
	
	$order = rtrim($order, ',');
} else {
	$order = ' _rct_candidate._update_date DESC, _rct_candidate._first_name ASC, _rct_candidate._last_name ASC ';
}

//le tri	
			if($searchRecord->sort_by->object !="")
			$order="_".$searchRecord->sort_by->object;

$query = <<<QUERY
	SELECT 
	$fields
	$sqlClause
	GROUP BY _rct_candidate._oid
	ORDER BY $order
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