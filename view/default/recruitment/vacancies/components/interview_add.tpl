
			<?php $_nx_content_stack[]="page.content";	ob_start(); ?>
				
		
		<?php ob_start(); ?>

			
	<link href="/nx/controls/font-awesome/css/font-awesome.min.css" rel="stylesheet" type="text/css" media="all">
		<style type="text/css">
			.black .panel{
				background-color: #fff !important;
				width: 350px !important;
				height: 225px;
			}
			.input-group.field-date {
				width: 195px;
			}
			
		</style>
	<script type="text/javascript" language="Javascript">
//<![CDATA[

		if (window.container)
			window.container.setAppTitle("");
		
//]]>
</script>
	<div class="pm-page-title-wrapper">
		<div class="pm-page-title-inner-wrapper">
			<div id="page_title" class="pm-title">
				<div class="title_tb" style="float:right"></div></div></div></div>
			<style>
			
            {=app.form.css}

        
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
}?><?php 
	$current_operation = "candidates";
	$linkText = 'title_candidates';
	$linkText = addslashes(__($linkText));
?>
<?php $_nx_content_stack[]="buttons";	ob_start(); ?>
	<button type="button" class="btn btn-default button_back" onclick="document.location.href='{=previous_operation.url}';"><span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>&nbsp;&nbsp;
		{string:"previous_op_label"}
	</button><span class="pm-button-sep"></span><button type="button" class="btn btn-default" onclick="PMFormSubmit.submit(this, dlg_waitConfig, dlg_successConfig, dlg_failureConfig); this.blur(); return false;"><span class="glyphicon glyphicon-floppy-save" aria-hidden="true"></span>&nbsp;&nbsp;
		{string:"submit"}
	</button>
			<script type="text/javascript" language="Javascript">
//<![CDATA[

		window.dlg_waitConfig = { title : "{string:'dlg_wait_title'}", message : "{string:'dlg_wait_content'}", viewMode : "wait" };

		window.dlg_successConfig = { title : "{string:'dlg_success_title'}", message : "{string:'dlg_success_content'}", viewMode : "ok", url : "{=previous_operation.url}", target : "content", labels : { ok : "{string:'dlg_success'}" } };

		window.dlg_failureConfig = { title : "{string:'dlg_failure_title'}", message : "{string:'dlg_failure_content'}", viewMode : "cancel", target : "content", labels : { cancel : "{string:'dlg_cancel'}" } };	
	
//]]>
</script>
	
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
{record:candidate.record}
	<?php $_nx_content_stack[]="candidate_etat";	ob_start(); ?>
		
			<div id="field_etat_oid" class="form-group form-group-bs field-type-text_choice ">
				<div class="control-label-wrapper-bs">
					<label for="etat_oid" class="control-label-bs control-label">{field.label:etat_oid} :
					</label></div>
				<div class="form-control-bs" id="etat_oid-control">
				{field.form:etat_oid}
			</div></div>
	<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>		
	<?php $_nx_content_stack[]="cv_preview";	ob_start(); ?>
		
			<iframe src="{field.string:cv_path:url}" width="100%" height="800" frameborder="0" marginwidth="0" marginheight="0" align="top" hspace="0" vspace="0" scrolling="0">
				<object width="100%" height="2000">
					<param name="MOVIE" value="{field.string:cv_path:url}.swf">
						<param name="PLAY" value="true">
							<param name="LOOP" value="true">
								<param name="QUALITY" value="high">
									<embed src="{field.string:cv_path:url}.swf" width="100%" height="2000" play="true" align="" loop="true" quality="high" type="application/x-shockwave-flash" pluginspage="[[http://www.macromedia.com/go/getflashplaye]r]"/>
								</param>
							</param>
	<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
{/record}
<?php $_nx_content_stack[]="interviews";	ob_start(); ?>
{records:interviews.records}

							<table style="width:100%">
	{record}
		
								<tr>
									<td>Entretien avec&nbsp;&nbsp;  <b>{field:_candidate_oid}</b> &nbsp;&nbsp;</td>
									<td>Effectu?? par <b>{field:_interviewer_oid}</b> &nbsp;&nbsp;</td>
									<td>De: <b>{field:_time_start}</b> A <b>{field:_time_end}</b></td>
								</tr>
	{/record}

							</table>
{/records}
{no_record}

							<div class="empty-records">{string:"empty_interviews"}</div>
{/no_record}



							<script type="text/javascript" language="Javascript">
