// Zecer_mgr.h
#include "global_variables.h"
#include "Stop.h"
#include "Button_Z.h"

#ifndef _ZECER_MGR_h
#define _ZECER_MGR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define SETTER_ALL_INIT_NUM 87

class Zecer_mgr
{


public:
	byte OUT_array[20];
	byte BUTTN_NUM = 87;
	int current_combination = 0;
	//Stop_mgr();
	void Zecer_mgr_init(void(*on_event_B)(Button_z*,bool));
	void link_id(byte buttn_name, byte connect_to_id);
	////////////////////

	//void load_zecer_combination(byte* combination);
	void read_input();
	//void temp_set_outArray(byte* Array);
	

	Button_z* id(int id);
	Button_z* linked_id(int buttn_name);

	void set_disposition(byte zecer_model);
	byte link_tab[100];
	//byte link_tab_out[120];
private:
	//byte link_tab[120];
	Button_z* _BUTTNS[89];
	void add_buttn(Button_z* buttn);


};


















#endif

