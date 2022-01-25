<?php $properties["query"]="INSERT INTO _rct_vacancy_readonly(_oid,_progress_level) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("progress_level","DB","NULL").")"; ?>