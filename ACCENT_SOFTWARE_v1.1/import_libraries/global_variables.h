// global_variables.h
#include "Definitions_pins.h"
#include "Definitions.h"

#include "Definitions_settings.h"
#include "SoftwareSerial.h"


//#include <Arduino.h>
//#include <virtmem.h>
//#include <SPI.h>
//#include <serialram.h>
//#include <alloc/spiram_alloc.h>

#ifndef _GLOBAL_VARIABLES_h
#define _GLOBAL_VARIABLES_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


#ifdef MODEL_GRANDIOSO_232T//NAVADNI z enojnim zecerjem
#define  NAVADNA_REGISTRACIJA
#define STOP_num  48
#define  STOP_type  LED_MANUBRI
#define ZECER_num  32
#define GAS1_pin A13
#define GAS2_pin A14
#define stop_R_num 8
#define stop_L_num 8
#define ZECER_1X
//#define ZECER_2X_AMERIKA

#endif // _RODGERS

#ifdef MODEL_FESTOSO_232T//NAVADNI z enojnim zecerjem
#define  NAVADNA_REGISTRACIJA
#define STOP_num  48
#define  STOP_type  LED_MANUBRI
#define ZECER_num  64
#define GAS1_pin A13
#define GAS2_pin A14
#define stop_R_num 8
#define stop_L_num 8
//#define ZECER_1X
#define ZECER_2X_AMERIKA

#endif // _RODGERS



#ifndef EXCLUDE_SPIRAM
//using namespace virtmem;
//extern SPIRAMVAlloc valloc;

#endif
//extern SPIRAMVAlloc valloc;
#include "SPIEEP.h"
#include "SpiRam_Extended.h"
extern SoftwareSerial softSerial; // RX, TX
extern SPIEEP exEEPROM;
extern SpiRAM exRAM;
/////////////////////////////////////////


//Globalne spremenljivke
/////////////////////////////////////////



/////////////////////////////////////////



/////////////////////////////////////////

#ifdef SERIAL_MONITOR_DEBUG
#define DEBUG_print_HEX(x)  softSerial.print (x,HEX)
#else
#define  DEBUG_print_HEX(x)
#endif

#ifdef SERIAL_MONITOR_DEBUG
#define DEBUG_print(x)  softSerial.print (x)
#else
#define  DEBUG_print(x)
#endif

#ifdef SERIAL_MONITOR_DEBUG
#define DEBUG_println(x)  softSerial.println (x)
#else
#define DEBUG_println(x)
#endif

#ifdef SERIAL_MONITOR_DEBUG
#define DEBUG_STRING_print(x)  softSerial.print (F(x))
#else
#define  DEBUG_STRING_print(x)
#endif

#ifdef SERIAL_MONITOR_DEBUG
#define DEBUG_STRING_println(x)  softSerial.println (F(x))
#else
#define DEBUG_STRING_println(x)
#endif

#ifdef TEMP_DEBUG
#define TEMP_DEBUG_print(x)  softSerial.print (x)
#else
#define TEMP_DEBUG_print(x)
#endif

#ifdef TEMP_DEBUG
#define TEMP_DEBUG_println(x)  softSerial.println (x)
#else
#define TEMP_DEBUG_println(x)
#endif


extern bool extern_eeprom_ok;
//extern bool RECORDING;
extern bool  CRESCENDO_STATE;
extern bool  Z_STATE;

extern byte  MODUL_1_ranks;//enabled stops counter
extern byte  MODUL_2_ranks;
extern byte  MODUL_3_ranks;
extern byte  MODUL_4_ranks;

extern bool  MODUL_1_ranks_LOW_MODE;//enabled stops counter
extern bool  MODUL_2_ranks_LOW_MODE;
extern bool  MODUL_3_ranks_LOW_MODE;
extern bool  MODUL_4_ranks_LOW_MODE;

extern int   SETTER_combination;

