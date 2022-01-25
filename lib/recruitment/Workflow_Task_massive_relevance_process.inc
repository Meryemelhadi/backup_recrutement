<?php

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_massive_relevance_process extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
	}

	function run()
	{
		if(isset($_REQUEST["candidates_oid"]) && (isset($_REQUEST["relevance_oid"]))){
			$candidates_oids = explode('|', trim($_REQUEST["candidates_oid"], '|'));
			$inseredOids = array();
			
			foreach($candidates_oids as $i=>$value)
			{
				$this->setProperty("relevance_oid",(isset($_REQUEST["relevance_oid"])?$_REQUEST["relevance_oid"]:""));
				$this->setProperty("oid", $value);
				$this->putRecord($null=null,'rct_candidate.relevance','update','db','Object',null);
			}
		}
		$this->setProperty("filterKey",(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""));
		header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=list&nxs='.preg_replace(array('%&amp;%','%[+]%'),array('&','%2B'),urldecode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""))).'&mode=ajax'));
		nxLog('redirect to '.$u,'redirect');
		
		return true;
	}
}
?>