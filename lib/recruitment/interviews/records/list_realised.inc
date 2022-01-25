<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_interviews_records_list_realised
{
    var $ctxt;

    function __construct($ctxt,$instance) {
        $this->ctxt=$ctxt;

    }

    function getRecords($recDesc,$errorCB,$data,$props)
    {
        $userOid = $GLOBALS["_NX_user"]->getProperty("oid","",true);

        // gestion de la pagination
        $pageAlias 		= 'page_interview_r';
        $pageOffset 	= isset($_GET[$pageAlias])? $_GET[$pageAlias] : 0;
        $recordsPerPage = 5;
        $indexFirst 	= $pageOffset * $recordsPerPage;
        $limit 			= "LIMIT $indexFirst,$recordsPerPage";
        $join = '';

        $where ="";
        if(isset($_REQUEST['candidate_oid']) && ctype_digit(strval($_REQUEST['candidate_oid']))){
            $where.= " and _rct_candidate._oid =".$_REQUEST['candidate_oid'];
        }
		if(isset($_REQUEST['interview_type']) && ctype_digit(strval($_REQUEST['interview_type']))){
            $where.= " and _rct_interview._interview_type =".$_REQUEST['interview_type'];
        }
        
        if(isset($_REQUEST['vacancy_oid']) && $_REQUEST['vacancy_oid'] == -2 ){
			if($GLOBALS['_NX_user']->checkPerm('?-drh')){
				$where2 = $where." and VAC2._current_step =0 and VAC2._oid is not null ";
				$where .= " and VAC._current_step =0 and VAC._oid is not null ";
			}else{
				$join = "LEFT JOIN _rct_vacancy_total_control AS T_CTRL ON T_CTRL._key =  VAC._oid 
						LEFT JOIN _rct_vacancy_readonly		 AS R_CTRL ON R_CTRL._key = VAC._oid";
				
				$join2 = "LEFT JOIN _rct_vacancy_total_control AS T_CTRL ON T_CTRL._key =  VAC2._oid 
						LEFT JOIN _rct_vacancy_readonly		 AS R_CTRL ON R_CTRL._key = VAC2._oid";
						
				$where2 = $where." and VAC2._current_step =0 and VAC2._oid is not null and (
							VAC2._creator='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							T_CTRL._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							R_CTRL._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							VAC2._manager_oid='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							VAC2._creator in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') OR 
							T_CTRL._val in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') OR 
							R_CTRL._val in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') OR 
							VAC2._manager_oid in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') 
						)";
						
				$where .= " and VAC._current_step =0 and VAC._oid is not null and (
							VAC._creator='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							T_CTRL._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							R_CTRL._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							VAC._manager_oid='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							VAC._creator in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') OR 
							T_CTRL._val in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') OR 
							R_CTRL._val in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') OR 
							VAC._manager_oid in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') 
						)";
				
			}
        	
        }elseif(isset($_REQUEST['vacancy_oid']) && ctype_digit(strval($_REQUEST['vacancy_oid']))){
            $where.= " and ((VAC2._oid =". $_REQUEST['vacancy_oid']." and (_rct_interview._vacancy_oid IS NULL or _rct_interview._vacancy_oid = 0)) or _rct_interview._vacancy_oid = ".$_REQUEST['vacancy_oid'].")";
        }elseif(isset($_REQUEST['void']) && ctype_digit(strval($_REQUEST['void']))){
			 $where.= " and ((VAC2._oid =".$_REQUEST['void']." and (_rct_interview._vacancy_oid IS NULL or _rct_interview._vacancy_oid = 0)) or _rct_interview._vacancy_oid = ".$_REQUEST['void'].")";
		}
		//Permission DRH
		if($GLOBALS['_NX_user']->checkPerm('?-drh')){
			$query='SELECT
						  _rct_interview._oid AS _oid,
						  _rct_interview._candidate_oid AS _candidate_oid,
						  _rct_interview._interview_by_oid AS _interview_by_oid,
						  IFNULL(_rct_interview._vacancy_oid,IFNULL(VAC2._oid,"")) as _vacancy_oid,
						  IFNULL(VAC._name,IFNULL(VAC2._name,"")) as _vacancy_name,
						   CONCAT_WS(" ",_rct_candidate._first_name,_rct_candidate._last_name) AS _candidate_name,
						  _rct_interview._date AS _date,
						  _rct_interview._time_start AS _time_start,
						  _rct_interview._time_end AS _time_end,
						  _rct_interview._validation_state AS _validation_state,
						  _rct_candidate_etat._color as _etat_color,
						  _rct_candidate._etat_oid as _etat_oid,
						  _rct_interview._created_by as _created_by,
						  _rct_interview._interview_etat as _interview_etat,
						  _rct_interview_synthesis._oid as _synthesis_oid,
						  _rct_interview._video_link as _video_link,
						  _rct_interview._interview_type as _interview_type,
						  _rct_candidate._cv_path as _cv_path,
						  _rct_interview._location as _location,
						  _rct_candidate._mobile as _mobile,
						  _rct_candidate._phone_1 as _phone_1,
						  _rct_candidate._phone_2 as _phone_2
						FROM _rct_interview JOIN _rct_interview_by
						LEFT JOIN _rct_candidate ON _rct_candidate._oid = _rct_interview._candidate_oid
						LEFT JOIN _rct_candidate_etat ON  _rct_candidate_etat._oid = _rct_candidate._etat_oid
						LEFT JOIN _rct_interview_synthesis ON _rct_interview_synthesis._interview_oid = _rct_interview._oid 
						-- vacancy attached to the interview
						LEFT JOIN _rct_vacancy AS VAC ON VAC._oid = _rct_interview._vacancy_oid
						-- vacancy attached to the candidate
						LEFT JOIN (
							SELECT
								_candidate_oid,_vacancy_oid as _v_oid
							FROM
								_rct_candidate_vacancy
							GROUP BY _rct_candidate_vacancy._candidate_oid
							ORDER BY _add_date DESC
						) AS CAND_VAC ON CAND_VAC._candidate_oid = _rct_candidate._oid
						--  LEFT JOIN _rct_candidate_vacancy AS CAND_VAC ON CAND_VAC._candidate_oid = CAND._oid
						LEFT JOIN _rct_vacancy AS VAC2 ON VAC2._oid = CAND_VAC._v_oid
						'.$join.'
						WHERE (_rct_interview_by._key=_rct_interview._oid
								AND _rct_interview._date <"'.date('Y-m-d').'" '.$where.')
						GROUP BY _rct_interview._oid
						ORDER BY _rct_interview._date DESC , _rct_interview._oid DESC '.$limit;


			$queryCount = 'SELECT count(*) as nbrecords
							FROM (select distinct _rct_interview._oid FROM _rct_interview JOIN _rct_interview_by
						LEFT JOIN _rct_candidate ON _rct_candidate._oid = _rct_interview._candidate_oid
						-- vacancy attached to the interview
						LEFT JOIN _rct_vacancy AS VAC ON VAC._oid = _rct_interview._vacancy_oid
						-- vacancy attached to the candidate
						LEFT JOIN (
							SELECT
								_candidate_oid,_vacancy_oid as _v_oid
							FROM
								_rct_candidate_vacancy
							GROUP BY _rct_candidate_vacancy._candidate_oid
							ORDER BY _add_date DESC
						) AS CAND_VAC ON CAND_VAC._candidate_oid = _rct_candidate._oid
						--  LEFT JOIN _rct_candidate_vacancy AS CAND_VAC ON CAND_VAC._candidate_oid = CAND._oid
						LEFT JOIN _rct_vacancy AS VAC2 ON VAC2._oid = CAND_VAC._v_oid
						'.$join.'
						WHERE (_rct_interview_by._key=_rct_interview._oid
								AND _rct_interview._date <"'.date('Y-m-d').'" '.$where.')
						GROUP BY _rct_interview._oid) as count';
		}else{
			
			$query='SELECT
						  _rct_interview._oid AS _oid,
						  _rct_interview._candidate_oid AS _candidate_oid,
						  _rct_interview._interview_by_oid AS _interview_by_oid,
						  IFNULL(_rct_interview._vacancy_oid,IFNULL(VAC2._oid,"")) as _vacancy_oid,
						  IFNULL(VAC._name,IFNULL(VAC2._name,"")) as _vacancy_name,
						   CONCAT_WS(" ",_rct_candidate._first_name,_rct_candidate._last_name) AS _candidate_name,
						  _rct_interview._date AS _date,
						  _rct_interview._time_start AS _time_start,
						  _rct_interview._time_end AS _time_end,
						  _rct_interview._validation_state AS _validation_state,
						  _rct_candidate_etat._color as _etat_color,
						  _rct_candidate._etat_oid as _etat_oid,
						  _rct_interview._created_by as _created_by,
						  _rct_interview._interview_etat as _interview_etat,
						  _rct_interview_synthesis._oid as _synthesis_oid,
						  _rct_candidate._cv_path as _cv_path,
						  _rct_interview._location as _location,
						  _rct_candidate._mobile as _mobile,
						  _rct_candidate._phone_1 as _phone_1,
						  _rct_candidate._phone_2 as _phone_2,
						  _rct_interview._video_link as _video_link,
						  _rct_interview._interview_type as _interview_type
						FROM _rct_interview JOIN _rct_interview_by
						LEFT JOIN _rct_candidate ON _rct_candidate._oid = _rct_interview._candidate_oid
						LEFT JOIN _rct_candidate_etat ON  _rct_candidate_etat._oid = _rct_candidate._etat_oid
						LEFT JOIN _rct_interview_synthesis ON _rct_interview_synthesis._interview_oid = _rct_interview._oid AND _rct_interview_synthesis._user_oid = '.$userOid.'
						-- vacancy attached to the interview
						LEFT JOIN _rct_vacancy AS VAC ON VAC._oid = _rct_interview._vacancy_oid
						-- vacancy attached to the candidate
						LEFT JOIN (
							SELECT
								_candidate_oid,_vacancy_oid as _v_oid
							FROM
								_rct_candidate_vacancy
							GROUP BY _rct_candidate_vacancy._candidate_oid
							ORDER BY _add_date DESC
						) AS CAND_VAC ON CAND_VAC._candidate_oid = _rct_candidate._oid
						--  LEFT JOIN _rct_candidate_vacancy AS CAND_VAC ON CAND_VAC._candidate_oid = CAND._oid
						LEFT JOIN _rct_vacancy AS VAC2 ON VAC2._oid = CAND_VAC._v_oid
						'.$join.'
						WHERE (_rct_interview_by._key=_rct_interview._oid
								AND (_rct_interview_by._val='.$userOid.'
								OR _rct_interview._created_by='.$userOid.'
								OR _rct_interview_by._val in (select _oid from _user where `_interim` = '.$userOid.')
								OR _rct_interview._created_by in (select _oid from _user where `_interim` = '.$userOid.')
								)
								AND _rct_interview._date <"'.date('Y-m-d').'" '.$where.')
						GROUP BY _rct_interview._oid
						ORDER BY _rct_interview._date DESC , _rct_interview._oid DESC '.$limit;


			$queryCount = 'SELECT count(*) as nbrecords
							FROM (select distinct _rct_interview._oid FROM _rct_interview JOIN _rct_interview_by
						LEFT JOIN _rct_candidate ON _rct_candidate._oid = _rct_interview._candidate_oid
						LEFT JOIN _rct_candidate_etat ON  _rct_candidate_etat._oid = _rct_candidate._etat_oid
						LEFT JOIN _rct_vacancy AS VAC ON VAC._oid = _rct_interview._vacancy_oid
						-- vacancy attached to the candidate
						LEFT JOIN (
							SELECT
								_candidate_oid,_vacancy_oid as _v_oid
							FROM
								_rct_candidate_vacancy
							GROUP BY _rct_candidate_vacancy._candidate_oid
							ORDER BY _add_date DESC
						) AS CAND_VAC ON CAND_VAC._candidate_oid = _rct_candidate._oid
						--  LEFT JOIN _rct_candidate_vacancy AS CAND_VAC ON CAND_VAC._candidate_oid = CAND._oid
						LEFT JOIN _rct_vacancy AS VAC2 ON VAC2._oid = CAND_VAC._v_oid
						'.$join.'
						WHERE (_rct_interview_by._key=_rct_interview._oid
								AND (_rct_interview_by._val='.$userOid.'
								OR _rct_interview._created_by='.$userOid.'
								OR _rct_interview_by._val in (select _oid from _user where `_interim` = '.$userOid.')
								OR _rct_interview._created_by in (select _oid from _user where `_interim` = '.$userOid.')
								)
								AND _rct_interview._date <"'.date('Y-m-d').'" '.$where.')
						GROUP BY _rct_interview._oid) as count';
			
		}

        $errorCB=new NxErrorCB();
        $db = &$this->ctxt->getDB($errorCB);
        $res = $db->queryWithData($query);
        if (!$res) {
            return null;
        }

        $records =  new NxData_ArrayRecords($res, $recDesc,'db');
        $resCount = $db->queryWithData($queryCount);

        $records->setPageCounters($resCount[0]['nbrecords'],$pageOffset,$recordsPerPage,$pageAlias);

        return $records;
    }

    function countRecords($recDesc,$errorCB)    {}
}

?>