<?php $properties["query"]="INSERT INTO _rct_candidate_provider(_oid,_candidate_oid,_provider) VALUES('null',".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("provider","DB","NULL").")"; ?>