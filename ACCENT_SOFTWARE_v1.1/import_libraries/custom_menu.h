// custom_menu.h


#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif



#define ON_SELECT 1
#define ON_DRAW_ENABLED 2
#define ON_DRAW_DISABLED 3
#define ON_CLEAR 4
#define ON_FIRST_DRAW 5
class MenuComponent
{
	public:
	MenuComponent(int name_id);

	void set_name(__FlashStringHelper *name);
	const __FlashStringHelper* get_name() ;
	

	int get_x() ;
	int get_min_display_val();
	int get_max_display_val();
	int get_y() ;


	virtual MenuComponent* draw_first_time();
	virtual MenuComponent* draw_enabled();
	virtual MenuComponent* draw_normal();
	virtual MenuComponent* draw_selected();
	virtual MenuComponent* clear_component();
	//virtual MenuComponent* tempClear();

	virtual MenuComponent* select() = 0;

	virtual  byte get_type() ;

	virtual  byte getValue();
	virtual  int getMemAddress();

	virtual void setValue(int _value);
	virtual void setMemAddress(int address);
	virtual void set_interactive(bool true_false);
	virtual void addValue(int _value);
	virtual void reset() = 0;
	virtual void refresh();
	bool is_alive();
	//	bool is_interactive = true;
	int get_name_id();

	protected:

	int _name_id;
	//byte _type;
	//__FlashStringHelper* _name;


	//const char _name[] PROGMEM = { "test" };

	// byte _x;
	// byte _y;
	// int _mem_address;
	int read_PROGMEM_info(int id_data);

};


class MenuItem : public MenuComponent
{
	public:
	MenuItem(int name_id);
	//const __FlashStringHelper* get_name2() const;

	void set_select_function(void(*on_select)(MenuItem*,byte));
	void set_draw_function(void(*on_draw_enabled)(MenuItem*));
	void set_undraw_function(void(*on_draw_disabled)(MenuItem*));
	void set_clear_function(void(*on_clear)(MenuItem*));

	virtual MenuComponent* draw_first_time();
	virtual MenuComponent* select();
	virtual MenuComponent* draw_enabled();
	virtual MenuComponent* draw_selected();
	virtual MenuComponent* draw_normal();
	virtual MenuComponent* clear_component();
	virtual MenuComponent* tempClear();

	virtual  byte getValue();
	byte saveValueEEPROM();
	virtual void setValue(int _value);
	virtual void addValue(int _value);
	virtual void setMemAddress(int address);
	virtual void reset();
	void refreshValueFromEEPROM();
	virtual void refresh();
	virtual  byte get_type() ;

	byte value;
	//String temp_value;
	//bool _com_enabled=false;
	//char* temp_value;

	private:

	void(*_on_event)(MenuItem*,byte);
	//void(*_on_select)(MenuItem*);
	//void(*_on_draw_enabled)(MenuItem*);
	//void(*_on_draw_disabled)(MenuItem*);
	//void(*_on_clear)(MenuItem*);


	//int _mem_address;
	//const char signMessage[] PROGMEM = { "I AM PREDATOR,  UNSEEN COMBATANT. CREATED BY THE UNITED STATES DEPART" };
	//__FlashStringHelper* _name2;
	


};

class MenuItem_rec_play : public MenuItem
{
	public:
	MenuItem_rec_play(int name_id);
	void set_select_function(void(*on_select)(MenuItem_rec_play*,byte));
	void set_draw_function(void(*on_draw_enabled)(MenuItem_rec_play*));
	void set_undraw_function(void(*on_draw_disabled)(MenuItem_rec_play*));
	void set_clear_function(void(*on_clear)(MenuItem_rec_play*));

	virtual void setValue(int _value);
	virtual  byte getValue();



	private:
	void(*_on_event)(MenuItem*,byte);



};

