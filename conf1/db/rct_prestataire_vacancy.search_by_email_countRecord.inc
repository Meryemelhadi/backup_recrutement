<?php $properties["query"]="SELECT COUNT(*) as nbrecords FROM _rct_vacancy_provider WHERE (_from_email='".$props->getProperty("email","",true)."' OR _to_email='".$props->getProperty("email","",true)."') "; ?>