extern byte HEADPHONE_FIX;
extern int value_TRANSPOSE;
extern byte ID_last_stop;
extern byte ID_last_note;
extern byte MASTER_VOLUME;
extern byte GAS_PED_1;
extern byte GAS_PED_2;
extern byte GAS_PED_man2;

extern bool GAS1_refresh;
extern bool GAS2_refresh;
extern bool GAS2_ped_refresh;
extern bool MASTER_VOL_refresh;

extern byte TEMPER_SELECTED;
extern int HERTZ_SELECTED;

extern byte MASTER_VOLUME;

extern byte USER_ID;
extern byte USER_ID_old;
extern byte _THEME;
extern int gas1_temp;
extern int gas2_temp;
extern int VALUE_TRANSPOSE;

extern float last_time_interacted;
extern float last_time_interacted_zecer;


extern char COMBINATION_string[];
extern char COMBINATION_string_old[];
//extern String COMBINATION_LABEL_TEXT;
//extern String COMBINATION_LABEL_TEXT_old;
extern String  FILENAME_PATH;

extern String COMBINATION_LABEL_FIRST_letter;
extern String COMBINATION_LABEL_FIRST_letter_old;

//extern String TRANSPOSE_LABEL_TEXT;
//extern String TRANSPOSE_LABEL_TEXT_old;
//extern String REVERB_LABEL_TEXT;
//extern String REVERB_LABEL_TEXT_old;

//extern String key_LABEL_TEXT;
//extern String key_LABEL_TEXT_old;
//
//extern String stop_LABEL_TEXT;
//extern String stop_LABEL_TEXT_old;
//
//extern char* COMBINATION_LABEL_TEXT;
//extern bool master_volume_show;

extern byte preklop_MIDI1[2];
extern byte preklop_MIDI2[2];
extern byte preklop_MIDI3[2];
extern byte preklop_MIDI4[2];

void init_global_values();

extern byte line_color[3];
extern byte back_color[3];
extern byte check_color[3];
extern byte select_color[3];
extern byte info_color[3];
extern byte RGB_STOP_COLOR[3];



//extern bool k_readPin[32];
//extern bool k_buttonOne[90];
//extern bool k_oldButtonOne[90];
//extern bool k_buttonTwo[90];
//extern bool k_oldButtonTwo[90];
//extern bool k_buttonThree[90];
//extern bool k_oldButtonThree[90];
//extern bool p_button[90];
//extern bool p_oldButton[90];
//extern bool tempButton[90];

extern byte k_readPin[12];

extern byte k_MAN_I_H[key_arr_size];
extern byte k_MAN_I_H_old[key_arr_old_size];

extern byte k_MAN_II_H[key_arr_size];
extern byte k_MAN_II_H_old[key_arr_old_size];

extern byte k_MAN_III_H[key_arr_size];
extern byte k_MAN_III_H_old[key_arr_old_size];

//extern byte k_MAN_IV[90];
//extern byte k_MAN_IV_old[90];
//
//extern byte k_MAN_V[90];
//extern byte k_MAN_V_old[90];

extern byte k_PED[key_arr_size];
extern byte k_PED_old[key_arr_old_size];
extern byte tempButton[key_arr_size];

extern byte bass_prev[key_arr_size];

extern byte k_MAN_I_L[key_arr_size];
extern byte k_MAN_I_L_old[key_arr_size];

extern byte k_MAN_II_L[key_arr_size];
extern byte k_MAN_II_L_old[key_arr_old_size];

extern byte k_MAN_III_L[key_arr_size];
extern byte k_MAN_III_L_old[key_arr_old_size];

extern byte k_PED_recorder[key_arr_size];
extern byte k_PED_old_recorder[key_arr_old_size];


extern byte k_MAN_I_L_recorder[key_arr_size];
extern byte k_MAN_I_L_old_recorder[key_arr_old_size];

extern byte k_MAN_II_L_recorder[key_arr_size];
extern byte k_MAN_II_L_old_recorder[key_arr_old_size];

