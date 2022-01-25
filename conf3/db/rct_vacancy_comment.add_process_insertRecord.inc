<?php $properties["query"]="INSERT INTO _rct_vacancy_comment(_oid,_interview_oid,_user_oid,_date,_education,_motivations,_experiences,_qualifications,_current_salary,_desired_salary,_leaving_period,_hobbies,_best_professional_moment,_worst_professional_moment,_person_who_marked_me_posivively,_person_who_marked_me_negatively,_parents_jobs,_spouse_job,_best_quality,_worst_lack,_lucky_or_brave,_last_making_authority) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
"'".$props->getProperty("interview_oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
$record->getFieldValue("education","DB","NULL").",".
$record->getFieldValue("motivations","DB","NULL").",".
$record->getFieldValue("experiences","DB","NULL").",".
$record->getFieldValue("qualifications","DB","NULL").",".
$record->getFieldValue("current_salary","DB","NULL").",".
$record->getFieldValue("desired_salary","DB","NULL").",".
$record->getFieldValue("leaving_period","DB","NULL").",".
$record->getFieldValue("hobbies","DB","NULL").",".
$record->getFieldValue("best_professional_moment","DB","NULL").",".
$record->getFieldValue("worst_professional_moment","DB","NULL").",".
$record->getFieldValue("person_who_marked_me_posivively","DB","NULL").",".
$record->getFieldValue("person_who_marked_me_negatively","DB","NULL").",".
$record->getFieldValue("parents_jobs","DB","NULL").",".
$record->getFieldValue("spouse_job","DB","NULL").",".
$record->getFieldValue("best_quality","DB","NULL").",".
$record->getFieldValue("worst_lack","DB","NULL").",".
$record->getFieldValue("lucky_or_brave","DB","NULL").",".
$record->getFieldValue("last_making_authority","DB","NULL").")"; ?>