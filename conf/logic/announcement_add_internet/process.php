<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class announcement_add_internet_process extends NxPage
{
	function announcement_add_internet_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
							$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
							$article=
								$this->getRecord('','page.record','post',false,null,null);
							$this->putRecord($article,'','insert','db','Object',null);
							$this->setProperty("lastInsertId",
								$this->getLastInsertID('db'));
							$path='';
							$handler='';
							($tmp=
								(($__o=$this->getHandler('','')) ? $__o->uploadAnnouncementFiles($this->getProperty("lastInsertId",""),$handler,$path) : null))!=null?$this->addProperties($tmp):null;
							$article_title=
								$article->getProperty('title','',false,'object','');
							$article_content=
								$article->getProperty('article_content','',false,'object','');
							$article_type=
								$article->getProperty('type','',false,'object','');
							$article_provider=
								$article->getProperty('provider_oid','',false,'object','');
							$this->putRecord(
								$_nx_record_data54=array(
										'ann_title'=>$article_title,
										'ann_content'=>$article_content,
										'ref_oid'=>$this->getProperty("lastInsertId",""),
										'type'=>$article_type,
										'provider_oid'=>$article_provider,),'','insert','db','Object',null);
							$this->setProperty("lastInsertId",
								$this->getLastInsertID('db'));
							$this->putRecord(
								$_nx_record_data55=array(
										'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
										'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
										'action_oid'=>'30',
										'ref_oid'=>$this->getProperty("lastInsertId",""),
										'additional_infos'=>'',),'rct_vacancy_action.record@recruitment','insert','db','Object',null);
							($tmp=
								(($__o=$this->getHandler('','')) ? $__o->postJobBoard($article) : null))!=null?$this->addProperties($tmp):null;
		return true;
	}
}
?>