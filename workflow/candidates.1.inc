<?php

$app_desc = $this->ctxt->getProperty('application.desc');

$icons = array(
	'add'=>'si-add',
	'edit'=>'si-page-white-edit',
	'delete'=>'si-delete',
	'save'=>'si-disk',
	'export_excel'=>'si-page-white-excel');

$strings   = $this->ctxt->getProperty('page.strings',$strings);
$datasources   = $this->ctxt->getProperty('app.datasources');
$forms   = $this->ctxt->getProperty('app.forms',array());
$nxo = $this->ctxt->getProperty('nxo','nxo');

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
					'search' => 'rct_candidate.search@recruitment',

					'fields' => array
					(
						'search' => array(
							'hide' => array('age'),
						)
					)
				),
			
				// default display views 
				'views' => array(
					'list' => 'workflow.xlist_search@workflow',
					'record' => 'workflow.xedit_generic@workflow',
				),

				'forms' => $forms,

				'icons'=>$icons,

				'list_operations' => array('edit'=>array($nxo=>'edit'),'delete'=>array($nxo=>'delete')),

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
						'list_candidates'=>array(
							'data'=>'list','search'=>'search','view'=>'list',
						//	'buttons'=>array('action'=>'?wao=action','add'=>'?wao=add')
						)
					),

					'actions'=>array(
						'add' => array('name'=>('add'),$nxo => 'add','id'  => 'content'),
						// 'export_excel' => array('name'=>('export_excel'),$nxo => 'export_excel')
					)					
				),

				'add' => array(
					'title' => ('Create record'),
					'description' => ('Create record'),

					'tasks' => array(
						'display_record' => array('media'=>'empty','buttons'=>array('back'=>'?wao=list'))
					),

					'actions'=>array(
						'submit' => array('name'=>('submit'), $nxo => 'add_process','id'  => 'content')
					)					

				),
			
				'add_process' => array(
					'title' => ('process record'),
					'description' => ('process record'),

					'tasks' => array(
						'save_record'=>array('media'=>'post','method'=>'insert'),
						'redirect'=>array('url'=>'?wao=list'),
					)
				),

				'edit' => array(
					'title' => ('edit record'),
					'description' => ('exec_workflow'),

					'tasks' => array(
						'display_record' => array('media'=>'db')
					),

					'actions'=>array
                    (
						// 'save' => array('name'=>('save'), $nxo => 'edit_save','id'  => 'content'),
						'submit' => array('name'=>'submit', $nxo => 'edit_process','id'  => 'content')
					)				
				),

				'edit_save' => array(
					'title' => ('process record'),
					'description' => ('process record'),

					'tasks' => array(
						'save_record'=>array('media'=>'post','method'=>'update'),
						'display_record' => array('media'=>'db')
					),
					'actions'=>array
                    (
						//'back' => array('name'=>('back'), $nxo => 'list', 'id'  => 'content'),
						'save' => array('name'=>('save'), $nxo => 'edit_save','id'  => 'content'),
						'submit' => array('name'=>('submit'), $nxo => 'edit_process','id'  => 'content')
					)				
				),

				'edit_process' => array(
					'title' => ('process record'),
					'description' => ('process record'),

					'tasks' => array(
						'save_record'=>array('media'=>'post','method'=>'update'),
						'redirect'=>array('url'=>'?wao=list'),
					)
				),

				'delete' => array(
					'title' => ('delete record'),
					'description' => ('delete record'),

					'tasks' => array(
						'delete_record',
						'redirect'=>array('url'=>'?wao=list'),
					)
				)
			)
		)
	)
);

?>