class MenuItem_editable : public MenuItem
{
	public:
	MenuItem_editable(int name_id);
	void set_select_function(void(*on_select)(MenuItem_editable*,byte));
	void set_draw_function(void(*on_draw_enabled)(MenuItem_editable*));
	void set_undraw_function(void(*on_draw_disabled)(MenuItem_editable*));
	void set_clear_function(void(*on_clear)(MenuItem_editable*));

	
	virtual void setMemAddress(int address);
	virtual  int getMemAddress();

	//String temp_value;
	//bool _com_enabled=false;
	//char* temp_value;

	private:
	int _mem_address;
	void(*_on_event)(MenuItem*,byte);




};
class MenuItem_editable_for_tones : public MenuItem
{
	public:
	MenuItem_editable_for_tones(int name_id);
	void set_select_function(void(*on_select)(MenuItem_editable_for_tones*,byte));
	void set_draw_function(void(*on_draw_enabled)(MenuItem_editable_for_tones*));
	void set_undraw_function(void(*on_draw_disabled)(MenuItem_editable_for_tones*));
	void set_clear_function(void(*on_clear)(MenuItem_editable_for_tones*));

	
	virtual void setMemAddress(int address);
	virtual  int getMemAddress();
	virtual void setValue(int _value);
	virtual  byte getValue();
	//String temp_value;
	//bool _com_enabled=false;
	//char* temp_value;

	private:
	int _mem_address;
	void(*_on_event)(MenuItem*,byte);




};






class Menu : public MenuComponent
{
	public:
	Menu(int name_id);


	boolean change_value(byte value);
	boolean next(int count, boolean loop = false);
	boolean prev(int count, boolean loop = false);
	MenuComponent* activate();
	virtual MenuComponent* select();
	virtual MenuComponent* draw_first_time();
	virtual MenuComponent* draw_enabled();
	virtual MenuComponent* draw_selected();
	virtual MenuComponent* draw_normal();
	virtual MenuComponent* clear_component();

	virtual MenuComponent* tempClear();
	virtual  byte get_type() ;


	virtual  byte getValue();
	virtual void setValue(int _value) ;
	virtual void addValue(int _value);
	virtual void setMemAddress(int address);
	virtual void reset();
	virtual void refresh();

	void clear_current_display();
	void add_item(MenuItem* pItem, void(*on_select)(MenuItem*,byte), void(*on_draw_enabled)(MenuItem*), void(*on_draw_disabled)(MenuItem*), void(*on_clear)(MenuItem*));
	Menu const* add_menu(Menu* pMenu, void(*on_select)(Menu*,byte), void(*on_draw_enabled)(Menu*), void(*on_draw_disabled)(Menu*), void(*on_clear)(Menu*));

	void set_parent(Menu* pParent);
	Menu* get_parent() ;

	MenuComponent * get_selected() ;
	MenuComponent * get_activated() ;
	MenuComponent * get_menu_component(byte index) ;

	byte get_num_menu_components() ;
	byte get_cur_menu_component_num() ;


	void set_select_function(void(*on_select)(Menu*,byte));
	void set_draw_function(void(*on_draw_enabled)(Menu*));
	void set_undraw_function(void(*on_draw_disabled)(Menu*));
	void set_clear_function(void(*on_clear)(Menu*));

	public:
	void(*_on_event)(Menu*,byte id_event);
	

	//void(*_on_select)(Menu*);
	//void(*_on_draw_enabled)(Menu*);
	//void(*_on_draw_disabled)(Menu*);
	//void(*_on_clear)(Menu*);


	MenuComponent* _p_activated_menu_component;
	MenuComponent* _p_sel_menu_component;
	MenuComponent** _menu_components;
	Menu* _p_parent;
	byte _num_menu_components;
	byte _cur_menu_component_num;
};


class MenuSystem
{
	public:
	MenuSystem();

	boolean next(int count, boolean loop = false);
	boolean prev(int count, boolean loop = false);
	void reset();
	void refresh();
	void select(boolean reset = false);
	boolean back();
	boolean is_root();

	void set_root_menu(Menu* p_root_menu);

	Menu * get_current_menu() ;
	MenuComponent * get_selected1() ;
	

	Menu* _p_root_menu;
	Menu* _p_curr_menu;

};


#endif


