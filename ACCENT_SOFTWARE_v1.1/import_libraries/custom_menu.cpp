
#include "custom_menu.h"
#include "global_variables.h"
#include <avr/pgmspace.h>
#include "EEPROM.h"

// *********************************************************
// MenuComponent
// *********************************************************
MenuComponent::MenuComponent(int name_id)
: _name_id(name_id)
{
}


const __FlashStringHelper* return_name(int id)
{
	switch (id) {
		case	NUM_enter_menu	:	return F("MENU");break;
		case	 NUM_VOLUME_SLIDER	:	return F("	 NUM_VOLUME_SLIDER	");break;
		case	 NUM_VOL_label	:	return F("VOLUME");break;
		case	 NUM_Z_COMBINATION	:	return F("Z COMB");break;
		case	 NUM_Setter_combination	:	return F("COMBINATION");break;
		case	 NUM_transpose_1	:	return F("TRANSPOSE:");break;
		case	 NUM_transpose_label	:	return F("TVAL");break;
		case	 NUM_MAIN_STATIC_LABEL	:	return F("REVERB:");break;
		case	 NUM_REVERB_VALUE	:	return F("RvB");break;
		case	 NUM_Z_LABEL	:	return F("Z:");break;
		case	 NUM_cr_ped	:	return F("CR");break;
		case	 NUM_exp_ped_1	:	return F("EXP");break;
		case	 NUM_exp_ped	:	return F("EXP1");break;
		case	 NUM_exp_ped_label	:	return F("EXP_LBL");break;
		case	 NUM_cr_ped_label	:	return F("CR_LBL");break;
		case	 NUM_styles_menu	:	return F("STYLES");break;
		case	 NUM_transpose_menu	:	return F("TRANSPOSE");break;
		case	 NUM_hist_temperament_menu	:	return F("TUNING");break;
		case	 NUM_EFFECT_menu	:	return F("REVERB");break;
		case	 NUM_utility_menu	:	return F("UTILITY");break;
		case	 NUM_tremulant_menu	:	return F("TREMULANT");break;
		case	 NUM_EQUALIZER_menu	:	return F("EQUALIZER");break;
		case	 NUM_mem_bank_menu	:	return F("ORGANIST");break;
		case	 NUM_intonation_menu	:	return F("INTONATION");break;
		case	 NUM_transpose	:	return F("TRANSPOSE");break;
		case	 NUM_hist_temperament_1	:	return F("	 NUM_hist_temperament_1	");break;
		case	 NUM_REVERB_1_menu	:	return F("MANUAL I");break;
		case	 NUM_REVERB_2_menu	:	return F("MANUAL II");break;
		case	 NUM_master_level	:	return F("LEVEL");break;
		case	 NUM_reverb_type_	:	return F("TYPE");break;
		case	 NUM_pre_LPF	:	return F("PRE LPF");break;
		case	 NUM_reverb_time_ms	:	return F("REVERB TIME");break;
		case	 NUM_predelay_time	:	return F("PREDELAY");break;
		case	 NUM_delay_feedback	:	return F("DLY FEEDBACK");break;
		case	 NUM_reverb_send	:	return F("SEND LVL");break;
		case	 NUM_master_level_II	:	return F("LEVEL");break;
		case	 NUM_reverb_type_II	:	return F("TYPE");break;
		case	 NUM_pre_LPF_II	:	return F("PRE LPF");break;
		case	 NUM_reverb_time_ms_II	:	return F("REVERB TIME");break;
		case	 NUM_predelay_time_II	:	return F("PREDELAY");break;
		case	 NUM_delay_feedback_II	:	return F("DLY FEEDBACK");break;
		case	 NUM_reverb_send_II	:	return F("SEND LVL");break;
		case	 NUM_tremulant1	:	return F("RATE");break;
		case	 NUM_tremulant1_depth	:	return F("DEPTH");break;
		case	 NUM_GAIN_LOW	:	return F("LOW");break;
		case	 NUM_band_freq_low_band_0_800	:	return F("x");break;
		case	 NUM_gain_Q_low	:	return F("x");break;
		case	 NUM_GAIN_LOW_MID	:	return F("L-MID");break;
		case	NUM_band_freq_low_mid_band_0_2500	:	return F("x");break;
		case	 NUM_EQ_SELECT	:	return F("EQ");break;
		case	NUM_equalizer_gain_high_mid	:	return F("H-MID");break;
		case	NUM_equalizer_band_freq_high_mid_band_60_10700	:	return F("x");break;
		case	NUM_equalizer_gain_high	:	return F("HIGH");break;
		case	NUM_band_freq_high_band_1000_5800	:	return F("x");break;
		case	NUM_gain_Q_high	:	return F("	NUM_gain_Q_high	");break;
		case	 NUM_STOP_SELECT_menu	:	return F("PAN");break;
		case	 NUM_STOP_SELECTOR	:	return F("DECAY");break;
		case	 NUM_LEFT	:	return F("PANORAMA");break;
		case	 NUM_LEVEL	:	return F("STOP VOL");break;
		case	 NUM_TVF_RESONANCE	:	return F("FREQ GAIN");break;
		case	 NUM_TVF_CUTOFF	:	return F("FREQUENCY");break;
		case	 NUM_hist_temperament	:	return F("	 NUM_hist_temperament	");break;
		case	 NUM_STYLE	:	return F("	NUM_STYLE	");break;
		case	 NUM_mem_bank	:	return F("	 NUM_mem_bank	");break;
		case	 NUM_ROMANTIC	:	return F("	 NUM_ROMANTIC	");break;
		case	 NUM_TUNING	:	return F("	 NUM_TUNING	");break;
		case	 NUM_EQUAL	:	return F("	 NUM_EQUAL	");break;
		case	 NUM_theme	:	return F("THEME");break;
		case	 NUM_about	:	return F("ABOUT");break;
		case	 NUM_organ	:	return F("	 NUM_organ	");break;
		case	 NUM_crescendo	:	return F("	 NUM_crescendo	");break;
		case	 NUM_gen_volume	:	return F("	 NUM_gen_volume	");break;
		case	 NUM_white_black	:	return F("	 NUM_white_black	");break;
		case	 NUM_RGB_R	:	return F("RED");break;
		case	 NUM_RGB_G	:	return F("GREEN");break;
		case	 NUM_RGB_B	:	return F("BLUE");break;
		case	 NUM_en_us	:	return F("	 NUM_en_us	");break;
		case	  NUM_TEST_A	:	return F("	  NUM_TEST_A	");break;
		case	   NUM_TEST_B	:	return F("	   NUM_TEST_B	");break;
		case	  NUM_TEST_C	:	return F("	  NUM_TEST_C	");break;
		case	  NUM_TEST_D	:	return F("	  NUM_TEST_D	");break;
		case		 NUM_reverb_character_II	:	return F("CHARACTER");break;
		case		 NUM_reverb_character_I	:	return F("CHARACTER");break;
		
		case	  NUM_MAN_I_EQU	:	return F("MAN I_PED");break;
		case	  NUM_MAN_II_EQU	:	return F("MAN II");break;
		case	  NUM_EQU_HEADPHONES	:	return F("HEADPHONE");break;
		case	  NUM_EQU_SPEAKERS	:	return F("SPEAKERS");break;
		case	  NUM_MAN_I_EQU_HEADPHONES	:	return F("MAN I_PED");break;
		case	  NUM_MAN_II_EQU_HEADPHONES	:	return F("MAN II");break;
		case	  NUM_PRESETS	:	return F("PRESETS");break;
		case	  NUM_PRESETS_menu	:	return F("p_menu");break;
		case	  NUM_STOPS_LVLS_menu	:	return F("MAN LEVEL");break;
		case	  NUM_MAN_PED_LVL	:	return F("PEDAL VOL");break;
		case	  NUM_MAN_I_LVL	:	return F("MAN I VOL");break;
		case	  NUM_MAN_II_LVL	:	return F("MAN II VOL");break;
		case	  NUM_REC_PLAY_menu	:	return F("REC/PLAY");break;
		case	  NUM_REC_menu	:	return F("RECORD");break;
		case	  NUM_PLAY_menu	:	return F("PLAY");break;
		case	  NUM_PLAY_buttn	:	return F("START PLAYING");break;
		case	  NUM_REC_buttn	:	return F("START RECORDING");break;
		case	  NUM_tune_cent:	return F("TUNE");break;
		case	  NUM_special:	return F("SPECIAL");break;
		case	  NUM_swell_calibration:	return F("SWELL CALIBRATION");break;
		case	  NUM_calibration_menu:	return F("CALIBRATE");break;
		case	  NUM_save_load:	return F("MEM BANK");break;
		case	  NUM_settings:	return F("ORGAN SET");break;
		case	  NUM_organist:	return F("ORGANIST");break;
		case	  NUM_tone_selector:	return F("TONE");break;
		case	  NUM_save_buttn_dialog:	return F("SAVE TO SD CARD");break;
		case	  NUM_load_buttn_dialog:	return F("LOAD FROM SD CARD");break;
		case	  NUM_src_file:	return F("INTERNAL MEM");break;	
		case	  NUM_dest_file:	return F("SD CARD");break;
		case	  NUM_swap_keyboard:	return F("SWAP MANUAL");break;
		
		
		
		default:
		
		return F("empty");
		break;
	}
}