extern byte k_MAN_III_L_recorder[key_arr_size];
extern byte k_MAN_III_L_old_recorder[key_arr_old_size];




//extern byte k_MAN_IV_L[90];
//extern byte k_MAN_IV_old_L[90];
//
//extern byte k_MAN_V_L[90];
//extern byte k_MAN_V_old_L[90];



const byte array_PP_ldk[] PROGMEM = { 32, 0, 128, 0, 80, 0, 199, 199, 199, 199 };
const byte array_P_ldk[] PROGMEM = { 52, 1, 144, 0, 84, 0, 199, 199, 199, 199 };
const byte array_FF_ldk[] PROGMEM = { 119, 1, 156, 0, 92, 0, 199, 199, 199, 199 };
const byte array_MF_ldk[] PROGMEM = { 255, 17, 189, 22, 126, 0, 199, 199, 199, 199 };
const byte array_F_ldk[] PROGMEM = { 255, 145, 191, 22, 127, 0, 199, 199, 199, 199 };
const byte array_T_ldk[] PROGMEM = { 255, 255, 255, 255, 255, 255, 199, 199, 199, 199 };
const byte array_Z_ldk[] PROGMEM = { 192, 136, 0, 0, 3, 8, 1, 0, 0, 0 };

//const byte array_T_ldk[] PROGMEM = { 255, 253, 191, 247, 255, 192, 199, 199, 199, 199 };

const byte array_PP_sdk[] PROGMEM = { 32, 0, 128, 0, 80, 0, 199, 199, 199, 199 };
const byte array_P_sdk[] PROGMEM = { 52, 1, 144, 0, 84, 0, 199, 199, 199, 199 };
const byte array_FF_sdk[] PROGMEM = { 52, 1, 144, 0, 84, 0, 199, 199, 199, 199 };
const byte array_MF_sdk[] PROGMEM = { 255, 17, 189, 22, 126, 0, 199, 199, 199, 199 };
const byte array_F_sdk[] PROGMEM = { 255, 145, 191, 22, 127, 0, 199, 199, 199, 199 };
const byte array_T_sdk[] PROGMEM = { 255, 253, 191, 247, 255, 192, 199, 199, 199, 199 };
//const byte array_Z_ldk[] PROGMEM = { 255, 255, 255, 255, 255, 255, 199, 199, 199, 199 };






const byte array_Reset[] PROGMEM = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

#ifdef _DRAW_KNOB
const byte crescendo_0[] PROGMEM = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const byte crescendo_1[] PROGMEM = { 36, 0, 3, 195, 192, 0, 16, 0, 0, 0 };
const byte crescendo_2[] PROGMEM = { 36, 0, 19, 195, 193, 0, 16, 0, 0, 0 };
const byte crescendo_3[] PROGMEM = { 44, 1, 19, 195, 209, 0, 80, 0, 0, 0 };
const byte crescendo_4[] PROGMEM = { 44, 3, 19, 195, 219, 0, 80, 0, 0, 0 };
const byte crescendo_5[] PROGMEM = { 44, 3, 51, 195, 219, 0, 84, 0, 0, 0 };
const byte crescendo_6[] PROGMEM = { 44, 35, 51, 195, 219, 8, 116, 0, 0, 0 };
const byte crescendo_7[] PROGMEM = { 62, 43, 51, 195, 219, 8, 117, 0, 0, 0 };
const byte crescendo_8[] PROGMEM = { 63, 63, 51, 195, 219, 8, 117, 0, 0, 0 };
const byte crescendo_9[] PROGMEM = { 127, 191, 51, 203, 223, 90, 245, 0, 0, 0 };
const byte crescendo_10[] PROGMEM = { 255, 255, 51, 239, 223, 90, 255, 0, 0, 0 };
const byte crescendo_11[] PROGMEM = { 255, 255, 59, 255, 223, 90, 255, 0, 0, 0 };
const byte crescendo_12[] PROGMEM = { 255, 255, 63, 255, 223, 218, 255, 0, 0, 0 };

#endif _DRAW_KNOB

