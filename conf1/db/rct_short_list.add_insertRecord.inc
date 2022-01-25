<?php $properties["query"]="INSERT INTO _rct_short_list(_name,_created_by,_creation_date,_vacancy_oid,_is_visible) VALUES(".$record->getFieldValue("name","DB","NULL").",".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
"'".$props->getProperty("vacancy_oid","",true)."',".
"'0')"; ?>