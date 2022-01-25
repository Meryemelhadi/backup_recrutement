<?php $properties["query"]="INSERT INTO _rct_vacancy_history(_oid,_date,_vacancy_oid,_progress_level,_progress_level_meta) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("date","DB","now").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("progress_level","DB","NULL").",".
$record->getFieldValue("progress_level_meta","DB","NULL").")"; ?>