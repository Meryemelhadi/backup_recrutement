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

				'list_operations' => array('edit'=>array('nxo'=>'candidates@recruitment:edit'),'delete'=>array('nxo'=>'candidates@recruitment:delete')),

				'operation_init'=>'candidates@recruitment:list',

				// default tasks executed for loading a state
				// 'state_loader'  => 'Workflow_StateLoader',
				'onload'  => array(),

				// tasks executed before executing an action : load submitted form
				'onBeforeAction'  => array(),

				// default tasks executed after executing an action
				// 'onAfterAction'  => array( 'tasks' => array('log')),
			),
			
			'operations' => array(

				'interview@recruitment:add_interview' => array
				(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'add_interview'
					)
				),

				'interview@recruitment:add_interview_process' => array
				(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'add_interview_process'
					)
				),

				'interview@recruitment:edit_interview' => array
				(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'edit_interview'
					)
				),

				'interview@recruitment:edit_interview_process' => array
				(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'edit_interview_process'
					)
				)

			)
		)
	)
);

?>