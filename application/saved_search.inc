<?php
// package
$package = 'recruitment';

// prefix for dml views .record, .list, .search.
$base_data = 'recruitment';

// data sources (optional)
$datasources = array(
    // WORKFLOW
    'header'   => 'saved_search.record@recruitment', // state header

    // ADD
    'new'	   => 'saved_search.add@recruitment',    // new record form
    'add_process'   => 'saved_search.record@recruitment',  // save new form

    // EDIT
    'record'   => 'saved_search.record@recruitment',       // default record form
    'edit_process'   => 'saved_search.record@recruitment', // save edited form

    // LIST
    'search'   => 'saved_search.search@recruitment', // search form
    'excel'    => 'saved_search.excel@recruitment',  // excel list export
    'list'	   => 'saved_search.list@recruitment',   // list

);

// strings name
$strings = 'saved_search@recruitment';

// permissions foir the application
$permissions='default';

// same role as in www .php file
$main_role='editor';

$this->ctxt->setProperty('app.form.css',<<<ECSS
	/* CSS RULES here */
	#fields-control .checkbox_label{
	    margin:0px 5px;
	}
	#fields-control{
	    width:600px;
	}
ECSS
);

$this->ctxt->setProperty('app.form.js',<<<EJS
	/* js code */
EJS
);

// form definition
$forms = array(
    'record' => array(
        'tabs' => array(
            'Informations' => array(
                'title' => 'Informations',
                'fields' => array('*')
            ),
        )
    )
);

// optional views
$views = array
(
    'list' => 'workflow.list_page@workflow',
    'record' => 'workflow.xedit_generic_attachments3@workflow',
    'excel' => 'exports.excel.records',
);

// base application
$app_pre = isset($application) ? ($application.':') : '';

// extension liste des boutons de la liste
if(!isset($listActions))
    $listActions=array();

// classes des icones Ã  appliquer aux boutons
$icons = array(
    'add'=>'si-add',
    'edit'=>'si-page-white-edit',
    'display' => 'si-page-white',
    'delete'=>'si-delete',
    'submit'=>'si-disk',
    'save'=>'si-disk',
    'save_continue'=>'si-disk',
    'export_excel'=>'si-page-white-excel');

// nom des vues DML Ã  appliquer par les opÃ©rations
if(!isset($datasources))
    $datasources = array(
        'header'   => $base_data.'.record@'.$package,
        'new'	   => $base_data.'.add@'.$package,
        'record'   => $base_data.'.record@'.$package,
        'search'   => $base_data.'.search@'.$package,
        'excel'    => $base_data.'.excel@'.$package,
        'list'	   => $base_data.'.list@'.$package,
    );

if(!isset($views))
{
    $views = array
    (
        'list' => 'workflow.list_page@workflow',
        'record' => 'workflow.edit_page@workflow',
        'excel' => 'exports.excel.records',
    );
}

if(!isset($forms))
    $forms = array(
        'record'=>array()
    );

// $onLoad($workflow,$user,$record,$thisTask,$method)
if(!isset($onLoad))
    $onLoad = null;

// $onChange($workflow,$user,$changes,$old_record,$record,$thisTask)
if(!isset($onChange))
    $onChange = null;

// $onSave($workflow,$user,$record,$thisTask,$method)
if(!isset($onSave))
    $onSave = null;

$onSaveSearch = function($workflow,$user,$record,$task){
	$workflow->ctxt->setProperty('redirect_url.url',str_replace('&amp;', '&', $record->url->object.'&search_oid='.$record->oid->object));
	$workflow->ctxt->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);
};

if(!isset($showSearch))
    $showSearch = 'no';

