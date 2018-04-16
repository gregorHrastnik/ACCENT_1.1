/* 
* menu_mgr.h
*
* Created: 30.3.2017 11:56:02
* Author: Greg
*/


#ifndef __MENU_MGR_H__
#define __MENU_MGR_H__
#include <UTFT.h>
#include "custom_menu.h"
class menu_mgr
{
//variables
public:
void display_menu();
void menu_init();
void quick_fix_TRANSPOSE(byte trans);
void check_reverb(String string_name, byte tempVar);
void send_startup_reverb(byte MIDI_out, byte tempVar);
void resend_notes();
	void resend_notes_with_on_off();
void draw_text_string(String text,int x,int y,bool visible);
protected:
private:
//void check_reverb(String string_name, byte tempVar);

/*
void(*on_menu_selected)(Menu*),void(*on_item_select)(MenuItem*),
void(*on_menu_draw_enabled)(Menu*),void(*on_item_clear)(MenuItem*),
void(*on_menu_draw_disabled)(Menu*),void(*on_menu_clear)(Menu*),
void(*on_item_draw_enabled)(MenuItem*),void(*on_item_draw_disabled)(MenuItem*));*/


//void display_menu();
//void on_item_dummy(MenuItem* p_menu_item);
//void call_item_mode(MenuItem* p_menu_item, byte mode);
//void on_item_select(MenuItem* p_menu_item);
//void on_item_draw_disabled(MenuItem* p_menu_item);
//void on_item_clear(MenuItem* p_menu_item);
//void on_menu_selected(Menu* p_menu);
//void on_menu_draw_enabled(Menu* p_menu);
//void on_menu_draw_disabled(Menu* p_menu);
//void on_menu_clear(Menu* p_menu);
//functions
public:

	menu_mgr();
	~menu_mgr();
protected:
private:
	menu_mgr( const menu_mgr &c );
	menu_mgr& operator=( const menu_mgr &c );

}; //menu_mgr
//void drawButtonSelect(MenuItem* p_menu_item, int mode);
//void drawSlider_from_stop_selector(MenuItem* p_menu_item, byte mode);
//


void on_item_select(MenuItem* p_menu_item,byte id_mode);
void on_item_draw_enabled(MenuItem* p_menu_item);
void on_item_draw_disabled(MenuItem* p_menu_item);
void on_item_clear(MenuItem* p_menu_item);
void on_menu_selected(Menu* p_menu,byte id_mode);
void on_menu_draw_enabled(Menu* p_menu);
void on_menu_draw_disabled(Menu* p_menu);
void on_menu_clear(Menu* p_menu);

#endif //__MENU_MGR_H__

// extern unsigned int

 