int MenuComponent::read_PROGMEM_info(int id_data)
{
	int var = pgm_read_byte(&(menu_item_info[_name_id][id_data]));
	//for(int x=0;x<10;x++)
	//{
	//var = pgm_read_byte(&(buttns_info[x][0]));
	//DEBUG_print("id ");
	//DEBUG_print(var);
	//var = pgm_read_byte(&(buttns_info[x][1]));
	//DEBUG_print("ch ");
	//DEBUG_print(var);
	//var = pgm_read_byte(&(buttns_info[x][2]));
	//DEBUG_print("out ");
	//DEBUG_print(var);
	//var = pgm_read_byte(&(buttns_info[x][3]));
	//DEBUG_print("common ");
	//DEBUG_println(var);
	//}
	//
	//
	//delay(100000);
	return var;
}

//bool MenuComponent::is_interactive()
//{
//return true;
//if(read_PROGMEM_info(6)==TRUE)
//return true;
//else
//return false;
////return read_PROGMEM_info(6);
//}

const __FlashStringHelper* MenuComponent::get_name()
{
	
	//DEBUG_println(F("neki name:"));
	//	return F("ffd");
	return return_name(_name_id);
	
	//return _name;
}

//const __FlashStringHelper* MenuItem::get_name2() const
//{
//
//	return _name;// _name2;
//}

