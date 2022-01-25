
			<?php $_nx_content_stack[]="page.content";	ob_start(); ?>
				
		
		<?php ob_start(); ?>

			<?php 
		$workflow = $this->getProperty('workflow');
		?>
<script type="text/javascript" language="Javascript">
//<![CDATA[

		if (window.container)
			window.container.setAppTitle("");
		
//]]>
</script>
<div class="pm-page-title-wrapper">
	<div class="pm-page-title-inner-wrapper">
		<div id="page_title" class="pm-title">
			<div class="title_tb" style="float:right"></div></div></div></div><style type="text/css">
            {=app.form.css}
			#field_technical_qualifications .control-label, #field_behavioral_qualifications .control-label{
				width:200px;
			}
			#field_companies_having_same_profile{
				margin-bottom: 24px;
			}
			#field_suited_recruitment_date{
				display:none;
			}
            #requirements_div .control-label-wrapper{
                width:35% !important;
            }
            #groups_user_total_control_1 , .control_lists_filter td, #filter_val_groups_user_total_control, #filter_val_groups_user_readonly, #groups_user_total_control_2, #groups_user_readonly_1, #groups_user_readonly_2{
                width: 170px !important;
                font-size: 11px !important;
            }
        </style>
		<script type="text/javascript" language="Javascript">
//<![CDATA[

            {=app.form.js}
        
//]]>
</script><?php 

	echo $this->getProperty('log.warn',$_SESSION['log.warn']);
	echo $this->getProperty('log.errors',$_SESSION['log.errors']);
	echo $this->getProperty('log.ok',$_SESSION['log.ok']);

	if(defined('KEEP_SESSION') && KEEP_SESSION==false)
		session_start();

	if(isset($_SESSION['log.warn']))
		unset($_SESSION['log.warn']);

	if(isset($_SESSION['log.errors']))
		unset($_SESSION['log.errors']);

	if(isset($_SESSION['log.ok']))
		unset($_SESSION['log.ok']);

?><?php 
$msgHelp = $this->getProperty('msg.help');
if($msgHelp)
{
?><div id="help" class="help"><div class="message">{var:msgHelp}</div></div><?php 
}?>



        <?php $_nx_content_stack[]="comments";	ob_start(); ?>
            <div class="pm-bxm-box-content"><div class="comments-wrapper" id="comments-wrapper">
    {records:comments.records}
        {record}
            <div class="comment-wrapper"><div class="comment"><span class="comment_author">{field:user_oid}</span>: {field:comment}</div><div class="comment_date">{field:date}</div></div>
        {/record}
    {/records}
    </div><div class="add-comment-wrapper"><div class="add-comment"><div class="add-comment-inner"><textarea rows="3" cols="30" name="add_comment_zone" type="text" class="text"></textarea></div></div><div class="add-comment-process clear-both"><a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="Generis.Recruitment.addComment(this, 'add_comment_zone', '{=add_comment.url}'); this.blur(); return false;"><span class="btn-bg"><span class="s-icon si-comment-add">{string:"post_comment"}</span></span></a><div style="display: none;" id="vacancy-button-loader"></div></div></div></div>

        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="accepted_proposals";	ob_start(); ?>
            {records:accepted_proposals.records}
                {record}
                    <div class="vacancy-meta-entry"><strong>{field:full_name}</strong> {string:"date_prefix_lc"} {field:proposal_acceptance_date}</div>
                {/record}
            {/records}
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="selected_candidates";	ob_start(); ?>
            {records:selected_candidates.records}
	{if:records.count>0}
	<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'selected_candidates'}</h3></div>
		<div class="pm-bxm-box-content">
			<div class="table-list-wrapper">
				<table class="table-list">
			
				{record}
				
					<tr>
						<td class="entry"><strong>{field:full_name}</strong><br/>
							<script type="text/javascript" language="Javascript">
//<![CDATA[

							window.dlg_change_contrat_signingCfg{record.index} = { title:"{string:'change_contrat_signing_title'}", url: "{=change_contrat_signing.url}{record.url_key}", width:550 };

							window.dlg_change_integration_planCfg{record.index} = { title:"{string:'change_integration_plan_title'}", url: "{=change_integration_plan.url}{record.url_key}", width:550 };

							window.dlg_change_integration_noteCfg{record.index} = { title:"{string:'change_integration_note_title'}", url: "{=change_integration_note.url}{record.url_key}", width:550 };

							window.dlg_change_hire_dateCfg{record.index} = { title:"{string:'change_hire_date_title'}", url: "{=change_hire_date.url}{record.url_key}", width:550 };
						
//]]>
</script>
							<u>{field.label:contrat_signing}
							</u>: <strong>{field:contrat_signing}</strong> (
							<a onclick="PMModalbox.loadFromUrl(window.dlg_change_contrat_signingCfg{record.index}, event); return false;" href="javascript:void(0);">
								<span>{string:"change_data"}</span></a>)
						
<br/>
							<u>{field.label:hire_date}
							</u>: <strong>{if:#field.object:hire_date_raw#!=''}{field:hire_date}{else}{string:"empty_hire_date"}{/if}</strong> (
							<a onclick="PMModalbox.loadFromUrl(window.dlg_change_hire_dateCfg{record.index}, event); return false;" href="javascript:void(0);">
								<span>{string:"change_data"}</span></a>)
						
<br/>
							<u>{field.label:integration_plan}
							</u>: <strong>{field:integration_plan}</strong> (
							<a onclick="PMModalbox.loadFromUrl(window.dlg_change_integration_planCfg{record.index}, event); return false;" href="javascript:void(0);">
								<span>{string:"change_data"}</span></a>)
						
