<?php

$icons = array(
	'add'=>'si-add',
	'edit'=>'si-page-white-edit',
	'delete'=>'si-delete',
	'save'=>'si-disk',
	'export_excel'=>'si-page-white-excel');

$forms   = array();
$strings = 'recruitment_vacancies_directory_admin@recruitment';
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

				'uid' => 'vacancy_shortlists@recruitment',

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

				'list_operations' => array('edit'=>array('nxo'=>'candidates@recruitment:edit')),

				'operation_init'=>'vacancy_shortlists@recruitment:candidates',

				// default tasks executed for loading a state
				// 'state_loader'  => 'Workflow_StateLoader',
				'onload'  => array(),

				// tasks executed before executing an action : load submitted form
				'onBeforeAction'  => array(),

				// default tasks executed after executing an action
				// 'onAfterAction'  => array( 'tasks' => array('log')),
			),
			
			'operations' => array(

				'vacancy_shortlists@recruitment:candidates' => array
				(
					'title' => '', // ('List items'),
					'description' => (''),

					'tasks' => array(
						'shortlist_candidates'
					)
				),

				'vacancy_shortlists@recruitment:list_by_state' => array
				(
					'title' => '', // ('List items'),
					'description' => (''),

					'tasks' => array(
						'shortlist_candidates_by_state'
					)
				),
			)
		)
	)
);

?>