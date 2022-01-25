<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_vacancies_records_interview_vacancies
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}

	function getRecords($recDesc,$errorCB,$data,$props) 
	{
		$parentRecord = $recDesc->parent->getProperty('parentRecord');
		$parentOid = $parentRecord->oid->object;
		$res =  false;
		/*if(isset($_REQUEST['candidate_oid']) && $_REQUEST['candidate_oid'] != '' && $_REQUEST['candidate_oid']!= 0){
			$query = "SELECT _rct_vacancy._oid,
						_rct_vacancy._name,
						_rct_vacancy._code
						FROM _rct_vacancy  
						Left join _rct_candidate_vacancy ON _rct_candidate_vacancy._vacancy_oid = _rct_vacancy._oid
						WHERE _rct_candidate_vacancy._candidate_oid = '".$_REQUEST['candidate_oid']."' ";
			$errorCB=new NxErrorCB();
			$db = &$this->ctxt->getDB($errorCB);
			$res = $db->queryWithData($query);
		}*/
		
		
		if (!$res) {
			//Permission DRH
			if($GLOBALS['_NX_user']->checkPerm('?-drh')){
				$query = "SELECT _rct_vacancy._oid , _rct_vacancy._name,
						_rct_vacancy._code FROM _rct_vacancy 
						where _rct_vacancy._current_step = 0";
			}else{
				$query = "SELECT _rct_vacancy._oid , _rct_vacancy._name,
						_rct_vacancy._code FROM _rct_vacancy 
						LEFT JOIN _rct_vacancy_total_control AS T_CTRL ON T_CTRL._key = _rct_vacancy._oid 
						LEFT JOIN _rct_vacancy_readonly		 AS R_CTRL ON R_CTRL._key = _rct_vacancy._oid
						where _rct_vacancy._current_step = 0 AND (
							_rct_vacancy._creator='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							T_CTRL._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							R_CTRL._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							_rct_vacancy._manager_oid='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							_rct_vacancy._creator in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') OR 
							T_CTRL._val in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') OR 
							R_CTRL._val in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') OR 
							_rct_vacancy._manager_oid in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') ) ";
			}
			
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