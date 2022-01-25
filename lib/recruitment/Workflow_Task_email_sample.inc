<?php

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_email_sample  extends Workflow_Task
{
	function run($workflow, $user)
	{
		if(!isset($_REQUEST['oid']))
			return true;

		$oid = $_REQUEST['oid'];
		$sample = new PersistentObject('rct_email_sample.by_oid@recruitment','db',array('oid'=>$oid));
		if(!$sample->isOk())
			return true;

		$res = new stdClass();
		
		$res->title = $sample->email_title->js; 
		$res->content = $sample->email_content->js; 
		$res->docs = $sample->docs->object;

		// echo json_encode($res);
		echo <<<EOH
{
title:'{$res->title}',
content:'$res->content',
docs: '{$res->docs}'
}
EOH;

		return true;
	}
}
?>