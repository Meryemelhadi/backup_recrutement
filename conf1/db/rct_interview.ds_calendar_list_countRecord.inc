<?php $properties["query"]="SELECT COUNT(*) as nbrecords FROM _rct_interview,_rct_interview_by WHERE ((_rct_interview_by._key=_rct_interview._oid AND _rct_interview_by._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."')  OR (_rct_interview._created_by='".$GLOBALS["_NX_user"]->getProperty("oid","",true)."') )  GROUP BY _rct_interview._oid "; ?>