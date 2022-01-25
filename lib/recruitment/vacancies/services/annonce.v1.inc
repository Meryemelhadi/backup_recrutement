<?php 

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');

class lib_recruitment_vacancies_services_annonce
{
	var $ctxt;

	function lib_recruitment_vacancies_services_annonce($ctxt)
	{
		$this->ctxt = $ctxt;
		Framework::setContext($this->ctxt = $ctxt);
	}
	
	function loadRecord() {
		
	}

	function getConfig() {
		if ($this->config)
			return $this->config;
		include_once(NX_LIB.'NxConfig.inc');
		return $this->config = NxConfig::getConfig($this->ctxt,'recruitment','providers','recruitment');
		
   	}
	
	
	function postJobBoard($record)
	{
		//$providerName = $record->provider_oid->string;
        $providerName="reckrute";
		// get section for our provider
		$mainConf = $this->getConfig();
        
		if (!($providersConf = $mainConf->getSection($providerName)))  
			return false;

		// check if account is active
		if (!$providersConf->getProperty('active',true))
			return false;
		$path = $providersConf->getProperty('jobs_board.files.tmp_path',GENERIS_PACKAGES.'recruitment/tmp/');
		
		// generate XML file
		$xmlType = $providersConf->getProperty('job_board.xml_format','reckrute');
		$fxml = 'getXML_'.$xmlType;
		$fpath = $this->$fxml($providersConf,$path, $record);
        $str= explode("/",$fpath);
		$fname=$str[count($str)-1];

		Switch($providersConf->getProperty('job_board.method','ftp'))
		{
			case 'ftp':
				$this->upload_ftp($providersConf,$path,$fname);
				break;
		}
	}

