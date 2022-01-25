<style type="text/css">
	{=app.form.css}
	#field_technical_qualifications .control-label, #field_behavioral_qualifications .control-label{
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
	#descriptionProfil-control-wrapper{
		margin-top:3px;
	}
	#field_companies_having_same_profile .control-label{
	}
	.mp_span{
		float: left; 
		width: 80px;
	}
	.mp_btn{
		width : 126px;
	}
	.dropdown-menu {
		right: 0px;
		left: auto !important;
	}
	.checkbox_label{
		font-size : 14px;
	}

</style><script>
	{=app.form.js}

</script><script language="php">

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


</script><script language="php">
$msgHelp = $this->getProperty('msg.help');
if($msgHelp)
{

</script><div id="help" class="help"><div class="message">{var:msgHelp}
	</div>
</div><script language="php">
}
</script>



<?php $_nx_content_stack[]="comments";	ob_start(); ?>
	<div class="pm-bxm-box-content"><div class="comments-wrapper" id="comments-wrapper">
    {records:comments.records}
        {record}
            <div class="comment-wrapper"><div class="comment"><span class="comment_author">{field:user_oid}
				</span>: {field:comment}
			</div><div class="comment_date">{field:date}
			</div>
		</div>
        {/record}
    {/records}
    
	</div><div class="add-comment-wrapper"><div class="add-comment"><div class="add-comment-inner"><textarea rows="3" cols="30" name="add_comment_zone" type="text" class="text"/>
			</div>
		</div><div class="add-comment-process clear-both"><a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="Generis.Recruitment.addComment(this, 'add_comment_zone', '{=add_comment.url}'); this.blur(); return false;"><span class="btn-bg"><span class="s-icon si-comment-add">{string:"post_comment"}
					</span>
				</span>
			</a><div style="display: none;" id="vacancy-button-loader"/>
		</div>
	</div>
</div>

<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="accepted_proposals";	ob_start(); ?>
	{records:accepted_proposals.records}
		{record}
			<div class="vacancy-meta-entry"><strong>{field:full_name}
	</strong> {string:"date_prefix_lc"} {field:proposal_acceptance_date}
</div>
		{/record}
	{/records}
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="selected_candidates";	ob_start(); ?>
	{records:selected_candidates.records}
	{if:records.count>0}
	<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'selected_candidates'}
	</h3>
