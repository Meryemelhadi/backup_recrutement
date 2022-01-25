<?php $properties["query"]="
					SELECT 
						CA._url AS _url,
						CA._logo AS _logo,
						CA._menu_text_color AS _menu_text_color,
						CA._menu_text_font_size AS _menu_text_font_size,
						CA._menu_text_font_family AS _menu_text_font_family,
						CA._menu_background_color AS _menu_background_color,
						
						CA._favicon AS _favicon,
						CA._contact_email AS _contact_email,
						CA._adress AS _adress,
						CA._compagnie_name AS _name_society,
						CA._description AS _description_society,
						CA._banner_background_image AS _banner_background_image,
						CA._banner_second_background_image AS _banner_second_background_image,
						CA._baniere_title_color AS _baniere_title_color,
						CA._baniere_title_font_size AS _baniere_title_font_size,
						CA._baniere_title_font_family AS _baniere_title_font_family,
						CA._baniere_title_text_align AS _baniere_title_text_align,
						CA._baniere_description_color AS _baniere_description_color,
						CA._baniere_description_font_size AS _baniere_description_font_size,
						CA._baniere_description_font_family AS _baniere_description_font_family,
						CA._button_nous_rejoindre_color AS _button_nous_rejoindre_color,
						CA._button_nous_rejoindre_font_size AS _button_nous_rejoindre_font_size,
						CA._button_nous_rejoindre_font_family AS _button_nous_rejoindre_font_family,
						CA._button_nous_rejoindre_rounded AS _button_nous_rejoindre_rounded,
						CA._button_nous_rejoindre_color_text AS _button_nous_rejoindre_color_text,
						CA._footer_content AS _footer_content,
						CA._footer_text_color AS _footer_text_color,
						CA._footer_text_font_size AS _footer_text_font_size,
						CA._footer_text_font_family AS _footer_text_font_family,
						CA._footer_text_text_align AS _footer_text_text_align,
						CA._footer_text_height AS _footer_text_height,
						CA._footer_text_background_color AS _footer_text_background_color,
						CA._css_txt AS _css_txt,
						CA._js_txt AS _js_txt
					FROM 
						 _rct_app_connected AS CA

					WHERE 
						CA._actif = 1 and CA._url like '%".$_REQUEST['origine']."%'
						
					
				"; ?>