<br/>
							<u>{field.label:integration_note}
							</u>: <strong>{field:integration_note}</strong> (
							<a onclick="PMModalbox.loadFromUrl(window.dlg_change_integration_noteCfg{record.index}, event); return false;" href="javascript:void(0);">
								<span>{string:"change_data"}</span></a>)
						
<br/></td>
					</tr>
				{/record}
		   
			
				</table></div></div>
	{/if} 
 {/records}





        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="email_field";	ob_start(); ?>
            
		<div class="control-main-wrapper">
			<div class="control-label-wrapper">
				<div class="control-label">Email du poste</div></div>
			<div class="control-wrapper">
        <?php
        $oid = $_nx_record->oid->object;

        $channelOid = $_nx_record->cand_channel->object;
        if($channelOid && $channelOid!='?')
        $suffix = str_pad($channelOid, 2, '0', STR_PAD_LEFT);
        else
        $suffix='';

        $code_client = $this->getProperty('recruitment.code_client');
        if(!$code_client)
        {
        $a = explode('.',strtolower($_SERVER['SERVER_NAME']));
        if($a[1]=='presencesoft'||$a[1]=='presencerecrute')
        // editialis.presencerecrute.com
        $code_client = $a[0];
        else
        // xx.editialis.fr
        $code_client = $a[1];
        }

        if($code_client)
        {
        $year = '15';
        $oidpad = str_pad($oid, 3, '0', STR_PAD_LEFT);
        $check = ($year * $oid)%100;
        $email = $code_client.'_'.$year.$oidpad.$check.$suffix.'@pourcandidature.com';
        }
        else
        $email = '';

        ?>
        
				<div class="control width-66">{var:email}</div></div></div>
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="buttons";	ob_start(); ?>
        
		<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="PMFormSubmit.submit(this, dlg_submitConfig, dlg_successConfig, dlg_failureConfig); this.blur(); return false;">
			<span class="btn-bg">
				<span class="s-icon si-disk">{string:"submit"}</span></span></a>
		<span class="pm-button-sep"></span>
		<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="PMModalbox.display(dlg_deleteConfig{record.index}, event);">
			<span class="btn-bg">
				<span class="s-icon si-delete">{string:"dlg_delete_definitly"}</span></span></a>
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="vacancy_dashboard";	ob_start(); ?>
            
		<div class="pm-bxm-box-content">
			<div class="table-list-wrapper">
				<table class="table-list">
					<tr>
						<td class="entry">{string:"title_delay_open_close"}: <strong>{field.html:delay_between_open_and_close}</strong> {string:"days"}</td>
					</tr>
					<tr>
						<td class="entry">{string:"title_delay_close_office_taking"}: <strong>{field.html:delay_between_close_and_taking_office}</strong> {string:"days"}</td>
					</tr>
					<tr>
						<td class="entry">{string:"title_instant_feedback"}: <strong>{=instant_feedback_count}</strong></td>
					</tr>
					<tr>
						<td class="entry">{string:"title_delayed_feedback"}: <strong>{=delayed_feedback_count}</strong></td>
					</tr>
				</table></div></div>
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
        <?php $_nx_content_stack[]="attached_files";	ob_start(); ?>
            

		<div class="pm-bxm-box-content" id="associated-files">
			<table class="associated-files">
{records:attached_files.records}
	{record}

    
				<tr id="row-file-{field:oid}">
					<td class="label">
						<a href="{=download.url}{record.url_key}">{field.html:file_name}</a></td>
					<td class="operations">
						<a class="s-icon si-page-white-put" href="{=download.url}{record.url_key}" alt="{string:">
							<span>{string:"action_download"}</span></a>
						<a class="s-icon si-delete af-delete-action" href="javascript:void(0);" alt="{string:">
							<span>{string:"action_delete"}</span></a>
<input type="checkbox" value="{field:oid}" id="checkbox-file-{field:oid}" name="files_to_delete[]"/></td>
				</tr>
				<tr id="deleted-row-file-{field:oid}" style="display:none">
					<td colspan="2" class="deleted">{field.html:file_name} {string:"deleted"},
            
						<a href="javascript:void(0);" objectoid="{field:oid}" class="action s-icon si-arrow-rotate-clockwise af-restore-action">
							<span>{string:"action_restore"}</span></a></td>
				</tr>

	{/record}
{/records}

			</table>
			<div class="add-file-wrapper">
				<div class="add-file-title">
					<a href="javascript:void(0);" class="action s-icon si-add af-add-action">
						<span>{string:"action_add_file"}</span></a></div></div>
			<script type="text/javascript" language="Javascript">
//<![CDATA[

		Generis.Recruitment.appendAssocFilesHandlers('associated-files');
	
//]]>
</script></div>

        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        
	<div id="content_form" class="pm-bxm-wrapper">
		{form:page.record}
		
		<script language="javascript" type="text/javascript">
//<![CDATA[

			window.autoSaveDesc = null;
			window.content_form = document.getElementById('{=submit.id}');
			window.currentForm = document.getElementById('{=submit.id}');
			if(window.currentForm)
				window.currentForm.handler = window.content_form_handler = new window.Generis.Forms(window.currentForm);
		
//]]>
</script>
		<table class="pm-bxm">
			<tr>
			<?php $_nx_content_stack[]="field_state_with_help";	ob_start(); ?>
				
			<div id="field_current_step" class="control-main-wrapper ">
				<div class="control-label-wrapper" style="position:relative">
					<div class="control-label">{field.label:current_step}</div>
					<div class="help-tip">
						<p>Les différentes états de recrutement:
<br/>
					1 - En cours
<br/>
					2 - Suspendu 
