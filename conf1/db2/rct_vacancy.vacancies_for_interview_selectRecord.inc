<?php $properties["query"]="
					select IFNULL( (SELECT _rct_vacancy._oid ,
											_rct_vacancy._name,
											_rct_vacancy._code
									FROM _rct_vacancy  
									Left join _rct_candidate_vacancy ON _rct_candidate_vacancy._vacancy_oid = _rct_vacancy._oid
									WHERE _rct_candidate_vacancy._candidate_oid = '".$this->getProperty("candidate_oid")."' ) ,
									(SELECT _rct_vacancy._oid ,
											_rct_vacancy._name,
											_rct_vacancy._code
									 FROM _rct_vacancy));
				"; ?>