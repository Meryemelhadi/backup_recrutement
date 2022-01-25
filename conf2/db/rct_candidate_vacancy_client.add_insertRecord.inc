<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy_client(_candidate_oid,_vacancy_oid,_proposed_by,_proposal_date,_comment) VALUES('".$props->getProperty("candidate_oid","",true)."',".
"'".$props->getProperty("vacancy_oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
$record->getFieldValue("comment","DB","NULL").")"; ?>