//<![CDATA[

window.date_interview = '{string:"other_interviews"}';

//]]>
</script>


<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
<?php $_nx_content_stack[]="left_column";	ob_start(); ?>
	???<?php 
	$current_operation = $this->getProperty('current_operation');
?><td class="directory-card-side-column left_side" id="left_column"><div class="tabbable tabs-left"><ul class="nav nav-tabs"><li class="back-btn"><a href="{var:backList}&mode=page" style="width:245px"><span class="glyphicon glyphicon-chevron-left"></span><span>{string:"back_to_vacancies"}</span></a></li><li class="<?php  if($current_operation == 'edit'){ ?>active<?php } ?>" ><a href=" {=edit.url}&mode=page"><span>{string:"title_general_infos"}</span></a></li><li class="{if:'.$current_operation.' == 'candidates'}active{/if}"><a href="{=candidates.url}&from_vac=1&mode=page"><span>{string:"title_candidates"}</span></a></li><li class="<?php  if($current_operation == 'calendar'){ ?>active<?php } ?>" ><a href="{=calendar.url}&mode=page"><span>{string:"title_calendar"}</span></a></li><li class="<?php  if($current_operation == 'recruitment_providers'){ ?>active<?php } ?>"><a href="{=feedback.url}&mode=page"><span>{string:"title_evaluation"}</span></a></li><li class="<?php  if($current_operation == 'warning'){ ?>active<?php } ?>" ><a href="{=warning.url}&mode=page"><span>{string:"title_warnings"}</span></a></li><li class="<?php  if($current_operation == 'history'){ ?>active<?php } ?>" ><a href="{=history.url}&mode=page"><span>{string:"title_history"}</span></a></li></ul></div></td>
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
<?php $_nx_content_stack[]="vacancy_title";	ob_start(); ?>
	???{record:vacancy_title_record}{/record}

							<script type="text/javascript" language="Javascript">
//<![CDATA[

/* set current page BC */
if(window.container)
{
	window.container.bc.resetLink().addAjaxLink('{=title}','{=edit.url}&mode=ajax').addLink('{var:linkText}','');
}
document.getElementById('page_title').innerHTML = 'Poste ?? pourvoir: {=title} <br/> {=step}';

//]]>
</script>
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

{=vacancy_title}

		
							<table class="directory-card-table">
								<tr>
				{=left_column}
				
									<td class="directory-card-main-column">
									<div id="content_form" class="pm-bxm-wrapper">
		{form:page.record}
		
										<script language="javascript" type="text/javascript">
//<![CDATA[

			window.autoSaveDesc = null;
			window.content_form = document.getElementById('{=submit.id}');
			window.currentForm = document.getElementById('{=submit.id}');
			if(window.currentForm)
			{
				window.currentForm.handler = window.content_form_handler = new window.Generis.Forms(window.currentForm);
				// window.currentForm.className += 'form-horizontal';
			}

		
//]]>
</script>
											<script type="text/javascript" language="Javascript">
//<![CDATA[

						document.getElementById('page_title').innerHTML = unescape("{string:'page_title_add_interview'}")+' : {field.html:candidate_oid}';
						if (typeof document.getElementById('page-bread-crumb') === "undefined") {
							document.getElementById('page-bread-crumb').innerHTML += ' > <span class="png_bg"><a class="nav-item" href="#">'+document.getElementById('page_title').innerHTML+'</a></span>';
						}
						
					
//]]>
</script>
											<div class="form-actions-wrapper">
												<div class="pm-button-wrapper clear-both pm-bxm-top-button-wrapper">
													<div class="btn-group btn-group-width">
							   {=buttons}
						   </div></div></div>
											<script language="javascript" type="text/javascript">
//<![CDATA[

			window.taber = new window.Generis.Tabs();
		