	function getXML_reckrute($conf, $path, $record) {

        $salt = md5(time()); 
		$ref=$record->reference;
		$intit=$record->intitule;
		$of=$record->typeoffre->html;
		$reponse=$record->typereponses->html;
		$contrat=$record->codeContrat->value;
		$experience=$record->codeExperience->value;
		$education=$record->codeEducation->value;


		$docXML=new DomDocument('1.0','iso-8859-1');  
		
		$clients=$docXML->createElement("Clients");

		$client=$docXML->createElement("Client");     

		$nomRekrute=$docXML->createElement("nomRekrute"); 

		$nomRekrute->nodeValue="Lydec";
		
		$offres=$docXML->createElement("Offres");

		$offre=$docXML->createElement("Offre");

		$identifiantEntreprise=$docXML->createElement("IdentifiantEntreprise");

		$identifiantEntreprise->nodeValue="16460";

		$reference=$docXML->createElement("reference");

		$reference->nodeValue="".$ref;

		$intitule=$docXML->createElement("intitule");

		$intitule->nodeValue="".$intit;

		$typeOffre=$docXML->createElement("typeOffre");

		$typeOffre->nodeValue="".$of;

		$typeReponse=$docXML->createElement("typeReponse");

		$typeReponse->nodeValue="".$reponse;

		$entreprise=$docXML->createElement("entreprise");

		$codeContrat=$docXML->createElement("codeContrat");

		$codeContrat->nodeValue=$contrat;

		$codeExperience=$docXML->createElement("codeExperience");

		$codeExperience->nodeValue="".$experience;

		$codeEducation=$docXML->createElement("codeEducation");

		$codeEducation->nodeValue="".$education;

		$salaire=$docXML->createElement("salaire");

		$salaire->nodeValue="".$record->salaire->value;

		$descriptionEntreprise=$docXML->createElement("descriptionEntreprise");

		$descriptionEntreprise->nodeValue=strtr($record->descriptionEntreprise, get_html_translation_table(HTML_ENTITIES, ENT_QUOTES));

		$descriptionPoste=$docXML->createElement("descriptionPoste");

		$descriptionPoste->nodeValue=strtr($record->descriptionPoste, get_html_translation_table(HTML_ENTITIES, ENT_QUOTES));

		$descriptionProfil=$docXML->createElement("descriptionProfil");

		$descriptionProfil->nodeValue=strtr($record->descriptionProfil, get_html_translation_table(HTML_ENTITIES, ENT_QUOTES));

		$date=$docXML->createElement("date");

		$date->nodeValue="".$record->date;

		$duree=$docXML->createElement("duree");

		$duree->nodeValue="".$record->duree;

		$contactMail=$docXML->createElement("contactMail");

		$contactMail->nodeValue="".$record->contactMail;

		$typeAlerte=$docXML->createElement("typeAlerte");

		$typeAlerte->nodeValue="".$record->typeAlerte->value;

		$lien=$docXML->createElement("lien");

		$lien->nodeValue="".$record->lien;

		$codePaysVisibilite=$docXML->createElement("codePaysVisibilite");

		$codePaysVisibilite->nodeValue="1";

		$codePays=$docXML->createElement("codePays");

		$codePays->nodeValue="134";

		$codeRegion=$docXML->createElement("codeRegion");

		$codeRegion->nodeValue="".$record->codeRegion->value;

		$ville=$docXML->createElement("ville");

		$ville->nodeValue="".$record->ville->value;

		$codeSecteur=$docXML->createElement("codeSecteur");

		$codeSecteur->nodeValue="".$record->codeSecteur->value;

		$codeFonction1=$docXML->createElement("codeFonction1");

		$codeFonction1->nodeValue="".$record->codeFonction1->value;

		$codeFonction2=$docXML->createElement("codeFonction2");

		$codeFonction2->nodeValue="".$record->codeFonction2->value;

		$codeLangue1=$docXML->createElement("codeLangue1");

		$codeLangue1->nodeValue="".$record->codeLangue1->value;

		$codeLangue2=$docXML->createElement("codeLangue2");

		$codeLangue2->nodeValue="".$record->codeLangue2->value;


		$cadre=$docXML->createElement("cadre");

		$cadre->nodeValue="".$record->cadre->value;

		$nombrePoste=$docXML->createElement("nombrePoste");

		$nombrePoste->nodeValue="".$record->nombrePoste;

		$startDate=$docXML->createElement("startDate");

		$startDate->nodeValue="".$record->startDate;

		$endDate=$docXML->createElement("endDate");

		$endDate->nodeValue="".$record->endDate;

		//**********

		$docXML->appendChild($clients);  
		
		$clients->appendChild($client);

		$client->appendChild($nomRekrute);

		$client->appendChild($offres);

		$offres->appendChild($offre);

		$offre->appendChild($identifiantEntreprise);

		$offre->appendChild($reference);

		$offre->appendChild($intitule);

		$offre->appendChild($typeOffre);

		$offre->appendChild($typeReponse);

		$offre->appendChild($entreprise);

		$offre->appendChild($codeContrat);

		$offre->appendChild($codeExperience);

		$offre->appendChild($codeEducation);

		$offre->appendChild($salaire);
		
		$offre->appendChild($descriptionEntreprise);

		$offre->appendChild($descriptionProfil);

		$offre->appendChild($date);

		$offre->appendChild($duree);

		$offre->appendChild($contactMail);

		$offre->appendChild($typeAlerte);

		$offre->appendChild($lien);

		$offre->appendChild($codePaysVisibilite);

		$offre->appendChild($codePays);

		$offre->appendChild($codeRegion);

		$offre->appendChild($ville);
		
		$offre->appendChild($codeSecteur);

		$offre->appendChild($codeFonction1);

		$offre->appendChild($codeFonction2);

		$offre->appendChild($codeLangue1);

		$offre->appendChild($codeLangue2);

		$offre->appendChild($cadre);

		$offre->appendChild($nombrePoste);

		$offre->appendChild($startDate);

		$offre->appendChild($endDate);

		$fpath = $path."annonce_{$intit}_{$salt}.xml";

		$docXML->save($fpath);

		return $fpath;
	}

	function upload_ftp($conf,$path,$fname) {
		if (
			!($host =  $conf->getProperty('job_board.ftp.host','lydec.presencemedia.ma')) ||
			!($user =  $conf->getProperty('job_board.ftp.user','melftp.lydec')) ||
			!($password =  $conf->getProperty('job_board.ftp.password','_z2naGQG'))
			)
			{
				nxError('param missing in recruitment job posting','RECRUITMENT');
				return false;
			}
			
			//$port =  $conf->getProperty('job_board.ftp.port','21');
			$dir =  $conf->getProperty('job_board.ftp.dir','/home/presencemedia/domains/intranet.presencemedia.ma/public_html/intranet/generis2011/packages/recruitment/tmp/');
			
			$conn_id = ftp_connect($host);

			ftp_login($conn_id, $user, $password);

			$p = $conf->getProperty('jobs_board.files.tmp_path',GENERIS_PACKAGES.'recruitment/tmp/');

			ftp_nb_put($conn_id, $dir."".$fname, $p."".$fname ,FTP_BINARY);

		}
	}