<?php 

require_once(NX_LIB.'framework.inc');

class lib_recruitment_short_lists_services_directory
{
	var $ctxt;

	function lib_recruitment_short_lists_services_directory($ctxt)
	{
		$this->ctxt = $ctxt;
		Framework::setContext($this->ctxt = $ctxt);
	}
	
	function saveAssociations($candidatesOids, $shortListOid) {
		
		if( trim($shortListOid) == '?' || trim($candidatesOids) == '' ) {
			return false;
		}
		$oids = explode('|', $candidatesOids);
		
		$errorCB=new NxErrorCB();
		$db = &$this->ctxt->getDB($errorCB);
		
		$inseredOids = array();
		
		for($i=0; $i<count($oids); $i++) {
			$oid = $oids[$i];
			$db->queryWithData("INSERT INTO _rct_candidate_short_list (_candidate_oid,_short_list_oid) SELECT '$oid', '$shortListOid' FROM DUAL WHERE NOT EXISTS (SELECT * FROM _rct_candidate_short_list WHERE _candidate_oid='$oid' AND _short_list_oid='$shortListOid')");
			
			$db->getLastInsertID($lastInsertId);
			
			if( $lastInsertId != '' ) {
				$inseredOids[] = $oid;
			}
			
		}
		
		return $inseredOids;
	}

    function moveAssociations($candidatesOids, $shortListOid) {

        if( trim($shortListOid) == '?' || trim($candidatesOids) == '' ) {
            return false;
        }
        $oids = explode('|', $candidatesOids);

        $errorCB=new NxErrorCB();
        $db = &$this->ctxt->getDB($errorCB);

        $inseredOids = array();

        for($i=0; $i<count($oids); $i++) {
            $oid = $oids[$i];
            $db->queryWithData("delete from _rct_candidate_short_list where _candidate_oid='$oid'");
            $db->queryWithData("INSERT INTO _rct_candidate_short_list (_candidate_oid,_short_list_oid) SELECT '$oid', '$shortListOid' FROM DUAL WHERE NOT EXISTS (SELECT * FROM _rct_candidate_short_list WHERE _candidate_oid='$oid' AND _short_list_oid='$shortListOid')");

            $db->getLastInsertID($lastInsertId);

            if( $lastInsertId != '' ) {
                $inseredOids[] = $oid;
            }

        }

        return $inseredOids;
    }
	
}