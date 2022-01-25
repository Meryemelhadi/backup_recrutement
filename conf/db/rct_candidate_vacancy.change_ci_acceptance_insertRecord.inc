<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy(_ci_acceptance_state,_ci_acceptance_date) VALUES('".$props->getProperty("acceptance_status","",true)."',".
"NOW())"; ?>