<?php $properties["query"]="UPDATE _rct_delayed_feedback SET _oid=".$record->getFieldValue("oid","DB","NULL")." WHERE _vacancy_oid='".$props->getProperty("vacancy_oid","",true)."' AND _fill_state='1'"; ?>