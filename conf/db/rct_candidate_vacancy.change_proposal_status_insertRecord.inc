<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy(_status,_proposal_acceptance_date,_proposal_acceptance_state) VALUES('".$props->getProperty("status_value","",true)."',".
"'".$props->getProperty("rawdate","",true)."',".
"'".$props->getProperty("proposal_acceptance_state","",true)."')"; ?>