<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961.
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once('candidates/services/directory.inc');


class Workflow_Task_download_cv extends NxPage
{
    function __construct($ctxt,$params,$taskID)
    {
        $this->NxPage($params,$ctxt,null);
        $this->ctxt = $this;
    }

    function run($workflow,$user)
    {
        $directory = new lib_recruitment_candidates_services_directory($this->ctxt);
        $directory->download($_REQUEST['candidate_oid'] , $_REQUEST['type']);
        return true;
    }
}
?>