void MenuComponent::set_name(__FlashStringHelper *name)
{
	//	_name = name;
}

void MenuComponent::set_interactive(bool true_false)
{
	//is_interactive = true_false;
}
int MenuComponent::get_name_id()
{
	return _name_id;
}

bool MenuComponent::is_alive()
{
	if(read_PROGMEM_info(6)==TRUE)
	{
		
		return true;
	}
	else
	{
		
		return false;
	}
}
int MenuComponent::get_x()
{
	//DEBUG_println(F("x vrednost "));
	//DEBUG_println( read_PROGMEM_info(2));
	//DEBUG_println(F("x name "));
	//
	//DEBUG_println(B1_Y);
	//DEBUG_println(B2_Y);
	//DEBUG_println(B3_Y);
	//DEBUG_println(B4_Y);
	//DEBUG_println(B5_Y);
	return read_PROGMEM_info(2);
	//return _x;
}
int MenuComponent::get_min_display_val()
{
	return read_PROGMEM_info(10);
}
int MenuComponent::get_max_display_val()
{
	return read_PROGMEM_info(11);
}
int MenuComponent::get_y()
{
	return read_PROGMEM_info(3);
	//return _y;
}

byte MenuComponent::get_type()
{
	return read_PROGMEM_info(0);
}

int MenuComponent::getMemAddress()
{
	return read_PROGMEM_info(5);
	//return _mem_address;
}

// *********************************************************
// Menu
// *********************************************************

//MenuComponent::MenuComponent(const char* label1, const char* label2, int x, int y, const char* type)
//: label1(label1), label2(label2), _x(x), _y(y), item_type(type)
//{
//}


