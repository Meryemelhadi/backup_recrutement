<?php $properties["query"]="UPDATE _rct_school SET _oid=".$record->getFieldValue("oid","DB","NULL").",_code=".$record->getFieldValue("code","DB","NULL").",_label=".$record->getFieldValue("label","DB","NULL")." WHERE _code='".$props->getProperty("code","",true)."'"; ?>