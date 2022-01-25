<?php $properties["query"]="INSERT INTO _rct_candidate_email(_oid,_email_content) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").")"; ?>