$properties=array
(
    // ========================= CRUD APPLICATION ==================
    'application' => array
    (
        // application descriptor for role = magasin
        $main_role => array
        (
            'meta' => array
            (
                'description' => ('Edit items'),
                'strings' => $strings,

                // data descriptors
                'data'  => $datasources,

                // default display views
                'views' => $views,
                'icons'=>$icons,
                'forms' => $forms,

                // opÃ©rations pouvant Ãªtre appellÃ©es depuis la liste, pour chaque entrÃ©e
                'list_operations' => array('edit'=>array('nxo'=>$app_pre.'edit'),'delete'=>array('nxo'=>$app_pre.'delete','confirm'=>true)),

                // opÃ©rations par dÃ©faut
                'operation_init'=>$app_pre.'list',

                // default tasks executed for loading a state
                // 'state_loader'  => 'Workflow_StateLoader',
                'onload'  => array(),

                // tasks executed before executing an action : load submitted form
                'onBeforeAction'  => array(),

                'permissions' => $permissions
            ),

            // OPERATIONS DE L'APPLICATION
            'operations' => array(

                'list' => array(
                    'title' => 'list records',
                    'description' => ('List items'),

                    'tasks' => array(
                        'display_list'=>array(
                            'data'=>'list','search'=>'search','view'=>'list',
                            'showSearch'=>$showSearch,
                            'buttons'=>array('search'=>"?nxo={$app_pre}list")
                        )
                    ),

                    'actions'=>$listActions+array(
                            'add' => array('name'=>('add'),'nxo' => $app_pre.'add','id'  => 'content'),

                            'export_excel' => array(
                                'name'=>('export_excel'),
                                'nxo' => $app_pre.'export_excel',
                                'filterKey' => true
                            )
                        )
                ),

                'export_excel' => array(

                    'tasks' => array(
                        'display_list'=>array(
                            'data'=>'excel','search'=>'search',
                            'view'=>'excel','view_type'=>'XLS',
                        )
                    )
                ),


                'add' => array(
                    'title' => ('create record'),
                    'description' => ('Create record'),

                    'tasks' => array(
                        'display_record' => array('media'=>'empty','buttons'=>array('back'=>"?nxo={$app_pre}list"))
                    ),

                    'actions'=>array(
                        'save' => array('name'=>('save'), 'nxo' => $app_pre.'add_process','type'=>'submit')
                    )

                ),

                'add_process' => array(
                    'title' => ('process record'),
                    'description' => ('process record'),

                    'tasks' => array(
                        'save_record'=>array('media'=>'post','method'=>'insert',
                            'onLoad' => $onLoad, 'onChange' => $onChange,'onSave' => $onSave),
                        /*'redirect'=>array('url'=>"?nxo={$app_pre}list&mode=page"),*/
                    )
                ),
				
				'add_process_ajax' => array(
                    'title' => ('process record'),
                    'description' => ('process record'),

                    'tasks' => array(
                        'save_record'=>array('media'=>'post','method'=>'insert',
                            'onLoad' => $onLoad, 'onChange' => $onChange,'onSave' => $onSaveSearch),
                        /*'redirect'=>array('url'=>"?nxo={$app_pre}list&mode=page"),*/
                    )
                ),

                'edit' => array(
                    'title' => ('edit record'),
                    'description' => ('exec_workflow'),

                    'tasks' => array(
                        'display_record' => array('media'=>'db','buttons'=>array('back'=>"?nxo={$app_pre}list"))
                    ),

                    'actions'=>array
                    (
//						'save' => array('name'=>('save'), 'nxo' => $app_pre.'edit_process', 'id'=>'content'),
                        'save' => array('name'=>('save'), 'nxo' => $app_pre.'edit_process','type'=>'submit'),
                        'save_continue' => array('name'=>('save and continue'), 'nxo' => $app_pre.'edit_process2','type'=>'submit')
                    )
                ),

                'edit_process' => array(
                    'title' => ('process record'),
                    'description' => ('process record'),

                    'tasks' => array(
                        'save_record'=>array('media'=>'post','method'=>'update',
                            'onLoad' => $onLoad, 'onChange' => $onChange,'onSave' => $onSave),
                        'redirect'=>array('url'=>"?nxo={$app_pre}list&mode=page"),
                    )
                ),

                'edit_process2' => array(
                    'title' => ('process record'),
                    'description' => ('process record'),

                    'tasks' => array(
                        'save_record'=>array('media'=>'post','method'=>'update',
                            'onLoad' => $onLoad, 'onChange' => $onChange,'onSave' => $onSave),
                        'redirect'=>array('url'=>"?nxo={$app_pre}edit&mode=page&oid=".$_REQUEST['oid'].(isset($_REQUEST['tab'])?'&tab='.$_REQUEST['tab']:$taber)),
                    )
                ),

                'delete' => array(
                    'title' => ('delete record'),
                    'description' => ('delete record'),

                    'tasks' => array(
                        'delete_record',
                        'redirect'=>array('url'=>"?nxo={$app_pre}list&mode=ajax"),
                    )
                ),
				
				'delete_ajax' => array(
                    'title' => ('delete record'),
                    'description' => ('delete record'),

                    'tasks' => array(
                        'delete_record',
                    )
                ),
				
				'add_search_process' => array(
                    'title' => ('process record'),
                    'description' => ('process record'),

                    'tasks' => array(
                        'save_search_record'=>array('media'=>'post','method'=>'insert',
                            'onLoad' => $onLoad, 'onChange' => $onChange,'onSave' => $onSave),
                        'redirect'=>array('url'=>"?nxo={$app_pre}list&mode=page"),
                    )
                ),
				
				'get_search_ajax' => array(
                    'title' => ('Get search by oid'),
                    'description' => ('Get search by oid ajax'),

                    'tasks' => array(
                        'get_search_ajax'
                    )
                ),
            )
        )
    )
);
?>