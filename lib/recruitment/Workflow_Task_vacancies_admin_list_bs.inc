<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_vacancies_admin_list_bs extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
	}

	function run()
	{
	
		//Permission DRH
		$drh = "";
		if($GLOBALS['_NX_user']->checkPerm('?-drh')) $drh = "-drh";
	
		//Multiposting config
		if(defined("NX_RECRUITMENT_MULTIPOSTING") && NX_RECRUITMENT_MULTIPOSTING ==  true){
			$this->setProperty("use_multiposting",NX_RECRUITMENT_MULTIPOSTING);
		}else{
			$this->setProperty("use_multiposting",false);
		}
		if(!isset($_REQUEST['current_step']) || $_REQUEST['current_step']==='')
		{
			$defaultState = true;
			$_POST['current_step']=$_GET['current_step']=$_REQUEST['current_step']='0';
		}
		else
			$defaultState = false;

		// search context
		$searchData=
			$this->getRecord('rct_vacancy.search@recruitment','page.search','request',false,null,null);

		// load vacancies
		
		$vacanciesList=$this->getRecords('rct_vacancy.list'.$drh.'@recruitment','page.records','db',false,$searchData,null);

		if($defaultState)
		{
			// reset state
			$searchData->current_step->object='';
		}

		$searchDataVar='searchData';
		$_searchKey_=(($_nx_rec64=${$searchDataVar})!=null?$_nx_rec64->getUrlKey(true):'');
		
		if((isset($_REQUEST["page"])?$_REQUEST["page"]:""))
		{
			$_searchKey_ = preg_replace("/page=[^&]+(&(amp;)?)?/",'',$_searchKey_);  
			$_searchKey_=$_searchKey_.'&amp;page='.(isset($_REQUEST["page"])?$_REQUEST["page"]:"");
		}
		
		if((isset($_REQUEST["sort_by"])?$_REQUEST["sort_by"]:""))
		{
			$_searchKey_ = preg_replace("/sort_by=[^&]+(&(amp;)?)?/",'',$_searchKey_);  
			$_searchKey_=$_searchKey_.'&amp;sort_by='.(isset($_REQUEST["sort_by"])?$_REQUEST["sort_by"]:"");
		}

		if((isset($_REQUEST["sort_dir"])?$_REQUEST["sort_dir"]:""))
		{
			$_searchKey_ = preg_replace("/sort_dir=[^&]+(&(amp;)?)?/",'',$_searchKey_);  		
			$_searchKey_=$_searchKey_.'&amp;sort_dir='.(isset($_REQUEST["sort_dir"])?$_REQUEST["sort_dir"]:"");
		}
		
		$this->setProperty("filterKey",$_searchKey_);

		if(isset($_GET['nxs']))
			$_searchKey_ = 'nxs='.$_GET['nxs'].'&'.$_searchKey_;
		if(isset($_GET['nxo']))
			$_searchKey_ = 'nxo='.$_GET['nxo'].'&'.$_searchKey_;
		if(isset($_GET['wao']))
			$_searchKey_ = 'wao='.$_GET['wao'].'&'.$_searchKey_;

		$GLOBALS["NX_CURRENT_URL"] ='?'.$_searchKey_;
	
		$this->setProperty("alphabet_filter",(isset($_REQUEST["alphabet_filter"])?$_REQUEST["alphabet_filter"]:""));

        $count_multiposting =0;
		$no_project = true;
		if($_nx_records69=$vacanciesList) 
		{
			for (	$_nx_iterRec68 = $vacanciesList->getRecordIterator(); 
				$_nx_iterRec68->isValid(); 
				$_nx_iterRec68->next())
			{

				$vacancy=&$_nx_iterRec68->getCurrent();
				$this->setProperty('vacancy_id',
					$vacancy->getProperty('oid','',false,'object',''));
				$_REQUEST['vacancy_id'] = $vacancy->getProperty('oid','',false,'object','');
				$candidatesList=
					$this->getRecords('rct_candidate_vacancy.vacancy_candidates_not_null@recruitment','','db',false,null,null);
				
				$candidatescount=
					(($_nx_records65=$candidatesList)!=null?$_nx_records65->count():0);
				
				$count_rekrute= $this->getRecord('vacancy_rekrute_count@recruitment','','db',false,null,null);
				
				
				if(($_nx_rec66=&$vacancy)!=null) {
					$_nx_rec66->setField('candidates_count',$candidatescount);
					$_nx_rec66->setField('rekrute_count',$count_rekrute->count_recrute);
				}
				
				//Project 
				if($vacancy->getProperty('vacancy_project','',false,'object','') != null){
					$no_project = false;
				}

                //Multiposting informations
                $offer= $this->getRecord('posting.by_vacancy@recruitmentmp','','db',false,null,null);
                if($offer != null) {
                    $count_multiposting++;
                    if(($_nx_rec66=&$vacancy)!=null) $_nx_rec66->setField('multiposting_status',$offer->status->object);
                    if(($_nx_rec66=&$vacancy)!=null) $_nx_rec66->setField('multiposting_oid',$offer->oid->object);
                    //add total clics
                    $_GET['oid'] = $offer->oid->object;
                    $jobboardList= $this->getRecords('posting.provider_list@recruitmentmp','','db',false,null,null);
                    $nbrClics = 0;
                    $countStatus=0;
                    for (	$_nx_iterRec69 = $jobboardList->getRecordIterator();
                             $_nx_iterRec69->isValid();
                             $_nx_iterRec69->next())
                    {
                        $jobboard=&$_nx_iterRec69->getCurrent();
                        $nbrClics+= $jobboard->clicks->value;
                        if($offer->status->object == 'New' && $jobboard->status->object == 'New'){
                            $countStatus++;
                        }
                    }

                    if(($_nx_rec66=&$vacancy)!=null) $_nx_rec66->setField('multiposting_clics',$nbrClics);
                    //Add new status pourcent
                    if($offer->status->object == 'New'){
                        if(($_nx_rec66=&$vacancy)!=null) $_nx_rec66->setField('status_pourcent','('.$jobboardList->count().'/'.$countStatus.')');
                    }

                }else{
                    if(($_nx_rec66=&$vacancy)!=null) $_nx_rec66->setField('multiposting_status','#');
                    if(($_nx_rec66=&$vacancy)!=null) $_nx_rec66->setField('multiposting_clics','#');
                }



			}
		}
		$this->setProperty('no_project' , $no_project);

		$pself = $_SERVER["PHP_SELF"];
		$fkey = '&amp;filterKey='.urlencode($this->getProperty("filterKey",""));
		
		$this->getRecords('rct_vacancy.pending_list@recruitment','page_pending.records','db',false,null,null);

		$this->addProperties(
			array(
				'add.url'=>$pself.'?nxo=add&amp;nxs='.$fkey,
				'edit.url'=>$pself.'?nxo=edit&amp;nxs='.$fkey,
				'xls_export.url'=>$pself.'?nxo=xls_export_'.$this->getProperty("recruitement_profile","default").'&amp;nxs='.$this->getProperty("filterKey",""),
				'archive.url'=>$pself.'?nxo=archive&amp;nxs='.$fkey,
				'delete.url'=>$pself.'?nxo=delete&amp;nxs='.$fkey,
				'validate.url'=>$pself.'?nxo=validate&amp;nxs='.$fkey,
				'search.url'=>$pself.'?nxo=listbs&amp;nxs=&amp;is_search=true',
				'manage_candidate_etats.url'=>PORTAL_URL_PREFIX.'/recruitment/admin/manage_candidate_etats.php',
				'manage_recruitment_reasons.url'=>PORTAL_URL_PREFIX.'/recruitment/admin/manage_recruitment_reasons.php',
				'manage_contract_types.url'=>PORTAL_URL_PREFIX.'/recruitment/admin/manage_contract_types.php',
				'manage_duty_stations.url'=>PORTAL_URL_PREFIX.'/recruitment/admin/manage_duty_stations.php',
				'manage_subsidiaries.url'=>PORTAL_URL_PREFIX.'/recruitment/admin/manage_subsidiaries.php',
				'manage_services.url'=>PORTAL_URL_PREFIX.'/recruitment/admin/manage_services.php',
				'manage_vacancy_categories.url'=>PORTAL_URL_PREFIX.'/recruitment/admin/manage_vacancy_categories.php',
				'app_connected.url'=>PORTAL_URL_PREFIX.'/recruitment/search_params.php',

				'back_list.url'=>PORTAL_URL_PREFIX.'/recruitment/vacancies/directory.php?nxo=listbs&amp;nxs='.$_searchKey_,

				'list.url'=>$pself.'?nxo=listbs&amp;nxs=',
				'cvtq.url'=> PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php?nxo=list&nxs=&mode=page&vacancy=';
                'count_multiposting' => $count_multiposting
			)
		);

		if((isset($_REQUEST["is_search"])?$_REQUEST["is_search"]:"") == 'true')
		{
			$this->setProperty("is_search",'true');
		}

		$this->runView('recruitment.vacancies.list_bs1@recruitment',array('fmethod' => 'toHTML',),null);
		return true;
	}
}
?>