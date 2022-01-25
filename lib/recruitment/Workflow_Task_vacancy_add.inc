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
        $this->setProperty('list.url',$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs='.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=ajax');
        $this->setProperty("back_list.url",
            PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=list&amp;'.(isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"").'&amp;mode=page'
        );

		if(isset($_REQUEST['from']) && $_REQUEST['from'] == 'home'){
			$this->setProperty("back_home.url",PORTAL_URL_PREFIX.'/recruitment3');
			$this->setProperty("from_home", true);
		}

        $this->setProperty('submit.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=add_process&amp;redirect=list');
        $this->setProperty('submit_continue.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=add_process&redirect=edit');


        /*$this->runView('/recruitment/vacancies/admin/directory__add@recruitment',array(
            'fmethod' => 'toForm',

        ),null);*/
        $this->runView('/recruitment/vacancies/add',array(
            'fmethod' => 'toHTML',

        ),null);

        return true;
	}
}
?>