//#define MODEL_FESTOSO_232T //èrni
#define MODEL_GRANDIOSO_232T //svetli
//#define MODEL_GRANDIOSO_232T_NOT_RGB //svetli

//#define EXCLUDE_SPIRAM
//#define RGB_LED_OUTPUT
#define SAVE_USP_SUB
#define SAVE_RAM_STOPS
#define ONE_WIRE_MIDI
//#define DEBUG_ARRAY_info //za shranjevanje fix kombinacij v PROGMEM
//#define SERIAL_MONITOR_DEBUG //odkomentirano-> Serial monitor
//#define TEMP_DEBUG 
#define INCLUDE_FINAL
//#define SET_KEYS
#define  vkljuci_menije

#define NEW_DISPOSITION //nova, pedal na modulu 1
//#define TESTED_DISPOSITION //tta zihr dela, pedal na svojem modulu

#define DREAM_OUTPUT 
//#define MIDI_OX_OUTPUT
//___________________________________________________________________
//IZBIRA MODELA______________________________________________________

//vrsta igralnika-> zaradi definicije manualov in
//#define _RODGERS //odkomentirano-> rodgers
//#define _ANGELINA //odkomentirano-> rodgers


//#define FESTOSO_232T_FORTE //angelina zagreb

//#define _DRAW_KNOB 
//#define _AMERIKA_DEMO

//#define ARDUINO_BOARD
#define DEMO_BOARD //pusti to
//#define _FTA_BOARD

//#define MODEL_X //to je model na katerem si intoniral
  //poglej na ohišje, je oznaèeno, ta model se bo uporabljal
//#define MODEL_B
//#define MODEL_C

//___________________________________________________________________

#define key_arr_size 12 //pusti
#define key_arr_old_size 12

//OSTALE DEFINICIJE______________________________________________________
//#define NEW_OKTAVE
//#define OLD_OKTAVE //pusti zaenkrat
#define EEPROM_CANCEL_first_boot //da se hitreje zažene

//#define SWAP_MAN3_to_MAN2

//#define MANUAL_num_3
#define INCLUDE_KEY_INFO1
#define NEW_STOPS
//#define NEW_MIDI_SEND
//TODO:pazi na stop_num spremenljivko pri read_keybord

//#define ZECER_1x_ //TOLE MORE BITI DEFINIRANO Z STARO ALI NOVO DISPOZICIJO!!
//#define ZECER_1x_stara_plata_dispozicija
//#define ZECER_1x_nova_plata_dispozicija




//ostale nastavitve
#ifdef _GRAND_ORGUE_output
#define TOTTER_SINGLE_STOP_MIX
#endif

#ifdef DREAM_OUTPUT
#define TOTTER_SINGLE_STOP_MIX
#endif



#ifdef TOTTER_DUAL_output
#define TOTTER_DUAL_STOP_MIX
#else
#ifdef TOTTER_SINGLE_output
#define TOTTER_SINGLE_STOP_MIX
#endif
#endif // TOTTER_DUAL_output




#ifdef EEPROM_CANCEL_first_boot
#define BOOT_TIME_DELAY 100 //drugaèe ene 5000 ms
#else
#define BOOT_TIME_DELAY 5000 //drugaèe ene 5000 ms
#endif 

#ifdef INCLUDE_FINAL
#define BOOT_TIME_DELAY 500 //drugaèe ene 5000 ms
#endif 

#define POLYPHONY 320//na modul

#define POLY1 70
#define POLY2 70
#define POLY3 70
#define POLYP 70

#define STOP_LIMIT 3