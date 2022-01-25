<?php

$forms = array(
    'record' => array(
        'tabs' => array(
            'cv' => array(
                'title' => "cv",
                'fields' => array(
                    "preview"=>"cv_path"
                    //"first_name"
                )
            ),
            'recruitement card' => array(
                'title' => "recruitement card",
                'columns' => array(
                    array
                    (
                        'groups' => array
                        (
                            'comments' => array
                            (
                                'title'=>'comments',
                                'fields' => array
                                (
                                    "oid",
                                    "add_comment_zone"

                                ),

                            ),

                            /*'title_salary_package' => array
                            (
                                'title'=>'title_salary_package',
                                'fields' => array
                                (
                                    "current_salary",
                                    "desired_salary"

                                ),

                            )*/


                        ),

                    ),
                    array
                    (
                        'groups' => array
                        (
                            array(
                                'fields' => array
                                (
                                    "experiences",
                                    "qualifications"

                                ),

                            ),
                            'title_leaving_period' => array
                            (
                                'title'=>'title_leaving_period',
                                'fields' => array
                                (
                                    "leaving_period"

                                ),

                            )

                        ),

                    )

                )

            ),
            'general_infos' => array(
                'title' => "general_infos",
                'columns' => array(
                    array
                    (
                        'groups' => array
                        (
                            'Informations sur le profil' => array
                            (
                                'title'=>'Informations sur le profil',
                                'fields' => array
                                (
                                    "oid",
                                    "first_name",
                                    "last_name",
                                    "civility",
                                    "gender",
                                    "date_of_birth",
                                    "nationality"

                                ),

                            ),

                            'Informations sur le candidat' => array
                            (
                                'title'=>'Informations sur le candidat',
                                'fields' => array
                                (
                                    "studies_level"

                                ),

                            )


                        ),

                    ),
                    array
                    (
                        'groups' => array
                        (

                            'Coordonnées' => array
                            (
                                'title'=>'Coordonnées',
                                'fields' => array
                                (
                                    "email",
                                    "mobile",
                                    "phone_1",
                                    "phone_2",
                                    "zip",
                                    "country_oid",
                                    "town_oid"

                                ),

                            )

                        ),

                    )

                )

            ),
            'education_infos' => array(
                'title' => "education_infos",
                'columns' => array(
                    array
                    (
                        'groups' => array
                        (
                            'Diplômes' => array
                            (
                                'title'=>'Diplômes',
                                'fields' => array
                                (
                                    "education_entries"

                                ),

                            ),

                            'Baccalauréat' => array
                            (
                                'title'=>'Baccalauréat',
                                'fields' => array
                                (
                                    "bachelor_year"

                                ),

                            )


                        ),

                    ),
                    array
                    (
                        'groups' => array
                        (
                            'Langues' => array
                            (
                                'title'=>'Langues',
                                'fields' => array
                                (
                                    "language_entries"

                                ),

                            ),
                            'Formations et certifications' => array
                            (
                                'title'=>'Formations et certifications',
                                'fields' => array
                                (
                                    "education_entries_2"

                                ),

                            )

                        ),

                    )

                )

            ),
            'experiences' => array(
                'title' => "experiences",
                'columns' => array(
                    array
                    (
                        'groups' => array
                        (
                            'Expérience professionnelle' => array
                            (
                                'title'=>'Expérience professionnelle',
                                'fields' => array
                                (
                                    "employment_entries"

                                ),

                            ),

                        ),

                    ),
                    array
                    (
                        'groups' => array
                        (
                            'Stages' => array
                            (
                                'title'=>'Stages',
                                'fields' => array
                                (
                                    "training_entries"

                                ),

                            )

                        ),

                    )

                )

            ),
            'emails' => array(
                'title' => "emails",
                'fields' => array(
                    //"preview"=>"cv_path"
                    "emails"
                )
                /*'columns' => array(
                    array
                    (
                        'groups' => array
                        (
                            'title_interview_summary' => array
                            (
                                'title'=>'title_interview_summary',
                                'fields' => array
                                (
                                    "oid",
                                    "education",
                                    "motivations"

                                ),

                            ),

                            'title_salary_package' => array
                            (
                                'title'=>'title_salary_package',
                                'fields' => array
                                (
                                    "current_salary",
                                    "desired_salary"

                                ),

                            )


                        ),

                    ),
                    array
                    (
                        'groups' => array
                        (
                            array(
                                'fields' => array
                                (
                                    "experiences",
                                    "qualifications"

                                ),

                            ),
                            'title_leaving_period' => array
                            (
                                'title'=>'title_leaving_period',
                                'fields' => array
                                (
                                    "leaving_period"

                                ),

                            )

                        ),

                    )

                )*/

            ),

        )
    ),

);