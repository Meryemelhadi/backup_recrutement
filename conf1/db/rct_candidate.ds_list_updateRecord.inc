<?php $properties["query"]="UPDATE _rct_candidate SET _oid=".$record->getFieldValue("oid","DB","NULL").",_first_name=".$record->getFieldValue("first_name","DB","NULL").",_last_name=".$record->getFieldValue("last_name","DB","NULL")." WHERE _oid in('".$props->getProperty("cat.enum","",true)."')"; ?>