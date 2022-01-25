<?php $properties["query"]="INSERT INTO _rct_instant_feedback(_completed_by,_completed_on,_complete_state,_recruitment_cost,_recruitment_budget_followed) VALUES('".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
"'1',".
$record->getFieldValue("recruitment_cost","DB","NULL").",".
$record->getFieldValue("recruitment_budget_followed","DB","NULL").")"; ?>