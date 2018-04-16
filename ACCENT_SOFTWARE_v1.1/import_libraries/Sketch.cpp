
//FUSEBITS MEGA2560 E:FD, H:D9, L:FF
//FUSEBITS za PWR ON OFF tiny44 E:FD H:DF L:62
//ff dd 62 prava
///////////////////////////
///////////////////////////
///////////////////////////
//Gregor Hrastnik, 15.3.2016
///////////////////////////

#define program_navadni
#ifdef program_navadni

#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <MIDI.h>
#include "Zecer_stop_mgr.h"
#include "global_variables.h"
#include "global_methods.h"
#include <Timer.h>
#include <MemoryFree.h>

#include "SD_mgr.h"
//#include <UTFT.h>
//#include "LCD_mgr.h"
#include "Definitions_settings.h"
#include "menu_mgr.h"
#include "PROGMEM_labels.h"
#include "SPIEEP.h"

//

//SPIEEP eep(16, 128, 65536);
//#define EEPROM_CSPIN A7
#include <SPI.h>
#include "SpiRam_Extended.h"

//Timer t;//preveč rama požere

Zecer_stop_mgr Z_S_mgr;
menu_mgr MENU_mgr;



const GPIO_pin_t DATA_164_keyboard_FAST = DP7;
const GPIO_pin_t CLK_164_keyboard_FAST = DP3;
const GPIO_pin_t DATA_165_keyboard_FAST = DP8;
const GPIO_pin_t LOAD_165_keyboard_FAST = DP9;
const GPIO_pin_t CLK_pin_FAST = DP2;

#define HEAD_MUTE 75


int numb=0;
float previous_millis;

byte test_blink=false;

void doSomething()
{


	//return;
	//	Z_S_mgr.keyboardCheck();
	if(test_blink)
	{
		test_blink=false;
		digitalWrite(STATUS_LED,LOW);
		digitalWrite(PWR_LED,HIGH);
	}
	else
	{

		test_blink=true;
		digitalWrite(STATUS_LED,HIGH);
		digitalWrite(PWR_LED,LOW);
	}
	return;
	
	DEBUG_print(F("refresh "));
	DEBUG_print(numb);
	DEBUG_println(F(" Hz "));
	DEBUG_println(millis()-previous_millis);
	numb=0;
	previous_millis=millis();
	
	calculate_free_RAM(0);
	
	

}

