<?php $properties["query"]="INSERT INTO _rct_candidate(_cv_path,_first_name,_last_name) VALUES(".$record->getFieldValue("cv_path","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").")"; ?>