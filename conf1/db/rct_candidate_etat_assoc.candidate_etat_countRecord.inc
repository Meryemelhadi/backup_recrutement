<?php $properties["query"]="SELECT COUNT(*) as nbrecords FROM _rct_candidate_etat_assoc WHERE _candidate_oid='".$props->getProperty("candidate_oid","",true)."' AND _etat_oid='".$this->getParamValue("etat_oid","","request",",")."'"; ?>