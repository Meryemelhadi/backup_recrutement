<?php


require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_archive_vacancy extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}
	

	function run()
	{
		$this->putRecord($null=null, 'rct_vacancy.archive','update','db','Object',null);
		$url = PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php'; 
		$this->setProperty('redirect_url.url',$url);
		$this->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);
		return true;

	}
}
?>