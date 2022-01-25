<?php

require_once('candidates/services/directory.inc');

class Workflow_Task_edit_test extends Workflow_Task_record
{
    function run($workflow, $user)
    {

        $model = $workflow->model;
        $state = $workflow->getState();

        $this->ctxt->setProperty('workflow',$workflow);

        $media=$this->getParam('media','db');
        if($media == 'empty')
        {
            // new record
            $ds=$this->getParam('ds','new');
            $dml = $model->getDS($ds,$state);
            if(!$dml)
                $dml = $model->getDS('record',$state);
        }
        else
        {
            // edit existing record
            $ds=$this->getParam('ds','record');
            $dml = $model->getDS($ds,$state);
            if(!$dml)
                $dml = $model->getDS('edit',$state);
        }

        // if no valid data source, just stop...
        if(!$dml)
            return false;

        // load record from request in create mode (with clone enabled if using models)
        $o = new PersistentObject();
        $o->load($dml,$media);
        if(!$o->isOk())
        {
            // execute callback if cant load
            if($onFailure =$this->getParam('onFailure'))
                $onFailure($workflow,$user,$o,$this);
        }

        if($o->isOk())
        {
            $formDesc=$this->getParam('fields','fields');

            // customise fields
            $state = $workflow->getState();
            $this->customiseFields($state,$workflow, $user,$o->record,$formDesc);

            // execute callback
            if($onLoad =$this->getParam('onLoad'))
                $onLoad($workflow,$user,$o->record,$this);

            // get buttons
            $props=array();
            if($buttons =$this->getParam('buttons'))
            {
                foreach($buttons as $k=>$url)
                    $props[$k.'.url']=$url;
            }
            $props['actions']=$workflow->getActions();
        }
        else
        {
            $props['actions']=array();
        }

        // search context to pass on to next operation
        if(isset($_REQUEST['filterKey']))
        {
            // for passing as actual search params (to list)
            $this->ctxt->setProperty('filterKey',$_REQUEST['filterKey']);

            // for passing on to next operation (encoded)
            $this->ctxt->setProperty('filterKeyUrl','&amp;filterKey='.urlencode($_REQUEST['filterKey']));
        }

        // get form def if any
        $this->ctxt->setProperty('form.desc',$this->getParam('form','record'));

        // Mark CV as read
        /*$directory = new lib_recruitment_candidates_services_directory($this->ctxt);
        $directory->insertReadState($userOid,$oid);*/

        // display record
        $view = $model->getDisplayView($this->getParam('view','record'));
        $view_type = $this->getParam('view_type','HTML');
        $props['view.type']=$view_type;
        $props['page.record']=$o->record;
        $this->ctxt->runView($view,$props);

        return true;
    }
}