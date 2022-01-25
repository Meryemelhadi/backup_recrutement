<?php $properties["query"]="INSERT INTO _rct_candidate_etat_assoc(_candidate_oid,_etat_oid,_vacancy_oid) VALUES('".$props->getProperty("candidate_oid","",true)."',".
"'".$this->getParamValue("etat_oid","","request",",")."',".
"'".$props->getProperty("vacancy_oid","",true)."')"; ?>