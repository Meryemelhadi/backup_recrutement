if(typeof PMDH != 'undefined')
{
    PMDH.registerNS('Generis.form_candidate_search');

    Generis.form_candidate_search = PMDH.createClass(
        {
            // constructor
            initialize : function(formHandler) {
                try
                {
                    var self = this;

                    if(formHandler)
                    {

                        this.form = formHandler.form;
                        this.formHandler = formHandler;

                        // set onchange handlers
                        this.formHandler.register_onchange_field('#full_text_search-control input',function(srcElt,self) {if(self.formHandler.getFieldValue(self.formHandler.getField('sort_by')) == '?') self.formHandler.setFieldValue(self.formHandler.getField('sort_by') , 'update_date' );} ,false,this);

						/*this.formHandler.register_onchange_field('#full_text_search-control input',function(srcElt,self) {if(self.formHandler.getFieldValue(self.formHandler.getField('sort_by')) == '?') self.formHandler.setFieldValue(self.formHandler.getField('sort_by') , 'relevance_rate' );self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#first_name-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#last_name-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#gender-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#town_oid-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#diploma-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#school-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#studies_level-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#salary-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#years_of_practice-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#available_from-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#profile-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#current_salary-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#vacancy-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#archive_state-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#relevance-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#category_oid-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#etat_oid-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#provider-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#update_date_min-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#update_date_max-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#sort_by-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#read_by-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#hr_manager-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#cand_channel-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
						this.formHandler.register_onchange_field('#establishment-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
  						*/
                    }
                }
                catch (e)
                {
                    ajax_log("Exception "+e);
                }
            },

			submitAllForm:function(fieldcontrol , self, srcElt){
                if(fieldcontrol)
                    self.updateProgress(fieldcontrol);
                else
                    self.updateProgress(null,srcElt);

				self.form.submit();
            },
			
			updateProgress:function(fieldControl, srcElt, evt){
                this.changeControlColor(fieldControl, srcElt, "#FFFF80");
            },
			
			changeControlColor:function(fieldControl, srcElt , color){

                if (!srcElt)
                {
                    var control = document.getElementById(fieldControl);
                    if(control.getElementsByTagName("select").length > 0)
                        srcElt = control.getElementsByTagName("select")[0];
                    else if(control.getElementsByTagName("input").length > 0)
                        srcElt = control.getElementsByTagName("input")[0];
                    if(fieldControl == "application_type-control"){
                        srcElt = control;
                    }
                    else if(fieldControl == "profile-control"){
                        srcElt = control.getElementsByTagName("ul")[0];
                    }
                }

                if(srcElt)
                    srcElt.style.backgroundColor = color;

            },

            registerGenericOnchange:function(selector)
            {
                this.formHandler.register_onchange_field(selector,
                    function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this);
            },
			
			changefield:function(name , default_value , type=''){
				if(type == 'max_min'){
					this.formHandler.setFieldValue(this.formHandler.getField(name+'_min') , default_value);
					this.formHandler.setFieldValue(this.formHandler.getField(name+'_max') , default_value);
					this.submitAllForm(name+'-control' , this, this.formHandler.getField(name));
				}else{
					this.formHandler.setFieldValue(this.formHandler.getField(name) , default_value);
					this.submitAllForm(false , this, this.formHandler.getField(name));
				}
			}
	});

    window.formObj = new window.Generis.form_candidate_search(window.content_form_handler);

} // end