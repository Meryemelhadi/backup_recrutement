<?php $properties["query"]="SELECT COUNT(*) as nbrecords FROM _rct_education WHERE _candidate_oid='".$props->getProperty("oid","0",true)."' GROUP BY _diploma,_date,_diploma_type "; ?>