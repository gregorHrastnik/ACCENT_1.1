//
//
//

#include "global_variables.h"
#include "EEPROM.h"
#include "SpiRam_Extended.h"








bool  CRESCENDO_STATE=false;
bool  Z_STATE = false;
int   SETTER_combination=0;
//bool RECORDING = false;
bool extern_eeprom_ok=false;

//const __FlashStringHelper*  get_tone_name(int id)
//{
	//String name=F("");
	//int cmp=id%12;
//
	//switch (cmp)
	//{
		//case C:
		//name=" ";
		//break;
		////case Cis:
		////name=F("C#");
		////break;
		////case D:
		////name=F("D");
		////break;
		////case Dis:
		////name=F("D#");
		////break;
		////case E:
		////name=F("E");
		////break;
		////case F:
		////name=F("F");
		////break;
		////case Fis:
		////name=F("F#");
		////break;
		////case G:
		////name=F("G");
		////break;
		////case Gis:
		////name=F("G#");
		////break;
		////case A:
		////name=F("A");
		////case Aeis:
		////name=F("A");
		////break;
		////case B:
		////name=F("B");
		////break;
	//};
	//int num_count=id/12;
	//name+=String(num_count);
	//return name;
//}

extern SPIEEP exEEPROM(16, 128, 65536);
extern SpiRAM exRAM(SPI_CLOCK_DIV4, A6, CHIP_23LC1024);
SoftwareSerial softSerial(A14, A15); // RX, TX

#ifndef EXCLUDE_SPIRAM
// SPIRAMVAlloc valloc(4096l * 8l, false, A6, SerialRam::SPEED_FULL);
#endif
//zecer
//int clock = 13;


//arduino mega plata

float last_time_interacted=millis();
float last_time_interacted_zecer=millis();

byte USER_ID=EEPROM.read(add_VALUE_SELECTED_USER);
byte USER_ID_old=255;
byte _THEME=0;

int gas1_temp;
int gas2_temp;

byte  preklop_MIDI1[2];
byte preklop_MIDI2[2];
byte  preklop_MIDI3[2];
byte preklop_MIDI4[2];

//String COMBINATION_LABEL_TEXT="TEST";
//String COMBINATION_LABEL_TEXT_old;
String FILENAME_PATH="";
#ifdef TRIPLE_SETTER
String COMBINATION_LABEL_Z_letter = "Z on";

#else
String COMBINATION_LABEL_Z_letter = "";
#endif // TRIPLE_SETTER


char COMBINATION_string[]="loading";
char COMBINATION_string_old[]=" ";
String COMBINATION_LABEL_FIRST_letter = "LOADING..";
String COMBINATION_LABEL_FIRST_letter_old = "";
int value_TRANSPOSE =TRANS_adjust;//da je na 0 // EEPROM.read(add_VALUE_TRANSPOSE);
byte HEADPHONE_FIX=0;
//String TRANSPOSE_LABEL_TEXT = (String)((int)(value_TRANSPOSE-TRANS_adjust));
//String TRANSPOSE_LABEL_TEXT_old;

//String REVERB_LABEL_TEXT = (String)EEPROM.read(add_VALUE_REVERB);
//String REVERB_LABEL_TEXT_old;

//String key_LABEL_TEXT = " ";
//String key_LABEL_TEXT_old;
//
//String stop_LABEL_TEXT = " ";
//String stop_LABEL_TEXT_old;
//
//byte ID_last_stop = EMPTY;
//byte ID_last_note = EMPTY;
byte TEMPER_SELECTED=0;//po defaulti naj bojo 0
int HERTZ_SELECTED=-20;

byte MASTER_VOLUME=50;
byte GAS_PED_1=10;
byte GAS_PED_2 = 10;
byte GAS_PED_man2 = 10;


//29 je za prvo programiranje

//bool master_volume_show = false;



void init_global_values()
{
	preklop_MIDI1[0] = 0xF5;
	preklop_MIDI1[1] = 0x01;

	preklop_MIDI2[0] = 0xF5;
	preklop_MIDI2[1] = 0x02;


	preklop_MIDI3[0] = 0xF5;
	preklop_MIDI3[1] = 0x03;


	preklop_MIDI4[0] = 0xF5;
	preklop_MIDI4[1] = 0x04;

}



byte line_color[3];
byte back_color[3];
byte check_color[3];
byte select_color[3];
byte info_color[3];

byte RGB_STOP_COLOR[3];




//
//bool k_readPin[32];
//bool k_buttonOne[90];
//bool k_oldButtonOne[90];
//bool k_buttonTwo[90];
//bool k_oldButtonTwo[90];
//bool k_buttonThree[90];
//bool k_oldButtonThree[90];
//bool p_button[90];
//bool p_oldButton[90];
//bool tempButton[90];


byte k_readPin[12];

byte k_MAN_I_H[key_arr_size];
byte k_MAN_I_H_old[key_arr_old_size];

byte k_MAN_II_H[key_arr_size];
byte k_MAN_II_H_old[key_arr_old_size];

byte k_MAN_III_H[key_arr_size];
byte k_MAN_III_H_old[key_arr_old_size];

//byte k_MAN_IV[90];
//byte k_MAN_IV_old[90];
//
//byte k_MAN_V[90];
//byte k_MAN_V_old[90];

byte k_PED[key_arr_size];
byte k_PED_old[key_arr_old_size];


byte k_MAN_I_L[key_arr_size];
byte k_MAN_I_L_old[key_arr_old_size];

byte k_MAN_II_L[key_arr_size];
byte k_MAN_II_L_old[key_arr_old_size];

byte k_MAN_III_L[key_arr_size];
byte k_MAN_III_L_old[key_arr_old_size];

byte bass_prev[key_arr_size];

//byte k_MAN_IV_L[90];
//byte k_MAN_IV_old_L[90];
//
//byte k_MAN_V_L[90];
//byte k_MAN_V_old_L[90];


byte k_PED_recorder[key_arr_size];
byte k_PED_old_recorder[key_arr_old_size];


byte k_MAN_I_L_recorder[key_arr_size];
byte k_MAN_I_L_old_recorder[key_arr_old_size];

byte k_MAN_II_L_recorder[key_arr_size];
byte k_MAN_II_L_old_recorder[key_arr_old_size];

byte k_MAN_III_L_recorder[key_arr_size];
byte k_MAN_III_L_old_recorder[key_arr_old_size];


byte tempButton[key_arr_old_size];
