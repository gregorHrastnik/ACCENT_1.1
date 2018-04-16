// global_methods.h

#ifndef _GLOBAL_METHODS_h
#define _GLOBAL_METHODS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"


   // #include "MIDI.h"
#else
	#include "WProgram.h"
#endif

#include "SD_mgr.h"
#include "Zecer_stop_mgr.h"
#include "MIDI_mgr.h"
#include "arduino2.h"
#include "Stop_mgr.h"
#include "Zecer_mgr.h"
//#include "LCD_mgr.h"
#include "SPIEEP.h"
#include "menu_mgr.h"

//



extern MIDI_mgr MIDI_sender;
extern Zecer_stop_mgr Z_S_mgr;
extern menu_mgr MENU_mgr;
extern Stop_mgr STOP_mgr;
extern SD_mgr  SD_work;
extern Zecer_mgr  ZECER;
//extern LCD_mgr DISPLAY_mgr;
//extern byte map_tabela_Z[64];
//extern byte map_tabela_zecer[64];
bool _readBit_normal(byte variable[], int position);
bool _writeBit_normal(byte variable[], int position, bool state);

bool _readBit_load(byte variable[], int position);
bool _readBit_stop(byte variable[], int position);
bool _writeBit_stop(byte variable[], int position, bool state);
//byte get_map_tabela_zecer(int position);
//byte get_map_Z_buttn_id(int position);
byte get_map_tabela_Z(int position);
byte get_key_map(int position);


bool write_mem(int _mem_location, byte *variable);
void setTheme(int theme);
byte return_oktav_mode(Stop* stop);
void print_note_velocity(Stop *stop);
byte read_mem_velocity(Stop *stop, byte note);
byte write_EEPROM_from_progmem();
byte write_to_EEPROM_from_PROGMEM(int* location, int destination_eeprom, int length);
byte read_STOP_velocity(Stop *stop, byte oktav_mode);
byte read_mem_velocity_progmem(Stop *stop, byte note);
byte read_STOP_velocity_progmem(Stop *stop,byte oktav_mode);
void write_STOP_velocity(Stop *stop, byte note, byte oktav_mode);
void EEPROMWriteLong(int address, long value);
long EEPROMReadlong(long address);

bool write_mem_stop_volume1(Stop *stop, byte velocity);
bool write_mem_velocity(Stop *stop, byte note, byte velocity);


byte write_mem_velocity_from_PROGMEM(Stop *stop);

void load_SDK_output(byte* output); 
void load_SDK_output_all(byte* output);
void load_zecer_output(byte* output);
void calculate_free_RAM(int id);

void manubri_na_nulo();
void zecer_na_nulo();
String get_tone_name(int id);


byte G_bit(byte *_array,byte key);
void S_bit(byte *_array,byte key,byte _state);
void test_bit(byte key);


String get_stop_name(byte id);
void get_splited_float_arr(char *splitted_float,long value);
long return_float(char *splitted_float);
 unsigned long return_float_from_3_byte(byte *splitted);
//void send_midi_key(int key, Stops *stop, bool on_off, int manual, bool force_skip_check);
//
//void send_midi_volume_change(Stops *stop, byte volume);
//
//void send_tremulant_key(int key, Stops *stop, bool on_off, int manual, bool force_skip_check);
//


#endif

