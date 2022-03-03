if(typeof PMDH != 'undefined')
{ 
    PMDH.registerNS('Generis.form_candidate');

    Generis.form_candidate = PMDH.createClass(
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
						this.etat_counter = 0;

                        // set onchange handlers
                        this.registerGenericOnchangeOneField('#last_name-control input','last_name' , 'last_name-control' ,this);
                        this.registerGenericOnchangeOneField('#first_name-control input','first_name' , 'first_name-control' ,this);
                        this.registerGenericOnchangeOneField('#civility-control select','civility','civility-control',this);
                        this.registerGenericOnchangeOneField('#gender-control select','gender','gender-control',this);
                        this.registerGenericOnchangeOneField('#date_of_birth-control input','date_of_birth','date_of_birth-control',this);
                        this.registerGenericOnchangeOneField('#nationality-control input','nationality','nationality-control',this);
                        this.registerGenericOnchangeOneField('#studies_level-control input','studies_level','studies_level-control',this);
                        this.registerGenericOnchangeOneField('#email-control input','email','email-control',this);
                        this.registerGenericOnchangeOneField('#mobile-control input','mobile','mobile-control',this);
                        this.registerGenericOnchangeOneField('#phone_1-control input','phone_1','phone_1-control',this);
                        this.registerGenericOnchangeOneField('#phone_2-control input','phone_2','phone_2-control',this);
                        this.registerGenericOnchangeOneField('#zip-control input','zip','zip-control',this);
                        this.registerGenericOnchangeOneField('#country_oid-control select','country_oid','country_oid-control',this);
                        this.registerGenericOnchangeOneField('#town_oid-control input','town_oid','town_oid-control',this);
                        this.registerGenericOnchangeOneField('#mobility_town_oid-control input','mobility_town_oid','mobility_town_oid-control',this);
                        this.formHandler.register_onchange_field('#relevance-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);} ,false,this);
                        this.formHandler.register_onchange_field('#application_type-control input',function(srcElt,self) {self.submitAllForm("application_type-control" , self,srcElt);},false,this);
                        this.formHandler.register_onchange_field('#archive_state-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this);
                        this.formHandler.register_onchange_field('#cand_channel-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this);
                        this.formHandler.register_onchange_field('#establishment-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this);
                        this.registerGenericOnchangeOneField('#hr_manager-control select','hr_manager','hr_manager-control',this);
                        //this.registerGenericOnchangeOneField('#etat_oid-control select','etat_oid','etat_oid-control',this);
						this.formHandler.register_onchange_field('#etat_oid-control select',function(srcElt,self) {if(self.etat_counter == 1)self.sendFormByField('etat_oid' , 'hr_manager-control'  , self); else self.etat_counter = 1;self.addButtonsAction(self)},true,this);
	  
                        this.formHandler.register_onchange_field('#available_delai-control select',this.onchange_available_delai,false,this);

                        this.formHandler.register_onchange_field('#available_from-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this);
                        this.formHandler.register_onchange_field('#salary_min-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this);
																																										  
                        this.formHandler.register_onchange_field('#salary_package-control textarea',function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this);
                        this.formHandler.register_onchange_field('#salary_max-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this);
                        this.formHandler.register_onchange_field('#profile-control input',function(srcElt,self) {self.submitAllForm("profile-control" , self,srcElt);},false,this);
                        this.formHandler.register_onchange_field('#tag-control input',function(srcElt,self) {self.submitAllForm("tag-control" , self,srcElt);},false,this);
                        this.formHandler.register_onchange_field('#years_of_practice-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this);
                        this.formHandler.register_onchange_field('#bachelor_year-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this);
                        this.formHandler.register_onchange_field('#category_oid-control select',function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this);
						this.formHandler.register_onchange_field('#integration_date-control input',function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this);
						
						this.registerGenericOnchangeOneField('#last_position-control input','last_position' , 'last_position-control' ,this);
						this.registerGenericOnchangeOneField('#last_company-control input','last_company' , 'last_company-control' ,this);																								   																														
                        /* this.formHandler.register_onchange_field('.pm-bx-subform-wrapper textarea',
                         function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this); */

                        this.registerGenericOnchange('.pm-bx-subform-wrapper textarea');
                        this.registerGenericOnchange('.pm-bx-subform-wrapper select');
                        this.registerGenericOnchange('.pm-bx-subform-wrapper input');
						this.registerGenericOnchange('#sources-control select');

                        this.formHandler.register_onchange_field('#add_vacancy_wrapper select' , this.onchange_available_vacancies , false, this);

						//autosave : suppression d'un sous record
						this.onclick_delete_record(self);
						
						this.onchange_init_available_delai('#available_delai-control select' , self);
						//Mettre le contenu des emails reçu dans iframe
						//this.received_mail_iframe();
						
						
					

                    }
                }
                catch (e)
                {
                    ajax_log("Exception "+e);
                }
            },

            registerGenericOnchange:function(selector)
            {
                this.formHandler.register_onchange_field(selector,
                    function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this);
            },
            registerGenericOnchangeOneField:function(selector , record , fieldControl)
            {
                this.formHandler.register_onchange_field(selector,
                    function(srcElt,self) {self.sendFormByField(record , fieldControl  , self);},false,this);
				
            },
			addButtonsAction:function(self)
			{	//document.getElementById('actions_ws').style.display = 'none';
				new Ajax.Request('/recruitment/candidates/directory.php?nxo=etat_actions&etat_oid='+self.formHandler.getFieldValue(self.formHandler.getField('etat_oid'))+'&candidate_oid='+self.formHandler.getFieldValue(self.formHandler.getField('oid')),{
					 method : 'GET',
					 asynchronous: true,
					 contentType : 'application/x-www-form-urlencoded',
					 encoding : 'UTF-8',
					 onSuccess : function(data) {
						if(data.responseText.trim() != ''){
							document.getElementById('candidate_actions').innerHTML = data.responseText;
							/*document.getElementById('actions_ws').innerHTML = "<span style='padding: 5px;font-weight: bold;'>Actions:</span>"+data.responseText;
							document.getElementById('actions_ws').style.display = 'block'; */
						}else {
							document.getElementById('candidate_actions').innerHTML = data.responseText;
							/*document.getElementById('actions_ws').innerHTML = ''
							document.getElementById('actions_ws').style.display = 'none'; */
						}
						 
					 }
				});
			},
			

            sendFormByField:function(record , fieldControl , self)
            {
                var http = new XMLHttpRequest();
                var url = window.edit_url+"&record="+record;
                var params = record+"="+self.formHandler.getFieldValue(self.formHandler.getField(record))+"&oid="+self.formHandler.getFieldValue(self.formHandler.getField('oid'));
                http.addEventListener("progress", self.updateProgress(fieldControl));
                http.addEventListener("load", self.transfertComplete(fieldControl));
                http.open("POST", url, true);

                //Send the proper header information along with the request
                http.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

                http.send(params);
            },

            // onchange handlers

            onchange_available_delai:function(srcElt,self) {
                document.getElementById('available_from-control').style.visibility="hidden";
                if(self.formHandler.getFieldValue(self.formHandler.getField('available_delai')) == 'date'){
                    document.getElementById('available_from-control').style.visibility="visible";
                }else{
                    document.getElementById('available_from-control').style.visibility="hidden";
                }
                self.submitAllForm("available_delai-control" , self);

            },
			
			onchange_init_available_delai:function(srcElt,self) {
                document.getElementById('available_from-control').style.visibility="hidden";
                if(self.formHandler.getFieldValue(self.formHandler.getField('available_delai')) == 'date'){
                    document.getElementById('available_from-control').style.visibility="visible";
                }else{
                    document.getElementById('available_from-control').style.visibility="hidden";
                }

            },

            onchange_available_vacancies:function(srcElt,self) {

                    if(self.formHandler.getFieldValue(self.formHandler.getField('available_vacancies')) == '?'){
                        document.getElementById('association_button').style.visibility = 'hidden'
                    }else{
                        document.getElementById('association_button').style.visibility = 'visible'
                    }
                    //Modalbox.show(null,{overlayClose: false});
                    //associateToVacancy('available_vacancies-control', 'available_vacancies', 'associate-to-vacancy');

            },

            // FY
            //onchange_sf_generic:function(srcElt,self) {self.submitAllForm("establishment-control" , self);},

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

            updateProgress:function(fieldControl, srcElt, evt){
                this.changeControlColor(fieldControl, srcElt, "#FFFF80");
            },

            transfertComplete:function(fieldControl, srcElt , evt){
                var self = this;
				if(fieldControl == 'first_name-control' || fieldControl == 'last_name-control'){
					this.updateTitle();
				}
                setTimeout(function()
                {
                    self.changeControlColor(fieldControl, srcElt, "");
                },500);
            },
			
			updateTitle:function(){
				var self = this;
				try { 
					document.getElementById("page_title").getElementsByTagName('a')[0].innerHTML = self.formHandler.getFieldValue(self.formHandler.getField('first_name'))+' '+self.formHandler.getFieldValue(self.formHandler.getField('last_name'));
				}catch(err){
					console.log(err);
				}
			},


            submitAllForm:function(fieldcontrol , self, srcElt){
                if(fieldcontrol)
                    self.updateProgress(fieldcontrol);
                else
                    self.updateProgress(null,srcElt);

                self.form.request({
                    onComplete: function(transport){
                        if(fieldcontrol)
                            self.transfertComplete(fieldcontrol);
                        else
                            self.transfertComplete(null,srcElt);
                    }
                });
            },
			
	    onclick_delete_record:function(self)
		{
			var elements = document.getElementsByClassName('delete-action');

			for (var i = 0; i < elements.length; i++) {
				elements[i].addEventListener('click', (function(i) {
					return function() {
						self.form.request({
							onComplete: function(transport){}
						});
					};
				})(i), false);
			}
		},

		received_mail_iframe:function(){
			frames = document.getElementsByClassName('iframe_email_content');
			for(var i=0; i<frames.length; i++){
				iframe = frames[i];
				email_content = iframe.parentNode.firstChild;
				iframe = (iframe.contentWindow) ? iframe.contentWindow : (iframe.contentDocument.document) ? iframe.contentDocument.document : iframe.contentDocument;
				iframe.document.open();
				iframe.document.write(email_content.innerHTML);
				iframe.document.close();
				frames[i].style.height = document.body.scrollHeight+"px";	
			}
		}
	});

    window.formObj = new window.Generis.form_candidate(window.content_form_handler);

} // end