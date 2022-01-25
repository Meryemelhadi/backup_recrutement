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

                        //fields value
                        this.last_name_value= self.formHandler.getFieldValue(self.formHandler.getField('last_name'));
                        this.first_name_value= self.formHandler.getFieldValue(self.formHandler.getField('first_name'));
                        this.date_of_birth_value= self.formHandler.getFieldValue(self.formHandler.getField('date_of_birth'));
                        this.nationality_value= self.formHandler.getFieldValue(self.formHandler.getField('nationality'));
                        this.studies_level_value= self.formHandler.getFieldValue(self.formHandler.getField('studies_level'));
                        this.email_value= self.formHandler.getFieldValue(self.formHandler.getField('email'));
                        this.mobile_value= self.formHandler.getFieldValue(self.formHandler.getField('mobile'));
                        this.phone1_value= self.formHandler.getFieldValue(self.formHandler.getField('phone_1'));
                        this.phone2_value= self.formHandler.getFieldValue(self.formHandler.getField('phone_2'));
                        this.zip_value= self.formHandler.getFieldValue(self.formHandler.getField('zip'));
                        this.town_oid_value= self.formHandler.getFieldValue(self.formHandler.getField('town_oid'));


                        // set onchange handlers
                        this.formHandler.register_onchange_field('#last_name-control input',this.onchange_last_name,false,this);
                        this.formHandler.register_onchange_field('#first_name-control input',this.onchange_first_name,false,this);
                        this.registerGenericOnchangeOneField('#civility-control select','civility','civility-control',this);
                        this.registerGenericOnchangeOneField('#gender-control select','gender','gender-control',this);
                        this.formHandler.register_onchange_field('#date_of_birth-control input',this.onchange_date_of_birth,false,this);
                        this.formHandler.register_onchange_field('#nationality-control input',this.onchange_nationality,false,this);
                        this.formHandler.register_onchange_field('#studies_level-control input',this.onchange_studies_level,false,this);
                        this.formHandler.register_onchange_field('#email-control input',this.onchange_email,false,this);
                        this.formHandler.register_onchange_field('#mobile-control input',this.onchange_mobile,false,this);
                        this.formHandler.register_onchange_field('#phone_1-control input',this.onchange_phone1,false,this);
                        this.formHandler.register_onchange_field('#phone_2-control input',this.onchange_phone2,false,this);
                        this.formHandler.register_onchange_field('#zip-control input',this.onchange_zip,false,this);
                        this.registerGenericOnchangeOneField('#country_oid-control select','country_oid','country_oid-control',this);
                        this.formHandler.register_onchange_field('#town_oid-control input',this.onchange_town_oid,true,this);
                        this.registerGenericOnchangeOneField('#relevance-control select','relevance','relevance-control',this);
                        this.formHandler.register_onchange_field('#application_type-control input',this.onchange_application_type,true,this);
                        this.registerGenericOnchangeOneField('#archive_state-control select','archive_state','archive_state-control',this);
                        this.registerGenericOnchangeOneField('#establishment-control select','establishment','establishment-control',this);
                        this.registerGenericOnchangeOneField('#cand_channel-control select','cand_channel','cand_channel-control',this);

                        this.registerGenericOnchangeOneField('#hr_manager-control select','hr_manager','hr_manager-control',this);
                        this.registerGenericOnchangeOneField('#etat_oid-control select','etat_oid','etat_oid-control',this);
                        this.formHandler.register_onchange_field('#available_delai-control select',this.onchange_available_delai,false,this);
                        this.formHandler.register_onchange_field('#available_from-control input',function(srcElt,self) {self.submitAllForm("available_from-control" , self);},false,this);
                        this.formHandler.register_onchange_field('#salary_min-control input',function(srcElt,self) {self.submitAllForm("salary_min-control" , self);},false,this);
                        this.formHandler.register_onchange_field('#salary_max-control input',function(srcElt,self) {self.submitAllForm("salary_max-control" , self);},false,this);
                        this.formHandler.register_onchange_field('#profile-control input',function(srcElt,self) {self.submitAllForm("profile-control" , self);},false,this);
                        this.registerGenericOnchangeOneField('#category_oid-control select','category_oid','category_oid-control',this);
                        this.formHandler.register_onchange_field('#years_of_practice-control input',function(srcElt,self) {self.submitAllForm("years_of_practice-control" , self);},false,this);
                        this.formHandler.register_onchange_field('#bachelor_year-control select',this.onchange_bachelor_year,false,this);
                         /* this.formHandler.register_onchange_field('.pm-bx-subform-wrapper textarea',
                         function(srcElt,self) {self.submitAllForm(false , self,srcElt);},false,this); */

                        this.registerGenericOnchange('.pm-bx-subform-wrapper textarea');
                        this.registerGenericOnchange('.pm-bx-subform-wrapper select');
                        this.registerGenericOnchange('.pm-bx-subform-wrapper input');

                        this.formHandler.register_onchange_field('#available_vacancies-control select' , this.onchange_available_vacancies , true , this);



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


            sendFormByField:function(record , fieldControl , self)
            {
                var http = new XMLHttpRequest();
                var url = edit_url+"&record="+record;
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
                document.getElementById('available_from-control-wrapper').style.visibility="hidden";
                if(self.formHandler.getFieldValue(self.formHandler.getField('available_delai')) == 'date'){
                    document.getElementById('available_from-control-wrapper').style.visibility="visible";
                }else{
                    document.getElementById('available_from-control-wrapper').style.visibility="hidden";
                }
                self.submitAllForm("available_delai-control" , self);

            },

            onchange_available_vacancies:function(srcElt,self) {

                if(self.count_vacancies == 1){
                    if(self.formHandler.getFieldValue(self.formHandler.getField('available_vacancies')) == '?'){
                        document.getElementById('association_button').style.visibility = 'hidden'
                    }else{
                        document.getElementById('association_button').style.visibility = 'visible'
                    }
                    //Modalbox.show(null,{overlayClose: false});
                    //associateToVacancy('available_vacancies-control', 'available_vacancies', 'associate-to-vacancy');
                }else{ self.count_vacancies ++; }

            },

            onchange_last_name:function(srcElt,self){
                if( self.last_name_value != self.formHandler.getFieldValue(self.formHandler.getField('last_name'))){
                    self.sendFormByField("last_name" , "last_name-control"  , self);
                }

            },

            onchange_first_name:function(srcElt,self){
                if(self.first_name_value != self.formHandler.getFieldValue(self.formHandler.getField('first_name'))){
                    self.sendFormByField("first_name" , "first_name-control"  , self);
                }

            },

            onchange_date_of_birth:function(srcElt,self){
                if(self.date_of_birth_value != self.formHandler.getFieldValue(self.formHandler.getField('date_of_birth'))){
                    self.sendFormByField("date_of_birth" , "date_of_birth-control"  , self);
                }

            },

            onchange_nationality:function(srcElt,self){
                if(self.nationality_value != self.formHandler.getFieldValue(self.formHandler.getField('nationality'))){
                    self.sendFormByField("nationality" , "nationality-control"  , self);
                }

            },

            onchange_studies_level:function(srcElt,self){
                if(self.studies_level_value != self.formHandler.getFieldValue(self.formHandler.getField('studies_level'))){
                    self.sendFormByField("studies_level" , "studies_level-control"  , self);
                }

            },

            onchange_email:function(srcElt,self){
                if(self.email_value != self.formHandler.getFieldValue(self.formHandler.getField('email'))){
                    self.sendFormByField("email" , "email-control"  , self);
                }

            },

            onchange_mobile:function(srcElt,self){
                if(self.mobile_value != self.formHandler.getFieldValue(self.formHandler.getField('mobile'))){
                    self.sendFormByField("mobile" , "mobile-control"  , self);
                }

            },

            onchange_phone1:function(srcElt,self){
                if(self.phone1_value != self.formHandler.getFieldValue(self.formHandler.getField('phone_1'))){
                    self.sendFormByField("phone_1" , "phone_1-control"  , self);
                }

            },

            onchange_phone2:function(srcElt,self){
                if(self.phone2_value != self.formHandler.getFieldValue(self.formHandler.getField('phone_2'))){
                    self.sendFormByField("phone_2" , "phone_2-control"  , self);
                }

            },

            onchange_zip:function(srcElt,self)
            {
                if(self.zip_value != self.formHandler.getFieldValue(self.formHandler.getField('zip')))
                {
                    self.sendFormByField("zip" , "zip-control"  , self);
                }

            },

            onchange_town_oid:function(srcElt,self){
                if(self.town_oid_value != self.formHandler.getFieldValue(self.formHandler.getField('town_oid'))){
                    self.sendFormByField("town_oid" , "town_oid-control"  , self);
                }

            },

            // FY
            onchange_sf_generic:function(srcElt,self) {self.submitAllForm("establishment-control" , self);},

            onchange_sources:function(srcElt,self) {
                self.submitAllForm("sources-control" , self);
            },
            onchange_application_type:function(srcElt,self) {
                self.submitAllForm("application_type-control" , self );
            },
            onchange_bachelor_year:function(srcElt,self) {
                self.submitAllForm("bachelor_year-control" , self);
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

            updateProgress:function(fieldControl, srcElt, evt){
                this.changeControlColor(fieldControl, srcElt, "#FFFF80");
            },

            transfertComplete:function(fieldControl, srcElt , evt){
                var self = this;
                setTimeout(function()
                {
                    self.changeControlColor(fieldControl, srcElt, "");
                },500);
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
            }

        });

    window.formObj = new window.Generis.form_candidate(window.content_form_handler);

} // end