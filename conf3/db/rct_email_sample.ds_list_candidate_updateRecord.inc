<?php $properties["query"]="UPDATE _rct_email_sample SET _oid=".$record->getFieldValue("oid","DB","NULL").",_name=".$record->getFieldValue("name","DB","NULL").",_type_email=".$record->getFieldValue("type_email","DB","NULL").",_email_title=".$record->getFieldValue("email_title","DB","NULL").",_email_content=".$record->getFieldValue("email_content","DB","NULL").",_docs=".$record->getFieldValue("docs","DB","NULL")." WHERE _type_email in('2','3','4','6','7','8','1')"; ?>