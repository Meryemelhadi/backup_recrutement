<?php $properties["query"]="UPDATE _rct_vacancy SET _oid=".$record->getFieldValue("oid","DB","NULL").",_name=".$record->getFieldValue("name","DB","NULL").",_email=".$record->getFieldValue("email","DB","NULL").",_number=".$record->getFieldValue("number","DB","'1'").",_code=".$record->getFieldValue("code","DB","NULL").",_opening_date=".$record->getFieldValue("opening_date","DB","NOW()").",_duty_station_oid=".$record->getFieldValue("duty_station_oid","DB","NULL").",_salaire=".$record->getFieldValue("salaire","DB","NULL").",_descriptionEntreprise=".$record->getFieldValue("descriptionEntreprise","DB","NULL").",_descriptionPoste=".$record->getFieldValue("descriptionPoste","DB","NULL").",_descriptionProfil=".$record->getFieldValue("descriptionProfil","DB","NULL").",_date=NOW(),_duree=".$record->getFieldValue("duree","DB","NULL").",_nombrePoste=".$record->getFieldValue("nombrePoste","DB","NULL").",_startDate=".$record->getFieldValue("startDate","DB","NOW()").",_endDate=".$record->getFieldValue("endDate","DB","NOW()"); ?>