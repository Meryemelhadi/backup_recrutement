<?php $properties["query"]="INSERT INTO _rct_instant_feedback(_oid,_scheduled_by,_scheduled_on,_filled_by,_filled_on,_completed_by,_completed_on,_fill_state,_complete_state,_first_sl_period,_cv_in_sl,_cv_pc_in_interview,_cv_having_good_level,_period_before_agreement,_recruitment_cost,_hr_staff_need_identification,_cv_in_sl_quality,_cv_in_interview_quality,_satisfaction_with_candidate,_recruitment_budget_followed,_instant_comment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("scheduled_by","DB","NULL").",".
$record->getFieldValue("scheduled_on","DB","NOW()").",".
$record->getFieldValue("filled_by","DB","NULL").",".
$record->getFieldValue("filled_on","DB","NOW()").",".
$record->getFieldValue("completed_by","DB","NULL").",".
$record->getFieldValue("completed_on","DB","NOW()").",".
$record->getFieldValue("fill_state","DB","NULL").",".
$record->getFieldValue("complete_state","DB","NULL").",".
$record->getFieldValue("first_sl_period","DB","NULL").",".
$record->getFieldValue("cv_in_sl","DB","NULL").",".
$record->getFieldValue("cv_pc_in_interview","DB","NULL").",".
$record->getFieldValue("cv_having_good_level","DB","NULL").",".
$record->getFieldValue("period_before_agreement","DB","NULL").",".
$record->getFieldValue("recruitment_cost","DB","NULL").",".
$record->getFieldValue("hr_staff_need_identification","DB","NULL").",".
$record->getFieldValue("cv_in_sl_quality","DB","NULL").",".
$record->getFieldValue("cv_in_interview_quality","DB","NULL").",".
$record->getFieldValue("satisfaction_with_candidate","DB","NULL").",".
$record->getFieldValue("recruitment_budget_followed","DB","NULL").",".
$record->getFieldValue("instant_comment","DB","NULL").")"; ?>