</div><div class="pm-bxm-box-content"><div class="table-list-wrapper"><table class="table-list">
			
				{record}
				<tr><td class="entry"><strong>{field:full_name}
					</strong><br _pmethod="flatten"/><script>
							window.dlg_change_contrat_signingCfg{record.index} = { title:"{string:'change_contrat_signing_title'}", url: "{=change_contrat_signing.url}{record.url_key}", width:550 };

							window.dlg_change_integration_planCfg{record.index} = { title:"{string:'change_integration_plan_title'}", url: "{=change_integration_plan.url}{record.url_key}", width:550 };

							window.dlg_change_integration_noteCfg{record.index} = { title:"{string:'change_integration_note_title'}", url: "{=change_integration_note.url}{record.url_key}", width:550 };

							window.dlg_change_hire_dateCfg{record.index} = { title:"{string:'change_hire_date_title'}", url: "{=change_hire_date.url}{record.url_key}", width:550 };
						
					</script><u>{field.label:contrat_signing}
					</u>: <strong>{field:contrat_signing}
					</strong> (<a onclick="PMModalbox.loadFromUrl(window.dlg_change_contrat_signingCfg{record.index}, event); return false;" href="javascript:void(0);"><span>{string:"change_data"}
						</span>
					</a>)
						<br _pmethod="flatten"/><u>{field.label:hire_date}
					</u>: <strong>{if:#field.object:hire_date_raw#!=''}{field:hire_date}{else}{string:"empty_hire_date"}{/if}
					</strong> (<a onclick="PMModalbox.loadFromUrl(window.dlg_change_hire_dateCfg{record.index}, event); return false;" href="javascript:void(0);"><span>{string:"change_data"}
						</span>
					</a>)
						<br _pmethod="flatten"/><u>{field.label:integration_plan}
					</u>: <strong>{field:integration_plan}
					</strong> (<a onclick="PMModalbox.loadFromUrl(window.dlg_change_integration_planCfg{record.index}, event); return false;" href="javascript:void(0);"><span>{string:"change_data"}
						</span>
					</a>)
						<br _pmethod="flatten"/><u>{field.label:integration_note}
					</u>: <strong>{field:integration_note}
					</strong> (<a onclick="PMModalbox.loadFromUrl(window.dlg_change_integration_noteCfg{record.index}, event); return false;" href="javascript:void(0);"><span>{string:"change_data"}
						</span>
					</a>)
						<br _pmethod="flatten"/>
				</td>
			</tr>
				{/record}
		   
			
		</table>
	</div>
</div>
	{/if} 
 {/records}





<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="buttons";	ob_start(); ?>

<div class="btn-group button_bs_right" role="group"><button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false"><span class="glyphicon glyphicon-menu-hamburger"/>
	&nbsp;{string:"actions_vacancy"}
	</button><ul class="dropdown-menu">
		{if: %property:use_multiposting% && %property:multiposting_url% }
		<li><a href="{=multiposting_url}"><span class="glyphicon glyphicon-chevron-right" aria-hidden="true"/>&nbsp;&nbsp;{string:"multiposting_access"}
			</a>
		</li>
		{/if}
		<li><a onclick="PMModalbox.display(dlg_deleteConfig{record.index}, event);"><span class="glyphicon glyphicon-remove-circle" aria-hidden="true"/>&nbsp;&nbsp;{string:"dlg_delete_definitly"}
			</a>
		</li><li><a onclick="PMModalbox.display(dlg_archiveConfig{record.index}, event);"><span class="glyphicon glyphicon-th-large" aria-hidden="true"/>&nbsp;&nbsp;{string:"archive_helper"}
			</a>
		</li><li><a href="{=applicant.url}"><span class="glyphicon glyphicon-user" aria-hidden="true"/>&nbsp;&nbsp;Candidats
			</a>
		</li><li><a href="{=calendar.url}"><span class="glyphicon glyphicon-calendar" aria-hidden="true"/>&nbsp;&nbsp;Entretiens
			</a>
		</li><li><a href="{=candidate_add.url}"><span class="glyphicon glyphicon-plus" aria-hidden="true"/>&nbsp;&nbsp;Ajouter Candidat
			</a>
		</li>
	</ul>
</div><button type="button" class="btn btn-default right submit_marge" onclick="PMFormSubmit.submit(this, dlg_submitConfig, dlg_successConfig, dlg_failureConfig); this.blur(); return false;"><span class="glyphicon glyphicon-floppy-save" aria-hidden="true"/>&nbsp;&nbsp;
	{string:"submit"} 
</button>
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="attached_files";	ob_start(); ?>
	
<div class="pm-bxm-box-content" id="associated-files"><table class="associated-files">
{records:attached_files.records}
	{record}

    <tr id="row-file-{field:oid}"><td class="label"><a href="{=download.url}{record.url_key}">{field.html:file_name}
				</a>
			</td><td class="operations"><a class="s-icon si-page-white-put" href="{=download.url}{record.url_key}" alt="{string:"><span>{string:"action_download"}
					</span>
				</a><a class="s-icon si-delete af-delete-action" href="javascript:void(0);" alt="{string:"><span>{string:"action_delete"}
					</span>
				</a><input type="checkbox" value="{field:oid}" id="checkbox-file-{field:oid}" name="files_to_delete[]" _pmethod="flatten"/>
			</td>
		</tr><tr id="deleted-row-file-{field:oid}" style="display:none"><td colspan="2" class="deleted">{field.html:file_name} {string:"deleted"},
            <a href="javascript:void(0);" objectoid="{field:oid}" class="action s-icon si-arrow-rotate-clockwise af-restore-action"><span>{string:"action_restore"}
					</span>
				</a>
			</td>
		</tr>

	{/record}
{/records}

	</table><div class="add-file-wrapper"><div class="add-file-title"><a href="javascript:void(0);" class="action s-icon si-add af-add-action"><span>{string:"action_add_file"}
				</span>
			</a>
		</div>
	</div><script>
		Generis.Recruitment.appendAssocFilesHandlers('associated-files');
	
	</script>
</div>

<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
<?php $_nx_content_stack[]="instant_feedback_count";	ob_start(); ?>
	{records:instant_feedback_count.records}
		{if:records.count > 0}
			{string:"yes"} ({records.count})
		{else}
			{string:"no"}
		{/if}
	{/records}
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="delayed_feedback_count";	ob_start(); ?>
	{records:delayed_feedback_count.records}
		{if:records.count > 0}
			{string:"yes"} ({records.count})
		{else}
			{string:"no"}
		{/if}		
	{/records}
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="offer";	ob_start(); ?>
{if: %property:use_multiposting% && %property:multiposting_url% }
	{record:multiposting.record}
	<form:group title="{string:'title_offer'}"><div class="pm-bxm-box-content"><div class="table-list-wrapper"><table class="table-list"><tr><td class="entry">{field.label:status}: <strong>{field.html:status}
						</strong>
					</td>
				</tr><tr><td class="entry">{field.label:nbr_jobboard}: <strong>{field.html:nbr_jobboard}
						</strong>
					</td>
				</tr><tr><td class="entry">{field.label:nbr_clics}: <strong>{field.html:nbr_clics}
						</strong> clic(s)
					</td>
				</tr>
			</table>
		</div>
	</div>
</form:group>
	{/record}
{/if}
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
<?php $_nx_content_stack[]="publication";	ob_start(); ?>
	<div class="pm-bxm-box-content"><div class="table-list-wrapper"><table class="table-list"><tr><td class="entry"><span class="mp_span">{string:"publiate"}: 
					</span><a class="pm-button btn-with-icon mp_btn" href="{=multiposting_url}"><span class="btn-bg"><span class="s-icon si-arrow-right">{string:"multiposting_access_new"}
							</span>
						</span>
					</a>
				</td>
			</tr>
		</table>
	</div>
</div>
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<form:record id="content_form" record="page.record">
	<?php $_nx_content_stack[]="email_field";	ob_start(); ?>
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
	if($check < 10){
		$check = '0'.$check;
	}
	$email = $code_client.'_'.$year.$oidpad.$check.$suffix.'@pourcandidature.com';
}
else
	$email = '';