<br/>
					3 - Clôturé 
<br/>
					4 - En brief 
<br/></p></div></div>
				<div class="control-wrapper" id="current_step-control-wrapper">
					<div class="control" id="current_step-control">
			{field:current_step}
		</div></div></div>
			<div id="field_progress_level" class="control-main-wrapper ">
				<div class="control-label-wrapper" style="position:relative">
					<div class="control-label">{field.label:progress_level}</div>
					<div class="help-tip">
						<p>Les différentes phases de recrutement:
<br/>
					1 - Poste ouvert
<br/>
					2 - Validation de la demande d'ouverture 
<br/>
					3 - Sollicitation de cabinets de recrutement 
<br/>
					4 - Association de CV au poste 
<br/>
					5 - Envoi de candidats aux clients internes 
<br/>
					6 - Envoi de short-list aux clients internes 
<br/>
					7 - Planification d'entretiens 
<br/>
					8 - Acceptation de proposition 
<br/>
					9 - Refus de proposition 
<br/>
					10- Candidat(s) retenu(s) pour le poste 
<br/> 
					11- Sélection de candidat(s) annulée 
<br/>
					12- Proposition(s) envoyée(s) 
			</p></div></div>
				<div class="control-wrapper" id="progress_level-control-wrapper">
					<div class="control" id="progress_level-control">
			{field:progress_level}
		</div></div></div>
			<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
            <?php $_nx_content_stack[]="field_closing_date_with_help";	ob_start(); ?>
                
			<div id="field_closing_date" class="control-main-wrapper ">
				<div class="control-label-wrapper" style="position:relative">
					<div class="control-label">Clôture :</div>
					<div class="help-tip">
						<p>Date de fermeture du poste</p></div></div>
				<div class="control-wrapper" id="closing_date-control-wrapper">
					<div class="control" id="closing_date-control">
						<div class="datepicker_wrapper" style="position: relative;">
<input id="closing_date_5" name="closing_date" style="width:auto;padding-right:0;" value="" xclass="datetimepicker date" xreadonly="readonly"/><img style="position: relative; left: -19px; top: 1px;" class="inputExtension" title="Ouvrir le calendrier" src="/nx/controls/datepicker/images/calendar.png"/>
								<script type="text/javascript" language="Javascript">
//<![CDATA[

				if (((typeof DateFormat == "undefined") || (typeof DateFormat.parseFormat == "undefined")) && (typeof ajax_require != "undefined"))
				{
					ajax_require("/nx/controls/datepicker/prototype-date-extensions.js","prototype-date-extensions");
				}
				if (((typeof Control == "undefined") || (typeof Control.DatePicker == "undefined")) && (typeof ajax_require != "undefined"))
				{
					ajax_require("/nx/controls/datepicker/datepicker.js","datepicker");
				}

				if (typeof ajax_require != "undefined")
				{
					ajax_onload(function(){ajax_onload(function(){
						try {
							new window.Control.DatePicker(document.getElementById('closing_date_5'), { icon: '/nx/controls/datepicker/images/calendar.png', locale:'fr_FR', timePicker:false, timePickerAdjacent: false, use24hrs: true });
						} catch(e) {
							if(console && console.log) console.log('cant find date element closing_date_5');
						}

					},"datepicker")},"prototype-date-extensions");
				}
			