Menu::Menu(int name_id)
: MenuComponent(_name_id),
_p_sel_menu_component(NULL),
_menu_components(NULL),
_p_parent(NULL),
_num_menu_components(0),
_cur_menu_component_num(0)
{
	_name_id=name_id;
	//_type = type_menu;
}

boolean Menu::next(int count, boolean loop)
{
	loop=false;
	//DEBUG_println(F("parent"));

	//if(this->is_alive()== false)
	//return false;
	
	//if(this->get_name_id()== NUM_root)
	//return false;
	
	if(_num_menu_components==1)
	return false;
	
	
	_p_activated_menu_component = NULL;


	if (_cur_menu_component_num != _num_menu_components - 1)
	{
		/*if (_menu_components[_cur_menu_component_num]->is_interactive == false)
		return true;
		Serial.println("tuki 1");
		if (_menu_components[_cur_menu_component_num++]->is_interactive == false)
		return true;*/
		//nariši disabled prejšnjo komponento
		
		byte tmp_checker=_cur_menu_component_num;
		bool next_ok=false;
		
		while(tmp_checker<_num_menu_components-1)
		{
			tmp_checker++;
			if (_menu_components[tmp_checker]->is_alive() == true)
			{
				next_ok=true;
				break;
			}
		}
		if(next_ok==false)
		return false;
		

		_menu_components[_cur_menu_component_num]->draw_normal();
		_cur_menu_component_num=tmp_checker;
		

		//_cur_menu_component_num++;

		if (_menu_components[_cur_menu_component_num]->is_alive() == false)
		{
			//next(1,false);
			return false;
		}

		_p_sel_menu_component = _menu_components[_cur_menu_component_num];
		//nariši enabled
		_menu_components[_cur_menu_component_num]->draw_enabled();
		return true;
	}
	else if (loop)
	{  //nariši disabled prejšnjo komponento
		//Serial.println("tuki 2");
		if (_menu_components[0]->is_alive()  == false)
		{
			next(1,false);
			return false;
		}

		_menu_components[_cur_menu_component_num]->draw_normal();

		_cur_menu_component_num = 0;
		_p_sel_menu_component = _menu_components[_cur_menu_component_num];
		//nariši enabled
		_menu_components[_cur_menu_component_num]->draw_enabled();


		return true;
	}

	return false;
}

boolean Menu::change_value(byte value)
{
	MenuComponent* tmpCom = const_cast<MenuComponent*>(this->get_selected());
	//	tmpCom->draw_enabled();

	byte temp_type = _menu_components[_cur_menu_component_num]->get_type();
	//temp_type == type_slider_double_label

	if (_menu_components[_cur_menu_component_num]->getValue() + value > 127)
	{
		_menu_components[_cur_menu_component_num]->setValue(127);
	}

	if (_menu_components[_cur_menu_component_num]->getValue()  < 0)
	{
		_menu_components[_cur_menu_component_num]->setValue(0);
	}
	_menu_components[_cur_menu_component_num]->draw_enabled();

	

	return true;
}

boolean Menu::prev(int count, boolean loop)
{
	//if(this->get_name_id()== NUM_root)
	//return false;
	loop=false;
	
	
	if(_num_menu_components==1)
	return false;
	_p_activated_menu_component = NULL;
	if (_cur_menu_component_num != 0)
	{
		//nariši disabled prejšnjo komponento
		_menu_components[_cur_menu_component_num]->draw_normal();
		_cur_menu_component_num--;

		if (_menu_components[_cur_menu_component_num]->is_alive()  == false)
		{	prev(1, false);
			return true;
		}

		_p_sel_menu_component = _menu_components[_cur_menu_component_num];
		//nariši enabled
		_menu_components[_cur_menu_component_num]->draw_enabled();

		return true;
	}
	else if (loop)
	{//nariši disabled prejšnjo komponento
		if (_menu_components[_num_menu_components - 1]->is_alive()  == false)
		{	prev(1, false);
			return true;
		}

		_menu_components[_cur_menu_component_num]->draw_normal();
		_cur_menu_component_num = _num_menu_components - 1;
		_p_sel_menu_component = _menu_components[_cur_menu_component_num];
		//nariši enabled
		_menu_components[_cur_menu_component_num]->draw_enabled();
		return true;
	}

	return false;
}

