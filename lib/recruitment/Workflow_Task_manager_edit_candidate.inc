<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961.
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once('candidates/services/directory.inc');

class Workflow_Task_manager_edit_candidate extends NxPage
{
    function __construct($ctxt,$params,$taskID)
    {
        $this->NxPage($params,$ctxt,null);
        $this->ctxt = $this;
    }

    function run($workflow,$user)
    { 
        /** check if candidate exists **/
        $model = $workflow->model;
        $state = $workflow->getState();
        $dml = $model->getDS('record',$state);
        $candidate = new PersistentObject();
        $candidate->load($dml,'db');
        if(!$candidate->isOk()){
            header('Location:'.PORTAL_URL_PREFIX.'/recruitment/manager_candidates/index.php?nxo=list&nxs='.preg_replace(array('%&amp;%','%[+]%'),array('&','%2B'),urldecode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""))));
            return true;
        }
        /** end **/

        $userOid = $user->oid->object;
        $filterKey = (isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:"");

        $candidateOid = $oid = (isset($_REQUEST["coid"])?$_REQUEST["coid"]:'');
        if(!$candidateOid)
        {
            $candidateOid = $oid = (isset($_REQUEST['oid'])?$_REQUEST['oid']:'');

        }
        $_REQUEST['oid']=$_GET['oid']=$_GET['coid']=$_REQUEST['coid']=$candidateOid;

        // Mark CV as read
        $directory = new lib_recruitment_candidates_services_directory($this->ctxt);
        $directory->insertReadState($userOid,$oid);

        // Mark CV as read
        $this->putRecord($null=null,'rct_candidate.mark_as_read@recruitment','update','db','Object',null);

        // Load data
        $this->setProperty("candidate_oid",$oid);
		$this->getRecord('rct_candidate.edit@recruitment','page.record','db',false,null,null);
		$candidate_record = $this->getProperty('page.record');
		$workflow->setFieldsProperty(array('hr_manager'),'isEdit', false,$candidate_record);


        // back to homepage
        $back_home= (isset($_REQUEST["from_home"])?$_REQUEST["from_home"]:"");
        if($back_home == ""){
            $this->setProperty('previous_operation_link.url',PORTAL_URL_PREFIX.'/recruitment/manager_candidates/index.php?nxo=list&amp;nxs='.$filterKey.'&amp;mode=page');
            $this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$candidateOid.'&candidate_oid='.$candidateOid);
        }else{
            $this->setProperty('previous_operation_link.url',PORTAL_URL_PREFIX.'/homepage/');
            $this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&from_home=1');
            $this->setProperty('back_home' , true);
        }

		//Date entretien

		$this->getRecord('rct_interview.by_user_and_candidate','interview','db',false,null,null);
		$interview_record = $this->getProperty('interview');

        $this->getRecords('rct_candidate_etat_assoc.candidate_etats@recruitment','candidate_etats.records','db',false,null,null);
        $this->getRecord('rct_candidate_etat_assoc.add@recruitment','candidate_etats.record','empty',false,null,null);
		$this->getRecords('rct_candidate_comment.record','comments.records','db',false,null,null);
       	$this->setProperty('fiche_interview.url',PORTAL_URL_PREFIX.'/recruitement2/interview_evaluation.php?nxo=edit_by_interview&mode=page&oid='.$interview_record->oid->object);
		

        $this->setProperty('download_cv.url',$_SERVER["PHP_SELF"].'?nxo=download&amp;nxs=&amp;type=cv&amp;candidate_oid='.$candidateOid);
        $this->setProperty('download_cl.url',$_SERVER["PHP_SELF"].'?nxo=download&amp;nxs=&amp;type=cl&amp;candidate_oid='.$candidateOid);
        $this->setProperty('preview_cv.url',$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cv&amp;candidate_oid='.$candidateOid);
        //$this->setProperty('edit.url',$_SERVER["PHP_SELF"].'?nxo=edit&amp;nxs=&amp;oid='.$candidateOid.'&candidate_oid='.$candidateOid);
        $this->setProperty('preview_cl.url',$_SERVER["PHP_SELF"].'?nxo=preview&amp;nxs=&amp;type=cl&amp;candidate_oid='.$candidateOid);
        $this->setProperty('add_etat.url',$_SERVER["PHP_SELF"].'?nxo=add_etat&amp;nxs=&amp;candidate_oid='.$candidateOid);
        $this->setProperty('delete_etat.url',$_SERVER["PHP_SELF"].'?nxo=delete_etat&amp;nxs=');
		$this->setProperty('add_comment.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=add_comment&amp;nxs=&amp;oid='.$oid);
		$this->setProperty('delete_comment.url',PORTAL_URL_PREFIX.$_SERVER["PHP_SELF"].'?nxo=delete_comment&amp;nxs=&amp;candidate_oid='.$candidateOid);
        $this->setProperty('reinit_status.url',PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/directory.php?nxo=change_candidate_status_from_candidate&nxs=&status_value=0&is_visible=0&candidate_oid='.$candidateOid.'&vacancy_oid=');

        $this->setProperty('submit.url',$_SERVER["PHP_SELF"].'?nxo=edit_process&amp;filterKey='.urlencode($filterKey));


        $this->runView('/recruitment/candidates/manager_edit',array(
            'fmethod' => 'toHTML',

        ),null);
        return true;
    }
}
?>