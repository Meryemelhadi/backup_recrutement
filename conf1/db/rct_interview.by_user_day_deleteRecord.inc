<?php $properties["query"]="DELETE FROM _rct_interview WHERE (_key=_rct_interview._oid AND _val='".$this->getParamValue("interview_by_oid","","request",",")."')  AND _date='".$this->getParamValue("date","","request",",")."'"; ?>