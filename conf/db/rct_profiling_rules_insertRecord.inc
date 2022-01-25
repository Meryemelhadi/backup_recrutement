<?php $properties["query"]="INSERT INTO _rct_profiling_rules(_oid,_index,_name,_keywords,_not_keywords,_vacancy,_cand_channel,_profiling_on,_form_field,_profiling_value_for,_category_oid,_profile,_provider,_establishment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("index","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("keywords","DB","NULL").",".
$record->getFieldValue("not_keywords","DB","NULL").",".
$record->getFieldValue("vacancy","DB","NULL").",".
$record->getFieldValue("cand_channel","DB","NULL").",".
$record->getFieldValue("profiling_on","DB","cv").",".
$record->getFieldValue("form_field","DB","NULL").",".
$record->getFieldValue("profiling_value_for","DB","list").",".
$record->getFieldValue("category_oid","DB","NULL").",".
$record->getFieldValue("profile","DB","NULL").",".
$record->getFieldValue("provider","DB","NULL").",".
$record->getFieldValue("establishment","DB","NULL").")"; ?>