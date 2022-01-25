<?php
$properties=array(

	// list of clients , with default values if client not defined

	// EVASOL
	'evasol.presencesoft.com' => array(
		
		'email.from'=>'recrutement@evasol.fr', 
		'send.notifications'=>true, 

		'RECRUITMENT_MAILHTML' => "<p>Nous accusons réception de votre candidature.</p>
	<p>Votre dossier sera examiné dans un délai de 3 semaines. Si votre dossier est
retenu, vous serez contacté par téléphone. Dans l'hypothèse contraire, veuillez
considérer que votre candidature n'est pas retenue. En l'absence de contact et
sauf désaccord écrit de votre part, nous nous permettons de conserver votre
dossier pour répondre à d'éventuels postes à venir.</p>
<p>Vous remerciant par avance, nous vous prions de recevoir nos sentiments les
meilleurs.</p>
<p>Conformément aux dispositions légales (Article 34 de la loi \"Informatique
et Libertés\" ) relatives au droit d'accès, de modification, de rectification et
d'opposition aux fichiers informatiques, la Direction du Recrutement peut,
à votre demande, vous permettre de vérifier et de rectifier le contenu des
informations vous concernant.</p>
<p>Le service Ressources Humaines</p>",
	),

	// EDITIALIS
	'editialis.presencerecrute.com' => array(
		
		'email.from'=>'recrutement@editialis.fr', 
		'send.notifications'=>true, 
		'RECRUITMENT_MAILHTML' => "

<p>Nous avons bien reçu votre dossier de candidature et nous vous remercions de la confiance que vous nous témoignez en nous adressant votre dossier.</p>
<p>Nous procédons à l'heure actuelle à son examen approfondi. Si nous l'estimons susceptible de correspondre au profil recherché, nous ne manquerons pas de vous contacter dans un délai d’un mois afin de vous fixer un rendez-vous.</p>
<p>Sans réponse de notre part passé ce délai, cet accusé de réception tiendra lieu de réponse négative. Nous vous proposons de conserver votre curriculum vitae (6 mois) afin de pouvoir, le cas échéant, vous recontacter dans le cadre d'une autre recherche. N’hésitez pas à renouveler votre candidature si l’une de nos prochaines offres d’emploi retenait votre attention.</p>
<p>Vous souhaitant bonne réception de la présente, nous vous prions d'agréer, Madame, Monsieur, l'expression de nos cordiales salutations.</p>
<p>Cordialement</p>
<p>Le service des ressources humaines</p>",
	),


	// SGTM
//	'sgtm.presencerecrute.com' => array(
	'www.access.ads' => array(
		
		'email.from'=>'drh@sgtm-maroc.com', 
		'send.notifications'=>true, 
		'email_view' => 'recruitment.emails.tpl_new_candidate_email_default@recruitment',
		'new_candidate_email_subject'=>'Accusé de réception de candidature',

		'RECRUITMENT_MAILHTML' => <<<EOM
      
<p style="text-align:justify"><span style="font-size:10.0pt;font-family:Arial">De prime abord, nous tenons à vous remercier pour la confiance que vous nous avez témoignée en nous adressant votre candidature spontanée. A cet effet, nous vous informons que nous examinons actuellement votre candidature avec le plus grand soin et en toute confidentialité. <u></u><u></u></span></p>
<p style="text-align:justify"><span style="font-size:10.0pt;font-family:Arial">Ainsi, si elle correspond à un poste à pourvoir, un de nos responsables prendra contact avec vous afin de vous rencontrer. Autrement, elle sera gardée dans notre vivier candidatures et consultée régulièrement pas nos responsables recrutement pour des ouvertures à venir.<u></u><u></u></span></p>
<p style="text-align:justify"><span style="font-size:10.0pt;font-family:Arial">D’autre part et afin de tenir à jour vos coordonnées et profils, nous vous prions de nous aviser pour tout changement de votre situation à l’adresse e-mail : </span><a href="mailto:drh@sgtm-maroc.com" title="blocked::mailto:drh@sgtm-maroc.com" target="_blank"><span style="font-size:10.0pt;font-family:Arial">drh@sgtm-maroc.com</span></a><span style="font-size:10.0pt;font-family:Arial"><u></u><u></u></span></p>
<p style="text-align:justify"><span style="font-size:10.0pt;font-family:Arial">En vous réitérant nos remerciements pour l’intérêt que vous
portez à la SGTM, nous vous prions d’agréer l’expression de nos salutations les
meilleures. <u></u><u></u></span></p>
<p class="MsoNormal"><span style="">Cordialement<u></u><u></u></span></p>
<p class="MsoNormal"><span style=""><u></u>&nbsp;<u></u></span></p>
<p class="MsoNormal"><span style="font-size:10.0pt;line-height:115%;font-family:Arial;color:#999999">Direction des Ressources Humaines &amp; Organisation</span><span style=""> <u></u><u></u></span></p>
<p class="MsoNormal"><b><i><span style="font-size:10.0pt;line-height:115%;font-family:Arial;color:#999999">SGTM</span></i></b><span style="color:navy"> <u></u><u></u></span></p>
<p class="MsoNormal"><span style="font-size:8.0pt;line-height:115%;"><u></u>&nbsp;<u></u></span></p>
<p class="MsoNormal"><span style="font-size:10.0pt;line-height:115%;font-family:Arial">Email : <a href="mailto:drh@sgtm-maroc.com" target="_blank">drh@sgtm-maroc.com</a><u></u><u></u></span></p>
<p class="MsoNormal"><span style="font-size:10.0pt;line-height:115%;font-family:Arial">Tél : <a href="tel:%2B212%20%2805%2922.888.000" value="+212522888000" target="_blank">+212 (05)22.888.000</a> à 022.888.003<br>
Fax : +212 (05) 32.05.69 / 022 32.02.77<br>
</span><i><span style="font-size:10.0pt;line-height:115%;font-family:Arial;color:#999999"><br>
<em>Consultez notre site Web </em></span></i><em><b><span style="font-size:10.0pt;line-height:115%;font-family:Arial;font-style:normal">:</span></b></em><b><i><span style="font-size:10.0pt;line-height:115%;font-family:Arial;"> </span></i></b><a href="http://www.sgtm-maroc.com" target="_blank"><b><i><span style="font-size:10.0pt;line-height:115%;font-family:Arial">http://www.sgtm-maroc.com</span></i></b></a><span style="color:navy"> </span><span style="font-size:12.0pt;line-height:115%;color:navy"><u></u><u></u></span></p>

<p class="MsoNormal"><b><i><span style="font-size:10.0pt;line-height:115%;font-family:Arial;">Constructeur de valeur</span></i></b></p>

EOM
	),


	// Pyxicom
	'pyxicom.presencesoft.com' => array(
		
		'send.notifications'=>true, 
		'email.from'=>'contact@pyxicom.com',
		),


	// EVASOL test
	'www.access.evasol' => array(
		
		'send.notifications'=>true, 

		'RECRUITMENT_MAILHTML' => "<p>Nous accusons réception de votre candidature.</p>
	<p>Votre dossier sera examiné dans un délai de 3 semaines. Si votre dossier est
retenu, vous serez contacté par téléphone. Dans l'hypothèse contraire, veuillez
considérer que votre candidature n'est pas retenue. En l'absence de contact et
sauf désaccord écrit de votre part, nous nous permettons de conserver votre
dossier pour répondre à d'éventuels postes à venir.</p>
<p>Vous remerciant par avance, nous vous prions de recevoir nos sentiments les
meilleurs.</p>
<p>Conformément aux dispositions légales (Article 34 de la loi \"Informatique
et Libertés\" ) relatives au droit d'accès, de modification, de rectification et
d'opposition aux fichiers informatiques, la Direction du Recrutement peut,
à votre demande, vous permettre de vérifier et de rectifier le contenu des
informations vous concernant.</p>
<p>Le service Ressources Humaines</p>",

		),

	// SGTM
	'sgtm.presencerecrute.com' => array(
//	'www.access.ads' => array(
		
		'email.from'=>'drh@sgtm-maroc.com', 
		'send.notifications'=>true,

		'email_view' => 'recruitment.emails.tpl_new_candidate_email_default@recruitment',
		'new_candidate_email_subject'=>'Accusé de réception de candidature',

		'RECRUITMENT_MAILHTML' => <<<EOM
        
<p style="text-align:justify"><span style="font-size:10.0pt;font-family:Arial">De prime abord, nous tenons à vous remercier pour la confiance que vous nous avez témoignée en nous adressant votre candidature spontanée. A cet effet, nous vous informons que nous examinons actuellement votre candidature avec le plus grand soin et en toute confidentialité. <u></u><u></u></span></p>
<p style="text-align:justify"><span style="font-size:10.0pt;font-family:Arial">Ainsi, si elle correspond à un poste à pourvoir, un de nos responsables prendra contact avec vous afin de vous rencontrer. Autrement, elle sera gardée dans notre vivier candidatures et consultée régulièrement pas nos responsables recrutement pour des ouvertures à venir.<u></u><u></u></span></p>
<p style="text-align:justify"><span style="font-size:10.0pt;font-family:Arial">D’autre part et afin de tenir à jour vos coordonnées et profils, nous vous prions de nous aviser pour tout changement de votre situation à l’adresse e-mail : </span><a href="mailto:drh@sgtm-maroc.com" title="blocked::mailto:drh@sgtm-maroc.com" target="_blank"><span style="font-size:10.0pt;font-family:Arial">drh@sgtm-maroc.com</span></a><span style="font-size:10.0pt;font-family:Arial"><u></u><u></u></span></p>
<p style="text-align:justify"><span style="font-size:10.0pt;font-family:Arial">En vous réitérant nos remerciements pour l’intérêt que vous
portez à la SGTM, nous vous prions d’agréer l’expression de nos salutations les
meilleures. <u></u><u></u></span></p>
<p class="MsoNormal"><span style="">Cordialement<u></u><u></u></span></p>
<p class="MsoNormal"><span style=""><u></u>&nbsp;<u></u></span></p>
<p class="MsoNormal"><span style="font-size:10.0pt;line-height:115%;font-family:Arial;color:#999999">Direction des Ressources Humaines &amp; Organisation</span><span style=""> <u></u><u></u></span></p>
<p class="MsoNormal"><b><i><span style="font-size:10.0pt;line-height:115%;font-family:Arial;color:#999999">SGTM</span></i></b><span style="color:navy"> <u></u><u></u></span></p>
<p class="MsoNormal"><span style="font-size:8.0pt;line-height:115%;"><u></u>&nbsp;<u></u></span></p>
<p class="MsoNormal"><span style="font-size:10.0pt;line-height:115%;font-family:Arial">Email : <a href="mailto:drh@sgtm-maroc.com" target="_blank">drh@sgtm-maroc.com</a><u></u><u></u></span></p>
<p class="MsoNormal"><span style="font-size:10.0pt;line-height:115%;font-family:Arial">Tél : <a href="tel:%2B212%20%2805%2922.888.000" value="+212522888000" target="_blank">+212 (05)22.888.000</a> à 022.888.003<br>
Fax : +212 (05) 32.05.69 / 022 32.02.77<br>
</span><i><span style="font-size:10.0pt;line-height:115%;font-family:Arial;color:#999999"><br>
<em>Consultez notre site Web </em></span></i><em><b><span style="font-size:10.0pt;line-height:115%;font-family:Arial;font-style:normal">:</span></b></em><b><i><span style="font-size:10.0pt;line-height:115%;font-family:Arial;"> </span></i></b><a href="http://www.sgtm-maroc.com" target="_blank"><b><i><span style="font-size:10.0pt;line-height:115%;font-family:Arial">http://www.sgtm-maroc.com</span></i></b></a><span style="color:navy"> </span><span style="font-size:12.0pt;line-height:115%;color:navy"><u></u><u></u></span></p>

<p class="MsoNormal"><b><i><span style="font-size:10.0pt;line-height:115%;font-family:Arial;">Constructeur de valeur</span></i></b></p>

EOM
	),


	// Default EMAIL SETTINGS
	'send.notifications'=>true, 
	'email_view' => 'recruitment.emails.tpl_new_candidate_email_default@recruitment',
	'new_candidate_email_subject' => __('new_candidate_email_subject'),
	'RECRUITMENT_MAILTITLE'    =>$GLOBALS['RECRUITMENT_MAILTITLE'],
	'RECRUITMENT_MAILSUBTITLE' => $GLOBALS['RECRUITMENT_MAILSUBTITLE'],
	'RECRUITMENT_MAILHTML' => 
		"<p>Nous avons bien reçu votre candidature et nous vous remercions de l'intérêt que vous portez à notre société.</p><p>Nous allons étudier avec le plus grand soin votre candidature</p><p>Service Ressources Humaines,</p>",
);

?>