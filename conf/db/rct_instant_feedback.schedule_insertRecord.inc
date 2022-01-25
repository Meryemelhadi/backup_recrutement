<?php $properties["query"]="INSERT INTO _rct_instant_feedback(_filled_by,_scheduled_by,_scheduled_on,_vacancy_oid,_fill_state,_complete_state) VALUES(".$record->getFieldValue("filled_by","DB","NULL").",".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
"'".$props->getProperty("vacancy_oid","",true)."',".
"'0',".
"'0')"; ?>