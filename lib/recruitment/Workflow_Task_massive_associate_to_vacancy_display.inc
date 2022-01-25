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
		$this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=massive_associate_to_vacancy_process&'.$this->lien_cleaner());
		//$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&'.$this->lien_cleaner().'&amp;mode=ajax');
		$this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&nxs='.preg_replace(array('%&amp;%','%[+]%'),array('&','%2B'),urldecode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""))).'&mode=ajax');
		$this->runView('recruitment.candidates.components.vacancy_massive_assoc_bs',array(
			'fmethod' => 'toHTML',

			),null);
		return true;
	}
	function lien_cleaner ()
	{
		$arg = explode('&', $_SERVER['QUERY_STRING']);
		$chaine_final = '';
		foreach( $arg as $value )
		{
			$arg2 = explode('=', $value);  
			if ($arg2[0]!= 'nxo' && $arg2[0]!= 'nxs') {$chaine_final .= $value.'&';}   
		}
		return $chaine_final ;
	}
}
?>