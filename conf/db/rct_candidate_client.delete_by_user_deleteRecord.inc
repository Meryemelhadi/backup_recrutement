<?php $properties["query"]="DELETE FROM _rct_candidate_client WHERE (_proposed_by='".$props->getProperty("user_oid","",true)."' OR _proposed_to='".$props->getProperty("user_oid","",true)."') "; ?>