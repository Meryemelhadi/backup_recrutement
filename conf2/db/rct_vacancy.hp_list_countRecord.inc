<?php $properties["query"]="SELECT COUNT(*) as nbrecords FROM _rct_vacancy,_rct_vacancy_total_control,_rct_vacancy_readonly WHERE _rct_vacancy._manager_oid<>'".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' AND _rct_vacancy._current_step='0' AND ".$this->getWhereClause("_rct_vacancy._archive_state","'0'",'=','OR','','',true,false,'|','false')." AND (_rct_vacancy._workflow_state='1' OR _rct_vacancy._workflow_state='2')  AND ((".$this->getWhereClause("_rct_vacancy._client_oid","'".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."'",'=','OR','','',true,false,'|','false').")  OR (_rct_vacancy_total_control._key=_rct_vacancy._oid AND _rct_vacancy_total_control._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."')  OR (_rct_vacancy_readonly._key=_rct_vacancy._oid AND _rct_vacancy_readonly._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."') )  GROUP BY _rct_vacancy._oid "; ?>