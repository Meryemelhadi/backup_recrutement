<?php 

class lib_recruitment_dashboards_services_dashboard
{
	var $ctxt;
	
	function lib_recruitment_dashboards_services_dashboard($ctxt) {
		$this->ctxt = $ctxt;
		Framework::setContext($this->ctxt = $ctxt);
	}

	function load_stats($data) {
		$arecordsObject=$data->getRecordArray();
		$arecords=$arecordsObject->records;
		
        //Récuperer tous les providers et les types
		//la liste des fournisseurs
		$entreeF=array();

		//la liste des types
		$entreeT=array();
		foreach($arecords as $rec) {
			$entreeF[] = $rec->providers->string;
			$entreeT[] = $rec->application_type->string;
		}
         
		$indF=array_count_values($entreeF);
		$sommeF=array_sum($indF);
		$p=0;
		//Fournisseurs
		$chartsF="<chart  caption='' numberPrefix='%' yAxisName='pourcentage'>";
		foreach($indF as $cle=>$element)
		{
		 $p=round((($element/$sommeF)*100)*100)/100;

		if($cle=='')
			$cle="aucun fournisseur";
         $chartsF.= "<set name='".$cle."' value='" .str_replace(",", ".",$p). "' />";
		}
		$chartsF.="</chart>";
		

        //Type
		$chartsT="<chart bgColor='#c4c9be,#e9ede5' caption='' yAxisName='pourcentage'>";
		foreach(array_count_values($entreeT) as $cle=>$element)
		{
         $chartsT.= "<set name='".$cle."' value='" . $element . "' />";
		}
		$chartsT.="</chart>";


		$this->ctxt->setProperty('fournisseurs',$chartsF);
		$this->ctxt->setProperty('type',$chartsT);
	}
	
	

}

?>