?>
<form:field-wrapper><form:field-label>{string:'Email du poste'}
		</form:field-label><form:field-control><p class="form-control-static">{$email}
			</p><input type="hidden" name="email" value="{var:email}" _pmethod="flatten"/>
		</form:field-control>
	</form:field-wrapper>
	<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
	<?php $_nx_content_stack[]="vacancy_dashboard";	ob_start(); ?>
		<form:field-wrapper><form:field-label>{string:"title_delay_open_close"}
		</form:field-label><form:field-control><p class="form-control-static">{field.html:delay_between_open_and_close}
			</p>
		</form:field-control>
	</form:field-wrapper><form:field-wrapper><form:field-label>{string:"title_delay_close_office_taking"}
		</form:field-label><form:field-control><p class="form-control-static">{field.html:delay_between_close_and_taking_office} {string:"days"}
			</p>
		</form:field-control>
	</form:field-wrapper><form:field-wrapper><form:field-label>{string:"title_instant_feedback"}
		</form:field-label><form:field-control><p class="form-control-static">{=instant_feedback_count}
			</p>
		</form:field-control>
	</form:field-wrapper><form:field-wrapper><form:field-label>{string:"title_delayed_feedback"}
		</form:field-label><form:field-control><p class="form-control-static">{=delayed_feedback_count}
			</p>
		</form:field-control>
	</form:field-wrapper>
	<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
	<script>
		window.debugme = 2;

		window.dlg_backConfig = { title : "{string:'dlg_back_title'}", message : "{string:'dlg_back_content'}", viewMode : "okCancel", url : "{=back_list.url}", target : "content", labels : { ok : "{string:'dlg_ok'}", cancel : "{string:'dlg_cancel'}" } };

		window.dlg_submitConfig = { title : "{string:'dlg_wait_title'}", message : "{string:'dlg_wait_content'}", viewMode : "wait" };

		window.dlg_successConfig = { title : "{string:'dlg_success_title'}", message : "{string:'dlg_success_content'}", viewMode : "ok", target : "content", labels : { ok : "{string:'dlg_success'}" } };

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
		
		window.dlg_archiveConfig{record.index} = {
                                                title : "{string:'dlg_archive_title'}",
                                                message : "{string:'dlg_archive_content'}",
                                                viewMode : "okCancel",
                                                url : "{=archive.url}{record.url_key}",
                                                target : "content",
                                                labels : {
                                                    ok : "{string:'dlg_ok'}",
                                                    cancel : "{string:'dlg_cancel'}"
                                            } };
	
	</script><form:main><form:toolbar>
			{if:%property:from_home%}
			<button type="button" class="btn btn-default button_back" onclick="document.location.href='{=back_to_home.url}'"><span class="glyphicon glyphicon-chevron-left" aria-hidden="true"/>&nbsp;&nbsp;
				{string:"back_to_home"}
			
			</button>
			{/if}
			{=buttons}
		
		</form:toolbar><form:tabs><form:tab id="informations" title="{string:'title_vacancy_fiche'}"><form:panels><form:panel titlexx="{string:'title_vacancy_fiche'}"><form:columns><form:column index="1"><form:group title="{string:'general_infos'}"><form:field name="name" _pmethod="flatten"/><form:field name="code" _pmethod="flatten"/><form:field name="vacancy_project" _pmethod="flatten"/><form:field name="number" _pmethod="flatten"/><form:field name="announce_date" _pmethod="flatten"/><form:field name="opening_date" _pmethod="flatten"/><form:field name="current_step"><form:field-help>Les différentes états de recrutement:<br _pmethod="flatten"/>
											1 - En cours<br _pmethod="flatten"/>
											2 - Suspendu <br _pmethod="flatten"/>
											3 - Clôturé <br _pmethod="flatten"/>
											4 - En brief <br _pmethod="flatten"/>
										</form:field-help>
									</form:field>
								</form:group><form:group title="{string:'title_contract'}"><form:field name="contract_type_oid" _pmethod="flatten"/><form:field name="category_oid" _pmethod="flatten"/><form:field name="mission_start_date" _pmethod="flatten"/><form:field name="closing_date"><form:field-help>Date de fermeture du poste
										</form:field-help>
									</form:field><form:field name="suited_recruitment_date" _pmethod="flatten"/><form:field name="taking_office_date" _pmethod="flatten"/>
								</form:group><form:group title="{string:'title_classement_poste'}"><form:field name="application_type" _pmethod="flatten"/><form:field name="archive_state" _pmethod="flatten"/>
								</form:group><div id="stage_group" style="display:none"><form:group title="{string:'title_internship_section'}"><form:field name="internship_title" _pmethod="flatten"/><form:field name="internship_start" _pmethod="flatten"/><form:field name="internship_end" _pmethod="flatten"/><form:field name="executive_committee_presentation" _pmethod="flatten"/>
									</form:group>
								</div>
							</form:column><form:column index="2"><form:group title="{string:'title_manage_recruitment'}"><form:field name="manager_oid" _pmethod="flatten"/><form:field name="cand_channel" _pmethod="flatten"/>
									{=email_field}
								
								</form:group><form:group title="{string:'title_poste_affectation'}"><form:field name="client_oid" _pmethod="flatten"/><form:field name="subsidiary_oid" _pmethod="flatten"/><form:field name="establishment" _pmethod="flatten"/><form:field name="pole" _pmethod="flatten"/><form:field name="direction" _pmethod="flatten"/><form:field name="service_oid" _pmethod="flatten"/><form:field name="duty_station_oid" _pmethod="flatten"/>
								</form:group><form:group title="{string:'title_salary_package'}"><form:field-double name="salary_min" name2="salary_max" _pmethod="flatten"/><form:field name="salary_type" _pmethod="flatten"/>
								</form:group><form:group title="{string:'title_vacancy_dashboard'}">
									{=vacancy_dashboard}
								
								</form:group>
								{=selected_candidates}
								{=offer}
								
							
							</form:column>
						</form:columns>
					</form:panel>
				</form:panels>
			</form:tab><form:tab id="permission" title="{string:'permissions'}">