MenuComponent* Menu::activate()
{
	
	bool default_color = false;

	MenuComponent* pComponent = _menu_components[_cur_menu_component_num];

	if (pComponent->get_type() != 1)
	{
		if (_p_activated_menu_component==NULL)
		{
			_p_activated_menu_component = pComponent;
		}
		else
		{
			EEPROM.write(_p_activated_menu_component->getMemAddress(), _p_activated_menu_component->getValue());
			_p_activated_menu_component = NULL;
			default_color = true;
			//TODO: TUKAJ SHRANI SPREMEMBE
			
			//value = EEPROM.read(_mem_address);
		}
		
	}
	


	//DEBUG_print(F("type::"));
	const byte tmpL = pComponent->get_type();
	//Serial.println(pComponent->get_type());

	if (pComponent->get_type() == 1)
	tempClear();
	//pComponent->   tempClear();

	//if (dynamic_cast<Menu*>(_menu_components[_cur_menu_component_num]))
	//{
	//	for (int x = 0; x < _num_menu_components; x++)
	//	{
	//		//Serial.println("neki dela");
	//		_menu_components[x]->clear_component();
	//	}
	//}


	if (pComponent == NULL)
	return NULL;



	if (default_color)
	return pComponent->draw_enabled();
	else
	return pComponent->select();

	
	
}

MenuComponent* Menu::select()
{
	
	MenuComponent* tmpCom = const_cast<MenuComponent*>(this->get_selected());
	//tmpCom->draw_normal();
	//tmpCom->draw_enabled();
	tmpCom->draw_first_time();
	for (int x = 0; x < _num_menu_components; x++)
	{
		if(x!=this->_cur_menu_component_num)
		_menu_components[x]->draw_normal();//vse razen izbranega
	}
	return this;
}
MenuComponent* Menu::draw_first_time()
{
	if(_on_event!=NULL)
	_on_event(this,ON_FIRST_DRAW);
	//if (_on_draw_enabled != NULL)
	//_on_draw_enabled(this);
	return 0;
}
MenuComponent* Menu::draw_enabled()
{
	_on_event(this,ON_DRAW_ENABLED);
	//_on_draw_enabled(this);
	return this;
}

#define ON_SELECT 1
#define ON_DRAW_ENABLED 2
#define ON_DRAW_DISABLED 3
#define ON_CLEAR 4

MenuComponent* Menu::draw_normal()
{
	_on_event(this,ON_DRAW_DISABLED);
	//_on_draw_disabled(this);
	return this;
}
MenuComponent* Menu::draw_selected()
{
	_on_event(this,ON_SELECT);
	//_on_draw_disabled(this);
	return this;
}

MenuComponent* Menu::clear_component()
{
	_on_event(this,ON_CLEAR);
	//_on_clear(this);
	return this;
}

MenuComponent* Menu::tempClear()
{
	//Serial.println(F("menu temp clear"));
	for (int x = 0; x < _num_menu_components; x++)
	{

		_menu_components[x]->clear_component();

	}

	return this;
}
byte Menu::get_type()
{
	return type_menu;
	//return _type;
}
void Menu::reset()
{
	_p_activated_menu_component = NULL;

	for (int i = 0; i < _num_menu_components; ++i)
	_menu_components[i]->reset();
	_cur_menu_component_num = 0;
	_p_sel_menu_component = _menu_components[0];
}

byte Menu::getValue()
{};


void Menu::setValue(int _value)
{}
void Menu::addValue(int _value)
{
	
}
void Menu::setMemAddress(int address)
{}

void Menu::refresh()
{
	_p_activated_menu_component = NULL;

	for (int x = 0; x < _num_menu_components; x++)
	{
		//Serial.println("neki dela");
		_menu_components[x]->draw_normal();
	}
	MenuComponent* tmpCom = const_cast<MenuComponent*>(this->get_selected());
	tmpCom->draw_enabled();
}
void Menu::clear_current_display()
{

	for (int x = 0; x < _num_menu_components; x++)
	{
		_menu_components[x]->clear_component();
	}

}

