<?php $properties["query"]="SELECT _oid,_proposed_by,_date,_comment FROM _rct_candidate_client WHERE ".$this->getWhereClause("_proposed_to","'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."'",'LIKE','OR','%','%',true,false,'|','false')." ORDER BY _date DESC "; ?>