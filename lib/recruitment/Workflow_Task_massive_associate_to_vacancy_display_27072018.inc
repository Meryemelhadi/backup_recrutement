<?php


require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_massive_associate_to_vacancy_display extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}

	function run()
	{
		$this->setProperty("candidates_oid",(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""));
		if($GLOBALS['_NX_user']->checkPerm('?-drh'))
			$this->getRecords('handler:recruitment.vacancy.list.drh','page.records','db',false,null,null);
		else $this->getRecords('handler:recruitment.vacancy.list','page.records','db',false,null,null);
		$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=massive_associate_to_vacancy_process');
		$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
		$this->runView('recruitment.candidates.components.vacancy_massive_assoc_bs',array(
			'fmethod' => 'toHTML',

			),null);
		return true;
	}
}
?>