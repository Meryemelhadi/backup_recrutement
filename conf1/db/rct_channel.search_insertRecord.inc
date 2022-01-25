<?php $properties["query"]="INSERT INTO _rct_channel(_name,_establishment) VALUES(".$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("establishment","DB","NULL").")"; ?>