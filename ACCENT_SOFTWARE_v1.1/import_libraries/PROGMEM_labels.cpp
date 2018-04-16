//
//
//

#include "PROGMEM_labels.h"

#define HELLO_WORLD "Hello World"
#define HELLO_WORLD2 "Hello World"




















const __FlashStringHelper* return_label(int id)
{
	switch (id) {
		case 3:return F("");	break;
		case 2:return F("");	break;
		//case NUM_reverb_type:return F("")  ; break;
		//case H_pre_LPF:return  ; break;
		//case H_master_level:return  ; break;
		//case H_reverb_time_ms:return  ; break;
		//case H_delay_feedback:return  ; break;
		//case H_predelay_time:return  ; break;
		//case H_reverb_send:return  ; break;
		//case H_neutral:return  ; break;
		//case H_natuerlich_harmo:return  ; break;
		//case H_mitteltoenig:return  ; break;
		//case H_mittel_muriorg:return  ; break;
		//case H_ho_cheng_thien:return  ; break;
		//case H_joung:return  ; break;
		//case H_praetorious:return  ; break;
		//case H_pytagoras:return  ; break;
		//case H_gramathaeus_orgel:return  ; break;
		//case H_ganassi:return  ; break;
		//case H_schlick:return  ; break;
		//case H_werckmeister_3:return  ; break;
		//case H_silberman_1:return  ; break;
		//case H_silberman_2:return  ; break;
		//case H_bach_billeter:return  ; break;
		//case H_back_woltemp:return  ; break;
		//case H_billeter_orgel:return  ; break;
		//case H_kimberger_1:return  ; break;
		//case H_kimberger_2:return  ; break;
		//case H_kimberger_3:return  ; break;
		//case H_kelletal_1966:return  ; break;
		//case H_kelletal_1977:return  ; break;
		//case H_werckmeister_2:return  ; break;
		//case H_style_1:return  ; break;
		//case H_style_2:return  ; break;
		//case H_style_3:return  ; break;
		//case H_style_4:return  ; break;
		//case H_style_5:return  ; break;
		//case H_style_6:return  ; break;
		//case H_color_1:return  ; break;
		//case H_color_2:return  ; break;
		//case H_color_3:return  ; break;
		//case H_color_4:return  ; break;
		//case H_color_5:return  ; break;
		//case H_plus:return  ; break;
		//case H_stop_label:return  ; break;
		//case H_root:return  ; break;
		//case C_a1:return  ; break;
		//case C_a2:return  ; break;
		//case C_a3:return  ; break;
		//case H_Setter_combination:return  ; break;
		//case H_transpose:return  ; break;
		//case H_Setter_combination_null:return  ; break;
		//case H_exp_ped:return  ; break;
		//case H_cr_ped:return  ; break;
//
//
//
//
		//case H_options:return  ; break;
		//case H_sound:return  ; break;
		//case H_effect:return  ; break;
		//case H_styles:return  ; break;
		//case H_voicing:return  ; break;
		//case H_instrument:return  ; break;
		//case H_hist_temperament:return  ; break;
//
		//case H_reverb_:return  ; break;
		//case H_reverb:return  ; break;
		//case H_mem_bank:return  ; break;
		//case H_tremulant:return  ; break;
		//case H_tremulant1:return  ; break;
		//case H_tremulant1_depth:return  ; break;
		//case H_intonation:return  ; break;
//
		//case H_menu_testA:return  ; break;
		//case H_menu_testB:return  ; break;
		//case H_menu_testC:return  ; break;
		//case H_menu_testD:return  ; break;
//
//
		//case H_tremulant2:return  ; break;
		//case H_rec_play:return  ; break;
		//case H_utility:return  ; break;
		//case H_transpose_:return  ; break;
//
		//case H_PAN:return  ; break;
		//case H_LEFT:return  ; break;
		//case H_RIGHT:return  ; break;
		//case H_EFFECT:return  ; break;
		//case H_DECAY:return  ; break;
		//case H_LEVEL:return  ; break;
//
		//case H_TVF_RESONANCE:return  ; break;
		//case H_TVF_CUTOFF:return  ; break;
//
		//case HEADERPTR:return  ; break;
//
		//case H_EQUALIZER:return  ; break;
		//case H_GAIN:return  ; break;
		//case H_BAND_FREQ:return  ; break;
//
		//case H_BASS:return  ; break;
		//case H_MIDDLE:return  ; break;
		//case H_TREBLE:return  ; break;
//
		//case H_GAIN_LOW:return  ; break;
		//case H_GAIN_LOW_MID:return  ; break;
		//case H_GAIN_HIGH_MID:return  ; break;
		//case H_GAIN_HIGH:return  ; break;
//
		//case H_0_800HZ:return  ; break;
		//case H_0_2500HZ:return  ; break;
		//case H_60_10700HZ:return  ; break;
		//case H_1000_5800:return  ; break;
//
//
		//case H_STYLE:return  ; break;
		//case H_ROMANTIC:return  ; break;
		//case H_TUNING:return  ; break;
		//case H_EQUAL:return  ; break;
//
		//case H_stop_edit:return  ; break;
		//case H_principal_8:return  ; break;
		//case H_oktava_4:return  ; break;
		//case H_principal_2:return  ; break;
		//case H_les_flavta_4:return  ; break;
		//case H_trobenta_8:return  ; break;
//
		//case H_pipe_edit:return  ; break;
		//case H_organ:return  ; break;
		//case H_save:return  ; break;
		//case H_todo:return  ; break;
//
		//case H_about :return  ; break;
		//case H_theme:return  ; break;
		//case H_language:return  ; break;
		//case H_main:return  ; break;
		//case H_crescendo:return  ; break;
		//case H_gen_volume:return  ; break;
//
		//case H_white_black:return  ; break;
		//case H_white_blue:return  ; break;
		//case H_white_red:return  ; break;
		//case H_black_white:return  ; break;
		//case H_black_blue:return  ; break;
		//case H_black_red:return  ; break;
//
		//case H_RGB_R:return  ; break;
		//case H_RGB_G:return  ; break;
		//case H_RGB_B:return  ; break;
//
//
		//case H_en_us:return  ; break;
		//case H_de_at:return  ; break;
		//case H_default:return  ; break;
		//case H_screen_2:return  ; break;
		//case H_screen_3:return  ; break;
		//case H_volume:return  ; break;


	


		
		default:
		// statements
		break;
	}
}





