<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy(_job_acceptance_state,_job_acceptance_date) VALUES('".$props->getProperty("acceptance_status","",true)."',".
"NOW())"; ?>