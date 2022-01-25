<?php $properties["query"]="
					SELECT _rct_vacancy._oid , _rct_vacancy._name,
						_rct_vacancy._code FROM _rct_vacancy 
						where _rct_vacancy._current_step = 0 
				"; ?>