int calc_loc(int stop_id,int code)
{
	byte add_val=0;
	if(code==CODE_PAN)
	add_val=1;
	if(code==CODE_STOP_VOL)
	add_val=2;
	
	int mem_add=STOPS_START_ADDRESSES+((stop_id)*5)+add_val;
	return mem_add;
}
void set_default_intonation()
{
	

	EEPROM.write(calc_loc( BORDUN_16,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( PRINZIPAL_8 ,CODE_STOP_VOL),  100);
	EEPROM.write(calc_loc( FLUTE_HARMONIQ ,CODE_STOP_VOL), 88 );
	EEPROM.write(calc_loc( SALICIONAL ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( OKTAVE_4 ,CODE_STOP_VOL), 86 );
	EEPROM.write(calc_loc( SPITZFLOTE ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( QUINTE ,CODE_STOP_VOL),110  );
	EEPROM.write(calc_loc( PRINZIPAL_2 ,CODE_STOP_VOL),110  );
	EEPROM.write(calc_loc( MIXTUR_5F ,CODE_STOP_VOL),88  );
	EEPROM.write(calc_loc( TROMPETE_8 ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( CLARION_4 ,CODE_STOP_VOL), 95 );
	EEPROM.write(calc_loc( BORDUN_8 ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( PRESTANT_4 ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( ROHRFLOTE_4 ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( QUINTE_m3 ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( GEMSHORN_2 ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( TERZE_m3 ,CODE_STOP_VOL), 51 );
	EEPROM.write(calc_loc( PICCOLO ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( SCHARF_3F ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( KRUMHORN ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( PORTUNAL_FLOTE  ,CODE_STOP_VOL), 53 );
	EEPROM.write(calc_loc( GAMBE ,CODE_STOP_VOL), 122 );
	EEPROM.write(calc_loc( VOX_COELESTIS ,CODE_STOP_VOL), 122 );
	EEPROM.write(calc_loc( GEIGEN_PRINZIPAL ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( TRAVERS_FLUTE ,CODE_STOP_VOL), 127 );
	EEPROM.write(calc_loc( NASAT ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( FLAGEOLET ,CODE_STOP_VOL), 89 );
	EEPROM.write(calc_loc( MIXTUR_4F ,CODE_STOP_VOL), 77 );
	EEPROM.write(calc_loc( LARIGOT ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc( FAGOTT ,CODE_STOP_VOL), 72 );
	EEPROM.write(calc_loc( OBOE ,CODE_STOP_VOL), 88 );
	EEPROM.write(calc_loc( TROMPETE_HARMONIQ ,CODE_STOP_VOL), 100 );
	EEPROM.write(calc_loc( SCHALMEI ,CODE_STOP_VOL), 82 );
	EEPROM.write(calc_loc( PRINZIPAL_BASS_16 ,CODE_STOP_VOL), 73 );
	EEPROM.write(calc_loc( SUBBASS_8 ,CODE_STOP_VOL), 78 );
	EEPROM.write(calc_loc( OKTAVBASS_8 ,CODE_STOP_VOL), 71 );
	EEPROM.write(calc_loc( BASSFLOTE_8 ,CODE_STOP_VOL), 40 );
	EEPROM.write(calc_loc( CHORALBASS_4  ,CODE_STOP_VOL), 95 );
	EEPROM.write(calc_loc( PEDAL_MIXTUR_2F ,CODE_STOP_VOL), 55 );
	EEPROM.write(calc_loc( POSAUNE_16 ,CODE_STOP_VOL), 51 );
	EEPROM.write(calc_loc( TROMPETE_8_ped ,CODE_STOP_VOL), 80 );
	
	EEPROM.write(calc_loc(head_BORDUN_16,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_PRINZIPAL_8 ,CODE_STOP_VOL),  100);
	EEPROM.write(calc_loc(head_FLUTE_HARMONIQ ,CODE_STOP_VOL), 88 );
	EEPROM.write(calc_loc(head_SALICIONAL ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_OKTAVE_4 ,CODE_STOP_VOL), 86 );
	EEPROM.write(calc_loc(head_SPITZFLOTE ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_QUINTE ,CODE_STOP_VOL),110  );
	EEPROM.write(calc_loc(head_PRINZIPAL_2 ,CODE_STOP_VOL),110  );
	EEPROM.write(calc_loc(head_MIXTUR_5F ,CODE_STOP_VOL),88  );
	EEPROM.write(calc_loc(head_TROMPETE_8 ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_CLARION_4 ,CODE_STOP_VOL), 95 );
	EEPROM.write(calc_loc(head_BORDUN_8 ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_PRESTANT_4 ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_ROHRFLOTE_4 ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_QUINTE_m3 ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_GEMSHORN_2 ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_TERZE_m3 ,CODE_STOP_VOL), 51 );
	EEPROM.write(calc_loc(head_PICCOLO ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_SCHARF_3F ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_KRUMHORN ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_PORTUNAL_FLOTE  ,CODE_STOP_VOL), 53 );
	EEPROM.write(calc_loc(head_GAMBE ,CODE_STOP_VOL), 122 );
	EEPROM.write(calc_loc(head_VOX_COELESTIS ,CODE_STOP_VOL), 122 );
	EEPROM.write(calc_loc(head_GEIGEN_PRINZIPAL ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_TRAVERS_FLUTE ,CODE_STOP_VOL), 127 );
	EEPROM.write(calc_loc(head_NASAT ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_FLAGEOLET ,CODE_STOP_VOL), 89 );
	EEPROM.write(calc_loc(head_MIXTUR_4F ,CODE_STOP_VOL), 77 );
	EEPROM.write(calc_loc(head_LARIGOT ,CODE_STOP_VOL), 110 );
	EEPROM.write(calc_loc(head_FAGOTT ,CODE_STOP_VOL), 72 );
	EEPROM.write(calc_loc(head_OBOE ,CODE_STOP_VOL), 88 );
	EEPROM.write(calc_loc(head_TROMPETE_HARMONIQ ,CODE_STOP_VOL), 100 );
	EEPROM.write(calc_loc(head_SCHALMEI ,CODE_STOP_VOL), 82 );
	EEPROM.write(calc_loc(head_PRINZIPAL_BASS_16 ,CODE_STOP_VOL), 73 );
	EEPROM.write(calc_loc(head_SUBBASS_8 ,CODE_STOP_VOL), 78 );
	EEPROM.write(calc_loc(head_OKTAVBASS_8 ,CODE_STOP_VOL), 71 );
	EEPROM.write(calc_loc(head_BASSFLOTE_8 ,CODE_STOP_VOL), 40 );
	EEPROM.write(calc_loc(head_CHORALBASS_4  ,CODE_STOP_VOL), 95 );
	EEPROM.write(calc_loc(head_PEDAL_MIXTUR_2F ,CODE_STOP_VOL), 55 );
	EEPROM.write(calc_loc(head_POSAUNE_16 ,CODE_STOP_VOL), 51 );
	EEPROM.write(calc_loc(head_TROMPETE_8_ped ,CODE_STOP_VOL), 80 );
	
}


void setup() {
	


	pinMode(A7, OUTPUT);
	digitalWrite(A7, HIGH);
	
	pinMode(ENCODER_PIN_1, INPUT);
	pinMode(ENCODER_PIN_2, INPUT);

	
	pinMode(HEAD_MUTE,INPUT);
	pinMode(STOP1_OUT_ENABLE,OUTPUT);
	pinMode(STOP2_OUT_ENABLE,OUTPUT);
	
	
	
	pinMode2(MISO_165_STOPS1, INPUT);
	pinMode2(LOAD_165_STOPS1, OUTPUT);
	pinMode2(MOSI_595_STOPS1, OUTPUT);
	pinMode2(SS_595_STOPS1, OUTPUT);


	pinMode(ZECER_OUT_ENABLE,OUTPUT);
	digitalWrite(ZECER_OUT_ENABLE,LOW);
	digitalWrite(STOP1_OUT_ENABLE,HIGH);
	
	//delay(100000);
	
	
	
	digitalWrite(ZECER_OUT_ENABLE,LOW);
	digitalWrite(STOP1_OUT_ENABLE,LOW);
	digitalWrite(STOP2_OUT_ENABLE,LOW);
	pinMode2(CLK_ZECER, OUTPUT);
	pinMode2(DATA_165_Z, INPUT);
	pinMode2(LOAD_165_Z, OUTPUT);

	pinMode2(DATA_595_Z, OUTPUT);
	pinMode2(LOAD_595_Z, OUTPUT);





	//STOPS
	//pinMode2(DATA_165_R, INPUT);
	//pinMode2(LOAD_165_R, OUTPUT);
	//
	//pinMode2(DATA_595_R, OUTPUT);
	//pinMode2(LOAD_595_R, OUTPUT);


	
	EEPROM.update(ADD_menu_hist_temp,0);
	EEPROM.update(ADD_menu_tune_cents,20);
	
	manubri_na_nulo();//prvo more biti to
	
	
	softSerial.begin(1000000);
	const char compile_date[] = __DATE__ " " __TIME__" ";
	
	softSerial.println(F("==================RESTART==================="));
	softSerial.print(F("compile date: "));
	softSerial.println(compile_date);
	
	
	//Serial.println(F("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"));
	init_global_values();
	
	//preveč rama gre za timer...
	//int tickEvent = t.every(1000, doSomething);
	//int tickEvent1 = timer_input.every(20, on_timer_check);
	

	

	
	pinMode(STATUS_LED,OUTPUT);
	digitalWrite(STATUS_LED,HIGH);
	pinMode(PWR_LED,OUTPUT);
	digitalWrite(PWR_LED,LOW);
	
	pinMode2f(DATA_164_keyboard_FAST, OUTPUT);
	pinMode2f(CLK_164_keyboard_FAST, OUTPUT);
	//165
	pinMode2f(DATA_165_keyboard_FAST, INPUT);
	pinMode2f(LOAD_165_keyboard_FAST, OUTPUT);
	pinMode2f(CLK_pin_FAST, OUTPUT);
	
	pinMode(CLK_STOPS1, OUTPUT);
	//pinMode2(CLK_stop_pin_r, OUTPUT);

	pinMode2(DATA_165_pedal, INPUT_PULLUP);
	pinMode2(LOAD_165_pedal, OUTPUT);
	pinMode2(CLOCK_pedal, OUTPUT);
	
	
	pinMode2(ENCODER_PIN_1, INPUT_PULLUP);
	pinMode2(ENCODER_PIN_2, INPUT_PULLUP);
	pinMode2(ENCODER_PIN_BACK, INPUT_PULLUP);
	pinMode2(ENCODER_PIN_ENTER, INPUT_PULLUP);

	pinMode2(MASTER_VOLUME_PIN, INPUT_PULLUP);
	pinMode2(GAS1_pin, INPUT_PULLUP);
	pinMode2(GAS2_pin, INPUT_PULLUP);
	
	pinMode2(INPUT_FOOT_PISTON_UP,INPUT_PULLUP);
	pinMode2(INPUT_FOOT_PISTON_DOWN,INPUT_PULLUP);



	Z_S_mgr.Zecer_stop_mgr_init();
	ZECER.read_input();
	MENU_mgr.menu_init();
	zecer_na_nulo();
	
	
	int START_ADD= STOPS_START_ADDRESSES;
	int value1;
	int value2;
	int value3;
	int value4;
	byte midi_channel;
	byte midi_out;
	EEPROM.update(ADD_menu_b1_equalizer_select, 1);

	EEPROM.update(add_VALUE_TRANSPOSE, TRANS_adjust);
	//reset nastavitev, če držiš obadva knofa in pri prvem zagonu
	if (digitalRead2(ENCODER_PIN_ENTER) == false && digitalRead2(ENCODER_PIN_BACK) == false || EEPROM.read(29)!=42)//reset na nulo
	{

		EEPROM.write(29, 42);
		DEBUG_println(F("::EEPROM prepare"));
		EEPROM.write(ADD_menu_b8_theme_1, 0);
		setTheme(0);
		EEPROM.write(add_VALUE_TRANSPOSE, TRANS_adjust);
		EEPROMWriteLong(add_vol_min, analogRead(MASTER_VOLUME_PIN));//da lahko nastaviš range  ;)
		EEPROMWriteLong(add_vol_max, analogRead(MASTER_VOLUME_PIN));

		EEPROMWriteLong(add_gas1_min, analogRead(GAS1_pin));
		EEPROMWriteLong(add_gas1_max, analogRead(GAS1_pin));

		EEPROMWriteLong(add_gas2_min, analogRead(GAS2_pin));
		EEPROMWriteLong(add_gas2_max, analogRead(GAS2_pin));

		EEPROM.write(ADD_menu_b1_equalizer_gain_low, 64);
		EEPROM.write(ADD_menu_b1_equalizer_gain_low_mid, 64);
		EEPROM.write(ADD_menu_b1_equalizer_gain_high_mid, 64);
		EEPROM.write(ADD_menu_b1_equalizer_gain_high, 64);
		//
		//EEPROM.write(ADD_menu_b1_equalizer_gain_low, 0x60);
		//EEPROM.write(ADD_menu_b1_equalizer_gain_low_mid, 0x38);
		//EEPROM.write(ADD_menu_b1_equalizer_gain_high_mid, 0x38);
		//EEPROM.write(ADD_menu_b1_equalizer_gain_high, 0x60);


		EEPROM.write(ADD_menu_b1_equalizer_band_freq_low_band_0_800, 0x0A);
		EEPROM.write(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500, 0x18);
		EEPROM.write(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700, 0x68);
		EEPROM.write(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800, 0x7F);

		EEPROM.write(ADD_menu_b1_equalizer_Q_low, 0x40);
		EEPROM.write(ADD_menu_b1_equalizer_Q_low_mid, 0x40);
		EEPROM.write(ADD_menu_b1_equalizer_Q_high_mid, 0x40);
		EEPROM.write(ADD_menu_b1_equalizer_Q_high, 0x40);
		
		//////////////////
		//EEPROM.write(ADD_menu_b1_equalizer_gain_low_II, 0x60);
		//EEPROM.write(ADD_menu_b1_equalizer_gain_low_mid_II, 0x38);
		//EEPROM.write(ADD_menu_b1_equalizer_gain_high_mid_II, 0x38);
		//EEPROM.write(ADD_menu_b1_equalizer_gain_high_II, 0x60);

		EEPROM.write(ADD_menu_b1_equalizer_gain_low_II, 64);
		EEPROM.write(ADD_menu_b1_equalizer_gain_low_mid_II, 64);
		EEPROM.write(ADD_menu_b1_equalizer_gain_high_mid_II, 64);
		EEPROM.write(ADD_menu_b1_equalizer_gain_high_II, 64);

		EEPROM.write(ADD_menu_b1_equalizer_band_freq_low_band_0_800_II, 0x0A);
		EEPROM.write(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_II, 0x18);
		EEPROM.write(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_II, 0x68);
		EEPROM.write(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_II, 0x7F);

		EEPROM.write(ADD_menu_b1_equalizer_Q_low_II, 0x40);
		EEPROM.write(ADD_menu_b1_equalizer_Q_low_mid_II, 0x40);
		EEPROM.write(ADD_menu_b1_equalizer_Q_high_mid_II, 0x40);
		EEPROM.write(ADD_menu_b1_equalizer_Q_high_II, 0x40);
		//////////////////
		EEPROM.write(ADD_menu_b1_equalizer_gain_low_III, HEAD_gain_low);
		EEPROM.write(ADD_menu_b1_equalizer_gain_low_mid_III, HEAD_gain_low_mid);
		EEPROM.write(ADD_menu_b1_equalizer_gain_high_mid_III, HEAD_gain_high_mid);
		EEPROM.write(ADD_menu_b1_equalizer_gain_high_III, HEAD_gain_high);

		EEPROM.write(ADD_menu_b1_equalizer_band_freq_low_band_0_800_III, HEAD_freq_low_band_0_800);
		EEPROM.write(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_III, HEAD_freq_low_mid_band_0_2500);
		EEPROM.write(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III, HEAD_freq_high_mid__band_60_10700);
		EEPROM.write(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_III, HEAD_freq_high_band_1000_5800);

		EEPROM.write(ADD_menu_b1_equalizer_Q_low_III, HEAD_Q_low);
		EEPROM.write(ADD_menu_b1_equalizer_Q_low_mid_III, HEAD_Q_low);
		EEPROM.write(ADD_menu_b1_equalizer_Q_high_mid_III, HEAD_Q_high);
		EEPROM.write(ADD_menu_b1_equalizer_Q_high_III, HEAD_Q_high);
		
		//////////////////
		EEPROM.write(ADD_menu_b1_equalizer_gain_low_IV, HEAD_gain_low_II);
		EEPROM.write(ADD_menu_b1_equalizer_gain_low_mid_IV, HEAD_gain_low_mid_II);
		EEPROM.write(ADD_menu_b1_equalizer_gain_high_mid_IV, HEAD_gain_high_mid_II);
		EEPROM.write(ADD_menu_b1_equalizer_gain_high_IV, HEAD_gain_high_II);

		EEPROM.write(ADD_menu_b1_equalizer_band_freq_low_band_0_800_IV, HEAD_freq_low_band_0_800_II);
		EEPROM.write(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_IV, HEAD_freq_low_mid_band_0_2500_II);
		EEPROM.write(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_IV, HEAD_freq_high_mid__band_60_10700_II);
		EEPROM.write(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_IV, HEAD_freq_high_band_1000_5800_II);

		EEPROM.write(ADD_menu_b1_equalizer_Q_low_IV, HEAD_Q_low_II);
		EEPROM.write(ADD_menu_b1_equalizer_Q_low_mid_IV, HEAD_Q_low_II);
		EEPROM.write(ADD_menu_b1_equalizer_Q_high_mid_IV, HEAD_Q_high_II);
		EEPROM.write(ADD_menu_b1_equalizer_Q_high_IV, HEAD_Q_high_II);
		
		
		
		
		//
		//EEPROM.write(ADD_menu_b1_equalizer_gain_low, 0x40);
		//EEPROM.write(ADD_menu_b1_equalizer_gain_low_mid, 0x40);
		//EEPROM.write(ADD_menu_b1_equalizer_gain_high_mid, 0x40);
		//EEPROM.write(ADD_menu_b1_equalizer_gain_high, 0x40);
		//
		//EEPROM.write(ADD_menu_b1_equalizer_band_freq_low_band_0_800, 0x40);
		//EEPROM.write(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500, 0x40);
		//EEPROM.write(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700, 0x40);
		//EEPROM.write(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800, 0x40);
		//
		//EEPROM.write(ADD_menu_b1_equalizer_Q_low, 0x40);
		//EEPROM.write(ADD_menu_b1_equalizer_Q_low_mid, 0x40);
		//EEPROM.write(ADD_menu_b1_equalizer_Q_high_mid, 0x40);
		//EEPROM.write(ADD_menu_b1_equalizer_Q_high, 0x40);

		EEPROM.write(add_VALUE_tremulnat1, 64);
		EEPROM.write(add_VALUE_tremulnat1_depth, 72);
		EEPROM.write(add_VALUE_tremulnat2, 30);

		EEPROM.write(add_VALUE_predelay_time, 0);
		EEPROM.write(add_VALUE_REVERB, 105);
		//EEPROM.write(add_VALUE_master_level, 126);
		EEPROM.write(add_VALUE_pre_LPF, 5);
		EEPROM.write(add_VALUE_reverb_time_ms, 81);
		EEPROM.write(add_VALUE_reverb_type, 5);
		EEPROM.write(add_VALUE_hist_temp, 1);
		EEPROM.write(add_VALUE_delay_feedback, 0);
		EEPROM.write(add_VALUE_delay_send, 127);
		EEPROM.write(add_VALUE_characterI, 0);
		
		EEPROM.write(add_VALUE_predelay_time_II, 0);
		EEPROM.write(add_VALUE_REVERB_II, 95);
		//EEPROM.write(add_VALUE_master_level, 126);
		EEPROM.write(add_VALUE_pre_LPF_II, 4);
		EEPROM.write(add_VALUE_reverb_time_ms_II, 65);
		EEPROM.write(add_VALUE_reverb_type_II, 5);
		EEPROM.write(add_VALUE_delay_feedback_II, 0);
		EEPROM.write(add_VALUE_delay_send_II, 127);
		EEPROM.write(add_VALUE_characterII, 0);
		
		EEPROM.write(ADD_menu_b1_man_I_lvl, 110);
		EEPROM.write(ADD_menu_b1_man_II_lvl, 110);
		EEPROM.write(ADD_menu_b1_man_PED_lvl, 110);
		
		
		byte gas1_max,gas1_min,gas2_max,gas2_min,gas1_temp_,gas2_temp_;
		bool begin_read=true;
		
		//mem_add+42+value
		for(int x=0;x<84;x++)
		{
			int mem_add=STOPS_START_ADDRESSES+(x*5);//p_menu_item->getMemAddress();
			
			EEPROM.write(mem_add+1,64);
			EEPROM.write(mem_add+2,110);
			EEPROM.write(mem_add+3,0x40);
			EEPROM.write(mem_add+4,0x40);
			//EEPROM.write(START_ADD+42+x,64);
			//EEPROM.write(START_ADD+84+x,127);
			//EEPROM.write(START_ADD+84+42+x,0x40);
			//EEPROM.write(START_ADD+84+84+x,0x40);
			
		}
		set_default_intonation();
		EEPROM.write(ADD_menu_tune_cents, 20);
		
		COMBINATION_LABEL_FIRST_letter=F("");
		//TRANSPOSE_LABEL_TEXT=F("RESTART!");
		COMBINATION_LABEL_FIRST_letter=F("RESTART!");
		
	}
	else
	{
		COMBINATION_LABEL_FIRST_letter=F("");
		COMBINATION_LABEL_FIRST_letter_old=F("LOADING...");
		
	}
	
	
	
	
	//MIDI_sender.setup_stop_disposition(0,1);
	for(int x=0;x<STOP_num;x++)
	{
		//for(int a=0;a<10;a++)
		{
			
			MIDI_sender.send_stop_notes_volume(x,0x20);
			delay(30);
		}
	}
	
	
	calculate_free_RAM(4);
	//tmp fix: check and send reverb
	byte tmp_var = EEPROM.read(add_VALUE_reverb_type);
	if (tmp_var > 7)
	tmp_var = 3;
	//delay(2000);
	
	MENU_mgr.send_startup_reverb(MIDI_1,tmp_var);//send reverb
	tmp_var = EEPROM.read(add_VALUE_reverb_type_II);
	if (tmp_var > 7)
	tmp_var = 3;
	//delay(2000);
	//MENU_mgr.check_reverb(H_reverb_type_,tmp_var);//send reverb
	MENU_mgr.send_startup_reverb(MIDI_2,tmp_var);//send reverb
	
	MIDI_sender.equalizer_startup_send();
	MIDI_sender.tuning_send();

	

	MIDI_sender.mute_all_sounds();
	HEADPHONE_FIX=0;
	Z_S_mgr.Stop_headphones_change(false);


	Z_S_mgr.read_master_volume();

	calculate_free_RAM(5);
}

byte count_cycle;
bool head_mute=false;
bool first_send_eq=true;


void loop() {
	
	//for(int x=0;x<STOP_mgr.Stop_count;x++)
	//{
	//DEBUG_STRING_print("id:");
	//DEBUG_print(x);
	//DEBUG_STRING_print(" : ");
	//DEBUG_println(	STOP_mgr.id(x)->get_MIDI_CH());
	//}
	//DEBUG_println();
	//delay(30000);
	
	digitalWrite(STOP1_OUT_ENABLE,HIGH);
	//#define CLK_STOPS1  84
	//#define LOAD_165_STOPS1 A8
	//#define MISO_165_STOPS1  A9
	//#define SS_595_STOPS1  A10
	//#define MOSI_595_STOPS1  12
	//DEBUG_STRING_print(" clk:");
	//DEBUG_print(CLK_STOPS1);
	//DEBUG_STRING_print(" ss165:");
	//DEBUG_print(LOAD_165_STOPS1);
	//DEBUG_STRING_print(" miso:");
	//DEBUG_print(MISO_165_STOPS1);
	//DEBUG_STRING_print(" ss:");
	//DEBUG_print(SS_595_STOPS1);
	//DEBUG_STRING_print(" mosi:");
	//DEBUG_println(MOSI_595_STOPS1);
	
	if(millis()-previous_millis>1000)
	{
		doSomething();
		previous_millis=millis();
	}
	if(first_send_eq)
	{
		SD_work.SD_mgr_init();
	}
	
	if(digitalRead(HEAD_MUTE)!=head_mute||first_send_eq==true)
	{
		first_send_eq=false;
		head_mute=digitalRead(HEAD_MUTE);
		if(digitalRead(HEAD_MUTE))
		{
			delay(200);
			MIDI_sender.equalizer_headphones_send();
			DEBUG_println(F("headphone equlizer ON"));
			//HEADPHONE_FIX=43;
			HEADPHONE_FIX=0;
			MIDI_sender.mute_all_sounds();
			Z_S_mgr.Stop_headphones_change(false);
		}
		else
		{
			delay(200);
			MIDI_sender.equalizer_startup_send();
			DEBUG_println(F("headphone equlizer OFF"));
			HEADPHONE_FIX=0;
			MIDI_sender.mute_all_sounds();
			Z_S_mgr.Stop_headphones_change(false);

		}
		
	}

	//t.update();
	//timer_input.update();
	numb++;

	Z_S_mgr.read_Keyboards();
	

	Z_S_mgr.read_MIDIC_pedal();
	Z_S_mgr.inputCheck();
	Z_S_mgr.read_master_volume();
	Z_S_mgr.read_gas_pedal();
	MENU_mgr.display_menu();

}

#endif


#define  _testing1