//]]>
</script><?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','planification'));
				if($firstTab != 'planification')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='active current';
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
			<li id="planification" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('planification','planification_div',null,'active')"><b>{string:'planification'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="planification_div" class="tab panel">
														<div id="panel_" class="form-panel-bs">
															<div class="">
																<div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-">
															<div class="columns-layout-bs row">
																<div class="column-1 col-md-6">
																	<div class="row">
																	<fieldset id="group_1" class="field-group-bs">
																		<legend class="">{string:'planification'}
																		</legend>
																		<div class="form-group-content">{get_field:candidate_oid}{/get_field}
																		<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
																						<div class="control-label-wrapper-bs">
																							<label for="{field.name}" class="control-label-bs control-label">{field.label:candidate_oid}{if:field.isRequired}
																			<span class="required-field">*</span>{/if} :
																							</label></div>
																					<div class="form-control-bs" id="{field.name}-control">{field:candidate_oid}</div></div>{get_field:interview_by_oid}{/get_field}
																		<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
																						<div class="control-label-wrapper-bs">
																							<label for="{field.name}" class="control-label-bs control-label">{field.label:interview_by_oid}{if:field.isRequired}
																			<span class="required-field">*</span>{/if} :
																							</label></div>
																					<div class="form-control-bs" id="{field.name}-control">{field:interview_by_oid}</div></div>
																		<div class="column-1 col-md-6">
																			<div class="row">{get_field:date}{/get_field}
																			<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
																							<div class="control-label-wrapper-bs">
																								<label for="{field.name}" class="control-label-bs control-label">{field.label:date}{if:field.isRequired}
																				<span class="required-field">*</span>{/if} :
																								</label></div>
																						<div class="form-control-bs" id="{field.name}-control">{field:date}</div></div></div></div>
																		<div class="column-1 col-md-6">
																			<div class="row">{get_field:time_start}{/get_field}
																			<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
																							<div class="control-label-wrapper-bs">
																								<label for="{field.name}" class="control-label-bs control-label">{field.label:time_start}{if:field.isRequired}
																				<span class="required-field">*</span>{/if} :
																								</label></div>
																						<div class="form-control-bs" id="{field.name}-control">{field:time_start}</div></div>{get_field:time_end}{/get_field}
																			<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
																							<div class="control-label-wrapper-bs">
																								<label for="{field.name}" class="control-label-bs control-label">{field.label:time_end}{if:field.isRequired}
																				<span class="required-field">*</span>{/if} :
																								</label></div>
																						<div class="form-control-bs" id="{field.name}-control">{field:time_end}</div></div></div></div>{get_field:location}{/get_field}
																		<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
																						<div class="control-label-wrapper-bs">
																							<label for="{field.name}" class="control-label-bs control-label">{field.label:location}{if:field.isRequired}
																			<span class="required-field">*</span>{/if} :
																							</label></div>
																					<div class="form-control-bs" id="{field.name}-control">{field:location}</div></div></div>
																	</fieldset>
																	<fieldset id="group_2" class="field-group-bs">
																		<legend class=""> 
																		</legend>
																		<div class="form-group-content">{get_field:interview_type}{/get_field}
																		<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
																						<div class="control-label-wrapper-bs">
																							<label for="{field.name}" class="control-label-bs control-label">{field.label:interview_type}{if:field.isRequired}
																			<span class="required-field">*</span>{/if} :
																							</label></div>
																					<div class="form-control-bs" id="{field.name}-control">{field:interview_type}</div></div>{get_field:interview_etat}{/get_field}
																		<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
																						<div class="control-label-wrapper-bs">
																							<label for="{field.name}" class="control-label-bs control-label">{field.label:interview_etat}{if:field.isRequired}
																			<span class="required-field">*</span>{/if} :
																							</label></div>
																					<div class="form-control-bs" id="{field.name}-control">{field:interview_etat}</div></div></div>
																	</fieldset></div></div>
																<div class="column-1 col-md-6">
																	<div class="row">
																	<fieldset id="group_1" class="field-group-bs">
																		<legend class="">{string:'informations'}
																		</legend>
																		<div class="form-group-content">{get_field:vacancy_oid}{/get_field}
																		<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
																						<div class="control-label-wrapper-bs">
																							<label for="{field.name}" class="control-label-bs control-label">{field.label:vacancy_oid}{if:field.isRequired}
																			<span class="required-field">*</span>{/if} :
																							</label></div>
																					<div class="form-control-bs" id="{field.name}-control">{field:vacancy_oid}</div></div>
												{=candidate_etat}
											</div>
																	</fieldset>
																	<fieldset id="group_2" class="field-group-bs">
																		<legend class=""> 
																		</legend>
																		<div class="form-group-content">{get_field:interview_feedback}{/get_field}
																		<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
																						<div class="control-label-wrapper-bs">
																							<label for="{field.name}" class="control-label-bs control-label">{field.label:interview_feedback}{if:field.isRequired}
																			<span class="required-field">*</span>{/if} :
																							</label></div>
																					<div class="form-control-bs" id="{field.name}-control">{field:interview_feedback}</div></div></div>
																	</fieldset>
																	<fieldset id="group_interviews" class="field-group-bs">
																		<legend class="">{string:'other_interviews'}{=date_interview}
																		</legend>
																		<div class="form-group-content">
																			<div id="interviews">
												{=interviews}
												</div></div>
																	</fieldset></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','candidat_email'));
				if($firstTab != 'candidat_email')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='active current';
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
			<li id="candidat_email" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('candidat_email','candidat_email_div',null,'active')"><b>{string:'candidat_email'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="candidat_email_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div id="email-candidate-wrapper">{get_field:candidate_email_not}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:candidate_email_not}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:candidate_email_not}</div></div><div id="email-candidate-wrapper-fields">{get_field:default_email}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:default_email}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:default_email}</div></div>{get_field:email_title}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:email_title}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:email_title}</div></div>{get_field:email_content}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:email_content}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:email_content}</div></div>{get_field:email_docs}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:email_docs}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:email_docs}</div></div>{get_field:attached_files_candidate}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:attached_files_candidate}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:attached_files_candidate}</div></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','interviewer_email'));
				if($firstTab != 'interviewer_email')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='active current';
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
			<li id="interviewer_email" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('interviewer_email','interviewer_email_div',null,'active')"><b>{string:'interviewer_email'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="interviewer_email_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div id="email-interviewer-wrapper">{get_field:interviewer_email_not}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:interviewer_email_not}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:interviewer_email_not}</div></div><div id="email-interviewer-wrapper-fields">{get_field:user_default_email}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:user_default_email}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:user_default_email}</div></div>{get_field:user_email_title}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:user_email_title}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:user_email_title}</div></div>{get_field:user_email_content}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:user_email_content}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:user_email_content}</div></div>{get_field:user_email_docs}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:user_email_docs}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:user_email_docs}</div></div>{get_field:attached_files_interviewer}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:attached_files_interviewer}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:attached_files_interviewer}</div></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	
						{if:%field.string:cv_path:url%}
						<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','cv'));
				if($firstTab != 'cv')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='active current';
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
			<li id="cv" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('cv','cv_div',null,'active')"><b>{string:'cv'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="cv_div" class="tab panel">
							{=cv_preview}
						</div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	
						{/if}
						
													<script type="text/javascript" language="Javascript">