//]]>
</script></div></div></div></div>
            <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
            <?php $_nx_content_stack[]="vacancy_permission";	ob_start(); ?>
                
			<div style="display: block;" id="help" class="help">
				<div style="display: block;" id="permission_help" class="tab-help">{string:'permission_help'}</div></div>
			<div class="pm-bxm-box-content">
				<div class="pm-bx-form">
					<div class="columns-layout clear-both">
						<div class="column-1">
							<div id="group_1" class="form-group">
								<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:"total_control"}</h3></div>
								<div class="record_wrapper">
									<div class="record">
										<div id="field_creator" class="control-main-wrapper ">
											<div class="control-label-wrapper">
												<div class="control-label">{field.label:creator}</div></div>
											<div class="control-wrapper" id="creator-control-wrapper">
												<div class="control" id="creator-control">
                                        {field:creator}
                                    </div></div></div>
										<div id="field_creator" class="control-main-wrapper ">
											<div class="control-label-wrapper">
												<div class="control-label">{field.label:manager_oid}</div></div>
											<div class="control-wrapper" id="creator-control-wrapper">
												<div class="control" id="creator-control">
                                        {field:manager_oid}
                                    </div></div></div>
										<div class="control-main-wrapper">
											<div class="control-label-wrapper">
												<div class="control-label">{string:"readOnly"}</div></div>
											<div style="float:left;width:100%">
                                    {if:(#field.object:creator# == #user:oid#) || (#field.object:manager_oid# == #user:oid#)}
                                    
												<div class="control">{field:groups_user_total_control}</div>
                                    {else}
                                    
												<div class="control">{field.html:groups_user_total_control}</div>
												<div class="control" style="display:none">{field:groups_user_total_control}</div>
                                    {/if}
                                </div></div></div></div></div></div>
						<div class="column-2">
							<div id="group_2" class="form-group">
								<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:"title_readonly"}</h3></div>
								<div class="record_wrapper">
									<div class="record">
										<div class="control-main-wrapper">
											<div class="control-label-wrapper">
												<div class="control-label">{string:"readOnly"}</div></div>
											<div style="float:left;width:100%">
                                    {if:(#field.object:creator# == #user:oid#) || (#field.object:manager_oid# == #user:oid#)}
                                    
												<div class="control">{field:groups_user_readonly}</div>
                                    {else}
                                    
												<div class="control">{field.html:groups_user_readonly}</div>
												<div class="control" style="display:none">{field:groups_user_readonly}</div>
                                    {/if}
                                </div></div></div></div></div></div></div></div></div>
            <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
            
			<script type="text/javascript" language="Javascript">
//<![CDATA[

                window.debugme = 2;

                window.dlg_backConfig = { title : "{string:'dlg_back_title'}", message : "{string:'dlg_back_content'}", viewMode : "okCancel", url : "{=back_list.url}", target : "content", labels : { ok : "{string:'dlg_ok'}", cancel : "{string:'dlg_cancel'}" } };

                window.dlg_submitConfig = { title : "{string:'dlg_wait_title'}", message : "{string:'dlg_wait_content'}", viewMode : "wait" };

                window.dlg_successConfig = { title : "{string:'dlg_success_title'}", message : "{string:'dlg_success_content'}", viewMode : "ok", url : "{=submit.url}", target : "content", labels : { ok : "{string:'dlg_success'}" } };

                window.dlg_failureConfig = { title : "{string:'dlg_failure_title'}", message : "{string:'dlg_failure_content'}", viewMode : "cancel", target : "content", labels : { cancel : "{string:'dlg_cancel'}" } };
				
				window.dlg_deleteConfig{record.index} = {
                                                title : "{string:'dlg_delete_title'}",
                                                message : "{string:'dlg_delete_content'}",
                                                viewMode : "okCancel",
                                                url : "{=delete.url}{record.url_key}",
                                                target : "content",
                                                labels : {
                                                    ok : "{string:'dlg_ok'}",
                                                    cancel : "{string:'dlg_cancel'}"
                                            } };
            
//]]>
</script>
		<td class="pm-bxm-main-column">
			<div class="form-actions-wrapper">
				<div class="pm-button-wrapper clear-both pm-bxm-top-button-wrapper">
                    {=buttons}
                </div></div>
			<script language="javascript" type="text/javascript">
//<![CDATA[

			window.taber = new window.Generis.Tabs();
		
//]]>
</script><?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','informations'));
				if($firstTab != 'informations')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='current';
			}
			else
			{
				$displayMode = 'display:none;';
				$classNav='';
			}
		?>

		<?php $_nx_content_stack[]="tabs_help";	ob_start(); ?>
			{=tabs_help}
			
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_nav";	ob_start(); ?>
			{=tabs_nav}
			<li id="informations" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('informations','informations_div')"><b>{string:'title_vacancy_fiche'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="informations_div" class="tab">
						<div id="panel_" class="pm-bxm-box-wrapper pm-bxm-box-wrapper-panel">
							<div class="pm-bxm-box">
									<div class="box-title-wrapper box-title-red">
										<div class="box-title"><h3>{string:'title_vacancy_fiche'}</h3></div></div>
								<div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-">
							<div class="columns-layout clear-both">
								<div class="column-1">
									<div id="group_1" class="form-group">
										<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'general_infos'}</h3></div>
										<div class="pm-bx-form">
											<div class="record_wrapper">
												<div class="record">{get_field:name}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:name}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:name}</div></div></div>{get_field:code}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:code}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:code}</div></div></div>{get_field:number}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:number}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:number}</div></div></div>{get_field:opening_date}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:opening_date}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:opening_date}</div></div></div>
                                            {=field_state_with_help}
                                        </div></div></div></div>
									<div id="group_2" class="form-group">
										<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'title_contract'}</h3></div>
										<div class="pm-bx-form">
											<div class="record_wrapper">
												<div class="record">{get_field:contract_type_oid}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:contract_type_oid}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:contract_type_oid}</div></div></div>{get_field:category_oid}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:category_oid}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:category_oid}</div></div></div>{get_field:mission_start_date}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:mission_start_date}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:mission_start_date}</div></div></div>
                                            {=field_closing_date_with_help}
                                            {get_field:suited_recruitment_date}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:suited_recruitment_date}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:suited_recruitment_date}</div></div></div>{get_field:taking_office_date}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:taking_office_date}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:taking_office_date}</div></div></div></div></div></div></div>
									<div id="group_3" class="form-group">
										<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'title_classement_poste'}</h3></div>
										<div class="pm-bx-form">
											<div class="record_wrapper">
												<div class="record">{get_field:application_type}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:application_type}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:application_type}</div></div></div>{get_field:archive_state}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:archive_state}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:archive_state}</div></div></div></div></div></div></div>
										<div id="stage_group" style="display:none">
										<div id="group_1" class="form-group">
											<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'title_internship_section'}</h3></div>
											<div class="pm-bx-form">
												<div class="record_wrapper">
													<div class="record">{get_field:internship_title}{/get_field}
													<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
															<div class="control-label-wrapper">
																<div class="control-label">{field.label:internship_title}{if:field.isRequired}
																	<span class="required-field">*</span>{/if} :</div></div>
														<div class="control-wrapper" id="{field.name}-control-wrapper">
															<div class="control" id="{field.name}-control">{field:internship_title}</div></div></div>{get_field:internship_start}{/get_field}
													<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
															<div class="control-label-wrapper">
																<div class="control-label">{field.label:internship_start}{if:field.isRequired}
																	<span class="required-field">*</span>{/if} :</div></div>
														<div class="control-wrapper" id="{field.name}-control-wrapper">
															<div class="control" id="{field.name}-control">{field:internship_start}</div></div></div>{get_field:internship_end}{/get_field}
													<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
															<div class="control-label-wrapper">
																<div class="control-label">{field.label:internship_end}{if:field.isRequired}
																	<span class="required-field">*</span>{/if} :</div></div>
														<div class="control-wrapper" id="{field.name}-control-wrapper">
															<div class="control" id="{field.name}-control">{field:internship_end}</div></div></div>{get_field:executive_committee_presentation}{/get_field}
													<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
															<div class="control-label-wrapper">
																<div class="control-label">{field.label:executive_committee_presentation}{if:field.isRequired}
																	<span class="required-field">*</span>{/if} :</div></div>
														<div class="control-wrapper" id="{field.name}-control-wrapper">
															<div class="control" id="{field.name}-control">{field:executive_committee_presentation}</div></div></div></div></div></div></div></div></div>
								<div class="column-1">
									<div id="group_1" class="form-group">
										<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'title_manage_recruitment'}</h3></div>
										<div class="pm-bx-form">
											<div class="record_wrapper">
												<div class="record">{get_field:manager_oid}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:manager_oid}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:manager_oid}</div></div></div>{get_field:cand_channel}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:cand_channel}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:cand_channel}</div></div></div>
                                            {=email_field}
                                        </div></div></div></div>
									<div id="group_2" class="form-group">
										<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'title_poste_affectation'}</h3></div>
										<div class="pm-bx-form">
											<div class="record_wrapper">
												<div class="record">{get_field:client_oid}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:client_oid}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:client_oid}</div></div></div>{get_field:subsidiary_oid}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:subsidiary_oid}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:subsidiary_oid}</div></div></div>{get_field:establishment}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:establishment}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:establishment}</div></div></div>{get_field:pole}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:pole}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:pole}</div></div></div>{get_field:direction}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:direction}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:direction}</div></div></div>{get_field:service_oid}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:service_oid}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:service_oid}</div></div></div>{get_field:duty_station_oid}{/get_field}
												<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper">
															<div class="control-label">{field.label:duty_station_oid}{if:field.isRequired}
																<span class="required-field">*</span>{/if} :</div></div>
													<div class="control-wrapper" id="{field.name}-control-wrapper">
														<div class="control" id="{field.name}-control">{field:duty_station_oid}</div></div></div></div></div></div></div>
									<div id="group_3" class="form-group">
										<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'title_vacancy_dashboard'}</h3></div>
										<div class="pm-bx-form">
											<div class="record_wrapper">
												<div class="record">
                                            {=vacancy_dashboard}
                                        </div></div></div></div>
                                        {=selected_candidates}

                                    </div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','permission'));
				if($firstTab != 'permission')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='current';
			}
			else
			{
				$displayMode = 'display:none;';
				$classNav='';
			}
		?>

		<?php $_nx_content_stack[]="tabs_help";	ob_start(); ?>
			{=tabs_help}
			
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_nav";	ob_start(); ?>
			{=tabs_nav}
			<li id="permission" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('permission','permission_div')"><b>{string:'permissions'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="permission_div" class="tab"><div id="panel_" class="pm-bxm-box-wrapper pm-bxm-box-wrapper-panel"><div class="pm-bxm-box"><div class="box-title-wrapper box-title-red"><div class="box-title"><h3>{string:'permissions'}</h3></div></div><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-">
                                {=vacancy_permission}
                            </div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','requirements'));
				if($firstTab != 'requirements')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='current';
			}
			else
			{
				$displayMode = 'display:none;';
				$classNav='';
			}
		?>

		<?php $_nx_content_stack[]="tabs_help";	ob_start(); ?>
			{=tabs_help}
			
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_nav";	ob_start(); ?>
			{=tabs_nav}
			<li id="requirements" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('requirements','requirements_div')"><b>{string:'title_requirements'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="requirements_div" class="tab"><div id="panel_" class="pm-bxm-box-wrapper pm-bxm-box-wrapper-panel"><div class="pm-bxm-box"><div class="box-title-wrapper box-title-red"><div class="box-title"><h3>{string:'title_vacancy_identity_section'}</h3></div></div><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout clear-both"><div class="column-1"><div id="group_1" class="form-group"><div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'title_sought_after_profile_section'}</h3></div><div class="pm-bx-form"><div class="record_wrapper"><div class="record">{get_field:recruitment_reasons}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:recruitment_reasons}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:recruitment_reasons}</div></div></div>{get_field:suited_diplomas}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:suited_diplomas}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:suited_diplomas}</div></div></div>{get_field:years_of_practice}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:years_of_practice}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:years_of_practice}</div></div></div></div></div></div></div><div id="group_2" class="form-group"><div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'title_vacancy_requirement_section'}</h3></div><div class="pm-bx-form"><div class="record_wrapper"><div class="record">{get_field:technical_qualifications}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:technical_qualifications}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:technical_qualifications}</div></div></div>{get_field:behavioral_qualifications}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:behavioral_qualifications}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:behavioral_qualifications}</div></div></div></div></div></div></div></div><div class="column-1"><div id="group_1" class="form-group"><div class="section-title-wrapper"><h3 class="section-title inline-block"></h3></div><div class="pm-bx-form"><div class="record_wrapper"><div class="record">{get_field:work_schedule}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:work_schedule}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:work_schedule}</div></div></div>{get_field:companies_having_same_profile}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:companies_having_same_profile}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:companies_having_same_profile}</div></div></div></div></div></div></div><div id="group_2" class="form-group"><div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'title_mission_definitions_means'}</h3></div><div class="pm-bx-form"><div class="record_wrapper"><div class="record">{get_field:mission_definitions}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:mission_definitions}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:mission_definitions}</div></div></div>{get_field:mission_means}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:mission_means}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:mission_means}</div></div></div></div></div></div></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','attached_files'));
				if($firstTab != 'attached_files')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='current';
			}
			else
			{
				$displayMode = 'display:none;';
				$classNav='';
			}
		?>

		<?php $_nx_content_stack[]="tabs_help";	ob_start(); ?>
			{=tabs_help}
			
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_nav";	ob_start(); ?>
			{=tabs_nav}
			<li id="attached_files" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('attached_files','attached_files_div')"><b>{string:'title_files_notes'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="attached_files_div" class="tab"><div id="panel_" class="pm-bxm-box-wrapper pm-bxm-box-wrapper-panel"><div class="pm-bxm-box"><div class="box-title-wrapper box-title-red"><div class="box-title"><h3>{string:'title_files_notes'}</h3></div></div><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout clear-both"><div class="column-1"><div id="group_1" class="form-group"><div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'title_notes'}</h3></div><div class="pm-bx-form"><div class="record_wrapper"><div class="record">
                                            {=comments}
                                        </div></div></div></div></div><div class="column-1"><div id="group_1" class="form-group"><div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'title_associated_documents'}</h3></div><div class="pm-bx-form"><div class="record_wrapper"><div class="record">
                                            {=attached_files}
                                        </div></div></div></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	
