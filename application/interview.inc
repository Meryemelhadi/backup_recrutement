<?php

$app_desc = $this->ctxt->getProperty('application.desc');

//Permission DRH
$drh = "";
if($GLOBALS['_NX_user']->checkPerm('?-drh')) $drh = "-drh";
		
$icons = array(
	'add'=>'si-add',
	'edit'=>'si-page-white-edit',
	'delete'=>'si-delete',
	'save'=>'si-disk',
	'export_excel'=>'si-page-white-excel');

// strings name
$strings = 'recruitment_vacancies_directory_admin@recruitment';
$datasources   = array(
	'list' => 'rct_interview.ds_calendar_list@recruitment',
	'search_interview' => 'rct_interview.search'.$drh.'@recruitment',
	'excel'    => 'rct_interview.ds_calendar_list@recruitment', 
	'list_interviews' => 'rct_interview.ds_calendar_list_realised@recruitment',
	'search' => 'rct_candidate.search@recruitment',
	'fields' => array
	(
		'search' => array(
			'hide' => array('age'),
		)
	)
);
$forms   = $this->ctxt->getProperty('app.forms',array());
$nxo = $this->ctxt->getProperty('nxo','nxo');

$this->ctxt->setProperty('app.form.js',<<<EJS
	/* js code */
	ajax_require('/nx/skins/default/js/recruitment/form_interview.js','recruitment');
EJS
);
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
				// data descriptors
				'data'  => $datasources,
			
				// default display views 
				'views' => array(
					'list' => 'workflow.xlist_search@workflow',
					'record' => 'workflow.xedit_generic@workflow',
					'excel' => 'exports.excel.records',
					'list_interviews' => 'recruitment.vacancies.components.list_interviews@recruitment'
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

				'list' => array(
					'title' => 'page_title_my_interviews', 
					'description' => ('List interview'),
					'list_operations' => array('edit'=>array('nxo'=>'interview@recruitment:edit_interview&operation=my_calendar&mode=page' , 'type'=>'link' )),
					'tasks' => array(
						'list_interviews'=>array(
							'data'=>'list_interviews','view'=>'list_interviews'
						)
					),
					'actions'=>array(
					)					
				),
				'add_interview' => array
				(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'add_interview'
					)
				),
				
				'add_interview_process' => array
				(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'add_interview_process'
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

				'edit_interview' => array
				(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'edit_interview'
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
				),
				
				'edit_interview_process' => array
				(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'edit_interview_process'
					)
				),

				'interview@recruitment:edit_interview_cancel' => array
				(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'edit_interview_cancel'
					)
				),
				'interview@recruitment:export_excel' => array(
                    'tasks' => array(
                        'display_list@workflow'=>array(
                            'data'=>'excel','search'=>'search_interview',
                            'view'=>'excel','view_type'=>'XLS',
                        )
                    )
                ),
				'list_by_interviewer' => array(
                    'tasks' => array(
                        'list_by_interviewer'
                    )
                ),
				'delete_interview' => array
				(
					'title' => 'Delete candidate', 
					'description' => ('delete candidate'),

					'tasks' => array(
						'edit_interview_cancel',
						'delete_interview'
					)
				),
				'my_calendar' => array(
					'title' => 'page_title_my_interviews', 
					'description' => ('List interview'),
					'list_operations' => array('edit'=>array('nxo'=>'interview@recruitment:edit_interview&operation=my_calendar&mode=page' , 'type'=>'link' )),
					'tasks' => array(
						'list_interviews'=>array(
							'data'=>'list_interviews','view'=>'list_interviews'
						)
					),
					'actions'=>array(
					)					
				),
				'preview' => array(
					'title' => 'preview cv', 
					'description' => ('Preview CV'),

					'tasks' => array(
						'preview'
					),

				),
				'get_email_sample' => array(
					'title' => 'get email sample', 
					'description' => ('Get Email Sample'),

					'tasks' => array(
						'get_email_sample'
					),

				),

			)
		)
	)
);

?>