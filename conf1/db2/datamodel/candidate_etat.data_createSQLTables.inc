<?php $properties["query"]=array("CREATE TABLE IF NOT EXISTS _rct_candidate_etat(_oid INT AUTO_INCREMENT NOT NULL,_name TEXT,_index TEXT,_taskType TEXT,_in_home CHAR(2) NULL DEFAULT 1,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_candidate_etat_assoc(_oid INT AUTO_INCREMENT NOT NULL,_candidate_oid integer,_etat_oid integer,_vacancy_oid integer,PRIMARY KEY(_oid))",); ?>