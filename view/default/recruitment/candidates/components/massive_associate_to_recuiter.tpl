{form:page.record}
<script>	
	window.dlg_vma_w_cfg = { title : "{string:'dlg_wait_title'}", disableCheckForm: true, message : "{string:'dlg_wait_content'}", viewMode : "wait" };

	window.dlg_vma_s_cfg = { title : "{string:'dlg_success_title'}", message : "{string:'dlg_success_content'}", viewMode : "ok", url : "{=list.url}", target : "content", labels : { ok : "{string:'dlg_success'}" } };

	window.dlg_vma_f_cfg = { title : "{string:'dlg_failure_title'}", message : "{string:'dlg_failure_content'}", viewMode : "cancel", target : "content", labels : { cancel : "{string:'dlg_cancel'}" } };

</script><div class="modalbox-form"><div class="record_wrapper"><div class="record">
		{fields}
		<div id="field_{field.label}" class="form-group form-group-bs"><div class="control-label-wrapper-bs"><label for="{field.label}" class="control-label-bs control-label">{field.label} {if:#field.required#}* {/if}:
					</label>
				</div><div class="form-control-bs" id="{field.label}-control">
				{field}
			
				</div>
			</div>
		{/fields}
	
		</div>
	</div><div class="pm-button-wrapper clear-both"><button type="button" class="btn btn-default right" onclick="PMFormSubmit.submit(this, window.dlg_vma_w_cfg, window.dlg_vma_s_cfg, window.dlg_vma_f_cfg); this.blur(); return false;"><span class="glyphicon glyphicon-floppy-save" aria-hidden="true"/>&nbsp;{string:"submit"} 
		
		</button><button type="button" class="btn btn-default submit_marge right" onclick="PMModalbox.hide(); this.blur(); return false;"><span class="glyphicon glyphicon-off" aria-hidden="true"/>&nbsp;{string:"cancel"} 
		
		</button>
	</div>
</div>
{/form}	