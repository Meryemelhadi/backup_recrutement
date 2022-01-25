<?php $properties["query"]="INSERT INTO _rct_vacancy_provider(_provider_oid,_vacancy_oid,_request_date) VALUES(".$record->getFieldValue("provider_oid","DB","NULL").",".
"'".$props->getProperty("vacancy_oid","",true)."',".
"NOW())"; ?>