// Definitions_pins.h

#ifndef _DEFINITIONS_PINS_h
#define _DEFINITIONS_PINS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


#endif

#define STOP1_OUT_ENABLE 79
#define STOP2_OUT_ENABLE 79
#define ZECER_OUT_ENABLE 78

#define STATUS_LED 81
#define PWR_LED 82

#define DATA_164_keyboard  7
#define CLK_164_keyboard  3
#define DATA_165_keyboard  8
#define LOAD_165_keyboard  9
//#define load595Pin  9
#define CLK_pin  2

#define CLK_STOPS1  84
#define LOAD_165_STOPS1 A8
#define MISO_165_STOPS1  A9
#define SS_595_STOPS1  A10
#define MOSI_595_STOPS1  12


#define LOAD_165_pedal 43
#define DATA_165_pedal 42
#define CLOCK_pedal  44

//#define LOAD_165_pedal A8
//#define DATA_165_pedal A9
//#define CLOCK_pedal  84

//#define LOAD_165_R  49
//#define DATA_165_R  48
//#define LOAD_595_R  47
//#define DATA_595_R  46

#define INPUT_FOOT_PISTON_UP  47
#define INPUT_FOOT_PISTON_DOWN  49

//#define CLK_stop_pin_r  85

#define CLK_ZECER A12
#define LOAD_165_Z  10
#define DATA_165_Z  11
#define LOAD_595_Z  A11
#define DATA_595_Z  13
//#define CLK_ZECER 46
//#define LOAD_165_Z  43
//#define DATA_165_Z  42
//#define LOAD_595_Z  A11
//#define DATA_595_Z  13


#define ENCODER_PIN_ENTER  A2
#define ENCODER_PIN_BACK  A3
#define  MASTER_VOLUME_PIN  A1
#define ENCODER_PIN_1  20
#define ENCODER_PIN_2  21

//
//// Definitions_pins.h
//
//#ifndef _DEFINITIONS_PINS_h
//#define _DEFINITIONS_PINS_h
//
//#if defined(ARDUINO) && ARDUINO >= 100
//#include "arduino.h"
//#else
//#include "WProgram.h"
//#endif
//
//
//#endif
//
//#define STOP1_OUT_ENABLE 79
//#define STOP2_OUT_ENABLE 79
//#define ZECER_OUT_ENABLE 78
//
//#define STATUS_LED 81
//#define PWR_LED 82
//
//#define DATA_164_keyboard  7
//#define CLK_164_keyboard  3
//#define DATA_165_keyboard  8
//#define LOAD_165_keyboard  9
////#define load595Pin  9
//#define CLK_pin  2
//#define CLK_stop_pin  49
//
//#define LOAD_165_R_r A8
//#define DATA_165_R_r  A9
//#define LOAD_595_R_r  A10
//#define DATA_595_R_r  12
//
//#define LOAD_165_pedal 43
//#define DATA_165_pedal 42
//#define CLOCK_pedal  46
//
//#define LOAD_165_R  A8
//#define DATA_165_R  A9
//#define LOAD_595_R  A10
//#define DATA_595_R  12
//
//#define CLK_stop_pin_r  45
//
//#define CLK_ZECER 47
//#define LOAD_165_Z  10
//#define DATA_165_Z  11
//#define LOAD_595_Z  A11
//#define DATA_595_Z  13
////#define CLK_ZECER 46
////#define LOAD_165_Z  43
////#define DATA_165_Z  42
////#define LOAD_595_Z  A11
////#define DATA_595_Z  13
//
//
//#define ENCODER_PIN_ENTER  A2
//#define ENCODER_PIN_BACK  A3
//#define  MASTER_VOLUME_PIN  A1
//#define  GAS1_PIN  A6
//#define  GAS2_PIN  A7
//#define ENCODER_PIN_1  20
//#define ENCODER_PIN_2  21
//
//
