<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_town_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("town_oid","DB","NULL").")"; ?>