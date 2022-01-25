<?php

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_preview extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $ctxt;
		
	}

	function run()
	{
		($tmp=
			(($__o=$this->getHandler('lib.recruitment.candidates.services.directory','')) ? $__o->preview((isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""),(isset($_REQUEST["type"])?$_REQUEST["type"]:"")) : null))!=null?$this->addProperties($tmp):null;
		$this->runView('_preview',array(
			'fmethod' => 'toHTML',

			),null);
		
		return true;
	}
}