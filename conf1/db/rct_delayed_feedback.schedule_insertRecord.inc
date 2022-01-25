<?php $properties["query"]="INSERT INTO _rct_delayed_feedback(_candidate_oid,_filled_by,_launch_date,_scheduled_by,_scheduled_on,_vacancy_oid,_fill_state,_notification_state) VALUES(".$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("filled_by","DB","NULL").",".
$record->getFieldValue("launch_date","DB","now+6 months").",".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
"'".$props->getProperty("vacancy_oid","",true)."',".
"'0',".
"'0')"; ?>