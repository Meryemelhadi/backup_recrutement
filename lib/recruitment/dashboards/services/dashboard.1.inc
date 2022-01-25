<?php 

class lib_recruitment_candidates_services_dashboard
{
	var $ctxt;
	
	function lib_recruitment_candidates_services_dashboard($ctxt) {
		$this->ctxt = $ctxt;
		Framework::setContext($this->ctxt = $ctxt);
	}

	function  niveau_syntaxe($niveau)
	{
		if(substr($niveau,0,3)=="BAC" && $niveau[3]=="+" &&  0<=$niveau[4] && $niveau <=9)
			return substr($niveau,0,5);
		return 0;
	}
    
	function load_stats($data) {

		

		//Récuperer les données en entrée
		$entreeCategorie=array(); //categorie
		$entreeNiveau=array();//niveau d'etude
		$entreeDossier=array();//dossier
        $entreeEcole=array();//ecole

		if($data!=null)
		{
		$arecordsObject=$data->getRecordArray();
		$arecords=$arecordsObject->records;
		foreach($arecords as $rec) {
			
			foreach (explode(",",$rec->category_oid->string) as $c){
				$entreeCategorie[]=rtrim(ltrim($c));}

            if($rec->studies_level->string=='')
				$entreeNiveau[]=$niveau;
			else{
			$niveau=$this->niveau_syntaxe(trim($rec->studies_level->string));
				    if($niveau !="0")
					$entreeNiveau[]=$niveau;
			}

			if($rec->vacancy_name->string!='' and $rec->vacancy_code->string!='')
					$entreeDossier[]=rtrim(ltrim($rec->vacancy_name->string))." (N° ".rtrim(ltrim($rec->vacancy_code->string)).")";

					$entreeEcole[]=rtrim(ltrim($rec->institution->string));
		
		}
		}



		//Categories
		$chartsT="<chart caption='' numberPrefix='%' yAxisName='pourcentage'>";
		$indT=array_count_values($entreeCategorie);
		$sommeT=array_sum($indT);
		$p=0;
		foreach($indT as $cle=>$element)
		{
			 
			 if($cle !="")
			{
			 $p=round((($element/$sommeT)*100)*100)/100;
			 $chartsT.= "<set name='".$cle."' value='" . str_replace(",", ".",$p) . "' />" ;
			}
		}
		$chartsT.="</chart>";
        //indicateur pour la categorie
        $this->ctxt->setProperty('categorie',$chartsT);
        ////////////////////////////////////////////////////////////

		//Niveaux d'etude
		$indN=array_count_values($entreeNiveau); arsort($indN);
		$sommeN=array_sum($indN);
		$p=0;
		$chartsN="<chart caption='' numberPrefix='%' yAxisName='pourcentage'>";
		foreach($indN as $cle=>$element)
		{  
			if($cle !='')
			{
			 $p=round((($element/$sommeN)*100)*100)/100;
			 $chartsN.= "<set name='".$cle."' value='" .str_replace(",", ".",$p). "' />" ;
			}
		}
		$chartsN.="</chart>";

         //indicateur pour le niveau d'etude
        $this->ctxt->setProperty('niveau',$chartsN);

         /////////////////////////////////////////////////////////////////////////
		 //Dossier
		
        $ind=array_count_values($entreeDossier);arsort($ind);
		$chartsD="<chart caption='' numberPrefix='' yAxisName='Nombre'>";
		$i=0;
		while(list($key, $value) = each($ind) and $i<6)
		{
			 $chartsD.= "<set name='".$key."' value='" .$value. "' />" ;
			 $i++;
		}
		$chartsD.="</chart>";

         //indicateur pour les dossiers
        $this->ctxt->setProperty('dossier',$chartsD);

        ///////////////////////////////////////////////////////////////////////////////
		//Ecole
		

		$indE=array_count_values($entreeEcole);arsort($indE);
		$sommeE=array_sum($indE);
		$p=0;
		$chartsE="<chart caption='' numberPrefix='%' yAxisName='pourcentage'>";
		$i=0;
		while(list($key, $value) = each($indE) and $i<6)
		{    
			if($key!='')
			{
				 $p=(($value/$sommeE)*100);
				 $p=round($p*100)/100;
				 $chartsE.= "<set name='".$key."' value='" .str_replace(",", ".",$p). "' />" ;
				 $i++;
			}
		}
		$chartsE.="</chart>";

         //indicateur pour les dossiers
        $this->ctxt->setProperty('ecole',$chartsE);
      
        
	}
	
	

}

?>