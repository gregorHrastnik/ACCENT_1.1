// Stop_mgr.h
//#include "Definitions_settings.h"
#include "global_variables.h"
////#include "global_methods.h"
//#include <SoftwareSerial.h>
//#include <MIDI.h>
//#include "arduino2.h"
//#include "EEPROM.h"
//#include <Encoder.h>
//#include "SD_mgr.h"
//#include <avr\pgmspace.h>
//#include "PROGMEM_labels.h"
#include "Stop.h"







#ifndef _STOP_MGR_h
#define _STOP_MGR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif






extern Stop empty;

class Stop_mgr
{


public:

	int current_combination = 0;
	//Stop_mgr();
	void Stop_mgr_init(void(*on_stop_EVENT)(Stop*,bool), void(*on_stop_OFF)(Stop*), void(*on_Stop_oktav_OFF)(Stop*), void(*on_stop_tremulant_ON)(Stop*), void(*on_stop_tremulant_OFF)(Stop*));
	void link_id(byte stop_name, byte connect_to_id);
	//void load_stops_combination(byte* combination);
	//Stop** STOPS;
	void read_stopsNormal();
	//void read_stopsL();
	//void read_stopsR();
	byte Stop_count = 55;
//	void show_output();

	Stop* id(int id);
	Stop* linked_id(int stop_name);
	bool CHECK_stop_init(int stop_name);

	void set_disposition(byte model_name);
	bool refresh_STOP_OUTPUT=true;

	byte CURRENT_stop;
	byte PREV_stop;
private:
	byte link_tab[80];
	Stop* STOPS[56];
	void add_stop(Stop* stop);

	byte _num_buttons_Stops;
	
//
	//byte current_OKTAV_MODE_man1 = OKTAV_SINGLE_NOTE;
	//byte current_OKTAV_MODE_man2 = OKTAV_SINGLE_NOTE;
	//byte current_OKTAV_MODE_man3 = OKTAV_SINGLE_NOTE;

	

	
};


#endif

