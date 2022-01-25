<?php $properties["query"]="INSERT INTO _rct_search_params(_name,_is_default) VALUES(".$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("is_default","DB","NULL").")"; ?>