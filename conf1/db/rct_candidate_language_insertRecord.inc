<?php $properties["query"]="INSERT INTO _rct_candidate_language(_oid,_candidate_oid,_lang,_language_level) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("lang","DB","NULL").",".
$record->getFieldValue("language_level","DB","NULL").")"; ?>