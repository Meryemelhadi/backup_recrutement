<?php

$app_desc = $this->ctxt->getProperty('application.desc');

//Permission DRH
$drh = "";
if($GLOBALS['_NX_user']->checkPerm('?-drh')) $drh = "-drh";

$icons = array(
	'add'=>'si-add',
	'add_interview'=>'si-add',
	'edit'=>'si-page-white-edit',
	'delete'=>'si-delete',
	'save'=>'si-disk',
	'export_excel'=>'si-page-white-excel',
	'xls_export'=>'si-page-white-excel');

//$strings   = $this->ctxt->getProperty('page.strings',$strings);
$strings = 'recruitment_vacancies_directory_admin@recruitment';
$datasources   = array(
	'vacancies_ws'=>'handler:rct_vacancy.pub_web_site@recruitment',
	'vacancies_app_ws'=>'rct_vacancy.pub_app@recruitment',
	'vacancies_app_compagnie'=>'rct_vacancy.pub_app_compagnie@recruitment',
	'list_interviews' => 'rct_interview.ds_calendar_list_realised@recruitment',
	'search_interview' => 'rct_interview.search'.$drh.'@recruitment',
	'excel_short_list' => 'recruitment.short_lists.candidates.excel@recruitment',
	'excel' => 'rct_vacancy.list_excel'.$drh,
	'search' => 'rct_vacancy.search@recruitment'
);

// $this->ctxt->getProperty('app.datasources');
$forms   = $this->ctxt->getProperty('app.forms',array());
$nxo = $this->ctxt->getProperty('nxo','nxo');

$defaultLogic = function($workflow,$user) {

	$ctxt = $workflow->ctxt;
	$logic = $ctxt->getProperty('page.logic');
	return $ctxt->runLogic($logic);
};

$this->ctxt->setProperty('app.form.css',<<<ECSS
	/* CSS RULES here */
	@import url("/nx/skins/default/css/recruitment/helptip.css");
	.marge_green{
	    border-left-style:solid;
	    border-left-width:20px;
		border-left-color: rgba(0,128,0,0.31);
	}
	.marge_orange{
        border-left-style:solid;
	    border-left-width:20px;
		border-left-color: rgba(255,165,0,0.36);
	}
	.marge_gray{
	    border-left-style:solid;
	    border-left-width:20px;
		border-left-color: rgba(128,128,128,0.34);
	}

ECSS
);

$this->ctxt->setProperty('app.form.js',<<<EJS
	/* js code */
	ajax_require('/nx/skins/default/js/recruitment/form_vacancy.js','recruitment');

EJS
);

