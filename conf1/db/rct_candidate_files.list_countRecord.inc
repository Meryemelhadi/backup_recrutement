<?php $properties["query"]="SELECT COUNT(*) as nbrecords FROM _rct_candidate_files WHERE _candidate_oid='".$this->getParamValue("oid","","request",",")."'"; ?>