<input type="hidden" name="tab" value="{$tab}" id="taber"/>

		{if:trim(%property:tabs_help%)}
		
			<div id="help" class="help">{=tabs_help}</div>
			<script type="text/javascript" language="Javascript">
//<![CDATA[

			var helpDiv=document.getElementById('help');
			var helpText = (helpDiv.innerText||helpDiv.textContent).replace(/\s+/,'');
			if(!helpText)
				helpDiv.style.display = 'none';
		
//]]>
</script>

		{/if}

		
				<div id="nav">
					<ul>{=tabs_nav}
					</ul></div>

		{=tabs_src}

		<?php 
global $firstTab;
$tab = isset($_REQUEST['tab']) ? $_REQUEST['tab'] : $firstTab;
			
		?>
			<script language="javascript" type="text/javascript">
//<![CDATA[

	if('{$tab}'!='')
		window.taber.current_menu('{$tab}','{$tab}_div');

//]]>
</script>
			<div class="form-actions-wrapper">
				<div class="pm-button-wrapper clear-both pm-bxm-top-button-wrapper">
                    {=buttons}
                </div></div></td>
			</tr>
		</table>			
			{/form}

			
		<script language="javascript" type="text/javascript">
//<![CDATA[
			
				if(window.autoSaveDesc)
				{
					window.content_form_handler.initAutoSave(window.autoSaveDesc.url,window.autoSaveDesc.timeout,window.autoSaveDesc.autosaveIndicator);
				}
			
