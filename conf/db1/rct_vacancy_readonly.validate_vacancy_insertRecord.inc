<?php $properties["query"]="INSERT INTO _rct_vacancy_readonly(_workflow_state,_opening_date,_progress_level,_current_step) VALUES('".$this->getParamValue("validation_key","","request",",")."',".
"NOW(),".
"'0',".
"'0')"; ?>