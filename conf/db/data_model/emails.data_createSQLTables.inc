<?php $properties["query"]=array("CREATE TABLE IF NOT EXISTS _rct_email(_oid INT AUTO_INCREMENT NOT NULL,_candidate_oid integer,_vacancy_oid integer,_created_by integer,_creation_date DATETIME,_user_cc TEXT,_email_type integer,_email_title TEXT,_email_content TEXT,_docs varchar(255),PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_email_attached_file(_oid INT AUTO_INCREMENT NOT NULL,_email_oid integer,_file TEXT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_candidate_email_cc(_oid INT AUTO_INCREMENT NOT NULL,_key INT,_val INT,PRIMARY KEY(_oid),KEY IDX_MAIN (_key))",); ?>