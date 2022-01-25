<?php $properties["query"]="INSERT INTO _journal(_oid,_provider_oid,_category_id,_title,_summary,_content,_author_id,_creation_date,_validated,_validated_by,_image,_type) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("provider_oid","DB","NULL").",".
$record->getFieldValue("category_id","DB","NULL").",".
$record->getFieldValue("title","DB","NULL").",".
$record->getFieldValue("summary","DB","NULL").",".
$record->getFieldValue("content","DB","NULL").",".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
"'0',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
$record->getFieldValue("image","DB","NULL").",".
"'internet')"; ?>