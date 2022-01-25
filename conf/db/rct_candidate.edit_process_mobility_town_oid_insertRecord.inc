<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_mobility_town_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("mobility_town_oid","DB","NULL").")"; ?>