<?php $properties["query"]="SELECT COUNT(*) as nbrecords FROM _rct_candidate_client WHERE ".$this->getWhereClause("_proposed_to","'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."'",'LIKE','OR','%','%',true,false,'|','false'); ?>