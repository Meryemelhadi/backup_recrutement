<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_admin_directory__announcement_add_internet_process extends NxPage
{
	function recruitment_vacancies_admin_directory__announcement_add_internet_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$article=
						$this->getRecord('rct_announcement_rekrute.add@recruitment','page.record','post',false,null,null);
					$this->putRecord($article,'rct_announcement_rekrute.add@recruitment','insert','db','Object',null);
					$this->setProperty("lastInsertId",
						$this->getLastInsertID('db'));
					$path='journal';
					$handler='journal_file_attachements.add@recruitment';
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->uploadAnnouncementFiles($this->getProperty("lastInsertId",""),$handler,$path) : null))!=null?$this->addProperties($tmp):null;
					$article_title=
						$article->getProperty('title','',false,'object','');
					$article_content=
						$article->getProperty('article_content','',false,'object','');
					$article_type=
						$article->getProperty('type','',false,'object','');
					$article_provider=
						$article->getProperty('provider_oid','',false,'object','');
					$this->putRecord(
						$_nx_record_data4=array(
								'ann_title'=>$article_title,
								'ann_content'=>$article_content,
								'ref_oid'=>$this->getProperty("lastInsertId",""),
								'type'=>$article_type,
								'provider_oid'=>$article_provider,),'rct_announcement.add','insert','db','Object',null);
					$this->setProperty("lastInsertId",
						$this->getLastInsertID('db'));
					$this->putRecord(
						$_nx_record_data5=array(
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'30',
								'ref_oid'=>$this->getProperty("lastInsertId",""),
								'additional_infos'=>'',),'rct_vacancy_action.record','insert','db','Object',null);
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.annonce','')) ? $__o->postJobBoard($article) : null))!=null?$this->addProperties($tmp):null;
		return true;
	}
}
?>