void Menu::add_item(MenuItem* pItem, void(*on_select)(MenuItem*,byte), void(*on_draw_enabled)(MenuItem*), void(*on_draw_disabled)(MenuItem*), void(*on_clear)(MenuItem*))
{
	// Resize menu component list, keeping existing items.
	// If it fails, there the item is not added and the function returns.
	_menu_components = (MenuComponent**)realloc(_menu_components,
	(_num_menu_components + 1)
	* sizeof(MenuComponent*));
	if (_menu_components == NULL)
	return;

	_menu_components[_num_menu_components] = pItem;

	pItem->set_select_function(on_select);
	pItem->set_draw_function(on_draw_enabled);
	pItem->set_undraw_function(on_draw_disabled);
	pItem->set_clear_function(on_clear);

	if (_num_menu_components == 0)
	_p_sel_menu_component = pItem;

	_num_menu_components++;
}

Menu * Menu::get_parent()
{
	return _p_parent;
}

void Menu::set_parent(Menu* pParent)
{
	_p_parent = pParent;
}

Menu const* Menu::add_menu(Menu* pMenu, void(*on_select)(Menu*,byte), void(*on_draw_enabled)(Menu*), void(*on_draw_disabled)(Menu*), void(*on_clear)(Menu*))
{
	// Resize menu component list, keeping existing items.
	// If it fails, there the item is not added and the function returns.
	_menu_components = (MenuComponent**)realloc(_menu_components,
	(_num_menu_components + 1)
	* sizeof(MenuComponent*));
	if (_menu_components == NULL)
	return NULL;

	pMenu->set_parent(this);

	pMenu->set_select_function(on_select);
	pMenu->set_draw_function(on_draw_enabled);
	pMenu->set_undraw_function(on_draw_disabled);
	pMenu->set_clear_function(on_clear);

	_menu_components[_num_menu_components] = pMenu;

	if (_num_menu_components == 0)
	_p_sel_menu_component = pMenu;

	_num_menu_components++;

	return pMenu;
}

MenuComponent * Menu::get_menu_component(byte index)
{
	return _menu_components[index];
}

MenuComponent * Menu::get_selected()
{


	//return _menu_components[_cur_menu_component_num];
	return _p_sel_menu_component;
}

MenuComponent * Menu::get_activated()
{
	if (_p_activated_menu_component!=NULL)
	return _p_activated_menu_component;
	else return NULL;
}

byte Menu::get_num_menu_components()
{
	return _num_menu_components;
}

byte Menu::get_cur_menu_component_num()
{
	return _cur_menu_component_num;
}

void Menu::set_select_function(void(*on_select)(Menu*,byte id_mode))
{
	_on_event=on_select;
	//_on_select = on_select;
}

void Menu::set_draw_function(void(*on_draw_enabled)(Menu*))
{
	//_on_draw_enabled = on_draw_enabled;
}

void Menu::set_undraw_function(void(*on_draw_disabled)(Menu*))
{
	//_on_draw_disabled = on_draw_disabled;
}
void Menu::set_clear_function(void(*on_clear)(Menu*))
{
	//_on_clear = on_clear;
}


// *********************************************************
// MenuItem
// *********************************************************

//: _name(name), _x(x), _y(y)
MenuItem::MenuItem(int name_id)
: MenuComponent(_name_id),
_on_event(0)
{
	_name_id=name_id;
	//_type = type;
	//_mem_address = mem_address;
	value = EEPROM.read(getMemAddress());
}
MenuItem_editable::MenuItem_editable(int name_id)
: MenuItem(_name_id),
_on_event(0)
{
	_name_id=name_id;
	//_type = type;
	//_mem_address = mem_address;
	value = EEPROM.read(getMemAddress());
}
MenuItem_editable_for_tones::MenuItem_editable_for_tones(int name_id)
: MenuItem(_name_id),
_on_event(0)
{
	_name_id=name_id;
	//_type = type;
	//_mem_address = mem_address;
	value = EEPROM.read(getMemAddress());
}
void MenuItem::set_select_function(void(*on_select)(MenuItem*,byte))
{
	_on_event=on_select;
	//_on_select = on_select;
}
void MenuItem::set_draw_function(void(*on_draw_enabled)(MenuItem*))
{
	//_on_draw_enabled = on_draw_enabled;
}
void MenuItem::set_undraw_function(void(*on_draw_disabled)(MenuItem*))
{
	//_on_draw_disabled = on_draw_disabled;
}

