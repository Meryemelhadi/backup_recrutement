<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy(_candidate_oid,_vacancy_oid,_add_date) VALUES('".$props->getProperty("candidate_oid","",true)."',".
"'".$props->getProperty("vacancy_oid","",true)."',".
"NOW())"; ?>