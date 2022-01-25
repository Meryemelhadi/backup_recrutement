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
    
    function splitRange($val)
    {
		if(strpos($val,'-')!==false)
			$sep = '-';
		else
			$sep = '|';

		$res = explode($sep, $val);
		return array(trim($res[0]),trim($res[1]));
    }

	function getRecords($recDesc,$errorCB,$data,$props) 
	{
		$userOid = $GLOBALS["_NX_user"]->getProperty("oid","",true);		

		// get key record
		$searchRecord = $this->ctxt->getRecord('rct_candidate.search@recruitment',null,'request',false,null);
		
		$countKey = false;

		$key = '';

		if( isset( $_REQUEST['alphabet_filter'] ) ) {
			if( trim($_REQUEST['alphabet_filter']) != '' ) {
				$key = "_rct_candidate._first_name LIKE '".$_REQUEST['alphabet_filter']."%'";
			}
		}
		$firstName = $searchRecord->first_name->object;
		if( trim($firstName) != '' ) {
			$countKey = true;
			$key .= " _rct_candidate._first_name LIKE '%$firstName%' AND ";
		}
		
		$lastName = $searchRecord->last_name->object;
		if( trim($lastName) != '' ) {
			$countKey = true;
			$key .= " _rct_candidate._last_name LIKE '%$lastName%' AND ";
		}
		
		$etat = $searchRecord->etat_oid->object;
		if( trim($etat) != '' ) {
			$countKey = true;
			$key .= " _rct_candidate_etat._oid=".$etat." AND ";
		}

		/*$gender = $searchRecord->gender->object;
		if( trim($gender) != '' ) {
			$countKey = true;
			$key .= " _rct_candidate._gender = $gender AND ";
		}*/
		
		$age = $searchRecord->age->object;
		if( trim($age) != '' ) {
			$countKey = true;
			list($min,$max) = $this->splitRange($age);
			
			// Si le min et le max sont définis
			if( $min != '' && $max != '' ) {
				$min = (int)$min;
				$max = (int)$max;
				$key .= ' (_rct_candidate._age BETWEEN '.$min.' AND '.$max .')';
				//$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.($max+1).' YEAR), INTERVAL - 1 DAY) AND ';
				//$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.$min.' YEAR), INTERVAL + 1 DAY) ';
				
			}
			
			// Si uniquement le min est défini
			if( $min != '' && $max == '' ) {
				$min = (int)$min;
				$key .= ' _rct_candidate._age  >= '.$min;
				//$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.$min.' YEAR), INTERVAL + 1 DAY) ';
			}
			
			// Si uniquement le max est défini
			if( $min == '' && $max != '' ) {
				$max = (int)$max;
				$key .= ' _rct_candidate._age <= '.$max;
				//$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.($max+1).' YEAR), INTERVAL - 1 DAY) ';
			}
			
			$key .= ' AND ';
		}

		$salary = $searchRecord->salary->object;
		if( trim($salary) != '' ) {
			$countKey = true;
			list($min,$max) = $this->splitRange($salary);
			
			// Si le min et le max sont définis
			if( $min != '' && $max != '' ) 
			{
				$min = (int)$min;
				$max = (int)$max;
				// $key .= ' ((_rct_candidate._salary_max+_rct_candidate._salary_min) BETWEEN '.$min.' AND '.$max.')';
				$key .= ' ((_rct_candidate._salary_min)  >= '.$min;
				$key .= ' AND (_rct_candidate._salary_max+_rct_candidate._salary_min) <= '.$max.')';
			}
			
			// Si uniquement le min est défini (fixe)
			if( $min != '' && $max == '' ) {
				$min = (int)$min;
				$key .= ' (_rct_candidate._salary_min)  >= '.$min;
//				$key .= ' (_rct_candidate._salary_min+_rct_candidate._salary_max)  >= '.$min;
			}
			
			// Si uniquement le max est défini (fixe+var)
			if( $min == '' && $max != '' ) {
				$max = (int)$max;
				$key .= ' (_rct_candidate._salary_max+_rct_candidate._salary_min) <= '.$max;
			}
			
			$key .= ' AND ';
		}

		$salary = $searchRecord->current_salary->object;
		if( trim($salary) != '' ) {
			$countKey = true;
			list($min,$max) = $this->splitRange($salary);
			
			// Si le min et le max sont définis
			if( $min != '' && $max != '' ) 
			{
				$min = (int)$min;
				$max = (int)$max + $min;
				$key .= ' ((_employment._salary_max_exp+_employment._salary_min_exp) BETWEEN '.$min.' AND '.$max.') ';
			}
			
			// Si uniquement le min est défini
			if( $min != '' && $max == '' ) {
				$min = (int)$min;
				$key .= ' (_employment._salary_max_exp+_employment._salary_min_exp)  >= '.$min;
				//$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.$min.' YEAR), INTERVAL + 1 DAY) ';
			}
			
			// Si uniquement le max est défini
			if( $min == '' && $max != '' ) {
				$max = (int)$max;
				$key .= ' (_employment._salary_max_exp+_salary_min_exp) <= '.$max;
				//$key .= ' SUBDATE(SUBDATE("'.strftime("%Y-%m-%d").'", INTERVAL '.($max+1).' YEAR), INTERVAL - 1 DAY) ';
			}
			
			$key .= ' AND ';
		}

		
		$townOid = $searchRecord->town_oid->object;
		if( trim($townOid) != '' ){
			$towns = explode(' ', trim($townOid));
			//$towns = explode('/', trim($towns));
			$key .= ' ( ';
			foreach($towns as $town) {
			
				if(is_numeric($town))
					$key .= " _rct_candidate._zip LIKE '".$town."%' OR ";
				else
				$key .= " _rct_candidate._town_oid LIKE '%".$town."%' OR ";
			}
			$key .= ' 0=1 ) AND ';
		}		
		
		$studiesLevel = $searchRecord->studies_level->object;
		if( ($studiesLevel = trim($studiesLevel)) != '' ) {
			$countKey = true;
			if($studiesLevel == 'Bac+5+')
				$key .= " _rct_candidate._studies_level in ('Bac+5','Bac+6','Bac+7','Bac+8','Bac+9','Bac+10') AND ";
			else
				$key .= " _rct_candidate._studies_level LIKE '$studiesLevel' AND ";
		}
		
		$updateDateMin = $searchRecord->update_date_min->db;
		//echo $updateDate;
		if( trim($updateDateMin) != '' && $updateDateMin != 'NULL' ) {
			$countKey = true;
			$key .= " CAST(_rct_candidate._add_date AS DATE) >= '$updateDateMin' AND ";
		}
		$updateDateMax = $searchRecord->update_date_max->db;
		//echo $updateDate;
		if( trim($updateDateMax) != '' && $updateDateMax != 'NULL' ) {
			$countKey = true;
			$key .= " CAST(_rct_candidate._add_date AS DATE) <= '$updateDateMax' AND ";
		}
		$yearsOfPractice = $searchRecord->years_of_practice->object;
		if( trim($yearsOfPractice) != '' ) {
			$countKey = true;
			list($min,$max) = $this->splitRange($yearsOfPractice);
			
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

		/*$diploma = $searchRecord->diploma->object;
		if( trim($diploma) != '' ) {
			$countKey = true;			
			$diplomas = explode(',', trim($diploma));
			$key .= " ( ";
			for($i=0; $i<count($diplomas); $i++) {
				$key .= "_rct_candidate._diploma LIKE '".$diplomas[$i]."' ";
				if( count($diplomas) > $i+1 ) {
					$key .= ' OR ';
				}		
			}
			$key .= " ) AND ";
		}*/

		$diploma = $searchRecord->diploma->object;
		if( trim($diploma) != '' ) {			
			$diplomas = explode(',', trim($diploma));
			$key .= " ( "; $sep='';
			for($i=0; $i<count($diplomas); $i++) {
				$key .= "{$sep}_rct_diploma._code LIKE '".$diplomas[$i]."' ";
				$sep=' OR ';
			}
			$key .= " ) AND ";
			$countKey = true;
		}
		
		/*$school = $searchRecord->school->object;
		if( trim($school) != '' ) {
			$countKey = true;
			$schools = explode(',', trim($school));
			$key .= " ( ";
			for($i=0; $i<count($schools); $i++) {
				$key .= "_rct_candidate._institution LIKE '".$schools[$i]."' ";
				if( count($schools) > $i+1 ) {
					$key .= ' OR ';
				}		
			}
			$key .= " ) AND ";		
		}*/


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
			$countKey = true;
		}

		//Source du CV
		$provider = $searchRecord->provider->object;
		if( trim($provider) != '' ) {
			$key .= " _rct_provider._oid= ".$provider;	
			$key .= " AND ";	
			$countKey = true;
		}

		// recruteur
		$hr_manager = $searchRecord->hr_manager->object;
		if( trim($hr_manager) != '' ) {
			$key .= " _hr_manager= ".$hr_manager;	
			$key .= " AND ";	
			$countKey = true;
		}

		// catégorie
		$category = $searchRecord->category_oid->object;
		if( trim($category) != '' ) {
			$countKey = true;
			$key .= " (_rct_candidate_category_assoc._val = $category AND _rct_candidate._oid = _rct_candidate_category_assoc._key) AND ";
		}

		// date disponibilité
		$dispoDate = $searchRecord->available_from;
		if( $dispoDate->isOk()) {
			$countKey = true;
			$dateDB = $dispoDate->db;
			$key .= "( (_rct_candidate._available_delai = 'date' AND _rct_candidate._available_from <= '$dateDB') OR ";
			$key .= "  (_rct_candidate._available_delai != 'date' AND ( TO_DAYS(NOW()) + _rct_candidate._available_delai ) <= TO_DAYS('$dateDB'))) AND ";
		}

		// @todo : Rechercher avec match against et gérer le degré de pertinence.
		$keywords = $searchRecord->match_keywords->object;

		if( trim($keywords) != '' ) {
			$countKey = true;
			$sKeywords = '';
			$aKeywords = explode(' ', $keywords);
			for($i=0; $i<count($aKeywords); $i++) {
				$sKeywords .= "_rct_candidate._keywords LIKE '%".$aKeywords[$i]."%' " . ((count($aKeywords)>($i+1))?' OR ':'');
			}
			$key .= " ( ".$sKeywords." ) AND ";
		}

		$profile = $searchRecord->profile->object;
		
		if( trim($profile) != '' ) {
			$countKey = true;
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
			$countKey = true;
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
			$countKey = true;
			$key .= " _rct_vacancy._oid = '$vacancy' AND ";
		}

		// filter reserved candidates
		// $key .= " (_rct_candidate._hr_manager = '$userOid' OR _rct_candidate._hr_manager='?' OR _rct_candidate._hr_manager IS NULL ) AND ";

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
	
		if($_REQUEST['nxo']=="statistics")
		{
			$key .= "CAST(_rct_candidate._update_date AS DATE) >= '".date('Y')."-1-1' ";
			$key .= ' AND ';
		}

// CVs lus

$joinState = "
	LEFT JOIN (SELECT * FROM _rct_candidate_read_state rs1 WHERE rs1._user_oid <> '{$userOid}') AS rs ON rs._candidate_oid = _rct_candidate._oid
	LEFT JOIN (SELECT * FROM _rct_candidate_read_state rs1 WHERE rs1._user_oid = '{$userOid}') AS rs1 ON rs1._candidate_oid = _rct_candidate._oid
" ;

$otherTables='';
$cvReadBy = $searchRecord->read_by->object;
if( $cvReadBy != '' && $cvReadBy!='0') {
	$countKey = true;
	switch($cvReadBy) 
	{
		case 1: // lus par moi
			$key .= " (_rct_candidate_read_state._candidate_oid = _rct_candidate._oid AND _rct_candidate_read_state._user_oid = '$userOid') AND ";
			$otherTables = '_rct_candidate_read_state,';
			break;
		case 2: // lus
//			$key .= " (_rct_candidate_read_state._candidate_oid = _rct_candidate._oid) AND ";
//			$otherTables = '_rct_candidate_read_state,';
			$key .= " (rs._candidate_oid > 0 OR rs1._candidate_oid > 0) AND ";
			break;
		case 3: // non lus
			// $key .= " (rs._candidate_oid IS NULL AND rs1._candidate_oid IS NULL) AND "; // -FY
			$key .= " (rs._candidate_oid IS NULL) AND ";
			$joinState = "
	LEFT JOIN _rct_candidate_read_state AS rs ON rs._candidate_oid = _rct_candidate._oid
	LEFT JOIN (SELECT * FROM _rct_candidate_read_state rs1 WHERE rs1._user_oid = '{$userOid}') AS rs1 ON rs1._candidate_oid = _rct_candidate._oid
" ;
			break;
	}
}

// end key
$key.= '1=1';


//le tri	
$order = ' _rct_candidate._update_date DESC, _rct_candidate._first_name ASC, _rct_candidate._last_name ASC ';
if($searchRecord->sort_by->object !="")
{
	$order="_".$searchRecord->sort_by->object.' ASC, '.$order;
	$countKey = true;
}


if($_REQUEST['nxo']=="list" || $_REQUEST['nxo']=="candidate@recruitment:list" || $_REQUEST['nxo']==NULL)
{
	// gestion de la pagination
	$pageAlias 		= 'page';
	$pageOffset 	= isset($_GET[$pageAlias])? $_GET[$pageAlias] : 0;
	$recordsPerPage = 10;
	$indexFirst 	= $pageOffset * $recordsPerPage;
	$limit 			= "LIMIT $indexFirst,$recordsPerPage";
}

if($countKey!=1)
{
$fields = <<<FIELDS

	_rct_candidate._oid as _oid,

	(CASE WHEN rs._candidate_oid > 0 THEN 1 ELSE 0 END) AS _read_state,
	(CASE WHEN rs1._candidate_oid > 0 THEN 1 ELSE 0 END) AS _user_read_state,

	_rct_candidate_category._name AS _category_oid,

	_rct_candidate._first_name as _first_name,

	_rct_candidate._last_name as _last_name,

	_rct_candidate._studies_level AS _studies_level,

	_rct_candidate._cv_path as _cv_path,

	_rct_candidate._age as _age,

	_rct_candidate._zip as _zip,

	_rct_candidate._creation_date as _creation_date,

	_rct_candidate._gender as _gender,

	_rct_candidate._update_date as _update_date,

	_rct_candidate._town_oid as _town_name,

	_rct_candidate._years_of_practice as _years_of_practice,

	_rct_candidate._keywords as _keywords,

	_rct_candidate._reading_state as _reading_state,

	_rct_candidate._relevance as _relevance,

	_rct_candidate._profile AS _profile,

	_rct_candidate._add_date AS _add_date,

	_rct_candidate._update_date AS _update_date,

	_rct_candidate._diploma_type as _diploma_type,

	_rct_candidate._diploma as _diploma,

	_rct_candidate._institution as _institution,

	_rct_candidate._last_employment_start_date AS _last_employment_start_date,

	_rct_candidate._last_employment_end_date AS _last_employment_end_date,

	_rct_candidate. _last_employment AS _last_employment,

	_rct_candidate._last_training_start_date AS _last_training_start_date,

	_rct_candidate._last_training_end_date AS _last_training_end_date,

	_rct_candidate._last_training AS _last_training,

	_rct_vacancy._oid as _vacancy_oid,
	_rct_vacancy._name as _vacancy_name,
	_rct_vacancy._code as _vacancy_code,
	
	_rct_candidate._hr_manager AS _hr_manager,
	_rct_provider._name as _provider,

	_rct_candidate_etat._name as _etat_oid


FIELDS;
}else{
$fields = <<<FIELDS
	_rct_candidate._oid as _oid,
	
	(CASE WHEN rs._candidate_oid > 0 THEN 1 ELSE 0 END) AS _read_state,
	(CASE WHEN rs1._candidate_oid > 0 THEN 1 ELSE 0 END) AS _user_read_state,
	
	$profileRelevance
	$relevanceField
	
--	GROUP_CONCAT(_rct_candidate_category._name SEPARATOR ', ') AS _category_oid,
	_rct_candidate_category._name AS _category_oid,
	_rct_candidate._first_name as _first_name,
	_rct_candidate._last_name as _last_name,
	_rct_candidate._studies_level AS _studies_level,
	_rct_candidate._cv_path as _cv_path,
	COALESCE(FLOOR((TO_DAYS(NOW())-TO_DAYS(_rct_candidate._date_of_birth)) / 365.25),0) as _age,
	_rct_candidate._zip as _zip,
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
	_rct_vacancy._oid as _vacancy_oid,
	_rct_vacancy._name as _vacancy_name,
	_rct_vacancy._code as _vacancy_code,
	
	_employment._salary_min_exp AS _salary_min_exp,
	_employment._salary_max_exp AS _salary_max_exp,

	_employment._employment_start_date AS _last_employment_start_date,
	_employment._employment_end_date AS _last_employment_end_date,
	_employment._employment_content AS _last_employment,
	_training._employment_start_date AS _last_training_start_date,
	_training._employment_end_date AS _last_training_end_date,
	_training._employment_content AS _last_training,

	_rct_candidate._hr_manager AS _hr_manager,
	_rct_provider._name as _provider,
	_rct_candidate_etat._name as _etat_oid
FIELDS;
}

if($countKey!=1)
{
$sqlClause = <<<WHERECLAUSE
	FROM 
		$otherTables	_rct_candidate
	-- Récupération état de lecture	
	$joinState

	-- Récupération des dossiers
	
	LEFT JOIN _rct_candidate_vacancy 
		ON _rct_candidate_vacancy ._candidate_oid = _rct_candidate._oid
	LEFT JOIN 
		_rct_vacancy ON _rct_candidate_vacancy._vacancy_oid = _rct_vacancy._oid

	-- Récupération de la catégorie
	LEFT JOIN _rct_candidate_category_assoc ON _rct_candidate._oid = _rct_candidate_category_assoc._key
	LEFT JOIN _rct_candidate_category ON _rct_candidate_category_assoc._val = _rct_candidate_category._oid

	LEFT JOIN _rct_provider ON _rct_provider._oid = _rct_candidate_vacancy._cv_source_oid
	LEFT JOIN _rct_candidate_etat ON _rct_candidate_etat._oid = _rct_candidate._etat_oid

	WHERE
		$key

WHERECLAUSE;
}else{
$sqlClause = <<<WHERECLAUSE
	FROM 
		$otherTables _rct_candidate
	
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
		_rct_candidate_vacancy as _vacancy_temp
		ON _vacancy_temp._candidate_oid = _rct_candidate._oid
	
	LEFT JOIN 
		_rct_vacancy ON _vacancy_temp._vacancy_oid = _rct_vacancy._oid
		
	LEFT JOIN
		_rct_diploma ON _education._diploma = _rct_diploma._code
		
		
	LEFT JOIN
		_rct_school ON _education._institution = _rct_school._code
	
	-- Récupération état de lecture	
	$joinState
		
	-- Récupération de la catégorie
	LEFT JOIN _rct_candidate_category_assoc ON _rct_candidate._oid = _rct_candidate_category_assoc._key
	LEFT JOIN _rct_candidate_category ON _rct_candidate_category_assoc._val = _rct_candidate_category._oid
	LEFT JOIN _rct_provider ON _rct_provider._oid = _vacancy_temp._cv_source_oid
	LEFT JOIN _rct_candidate_etat ON _rct_candidate_etat._oid = _rct_candidate._etat_oid

	WHERE
		$key
		
		AND _employment1._candidate_oid IS NULL 
		AND _training1._candidate_oid IS NULL 
		
WHERECLAUSE;
}
$queryCount = <<<COUNTQUERY
	SELECT COUNT(*) as nbrecords FROM (SELECT	
	COUNT(*) as nbrecords
	$sqlClause
	GROUP BY _rct_candidate._oid) AS COUNTTBL
COUNTQUERY;

/*if( $relevanceField != '' || $profileRelevance != '' ) {
	if( $profileRelevance != '' ) {
		$order = ' _profile_relevance DESC,';
	}
	if( $relevanceField != '' ) {
		$order = ' _relevance_rate DESC';
	}
	
	$order = rtrim($order, ',');
} else {*/
	
//}


$query = <<<QUERY
	SELECT 
	$fields
	$sqlClause
	GROUP BY _rct_candidate._oid
	ORDER BY $order
	$limit
QUERY;

//echo $query;

nxError($query,'MYSQL');
		
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