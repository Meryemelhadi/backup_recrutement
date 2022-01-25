<?php
require_once(NX_LIB.'module/NxPage.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_add_comment extends NxPage
{
    function __construct($ctxt,$params,$taskID)
    {
        $this->NxPage($params,$ctxt,null);
        $this->ctxt = $this;
    }

    function run($workflow,$user)
    {
        $this->putRecord($this->getRecord('rct_candidate_comment.add@recruitment','page.record','post',false,null,null),'rct_candidate_comment.add@recruitment','insert','db','Object',null);
        $comment = $this->getLastInsertID('db');
		
        $this->setProperty("comment_oid", $comment );
        $c = $this->getRecord('rct_candidate_comment.get_record@recruitment','page.record','db',false,null,null);
		$this->setProperty("oid", $c->candidate_oid->object);
		
		$this->getLock();
		$comments_cache = $this->getRecord('rct_candidate.edit_comments_cache@recruitment',null,'db',false,null,null);
		$new_comment_cache = $comments_cache->comments_cache->html .' <p class="triangle-border top tooltip_comment" title="'.$c->user_oid->html.' '.$c->date->html.'">'.$c->comment->html.'</p>';
		$this->setProperty("comments_cache", $new_comment_cache );
		$this->putRecord($comments_cache , 'rct_candidate.edit_comments_cache@recruitment' , 'update','db','Object',null);
		$this->unlock();
		
        //Add log
        $log= new lib_recruitment_candidates_services_log($this->ctxt);
        $log->addLog($_GET['oid'], $user->oid->object, 9 , '' , '');
        
        $this->setProperty('delete_comment.url',$_SERVER["PHP_SELF"].'?nxo=delete_comment&nxs=&candidate_oid='.$_GET['oid'].'&oid='.$comment);
        $this->runView('/recruitment/candidates/components/comment',array('fmethod' => 'toHTML'),null);
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