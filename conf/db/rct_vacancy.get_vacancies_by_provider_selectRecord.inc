<?php $properties["query"]="
					SELECT 	_rct_vacancy._oid,_rct_vacancy._name , _rct_vacancy._email , _rct_vacancy._code , VP._oid AS _vp_oid , VP._ref , VP._offer_name , VP._index, VP._id_index
					FROM _rct_vacancy 
					LEFT JOIN _rct_vacancy_provider as VP ON VP._vacancy_oid = _rct_vacancy._oid
					WHERE VP._provider_oid= '".$props->getProperty("provider_oid")."' 
				"; ?>