#ifdef _AMERIKA_DEMO
const byte crescendo_0[] PROGMEM = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const byte crescendo_1[] PROGMEM = { 10, 0, 32, 60, 0, 128, 0, 8, 0, 0, };
const byte crescendo_2[] PROGMEM = { 10, 0, 36, 60, 0, 160, 2, 8, 0, 0, };
const byte crescendo_3[] PROGMEM = { 14, 0, 36, 60, 0, 160, 2, 8, 0, 0,  };
const byte crescendo_4[] PROGMEM = { 14, 0, 38, 60, 0, 160, 6, 12, 0, 0, };
const byte crescendo_5[] PROGMEM = { 14, 0, 182, 60, 0, 224, 134, 76, 0, 0, };
const byte crescendo_6[] PROGMEM = { 31, 2, 182, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_7[] PROGMEM = { 63, 3, 183, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_8[] PROGMEM = { 127, 7, 183, 60, 32, 249, 135, 94, 0, 0,  };
const byte crescendo_9[] PROGMEM = { 255, 7, 247, 60, 52, 249, 135, 254, 0, 0, };
const byte crescendo_10[] PROGMEM = { 255, 7, 247, 62, 60, 249, 135, 254, 0, 0, };
const byte crescendo_11[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };
const byte crescendo_12[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };

#endif
#ifdef _ANGELINA
const byte crescendo_0[] PROGMEM = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const byte crescendo_1[] PROGMEM = { 10, 0, 32, 60, 0, 128, 0, 8, 0, 0, };
const byte crescendo_2[] PROGMEM = { 10, 0, 36, 60, 0, 160, 2, 8, 0, 0, };
const byte crescendo_3[] PROGMEM = { 14, 0, 36, 60, 0, 160, 2, 8, 0, 0,  };
const byte crescendo_4[] PROGMEM = { 14, 0, 38, 60, 0, 160, 6, 12, 0, 0, };
const byte crescendo_5[] PROGMEM = { 14, 0, 182, 60, 0, 224, 134, 76, 0, 0, };
const byte crescendo_6[] PROGMEM = { 31, 2, 182, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_7[] PROGMEM = { 63, 3, 183, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_8[] PROGMEM = { 127, 7, 183, 60, 32, 249, 135, 94, 0, 0,  };
const byte crescendo_9[] PROGMEM = { 255, 7, 247, 60, 52, 249, 135, 254, 0, 0, };
const byte crescendo_10[] PROGMEM = { 255, 7, 247, 62, 60, 249, 135, 254, 0, 0, };
const byte crescendo_11[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };
const byte crescendo_12[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };

#endif
#ifdef FESTOSO_232T
const byte crescendo_0[] PROGMEM = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const byte crescendo_1[] PROGMEM = { 10, 0, 32, 60, 0, 128, 0, 8, 0, 0, };
const byte crescendo_2[] PROGMEM = { 10, 0, 36, 60, 0, 160, 2, 8, 0, 0, };
const byte crescendo_3[] PROGMEM = { 14, 0, 36, 60, 0, 160, 2, 8, 0, 0,  };
const byte crescendo_4[] PROGMEM = { 14, 0, 38, 60, 0, 160, 6, 12, 0, 0, };
const byte crescendo_5[] PROGMEM = { 14, 0, 182, 60, 0, 224, 134, 76, 0, 0, };
const byte crescendo_6[] PROGMEM = { 31, 2, 182, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_7[] PROGMEM = { 63, 3, 183, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_8[] PROGMEM = { 127, 7, 183, 60, 32, 249, 135, 94, 0, 0,  };
const byte crescendo_9[] PROGMEM = { 255, 7, 247, 60, 52, 249, 135, 254, 0, 0, };
const byte crescendo_10[] PROGMEM = { 255, 7, 247, 62, 60, 249, 135, 254, 0, 0, };
const byte crescendo_11[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };
const byte crescendo_12[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };

#endif
#ifdef GRANDIOSO_232T
const byte crescendo_0[] PROGMEM = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const byte crescendo_1[] PROGMEM = { 10, 0, 32, 60, 0, 128, 0, 8, 0, 0, };
const byte crescendo_2[] PROGMEM = { 10, 0, 36, 60, 0, 160, 2, 8, 0, 0, };
const byte crescendo_3[] PROGMEM = { 14, 0, 36, 60, 0, 160, 2, 8, 0, 0,  };
const byte crescendo_4[] PROGMEM = { 14, 0, 38, 60, 0, 160, 6, 12, 0, 0, };
const byte crescendo_5[] PROGMEM = { 14, 0, 182, 60, 0, 224, 134, 76, 0, 0, };
const byte crescendo_6[] PROGMEM = { 31, 2, 182, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_7[] PROGMEM = { 63, 3, 183, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_8[] PROGMEM = { 127, 7, 183, 60, 32, 249, 135, 94, 0, 0,  };
const byte crescendo_9[] PROGMEM = { 255, 7, 247, 60, 52, 249, 135, 254, 0, 0, };
const byte crescendo_10[] PROGMEM = { 255, 7, 247, 62, 60, 249, 135, 254, 0, 0, };
const byte crescendo_11[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };
const byte crescendo_12[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };

#endif
#ifdef _RODGERS
const byte crescendo_0[] PROGMEM = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const byte crescendo_1[] PROGMEM = { 10, 0, 32, 60, 0, 128, 0, 8, 0, 0, };
const byte crescendo_2[] PROGMEM = { 10, 0, 36, 60, 0, 160, 2, 8, 0, 0, };
const byte crescendo_3[] PROGMEM = { 14, 0, 36, 60, 0, 160, 2, 8, 0, 0, };
const byte crescendo_4[] PROGMEM = { 14, 0, 38, 60, 0, 160, 6, 12, 0, 0, };
const byte crescendo_5[] PROGMEM = { 14, 0, 182, 60, 0, 224, 134, 76, 0, 0, };
const byte crescendo_6[] PROGMEM = { 31, 2, 182, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_7[] PROGMEM = { 63, 3, 183, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_8[] PROGMEM = { 127, 7, 183, 60, 32, 249, 135, 94, 0, 0, };
const byte crescendo_9[] PROGMEM = { 255, 7, 247, 60, 52, 249, 135, 254, 0, 0, };
const byte crescendo_10[] PROGMEM = { 255, 7, 247, 62, 60, 249, 135, 254, 0, 0, };
const byte crescendo_11[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };
const byte crescendo_12[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };

#endif
#ifdef DEMO_BOARD
const byte crescendo_0[] PROGMEM = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const byte crescendo_1[] PROGMEM = { 10, 0, 32, 60, 0, 128, 0, 8, 0, 0, };
const byte crescendo_2[] PROGMEM = { 10, 0, 36, 60, 0, 160, 2, 8, 0, 0, };
const byte crescendo_3[] PROGMEM = { 14, 0, 36, 60, 0, 160, 2, 8, 0, 0, };
const byte crescendo_4[] PROGMEM = { 14, 0, 38, 60, 0, 160, 6, 12, 0, 0, };
const byte crescendo_5[] PROGMEM = { 14, 0, 182, 60, 0, 224, 134, 76, 0, 0, };
const byte crescendo_6[] PROGMEM = { 31, 2, 182, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_7[] PROGMEM = { 63, 3, 183, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_8[] PROGMEM = { 127, 7, 183, 60, 32, 249, 135, 94, 0, 0, };
const byte crescendo_9[] PROGMEM = { 255, 7, 247, 60, 52, 249, 135, 254, 0, 0, };
const byte crescendo_10[] PROGMEM = { 255, 7, 247, 62, 60, 249, 135, 254, 0, 0, };
const byte crescendo_11[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };
const byte crescendo_12[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };

#endif

#ifdef _FTA_BOARD
const byte crescendo_0[] PROGMEM = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const byte crescendo_1[] PROGMEM = { 10, 0, 32, 60, 0, 128, 0, 8, 0, 0, };
const byte crescendo_2[] PROGMEM = { 10, 0, 36, 60, 0, 160, 2, 8, 0, 0, };
const byte crescendo_3[] PROGMEM = { 14, 0, 36, 60, 0, 160, 2, 8, 0, 0, };
const byte crescendo_4[] PROGMEM = { 14, 0, 38, 60, 0, 160, 6, 12, 0, 0, };
const byte crescendo_5[] PROGMEM = { 14, 0, 182, 60, 0, 224, 134, 76, 0, 0, };
const byte crescendo_6[] PROGMEM = { 31, 2, 182, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_7[] PROGMEM = { 63, 3, 183, 60, 0, 224, 134, 92, 0, 0, };
const byte crescendo_8[] PROGMEM = { 127, 7, 183, 60, 32, 249, 135, 94, 0, 0, };
const byte crescendo_9[] PROGMEM = { 255, 7, 247, 60, 52, 249, 135, 254, 0, 0, };
const byte crescendo_10[] PROGMEM = { 255, 7, 247, 62, 60, 249, 135, 254, 0, 0, };
const byte crescendo_11[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };
const byte crescendo_12[] PROGMEM = { 255, 7, 247, 63, 60, 249, 135, 254, 0, 0, };

#endif

//historiène uglasitve
const int STYLE_neutral[] PROGMEM = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
const int STYLE_natuerlich_harmo[] PROGMEM = { 0, 0, 4, 0, -14, -2, 0, 2, 0, -16, 0 - 12 };
//const int STYLE_neutral[] PROGMEM = { 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60, 60 };

//const int STYLE_natuerlich_harmo[] PROGMEM = { -60, -60, -60, -60, -60, -60, -60, -60, -60, -60, -60 };
const int STYLE_mitteltoenig[] PROGMEM = { 0, -19, -6, 7, -12, 3, -17, -3, -20, -9, 5, -15 };
const int STYLE_mittel_muriorg[] PROGMEM = { 0, -20, -5, 6, -12, 2, -18, -1, -21, -9, 1, -15 };
const int STYLE_ho_cheng_thien[] PROGMEM = { 0, 1, 0, -3, -2, -7, -4, -1, 3, -3, -15, -9 };
const int STYLE_joung[] PROGMEM = { 0, -10, -4, -6, -8, -2, -12, -2, -8, -6, -4, -10 };
const int STYLE_praetorious[] PROGMEM = { 0, -24, -7, 10, -14, 3, -21, -3, -27, -10, 5, -17 };
const int STYLE_pytagoras[] PROGMEM = { 0, 0, 4, 0, 8, -2, 0, 2, 0, 6, 0, 10 };
const int STYLE_gramathaeus_orgel[] PROGMEM = { 0, 2, 4, 6, 8, -2, 0, 2, 4, 6, 8, 10 };
const int STYLE_ganassi[] PROGMEM = { 0, -12, -18, -19, -14, -2, -3, 2, -10, -16, -17, -12 };
const int STYLE_schlick[] PROGMEM = { 0, -14, -5, 2, -10, 2, -13, -2, -2, -8, 2, -12 };
const int STYLE_werckmeister_3[] PROGMEM = { 0, -10, -8, -6, -10, -2, -12, -4, -8, -12, -4, -8 };
const int STYLE_silberman_1[] PROGMEM = { 0, -13, 0, 8, -10, 3, -10, 0, -16, -5, 6, -10 };
const int STYLE_silberman_2[] PROGMEM = { 0, -14, -4, 6, -8, 12, -12, -2, -16, -6, 4, -10 };
const int STYLE_bach_billeter[] PROGMEM = { 0, -8, 0, -4, -10, 0, -10, 0, -6, -5, -2, -10 };
const int STYLE_back_woltemp[] PROGMEM = { 0, -10, -4, -6, -13, -2, -12, 0, -8, -8, -4, -14 };
const int STYLE_billeter_orgel[] PROGMEM = { 0, -7, -2, -3, -8, 1, -9, -1, -5, -5, -1, -8 };
const int STYLE_kimberger_1[] PROGMEM = { 0, -10, 4, -6, -14, -2, -10, 2, -8, -5, -4, -13 };
const int STYLE_kimberger_2[] PROGMEM = { 0, -10, 4, -6, -14, -2, -10, 2, -8, -5, -4, -12 };
const int STYLE_kimberger_3[] PROGMEM = { 0, -10, -7, -6, -14, -2, -10, -3, -8, -10, -4, -12 };
const int STYLE_kelletal_1966[] PROGMEM = { 0, -10, -4, -6, -13, -2, -12, 0, -8, -8, -4, -14 };
const int STYLE_kelletal_1977[] PROGMEM = { 0, -19, -5, -6, -11, -2, -12, -3, -8, -8, -4, -9 };
const int STYLE_werckmeister_2[] PROGMEM = { 12, 12, 4, 6, 2, 10, 0, 8, 4, 0, 8, 4 };



const int zeroX = 81; //koordinata x = 0
//koordinate gumbov
const byte buttn_gape = 40;
//byte buttn_max = 8;

const int b1_[2] = { 5, 3 };
const int b2_[2] = { 5, b1_[1] + buttn_gape };
const int b3_[2] = { 5, b2_[1] + buttn_gape };
const int b4_[2] = { 5, b3_[1] + buttn_gape };
const int b5_[2] = { 5, b4_[1] + buttn_gape };
const int b6_[2] = { 5, b5_[1] + buttn_gape };
const int b7_[2] = { 160, b1_[1] };
const int b8_[2] = { 160, b1_[1] + buttn_gape };
const int b9_[2] = { 160, b2_[1] + buttn_gape };
const int b10_[2] = { 160, b3_[1] + buttn_gape };
const int b11_[2] = { 160, b4_[1] + buttn_gape };
const int b12_[2] = { 160, b5_[1] + buttn_gape };
//koordinate poravnave sliderjev
const int s1_height = 20;
const int s1_originX = 3;

const int s1_[2] = { 5, 3 };
const int s2_[2] = { 5, 28 };
const int s3_[2] = { 5, 53 };
const int s4_[2] = { 5, 78 };
const int s5_[2] = { 5, 103 };
const int s6_[2] = { 5, 128 };
const int s7_[2] = { 5, 153 };
const int s8_[2] = { 5, 178 };
const int s9_[2] = { 5, 203 };
const int s10_[2] = { 5, 228 };
const int s11_[2] = { 5, 128 };
const int s12_[2] = { 5, 148 };

//koordinate malih labelov
const int s1_gape = 20;

const int xs1_[2] = { 5, 3 };
const int xs2_[2] = { 5, 28 };
const int xs3_[2] = { 5, 48 };
const int xs4_[2] = { 5, 68 };
const int xs5_[2] = { 5, 88 };
const int xs6_[2] = { 5, 108 };
const int xs7_[2] = { 5, 128 };
const int xs8_[2] = { 5, 148 };
const int xs9_[2] = { 5, 88 };
const int xs10_[2] = { 5, 108 };
const int xs11_[2] = { 5, 128 };
const int xs12_[2] = { 5, 148 };

//izraèunano polje ID link na 2D polje
const byte calc_bit_array[100][2] PROGMEM = {
	{0,0},
	{0,1},
	{0,2},
	{0,3},
	{0,4},
	{0,5},
	{0,6},
	{0,7},
	{1,0},
	{1,1},
	{1,2},
	{1,3},
	{1,4},
	{1,5},
	{1,6},
	{1,7},
	{2,0},
	{2,1},
	{2,2},
	{2,3},
	{2,4},
	{2,5},
	{2,6},
	{2,7},
	{3,0},
	{3,1},
	{3,2},
	{3,3},
	{3,4},
	{3,5},
	{3,6},
	{3,7},
	{4,0},
	{4,1},
	{4,2},
	{4,3},
	{4,4},
	{4,5},
	{4,6},
	{4,7},
	{5,0},
	{5,1},
	{5,2},
	{5,3},
	{5,4},
	{5,5},
	{5,6},
	{5,7},
	{6,0},
	{6,1},
	{6,2},
	{6,3},
	{6,4},
	{6,5},
	{6,6},
	{6,7},
	{7,0},
	{7,1},
	{7,2},
	{7,3},
	{7,4},
	{7,5},
	{7,6},
	{7,7},
	{8,0},
	{8,1},
	{8,2},
	{8,3},
	{8,4},
	{8,5},
	{8,6},
	{8,7},
	{9,0},
	{9,1},
	{9,2},
	{9,3},
	{9,4},
	{9,5},
	{9,6},
	{9,7},
	{10,0},
	{10,1},
	{10,2},
	{10,3},
	{10,4},
	{10,5},
	{10,6},
	{10,7},
	{11,0},
	{11,1},
	{11,2},
	{11,3},
	{11,4},
	{11,5},
	{11,6},
	{11,7},
	{12,0},
	{12,1},
	{12,2},
	{12,3}
};


//
//extern byte krumhorn PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte gemshorn PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 93, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte terz PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte scharf PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte piccolo PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 102, 127, 127, 127, 127, 127, 127 };
//extern byte bordun 8 PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 102, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 116, 102, 127, 127, 127, 127, 127, 127, 99, 84, 60, 79, 77, 96, 109, 89, 88, 89, 78, 87, 93, 99, 96, 87, 76, 97, 89, 69, 83, 85, 91, 92, 77, 93, 86, 93, 77, 103, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 82, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte prestant PROGMEM[90] = { 127, 127, 82, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte rohrflote PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 90, 77, 127, 95, 127, 105, 127, 91, 101, 96, 108, 94, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte quinte PROGMEM[90] = { 101, 96, 108, 94, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 67, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte schalmei PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 125, 126, 125, 125, 125, 126, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte trompete_harmoniq PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 120, 121, 122, 125, 125, 125, 124, 124, 127, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte oboa PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte faggot PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 104, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 97, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 86, 110, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte larigot_11 PROGMEM[90] = { 127, 86, 110, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 93, 91, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte mixtur_4f PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte flageolet PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 115, 127, 127, 127, 104, 127, 127, 127, 127, 127, 98, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 119, 119, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte portunal_flote PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 110, 107, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte gambe_8 PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 110, 107, 127, 127, 127 };
//extern byte vox_coletis PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte travers_flote PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte geinzhal_prinzipal PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte nasat PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 113, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte trompete_8 PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte posaune PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte mixtur_2f PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 125 };
//extern byte coral_bass PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte bassflote PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte oktavbass PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte subbas PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte prinzipal_bass PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte trompete PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 124, 83, 127, 127, 127, 127, 127, 127, 127, 98, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte mixtur_5f PROGMEM[90] = { 127, 74, 60, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 109, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte prinzipal_2 PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 99, 88, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 103, 127, 127, 127, 127, 127, 127, 104, 127, 106, 127, 127, 127, 127, 127, 127, 127, 127, 104, 103, 100, 127, 127, 111, 113, 127, 86, 117, 100, 106, 105, 127, 127, 127, 127, 101, 117, 112, 127, 127, 74, 60, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte quinte PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 104, 127, 127, 127, 127, 127, 127, 127, 85, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 99, 88 };
//extern byte clarion_4 PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 125, 127, 127, 127, 127, 127, 127, 127, 127, 97, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 100, 70, 98, 97, 103, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte spitzflote PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte oktave PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 122, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte salicional PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte flute_harmoniq PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 90, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 93, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte prinzipal_8 PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 100, 127, 121, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//extern byte bordun_8 PROGMEM[90] = { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 79, 127, 127, 127, 127, 127, 102, 127, 127, 127, 127, 89, 90, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 93, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
//
//


#endif

