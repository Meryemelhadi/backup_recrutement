<?php $properties["query"]="UPDATE _rct_short_list SET _oid=".$record->getFieldValue("oid","DB","NULL").",_name=".$record->getFieldValue("name","DB","NULL")." WHERE _oid='".$props->getProperty("sl_oid","",true)."'"; ?>