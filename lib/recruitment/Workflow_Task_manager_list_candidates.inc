<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961.
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_manager_list_candidates extends NxPage
{
    function __construct($ctxt,$params,$taskID)
    {
        $this->NxPage($params,$ctxt,null);
    }

    // change fields properties in record desc (edit, no_edit, hide, show)
    function customiseRecordFields($record,$workflow,$view=null)
    {
        $fields = $workflow->model->getDS('fields',$workflow->getState());

        if(isset($fields[$view]))
        {
            $fields = $fields[$view];
        }

        if($fields)
        {
            foreach($fields as $action => $fnames)
            {
                if($action == 'no_edit')
                    $workflow->setFieldsProperty($fnames, 'isEdit' , false,$record);
                elseif($action == 'edit')
                    $workflow->setFieldsProperty($fnames, 'isEdit' , true,$record);
                elseif($action == 'hide')
                    $workflow->setFieldsProperty($fnames, 'show' , false,$record);
                elseif($action == 'show')
                    $workflow->setFieldsProperty($fnames, 'show' , true,$record);
            }
        }
    }

    function run($workflow, $user)
    {
        $searchData=$this->getRecord('rct_candidate.manager_search','page.search','request',false,null,null);

        $this->customiseRecordFields($searchData,$workflow,'manager_search');

        $searchDataVar='searchData';
        $_searchKey_=(($_nx_rec13=${$searchDataVar})!=null?$_nx_rec13->getUrlKey(true):'');
        if((isset($_REQUEST["page"])?$_REQUEST["page"]:""))
        {
            $_searchKey_ = preg_replace("/page=[^&]+(&(amp;)?)?/",'',$_searchKey_);
            $_searchKey_=$_searchKey_.'&amp;page='.(isset($_REQUEST["page"])?$_REQUEST["page"]:"");
        }
        
        $this->setProperty("filterKey",$_searchKey_);

        if(isset($_GET['nxs']))
            $_searchKey_ = 'nxs='.$_GET['nxs'].'&'.$_searchKey_;

        if(isset($_GET['nxo']))
            $_searchKey_ = 'nxo='.$_GET['nxo'].'&'.$_searchKey_;

        $GLOBALS["NX_CURRENT_URL"] ='?'.$_searchKey_;

        $filterKey = $this->getProperty("filterKey","");
        $ufilterKey = urlencode($filterKey);

        $this->getRecords('handler:recruitment.candidates.manager_list','page.records','db',false,$searchData,null);
        $this->setProperty('edit.url',PORTAL_URL_PREFIX.'/recruitment/manager_candidates/index.php?nxo=edit&amp;nxs=&amp;from_mes_candidats=1&amp;filterKey='.$ufilterKey);
        $this->setProperty('preview_cv.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cv');
        $this->setProperty('relevance.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=relevance&amp;nxs=&amp;filterKey='.$ufilterKey);
        $this->setProperty('category.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=category&amp;nxs=process&amp;filterKey='.$ufilterKey);
        $this->setProperty('search.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;filterKey='.$ufilterKey);
        $this->setProperty('page.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;search_in_archive=0&amp;is_search=true');

        $this->setProperty('list.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=ajax&amp;cancel=true');
        $this->setProperty('list_cancel_search.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=ajax&amp;cancel=true');

        if((isset($_REQUEST["is_search"])?$_REQUEST["is_search"]:"") == 'true')
        {
            $this->setProperty("is_search",'true');
        }

        $this->setProperty('search_in_archive.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=list&amp;nxs=&amp;mode=ajax&amp;search_in_archive=1');
        $this->setProperty('xls_export.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=xls_export&amp;nxs='.$filterKey);

        $viewMode='page';
        $this->runView('recruitment.candidates.manager_list',array('fmethod' => 'toHTML',),null);

        return true;
    }
}
?>