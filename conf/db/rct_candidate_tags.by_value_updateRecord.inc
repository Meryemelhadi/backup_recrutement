<?php $properties["query"]="UPDATE _rct_candidate_tags SET _oid=".$record->getFieldValue("oid","DB","NULL").",_name=".$record->getFieldValue("name","DB","NULL")." WHERE _name='".$props->getProperty("value","",true)."'"; ?>