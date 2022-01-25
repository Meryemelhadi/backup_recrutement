<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy(_oid,_hire_date) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("hire_date","DB","NOW()").")"; ?>