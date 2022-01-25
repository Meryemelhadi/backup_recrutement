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
        $providerName="rekrute";
		// get section for our provider
		$mainConf = $this->getConfig();
        
		if (!($providersConf = $mainConf->getSection($providerName)))  
			return false;

		// check if account is active
		if (!$providersConf->getProperty('active',true))
			return false;
		$path = $providersConf->getProperty('jobs_board.files.tmp_path',GENERIS_PACKAGES.'recruitment/tmp/');
		
		// generate XML file
		$xmlType = $providersConf->getProperty('job_board.xml_format','rekrute');
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


	function getXML_rekrute($conf, $path, $record) {
		//DebugBreak();  
		$siteDesc =& $GLOBALS['_NX_site'];
		chmod($path, 0777);
		//Le chemin du fichier xml contenant les annonces
		$fpath_utf8 = $path."publication-rekrute-PresenceMedia-utf-8.xml";
		$fpath = $path."publication-rekrute-PresenceMedia.xml";
		$fxml =new DomDocument("1.0","iso-8859-1");
		$fxml->formatOutput = TRUE;

		//vérifier l'existance du fichier
		if(!file_exists($fpath_utf8)) 
		{  
			//L'entête si le fichier n'existe pas
			$clients=$fxml->createElement("Clients");
			$fxml->appendChild($clients);  
		}
		else {
			$fxml->preserveWhiteSpace=false;
			$fxml->load($fpath_utf8);
			$fxml->formatOutput = TRUE;
			$clients=$fxml->getElementsByTagName('Clients')->item(0);
			//gérer les balises vides
			$elements=$fxml->getElementsByTagName('Offre');
			foreach($elements as $element)
			{
				$enfants = $element->childNodes;
					foreach($enfants as $enfant) 
					{
                      if($enfant->nodeValue=="")
						  $enfant->nodeValue="";
					}
			}
			$nomrekrute = $fxml->getElementsByTagName('nomRekrute');
		
			$i=0;
			$found=false;
			foreach($nomrekrute as $nom)
			{
				if($nom->nodeValue==$siteDesc->getProperty('portal.recruitement.profile',''))
				{
					$found=true;
					break 1;
					
				}else {$i++;}	
			}    
		}

		$offre=$fxml->createElement("Offre");

		$identifiantEntreprise=$fxml->createElement("IdentifiantEntreprise");

		$identifiantEntreprise->nodeValue="16460";

		$reference=$fxml->createElement("reference");

		$reference->nodeValue="".$record->reference->value;

		$intitule=$fxml->createElement("intitule");

		$intitule->nodeValue="".$record->intitule->value;

		$typeOffre=$fxml->createElement("typeOffre");

		if($record->typeoffre->value=='?')
			$off='';
		else $off=$record->typeoffre->value;

		$typeOffre->nodeValue="".$off;

		$typeReponse=$fxml->createElement("typeReponse");

		$typeReponse->nodeValue="".$record->typereponses;

		$entreprise=$fxml->createElement("entreprise");

		$entreprise->nodeValue="";

		$codeContrat=$fxml->createElement("codeContrat");

		if($record->codeContrat->value=='?')
			$contrat='';
		else $contrat=$record->codeContrat->value;

		$codeContrat->nodeValue=$contrat;

		$codeExperience=$fxml->createElement("codeExperience");

		if($record->codeExperience->value=='?')
			$experience='';
		else $experience=$record->codeExperience->value;

		$codeExperience->nodeValue="".$experience;

		$codeEducation=$fxml->createElement("codeEducation");

		if($record->codeEducation->value=='?')
			$education='';
		else $education=$record->codeEducation->value;

		$codeEducation->nodeValue="".$education;

		$salaire=$fxml->createElement("salaire");

		if($record->salaire->value=='?')
			$salaire_record='';
		else $salaire_record=$record->salaire->value;

		$salaire->nodeValue="".$salaire_record;


		$descriptionEntreprise=$fxml->createElement("descriptionEntreprise");

		if($record->descriptionEntreprise=='')
			$descriptionEntreprise->nodeValue="";
		else{
			$cdataEntreprise = $fxml->createCDATASection(utf8_encode($record->descriptionEntreprise));

			$descriptionEntreprise->appendChild($cdataEntreprise);
		}

		$descriptionPoste=$fxml->createElement("descriptionPoste");
		if($record->descriptionPoste=='')
			$descriptionPoste->nodeValue="";
		else{
		$cdataPoste = $fxml->createCDATASection(utf8_encode($record->descriptionPoste));

		$descriptionPoste->appendChild($cdataPoste);
		}

		$descriptionProfil=$fxml->createElement("descriptionProfil");

		if($record->descriptionProfil=='')
			$descriptionProfil->nodeValue="";
		else{
		$cdataProfil = $fxml->createCDATASection(utf8_encode($record->descriptionProfil));

		$descriptionProfil->appendChild($cdataProfil);
		}

		$date=$fxml->createElement("date");

		$date->nodeValue="";

		$duree=$fxml->createElement("duree");

		$duree->nodeValue="".$record->duree;

		$contactMail=$fxml->createElement("contactMail");

		$contactMail->nodeValue="".utf8_encode($record->contactMail);

		$typeAlerte=$fxml->createElement("typeAlerte");

		if($record->typeAlerte->value=='?')
			$alerte='';
		else $alerte=$record->typeAlerte->value;

		$typeAlerte->nodeValue="".$alerte;

		$lien=$fxml->createElement("lien");

		$lien->nodeValue="".utf8_encode($record->lien);

		$codePaysVisibilite=$fxml->createElement("codePaysVisibilite");

		$codePaysVisibilite->nodeValue="1";

		$codePays=$fxml->createElement("codePays");

		$codePays->nodeValue="134";

		$codeRegion=$fxml->createElement("codeRegion");

		if($record->codeRegion->value=='?')
			$region='';
		else $region=$record->codeRegion->value;

		$codeRegion->nodeValue="".$region;

		$ville=$fxml->createElement("ville");

		$ville->nodeValue="".$record->ville->value;

		if($record->codeSecteur->value=='?')
			$secteur='';
		else $secteur=$record->codeSecteur->value;

		$codeSecteur=$fxml->createElement("codeSecteur");

		$codeSecteur->nodeValue="".$secteur;

		if($record->codeFonction1->value=='?')
			$fonction1='';
		else $fonction1=$record->codeFonction1->value;

		$codeFonction1=$fxml->createElement("codeFonction1");

		$codeFonction1->nodeValue="".utf8_encode($fonction1);

		$codeFonction2=$fxml->createElement("codeFonction2");

		if($record->codeFonction2->value=='?')
			$fonction2='';
		else $fonction2=$record->codeFonction2->value;

		$codeFonction2->nodeValue="".utf8_encode($fonction2);

		$codeLangue1=$fxml->createElement("codeLangue1");

		if($record->codeLangue1->value=='?')
			$langue1='';
		else $langue1=$record->codeLangue1->value;


		$codeLangue1->nodeValue="".utf8_encode($langue1);

		$codeLangue2=$fxml->createElement("codeLangue2");

		if($record->codeLangue2->value=='?')
			$langue2='';
		else $langue2=$record->codeLangue2->value;

		$codeLangue2->nodeValue="".utf8_encode($langue2);

		$cadre=$fxml->createElement("cadre");

		$cadre->nodeValue="".$record->cadre->value;

		$nombrePoste=$fxml->createElement("nombrePoste");

		$nombrePoste->nodeValue="".$record->nombrePoste;

		$startDate=$fxml->createElement("startDate");

		if($record->startDate=='-/-/-')
			$start='';
		else $start=$record->startDate;
		if($record->endDate=='-/-/-')
			$end='';
		else $end=$record->endDate;

		$startDate->nodeValue="".$start;

		$endDate=$fxml->createElement("endDate");

		$endDate->nodeValue="".$end;

		//**********
		
		//$clients=$fxml->getElementsByTagName("Clients")->item(0);  

		if($found==false)
		{
		$nomRekrute=$fxml->createElement("nomRekrute"); 
		$nomRekrute->nodeValue=$siteDesc->getProperty('portal.recruitement.profile','');
		$offres=$fxml->createElement("Offres");
		$client=$fxml->createElement("Client"); 
		$client->appendChild($nomRekrute);
		$client->appendChild($offres);
		$clients->appendChild($client);
		}
		else{
		$offres=$fxml->getElementsByTagName("Offres")->item($i);
		}
		
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
		
		$offre->appendChild($descriptionPoste);

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

		$fxml->save($fpath_utf8);
		
		$this->ConvertSimbols($fpath_utf8,$fpath);

		return $fpath;
	}

	
	function ConvertSimbols($fpath_utf8,$fpath) {
		//DebugBreak();
		$html_entities = array (     
				"'" =>	"&rsquo;",
				"á" =>  "&aacute;",    
				"Â" =>  "&Acirc;",     
				"â" =>  "&acirc;",     
				"Æ" =>  "&AElig;",     
				"æ" =>  "&aelig;",     
				"À" =>  "&Agrave;",     
				"à" =>  "&agrave;",     
				"Å" =>  "&Aring;",     
				"å" =>  "&aring;",     
				"Ã" =>  "&Atilde;",     
				"ã" =>  "&atilde;",    
				"Ä" =>  "&Auml;",     
				"ä" =>  "&auml;",     
				"Ç" =>  "&Ccedil;",     
				"ç" =>  "&ccedil;",     
				"É" =>  "&Eacute;",     
				"é" =>  "&eacute;",     
				"Ê" =>  "&Ecirc;",     
				"ê" =>  "&ecirc;",     
				"È" =>  "&Egrave;",
				"è" =>  "&egrave;",      
				"û" =>  "&ucirc;",     
				"Ù" =>  "&Ugrave;",     
				"ù" =>  "&ugrave;",    
				"Ü" =>  "&Uuml;",     
				"ü" =>  "&uuml;",    
				"Ý" =>  "&Yacute;",     
				"ý" =>  "&yacute;",    
				"ÿ" =>  "&yuml;",     
				"Ÿ" =>  "&Yuml;",     
			);

			//ouverture en lecture et modification
			$text_utf8=fopen($fpath_utf8,'r') or die("Fichier manquant");
			$contenu=file_get_contents($fpath_utf8);
			foreach ($html_entities as $key => $value) {
				$contenu = str_replace($key, $value, $contenu);
			} 
			
			fclose($fpath_utf8);

			//ouverture en écriture
			$text=fopen($fpath,'w+');
			fwrite($text,$contenu);
			fclose($text); 
	}


	function upload_ftp($conf,$path,$fname) {
		if (
			!($host =  $conf->getProperty('job_board.ftp.host','188.165.35.98')) ||
			!($user =  $conf->getProperty('job_board.ftp.user','defaultpresence')) ||
			!($password =  $conf->getProperty('job_board.ftp.password','fh897njt7'))
			)
			{
				nxError('param missing in recruitment job posting','RECRUITMENT');
				return false;
			}
			
			//$port =  $conf->getProperty('job_board.ftp.port','21');
			$dir =  $conf->getProperty('job_board.ftp.dir','/');
			
			$conn_id = ftp_connect($host);

			ftp_login($conn_id, $user, $password);

			$p = $conf->getProperty('jobs_board.files.tmp_path',GENERIS_PACKAGES.'recruitment/tmp/');

			ftp_nb_put($conn_id, $dir."".$fname, $p."".$fname ,FTP_BINARY);

		}
	}