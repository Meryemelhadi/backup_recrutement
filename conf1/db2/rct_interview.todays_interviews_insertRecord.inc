<?php $properties["query"]="INSERT INTO _rct_interview(_oid,_time_start) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("time_start","DB","NOW()").")"; ?>