$properties=array
(
	// ========================= CRUD APPLICATION ==================
	
	'application' => array
	(
		'admin' => array
		(
			'meta' => array
			(
				'name' => ('List title'),
				'description' => ('Edit items'),
				'strings' => $strings,

				// data descriptors
				'data'  => $datasources,
			
				// default display views 
				'views' => array(
					'list' => 'workflow.list_page@workflow',
					'record' => 'workflow.xedit_generic@workflow',
					'list_interviews' => 'recruitment.vacancies.components.list_interviews@recruitment',
					'list_interviews_vacancy' => 'recruitment.vacancies.components.list_interviews_vacancy@recruitment',
					'excel' => 'exports.excel.records'

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
			
			'operations' => array
			(
				'list' => array(
					'title'=>'',
					'tasks' => array(
						'vacancies_admin_list'
					)
				),
				'listbs' => array(
					'title'=>'',
					'tasks' => array(
						'vacancies_admin_list_bs'
					)
				),
                'add' => array
                (
                    'title' => '',
                    'description' => ('add'),

                    'tasks' => array(
                        'vacancy_add'
                    )
                ),
                'add_process' => array
                (
                    'title' => '',
                    'description' => ('add'),

                    'tasks' => array(
                        'vacancy_add_process'
                    )
                ),

				'edit' => array
				(
					'title' => '',
					'description' => ('edit'),

					'tasks' => array(
						'edit_vacancy'
					)
				),

				'edit_process' => array
				(
					'title' => '',
					'description' => ('edit'),

					'tasks' => array(
						'edit_process_vacancy',
						//'redirect'=>array('url'=>'?nxo=edit&void={request:void}&oid={request:void}&mode=ajax'),
					)
				),
				'delete' => array(
					'title' => ('delete record'),
					'description' => ('delete record'),

					'tasks' => array(
						'delete_vacancy',
					)
				),
				'archive' => array(
					'title' => ('archive record'),
					'description' => ('archive record'),

					'tasks' => array(
						'archive_vacancy',
					)
				),

				'add_interview_process' => array
				(
					'title' => '', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'add_interview_process'
					)
				),

				'add_email_process' => array(
					'title' => ('process record'),
					'description' => ('process record'),

					'tasks' => array(
						'save_record'=>array('media'=>'post','method'=>'insert', 'record_property'=>'page.record',
							'onSave' => function($workflow,$user,$record,$task,$method) { $workflow->record = $record; }),						
						'send_email',
						'redirect'=>array('url'=>'?nxo=emails:list&mode=ajax'),
					)
				),

                'send_to_ic_from_candidate' => array(
                    'title' => ('send_to_client_title'),
                    'description' => ('send_to_client_title'),

                    'tasks' => array(
                        'send_to_ic'=>array('previous_operation'=>'candidates@recruitment:edit&oid='.$_REQUEST['candidate_oid'].'&mode=ajax&tab=vacancies')
                    )
                ),
				
				'edit_integration_date' => array(
                    'title' => ('edit_integration_date_title'),
                    'description' => ('edit_integration_date_title'),

                    'tasks' => array(
                        'edit_integration_date'=>array('previous_operation'=>'candidates@recruitment:edit&oid='.$_REQUEST['candidate_oid'].'&mode=ajax&tab=vacancies')
                    )
                ),
				
				'edit_state' => array(
                    'title' => ('edit_state_title'),
                    'description' => ('edit_state_title'),

                    'tasks' => array(
                        'edit_state'=>array('previous_operation'=>'candidates@recruitment:edit&oid='.$_REQUEST['candidate_oid'].'&mode=ajax&tab=vacancies')
                    )
                ),
				
                'send_to_ic_process' => array(
                    'title' => ('send_to_ic_process'),
                    'description' => ('send_to_ic_process'),

                    'tasks' => array(
                        'send_to_ic_process'
                    )
                ),
				
				'edit_integration_date_process' => array(
                    'title' => ('edit_integration_date_process'),
                    'description' => ('edit_integration_date_process'),

                    'tasks' => array(
                        'edit_integration_date_process'
                    )
                ),
				
				'edit_state_process' => array(
                    'title' => ('edit_state_process'),
                    'description' => ('edit_state_process'),

                    'tasks' => array(
                        'edit_state_process'
                    )
                ),
				
				
                'handle_proposal_from_candidate' => array(
                    'title' => ('handle_proposal_from_candidate'),
                    'description' => ('handle_proposal_from_candidate'),

                    'tasks' => array(
                        'handle_proposal'=>array('previous_operation'=>'candidates@recruitment:edit&oid='.$_REQUEST['candidate_oid'].'&candidate_oid='.$_REQUEST['candidate_oid'].'&mode=ajax&tab=vacancies')
                    )
                ),
                'handle_proposal_process' => array(
                    'title' => ('handle_proposal_process'),
                    'description' => ('handle_proposal_process'),

                    'tasks' => array(
                        'handle_proposal_process'
                    )
                ),
                'change_candidate_status_from_candidate' => array(
                    'title' => ('change_candidate_status'),
                    'description' => ('change_candidate_status'),

                    'tasks' => array(
                        'change_candidate_status'=>array('previous_operation'=>'candidates@recruitment:edit&oid='.$_REQUEST['candidate_oid'].'&mode=ajax&tab=vacancies')
                    )
                ),
				'change_candidate_status' => array(
                    'title' => ('change_candidate_status'),
                    'description' => ('change_candidate_status'),

                    'tasks' => array(
                        'change_candidate_status'
                    )
                ),
				
                'unlink_candidate_from_candidate' => array(
                    'title' => ('unlink_candidate'),
                    'description' => ('unlink_candidate'),

                    'tasks' => array(
                        'unlink_candidate'=>array('previous_operation'=>'candidates@recruitment:edit&oid='.$_REQUEST['candidate_oid'].'&mode=ajax&tab=vacancies')
                    )
                ),
				
				'unlink_from_all_from_candidate' => array(
                    'title' => ('unlink_candidate'),
                    'description' => ('unlink_candidate'),

                    'tasks' => array(
                        'unlink_from_all'=>array('previous_operation'=>'candidates@recruitment:edit&oid='.$_REQUEST['candidate_oid'].'&mode=ajax&tab=vacancies')
                    )
                ),
				
				
                'associated_candidate_poste'=> array(
                    'title' => ('associated_candidate'),
                    'description' => ('associated_candidate'),

                    'tasks' => array(
                        'associated_candidate_poste'
                    )
                ),
				'associated_candidate'=> array(
                    'title' => ('associated_candidate'),
                    'description' => ('associated_candidate'),

                    'tasks' => array(
                        'associated_candidate'
                    )
                ),
				
				'add_email' => array
				(
					'title' => 'add email', 
					'description' => ('Add email'),

					'tasks' => array(
						'add_email'
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
					
						/*'xls_export' => array(
							'name'=>('export_excel'),
							'nxo' => 'interview@recruitment:export_excel',
							'filterKey' => false
							)*/
					)					
				),
				'calendar' => array(
					'title' => 'page_title_calendar', 
					'description' => ('page_title_calendar'),
					'tasks' => array(
						'calendar'
					)				
				),
				'calendar_vacancy' => array(
                    'title' => 'page_title_vacancy_interviews',
                    'description' => ('List interview vacancy'),
                    'list_operations' => array('add'=>array('nxo'=>'add_interview&nxs=&oid='.$_REQUEST['oid'].'&mode=ajax')),
                    'tasks' => array(
                        'list_interview_calendar'=>array(
                            'data'=>'list_interviews','view'=>'list_interviews_vacancy'
                        )
                    ),
                    'actions'=>array(
						'add_interview'  => array(
							'name'=>('add_interview'),
                            'nxo' => 'add_interview&oid='.$_REQUEST['oid'].'&void='.$_REQUEST['oid']
						)
                        /*'xls_export' => array(
                            'name'=>('export_excel'),
                            'nxo' => 'interview@recruitment:export_excel',
                            'filterKey' => false
                            )*/
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
				'shorts_list' => array
				(
					'title' => 'Shorts list', 
					'description' => ('Shorts list'),

					'tasks' => array(
						'shorts_list'
					)
				),
				'candidate_add_interview' => array(
					'tasks' => array(
                        'candidate_add_interview'
                    )
				),
				'candidates' => array(
					'tasks' => array(
                        'candidates'
                    )
				),
				'xls_export_short_list' => array(

                    'tasks' => array(
                        'display_list'=>array(
                            'data'=>'excel_short_list','search'=>'excel_short_list',
                            'view'=>'excel','view_type'=>'XLS',
                        )
                    )
                ),
				'export_excel' => array(

                    'tasks' => array(
                        'display_list'=>array(
                            'data'=>'excel','search'=>'search',
                            'view'=>'excel','view_type'=>'XLS', 'file.name'=>'postes.xls'
                        )
                    )
                ),
				'add_attached_files_vacancy' => array
                (
                    'title' => 'Add attached files',
                    'description' => ('Add attached files'),

                    'tasks' => array(
                        'add_attached_files_vacancy',
                    )
                ),
				
				/*'preview' => array(
					'title' => 'preview cv', 
					'description' => ('Preview CV'),

					'tasks' => array(
						'preview'
					),

				),*/

				'ws' => array
				(
					'title' => 'list records', 
					'description' => ('List items'),
					'permissions' => '',

					'tasks' => array(
						'display_list_ws@workflow'=>array(
							'data'=>'vacancies_ws','search'=>'search','view'=>'list'
						)
					),

					'actions'=>array()					
				),
				
				'ws_app' => array
				(
					'title' => 'list records', 
					'description' => ('List items'),
					'permissions' => '',

					'tasks' => array(
						'display_list_vacancies_ws'=>array(
							'data'=>'vacancies_app_ws','search'=>'search','view'=>'list'
						)
					),

					'actions'=>array()					
				),
				'ws_rss' => array
				(
					'title' => 'list records rss', 
					'description' => ('List items'),
					'permissions' => '',

					'tasks' => array(
						'display_vacancies_rss'
					),

					'actions'=>array()					
				),

				// default operation
				'default' => array(
					'title' => (''),
					'description' => (''),

					'tasks' => array(
						$defaultLogic
					)
				)
			)
		)
	)
);

?>