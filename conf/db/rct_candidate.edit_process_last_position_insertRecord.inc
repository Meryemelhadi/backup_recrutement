<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_last_position) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("last_position","DB","NULL").")"; ?>