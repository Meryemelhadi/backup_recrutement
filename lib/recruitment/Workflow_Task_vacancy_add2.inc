<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_vacancy_add extends NxPage
{

    function __construct($ctxt,$params,$taskID)
    {
        $this->NxPage($params,$ctxt,null);
    }

	function run()
	{

        $this->getRecord('rct_vacancy.add_'.$this->getProperty("recruitement_profile","default").'@recruitment','page.record','empty',false,null,null);
        $this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=vacancies@recruitment:list&amp;'.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
        $this->setProperty("list.url",
            PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=vacancies@recruitment:list&amp;'.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=page'
        );
        $this->setProperty("list.type", 'link');
        $this->setProperty("add.url", 'link');
        $this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=vacancies@recruitment:add_process&amp;redirect=list');
        $this->setProperty('submit_continue.url',$_SERVER["PHP_SELF"].'?nxo=vacancies@recruitment:add_process&amp;redirect=edit');

        $this->runView('/recruitment/vacancies/admin/directory__add@recruitment',array(
            'fmethod' => 'toForm',

        ),null);

        return true;
	}
}
?>