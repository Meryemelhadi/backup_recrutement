<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_cv_path,_cl_path) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("cv_path","DB","NULL").",".
$record->getFieldValue("cl_path","DB","NULL").")"; ?>