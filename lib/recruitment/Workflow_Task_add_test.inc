<?php
require_once(NX_LIB.'module/NxPage.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_add_test extends NxPage
{
    function __construct($ctxt,$params,$taskID)
    {
        $this->NxPage($params,$ctxt,null);
        $this->ctxt = $this;
    }

    function run($workflow,$user)
    {
        $this->setProperty("candidate_oid", $_REQUEST['candidate_oid'] );
        $this->setProperty("test_oid",  $_REQUEST['test_oid'] );
        $this->setProperty("pourcentage",  $_REQUEST['pourcentage'] );

        $this->putRecord($this->getRecord('rct_candidate_test_assoc.add@recruitment','page.record','get',false,null,null),'rct_candidate_test_assoc.add@recruitment','insert','db','Object',null);
        $this->getRecord('rct_candidate_test_assoc.candidate_test@recruitment','page.record','db',false,null,null);

        //Get test name
        $_GET["oid"] =  $_REQUEST['test_oid'];
        $record = new PersistentObject('rct_candidate_test.record@recruitment','db', array('oid'=>$_REQUEST['test_oid']));

        //Add log
        $log= new lib_recruitment_candidates_services_log($this->ctxt);
        $log->addLog($_GET['candidate_oid'], $user->oid->object, 12 , '' , '(Test:'.$record->name->html.')');

        $this->setProperty('delete_test.url',$_SERVER["PHP_SELF"].'?nxo=delete_test&nxs=&candidate_oid='.$_GET['candidate_oid']);
        $this->runView('/recruitment/candidates/components/test_assoc',array('fmethod' => 'toHTML'),null);
        return true;

    }

}
?>