<?php
	$user = &$GLOBALS['_NX_user'];
	$userOid = $user->getProperty('oid');
	if($_nx_record->creator->object != $userOid && $_nx_record->manager_oid->object != $userOid)
	{
		$_nx_record->groups_user_total_control->setProperty('isEdit',false);
		$_nx_record->groups_user_readonly->setProperty('isEdit',false);
	}
?>

				<form:panels><form:panel titlexx="{string:'permissions'}"><form:columns><form:column index="1"><form:group title="{string:'total_control'}"><form:field name="creator" _pmethod="flatten"/><form:field name="rh_oid" _pmethod="flatten"/><form:field flabel="{string:'total_control'}" name="groups_user_total_control" _pmethod="flatten"/>
								</form:group>
							</form:column><form:column index="2"><form:group title="{string:'title_readonly'}"><form:field flabel="{string:'readOnly'}" name="groups_user_readonly" _pmethod="flatten"/>
								</form:group>
							</form:column>
						</form:columns>
					</form:panel>
				</form:panels>
			</form:tab><form:tab id="requirements" title="{string:'title_requirements'}"><form:panels><form:panel titlexx="{string:'title_vacancy_identity_section'}"><form:columns><form:column index="1"><form:group title="{string:'title_sought_after_profile_section'}"><form:field name="recruitment_reasons" _pmethod="flatten"/><form:field name="suited_diplomas" _pmethod="flatten"/><form:field name="years_of_practice" _pmethod="flatten"/><form:field name="work_schedule" _pmethod="flatten"/><form:field name="companies_having_same_profile" _pmethod="flatten"/>
								</form:group><form:group title="{string:'title_vacancy_requirement_section'}"><form:field name="technical_qualifications" _pmethod="flatten"/><form:field name="behavioral_qualifications" _pmethod="flatten"/>
								</form:group>
							</form:column><form:column index="2"><form:group title="{string:'field:descriptionProfil'}"><form:field-no-label name="descriptionProfil" _pmethod="flatten"/>
								</form:group><form:group title="{string:'title_mission_definitions_section'}"><form:field-no-label name="mission_definitions" _pmethod="flatten"/>
								</form:group><form:group title="{string:'title_mission_means_section'}"><form:field-no-label name="mission_means" _pmethod="flatten"/>
								</form:group>
							</form:column>
						</form:columns>
					</form:panel>
				</form:panels>
			</form:tab><form:tab id="attached_files" title="{string:'title_files_notes'}"><form:panels><form:panel titlexx="{string:'title_files_notes'}"><form:columns><form:column index="1"><form:group title="{string:'title_notes'}">
									{=comments}
								
								</form:group>
							</form:column><form:column index="2"><form:group title="{string:'title_associated_documents'}">
									{=attached_files}
								
								</form:group>
							</form:column>
						</form:columns>
					</form:panel>
				</form:panels>
			</form:tab><form:tab id="publication" title="{string:'title_vacancy_publication'}"><form:panels><form:panel titlexx="{string:'title_files_notes'}"><form:columns><form:column index="1"><div id="annonce_group" style="display:block"><form:group title="{string:'title_app_connected_section'}"><form:field name="app_connected" _pmethod="flatten"/>
									</form:group>
								</div>
							</form:column>
							{if:%property:use_multiposting%}
							<form:column index="2"><form:group title="{string:'multiposting_publication'}">
									{=publication}
								
								</form:group>
							</form:column>
							{/if}
						
						</form:columns>
					</form:panel>
				</form:panels>
			</form:tab><form:tab id="evaluation" title="{string:'title_eval_criteria'}"><form:panels><form:panel titlexx="{string:''}"><form:group title="{string:'title_eval_criteria'}"><form:field-no-label name="evaluation_criteria" _pmethod="flatten"/>
						</form:group>
					</form:panel>
				</form:panels>
			</form:tab>
		</form:tabs><form:toolbar>
			{=buttons}
		
		</form:toolbar>
	</form:main>
</form:record>