//]]>
</script></div><?php 	
			$__buf=ob_get_contents();
			ob_end_clean();
			echo preg_replace(
				array('/[ \t]+/'),
				array(' '), $__buf);
		; ?>
			<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
			<?php 
			if(isset($_REQUEST['mode']) && $_REQUEST['mode']=='ajax') {
			?>
				{=page.content}
			{else}
				<!DOCTYPE HTML>
<?php
if(preg_match('/AppleWebKit/i',$_SERVER['HTTP_USER_AGENT']) && !preg_match('/chrome/i',$_SERVER['HTTP_USER_AGENT']))
{
	$device='ipad';
}
else
	$device='pc';

$pageMode = isset($_GET["spacemode"])?$_GET["spacemode"]:(isset($_GET["pagemode"])?($_GET["pagemode"]):'');
$this->setProperty('pagemode',$pageMode);
$portalType = $this->getProperty('portal.type');
?>

<html lang="fr"  class="lang_{=lang} device_{$device}">
<head>
	<title><?php echo INTRANET_TITLE; ?></title>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

<?php
if($device=='ipad') 
{
?>
	<meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=0, minimum-scale=1.0, maximum-scale=1.0" />
	<meta name="apple-mobile-web-app-capable" content="yes" />

	<!-- CSS -->
	<style type="text/css" media="all">
	#wrapper {
		position:absolute;
		z-index:1;
		top:0px; bottom:0px; left:0;
		width:100%;
		overflow:auto;
	}
	#scroll-content {
		position:absolute;
		z-index:1;
		width:100%;
		padding:0;
	}
	</style>

<?php 
} 
?>


	<!-- CSS -->
	{require:css/page.css:skin}
	{require:js/page.js:skin}
		
	{if:%var:pageMode% == 'minimal'}
	<link rel="stylesheet" type="text/css" href="/nx/skins/lightsky/css/minimal.css" media="screen" />
	{/if}
	
	<link rel="stylesheet" type="text/css" href="/nx/skins/lightsky/css/rct_print.css" media="print" />
	
{if:%var:pageMode% != 'minimal'}
	<script language="JavaScript" type="text/javascript" src="/nav/nav_def.php?suid={get:suid|0}&section=fdv&amp;delegate={request:delegate}"></script>

<?php 
class PageThemeParams {	function __get($k) {return '';} }

