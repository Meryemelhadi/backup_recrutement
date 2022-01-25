<?php $properties["query"]="INSERT INTO _rct_candidate(_first_name,_last_name,_cv_path) VALUES(".$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("cv_path","DB","NULL").")"; ?>