// Button_Z.h

#ifndef _BUTTON_Z_h
#define _BUTTON_Z_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Definitions.h"






const int buttns_info[][6] PROGMEM = {
	{BUTTN_DUMMY,NOT_USED, NOT_USED, on_buttn_combination_f, on_buttn_combination_deselect_f,class_NULL},
	{BUTTN_1, 10,1, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_2, 20,2, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_3, 30,3, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_4, 40,4, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_5, 50,5, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_6, 60,6, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_7, 70,7, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_8, 80,8, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_9, 90,9, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_10, 100,10, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_11, 110, 11,on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_12, 120,12, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_13, 130,13, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_14, 140,14, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_15, 150,15, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_16, 160,16, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_17, 170,17, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_18, 180,18, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_19, 190,19, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_20, 200,20, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_21, 210,21, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_22, 220,22, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_23, 230,23, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_24, 240,24, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_25, 250,25, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_26, 260,26, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_27, 270,27, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_28, 280,28, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_29, 290,29, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_30, 300,30, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_31, 310,31, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{BUTTN_32, 320,32, on_buttn_combination_f, on_buttn_combination_deselect_f,class_COMBINATION},
	{COM_MAN_I_1, 1010,COM_MAN_I_1, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_1},
	{COM_MAN_I_2, 1020,COM_MAN_I_2, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_1},
	{COM_MAN_I_3, 1030,COM_MAN_I_3, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_1},
	{COM_MAN_I_4, 1040,COM_MAN_I_4, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_1},
	{COM_MAN_I_5, 1050,COM_MAN_I_5, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_1},
	{COM_MAN_I_6, 1060,COM_MAN_I_6, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_1},
	{COM_MAN_II_1, 1070,COM_MAN_II_1, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_2},
	{COM_MAN_II_2_, 1080,COM_MAN_II_2_, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_2},
	{COM_MAN_II_3, 1090,COM_MAN_II_3, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_2},
	{COM_MAN_II_4, 1100,COM_MAN_II_4, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_2},
	{COM_MAN_II_5, 1110,COM_MAN_II_5, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_2},
	{COM_MAN_II_6, 1120,COM_MAN_II_6, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_2},
	{COM_MAN_III_1, 1130,NOT_USED, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_3},
	{COM_MAN_III_2, 1140,NOT_USED, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_3},
	{COM_MAN_III_3, 1150,NOT_USED, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_3},
	{COM_MAN_III_4, 1160,NOT_USED, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_3},
	{COM_MAN_III_5, 1170,NOT_USED, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_3},
	{COM_MAN_III_6, 1180,NOT_USED, on_buttn_combination_f, on_buttn_combination_deselect_f, class_FIX_COMBINATION_MAN_3},
	{BUTTN_SET_1, noMEM,NOT_USED, on_buttn_SET_f, on_buttn_SET_deselect_f, class_SET},
	{BUTTN_SET_2, noMEM,NOT_USED, on_buttn_SET_f, on_buttn_SET_deselect_f, class_SET},
	{BUTTN_SET_3, noMEM,NOT_USED, on_buttn_SET_f, on_buttn_SET_deselect_f, class_SET},
	{BUTTN_MINUS_1, noMEM,NOT_USED,  on_buttn_MINUS_f, on_buttn_MINUS_deselect_f,class_MINUS},
	{BUTTN_MINUS_2, noMEM,NOT_USED, on_buttn_MINUS_f, on_buttn_MINUS_deselect_f,class_MINUS},
	{BUTTN_MINUS_3, noMEM,NOT_USED, on_buttn_MINUS_f, on_buttn_MINUS_deselect_f,class_MINUS},
	{BUTTN_PLUS_1, noMEM ,NOT_USED, on_buttn_PLUS_f, on_buttn_PLUS_deselect_f,class_PLUS},
	{BUTTN_PLUS_2, noMEM,NOT_USED, on_buttn_PLUS_f, on_buttn_PLUS_deselect_f,class_PLUS},
	{BUTTN_PLUS_3, noMEM,NOT_USED, on_buttn_PLUS_f, on_buttn_PLUS_deselect_f,class_PLUS},
	{BUTTN_10_1, noMEM,NOT_USED, on_buttn_10_f, on_buttn_10_deselect_f,class_10},
	{BUTTN_10_2, noMEM,NOT_USED, on_buttn_10_f, on_buttn_10_deselect_f,class_10},
	{BUTTN_10_3, noMEM,NOT_USED, on_buttn_10_f, on_buttn_10_deselect_f,class_10},
	{BUTTN_100_1, noMEM,NOT_USED, on_buttn_100_f, on_buttn_100_deselect_f,class_100},
	{BUTTN_100_2, noMEM,NOT_USED, on_buttn_100_f, on_buttn_100_deselect_f,class_100},
	{BUTTN_100_3, noMEM,NOT_USED, on_buttn_100_f, on_buttn_100_deselect_f,class_100},
	{BUTTN_RESET_1, noMEM,NOT_USED, on_buttn_RESET_f, on_buttn_RESET_deselect_f,class_RESET},
	{BUTTN_RESET_2, noMEM,NOT_USED, on_buttn_RESET_f, on_buttn_RESET_deselect_f,class_RESET},
	{BUTTN_RESET_3, noMEM,NOT_USED, on_buttn_RESET_f, on_buttn_RESET_deselect_f,class_RESET},
	{BUTTN_CR_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f, class_FOOT_LINK},
	{BUTTN_III_II_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f, class_FOOT_LINK},
	{BUTTN_III_I_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f, class_FOOT_LINK},
	{BUTTN_II_I_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f, class_FOOT_LINK},
	{BUTTN_III_PED_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f, class_FOOT_LINK},
	{BUTTN_II_PED_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f, class_FOOT_LINK},
	{BUTTN_I_PED_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f, class_FOOT_LINK},
	{BUTTN_Z_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f, class_FOOT_LINK},
	{BUTTN_PP_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f,class_FIX_COMBINATION_MAN_1},
	{BUTTN_P_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f,class_FIX_COMBINATION_MAN_1},
	{BUTTN_MF_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f,class_FIX_COMBINATION_MAN_1},
	{BUTTN_F_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f,class_FIX_COMBINATION_MAN_1},
	{BUTTN_FF_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f,class_FIX_COMBINATION_MAN_1},
	{BUTTN_T_foot, noMEM,NOT_USED, on_foot_piston_f, on_foot_piston_deselect_f,class_FIX_COMBINATION_MAN_1},
	{BUTTN_PLUS_foot, noMEM,NOT_USED, on_buttn_PLUS_f, on_buttn_PLUS_deselect_f, class_FOOT_FIXED},
	{BUTTN_MINUS_foot, noMEM,NOT_USED, on_buttn_MINUS_f, on_buttn_MINUS_deselect_f, class_FOOT_FIXED},
	{BUTTN_RESET_foot, noMEM,NOT_USED, on_buttn_RESET_f, on_buttn_RESET_deselect_f, class_FOOT_FIXED},//PREVERI
	{BUTTN_BASS, noMEM,NOT_USED, on_buttn_SET_f, on_buttn_SET_deselect_f, class_ON_OFF},
	{BUTTN_MELODY, noMEM,NOT_USED, on_buttn_SET_f, on_buttn_SET_deselect_f, class_ON_OFF}
};




class Button_z
{

public:
	//byte *_button_list_array;

	//Zecer_stop_mgr * m_parent;
	//Button_z** _button_list;
	//Stops **_stop_list;

	//byte id_class;
	
	//byte _id_out;
	//bool out_state=false;
	//byte _id_num=200;
	
	void select(bool on_off);
	void SetState(bool on_off);
	bool GetState();
	int _mem_location;
	

	byte get_id();
	int get_mem_location();
	void set_mem_location(int address);
	byte get_id_class();
	bool get_out_state();
	void set_out_state(bool ON_OFF);
	byte get_id_num();
	byte get_BUTTN_type();
	
	
	void set_out_state();

//	int get_mem_location();
	Button_z(byte id, int mem_location, byte set_class, void(*on_select)(Button_z*,bool));

//	void set_list(byte *button_list_array, Button_z** button_list);

	bool set_NUM(byte number);
	bool read_mem(byte *variable);
	bool write_mem(byte *variable);
	bool write_mem_num_location(byte *variable, byte num_combination, int first_mem_location);
	bool read_mem_num_location(byte *variable, byte num_combination, int first_mem_location);

private:
	byte read_PROGMEM_info(byte id_data);
	//void(*_on_select)(Button_z*);
	//void(*_on_deselect)(Button_z*);
	
	void(*_on_event)(Button_z*,bool ON_OFF);
	void set_state(bool ON_OFF);
	bool get_state();	
	void set_temp_state(bool ON_OFF);
	bool get_temp_state();
	//bool _temp_state;
	//bool _state;
	byte multi_var=0;
	byte _id;

};



#endif