//<![CDATA[


							window.interviews_url = "{=interviews.url}";
							window.onloadForm2 = function()
							{
								window.formObj = new window.Generis.form_interview('{=submit.id}',true);
							};

							if(typeof window.Generis.form_interview == "undefined")
							{
								setTimeout(function(){
									window.ajax_load('/nx/skins/lightsky/js/recruitment/form_interview.js','form_interview_js');
									window.ajax_onload(window.onloadForm2,'form_interview_js');
								} , 2000);
							}
							else
								window.onloadForm2();
								
							/*Generis.Recruitment.appendAssocFilesHandlers('interviewers','file_attachement_interviewers');		  
							Generis.Recruitment.appendAssocFilesHandlers('candidate','file_attachement_candidate');

							Generis.Recruitment.emailSampleHandler({
								fieldname: 'default_email', 
								element: 'add-interview-wrapper',
								emailTitleField: 'email_title',
								emailContentField:'email_content',
								url: '/recruitment/vacancies/admin/directory.php?nxo=get_email_sample'});
								
							Generis.Recruitment.emailSampleHandler({
								fieldname: 'user_default_email', 
								element: 'add-interview-wrapper',
								emailTitleField: 'user_email_title',
								emailContentField:'user_email_content',
								url: '/recruitment/vacancies/admin/directory.php?nxo=get_email_sample'});
							
							
							document.getElementById("candidate_email_not1").onchange=function() {
								document.getElementById("default_email_div").style.display="none";
								document.getElementById("email_title_div").style.display="none";
								document.getElementById("email_content_div").style.display="none";
								document.getElementById("email_docs_div").style.display="none";
								document.getElementById("attached_files_candidate").style.display="none";
							};
							document.getElementById("candidate_email_not2").onchange=function() {
								document.getElementById("default_email_div").style.display="block";
								document.getElementById("email_title_div").style.display="block";
								document.getElementById("email_content_div").style.display="block";
								document.getElementById("email_docs_div").style.display="block";
								document.getElementById("attached_files_candidate").style.display="block";
							};

							document.getElementById("interviewer_email_not1").onchange=function() {
								document.getElementById("user_default_email_div").style.display="none";
								document.getElementById("user_email_content_div").style.display="none";
								document.getElementById("user_email_title_div").style.display="none";
								document.getElementById("user_email_docs_div").style.display="none";
								document.getElementById("attached_files_interviewers").style.display="none";
							};

							document.getElementById("interviewer_email_not2").onchange=function() {
								document.getElementById("user_default_email_div").style.display="block";
								document.getElementById("user_email_content_div").style.display="block";
								document.getElementById("user_email_title_div").style.display="block";
								document.getElementById("user_email_docs_div").style.display="block";
								document.getElementById("attached_files_interviewers").style.display="block";
							};*/
						
