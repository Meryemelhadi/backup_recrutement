<?php $properties["query"]="SELECT _oid,_candidate_oid,_diploma,_diploma_type,_institution,_date,_description FROM _rct_education WHERE _candidate_oid='".$props->getProperty("oid","0",true)."' ORDER BY _date DESC "; ?>