<?php $properties["query"]="UPDATE _rct_vacancy_comment SET _oid=".$record->getFieldValue("oid","DB","NULL")." WHERE _interview_oid='".$props->getProperty("interview_oid","",true)."'"; ?>