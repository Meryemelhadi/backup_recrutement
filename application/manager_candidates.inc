<?php

$app_desc = $this->ctxt->getProperty('application.desc');

$icons = array(
    'add'=>'si-add',
    'edit'=>'si-page-white-edit',
    'submit'=>'si-disk',
    'delete'=>'si-delete',
    'save'=>'si-disk',
    'export_excel'=>'si-page-white-excel');


// data sources (optional)
$datasources = array(
    // EDIT
    'record'   => 'rct_candidate.edit@recruitment',       // default record form
    'delete_comment' => 'rct_candidate_comment.delete@recruitment',
    'by_user_and_candidate' => 'rct_interview.by_user_and_candidate@recruitment'
);

$strings   = "recruitment_candidates_directory@recruitment";

$forms   = $this->ctxt->getProperty('app.forms',array());

$this->ctxt->setProperty('app.form.css',<<<ECSS
	/* CSS RULES here */
    @import url("/nx/skins/default/css/recruitment/candidate_bs.css");
ECSS
);

$this->ctxt->setProperty('app.form.js',<<<EJS
	/* js code */
	ajax_require('/nx/skins/default/js/recruitment/form_candidate.js','recruitment');

EJS
);

// form definition
include('candidate_form_desc.inc');

$nxo = $this->ctxt->getProperty('nxo','nxo');

$defaultLogic = function($workflow,$user) {
    $ctxt = $workflow->ctxt;
    $logic = $ctxt->getProperty('page.logic');
    return $ctxt->runLogic($logic);
};


$properties=array
(
    // ========================= CRUD APPLICATION ==================

    'application' => array
    (
        'editor' => array
        (
            'meta' => array
            (
                'name' => ('List title'),
                'description' => ('Edit items'),
                'strings' => $strings,

                'uid' => 'candidates@recruitment',

                // data descriptors
                'data'  => array(
                    'manager_search' => 'rct_candidate.manager_search@recruitment',
                    'new' => 'rct_candidate.add@recruitment',
                    'record' => 'rct_candidate.edit@recruitment'
                ),

                // default display views
                'views' => array(
                    'list' => 'workflow.xlist_search@workflow',
                    'new' => 'recruitment.candidates.add@recruitment',
                    //'record' => 'workflow.xedit_generic@workflow',
                    'record' => 'workflow.xedit_generic_attachments3@workflow',
                ),

                'forms' => $forms,

                'icons'=>$icons,

                'list_operations' => array('edit'=>array('nxo'=>'edit'),'delete'=>array('nxo'=>'delete')),

                'operation_init'=>'list',

                // default tasks executed for loading a state
                // 'state_loader'  => 'Workflow_StateLoader',
                'onload'  => array(),

                // tasks executed before executing an action : load submitted form
                'onBeforeAction'  => array(),

                // default tasks executed after executing an action
                // 'onAfterAction'  => array( 'tasks' => array('log')),
            ),

            'operations' => array(

                'list' => array(
                    'title' => 'Liste des candidats', // ('List items'),
                    'description' => ('List items'),

                    'tasks' => array(
                        'load_my_entities@admin2',
                        'manager_list_candidates'=>array(
                            'data'=>'list','manager_search'=>'manager_search','view'=>'list',
                            //	'buttons'=>array('action'=>'?nxo=action','add'=>'?nxo=add')
                        )
                    ),

                    'actions'=>array(
                    )
                ),

                'edit' => array(
                    'title' => ('edit record'),
                    'description' => ('exec_workflow'),

                    'tasks' => array(
                        'load_my_entities@admin2',
                       // 'permission_candidate',
                        'manager_edit_candidate'
                        //'display_record' => array('media'=>'db','buttons'=>array('back'=>"?nxo={$app_pre}list"))

                    ),

                    'actions'=>array
                    (
                        // 'save' => array('name'=>('save'), 'nxo' => 'edit_save','id'  => 'content'),
                        //'submit' => array('name'=>'submit', 'nxo' => 'edit_process','id'  => 'content')
                    )
                ),

                'edit_save' => array(
                    'title' => ('process record'),
                    'description' => ('process record'),

                    'tasks' => array(
                        'load_my_entities@admin2',
                        $defaultLogic
                    ),
                    'actions'=>array
                    (
                        //'back' => array('name'=>('back'), 'nxo' => 'list', 'id'  => 'content'),
                        'save' => array('name'=>('save'), 'nxo' => 'edit_save','id'  => 'content'),
                        'submit' => array('name'=>('submit'), 'nxo' => 'edit_process','id'  => 'content')
                    )
                ),

                'edit_process' => array(
                    'title' => ('process record'),
                    'description' => ('process record'),

                    'tasks' => array(
                        'load_my_entities@admin2',
                        'edit_candidate_process'
                    )
                ),

				'download' => array(
                    'title' => ('download cv'),
                    'description' => ('download cv'),

                    'tasks' => array(
                        'download_cv',
                    )
                ),
				'add_comment' => array
                (
                    'title' => 'Add comment',
                    'description' => ('Add comment'),

                    'tasks' => array(
                        'add_comment',
                    )
                ),
				'delete_comment' => array
                (
                    'title' => 'Delete comment',
                    'description' => ('Delete comment'),

                    'tasks' => array(
                        'delete_comment',
                    )
                ),

                // default operation
                'default' => array(
                    'title' => ('delete record'),
                    'description' => ('delete record'),

                    'tasks' => array(
                        'load_my_entities@admin2',
                        $defaultLogic
                    )
                )
            )
        )
    )
);

?>