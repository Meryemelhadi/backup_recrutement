<?php $properties["query"]="INSERT INTO _rct_candidate(_cv_path,_etat_oid) VALUES(".$record->getFieldValue("cv_path","DB","NULL").",".
$record->getFieldValue("etat_oid","DB","NULL").")"; ?>