void MenuItem::set_clear_function(void(*on_clear)(MenuItem*))
{
	//_on_clear = on_clear;
}


MenuComponent* MenuItem::select()
{
	if(_on_event!=NULL)
	_on_event(this,ON_SELECT);
	//if (_on_select != NULL)
	//_on_select(this);

	return 0;
}

MenuComponent* MenuItem::draw_first_time()
{
	if(_on_event!=NULL)
	_on_event(this,ON_FIRST_DRAW);
	//if (_on_draw_enabled != NULL)
	//_on_draw_enabled(this);
	return 0;
}
MenuComponent* MenuItem::draw_enabled()
{
	if(_on_event!=NULL)
	_on_event(this,ON_DRAW_ENABLED);
	//if (_on_draw_enabled != NULL)
	//_on_draw_enabled(this);
	return 0;
}
MenuComponent* MenuItem::draw_selected()
{
	if(_on_event!=NULL)
	_on_event(this,ON_SELECT);
	//if (_on_select != NULL)
	//_on_select(this);
	return 0;
}

MenuComponent* MenuItem::draw_normal()
{
	if(_on_event!=NULL)
	_on_event(this,ON_DRAW_DISABLED);
	//if (_on_draw_disabled != NULL)
	//_on_draw_disabled(this);
	return 0;
}

MenuComponent* MenuItem::clear_component()
{
	if(_on_event!=NULL)
	_on_event(this,ON_CLEAR);
	//if (_on_clear != NULL)
	//{
	////DEBUG_print(F("brisi"));
	//_on_clear(this);
	//}
	
	return 0;
}

MenuComponent* MenuItem::tempClear()
{
	return 0;
}

byte MenuItem::getValue()
{
	return value;
}

byte MenuItem::saveValueEEPROM()
{
	EEPROM.write(getMemAddress(),value);
	return 0;
}


byte MenuItem::get_type()
{
	return read_PROGMEM_info(4);
	//return _type;
}

void MenuItem::reset()
{
	// Do nothing.
}
void MenuItem::refreshValueFromEEPROM()
{
	value=EEPROM.read(getMemAddress());
	DEBUG_STRING_print("refreshed value:");
	DEBUG_println(value);
}

void MenuItem::setValue(int _value)
{
	int min_tick= read_PROGMEM_info(10);
	int max_tick= read_PROGMEM_info(11);
	//DEBUG_print(F("min tick:"));
	//DEBUG_print(min_tick);
	//DEBUG_print(F(" max tick:"));
	//DEBUG_print(max_tick);
	//DEBUG_print(F(" value:"));
	//DEBUG_print(_value);
	//DEBUG_print(F(" saved val:"));
	//DEBUG_println(value);
	
	if(_value<=min_tick)
	value = min_tick;
	else if(_value>=max_tick)
	value = max_tick;
	else
	value=_value;
	// Do nothing.
}
void MenuItem::addValue(int _value)
{
	//DEBUG_println(_value+value);
	setValue(_value+value);
	
}

void MenuItem::setMemAddress(int address)
{
	//_mem_address=address;
	// Do nothing.
}
void MenuItem_editable::setMemAddress(int address)
{
	_mem_address=address;
	refreshValueFromEEPROM();
	// Do nothing.
}
int MenuItem_editable::getMemAddress()
{
	return _mem_address;
}
void MenuItem_editable_for_tones::setMemAddress(int address)
{
	_mem_address=address;
	
	//value=exEEPROM.read(getMemAddress());
}
int MenuItem_editable_for_tones::getMemAddress()
{
	return _mem_address;
}