//]]>
</script>
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
													<ul class="nav nav-tabs nav-tabs-bs">{=tabs_nav}
													</ul></div>

		{=tabs_src}

		<?php 
global $firstTab;
$tab = isset($_REQUEST['tab']) ? $_REQUEST['tab'] : $firstTab;
			
		?>
											<script language="javascript" type="text/javascript">
//<![CDATA[

	if('{$tab}'!='')
		window.taber.current_menu('{$tab}','{$tab}_div',null,'active');

//]]>
</script>
			{/form}

			
										<script language="javascript" type="text/javascript">
//<![CDATA[
			
				if(window.autoSaveDesc)
				{
					window.content_form_handler.initAutoSave(window.autoSaveDesc.url,window.autoSaveDesc.timeout,window.autoSaveDesc.autosaveIndicator);
				}
			
//]]>
</script></div></td>
								</tr>
							</table>
						</param>
					</param>
				</object>
			</iframe>
	</link><?php 	
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
	{require:css/page_bs.css:skin}
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
		if(trim($space->banner_title->url) != '')
		{
			$this->title = '<img src="'.$space->banner_title->url.'" />';
		}
		else
			// $this->title = '<span>Espace</span><br>'.$this->space->title->object;
			$this->title = $this->space->title->object;

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


?>

<?php 

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

<link href="/nx/controls/bootstrap/css/bootstrap.min.css" rel="stylesheet" type="text/css"  media="all" />
<!--<link href="/nx/controls/font-awesome/css/font-awesome-bs.min.css" rel="stylesheet" type="text/css"  media="all" />-->



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
					document.write(window.container.nav.displayMenu());
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
					var curMenu = window.container.bc.displayMenu();
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
			<div id="page-footer-links1">R&eacute;alisation par <a href="http://www.presencesoft.com" title="Visitez le site de Pr&eacute;sence">Pr&eacute;sence</a> &copy; 2008-<?php echo strftime("%Y"); ?></div>
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

<script type="application/javascript" src="/nx/controls/ajax/jquery-3.0.0.min.js"></script>
<script type="text/javascript">$.noConflict();</script>
<script type="application/javascript" src="/nx/controls/bootstrap/js/bootstrap.min.js"></script>

</body>
</html>
			{/if}
			