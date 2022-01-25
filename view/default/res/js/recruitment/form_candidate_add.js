if(typeof PMDH != 'undefined')
{
    PMDH.registerNS('Generis.form_candidate_add');

    Generis.form_candidate_add = PMDH.createClass(
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
						//Change form onsubmit
						this.form.setAttribute('onsubmit','window.formObj.checkDoublon(this)');
                      
                    }
                }
                catch (e)
                {
                    ajax_log("Exception "+e);
                }
            },
			
            checkDoublon:function(f)
            {
				 var self = this;
                if (typeof check_form_rct_candidate_add === "function") { 
					var functionName = 'check_form_rct_candidate_add';
				else var functionName = 'check_form_rct_candidate_add_drh';
                if(window[functionName](
					var http = new XMLHttpRequest();
					var url = "?nxo=check_candidate_doublon";
					var params = "first_name="+self.formHandler.getFieldValue(self.formHandler.getField("first_name"))+"&last_name="+self.formHandler.getFieldValue(self.formHandler.getField('last_name'))+"&email="+self.formHandler.getFieldValue(self.formHandler.getField("email"));
					//http.addEventListener("load", 'return false');
					http.open("POST", url, true);
					//Send the proper header information along with the request
					http.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
					http.onreadystatechange = function() {//Call a function when the state changes.
						if(http.readyState == 4 && http.status == 200) {
							self.form.setAttribute('onsubmit','return '+functionName+'(this);');
							if(http.responseText)
							{
								PMModalbox.display({ title : "Candidat existe dans la cvthèque", message : "Un candidat avec le mème nom existe dans la cvthèque", viewMode : "okCancel", redirection : http.responseText, url : "?nxo=add_process" , target : "content", form : self.form , buttons : [{label : "Voir la fiche candidat existante", onclick : PMModalbox.go_to_url ,icon : 'si-arrow-right'}, {label : "Enregistrer", onclick : PMModalbox.executePost ,icon : 'si-disk'}]}, event); 
								 
								return true;
							}else{
								PMFormSubmit.submit(self.form, dlg_submitContinueConfig, null, dlg_failureConfig); self.form.blur(); return false;
								//self.form.submit();
							}
							
						}
					}
					http.send(params);
					return false;
                }else return false;
            }
            
        });

    window.formObj = new window.Generis.form_candidate_add(window.content_form_handler);

} // end