<?php $properties["query"]="UPDATE _journal_categories SET _oid=".$record->getFieldValue("oid","DB","NULL").",_category_label=".$record->getFieldValue("category_label","DB","NULL").",_category_description=".$record->getFieldValue("category_description","DB","NULL"); ?>