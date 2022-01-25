if(typeof PMDH != 'undefined')
{
    PMDH.registerNS('Generis.form_vacancy');

    Generis.form_vacancy = PMDH.createClass(
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
						this.formHandler.register_onchange_field('#contract_type_oid-control select',this.onchange_contract_type,true,this);
						this.formHandler.register_onchange_field('#cand_channel-control select',this.onchange_cand_channel,true,this);
						this.formHandler.register_onchange_field('#current_step-control select',this.onchange_current_step,true,this);
						this.formHandler.register_onchange_field('#application_type-control input',this.onchange_application_type_annonce,true,this);
						
                    }
                }
                catch (e)
                {
                    ajax_log("Exception "+e);
                }
            },

            /*
            //contract_type de type radio
            onchange_contract_type:function(srcElt,self) {
                var rate_value ="";
				var oRadio = document.forms[0].elements["contract_type_oid"];
			   for(var i = 0; i < oRadio.length; i++)
			   {
				  if(oRadio[i].checked)
				  {
					 rate_value = oRadio[i].nextSibling.data;
					 break;
				  }
			   }
                rate_value = rate_value.replace(/\s+/g, '').toLowerCase();
				if(rate_value.indexOf('stage') > -1){
					document.getElementById("stage_group").style.display="block";
					document.getElementById('field_suited_recruitment_date').style.display="none";
					var cand_channel = document.getElementsByName("cand_channel")[0] ;
					for(var j=1; j<cand_channel.options.length; j++){
						option = cand_channel.options[j].text.replace(/\s+/g, '').toLowerCase();
						if(option.indexOf('stage') > -1){
							cand_channel.selectedIndex = j;
							break;
						}
					}
				}else{
					document.getElementById("stage_group").style.display="none";
					document.getElementById('field_suited_recruitment_date').style.display="block";
					document.getElementsByName("cand_channel")[0].selectedIndex =0;
				}

            },
            onchange_cand_channel:function( srcElt,self ) {
                 var cand_channel = document.getElementsByName("cand_channel")[0] ;
                 option = cand_channel.options[cand_channel.selectedIndex].text.replace(/\s+/g, '').toLowerCase();
                 if(option.indexOf('stage') > -1){
                     var oRadio = document.forms[0].elements["contract_type_oid"];
                     for(var i = 0; i < oRadio.length; i++)
                     {
                         value = oRadio[i].nextSibling.data.replace(/\s+/g, '').toLowerCase();
                         if(value.indexOf('stage') > -1)
                         {
                             oRadio[i].checked=true;
                             self.onchange_contract_type();
                             break;
                         }
                     }
                 }
             }
            */
            onchange_contract_type:function(srcElt,self) {
                var contract_oid = document.getElementsByName("contract_type_oid")[0];
                var rate_value = contract_oid.options[contract_oid.selectedIndex].text.replace(/\s+/g, '').toLowerCase();

                if(rate_value.indexOf('stage') > -1){
                    document.getElementById("stage_group").style.display="block";
                    document.getElementById('field_suited_recruitment_date').style.display="none";
                    var cand_channel = document.getElementsByName("cand_channel")[0] ;
                    for(var j=1; j<cand_channel.options.length; j++){
                        option = cand_channel.options[j].text.replace(/\s+/g, '').toLowerCase();
                        if(option.indexOf('stage') > -1){
                            cand_channel.selectedIndex = j;
                            break;
                        }
                    }
                }else{
                    document.getElementById("stage_group").style.display="none";
                    document.getElementById('field_suited_recruitment_date').style.display="block";
                    document.getElementsByName("cand_channel")[0].selectedIndex =0;
                }

            },

            onchange_cand_channel:function( srcElt,self ) {
				var cand_channel = document.getElementsByName("cand_channel")[0] ;
				option = cand_channel.options[cand_channel.selectedIndex].text.replace(/\s+/g, '').toLowerCase();
				if(option.indexOf('stage') > -1){
					var oSelect = document.forms[0].elements["contract_type_oid"];
				   for(var i = 0; i < oSelect.options.length; i++)
				   {
                       value = oSelect.options[i].text.replace(/\s+/g, '').toLowerCase();
                       if(value.indexOf('stage') > -1){
                           oSelect.selectedIndex = i;
                           self.onchange_contract_type();
                           break;
                       }
				   }
				}

			},
			onchange_current_step:function(srcElt,self) {
                if(self.formHandler.getFieldValue(self.formHandler.getField('current_step')) == 3){
					self.formHandler.setFieldValue(self.formHandler.getField('archive_state') , 1);
				}else{
					self.formHandler.setFieldValue(self.formHandler.getField('archive_state') , 0);
				}
            },
			onchange_application_type_annonce:function(srcElt,self) {
				if(document.getElementById('application_type1').checked)
					document.getElementById('ref_jobboard').style.display = 'block';
				else document.getElementById('ref_jobboard').style.display = 'none';
			},

	});

    window.formObj = new window.Generis.form_vacancy(window.content_form_handler);

} // end