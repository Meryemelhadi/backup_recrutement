<?php
require_once(NX_LIB.'module/NxPage.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_add_attached_files extends NxPage
{
    function __construct($ctxt,$params,$taskID)
    {
        $this->NxPage($params,$ctxt,null);
        $this->ctxt = $this;
    }

    function run($workflow,$user)
    {
        $this->putRecord($this->getRecord('rct_candidate_files.record@recruitment','page.record','request',false,null,null),'rct_candidate_files.record@recruitment','insert','db','Object',null);
        //Add log
        $log= new lib_recruitment_candidates_services_log($this->ctxt);
        $log->addLog($_GET['candidate_oid'], $user->oid->object, 13 , '' , '');

        $src = "";
		$fram = "";
		if(isset($_REQUEST["src"]) && $_REQUEST["src"] ===  'newcvt'){
			$src = "&src=newcvt";
			$fram = "/fram";
		}
		header('Location:'.($u=$this->getProperty('site.url.noprefix','').$fram.$_SERVER["PHP_SELF"].'?nxo=edit&nxs=&mode=page&tab=recruitement_card&oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"").'&candidate_oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:"").$src));
        nxLog('redirect to '.$u,'redirect');
        return true;
    }

}

?>