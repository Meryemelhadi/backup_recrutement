<?php $properties["query"]="INSERT INTO _rct_candidate_test_assoc(_candidate_oid,_test_oid,_pourcentage,_comment) VALUES('".$props->getProperty("candidate_oid","",true)."',".
"'".$props->getProperty("test_oid","",true)."',".
"'".$props->getProperty("pourcentage","",true)."',".
"'".$this->getParamValue("comment","","request",",")."')"; ?>