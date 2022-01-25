<?php $_nx_content_stack[]="page.content";	ob_start(); ?>
 {require:css/rct.css:skin} 

<div class="pm-page-title-wrapper"><div class="pm-page-title-inner-wrapper"><div class="pm-title">{string:"page_title_list"}
		</div>
	</div>
</div><table class="columns-viewer"><tr><td class="left-column"><div class="pm-grid-outer-wrapper"><div class="generis-toolbar-wrapper"><div class="generis-toolbar"><a class="s-icon si-add" href="javascript:void(0);" onclick="ajax_navigate(event,'{=add.url}','content'); return false;"><span>{string:"request_vacancy_open"}
							</span>
						</a><a class="s-icon si-zoom" href="javascript:void(0);" onclick="PMDH.toggle('search-panel', 'appear'); return false;"><span>{string:"search"}
							</span>
						</a>
						{if:#property:is_search# == 'true'}
						<a class="s-icon si-arrow-refresh" href="javascript:void(0);" onclick="ajax_navigate(event,'{=list.url}','content'); return false;"><span>{string:"cancel_search"}
							</span>
						</a>
						{/if}
					
					</div>
				</div>
				
				
				
				 {records:page_pending.records} 
				{if:records.count > 0}
				<div class="vacancies-validation-wrapper"><div><a class="vacancies-validation-title" href="javascript:void(0)" onclick="PMDH.toggle(PMDH.getNextSibling(this));">{string:"title_pending_vacancies"}
						</a><div class="entries" style="display:none">
							 {record} 
							<a href="javascript:void(0)" onclick="ajax_navigate(event,'{=edit_request.url}{record.url_key}','content');">[{field:workflow_state}] <strong>{field:name} ({field:number})
								</strong>, {string:"by"} {field:requested_by} {string:"date_prefix_lc"} {field:request_date}
							</a>
							 {/record} 
						
						</div>
					</div>
				</div>
				{/if}
				 {/records} 

				 {records:page.records} 
				{if:records.count > 0}
				<div class="directory-grid-wrapper" id="vacancy-directory-grid"><table class="directory-grid directory-grid-header"><tr class="directory-grid-header-row columns-layout columns-layout-4 width-padding width-white-border"><th class="dg-column"><div class="dg-cell-wrapper">{string:"title_v_identity"}
								</div><th class="dg-column elastic"><div class="dg-cell-wrapper">{string:"title_localization"}
									</div>
								</th><th class="dg-column elastic"><div class="dg-cell-wrapper">{string:"title_v_state"}
									</div>
								</th><th class="dg-column elastic"><div class="dg-cell-wrapper">{string:"title_dates"}
									</div>
								</th><th class="dg-operations dg-1-operations">&nbsp;
								</th>
							</th>
						</tr><table class="directory-grid">
					 {record} 
						<tr class="directory-grid-row columns-layout columns-layout-4 width-padding width-white-border row_{record.even_odd}"><td class="dg-column" onclick="ajax_navigate(event,'{=edit.url}{record.url_key}','content')"><div class="dg-cell-wrapper"><span class="field-content"><strong>{field:name}
											</strong>
										</span>
									{if:#field.object:number# != ''}
									<span class="field-content">({field:number})
										</span>
									{/if}
									<br _pmethod="flatten"/><span class="field-content">{field:category_oid}{if:#field.object:category_oid# != '' && #field.object:contract_type_oid#}, {/if}{field:contract_type_oid}
										</span><br _pmethod="flatten"/><span class="field-content">Dossier N° {field:code}
										</span>
									</div>
								</td><td class="dg-column elastic" onclick="ajax_navigate(event,'{=edit.url}{record.url_key}','content')"><div class="dg-cell-wrapper"><span class="field-label">{field.label:subsidiary_oid} :
										</span><span class="field-content">{field:subsidiary_oid}
										</span><br _pmethod="flatten"/><span class="field-label">{field.label:service_oid} :
										</span><span class="field-content">{field:service_oid}
										</span><br _pmethod="flatten"/><span class="field-label">{field.label:duty_station_oid} :
										</span><span class="field-content">{field:duty_station_oid}
										</span>
									</div>
								</td><td class="dg-column elastic" onclick="ajax_navigate(event,'{=edit.url}{record.url_key}','content')"><div class="dg-cell-wrapper"><span class="field-label">{field.label:current_step} :
										</span><span class="field-content">{field:current_step}
										</span><br _pmethod="flatten"/><span class="field-label">{field.label:progress_level} :
										</span><span class="field-content">{field:progress_level}{if:#field:progress_level_meta# != ''} ({field:progress_level_meta}){/if}
										</span><br _pmethod="flatten"/><span class="field-label">{field.label:application_type} :
										</span><span class="field-content">{field:application_type}
										</span>
									</div>
								</td><td class="dg-column elastic" onclick="ajax_navigate(event,'{=edit.url}{record.url_key}','content')"><div class="dg-cell-wrapper"><span class="field-label">{field.label:opening_date} :
										</span><span class="field-content">
									{if:#field:opening_date# != '-/-/-'}{field:opening_date}{else}-{/if}
									
										</span><br _pmethod="flatten"/><span class="field-label">{field.label:closing_date} :
										</span><span class="field-content">
									{if:#field:closing_date# != '-/-/-'}{field:closing_date}{else}-{/if}
									
										</span><br _pmethod="flatten"/><span class="field-content">&nbsp;
										</span>
									</div>
								</td><td class="dg-operations dg-1-operations"><div class="dg-cell-wrapper"><a class="s-icon si-page-white-edit" href="javascript:void(0);" onclick="ajax_navigate(event,'{=edit.url}{record.url_key}','content');" title="{string:'edit_helper'}"><span>{string:"edit_helper"}
											</span>
										</a>
									</div>
								</td>
							</tr>
					
					 {/record} 
					
						</table>
					</table>
				{/if}
				 {/records} 

				{no_record}
<div class="pm-msg-wrapper"><span class="pm-msg-grid-empty">{string:"empty_list"}
						</span>
					</div>
{/no_record}
				
{if:pages.several_pages}
	<div class="pm-pagination">
	{pages:previous}
		<a href="javascript:void(0);" onclick="ajax_navigate(event,'{page.url}{=filterKey}','content')">&laquo;
						</a>
	{/pages}

	{pages:all}
		{if:page.is_current}
			<span class="current">{page.index}
						</span>
		{else}
			<a href="javascript:void(0);" onclick="ajax_navigate(event,'{page.url}{=filterKey}','content')">{page.index}
						</a>
		{/if}
	{/pages}

	{pages:next}
		<a href="javascript:void(0);" onclick="ajax_navigate(event,'{page.url}{=filterKey}','content')">&raquo;
						</a>
	{/pages}
	
					</div>
{/if}

				</div>
			</div><td class="right-column"><div class="clearBoth"/><p class="pm-page-message">
	{string:"page_message_list"}
	<br _pmethod="flatten"/>
	{string:"page_message_list_details"}
	<span class="pm-droiteIntro">&nbsp;
					</span>
				</p>
			</td>
		</td>
	</tr><script>
	PMDH.Skin.LightSky.Grid.init('', {
		wrapperClass	: 'directory-grid-wrapper',
		gridClass		: 'directory-grid',
		gridRowClass	: 'directory-grid-row'
	});

	</script>

<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>


<script language="php">
if(isset($_REQUEST['mode']) && $_REQUEST['mode']=='ajax') {

	</script>
{=page.content}
{else}

{/if}
</table>