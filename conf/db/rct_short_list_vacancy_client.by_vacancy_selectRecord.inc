<?php $properties["query"]="SELECT _oid,_short_list_oid,_vacancy_oid,_proposed_by,_proposal_date,_comment FROM _rct_short_list_vacancy_client WHERE _vacancy_oid='".$props->getProperty("vacancy_oid","",true)."'"; ?>