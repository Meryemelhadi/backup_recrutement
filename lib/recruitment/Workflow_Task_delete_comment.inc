<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
class Workflow_Task_delete_comment extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->ctxt = $ctxt;
		$this->NxPage($params,$ctxt,null);
	}

	function run($workflow, $user)
	{
		$this->getLock();
		$this->deleteRecords('rct_candidate_comment.delete',$this->getRecords('rct_candidate_comment.delete',null,'db'),'db',true);
		$this->setProperty("candidate_oid", $_REQUEST['candidate_oid']);
		$d =  new PersistentCollection('rct_candidate_comment.by_candidate@recruitment','db', null);
		$comment = '';
		for ($iterRec0 = $d->records->getRecordIterator(); $iterRec0->isValid(); $iterRec0->next())
		{
			$currentRecord0=$iterRec0->getCurrent();
			$comment .= '<p class="triangle-border top tooltip_comment" title="'.$currentRecord0->user_oid->html.' '.$currentRecord0->date->html.'">'.$currentRecord0->comment->html.'</p>';
			
		}
		$this->setProperty("oid", $_REQUEST['candidate_oid']);
		$comments_cache = $this->getRecord('rct_candidate.edit_comments_cache@recruitment',null,'db',false,null,null);
		$this->setProperty("comments_cache", $comment );
		$this->putRecord($comments_cache , 'rct_candidate.edit_comments_cache@recruitment' , 'update','db','Object',null);
        $this->unlock();
		
		return true;
		
	}
	// ======= LOCKS ========
	static $lock_comment;
	static $fp_comment;
	function getLock($name='comment') {
		
		$lockfp="fp_$name";
		$isLock = "lock_{$name}";
		if (!isset(self::$$isLock) || !self::$$isLock)
		{
			nxLog('REQUEST LOCK for '.$name , 'lock');
			self::$$lockfp = fopen(NX_CLIENT_ROOT .'locks/'."lock_{$name}.txt", "w+");
			self::$$isLock = flock(self::$$lockfp, LOCK_EX);

			nxLog('GOT THE LOCK for '.$name , 'lock');
		}
	}

	function unlock($name='comment') {
		$lockfp="fp_$name";
		$isLock = "lock_{$name}";
		if (isset(self::$$isLock) && self::$$isLock)
		{
			nxLog('RELEASING LOCK for '.$name , 'lock');
			flock(self::$$lockfp, LOCK_UN); // lib?re le verrou
			fclose(self::$$lockfp);
			self::$$isLock=null;
			self::$$lockfp=null;
		}
	}

}
?>