void MenuItem_editable_for_tones::setValue(int _value)
{
	//if(exEEPROM.read(getMemAddress()*200+MIDI_sender.LAST_sended_tone)!=_value)
	//exEEPROM.write(getMemAddress()*200+MIDI_sender.PREV_tone,ms.get_selected1()->getValue());
}

void MenuItem::refresh()
{
	// Do nothing.
}
// *********************************************************
// MenuSystem
// *********************************************************

MenuSystem::MenuSystem()
: _p_root_menu(NULL),
_p_curr_menu(NULL)
{
}


boolean MenuSystem::next(int count, boolean loop)
{
	return _p_curr_menu->next(count, loop);
}

boolean MenuSystem::prev(int count, boolean loop)
{
	return _p_curr_menu->prev(count, loop);
}

void MenuSystem::reset()
{
	_p_curr_menu = _p_root_menu;
	_p_root_menu->reset();
}

void MenuSystem::refresh()
{
	_p_curr_menu = _p_root_menu;
	_p_root_menu->refresh();
}

void MenuSystem::select(bool reset)
{
	DEBUG_STRING_println("current meni");
	DEBUG_println(_p_curr_menu->_menu_components[_p_curr_menu->_cur_menu_component_num]->get_name_id());
	
	

	//Serial.println("XXX pride");
	MenuComponent* pComponent = _p_curr_menu->activate();

	if (pComponent != NULL)
	_p_curr_menu = (Menu*)pComponent;
	else
	if (reset) this->reset();
	
	
}

boolean MenuSystem::back()
{


	if (_p_curr_menu != _p_root_menu)
	{
		for (int x = 0; x < _p_curr_menu->get_num_menu_components(); x++)
		{
			//Serial.println("neki dela");
			MenuComponent* tmp1 = const_cast<MenuComponent*>(_p_curr_menu->get_menu_component(x));
			tmp1->clear_component();
		}
		_p_curr_menu->reset();
		_p_curr_menu = const_cast<Menu*>(_p_curr_menu->get_parent());

		for (int x = 0; x < _p_curr_menu->get_num_menu_components(); x++)
		{
			//Serial.println("neki dela");
			MenuComponent* tmpCom = const_cast<MenuComponent*>(_p_curr_menu->get_menu_component(x));
			tmpCom->draw_normal();
		}
		MenuComponent* tmpCom = const_cast<MenuComponent*>(_p_curr_menu->get_selected());
		tmpCom->draw_enabled();
		return true;
	}

	// We are already in the root menu
	return false;
}

void MenuSystem::set_root_menu(Menu* p_root_menu)
{
	_p_root_menu = p_root_menu;
	_p_curr_menu = p_root_menu;
}

Menu * MenuSystem::get_current_menu()
{
	return _p_curr_menu;
}

boolean MenuSystem::is_root()
{

	if (_p_curr_menu->get_name_id() == _p_root_menu->get_name_id())
	return true;
	else
	return false;
}


MenuComponent * MenuSystem::get_selected1()
{

	//Serial.println("tuki");
	//if(_p_curr_menu->get_activated()!=NULL)
	//Serial.println(_p_curr_menu->get_selected()->get_name());

	//return NULL;
	//if (_p_curr_menu->get_selected() == _p_curr_menu->get_selected())

	//Serial.println("GET SELECTED");
	

	if (_p_curr_menu->get_activated() != NULL)
	{
		MenuComponent* tmpCom = const_cast<MenuComponent*>(_p_curr_menu->get_selected());
		//Serial.println(_p_curr_menu->get_activated()->get_name());
		return tmpCom;
	}
	else
	{
	}
	//Serial.println("NULL");




	//MenuComponent* tmpCom1 = const_cast<MenuComponent*>(_p_curr_menu->get_selected());
	//Serial.println(_p_curr_menu->get_activated()->get_name());

	//MenuItem * m_derivedType = dynamic_cast<MenuItem*>(tmpCom1);


	return NULL;
}


MenuItem_rec_play::MenuItem_rec_play(int name_id)
: MenuItem(_name_id),
_on_event(0)
{
	_name_id=name_id;
	value = 0;
}


void MenuItem_rec_play::setValue(int _value)
{
	value=_value;
}

byte MenuItem_rec_play::getValue()
{
	return value;
}
