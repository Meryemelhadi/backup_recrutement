<?php $properties["query"]="SELECT _oid,_candidate_oid,_test_oid,_pourcentage,_comment FROM _rct_candidate_test_assoc WHERE _test_oid='".$props->getProperty("test_oid","",true)."' AND _candidate_oid='".$props->getProperty("candidate_oid","",true)."'"; ?>