// space theme
class SpacePageThemeParams  extends PageThemeParams {
	function __construct($space,$props) {

		$this->space=$space;
		$this->props = $props;
		$this->type = 'space';

		$bgCol = $space->bgColor->object;
		$bgImURL = $space->bgImage->toHTML('url');
		$banURL = $space->banner->toHTML('url');

		// theme
		$this->theme = $this->space->space_theme->object;

		// title
		$this->title = '<span>Espace</span><br>'.$this->space->title->object;

		// main banner
		$bannerInnerStyle = '';
		$banner = new PageThemeParams;
		$bannerBg = $space->banner_background->object;
		if( $space->banner->path)
		{
			$banURL = $space->banner->url;

			// inner banner
			$bannerInnerStyle = "background:".$bannerBg." url(".$banURL.") no-repeat 0 0 !important;";
		}

		// background : outer banner
		if($space->banner_background_image->path)
			$banner->style = 'background: url('.$space->banner_background_image->url.') repeat-x scroll 0 0 transparent !important;';

		// float div
		$banfloat = new PageThemeParams;
		if($space->banner_float->path)
		{
			$banfloat->url = $this->space->banner_float->url;
			$banfloat->style = "background: url(".$banfloat->url.") no-repeat right top !important;position: absolute;right: 0;top: 0;";
		}

		// inner banner
		$banInner = new PageThemeParams;
		$this->nav = new PageThemeParams;
		$navBanStyle=''; 

		if($h=$space->banner_height->object)
		{
			$bannerInnerStyle .= 'height: '.$h.'px;'; 
			$this->nav->style = 'top:'.($h-53).'px;';
		}

		$banInner->style = $bannerInnerStyle;

		$banner->inner=$banInner;
		$banner->float=$banfloat;
		$this->banner = $banner;

		// free CSS
		$this->freeCss = $this->space->free_css->object;

		// logo
		$this->logo = new PageThemeParams;
		if($space->logo->path)
			$this->logo->url = $space->logo->url;

		$this->logo->name = 'Logo';

		// menu
		$this->topMenu=new PageThemeParams;
		if( $space->banner_menu->path)
		{
			$banMenuURL = $space->banner_menu->url;
			$this->topMenu->style = <<<EOH
.navTop li .leftOnglet,.navTop li .onglet,ul#main-navigation li.nav-item a.nav-link span,ul#main-navigation li.nav-item a.nav-link em,
ul#main-navigation li.nav-item a.nav-link.hovered span, ul#main-navigation li.nav-item a.nav-link:hover span,
ul#main-navigation li.active-nav-item a.nav-link span, ul#main-navigation li.active-nav-item a.nav-link em,
ul#main-navigation li.nav-item a.nomenu.hovered em,ul#main-navigation li.nav-item a.nomenu:hover em {
	background-image:url($banMenuURL);
}

EOH;
		}

	}
}

// portal theme
class PortalPageThemeParams extends PageThemeParams {
	function __construct($props) 
	{
		$this->props = $props;
		$this->type = 'portal';

		// theme
		$this->theme = $props->getProperty('space.theme','');

		// title
		if( trim($_SERVER['site_informations']['_banner_title']) != "")
		{
			$this->title = '<img src="'.$_SERVER['site_informations']['_banner_title'].'" />';
		}
		else
			$this->title = INTRANET_TITLE;

		// main banner
		$banner = new PageThemeParams;

		$bannerBg = (trim($_SERVER['site_informations']['_banner_background']) == "")?"":$_SERVER['site_informations']['_banner_background'];
		if( trim($_SERVER['site_informations']['_banner']) != "")
		{
			$banURL = (trim($_SERVER['site_informations']['_banner']) == "")?"":$_SERVER['site_informations']['_banner'];
			$banner->style = "background:".$bannerBg." url(".$banURL.") no-repeat 0 0 !important;";
		}

		$banInner = new PageThemeParams;
		$this->nav = new PageThemeParams;
		$navBanStyle=''; 
		$bannerInnerStyle = '';
		if($space->banner_height->object)
			$bannerInnerStyle = 'height: '.$space->banner_height->object.'px;'; 

		if( trim($_SERVER['site_informations']['_banner_height']) != "")
		{
			$bannerInnerStyle = 'height:'.$_SERVER['site_informations']['_banner_height'].'px;';
			$this->nav->style = 'top:'.($_SERVER['site_informations']['_banner_height']-53).'px;';
		}
		$banInner->style = $bannerInnerStyle;

		// float div
		$banfloat = new PageThemeParams;
		if( trim($_SERVER['site_informations']['_banner_float']) != "")
		{
			$banfloat->url = $_SERVER['site_informations']['_banner_float'];
			$banfloat->style = "background: url(".$banfloat->url.") no-repeat 0 0 !important;position: absolute;right: 0;top: 0;";			
		}			

		$banner->float=$banfloat;
		$banner->inner=$banInner;
		$this->banner = $banner;

		// free CSS
		$this->freeCss = $this->space->free_css->object;

		// logo
		$this->logo = new PageThemeParams;
		if(isset($_SERVER['site_informations']['_logo']))
			$this->logo->url = $_SERVER['site_informations']['_logo'];

		$this->logo->name = 'Logo';

		// menu
		$this->topMenu=new PageThemeParams;
		if( trim($_SERVER['site_informations']['_banner_menu']) != "")
		{
			$banMenuURL = (trim($_SERVER['site_informations']['_banner_menu']) == "")?"":$_SERVER['site_informations']['_banner_menu'];
			$this->topMenu->style = <<<EOH
.navTop li .leftOnglet,.navTop li .onglet,ul#main-navigation li.nav-item a.nav-link span,ul#main-navigation li.nav-item a.nav-link em,
ul#main-navigation li.nav-item a.nav-link.hovered span, ul#main-navigation li.nav-item a.nav-link:hover span,
ul#main-navigation li.active-nav-item a.nav-link span, ul#main-navigation li.active-nav-item a.nav-link em,
ul#main-navigation li.nav-item a.nomenu.hovered em,ul#main-navigation li.nav-item a.nomenu:hover em {
	background-image:url($banMenuURL);
}
EOH;
		}
	}
}

if($portalType=='space')
{
	$space=$this->getProperty('space.record');
	$pageParams = new SpacePageThemeParams($space,$this);
} 
else
{
	$pageParams = new PortalPageThemeParams($this);
}

