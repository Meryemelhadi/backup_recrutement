if(typeof PMDH != 'undefined')
{
    PMDH.registerNS('Generis.form_interview');

    // if(typeof Prototype.Version == "undefined")	window.$$ = window.$; // jQuery compatibility

    Generis.form_interview = PMDH.createClass(
        {
            // constructor
            initialize : function(formId,addMode) {
                try
                {
                    var self = this;
                    this.addMode = addMode;
                    this.initTime = false;

                    // get form
                    this.form = document.getElementById(formId);
                    if(!this.form)
                    {
                        ajax_log('formulaire non trouvé id='+formId);
                        return;
                    }

                    // add form handler
                    this.formHandler = new window.Generis.Forms(this.form);

                    // add onchange handlers
                    this.formHandler.register_onchange_field('#time_start-control select',this.onchange_time,true,this);
                    this.formHandler.register_onchange_field('#time_end-control select',this.onchange_time,true,this);

                    // add file attachments
                    // Generis.Recruitment.appendAssocFilesHandlers('interviewers','file_attachement_interviewers');
                    // Generis.Recruitment.appendAssocFilesHandlers('candidate','file_attachement_candidate');

                    // manage display of candidate email
                    if(!addMode) {
                        this.initEmailsState();
                    }

                    // manage email sample for candidate
                    var emailSamplerCandidate = Generis.Recruitment.emailSampleHandler
                    (
                        {
                            fieldname: 'default_email',
                            element: 'email-candidate-wrapper',
                            emailTitleField: 'email_title',
                            emailContentField:'email_content',
                            emailDocs:'email_docs',
                            url: '/recruitment/vacancies/admin/directory.php?nxo=get_email_sample',
                            formHandler:this.formHandler
                        }
                    );

                    // manage email sample for interviewer
                    var emailSamplerInterviewer = Generis.Recruitment.emailSampleHandler
                    (
                        {
                            fieldname: 'user_default_email',
                            element: 'email-interviewer-wrapper',
                            emailTitleField: 'user_email_title',
                            emailContentField:'user_email_content',
                            emailDocs:'user_email_docs',
                            url: '/recruitment/vacancies/admin/directory.php?nxo=get_email_sample',
                            formHandler:this.formHandler
                        }
                    );

                    // not sent
                    document.getElementById("candidate_email_not1").onchange=function() {
                        self.showEmailCand(false);
                    };

                    // resend
                    document.getElementById("candidate_email_not2").onchange=function() {
                        self.showEmailCand(true);
                        emailSamplerCandidate.autoLoadIfOneChoice();
                    };

                    // already sent
                    if(!addMode) {
                        document.getElementById("candidate_email_not3").onchange=function() {
                            self.showEmailCand(true);
                            emailSamplerCandidate.autoLoadIfOneChoice();
                        };
                    }

                    // manage display of interviewer email
                    document.getElementById("interviewer_email_not1").onchange=function() {
                        self.showEmailUser(false);
                        //self.showCancelButton(false);
                    };

                    document.getElementById("interviewer_email_not2").onchange=function() {
                        self.showEmailUser(true);
                        emailSamplerInterviewer.autoLoadIfOneChoice();
                    };

                    if(!addMode) {
                        document.getElementById("interviewer_email_not3").onchange=function() {
                            self.showEmailUser(true);
                            //self.showCancelButton(true);
                            emailSamplerInterviewer.autoLoadIfOneChoice();
                        };
                    }
                }
                catch (e)
                {
                    ajax_log("Exception "+e);
                }
            },

            initEmailsState:function() {
                // NOT 1 : not sent, NOT 2: already sent, NOT 3 : send again

                if(document.getElementById("candidate_email_not2").checked ||
                    document.getElementById("candidate_email_not3").checked)
                {
                    // display candidate email
                    document.getElementById("candidate_email_not3").checked=true;

                    this.showEmailCand(true);
                }

                if(document.getElementById("interviewer_email_not2").checked ||
                    document.getElementById("interviewer_email_not3").checked)
                {
                    // display recruiter email
                    document.getElementById("interviewer_email_not3").checked=true;

                    this.showEmailUser(true);
                    this.showCancelButton(true);
                }
            },

            showCancelButton:function(show) {
                var btn = $('cancel_button');
                if(!btn)
                    return;

                if(show)
                {
                    btn.show();
                    $('cancel_button_sep').show();
                }
                else
                {
                    btn.hide();
                    $('cancel_button_sep').hide();
                }
            },

            showEmailCand:function(show) {
                var display = show? 'block':'none';

                document.getElementById("default_email_div").style.display=display;
                document.getElementById("email_title_div").style.display=display;
                document.getElementById("email_content_div").style.display=display;
                document.getElementById("email_docs_div").style.display=display;
                document.getElementById("attached_files_candidate_div").style.display=display;
            },
            showEmailUser:function(show) {
                var display = show? 'block':'none';

                document.getElementById("user_default_email_div").style.display=display;
                document.getElementById("user_email_content_div").style.display=display;
                document.getElementById("user_email_docs_div").style.display=display;
                document.getElementById("user_email_title_div").style.display=display;
                document.getElementById("attached_files_interviewer_div").style.display=display;
            },

            // ============ ONCHANGE HANDLERS ===============

            // onchange handler for postponed_invest_name field
            onchange_time:function(srcElt,self)
            {
                ajax_log("changed time");

                // start date
                var fstart_h=self.formHandler.getField('time_start_h');
                var start_h=parseInt(self.formHandler.getFieldValue(fstart_h));

                // minutes
                var fstart_mn=self.formHandler.getField('time_start_mn');
                var vstart_mn=self.formHandler.getFieldValue(fstart_mn);
                var start_mn;
                if(vstart_mn=='?'||vstart_mn==0||(self.addMode && !this.initTime))
                {
                    start_mn=0;
                    self.formHandler.setFieldValue(fstart_mn,start_mn);
                    this.initTime = true;
                }
                else
                    start_mn=parseInt(vstart_mn);

                // end date
                var fend_h=self.formHandler.getField('time_end_h');
                var vend_h=self.formHandler.getFieldValue(fend_h);

                var end_h;
                if(vend_h=='?'||vend_h==0)
                {
                    end_h=0;
                    self.formHandler.setFieldValue(fend_h,'10');
                }
                else
                {
                    end_h=parseInt(vend_h);
                }

                var fend_mn=self.formHandler.getField('time_end_mn');
                var vend_mn=self.formHandler.getFieldValue(fend_mn);

                var end_mn;
                if(vend_mn=='?'||vend_mn==0)
                {
                    end_mn=0;
                    self.formHandler.setFieldValue(fend_mn,end_mn);
                }
                else
                {
                    end_mn=parseInt(vend_mn);
                }

                if(srcElt == fstart_h || srcElt == fstart_mn)
                {
                    // if start hour changed, change end hour
                    if((end_h <= start_h) || (end_h > start_h+1) || (end_h == start_h+1))
                    {
                        end_h=start_h;
                        self.formHandler.setFieldValue(fend_h,end_h);

                        if(end_h == start_h && end_mn < start_mn+60)
                        {
                            // allow 40 mn meeting time
                            end_mn=start_mn+60;

                            if(end_mn > 59)
                            {
                                end_mn = end_mn - 60;
                                end_h += 1;
                            }

                            if(end_h > 23)
                                end_h=0;

                            self.formHandler.setFieldValue(fend_h,end_h);
                            self.formHandler.setFieldValue(fend_mn,end_mn);
                        }
                    }
                }
            }
        });
}