<?php $properties["query"]="INSERT INTO _rct_instant_feedback(_first_sl_period,_cv_in_sl,_cv_pc_in_interview,_cv_having_good_level,_period_before_agreement,_hr_staff_need_identification,_cv_in_sl_quality,_cv_in_interview_quality,_satisfaction_with_candidate,_instant_comment) VALUES(".$record->getFieldValue("first_sl_period","DB","NULL").",".
$record->getFieldValue("cv_in_sl","DB","NULL").",".
$record->getFieldValue("cv_pc_in_interview","DB","NULL").",".
$record->getFieldValue("cv_having_good_level","DB","NULL").",".
$record->getFieldValue("period_before_agreement","DB","NULL").",".
$record->getFieldValue("hr_staff_need_identification","DB","NULL").",".
$record->getFieldValue("cv_in_sl_quality","DB","NULL").",".
$record->getFieldValue("cv_in_interview_quality","DB","NULL").",".
$record->getFieldValue("satisfaction_with_candidate","DB","NULL").",".
$record->getFieldValue("instant_comment","DB","NULL").")"; ?>