const char s_neutral[] PROGMEM = { "1 EQUAL" };
const char s_natuerlics_harmo[] PROGMEM = { "2 NATUERLICS HARMO." };
const char s_mitteltoenig[] PROGMEM = { "3 MITTELTOENIG" };
const char s_mittel_muriorg[] PROGMEM = { "4 MITTEL MURIORG" };
const char  s_ho_cheng_thien[] PROGMEM = { "5 HO CHENG THIEN" };
const char  s_joung[] PROGMEM = { "6 JOUNG" };
const char  s_praetorious[] PROGMEM = { "7 PRAETORIOUS" };
const char  s_pytagoras[] PROGMEM = { "8 PYTAGORAS" };
const char  s_gramathaeus_orgel[] PROGMEM = { "GRAMATHAEUS" };
const char  s_ganassi[] PROGMEM = { "GANASSI" };
const char  s_schlick[] PROGMEM = { "SCHLICK" };
const char  s_werckmeister_3[] PROGMEM = { "WERCKMEISTER" };
const char  s_silberman_1[] PROGMEM = { "SILBERMAN 1" };
const char  s_silberman_2[] PROGMEM = { "SILBERMAN 2" };
const char  s_bach_billeter[] PROGMEM = { "BACH BILLETER" };
const char  s_back_woltemp[] PROGMEM = { "BACK WOLTEMP." };
const char  s_billeter_orgel[] PROGMEM = { "BILLETER ORGEL" };
const char  s_kimberger_1[] PROGMEM = { "KIRNBERGER 1" };
const char  s_kimberger_2[] PROGMEM = { "KIRNBERGER 2" };
const char  s_kimberger_3[] PROGMEM = { "KIRNBERGER 3" };
const char  s_kelletal_1966[] PROGMEM = { "KELLETAL 1966" };
const char  s_kelletal_1977[] PROGMEM = { "KELLETAL 1977" };
const char  s_werckmeister_2[] PROGMEM = { "WERCKMEISTER 2" };




__FlashStringHelper* H_neutral = (__FlashStringHelper*)s_neutral;
__FlashStringHelper* H_natuerlich_harmo = (__FlashStringHelper*)s_natuerlics_harmo;
__FlashStringHelper* H_mitteltoenig = (__FlashStringHelper*)s_mitteltoenig;
__FlashStringHelper* H_mittel_muriorg = (__FlashStringHelper*)s_mittel_muriorg;
__FlashStringHelper* H_ho_cheng_thien = (__FlashStringHelper*)s_ho_cheng_thien;
__FlashStringHelper* H_joung = (__FlashStringHelper*)s_joung;
__FlashStringHelper* H_praetorious = (__FlashStringHelper*)s_praetorious;
__FlashStringHelper* H_pytagoras = (__FlashStringHelper *)s_pytagoras;
__FlashStringHelper* H_gramathaeus_orgel = (__FlashStringHelper *)s_gramathaeus_orgel;
__FlashStringHelper* H_ganassi = (__FlashStringHelper *)s_ganassi;
__FlashStringHelper* H_schlick = (__FlashStringHelper *)s_schlick;
__FlashStringHelper* H_werckmeister_3 = (__FlashStringHelper *)s_werckmeister_3;
__FlashStringHelper* H_silberman_1 = (__FlashStringHelper *)s_silberman_1;
__FlashStringHelper*  H_silberman_2 = (__FlashStringHelper *)s_silberman_2;
__FlashStringHelper*  H_bach_billeter = (__FlashStringHelper *)s_bach_billeter;
__FlashStringHelper*  H_back_woltemp = (__FlashStringHelper *)s_back_woltemp;
__FlashStringHelper* H_billeter_orgel = (__FlashStringHelper *)s_billeter_orgel;
__FlashStringHelper* H_kimberger_1 = (__FlashStringHelper *)s_kimberger_1;
__FlashStringHelper* H_kimberger_2 = (__FlashStringHelper *)s_kimberger_2;
__FlashStringHelper* H_kimberger_3 = (__FlashStringHelper *)s_kimberger_3;
__FlashStringHelper* H_kelletal_1966 = (__FlashStringHelper *)s_kelletal_1966;
__FlashStringHelper* H_kelletal_1977 = (__FlashStringHelper *)s_kelletal_1977;
__FlashStringHelper* H_werckmeister_2 = (__FlashStringHelper *)s_werckmeister_2;

//const char s_exp_ped[] PROGMEM = { "EXP PEDAL" };
////__FlashStringHelper* H_exp_ped = (__FlashStringHelper*)s_exp_ped;
//const char s_cr_ped[] PROGMEM = { "CR  PEDAL" };
//__FlashStringHelper* H_cr_ped = (__FlashStringHelper*)s_cr_ped;


