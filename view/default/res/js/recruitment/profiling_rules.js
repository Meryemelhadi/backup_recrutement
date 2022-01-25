PMDH.registerNS('Generis.Recruitment.Profiling_rules');

window.Generis.Recruitment.Profiling_rules = Generis.Recruitment.Profiling_rules = PMDH.createClass(
{
	form:null,
	formHandler:null,

	initialize : function(formHandler) {
		if(!formHandler)
			return;
		
		this.form = formHandler.form;
		this.formHandler = formHandler;

		// onchange handlers
		this.formHandler.register_onchange_field('#profiling_on-control select',this.onchange_profiling_on,true,this);
		// this.formHandler.register_onchange_field('profiling_value_for-control select',this.onchange_profiling_value_for,true,this);
		
		// for IE bug
		this.disableAutocomplete();
	},

	onchange_profiling_on:function(srcElt,self) 
	{
		var v = srcElt.value;
		if(v=='form_field_category' || v=='form_field_profile')
		{
			// champ de formulaire
			self.formHandler.showField('field_form_field');
			
			// self.formHandler.showField('field_profiling_value_for');
			self.formHandler.hideField('field_vacancy');
			self.formHandler.hideField('field_cand_channel');
			self.formHandler.hideField('field_category_oid');
			self.formHandler.hideField('field_profile');
			self.formHandler.hideField('field_provider');
			self.formHandler.hideField('field_establishment');
		}
		else
		{
			// autre : cacher le champs
			self.formHandler.hideField('field_form_field');

			self.formHandler.showField('field_vacancy');
			self.formHandler.showField('field_cand_channel');
			self.formHandler.showField('field_category_oid');
			self.formHandler.showField('field_profile');
			self.formHandler.showField('field_provider');
			self.formHandler.showField('field_establishment');
			// self.formHandler.hideField('field_profiling_value_for');
		}
	},

	onchange_profiling_value_for:function(srcElt,self) 
	{
		if(srcElt.value=='list')
		{
			// sélection liste
			self.formHandler.showField('field_keywords');
			self.formHandler.showField('field_not_keywords');
			self.formHandler.showField('field_vacancy');
			self.formHandler.showField('field_vacancy');
			self.formHandler.showField('field_cand_channel');
			self.formHandler.showField('field_category_oid');
			self.formHandler.showField('field_profile');
			self.formHandler.showField('field_provider');
			self.formHandler.showField('field_establishment');
		}
		else
		{
			// autre : cacher le champs
			self.formHandler.hideField('field_keywords');
			self.formHandler.hideField('field_not_keywords');
			self.formHandler.hideField('field_vacancy');
			self.formHandler.hideField('field_cand_channel');
			self.formHandler.hideField('field_category_oid');
			self.formHandler.hideField('field_profile');
			self.formHandler.hideField('field_provider');
			self.formHandler.hideField('field_establishment');
		}
	},

	disableAutocomplete : function()
	{
		if (document.getElementsByTagName)
		{
			var inputElements = document.getElementsByTagName('input');

			for (i=0; inputElements[i]; i++) 
			{
				if (inputElements[i].className && (inputElements[i].className.indexOf('disableAutoComplete') != -1)) 
				{
					inputElements[i].setAttribute('autocomplete','off');
				}
			}
		}
	}
});