<?php $properties["query"]="SELECT _oid,_interview_oid,_user_oid,_date FROM _rct_vacancy_comment WHERE _interview_oid='".$props->getProperty("interview_oid","",true)."' AND _user_oid='".$props->getProperty("interview_by_oid","",true)."'"; ?>