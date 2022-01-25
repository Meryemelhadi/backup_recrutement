<?php
require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

/* application */
class lib_recruitment_vacancies_records_api
{
	var $ctxt;

	function __construct($ctxt,$instance) {
		$this->ctxt=$ctxt;
	}

	function getRecords($recDesc,$errorCB,$data,$props) 
	{
		$countKey = '';
		$key = '';

		// gestion de la pagination
		/*
		$pageAlias 		= 'page';
		$pageOffset 	= isset($_GET[$pageAlias])? $_GET[$pageAlias] : 0;
		$recordsPerPage = 50;
		$indexFirst 	= $pageOffset * $recordsPerPage;

		$limit = "";
		if(
				((isset($_REQUEST['nxo'])?$_REQUEST['nxo']:"") != 'export_excel' ) &&
				((isset($_REQUEST['nopage'])?$_REQUEST['nopage']:"") != '1' )
			) 
		{
			$limit = "LIMIT $indexFirst,$recordsPerPage";
		}
		*/

		$limit = '';

		$site = isset($_GET['site'])?$_GET['site']:'';
				
		$query = <<<QUERY
		
		SELECT 
			V._oid AS _oid,
			V._cand_channel AS _cand_channel,
			V._name AS _name,
			'' AS _email,
			V._number AS _number,
			V._code AS _code,
			V._opening_date AS _opening_date,
			V._duty_station_oid AS _duty_station_oid,

			VP._salaire AS _salaire,
			VP._descriptionEntreprise AS _descriptionEntreprise,
			VP._descriptionPoste AS _descriptionPoste,
			VP._descriptionProfil AS _descriptionProfil,
			VP._date AS _date ,
			VP._duree AS _duree ,
			VP._nombrePoste AS _nombrePoste ,
			VP._startDate AS _startDate ,
			VP._endDate AS _endDate

		FROM 
			_rct_vacancy AS V 

			LEFT JOIN _rct_vacancy_provider as VP ON VP._vacancy_oid = V._oid
			LEFT JOIN _rct_provider as P ON P._oid = VP._provider_oid

		WHERE 
			V._current_step='0' AND 
			(V._archive_state = '0') AND 
			(V._workflow_state='1' OR V._workflow_state='2') AND
			(
				P._web = '{$site}' OR
				P._name = '{$site}' OR
				P._code = '{$site}'
			) AND
			VP._active = 1

		GROUP BY 
			V._oid  

		ORDER BY 
			VP._date DESC,
			V._name ASC,
			V._code ASC

		$limit		
QUERY;

		// exec query
		$errorCB=new NxErrorCB();
		$db = &$this->ctxt->getDB($errorCB);
		$res = $db->queryWithData($query);
		if (!$res) {

		}

		foreach($res as $i=>$record)
		{
			$oid = $record['_oid'];

			$channelOid = $record['_cand_channel'];
			if($channelOid && $channelOid!='?')
				$suffix = str_pad($channelOid, 2, '0', STR_PAD_LEFT);
			else
				$suffix='';
			
			$code_client = $this->ctxt->getProperty('recruitment.code_client');
			if(!$code_client)
			{
				$a = explode('.',strtolower($_SERVER['SERVER_NAME']));
				if($a[1]=='presencesoft'||$a[1]=='presencerecrute')
					// editialis.presencerecrute.com
					$code_client = $a[0];
				else
					// xx.editialis.fr
					$code_client = $a[1];
			}

			if($code_client)
			{		
				$year = '15';
				$oidpad = str_pad($oid, 3, '0', STR_PAD_LEFT);
				//$check = ($year * $oid)%100;
                $check = str_pad(''.($year * $oid)%100,2,'0', STR_PAD_LEFT);
				$email = $code_client.'_'.$year.$oidpad.$check.$suffix.'@pourcandidature.com';
			}
			else
				$email = '';

			$res[$i]['_email'] = $email;
		}

		$records =  new NxData_ArrayRecords($res, $recDesc,'db');
			
		/*
		// count records for pagination
		$queryCount = 'SELECT FOUND_ROWS() as nbrecords';
		$resCount = $db->queryWithData($queryCount);
		if ($resCount) {
			$totalRecords=$resCount[0]['nbrecords'];
		}
		$records->setPageCounters($totalRecords,$pageOffset,$recordsPerPage,$pageAlias);
		*/

		return $records;
	}

	function countRecords($recDesc,$errorCB)    {}
}
?>