<?php $properties["query"]="SELECT _vacancy_oid,_created_by,_creation_date,_ann_title,_provider_oid FROM _rct_announcement WHERE _vacancy_oid='".$props->getProperty("vacancy_oid","",true)."' AND _type='internet' ORDER BY _creation_date DESC "; ?>