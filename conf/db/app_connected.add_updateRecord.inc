<?php $properties["query"]="UPDATE _rct_app_connected SET _oid=".$record->getFieldValue("oid","DB","NULL").",_name=".$record->getFieldValue("name","DB","NULL").",_url=".$record->getFieldValue("url","DB","NULL").",_key=".$record->getFieldValue("key","DB","NULL").",_actif=".$record->getFieldValue("actif","DB","NULL").",_login=".$record->getFieldValue("login","DB","NULL").",_password=".$record->getFieldValue("password","DB","NULL").",_active_app=".$record->getFieldValue("active_app","DB","NULL").",_data_type=".$record->getFieldValue("data_type","DB","NULL").",_comment=".$record->getFieldValue("comment","DB","NULL").",_compagnie_name=".$record->getFieldValue("compagnie_name","DB","NULL").",_description=".$record->getFieldValue("description","DB","NULL").",_contact_email=".$record->getFieldValue("contact_email","DB","NULL").",_logo=".$record->getFieldValue("logo","DB","NULL").",_favicon=".$record->getFieldValue("favicon","DB","NULL").",_adress=".$record->getFieldValue("adress","DB","NULL").",_banner_background_image=".$record->getFieldValue("banner_background_image","DB","NULL").",_banner_second_background_image=".$record->getFieldValue("banner_second_background_image","DB","NULL").",_menu_text_color=".$record->getFieldValue("menu_text_color","DB","'#fff'").",_menu_text_font_size=".$record->getFieldValue("menu_text_font_size","DB","NULL").",_menu_text_font_family=".$record->getFieldValue("menu_text_font_family","DB","NULL").",_menu_background_color=".$record->getFieldValue("menu_background_color","DB","'#2c2c2c'").",_baniere_title_color=".$record->getFieldValue("baniere_title_color","DB","'#fff'").",_baniere_title_font_size=".$record->getFieldValue("baniere_title_font_size","DB","NULL").",_baniere_title_font_family=".$record->getFieldValue("baniere_title_font_family","DB","NULL").",_baniere_title_text_align=".$record->getFieldValue("baniere_title_text_align","DB","NULL").",_baniere_description_color=".$record->getFieldValue("baniere_description_color","DB","'#000'").",_baniere_description_font_size=".$record->getFieldValue("baniere_description_font_size","DB","NULL").",_baniere_description_font_family=".$record->getFieldValue("baniere_description_font_family","DB","NULL").",_button_nous_rejoindre_color=".$record->getFieldValue("button_nous_rejoindre_color","DB","'#fff'").",_button_nous_rejoindre_font_size=".$record->getFieldValue("button_nous_rejoindre_font_size","DB","NULL").",_button_nous_rejoindre_font_family=".$record->getFieldValue("button_nous_rejoindre_font_family","DB","NULL").",_button_nous_rejoindre_rounded=".$record->getFieldValue("button_nous_rejoindre_rounded","DB","NULL").",_button_nous_rejoindre_color_text=".$record->getFieldValue("button_nous_rejoindre_color_text","DB","'#fff'").",_footer_content=".$record->getFieldValue("footer_content","DB","NULL").",_footer_text_color=".$record->getFieldValue("footer_text_color","DB","'#fff'").",_footer_text_font_size=".$record->getFieldValue("footer_text_font_size","DB","NULL").",_footer_text_font_family=".$record->getFieldValue("footer_text_font_family","DB","NULL").",_footer_text_text_align=".$record->getFieldValue("footer_text_text_align","DB","NULL").",_footer_text_height=".$record->getFieldValue("footer_text_height","DB","NULL").",_footer_text_background_color=".$record->getFieldValue("footer_text_background_color","DB","'#000'").",_css_txt=".$record->getFieldValue("css_txt","DB","NULL").",_js_txt=".$record->getFieldValue("js_txt","DB","NULL")." WHERE _oid='".$this->getParamValue("oid","","request",",")."'"; ?>