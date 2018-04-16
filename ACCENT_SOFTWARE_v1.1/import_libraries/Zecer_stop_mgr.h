// zecer_mgr.h

#ifndef _ZECER_STOP_MGR_h
#define _ZECER_STOP_MGR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Button_Z.h"
#include "global_variables.h"
#include "Stop.h"
#include "Adafruit_NeoPixel.h"


//void send_tremulant_key(int key, Stops *stop_in, bool on_off, int manual, bool force_skip_check);
//bool write_mem_velocity(Stops *stop, byte note, byte velocity);
//byte read_mem_velocity(Stops *stop, byte note);
//void send_midi_key(int key, Stops *stop, bool on_off, int manual, bool force_skip_check);
//void send_midi_key_totter_single(int key, Stops *stop, bool on_off, int manual, bool force_skip_check, byte _volume);
//void send_midi_key_totter_dual(int key, Stops *stop, bool on_off, int manual, bool force_skip_check, byte _volume);
//void send_midi_key_grand_orgue(int key, Stops *stop, bool on_off, int manual, bool force_skip_check);


void on_stop_EVENT(Stop* stop,bool ON_OFF);
void on_stop_ON(Stop* stop);

void on_stop_OFF(Stop* stop);

void on_Stop_oktav_OFF(Stop* stop);
byte read_mem_velocity_test_out(Stop *stop, byte note);
void on_stop_tremulant_ON(Stop* stop);
void on_stop_tremulant_OFF(Stop* stop);
void on_foot_piston(Button_z* buttn);
void on_foot_piston_deselect(Button_z* buttn);
void dummy_method(Button_z* buttn);

void load_ordinary_stop_output(Stop* stop);
void on_buttn_EVENT(Button_z* buttn,bool ON_OFF);
void on_buttn_10(Button_z* buttn);
void on_buttn_10_deselect(Button_z* buttn);
void on_buttn_100(Button_z* buttn);
void on_buttn_100_deselect(Button_z* buttn);
void check_previous_combination();
void on_buttn_PLUS(Button_z* buttn);
void on_buttn_PLUS_deselect(Button_z* buttn);
void on_buttn_MINUS(Button_z* buttn);
void on_buttn_MINUS_deselect(Button_z* buttn);
void on_buttn_FIX_COMBINATION(Button_z* buttn);
void on_buttn_FIX_COMBINATION_deselect(Button_z* buttn);
void on_buttn_RESET(Button_z* buttn);
void on_buttn_RESET_deselect(Button_z* buttn);
void on_buttn_SET(Button_z* buttn);
void on_buttn_SET_deselect(Button_z* buttn);
void on_buttn_combination(Button_z* buttn);
void on_buttn_combination_deselect(Button_z* buttn);
void on_buttn_on_off(Button_z* buttn);
void on_buttn_on_off_deselect(Button_z* buttn);
void on_Stop_dummy(Stop* stop);
void help_refresh_note_manual(byte MANUAL_ID,byte OUT_ID,byte COMMON_CH);

class Zecer_stop_mgr
{


	public:
	#ifdef RGB_LED_OUTPUT
	//Adafruit_NeoPixel RGB_STOP1_OUT = Adafruit_NeoPixel(STOP_num, 12, NEO_GRB + NEO_KHZ800);
	
	#endif
//Adafruit_NeoPixel RGB_SETTER_OUT;// = Adafruit_NeoPixel(STOP_num, DATA_595_Z, NEO_GRB + NEO_KHZ800);

	
	bool allow_refresh=true;
	int current_combination = 0;
	//Zecer_stop_mgr();
	void Zecer_stop_mgr_init();

	void inputCheck();
	void help_edit_array(byte stop_id,byte *orgArray,byte *destArray,byte ini_start_value,byte ini_end_value);
//void help_keyrecorder(byte *buttn_tab_HIGH, byte *buttn_tab_old_HIGH,byte *buttn_tab_LOW, byte *buttn_tab_old_LOW, byte _MANUAL);
	//void help_edit_array_SUB_SUP(byte stop_id,byte orgArray[],byte destArray[],byte ini_start_value,byte ini_end_value,int sum_number);
	void help_edit_array_SUB_SUP(byte stop_id,byte copy_low_array[], byte high_array[],byte high_array_old[],byte low_array[],byte low_array_old[],byte ini_start_value,byte ini_end_value,byte sum_number);
	void help_edit_for_BASS(byte *orgArray,byte *destArray,byte ini_start_value,byte ini_end_value);
	void help_edit_for_MELODY(byte *orgArray,byte *destArray,byte ini_start_value,byte ini_end_value);

	void Stop_headphones_change(boolean on_off);
	//void help_refresh_note_manual(byte MANUAL_ID);
	void help_refresh_note(Stop* stop,bool note_on_off);
	void read_Keyboards();
		//void read_KeyboardsB();
	void read_gas_pedal();
	void on_test(String text);
	void read_master_volume();
	//void send_midi_MASTER_volume_change();
	//void read_zecer();
	void read_MIDIC_pedal();
	//void knobRead();
	void change_style(byte style);
	//void mute_manual(Stop* stop,byte manual);
	//void mute_all_sounds();
	//void send_reverb(byte value_, byte REVERB_command);
	//void init_TOTTER();
	//void equalizer_set(int ADDRESS_id, int value);

	//void load_SDK_output(byte* output);
	/*bool write_mem_stop_volume(Stops *stop, byte velocity);
	bool write_mem_velocity(Stops *stop, byte note, byte velocity);
	bool read_mem_velocity(Stops *stop, byte note, byte *variable);*/

	//int return_stop_by_id(int id);

	//void sendStopList();
	//void add_button_Z(Button_z* button);
	//void add_stop(Stop* button);
	
	int calibrate_gas1_min(int value);
	int calibrate_gas1_max(int value);
	//Button_z** Button_Z_list;
	//Stops** Stops_list;


	//void set_select_function(void(*on_select)(Button_z*));

	/*void on_buttn_combination(Button_z* buttn);
	
	void on_buttn_SET(Button_z* buttn);*/
	/*
	void on_buttn_combination(Button_z* buttn);
	void on_buttn_PLUS(Button_z* buttn);
	void on_buttn_MINUS(Button_z* buttn);
	void on_buttn_fix_combination(Button_z* buttn);
	void on_buttn_RESET(Button_z* buttn);*/

	


	protected:
	bool _readBit(byte variable[], int position);
	bool _readBit(byte variable[], byte position);
	bool _writeBit(byte variable[], int position, bool state);
	//void calculate();
	void(*_on_select)(Zecer_stop_mgr*);

byte id_low=255;
byte id_low_old=255;

	byte _bass_1=255;
	byte _bass_2=255;
	
	byte _melod_1=255;
	byte _melod_2=255;
	
	byte last_melody=0;

	byte button_list_array[20];

	

	int tempcount;

	int vol_temp;


	int vol_max = 0;
	int vol_min = 1023;

	int gas1_max = 0;
	int gas1_min = 1023;

	int gas2_max = 0;
	int gas2_min = 1023;


};


#endif

