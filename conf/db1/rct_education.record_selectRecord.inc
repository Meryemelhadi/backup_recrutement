<?php $properties["query"]="SELECT _oid,_candidate_oid,_diploma,_diploma_type,_institution,_date,_description FROM _rct_education WHERE _oid=".$this->getFieldParam("oid","null",",",$record,"")." ORDER BY _date DESC "; ?>