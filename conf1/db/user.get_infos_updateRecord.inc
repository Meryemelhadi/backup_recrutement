<?php $properties["query"]="UPDATE _user SET _oid=".$record->getFieldValue("oid","DB","NULL").",_civility=".$record->getFieldValue("civility","DB","NULL").",_first_name=".$record->getFieldValue("first_name","DB","NULL").",_last_name=".$record->getFieldValue("last_name","DB","NULL").",_email=".$record->getFieldValue("email","DB","NULL").",_role=".$record->getFieldValue("role","DB","NULL").",_mobile_phone=".$record->getFieldValue("mobile_phone","DB","NULL").",_direct_phone=".$record->getFieldValue("direct_phone","DB","NULL").",_local_phone=".$record->getFieldValue("local_phone","DB","NULL").",_personal_phone=".$record->getFieldValue("personal_phone","DB","NULL").",_group=".$record->getFieldValue("group","DB","NULL").",_photo=".$record->getFieldValue("photo","DB","NULL")." WHERE _oid in('".$props->getProperty("oid","",true)."')"; ?>