$space_theme = $pageParams->theme;
$space_type = $pageParams->type;
$pageType = $pageParams->pageType;
$space_title = $pageParams->title;
$cssTopMenu=$pageParams->topMenu->style;
$bannerFloatStyle = $pageParams->banner->float->style;
$logoUrl = $pageParams->logo->url;
$logoName = $pageParams->logo->name;

?>
{/if}

</head>
<?php flush(); ?>
<body lang="{=lang}" class="lang_{=lang} theme_{var:space_theme}">

<script>
	var fluidScreen = new FluidScreen('content',[680,1024,1280]);
	var homeUrl = '<?php echo PORTAL_HOME; ?>';
</script>

{if:%var:pageMode% != 'minimal'}
<link rel="stylesheet" type="text/css" href="/nx/skins/lightsky/css/theme_{var:space_theme}.css" />

<style>
	#top-navigation {right: 130px;}
	#logo a {padding: 20px;}

	html,body {	background-color:#ffffff;}
	#page-header		{<?php echo $pageParams->banner->style;?>}
	#page-header-inner	{<?php echo $pageParams->banner->inner->style;?> }
	#page-navigation	{<?php echo $pageParams->nav->style; ?>}

	{=skin_free_css_container}
	{var:cssTopMenu}
	<?php echo $pageParams->freeCss; ?>
</style>
{/if}

<div id="wrapper"><div id="scroll-content">
<!--
{if:#property:portal.type# == 'space'}{/if}
 -->
	<div id="page-wrapper">
		
		{if:%var:pageMode% != 'minimal'}
		<div id="page-header">

			<?php if($bannerFloatStyle) {  ?>
			<div id="banner_float" style="<?php echo $bannerFloatStyle; ?>" class="png"><img src="<?php echo $pageParams->banner->float->url; ?>"/></div>
			<?php } ?>

			<div id="page-header-inner">
				<div id="logo">
					<a href="javascript:void(0);" onclick="document.location='<?php echo PORTAL_HOME; ?>';return false;">
					<?php if($logoUrl) { ?>
						<img src="{var:logoUrl}" class="png_bg" alt="{var:logoName}" />
					<?php } ?></a>
				</div>

				<h1 class="banner_title" style="{$bannerTitleStyle}" title="Accueil" onclick="document.location='<?php echo PORTAL_HOME; ?>';return false;">{var:space_title}</h1>
								
				<div id="top-navigation" class="png_bg">
					<div class="top-navigation-w png_bg">
						<div class="top-navigation-i png_bg">
							<ul class="clear-both">
								<li class="first"><span><strong>Bienvenue {user:first_name} {user:last_name}</strong></span></li>
		
								{if:#property:portal.type# != 'space' || #property:portal.suid|portal#!='portal'}
								
								{if:#property:portal.messages# == 'yes'}
								<li><a class="messages" href="/messenger/index.php"><span id="messages-count">...</span> <span class="messages-label">Messages</span></a></li>
								{/if}
		
								<li><a href="/user/profile_editor.php" title="Editer les informations relatives &agrave; mon profil"><span>Mon profil</span></a></li>
								<li class="last"><a href="/user/logout.php"><span>D&eacute;connexion</span></a></li>
								{else}

								{/if}
							</ul>
						</div>
					</div>
				</div>			
			</div>

			<div id="page-navigation">
				<script>
					var currentURL = "<?php echo preg_replace('%/.?oid-[0-9]+/%','/',$_SERVER['REQUEST_URI']); ?>";
					window.container = new Container(nav_def,currentURL);
					// debugger;
					document.write(container.nav.displayMenu());
				</script>			
			</div>
			<!-- <div id="page-current-menu" class="clear-both">
				<script>
					var curMenu = container.currentMenu.displayMenu();
					if(curMenu)
						document.write(curMenu);
					else
						$('page-current-menu').hide();
				</script>
			</div>
			-->
		<div id="page-bread-crumb" class="clear-both">
				<script>
					var curMenu = container.bc.displayMenu();
					if(curMenu)
						document.write(curMenu);
					else
						$('page-bread-crumb').hide();
				</script>
			</div>
 		</div>
		{/if}
		
		<div id="page-content">
			
			<div id="outer-content-wrapper">
				<div id="content">
					{=page.content}
				</div>
			</div>

		</div>
		
		{if:%var:pageMode% != 'minimal'}
		<div id="page-footer">
			<div id="page-footer-links1">Cet Intranet a &eacute;t&eacute; r&eacute;alis&eacute; par <a href="http://www.presencesoft.com" title="Visitez le site de Pr&eacute;sence">Pr&eacute;sence</a> &copy; 2008-<?php echo strftime("%Y"); ?></div>
		</div>
		{/if}
	</div>
	
	

	{if:%var:pageMode% != 'minimal'}
	<script>
		//new Ajax.PeriodicalUpdater("messages-count","/messenger/index.php?nxo=count_unread_messages",{method:'get',frequency: 5});
	</script>
	{else}
	<div id="page-tools">
	<a href="javascript:document.location.reload();" class="s-icon si-arrow-refresh" style="position:absolute;top:10px;right:10px;padding-left: 16px;" title="{string:'refresh'}">&nbsp;</a>
	</div>
	{/if}

 </div></div>

<?php
if($device=='ipad' && $this->getProperty('iscroll_active',true)) 
{
?>
<script type="application/javascript" src="/nx/controls/iscroll/iscroll.js"></script>
<script type="text/javascript">
var theScroll;
function scroll() {
    theScroll = new iScroll('wrapper');
}
document.addEventListener('DOMContentLoaded', scroll, false);
</script>
<div style="height:500px"><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br></div>
<?php 
} 
?>

</body>
</html>
			{/if}
			