/*
* menu_mgr.cpp
*
* Created: 30.3.2017 11:56:02
* Author: Greg
*/


#include "menu_mgr.h"
#include "Definitions.h"
#include "global_variables.h"
#include "custom_menu.h"
#include "PROGMEM_labels.h"
#include "EEPROM.h"
#include "global_methods.h"

extern uint8_t SixteenSegment[];
extern uint8_t Sinclair_S[];
extern uint8_t mykefont2[];
//extern uint8_t OCR_A_Extended_M[];
extern uint8_t GroteskBold32x64[];
extern uint8_t GroteskBold24x48[];
extern uint8_t Grotesk32x64[];
extern uint8_t Sinclair_M[];
extern uint8_t SmallFont[];
extern uint8_t arial_bold[];
extern uint8_t arial_normal[];
extern uint8_t hallfetica_normal[];
extern uint8_t Various_Symbols_32x32[];
extern uint8_t ArialNumFontPlus[];
extern uint8_t SevenSegNumFontPlus[];
extern uint8_t BigFont1[];
extern uint8_t Ubuntu[];
extern uint8_t Retro8x16[];
extern unsigned int Accent_logo[];
extern unsigned int white_accent_logo[];
extern unsigned int green_accent_logo_[];
extern UTFT myGLCD(ILI9327, 38, 39, 40, 41);

// default constructor
menu_mgr::menu_mgr()
{
} //menu_mgr

// default destructor
menu_mgr::~menu_mgr()
{
} //~menu_mgr


#include "global_variables.h"
#include "PROGMEM_labels.h"
#include "PROGMEM_address_var.h"
#include "custom_menu.h"
//#include "LCD_mgr.h"
#include "global_methods.h"
#include "EEPROM.h"


#include "Encoder.h"

int theme = EEPROM.read(ADD_menu_b8_theme_1);//0 belo-èrna, 1 èrno-bela, 2 belo-modra, 3 èrno-modra, èrno-rdeèa


int button_width = 150;//širina gumba
int button_heigth = 35;//višina gumba

static const byte b_UP = 1;
static const byte b_DOWN = 2;
static const byte b_BACK = 3;
static const byte b_ENTER = 4;
static const byte b_STILL = 0;

MenuSystem ms;

Menu root( NUM_root);

//Menu menu_0("SETTINGS", b1_[0], b1_[1]);
Menu menu_main_screen1(NUM_enter_menu);
//MenuItem menu_main_screen1_all_titles(NUM_Setter_combination);


MenuItem menu_main_screen1_volume(NUM_VOLUME_SLIDER);
//MenuItem menu_main_screen1_volume_label(NUM_VOL_label);
MenuItem menu_main_screen1_zecer_label(NUM_Z_COMBINATION);//type big label
//MenuItem menu_main_screen1_zecer_label_title(NUM_Setter_combination);
//MenuItem menu_main_screen1_zecer_label_title_TRANSPOSE(NUM_transpose_1);

MenuItem menu_main_screen1_zecer_label_TRANSPOSE(NUM_transpose_label);

MenuItem menu_main_screen1_LABELS(NUM_MAIN_STATIC_LABEL);
MenuItem menu_main_screen1_zecer_label_REVERB(NUM_REVERB_VALUE);

MenuItem menu_main_screen1_zecer_LABEL_Z(NUM_Z_LABEL);

#ifdef CRESCENDO_PEDAL_DISPLAY
MenuItem menu_main_screen1_crescendo_slider(NUM_cr_ped);//515
MenuItem menu_main_screen1_exp_ped__slider(NUM_exp_ped);//490

MenuItem menu_main_screen1_zecer_label_title_exp_ped(NUM_exp_ped_label);
MenuItem menu_main_screen1_zecer_label_title_cr_ped(NUM_cr_ped_label);
#endif // CRESCENDO_PEDAL_DISPLAY

#ifndef CRESCENDO_PEDAL_DISPLAY
MenuItem menu_main_screen1_exp_ped__slider(NUM_exp_ped);
MenuItem menu_main_screen1_zecer_label_title_exp_ped(NUM_exp_ped_label);
#endif // !CRESCENDO_PEDAL_DISPLAY



//MenuItem menu_main_screen1_Setting_buttn(H_plus, 5, 5, type_buttn_symbol, 0);
//MenuItem menu_main_screen1_null_item(H_Setter_combination_null, 60, 30, type_label, ADDRESS_ROOT - 1);
//Menu menu_main_screen2(H_main, b1_[0], b1_[1]);H_voicing



Menu menu_b2(NUM_styles_menu);
Menu menu_B3(NUM_transpose_menu);
Menu menu_b4(NUM_hist_temperament_menu);
Menu menu_b5(NUM_EFFECT_menu);
Menu menu_B1(NUM_utility_menu);
Menu menu_B2(NUM_tremulant_menu);
Menu menu_b1(NUM_EQUALIZER_menu);

Menu menu_b9(NUM_intonation_menu);
//Menu menu_b10(NUM_calibration_menu);

//Menu menu_b10_REC_PLAY(NUM_intonation_menu);
//Menu menu_b10(H_voicing, b10_[0], b10_[1]);
//Menu menu_b9(H_transpose_, b9_[0], b9_[1]);

MenuItem menu_transpose(NUM_transpose);
MenuItem menu_swap_keyboard(NUM_swap_keyboard);




//Menu menu_b5__PRESETS(NUM_PRESETS_menu);
Menu menu_b5_REVERB1_EFFECT(NUM_REVERB_1_menu);
Menu menu_b5_REVERB2_EFFECT(NUM_REVERB_2_menu);


Menu menu_b8(NUM_mem_bank_menu);

#ifdef vkljuci_menije

Menu menu_SAVE_SAVE_LOAD(NUM_save_load);
Menu menu_SAVE_SEETINGS(NUM_settings);
Menu menu_SAVE_ORGANIST(NUM_organist);

MenuItem menu_save_buttn_dialog(NUM_save_buttn_settings);
MenuItem menu_load_buttn_dialog(NUM_load_buttn_settings);
MenuItem menu_dest_file(NUM_dest_file);

MenuItem menu_save_buttn_dialog_organist(NUM_save_buttn_dialog);
MenuItem menu_load_buttn_dialog_organist(NUM_load_buttn_dialog);
MenuItem menu_src_file_organist(NUM_src_file_setter);
MenuItem menu_dest_file_organist(NUM_dest_file_setter);


//
//MenuItem_rec_play menu_PLAY_buttn(NUM_PLAY_buttn);
//MenuItem menu_PLAY_file(NUM_PLAY_file);
#endif

MenuItem menu_reverb_master_level(NUM_master_level);
MenuItem menu_reverb_reverb_type(NUM_reverb_type_);
MenuItem menu_reverb_pre_LPF(NUM_pre_LPF);

MenuItem menu_reverb_reverb_time_ms(NUM_reverb_time_ms);
//MenuItem menu_reverb_delay_feedback(H_delay_feedback, s1_[0], s1_[1], type_slider_negative_single_label, add_VALUE_delay_feedback);
MenuItem menu_reverb_predelay_time(NUM_predelay_time);
MenuItem menu_reverb_delay_feedback(NUM_delay_feedback);
MenuItem menu_reverb_send(NUM_reverb_send);
MenuItem menu_reverb_character(NUM_reverb_character_I);



MenuItem menu_reverb_master_level_II(NUM_master_level_II);
MenuItem menu_reverb_reverb_type_II(NUM_reverb_type_II);
MenuItem menu_reverb_pre_LPF_II(NUM_pre_LPF_II);

MenuItem menu_reverb_reverb_time_ms_II(NUM_reverb_time_ms_II);
MenuItem menu_reverb_predelay_time_II(NUM_predelay_time_II);
MenuItem menu_reverb_delay_feedback_II(NUM_delay_feedback_II);
MenuItem menu_reverb_send_II(NUM_reverb_send_II);
MenuItem menu_reverb_characterII(NUM_reverb_character_II);

MenuItem menu_reverb_presets(NUM_reverb_character_II);


MenuItem menu_TREMULNAT1(NUM_tremulant1);
MenuItem menu_TREMULNAT1_depth(NUM_tremulant1_depth);

//MenuItem menu_testA(NUM_TEST_A);
//MenuItem menu_testB(NUM_TEST_B);
//MenuItem menu_testC(NUM_TEST_C);
//MenuItem menu_testD(NUM_TEST_D);
//
//MenuItem menu_TREMULNAT2(H_tremulant2, s2_[0], s2_[1], type_slider_negative_single_label, add_VALUE_tremulnat2);


//Menu menu_b1_equalizer(H_EQUALIZER, b1_[0], b1_[1]);


//Menu menu_b1_equalizer_gain(H_GAIN, b1_[0], b1_[1]);
//Menu menu_b1_equalizer_band_freq(H_BAND_FREQ, b2_[0], b2_[1]);

Menu menu_b1_SPEAKERS(NUM_EQU_SPEAKERS);
Menu menu_b1_HEADPHONES(NUM_EQU_HEADPHONES);

Menu menu_b1_MAN_I_EQU(NUM_MAN_I_EQU);
Menu menu_b1_MAN_II_EQU(NUM_MAN_II_EQU);

Menu menu_b1_MAN_I_EQU_HEADPHONES(NUM_MAN_I_EQU_HEADPHONES);
Menu menu_b1_MAN_II_EQU_HEADPHONES(NUM_MAN_II_EQU_HEADPHONES);

MenuItem_editable menu_b1_equalizer_gain_low(NUM_GAIN_LOW);
MenuItem_editable menu_b1_equalizer_band_freq_low_band_0_800(NUM_band_freq_low_band_0_800);
MenuItem_editable menu_b1_equalizer_gain_Q_low(NUM_gain_Q_low);

MenuItem_editable menu_b1_equalizer_gain_low_mid(NUM_GAIN_LOW_MID);
MenuItem_editable menu_b1_equalizer_band_freq_low_mid_band_0_2500(NUM_band_freq_low_mid_band_0_2500);
//MenuItem menu_b1_equalizer_select(NUM_EQ_SELECT);

MenuItem_editable menu_b1_equalizer_gain_high_mid(NUM_equalizer_gain_high_mid);
MenuItem_editable menu_b1_equalizer_band_freq_high_mid_band_60_10700(NUM_equalizer_band_freq_high_mid_band_60_10700 );
//MenuItem menu_b1_equalizer_gain_Q_high_mid(NUM_GAIN_HIGNUM_MID, 160, 10, type_slider_equ_Q, ADD_menu_b1_equalizer_Q_high_mid);

MenuItem_editable menu_b1_equalizer_gain_high(NUM_equalizer_gain_high);
MenuItem_editable menu_b1_equalizer_band_freq_high_band_1000_5800(NUM_band_freq_high_band_1000_5800);
MenuItem_editable menu_b1_equalizer_gain_Q_high(NUM_gain_Q_high);

#define test_add_equ
#ifdef test_add_equ1
MenuItem_editable menu_b1_equalizer_gain_low_II(NUM_GAIN_LOW);
MenuItem_editable menu_b1_equalizer_band_freq_low_band_0_800_II(NUM_band_freq_low_band_0_800);
MenuItem_editable menu_b1_equalizer_gain_Q_low_II(NUM_gain_Q_low);

MenuItem_editable menu_b1_equalizer_gain_low_mid_II(NUM_GAIN_LOW_MID);
MenuItem_editable menu_b1_equalizer_band_freq_low_mid_band_0_2500_II(NUM_band_freq_low_mid_band_0_2500);
MenuItem menu_b1_equalizer_select_II(NUM_EQ_SELECT);

MenuItem_editable menu_b1_equalizer_gain_high_mid_II(NUM_equalizer_gain_high_mid);
MenuItem_editable menu_b1_equalizer_band_freq_high_mid_band_60_10700_II(NUM_equalizer_band_freq_high_mid_band_60_10700 );
//MenuItem menu_b1_equalizer_gain_Q_high_mid(NUM_GAIN_HIGNUM_MID, 160, 10, type_slider_equ_Q, ADD_menu_b1_equalizer_Q_high_mid);

MenuItem_editable menu_b1_equalizer_gain_high_II(NUM_equalizer_gain_high);
MenuItem_editable menu_b1_equalizer_band_freq_high_band_1000_5800_II(NUM_band_freq_high_band_1000_5800);
//MenuItem_editable menu_b1_equalizer_gain_Q_high_II(NUM_gain_Q_high);
#endif





Menu menu_b1_STOP_select_menu(NUM_STOP_SELECT_menu);
MenuItem_editable menu_b1_PAN_stop_select(NUM_STOP_SELECTOR);
MenuItem_editable menu_b1_PAN_leftright(NUM_LEFT);
MenuItem_editable menu_b1_stop_level(NUM_LEVEL);
MenuItem_editable menu_b1_tvf_resonance(NUM_TVF_RESONANCE);
MenuItem_editable menu_b1_tvf_cutoff(NUM_TVF_CUTOFF);
MenuItem_editable menu_b1_tone_selector(NUM_tone_selector);


Menu menu_b1_manual_lvls(NUM_STOPS_LVLS_menu);
MenuItem menu_b1_ped_lvl(NUM_MAN_PED_LVL);
MenuItem menu_b1_man_I_lvl(NUM_MAN_I_LVL);
MenuItem menu_b1_man_II_lvl(NUM_MAN_II_LVL);



//gumb 3
MenuItem menu_hist_temp(NUM_hist_temperament);
MenuItem menu_tune_cent(NUM_tune_cent);

MenuItem menu_STYLE(NUM_STYLE);
MenuItem menu_mem_bank(NUM_mem_bank);
//MenuItem menu_b3_ROMANTIC(NUM_ROMANTIC);
//MenuItem menu_b3_TUNING(NUM_TUNING);
//MenuItem menu_b3_EQUAL(NUM_EQUAL);

Menu menu_theme(NUM_theme);
//Menu menu_about(NUM_about);
Menu menu_special(NUM_special);

MenuItem menu_sweel_calibration(NUM_swell_calibration);
//Menu menu_b8_screen(H_main, b3_[0], b3_[1] );
//MenuItem menu_b8_organ(NUM_organ);
MenuItem menu_b8_membankstatus(NUM_crescendo);
MenuItem menu_b8_genvolume(NUM_gen_volume);

MenuItem menu_b8_theme_1(NUM_white_black);
MenuItem menu_b8_theme_R(NUM_RGB_R);
MenuItem menu_b8_theme_G(NUM_RGB_G);
MenuItem menu_b8_theme_B(NUM_RGB_B);

MenuItem menu_FIRMWARE(NUM_en_us);

#define trenutni_equ1


Menu menu_REC_PLAY(NUM_REC_PLAY_menu);


Menu menu_REC(NUM_REC_menu);
Menu menu_PLAY(NUM_PLAY_menu);

MenuItem_rec_play menu_REC_buttn(NUM_REC_buttn);
MenuItem_rec_play menu_REC_file(NUM_REC_file);
MenuItem menu_NUM_timer(NUM_timer);

MenuItem_rec_play menu_PLAY_buttn(NUM_PLAY_buttn);
MenuItem menu_PLAY_file(NUM_PLAY_file);
MenuItem menu_NUM_play_timer(NUM_play_timer);


void menu_mgr::menu_init()
{
	setTheme(theme);
	myGLCD.InitLCD();

	//myGLCD.setFont(arial_normal);
	//myGLCD.fillScr(132, 22, 24);
	//myGLCD.fillScr(back_color[0], back_color[1], back_color[2]);
	#ifdef INCLUDE_FINAL
	//myGLCD.fillScr(132, 22, 24);
	//myGLCD.drawBitmap(135, 80, 158, 35, accent_logo_black_mini, 1);
	//myGLCD.drawBitmap(135, 80, 200, 63, Accent_logo, 1);
	
	//myGLCD.fillScr(34,83,79);
	//myGLCD.drawBitmap(135, 80, 210, 65, green_accent_logo_, 1);
	
	myGLCD.fillScr(255,255,255);
	myGLCD.drawBitmap(135, 80, 209, 64, white_accent_logo, 1);
	
	//myGLCD.drawBitmap(100, 100, 100, 140, Anton_Skrabl, 1);
	delay(1000);
	//myGLCD.drawBitmap(135, 80, 200, 63, accent_logo_black_mini, 1);
	//delay(4500); //dodaj delay
	#else
	delay(1300);
	#endif




	myGLCD.fillScr(back_color[0], back_color[1], back_color[2]);

	menu_main_screen1_volume.set_interactive(false);
	//menu_main_screen1_volume_label.set_interactive(false);
	//menu_main_screen1_volume_label.setValue(90);
	menu_main_screen1_zecer_label.set_interactive(false);
	menu_main_screen1_zecer_label.setValue(0);
	//menu_main_screen1_zecer_label_title.set_interactive(false);
	//menu_main_screen1_zecer_label_title.setValue(0);
	//menu_main_screen1_zecer_label_TRANSPOSE.set_interactive(false);
	//menu_main_screen1_zecer_label_TRANSPOSE.setValue(0);
	//menu_main_screen1_zecer_LABEL_Z.set_interactive(false);
	//menu_main_screen1_zecer_LABEL_Z.setValue(0);
	




	//	menu_main_screen1_zecer_label_title_exp_ped.set_interactive(false);
	//	menu_main_screen1_zecer_label_title_exp_ped.setValue(90);

	
	menu_main_screen1_exp_ped__slider.set_interactive(false);

	root.add_menu(&menu_main_screen1, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	//root.add_item(&menu_main_screen1_volume, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	root.add_item(&menu_main_screen1_volume, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//root.add_item(&menu_main_screen1_volume_label, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	root.add_item(&menu_main_screen1_zecer_label, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	root.add_item(&menu_main_screen1_LABELS, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//	root.add_item(&menu_main_screen1_zecer_label_title, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);


	#ifdef CRESCENDO_PEDAL_DISPLAY

	menu_main_screen1_crescendo_slider.set_interactive(false);
	menu_main_screen1_zecer_label_title_cr_ped.set_interactive(false);
	menu_main_screen1_zecer_label_title_cr_ped.setValue(90);
	root.add_item(&menu_main_screen1_zecer_label_title_cr_ped, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	root.add_item(&menu_main_screen1_crescendo_slider, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//menu_main_screen1_Setting_buttn
	#endif

	//root.add_item(&menu_main_screen1_zecer_label_title_exp_ped, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	

	//root.add_item(&menu_main_screen1_zecer_label_title_TRANSPOSE, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//	root.add_item(&menu_main_screen1_zecer_label_title_REVERB, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	root.add_item(&menu_main_screen1_zecer_label_TRANSPOSE, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	root.add_item(&menu_main_screen1_zecer_label_REVERB, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	root.add_item(&menu_main_screen1_zecer_LABEL_Z, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	
	
	root.add_item(&menu_main_screen1_exp_ped__slider, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//root.add_item(&menu_main_screen1_Setting_buttn, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//root.add_item(&menu_main_screen1_null_item, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//root.add_menu(&menu_main_screen2, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_main_screen1.add_menu(&menu_B1, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	//menu_main_screen1.add_menu(&menu_b1, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_main_screen1.add_menu(&menu_B2, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_main_screen1.add_menu(&menu_B3, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_main_screen1.add_menu(&menu_b4, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_main_screen1.add_menu(&menu_REC_PLAY, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	
	//menu_main_screen1.add_menu(&menu_special, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	


	menu_main_screen1.add_menu(&menu_b8, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	
	menu_main_screen1.add_menu(&menu_b5, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	//menu_main_screen1.add_menu(&menu_about, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	#ifdef vkljuci_menije
	menu_main_screen1.add_menu(&menu_SAVE_SAVE_LOAD, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	
	menu_main_screen1.add_menu(&menu_SAVE_SEETINGS, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	

	//menu_B1.add_menu(&menu_about, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	//menu_SAVE_SAVE_LOAD.add_menu(&menu_SAVE_SEETINGS, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	//menu_SAVE_SAVE_LOAD.add_menu(&menu_SAVE_ORGANIST, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);

	
	menu_SAVE_SAVE_LOAD.add_item(&menu_dest_file_organist, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_SAVE_SAVE_LOAD.add_item(&menu_src_file_organist, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_SAVE_SAVE_LOAD.add_item(&menu_load_buttn_dialog_organist, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_SAVE_SAVE_LOAD.add_item(&menu_save_buttn_dialog_organist, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);

	//menu_SAVE_SEETINGS.add_item(&menu_src_file_organist, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_SAVE_SEETINGS.add_item(&menu_dest_file, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_SAVE_SEETINGS.add_item(&menu_load_buttn_dialog, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_SAVE_SEETINGS.add_item(&menu_save_buttn_dialog, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);


	menu_dest_file_organist.setValue(1);
	menu_src_file_organist.setValue(1);
	menu_dest_file.setValue(1);
	menu_src_file_organist.setValue(1);

#endif
	DEBUG_STRING_println("reset-->");
	DEBUG_println(ZECER.id(BUTTN_RESET_1)->GetState());
	
	if(ZECER.id(BUTTN_SET_1)->GetState())
	{
		menu_main_screen1.add_menu(&menu_b1, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
		menu_main_screen1.add_menu(&menu_b9, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	}
	
	

	//menu_main_screen1.add_menu(&menu_b10, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	
	
	
	menu_REC_PLAY.add_menu(&menu_REC, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_REC_PLAY.add_menu(&menu_PLAY, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);


	//button 1
	#ifdef trenutni_equ
	menu_b1.add_menu(&menu_b1_SPEAKERS, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_b1.add_menu(&menu_b1_HEADPHONES, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	
	
	
	menu_b1_SPEAKERS.add_menu(&menu_b1_MAN_I_EQU, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_b1_SPEAKERS.add_menu(&menu_b1_MAN_I_EQU, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	

	menu_b1_HEADPHONES.add_menu(&menu_b1_MAN_I_EQU, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_b1_HEADPHONES.add_menu(&menu_b1_MAN_I_EQU, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);


	
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_gain_low, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_band_freq_low_band_0_800, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_gain_low_mid, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_band_freq_low_mid_band_0_2500, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_gain_Q_low, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_gain_high_mid, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_band_freq_high_mid_band_60_10700, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_gain_Q_high, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_gain_high, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_band_freq_high_band_1000_5800, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	#endif
	#ifdef test_add_equ
	menu_b1.add_menu(&menu_b1_HEADPHONES, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_b1.add_menu(&menu_b1_SPEAKERS, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	
	
	
	menu_b1_SPEAKERS.add_menu(&menu_b1_MAN_II_EQU, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_b1_SPEAKERS.add_menu(&menu_b1_MAN_I_EQU, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	

	menu_b1_HEADPHONES.add_menu(&menu_b1_MAN_I_EQU_HEADPHONES, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_b1_HEADPHONES.add_menu(&menu_b1_MAN_II_EQU_HEADPHONES, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);


	
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_gain_low, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_band_freq_low_band_0_800, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_gain_low_mid, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_band_freq_low_mid_band_0_2500, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_gain_Q_low, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_gain_high_mid, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_band_freq_high_mid_band_60_10700, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_gain_Q_high, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_gain_high, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU.add_item(&menu_b1_equalizer_band_freq_high_band_1000_5800, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	
	
	menu_b1_MAN_II_EQU.add_item(&menu_b1_equalizer_gain_low, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU.add_item(&menu_b1_equalizer_band_freq_low_band_0_800, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU.add_item(&menu_b1_equalizer_gain_low_mid, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU.add_item(&menu_b1_equalizer_band_freq_low_mid_band_0_2500, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU.add_item(&menu_b1_equalizer_gain_Q_low, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU.add_item(&menu_b1_equalizer_gain_high_mid, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU.add_item(&menu_b1_equalizer_band_freq_high_mid_band_60_10700, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU.add_item(&menu_b1_equalizer_gain_Q_high, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU.add_item(&menu_b1_equalizer_gain_high, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU.add_item(&menu_b1_equalizer_band_freq_high_band_1000_5800, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	
	
	menu_b1_MAN_I_EQU_HEADPHONES.add_item(&menu_b1_equalizer_gain_low, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU_HEADPHONES.add_item(&menu_b1_equalizer_band_freq_low_band_0_800, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU_HEADPHONES.add_item(&menu_b1_equalizer_gain_low_mid, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU_HEADPHONES.add_item(&menu_b1_equalizer_band_freq_low_mid_band_0_2500, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU_HEADPHONES.add_item(&menu_b1_equalizer_gain_Q_low, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU_HEADPHONES.add_item(&menu_b1_equalizer_gain_high_mid, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU_HEADPHONES.add_item(&menu_b1_equalizer_band_freq_high_mid_band_60_10700, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU_HEADPHONES.add_item(&menu_b1_equalizer_gain_Q_high, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU_HEADPHONES.add_item(&menu_b1_equalizer_gain_high, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_I_EQU_HEADPHONES.add_item(&menu_b1_equalizer_band_freq_high_band_1000_5800, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);

	
	menu_b1_MAN_II_EQU_HEADPHONES.add_item(&menu_b1_equalizer_gain_low, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU_HEADPHONES.add_item(&menu_b1_equalizer_band_freq_low_band_0_800, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU_HEADPHONES.add_item(&menu_b1_equalizer_gain_low_mid, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU_HEADPHONES.add_item(&menu_b1_equalizer_band_freq_low_mid_band_0_2500, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU_HEADPHONES.add_item(&menu_b1_equalizer_gain_Q_low, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU_HEADPHONES.add_item(&menu_b1_equalizer_gain_high_mid, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU_HEADPHONES.add_item(&menu_b1_equalizer_band_freq_high_mid_band_60_10700, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU_HEADPHONES.add_item(&menu_b1_equalizer_gain_Q_high, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU_HEADPHONES.add_item(&menu_b1_equalizer_gain_high, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_MAN_II_EQU_HEADPHONES.add_item(&menu_b1_equalizer_band_freq_high_band_1000_5800, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	#endif
	

	//button 2
	menu_b2.add_item(&menu_STYLE, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);

	//button 3

	menu_B3.add_item(&menu_transpose, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//menu_b3.add_item(&menu_b3_ROMANTIC, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//menu_b3.add_item(&menu_b3_TUNING, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//menu_b3.add_item(&menu_b3_EQUAL, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);

	menu_b4.add_item(&menu_hist_temp, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b4.add_item(&menu_tune_cent, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	
	menu_hist_temp.setValue(0);
	menu_tune_cent.setValue(20);
	
	//button 5
	//menu_b5.add_item(&menu_b5_organ, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5.add_menu(&menu_b5_REVERB1_EFFECT,&on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_b5.add_menu(&menu_b5_REVERB2_EFFECT,&on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	//menu_b5.add_menu(&menu_b5__PRESETS,&on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	
	
	menu_b5_REVERB1_EFFECT.add_item(&menu_reverb_master_level, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB1_EFFECT.add_item(&menu_reverb_reverb_type, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB1_EFFECT.add_item(&menu_reverb_pre_LPF, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB1_EFFECT.add_item(&menu_reverb_reverb_time_ms, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//menu_b5.add_item(&menu_reverb_delay_feedback, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB1_EFFECT.add_item(&menu_reverb_predelay_time, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB1_EFFECT.add_item(&menu_reverb_delay_feedback, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB1_EFFECT.add_item(&menu_reverb_send, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB1_EFFECT.add_item(&menu_reverb_character, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	


	menu_b5_REVERB2_EFFECT.add_item(&menu_reverb_master_level_II, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB2_EFFECT.add_item(&menu_reverb_reverb_type_II, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB2_EFFECT.add_item(&menu_reverb_pre_LPF_II, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB2_EFFECT.add_item(&menu_reverb_reverb_time_ms_II, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//menu_b5.add_item(&menu_reverb_delay_feedback, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB2_EFFECT.add_item(&menu_reverb_predelay_time_II, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB2_EFFECT.add_item(&menu_reverb_delay_feedback_II, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB2_EFFECT.add_item(&menu_reverb_send_II, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b5_REVERB2_EFFECT.add_item(&menu_reverb_characterII, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);

	//menu_b5__PRESETS.add_item(&menu_reverb_characterII, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);

	//button 6
	//	menu_b6.add_item(&menu_b6_internal, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	
	menu_B2.add_item(&menu_TREMULNAT1, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_B2.add_item(&menu_TREMULNAT1_depth, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//	menu_b7.add_item(&menu_testA, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//	menu_b7.add_item(&menu_testB, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//menu_b7.add_item(&menu_testC, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//menu_b7.add_item(&menu_testD, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	
	
	//menu_b7.add_item(&menu_TREMULNAT2, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//button 7
	//menu_b8.add_item(&menu_b7_mem, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);

	//button 8
	menu_B1.add_menu(&menu_theme, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	//menu_B1.add_menu(&menu_about, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	menu_B1.add_item(&menu_swap_keyboard, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	
	if(ZECER.id(BUTTN_SET_1)->GetState())
	{
		menu_B1.add_menu(&menu_special, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	}
	

	menu_special.add_item(&menu_sweel_calibration, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);

	//	menu_B1.add_item(&menu_sweel_calibration, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	
	//menu_special.add_item(&menu_sweel_calibration, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//menu_special.add_menu(&menu_b9, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	
	
	
	
	menu_b8.add_item(&menu_mem_bank, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);


	//menu_about.add_item(&menu_FIRMWARE, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//menu_b8.add_menu(&menu_b8_screen, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);

	menu_theme.add_item(&menu_b8_theme_1, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	
	
	//#ifdef RGB_LED_OUTPUT
	menu_theme.add_item(&menu_b8_theme_R, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_theme.add_item(&menu_b8_theme_G, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_theme.add_item(&menu_b8_theme_B, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	//#endif


	menu_b9.add_item(&menu_b1_PAN_stop_select, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b9.add_item(&menu_b1_PAN_leftright, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b9.add_item(&menu_b1_stop_level, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b9.add_item(&menu_b1_tvf_resonance, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b9.add_item(&menu_b1_tvf_cutoff, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b9.add_item(&menu_b1_tone_selector, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	
	
	
	menu_b9.add_menu(&menu_b1_manual_lvls, &on_menu_selected, &on_menu_draw_enabled, &on_menu_draw_disabled, &on_menu_clear);
	
	
	menu_b1_manual_lvls.add_item(&menu_b1_ped_lvl, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_manual_lvls.add_item(&menu_b1_man_I_lvl, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_b1_manual_lvls.add_item(&menu_b1_man_II_lvl, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	
	
	//RECORING PLAY
	
	menu_REC.add_item(&menu_REC_buttn, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_REC.add_item(&menu_REC_file, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_REC.add_item(&menu_NUM_timer, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	
	
	menu_PLAY.add_item(&menu_PLAY_buttn, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_PLAY.add_item(&menu_PLAY_file, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);
	menu_PLAY.add_item(&menu_NUM_play_timer, &on_item_select, on_item_draw_enabled, &on_item_draw_disabled, &on_item_clear);


	
	
	
	
	
	
	//	menu_b1.set_x(2);
	ms.set_root_menu(&root);
	ms.refresh();
	//	ms.next();
	//	ms.next();

	//ms.back();
	//displayMenu();
	int temp_vol = analogRead(MASTER_VOLUME_PIN);
	temp_vol = map(temp_vol, 0, 1023, 0, 127);
	menu_main_screen1_volume.setValue(MASTER_VOLUME);
	//menu_main_screen1_volume.draw_normal();



}





void menu_mgr::quick_fix_TRANSPOSE(byte trans)
{
	menu_main_screen1_zecer_label_TRANSPOSE.setValue(EEPROM.read(add_VALUE_TRANSPOSE));
	menu_transpose.setValue(trans);
	//TRANSPOSE_LABEL_TEXT = (String)((int)EEPROM.read(add_VALUE_TRANSPOSE)-TRANS_adjust);
	//menu_transpose.setValue(3);
	//tipka 25 == 0
	if (ms.is_root())
	{
		//menu_main_screen1_zecer_label_TRANSPOSE.setValue(3);
		//DEBUG_STRING_print("REFRESH OK");
		//DEBUG_println(EEPROM.read(add_VALUE_TRANSPOSE));
		menu_main_screen1_zecer_label_TRANSPOSE.draw_normal();
	}
}

void set_mode_color(byte mode)
{
	if (mode == ACTION_SELECT_COLOR)//checked
	myGLCD.setColor(check_color[0], check_color[1], check_color[2]);
	else if (mode == ACTION_REDRAW_COLOR)
	myGLCD.setColor(line_color[0], line_color[1], line_color[2]);
	else if (mode == ACTION_CLEAR_COLOR)
	myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	else if (mode == ACTION_EDITING_COLOR)//checked
	myGLCD.setColor(select_color[0], select_color[1], select_color[2]);
	else if (mode == ACTION_INFO_COLOR)//checked
	myGLCD.setColor(0, 255, 255);
	else if  (mode == ACTION_FIRST_DRAW)
	myGLCD.setColor(select_color[0], select_color[1], select_color[2]);

	
	

	//else if (mode == COLOR1)
	//	myGLCD.setColor(color1[0], color1[1], color1[2]);
}

////TODO: SPODAJ KUP SRANJA ZA UREDIT...
void drawButtonMenu(Menu* p_menu , int mode)
{

	int x=p_menu->get_x();
	int y=p_menu->get_y();
	String name= p_menu->get_name();
	int name_id= p_menu->get_name_id();
	
	
	if(mode==ACTION_EDITING_COLOR)//tmp fix, treba šparat ram
	{
		switch(name_id)
		{
			
			case NUM_MAN_I_EQU:
			menu_b1_equalizer_gain_low.setMemAddress(ADD_menu_b1_equalizer_gain_low);
			menu_b1_equalizer_band_freq_low_band_0_800.setMemAddress(ADD_menu_b1_equalizer_band_freq_low_band_0_800);
			menu_b1_equalizer_gain_Q_low.setMemAddress(ADD_menu_b1_equalizer_Q_low);
			menu_b1_equalizer_gain_low_mid.setMemAddress(ADD_menu_b1_equalizer_gain_low_mid);
			menu_b1_equalizer_band_freq_low_mid_band_0_2500.setMemAddress(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500);
			menu_b1_equalizer_gain_high_mid.setMemAddress(ADD_menu_b1_equalizer_gain_high_mid);
			menu_b1_equalizer_band_freq_high_mid_band_60_10700.setMemAddress(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700);
			menu_b1_equalizer_gain_high.setMemAddress(ADD_menu_b1_equalizer_gain_high);
			menu_b1_equalizer_band_freq_high_band_1000_5800.setMemAddress(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800);
			menu_b1_equalizer_gain_Q_high.setMemAddress(ADD_menu_b1_equalizer_Q_high_mid);
			break;
			
			case NUM_MAN_II_EQU:
			menu_b1_equalizer_gain_low.setMemAddress(ADD_menu_b1_equalizer_gain_low_II);
			menu_b1_equalizer_band_freq_low_band_0_800.setMemAddress(ADD_menu_b1_equalizer_band_freq_low_band_0_800_II);
			menu_b1_equalizer_gain_Q_low.setMemAddress(ADD_menu_b1_equalizer_Q_low_II);
			menu_b1_equalizer_gain_low_mid.setMemAddress(ADD_menu_b1_equalizer_gain_low_mid_II);
			menu_b1_equalizer_band_freq_low_mid_band_0_2500.setMemAddress(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_II);
			menu_b1_equalizer_gain_high_mid.setMemAddress(ADD_menu_b1_equalizer_gain_high_mid_II);
			menu_b1_equalizer_band_freq_high_mid_band_60_10700.setMemAddress(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_II);
			menu_b1_equalizer_gain_high.setMemAddress(ADD_menu_b1_equalizer_gain_high_II);
			menu_b1_equalizer_band_freq_high_band_1000_5800.setMemAddress(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_II);
			menu_b1_equalizer_gain_Q_high.setMemAddress(ADD_menu_b1_equalizer_Q_high_mid_II);
			break;
			
			case NUM_MAN_I_EQU_HEADPHONES:
			menu_b1_equalizer_gain_low.setMemAddress(ADD_menu_b1_equalizer_gain_low_III);
			menu_b1_equalizer_band_freq_low_band_0_800.setMemAddress(ADD_menu_b1_equalizer_band_freq_low_band_0_800_III);
			menu_b1_equalizer_gain_Q_low.setMemAddress(ADD_menu_b1_equalizer_Q_low_III);
			menu_b1_equalizer_gain_low_mid.setMemAddress(ADD_menu_b1_equalizer_gain_low_mid_III);
			menu_b1_equalizer_band_freq_low_mid_band_0_2500.setMemAddress(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_III);
			menu_b1_equalizer_gain_high_mid.setMemAddress(ADD_menu_b1_equalizer_gain_high_mid_III);
			menu_b1_equalizer_band_freq_high_mid_band_60_10700.setMemAddress(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III);
			menu_b1_equalizer_gain_high.setMemAddress(ADD_menu_b1_equalizer_gain_high_III);
			menu_b1_equalizer_band_freq_high_band_1000_5800.setMemAddress(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_III);
			menu_b1_equalizer_gain_Q_high.setMemAddress(ADD_menu_b1_equalizer_Q_high_mid_III);
			break;
			
			case NUM_MAN_II_EQU_HEADPHONES:
			menu_b1_equalizer_gain_low.setMemAddress(ADD_menu_b1_equalizer_gain_low_IV);
			menu_b1_equalizer_band_freq_low_band_0_800.setMemAddress(ADD_menu_b1_equalizer_band_freq_low_band_0_800_IV);
			menu_b1_equalizer_gain_Q_low.setMemAddress(ADD_menu_b1_equalizer_Q_low_IV);
			menu_b1_equalizer_gain_low_mid.setMemAddress(ADD_menu_b1_equalizer_gain_low_mid_IV);
			menu_b1_equalizer_band_freq_low_mid_band_0_2500.setMemAddress(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_IV);
			menu_b1_equalizer_gain_high_mid.setMemAddress(ADD_menu_b1_equalizer_gain_high_mid_IV);
			menu_b1_equalizer_band_freq_high_mid_band_60_10700.setMemAddress(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_IV);
			menu_b1_equalizer_gain_high.setMemAddress(ADD_menu_b1_equalizer_gain_high_IV);
			menu_b1_equalizer_band_freq_high_band_1000_5800.setMemAddress(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_IV);
			menu_b1_equalizer_gain_Q_high.setMemAddress(ADD_menu_b1_equalizer_Q_high_mid_IV);
			break;
			
		}
	}

	
	if (name_id == NUM_enter_menu)//temp fix
	{
		myGLCD.setFont(arial_bold);
		set_mode_color(mode);
		//myGLCD.setColor(line_color[0], line_color[1], line_color[2]);
		myGLCD.drawRoundRect(zeroX + 120, 207, zeroX + 200, 200 + button_heigth);
		myGLCD.drawRect(zeroX + 121, 208, zeroX + 199, 199 + button_heigth);
		myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
		
		if(mode==ACTION_REDRAW_COLOR||mode==ACTION_CLEAR_COLOR||mode==ACTION_FIRST_DRAW)
		{
			if(mode==ACTION_FIRST_DRAW)
			set_mode_color(ACTION_REDRAW_COLOR);
			
			myGLCD.print(name, zeroX + 10+120,  213);
		}
		
		return;
		
		myGLCD.drawRoundRect(zeroX + 10, 207, zeroX + 150, 200 + button_heigth);
		myGLCD.drawRect(zeroX + 11, 208, zeroX + 149, 199 + button_heigth);
		myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
		
		if(mode==ACTION_REDRAW_COLOR||mode==ACTION_CLEAR_COLOR||mode==ACTION_FIRST_DRAW)
		{
			if(mode==ACTION_FIRST_DRAW)
			set_mode_color(ACTION_REDRAW_COLOR);
			
			myGLCD.print(name, zeroX + 15,  213);
		}
		
		return;
	}
	

	myGLCD.setFont(arial_bold);
	set_mode_color(mode);
	//myGLCD.setColor(line_color[0], line_color[1], line_color[2]);
	myGLCD.drawRoundRect(zeroX + x, y, zeroX + x + button_width, y + button_heigth);
	myGLCD.drawRect(zeroX + x+1, y+1, zeroX + x + button_width-1, y + button_heigth-1);
	
	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	if(mode==ACTION_REDRAW_COLOR||mode==ACTION_CLEAR_COLOR||mode==ACTION_FIRST_DRAW)
	{
		if(mode==ACTION_FIRST_DRAW)
		set_mode_color(ACTION_REDRAW_COLOR);
		
		myGLCD.print(name, zeroX + x + 3, y + 10);
	}
	//myGLCD.print(name, zeroX + x + 3, y + 10);

	
}



void drawTinyLabel(MenuItem* p_menu_item, int value, byte mode)
{
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	if (p_menu_item->get_name_id() == NUM_cr_ped)
	{
		return;

	}
	else if (p_menu_item->get_name_id() == NUM_exp_ped)
	{
		return;
	}
	else if (p_menu_item->get_name_id() == NUM_VOL_label)
	{
		x=300;//tempfix
	}
	
	//int heigth = 225;
	x += zeroX;
	//x += 270;
	String name = p_menu_item->get_name();
	if ( p_menu_item->get_name_id() == NUM_exp_ped)
	return;

	set_mode_color(mode);

	if (mode != ACTION_CLEAR_COLOR && p_menu_item->value != 0)
	{
		myGLCD.setFont(mykefont2);
		if (p_menu_item->get_name_id() == NUM_VOL_label)
		myGLCD.print(name, x, y, 90);
		else
		myGLCD.print(name, x, y, p_menu_item->value);

	}
	else
	{
		myGLCD.fillRect(x-9, y, x, y+name.length() * 8);//performance boost
	}


}
void drawLabelInfo(MenuItem* p_menu_item, int value, byte mode)//ni še uporabljeno
{
	//myGLCD.setFont(OCR_A_Extended_M);
	myGLCD.setFont(arial_bold);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	//int heigth = 225;
	x += zeroX;
	//x += 270;
	String name = p_menu_item->get_name();
	if (p_menu_item->get_name_id() == NUM_transpose_label)
	{
		
		int val=p_menu_item->getValue();
		menu_transpose.setValue(val);
		value_TRANSPOSE=val;

		val=val-6;
		name=(String)val;
		
		
		
		for(int x=name.length();x<3;x++)
		{
			name+=' ';
		}
		set_mode_color(mode);
		myGLCD.print(name, x, y,0);
		
		
		return;
		//set_mode_color(ACTION_CLEAR_COLOR);
		//myGLCD.print(TRANSPOSE_LABEL_TEXT_old, x, y, 0);
		//set_mode_color(mode);
		//myGLCD.print(TRANSPOSE_LABEL_TEXT, x, y, 0);
		//

	}
	else
	if (p_menu_item->get_name_id() == NUM_REVERB_VALUE)
	{
		int val=p_menu_item->getValue();
		EEPROM.update(p_menu_item->getMemAddress(),val);
		name=(String)val;
		name+='%';
		
		for(int x=name.length();x<4;x++)
		{
			name+=' ';
		}
		
		set_mode_color(mode);
		myGLCD.print(name, x, y,0);
		
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_REVERB), 0x33);
		MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_REVERB_II), 0x33);
		
		
		return;
		
		set_mode_color(ACTION_CLEAR_COLOR);
		myGLCD.print((String)value, x, y, 0);
		set_mode_color(mode);
		myGLCD.print((String)value, x, y, 0);


	}
	else if (p_menu_item->get_name_id() == NUM_Z_LABEL)
	{
		byte tmp_color[3];
		set_mode_color(mode);
		myGLCD.setFont(arial_bold);
		//if(COMBINATION_LABEL_Z_letter_old.length()>COMBINATION_LABEL_Z_letter.length())
		//{
		//set_mode_color(ACTION_CLEAR_COLOR);
		//myGLCD.print(COMBINATION_LABEL_Z_letter_old, x, y, 0);
		//}
		
		//if (mode == ACTION_CLEAR_COLOR)
		//return;
		//if (COMBINATION_LABEL_Z_letter=="Z on")
		//myGLCD.setColor(0, 255, 0);
		//else
		//myGLCD.setColor(255, 128, 0);
		switch (USER_ID)
		{
			case 0:
			myGLCD.print(F("ORGANIST: 1 "), x, y, 0);
			break;
			
			case 1:
			myGLCD.print(F("ORGANIST: 2 "), x, y, 0);
			break;
			
			case 2:
			myGLCD.print(F("ORGANIST: 3 "), x, y, 0);
			break;
			
			case 3:
			myGLCD.print(F("ORGANIST: 4 "), x, y, 0);
			break;
			
			case 4:
			myGLCD.print(F("ORGANIST: 5 "), x, y, 0);
			break;
			
			case 5:
			myGLCD.print(F("ORGANIST: 6 "), x, y, 0);
			break;
			
			case 6:
			myGLCD.print(F("ORGANIST: 7 "), x, y, 0);
			break;
			
			case 7:
			myGLCD.print(F("ORGANIST: 8 "), x, y, 0);
			break;
			
			case 8:
			myGLCD.print(F("ORGANIST: 9 "), x, y, 0);
			break;
			
			case 9:
			myGLCD.print(F("ORGANIST: 10"), x, y, 0);
			break;
			
			case 10:
			myGLCD.print(F("ORGANIST: 11"), x, y, 0);
			break;
			
			case 11:
			myGLCD.print(F("ORGANIST: 12"), x, y, 0);
			break;
			
			default:
			myGLCD.print(F("NONE"), x, y, 0);
		}
		
		
	}
	else if (p_menu_item->get_name_id() == NUM_VOL_label)
	{
		set_mode_color(mode);
		myGLCD.print(name, x, y,90);
	}
	else{
		set_mode_color(mode);
		myGLCD.print(name, x, y,0);
	}

}

void drawBigLabel(MenuItem* p_menu_item, int value, byte mode)
{
	
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	x += zeroX;
	//	myGLCD.setFont(SixteenSegment);
	//Serial.println("pride not");

	String name = p_menu_item->get_name();

	//myGLCD.setFont(SevenSegNumFontPlus);

	myGLCD.setFont(GroteskBold24x48);

	if (COMBINATION_LABEL_FIRST_letter_old.length() > COMBINATION_LABEL_FIRST_letter.length())
	{
		for(byte x=COMBINATION_LABEL_FIRST_letter.length();x<COMBINATION_LABEL_FIRST_letter_old.length();x++)
		{
			COMBINATION_LABEL_FIRST_letter+=' ';
		}
	}

	set_mode_color(mode);
	myGLCD.print(COMBINATION_LABEL_FIRST_letter, x + 10, y, 0);


}

void drawSlider(MenuItem* p_menu_item, int value, byte mode)
{

	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	String name = p_menu_item->get_name();



	int min = 0;
	int max = 127;


	int heigth = 225;
	

	if (p_menu_item->get_name_id() == NUM_cr_ped)
	{
		//return;
		value = p_menu_item->getValue();
		
		if (value > 127)
		value = 127;
		heigth = 100;
		max = 127;
		
		value = map(value, 0, 127, 0, heigth);
		//Serial.print("CR");
		
	}
	else if (p_menu_item->get_name_id() == NUM_exp_ped)
	{
		//return;
		/*DEBUG_println(GAS_PED_1);
		DEBUG_println(GAS_PED_2);*/
		value = p_menu_item->getValue();
		if (value > 127)
		value = 127;
		heigth = 100;
		max = 127;
		
		value = map(value, 0, 127, 0, heigth);
		//Serial.print("EXP ");
		//Serial.print(GAS_PED_1);
		//Serial.print(" ");
		//Serial.println(value);
	}
	else
	{
		value = p_menu_item->getValue();
		value = map(value, 0, 127, 0, heigth);
	}
	

	x += zeroX;
	x += 270;




	myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	//myGLCD.fillRoundRect(zeroX + x, y, zeroX + x + 15, y + 140);
	myGLCD.fillRect(x + 1, y, x + 7, y + heigth - value - 1);



	//myGLCD.setColor(line_color[0], line_color[1], line_color[2]);

	set_mode_color(mode);


	myGLCD.fillRect(x + 1, y + heigth - value, x + 7, y + heigth);


	//myGLCD.fillRoundRect(zeroX + x, y+value, zeroX + x + 15, y +140);


	myGLCD.drawRect(x, y - 1, x + 8, y + heigth + 1);
	//myGLCD.drawRoundRect(x, y, x + 8, y + heigth); org

	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	//myGLCD.print(label_1, x +10, y + heigth , 270);

	//Serial.println("volume");
	//Serial.println(value);

	//TODO: preveri touch
	//isTouched = 0;
}

void drawSlider_H(MenuItem* p_menu_item, int value, byte mode)
{
	//Serial.println("vol change");
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	String name = p_menu_item->get_name();
	value = p_menu_item->getValue();

	int min = 0;
	int max = 127;


	int heigth = 127;
	x += zeroX;
	//value = MASTER_VOLUME;
	value = map(value, 0, 127, 0, heigth);


	//myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	set_mode_color(mode);
	//myGLCD.fillRoundRect(zeroX + x, y, zeroX + x + 15, y + 140);
	myGLCD.fillRect(x, y, x + heigth - value-1, y + 6);


	myGLCD.drawRect(x - 1, y-1, x + heigth+1, y + 7);

	//myGLCD.setColor(line_color[0], line_color[1], line_color[2]);

	myGLCD.setColor(back_color[0], back_color[1], back_color[2]);


	myGLCD.fillRect(x + heigth - value, y, x + heigth, y + 6);



	//myGLCD.drawRoundRect(zeroX + x, y, zeroX + x+ 15, y + 140);
	//myGLCD.drawRoundRect(x, y, x + 8, y + heigth);

	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	//myGLCD.print(label_1, x +10, y + heigth , 270);

	//Serial.println("volume");
	//Serial.println(value);

	//TODO: preveri touch
	//isTouched = 0;
}

void menu_mgr::draw_text_string(String text,int x,int y,bool visible)
{
	x += zeroX + 200;//zamik 4 crke - 4*16
	myGLCD.setFont(arial_bold);
	if(visible==false)
	set_mode_color(ACTION_CLEAR_COLOR);
	else
	set_mode_color(ACTION_REDRAW_COLOR);
	
	myGLCD.print(text, x, y - 4);
	
}

void drawBooleanLabel(MenuItem* p_menu_item, int value, byte mode)
{
	//if (p_menu_item->get_name() == H_transpose)
	//{
	//	TRANSPOSE_LABEL_TEXT = (String)(EEPROM.read(add_VALUE_TRANSPOSE)-100);
	//}

	myGLCD.setFont(arial_normal);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	String name = p_menu_item->get_name();

	int min = 0;
	int max = 127;

	value = p_menu_item->getValue();

	//Serial.println("drawSlider single label");

	int width = 40;
	int map_value = map(value, min, max, 0, width);


	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX + 200;//zamik 4 crke - 4*16
	map_value += 1;//da ne gre èez zaèetek kvadrata
	//Serial.println(value);

	myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	//myGLCD.fillRect(x, y + 1, x + map_value - 1, y + 7);//kvadrat za brisanje prejšnje slike
	//myGLCD.fillRect(x + map_value + px + 1, y + 1, x + width, y + 7);//kvadrat za brisanje prejšnje slike

	set_mode_color(mode);

	myGLCD.drawRoundRect(x , y-5, x + width + 30, y + 15);//okvir

	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	
	if(mode==ACTION_REDRAW_COLOR||mode==ACTION_CLEAR_COLOR||mode==ACTION_FIRST_DRAW)
	{
		if(mode==ACTION_FIRST_DRAW)
		set_mode_color(ACTION_REDRAW_COLOR);
		
		myGLCD.print(name, x - 200, y - 4);
	}





	//myGLCD.print(label_2, x + width + 10, y - 4);
	String intToString = String(value);

	String sValue = "   ";
	if(value==1)
	intToString="ON ";
	else if(value==0)
	intToString="OFF";
	else
	{
		p_menu_item->setValue(0);
		p_menu_item->saveValueEEPROM();
	}
	
	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = intToString[x];
	}
	myGLCD.setFont(hallfetica_normal);
	myGLCD.print(sValue, x + 15, y - 4);

}


void drawSlider_type_BASIC_value_label(MenuItem* p_menu_item, int value, byte mode)
{
	//if (p_menu_item->get_name() == H_transpose)
	//{
	//	TRANSPOSE_LABEL_TEXT = (String)(EEPROM.read(add_VALUE_TRANSPOSE)-100);
	//}

	myGLCD.setFont(arial_normal);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	String name = p_menu_item->get_name();

	int min = 0;
	int max = 127;

	value = p_menu_item->getValue();

	//Serial.println("drawSlider single label");

	int width = 40;
	int map_value = map(value, min, max, 0, width);


	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX + 200;//zamik 4 crke - 4*16
	map_value += 1;//da ne gre èez zaèetek kvadrata
	//Serial.println(value);

	myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.fillRect(x, y + 1, x + map_value - 1, y + 7);//kvadrat za brisanje prejšnje slike
	myGLCD.fillRect(x + map_value + px + 1, y + 1, x + width, y + 7);//kvadrat za brisanje prejšnje slike

	set_mode_color(mode);

	myGLCD.fillRect(x + map_value, y + 1, x + map_value + px, y + 7);//sredinski kvadrat

	myGLCD.drawRoundRect(x - 2, y, x + width + 2, y + 8);//okvir

	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	
	if(mode==ACTION_REDRAW_COLOR||mode==ACTION_CLEAR_COLOR||mode==ACTION_FIRST_DRAW)
	{
		if(mode==ACTION_FIRST_DRAW)
		set_mode_color(ACTION_REDRAW_COLOR);
		
		myGLCD.print(name, x - 200, y - 4);
	}





	//myGLCD.print(label_2, x + width + 10, y - 4);

	String sValue = "    ";
	String intToString = String(value);

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = intToString[x];
	}
	myGLCD.setFont(hallfetica_normal);
	myGLCD.print(sValue, x + width + 15, y - 4);

}

void drawSlider_negative_single_label(MenuItem* p_menu_item, int value, byte mode)
{
	value = p_menu_item->getValue();

	if (p_menu_item->get_name_id() == NUM_transpose)
	{
		DEBUG_STRING_println("transposeeee");
		//TRANSPOSE_LABEL_TEXT = (String)((int)EEPROM.read(add_VALUE_TRANSPOSE)-TRANS_adjust);
		int val=p_menu_item->getValue();
		menu_main_screen1_zecer_label_TRANSPOSE.setValue(val);
		
		String name = (String)(p_menu_item->getValue() - TRANS_adjust);
		
		
		String sValue = "  ";

		for (int x = 0; x < name.length(); x++)//TODO:temp fix, uporabi kazalce
		{
			sValue[x] = name[x];
		}


		//myGLCD.setFont(OCR_A_Extended_M);
		myGLCD.setFont(arial_bold);
		int x = p_menu_item->get_x();
		int y = p_menu_item->get_y();


		int min = -127;
		int max = 127;

		

		int px = 4;
		y += 4;//poravnava sliderja na sredino èrke
		x += zeroX;//zamik 4 crke - 4*16

		set_mode_color(mode);
		//myGLCD.setFont(Sinclair_M);
		myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);

		
		//myGLCD.print(sValue, x, y + 30);
		myGLCD.setFont(GroteskBold24x48);
		myGLCD.print(sValue, x + 140, 100);
		
		if(mode==ACTION_REDRAW_COLOR||mode==ACTION_CLEAR_COLOR||mode==ACTION_FIRST_DRAW)
		{
			if(mode==ACTION_FIRST_DRAW)
			set_mode_color(ACTION_REDRAW_COLOR);
			
			//myGLCD.setFont(OCR_A_Extended_M);
			myGLCD.setFont(arial_bold);
			myGLCD.print(F("TRANSPOSE"), x+90, y+30);
		}
		
		return;
		
		
	}
	if (p_menu_item->get_name_id() == NUM_master_level || p_menu_item->get_name_id() == NUM_master_level)
	{
		//REVERB_LABEL_TEXT = (String)((int)EEPROM.read(add_VALUE_REVERB));
		value = p_menu_item->getValue();
	}

	
	//myGLCD.setFont(OCR_A_Extended_M);
	myGLCD.setFont(arial_bold);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	String name = p_menu_item->get_name();

	int min = -127;
	int max = 127;

	

	//Serial.println("drawSlider single label");



	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX + 200;//zamik 4 crke - 4*16

	//Serial.println(value);

	//myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	//myGLCD.fillRect(x, y + 1, x + map_value - 1, y + 7);//kvadrat za brisanje prejšnje slike
	//myGLCD.fillRect(x + map_value + px + 1, y + 1, x + width, y + 7);//kvadrat za brisanje prejšnje slike

	set_mode_color(mode);
	//myGLCD.setFont(Sinclair_M);
	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.print(name, x - 200, y);




	//myGLCD.print(label_2, x + width + 10, y - 4);

	String sValue = "    ";
	String intToString = String(value);

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = intToString[x];
	}
	//	myGLCD.setFont(arial_normal);
	if (p_menu_item->get_name_id() == NUM_REVERB_VALUE)
	{
		myGLCD.print(sValue, x + 50, y);
	}else
	myGLCD.print(sValue, x+50, y);
}

void drawSlider_stop_label(MenuItem* p_menu_item,  int value, byte mode)
{
	myGLCD.setFont(arial_normal);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	String name = p_menu_item->get_name();


	int min = 0;
	int max = 127;

	value = p_menu_item->getValue();
	//Serial.println("drawSlider stop label");

	int width = 60;
	int map_value = map(value, min, max, 0, width);


	int px = 8;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX + 170;//zamik 4 crke - 4*16 //pusti
	map_value += 1;//da ne gre èez zaèetek kvadrata
	//Serial.println(value);

	myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.fillRect(x, y + 1 + 30, x + map_value - 1 + 30, y + 7);//kvadrat za brisanje prejšnje slike
	myGLCD.fillRect(x + map_value + px + 1 + 30, y + 1, x + width + 30, y + 7);//kvadrat za brisanje prejšnje slike

	set_mode_color(mode);

	myGLCD.fillRect(x + map_value + 30, y + 1, x + map_value + px + 30, y + 7);//sredinski kvadrat

	myGLCD.drawRoundRect(x - 2 + 30, y, x + width + 2 + 30, y + 8);//okvir

	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.print(name, x - 176, y - 4);

	String sValue = "    ";
	String intToString = String(value);

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = intToString[x];
	}
	myGLCD.setFont(hallfetica_normal);
	myGLCD.print(sValue, x + width + 50, y - 4);


	//TODO: preveri touch
	//isTouched = 0;
}

void drawRGBselector(MenuItem* p_menu_item, byte mode)
{
	int value;
	myGLCD.setFont(arial_normal);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	String name = p_menu_item->get_name();

	int min = 0;
	int max = 127;

	value = p_menu_item->getValue();
	p_menu_item->saveValueEEPROM();
	if(value>=127)
	value=127;

	//Serial.println("drawSlider single label");

	int width = 40;
	int map_value = map(value, min, max, 0, width);


	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX + 200;//zamik 4 crke - 4*16
	//map_value += 1;//da ne gre èez zaèetek kvadrata
	//Serial.println(value);

	if(p_menu_item->get_name_id()==NUM_reverb_type_||p_menu_item->get_name_id()==NUM_reverb_type_II)
	{
		set_mode_color(mode);
		String name1 = p_menu_item->get_name();
		int value = p_menu_item->getValue();

		switch (value)
		{
			case 0:
			name1 = "1 ROOM1    ";
			break;
			case 1:
			name1 = "2 ROOM2    ";
			break;
			case 2:
			name1 = "3 ROOM3    ";
			break;
			case 3:
			name1 = "4 HALL     ";
			break;
			case 4:
			name1 = "5 HALL2    ";
			break;;
			case 5:
			name1 = "6 PLATE    ";
			break;
			case 6:
			name1 = "7 DELAY    ";
			break;
			case 7:
			name1 = "8 DELAY2   ";
			break;
			default:
			name1 = "NULL     ";
			break;
		}
		myGLCD.print(name, x - 200, y - 4);
		
		myGLCD.print(name1, 270, y - 4);
		return;
	}

	myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.fillRect(x, y + 1, x + map_value - 1, y + 7);//kvadrat za brisanje prejšnje slike
	myGLCD.fillRect(x + map_value  + 1, y + 1, x + width, y + 7);//kvadrat za brisanje prejšnje slike

	set_mode_color(mode);

	myGLCD.fillRect(x + map_value, y + 1, x + map_value , y + 7);//sredinski kvadrat

	myGLCD.drawRoundRect(x - 2, y, x + width + 2, y + 8);//okvir

	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.print(name, x - 200, y - 4);




	//myGLCD.print(label_2, x + width + 10, y - 4);

	String sValue = "    ";
	String intToString = String(value);

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = intToString[x];
	}
	myGLCD.setFont(hallfetica_normal);
	myGLCD.print(sValue, x + width + 15, y - 4);



	//TODO: preveri touch
	//isTouched = 0;
}

int prev_MANUAL_1_lvl=EEPROM.read(ADD_menu_b1_man_I_lvl);
int prev_MANUAL_2_lvl=0;
int prev_MANUAL_ped_lvl=0;
void drawCustomValueSlider(MenuItem* p_menu_item, byte mode)
{
	myGLCD.setFont(arial_normal);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	String name = p_menu_item->get_name();

	int min = p_menu_item->get_min_display_val();
	int max =  p_menu_item->get_max_display_val();

	int value = p_menu_item->getValue();
	
	if(value>=max)
	value=max;
	if(value<=min)
	value=min;
	


	//Serial.println("drawSlider single label");

	int width = 40;
	int map_value = map(value, min, max, 0, width);
	

	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX + 200;//zamik 4 crke - 4*16
	//map_value += 1;//da ne gre èez zaèetek kvadrata
	//Serial.println(value);


	myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.fillRect(x, y + 1, x + map_value - 1, y + 7);//kvadrat za brisanje prejšnje slike
	myGLCD.fillRect(x + map_value  + 1, y + 1, x + width, y + 7);//kvadrat za brisanje prejšnje slike

	set_mode_color(mode);

	myGLCD.fillRect(x + map_value, y + 1, x + map_value , y + 7);//sredinski kvadrat

	myGLCD.drawRoundRect(x - 2, y, x + width + 2, y + 8);//okvir

	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.print(name, x - 200, y - 4);




	//myGLCD.print(label_2, x + width + 10, y - 4);

	String sValue = "    ";
	String intToString = String(value)+"%";

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = intToString[x];
	}
	myGLCD.setFont(hallfetica_normal);
	myGLCD.print(sValue, x + width+10, y - 4);
	byte tmp_var=0;

	DEBUG_println(p_menu_item->get_name_id());
	if(p_menu_item->get_name_id()==NUM_MAN_I_LVL)
	{
		
		for(int x=0;x<42;x++)
		{
			if(STOP_mgr.id(x)->get_active_on_manual()==MANUAL_1)
			{
				double calc_var=(double)EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2)*(double)value/100;
				tmp_var=calc_var;
				
				DEBUG_STRING_print("VALUE ");
				DEBUG_print(EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2));
				DEBUG_STRING_print(" calc VALUE: ");
				DEBUG_println(tmp_var);
				//EEPROM.write(STOPS_START_ADDRESSES+(x*5)+2,tmp_var);
				
				byte midi_ch=	STOP_mgr.id(x)->get_MIDI_CH();
				byte midi_out=	STOP_mgr.id(x)->get_MIDI_out_numb();
				MIDI_sender.send_MIDI_code(CODE_STOP_VOL,tmp_var,midi_ch,midi_out);
				
				
			}
		}
		
		
	}
	
	if(p_menu_item->get_name_id()==NUM_MAN_II_LVL)
	{
		for(int x=0;x<42;x++)
		{
			if(STOP_mgr.id(x)->get_active_on_manual()==MANUAL_2)
			{
				double calc_var=(double)EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2)*(double)value/100;
				tmp_var=calc_var;
				
				DEBUG_STRING_print("VALUE ");
				DEBUG_print(EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2));
				DEBUG_STRING_print(" calc VALUE: ");
				DEBUG_println(tmp_var);
				//EEPROM.write(STOPS_START_ADDRESSES+(x*5)+2,tmp_var);
				
				byte midi_ch=	STOP_mgr.id(x)->get_MIDI_CH();
				byte midi_out=	STOP_mgr.id(x)->get_MIDI_out_numb();
				MIDI_sender.send_MIDI_code(CODE_STOP_VOL,tmp_var,midi_ch,midi_out);
				
				
			}
		}
	}
	if(p_menu_item->get_name_id()==NUM_MAN_PED_LVL)
	{
		for(int x=0;x<42;x++)
		{
			if(STOP_mgr.id(x)->get_active_on_manual()==PEDAL)
			{
				double calc_var=(double)EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2)*(double)value/100;
				tmp_var=calc_var;
				
				DEBUG_STRING_print("VALUE ");
				DEBUG_print(EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2));
				DEBUG_STRING_print(" calc VALUE: ");
				DEBUG_println(tmp_var);
				//EEPROM.write(STOPS_START_ADDRESSES+(x*5)+2,tmp_var);
				
				byte midi_ch=	STOP_mgr.id(x)->get_MIDI_CH();
				byte midi_out=	STOP_mgr.id(x)->get_MIDI_out_numb();
				MIDI_sender.send_MIDI_code(CODE_STOP_VOL,tmp_var,midi_ch,midi_out);
				
				
			}
		}
	}

}
void drawCustomValueSlider_backup(MenuItem* p_menu_item, byte mode)
{
	myGLCD.setFont(arial_normal);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	String name = p_menu_item->get_name();

	int min = p_menu_item->get_min_display_val();
	int max =  p_menu_item->get_max_display_val();

	int value = p_menu_item->getValue();
	
	if(value>=max)
	value=max;
	if(value<=min)
	value=min;
	


	//Serial.println("drawSlider single label");

	int width = 40;
	int map_value = map(value, min, max, 0, width);
	

	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX + 200;//zamik 4 crke - 4*16
	//map_value += 1;//da ne gre èez zaèetek kvadrata
	//Serial.println(value);


	myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.fillRect(x, y + 1, x + map_value - 1, y + 7);//kvadrat za brisanje prejšnje slike
	myGLCD.fillRect(x + map_value  + 1, y + 1, x + width, y + 7);//kvadrat za brisanje prejšnje slike

	set_mode_color(mode);

	myGLCD.fillRect(x + map_value, y + 1, x + map_value , y + 7);//sredinski kvadrat

	myGLCD.drawRoundRect(x - 2, y, x + width + 2, y + 8);//okvir

	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.print(name, x - 200, y - 4);




	//myGLCD.print(label_2, x + width + 10, y - 4);

	String sValue = "    ";
	String intToString = String(value-127);

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = intToString[x];
	}
	myGLCD.setFont(hallfetica_normal);
	myGLCD.print(sValue, x + width + 15, y - 4);
	byte tmp_var=0;

	DEBUG_println(p_menu_item->get_name_id());
	if(p_menu_item->get_name_id()==NUM_MAN_I_LVL)
	{
		int tmp9=value;
		tmp9-=127;

		
		int diff=prev_MANUAL_1_lvl-tmp9;
		prev_MANUAL_1_lvl=(int)value-127;
		
		
		
		bool limit_max=false;
		bool limit_min=false;
		for(int x=0;x<42;x++)
		{
			if(STOP_mgr.id(x)->get_active_on_manual()==MANUAL_1)
			{
				if(((int)EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2)-diff)>126)
				{
					limit_max=true;
				}
				if(((int)EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2)-diff)<=2)
				{
					limit_min=true;
				}
			}
		}
		
		if(limit_max==false&&limit_min==false)
		{
			
			
			for(int x=0;x<42;x++)
			{
				if(STOP_mgr.id(x)->get_active_on_manual()==MANUAL_1)
				{

					tmp_var=(int)EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2)-diff;
					EEPROM.write(STOPS_START_ADDRESSES+(x*5)+2,tmp_var);
					DEBUG_println(EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2));
					
					byte midi_ch=	STOP_mgr.id(x)->get_MIDI_CH();
					byte midi_out=	STOP_mgr.id(x)->get_MIDI_out_numb();
					MIDI_sender.send_MIDI_code(CODE_STOP_VOL,tmp_var,midi_ch,midi_out);
					
					
				}
			}
		}
		else
		{
			myGLCD.setFont(mykefont2);
			myGLCD.print(F("limit"), x + width + 15+60, y - 4);
		}
		myGLCD.setFont(mykefont2);
		myGLCD.print(F("limit"), x + width + 15+60, y - 4);
		
	}
	
	if(p_menu_item->get_name_id()==NUM_MAN_II_LVL)
	{
		int tmp9=value;
		tmp9-=127;
		
		int diff=prev_MANUAL_1_lvl-tmp9;
		prev_MANUAL_1_lvl=(int)value-127;
		

		
		bool limit_max=false;
		bool limit_min=false;
		for(int x=0;x<42;x++)
		{
			if(STOP_mgr.id(x)->get_active_on_manual()==MANUAL_2)
			{
				if(((int)EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2)-diff)>126)
				{
					limit_max=true;
				}
				if(((int)EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2)-diff)<=2)
				{
					limit_min=true;
				}
			}
		}
		
		if(limit_max==false&&limit_min==false)
		{

			
			for(int x=0;x<42;x++)
			{
				if(STOP_mgr.id(x)->get_active_on_manual()==MANUAL_2)
				{

					tmp_var=(int)EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2)-diff;
					EEPROM.write(STOPS_START_ADDRESSES+(x*5)+2,tmp_var);
					DEBUG_println(EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2));
					
					byte midi_ch=	STOP_mgr.id(x)->get_MIDI_CH();
					byte midi_out=	STOP_mgr.id(x)->get_MIDI_out_numb();
					MIDI_sender.send_MIDI_code(CODE_STOP_VOL,tmp_var,midi_ch,midi_out);
					
					
				}
			}
		}
		
		
		
		
	}
	if(p_menu_item->get_name_id()==NUM_MAN_PED_LVL)
	{
		int tmp9=value;
		tmp9-=127;

		
		int diff=prev_MANUAL_1_lvl-tmp9;
		prev_MANUAL_1_lvl=(int)value-127;
		

		
		bool limit_max=false;
		bool limit_min=false;
		for(int x=0;x<42;x++)
		{
			if(STOP_mgr.id(x)->get_active_on_manual()==PEDAL)
			{
				if(((int)EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2)-diff)>126)
				{
					limit_max=true;
				}
				if(((int)EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2)-diff)<=2)
				{
					limit_min=true;
				}
			}
		}
		
		if(limit_max==false&&limit_min==false)
		{

			for(int x=0;x<42;x++)
			{
				if(STOP_mgr.id(x)->get_active_on_manual()==PEDAL)
				{

					tmp_var=(int)EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2)-diff;
					EEPROM.write(STOPS_START_ADDRESSES+(x*5)+2,tmp_var);
					DEBUG_println(EEPROM.read(STOPS_START_ADDRESSES+(x*5)+2));
					
					byte midi_ch=	STOP_mgr.id(x)->get_MIDI_CH();
					byte midi_out=	STOP_mgr.id(x)->get_MIDI_out_numb();
					MIDI_sender.send_MIDI_code(CODE_STOP_VOL,tmp_var,midi_ch,midi_out);
				}
			}
		}
	}

}
void drawSlider_double_label(MenuItem* p_menu_item,int value, byte mode)
{
	myGLCD.setFont(arial_normal);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	String name = p_menu_item->get_name();

	int min = 0;
	int max = 127;

	value = p_menu_item->getValue();
	
	if(value>=127)
	value=127;

	//Serial.println("drawSlider single label");

	int width = 40;
	int map_value = map(value, min, max, 0, width);


	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX + 200;//zamik 4 crke - 4*16
	//map_value += 1;//da ne gre èez zaèetek kvadrata
	//Serial.println(value);

	if(p_menu_item->get_name_id()==NUM_reverb_type_||p_menu_item->get_name_id()==NUM_reverb_type_II)
	{
		set_mode_color(mode);
		String name1 = p_menu_item->get_name();
		int value = p_menu_item->getValue();

		switch (value)
		{
			case 0:
			name1 = "1 ROOM1    ";
			break;
			case 1:
			name1 = "2 ROOM2    ";
			break;
			case 2:
			name1 = "3 ROOM3    ";
			break;
			case 3:
			name1 = "4 HALL     ";
			break;
			case 4:
			name1 = "5 HALL2    ";
			break;;
			case 5:
			name1 = "6 PLATE    ";
			break;
			case 6:
			name1 = "7 DELAY    ";
			break;
			case 7:
			name1 = "8 DELAY2   ";
			break;
			default:
			name1 = "NULL     ";
			break;
		}
		myGLCD.print(name, x - 200, y - 4);
		
		myGLCD.print(name1, 270, y - 4);
		return;
	}
	
	if(p_menu_item->get_name_id()==NUM_LEFT)
	{
		map_value = map(value, min, max, 0, width);
		int temp_val =map(value, 0, 127, -50, 50);
		//temp_val = 1000+temp_val*(double)5700 / 127;

		//name = String(temp_val);

		String sValue = "       ";
		String intToString = String(name);

		for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
		{
			if (x>6)
			break;
			sValue[x] = intToString[x];
		}
		byte offset=30;
		myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
		myGLCD.fillRect(x-offset, y + 1, x + map_value - 1-offset, y + 7);//kvadrat za brisanje prejšnje slike
		myGLCD.fillRect(x-offset + map_value  + 1, y + 1, x + width-offset, y + 7);//kvadrat za brisanje prejšnje slike

		set_mode_color(mode);

		myGLCD.fillRect(x-offset + map_value, y + 1, x + map_value -offset, y + 7);//sredinski kvadrat

		myGLCD.drawRoundRect(x - 2-offset, y, x + width + 2-offset, y + 8);//okvir

		myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
		myGLCD.print(name, x - 200, y - 4);
		
		name = String(temp_val);

		sValue = "    ";
		intToString = String(name)+"%";

		for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
		{
			if (x>4)
			break;
			sValue[x] = intToString[x];
		}
		
		myGLCD.setFont(hallfetica_normal);
		myGLCD.print(sValue, x + width, y - 4);
		myGLCD.print(F("R"), x+15, y - 4);
		myGLCD.print(F("L"), x-50, y - 4);
		myGLCD.setFont(Retro8x16);
		//myGLCD.print(F("% "), x + width+50, y-4);
		return;

	}
	
	if(p_menu_item->get_name_id()==NUM_LEVEL)
	{
		map_value = map(value, min, max, 0, width);
		int temp_val =value;
		//temp_val = 1000+temp_val*(double)5700 / 127;

		//name = String(temp_val);

		String sValue = "       ";
		String intToString = String(name);

		for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
		{
			if (x>6)
			break;
			sValue[x] = intToString[x];
		}
		byte offset=30;
		myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
		myGLCD.fillRect(x-offset, y + 1, x + map_value - 1-offset, y + 7);//kvadrat za brisanje prejšnje slike
		myGLCD.fillRect(x-offset + map_value  + 1, y + 1, x + width-offset, y + 7);//kvadrat za brisanje prejšnje slike

		set_mode_color(mode);

		myGLCD.fillRect(x-offset + map_value, y + 1, x + map_value -offset, y + 7);//sredinski kvadrat

		myGLCD.drawRoundRect(x - 2-offset, y, x + width + 2-offset, y + 8);//okvir

		myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
		myGLCD.print(name, x - 200, y - 4);
		
		name = String(temp_val);

		sValue = "    ";
		intToString = String(name)+"%";

		for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
		{
			if (x>4)
			break;
			sValue[x] = intToString[x];
		}
		
		myGLCD.setFont(hallfetica_normal);
		myGLCD.print(sValue, x + width, y - 4);

		return;

	}
	
	if(p_menu_item->get_name_id()==NUM_TVF_CUTOFF)
	{
		map_value = map(value, min, max, 0, width);
		int temp_val =map(value, 0, 127, 1320, 8000);
		//temp_val = 1000+temp_val*(double)5700 / 127;

		//name = String(temp_val);

		String sValue = "       ";
		String intToString = String(name);

		for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
		{
			if (x>6)
			break;
			sValue[x] = intToString[x];
		}
		byte offset=30;
		myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
		myGLCD.fillRect(x-offset, y + 1, x + map_value - 1-offset, y + 7);//kvadrat za brisanje prejšnje slike
		myGLCD.fillRect(x-offset + map_value  + 1, y + 1, x + width-offset, y + 7);//kvadrat za brisanje prejšnje slike

		set_mode_color(mode);

		myGLCD.fillRect(x-offset + map_value, y + 1, x + map_value -offset, y + 7);//sredinski kvadrat

		myGLCD.drawRoundRect(x - 2-offset, y, x + width + 2-offset, y + 8);//okvir

		myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
		myGLCD.print(name, x - 200, y - 4);
		
		name = String(temp_val);

		sValue = "    ";
		intToString = String(name);

		for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
		{
			if (x>4)
			break;
			sValue[x] = intToString[x];
		}
		
		myGLCD.setFont(hallfetica_normal);
		myGLCD.print(sValue, x + width-20, y - 4);
		myGLCD.setFont(Retro8x16);
		myGLCD.print(F("Hz"), x + width+50, y-4);
		return;

	}
	
	
	
	if(p_menu_item->get_name_id()==NUM_TVF_RESONANCE)
	{
		map_value = map(value, min, 20, 0, width);
		int temp_val =map(value, 0, 20, 0, 10);
		//temp_val = 1000+temp_val*(double)5700 / 127;

		//name = String(temp_val);

		String sValue = "       ";
		String intToString = String(name);

		for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
		{
			if (x>6)
			break;
			sValue[x] = intToString[x];
		}
		byte offset=30;
		myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
		myGLCD.fillRect(x-offset, y + 1, x + map_value - 1-offset, y + 7);//kvadrat za brisanje prejšnje slike
		myGLCD.fillRect(x-offset + map_value  + 1, y + 1, x + width-offset, y + 7);//kvadrat za brisanje prejšnje slike

		set_mode_color(mode);

		myGLCD.fillRect(x-offset + map_value, y + 1, x + map_value -offset, y + 7);//sredinski kvadrat

		myGLCD.drawRoundRect(x - 2-offset, y, x + width + 2-offset, y + 8);//okvir

		myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
		myGLCD.print(name, x - 200, y - 4);
		//
		//name = String(temp_val);
		//
		//sValue = "    ";
		//intToString = String(name);
		//
		//for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
		//{
		//if (x>4)
		//break;
		//sValue[x] = intToString[x];
		//}
		
		
		
		
		
		double tmp_val = p_menu_item->getValue();

		tmp_val = map(tmp_val,  0, 20,0, 120);
		//	tmp_val = -12 + ((double)24 / (double)127)*tmp_val;
		String val = String(tmp_val/10);



		//val = String(p_menu_item->getValue());
		//Serial.println(-12 + ((double)24 / (double)127)*tmp_val);
		//Serial.println(-12 + ((double)24 / (double)127)*tmp_val);

		//
		//myGLCD.print(F("+12dB"), x + 35, y);
		//myGLCD.print(F("GAIN"), x + 35, y + 30);
		//myGLCD.print(F("dB"), x + 35, y + 40);

		sValue = "     ";
		intToString = String(val);

		for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
		{
			if (tmp_val> -10 && x > 3)
			break;
			else if (tmp_val<-10 && x>4)
			break;//poreži decimalke
			sValue[x] = intToString[x];
		}

		
		myGLCD.setFont(hallfetica_normal);
		myGLCD.print(sValue, x + width-20, y - 4);
		myGLCD.setFont(Retro8x16);
		
		myGLCD.print(F("dB"), x + width+50, y-4);
		
		return;

	}
	

	myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	
	myGLCD.fillRect(x, y + 1, x + map_value - 1, y + 7);//kvadrat za brisanje prejšnje slike
	myGLCD.fillRect(x + map_value  + 1, y + 1, x + width, y + 7);//kvadrat za brisanje prejšnje slike

	set_mode_color(mode);

	myGLCD.fillRect(x + map_value, y + 1, x + map_value , y + 7);//sredinski kvadrat

	myGLCD.drawRoundRect(x - 2, y, x + width + 2, y + 8);//okvir

	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);

	if(mode==ACTION_REDRAW_COLOR||mode==ACTION_CLEAR_COLOR||mode==ACTION_FIRST_DRAW)
	{
		if(mode==ACTION_FIRST_DRAW)
		set_mode_color(ACTION_REDRAW_COLOR);
		
		myGLCD.print(name, x - 200, y - 4);
	}



	//myGLCD.print(label_2, x + width + 10, y - 4);

	String sValue = F("    ");
	String intToString = String(value);
	
	if(p_menu_item->get_name_id()==NUM_swap_keyboard)
	{
		if(map_value==0)
		{
			intToString=F("NORMAL  ");
		}
		else
		{
			intToString=F("INVERTED");
		}
	}

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = intToString[x];
	}
	myGLCD.setFont(hallfetica_normal);
	myGLCD.print(sValue, x + width + 15, y - 4);



	//TODO: preveri touch
	//isTouched = 0;
}

void drawSlider_tune_cents(MenuItem* p_menu_item,int value, byte mode)
{
	myGLCD.setFont(arial_bold);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	String name = p_menu_item->get_name();

	int min = 0;
	int max = 30;

	value = p_menu_item->getValue();
	
	if(value>=127)
	value=127;

	//Serial.println("drawSlider single label");

	int width = 40;
	int map_value = map(value, min, max, 0, width);


	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX + 200;//zamik 4 crke - 4*16
	//map_value += 1;//da ne gre èez zaèetek kvadrata
	//Serial.println(value);

	
	
	
	byte offset_=100;

	myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.fillRect(x-offset_, y + 1, x + map_value - 1-offset_, y + 7);//kvadrat za brisanje prejšnje slike
	myGLCD.fillRect(x + map_value  + 1-offset_, y + 1, x + width-offset_, y + 7);//kvadrat za brisanje prejšnje slike

	set_mode_color(mode);

	myGLCD.fillRect(x + map_value-offset_, y + 1, x + map_value-offset_ , y + 7);//sredinski kvadrat

	myGLCD.drawRoundRect(x - 2-offset_, y, x + width + 2-offset_, y + 8);//okvir

	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.print(name, x - 200, y - 4);




	//myGLCD.print(label_2, x + width + 10, y - 4);

	String sValue = "   ";
	String intToString = String(value+420);

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = intToString[x];
	}
	myGLCD.setFont(hallfetica_normal);
	myGLCD.print(sValue, x + width-30-50, y - 4);
	
	myGLCD.setFont(Retro8x16);
	myGLCD.print(F("Hz"), x + width+30-50, y - 4);

	HERTZ_SELECTED=value-20;
	MIDI_sender.tuning_send();

	//TODO: preveri touch
	//isTouched = 0;
}


void drawSelector(MenuItem* p_menu_item, int x, int y, String label_1, String label_2, int value, int min, int max, byte mode)
{
	myGLCD.setFont(arial_normal);
	value = p_menu_item->getValue();
	int width = 200;
	x += zeroX;
	int rec_x = 0;

	myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	//myGLCD.fillRect(x, y + 1 + 30, x + map_value - 1 + 30, y + 7);//kvadrat za brisanje prejšnje slike
	//myGLCD.fillRect(x + map_value + px + 1 + 30, y + 1, x + width + 30, y + 7);//kvadrat za brisanje prejšnje slike

	set_mode_color(mode);

	myGLCD.print(label_1, x, y);
	//myGLCD.print(value, x+rec_x, y);

	myGLCD.drawRoundRect(x + rec_x - 2, y - 1, x + rec_x+ width + 2, y + 17);//okvir


	
}

int get_new_mem_add(int parent_id,int NUM_ID)
{
	int add_eq_gain_low,add_eq_band_freq_low_800,add_eq_Q_low,add_eq_freq_2500,add_eq_gain_low_mid,add_eq_Q_low_mid,add_eq_freq_10700,add_eq_gain_high_mid,add_eq_Q_high_mid,add_eq_freq_5800,add_eq_gain_high,add_eq_Q_high;
	
	
	
	DEBUG_STRING_println("parent");
	DEBUG_println(ms._p_curr_menu->_menu_components[ms._p_curr_menu->_cur_menu_component_num]->get_name_id());
	
	//byte parent_id=ms._p_curr_menu->_menu_components[ms._p_curr_menu->_cur_menu_component_num]->get_name_id();
	
	switch(parent_id)
	{
		case NUM_MAN_I_EQU:
		add_eq_gain_low=   ADD_menu_b1_equalizer_gain_low ;
		add_eq_band_freq_low_800=  ADD_menu_b1_equalizer_band_freq_low_band_0_800 ;
		add_eq_Q_low=  ADD_menu_b1_equalizer_Q_low  ;
		add_eq_freq_2500=  ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500 ;
		add_eq_gain_low_mid=  ADD_menu_b1_equalizer_gain_low_mid  ;
		add_eq_Q_low_mid=  ADD_menu_b1_equalizer_Q_low_mid  ;
		add_eq_freq_10700=  ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700  ;
		add_eq_gain_high_mid=  ADD_menu_b1_equalizer_gain_high_mid  ;
		add_eq_Q_high_mid=  ADD_menu_b1_equalizer_Q_high_mid;
		add_eq_freq_5800=  ADD_menu_b1_equalizer_band_freq_high_band_1000_5800  ;
		add_eq_gain_high=  ADD_menu_b1_equalizer_gain_high  ;
		add_eq_Q_high=  ADD_menu_b1_equalizer_Q_high  ;

		break;
		
		case NUM_MAN_II_EQU:
		add_eq_gain_low=   ADD_menu_b1_equalizer_gain_low_II ;
		add_eq_band_freq_low_800=  ADD_menu_b1_equalizer_band_freq_low_band_0_800_II ;
		add_eq_Q_low=  ADD_menu_b1_equalizer_Q_low_II  ;
		add_eq_freq_2500=  ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_II ;
		add_eq_gain_low_mid=  ADD_menu_b1_equalizer_gain_low_mid_II  ;
		add_eq_Q_low_mid=  ADD_menu_b1_equalizer_Q_low_mid_II ;
		add_eq_freq_10700=  ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_II  ;
		add_eq_gain_high_mid=  ADD_menu_b1_equalizer_gain_high_mid_II  ;
		add_eq_Q_high_mid=  ADD_menu_b1_equalizer_Q_high_mid_II;
		add_eq_freq_5800=  ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_II  ;
		add_eq_gain_high=  ADD_menu_b1_equalizer_gain_high_II  ;
		add_eq_Q_high=  ADD_menu_b1_equalizer_Q_high_II  ;

		break;
		case NUM_MAN_I_EQU_HEADPHONES:
		add_eq_gain_low=   ADD_menu_b1_equalizer_gain_low_III ;
		add_eq_band_freq_low_800=  ADD_menu_b1_equalizer_band_freq_low_band_0_800_III ;
		add_eq_Q_low=  ADD_menu_b1_equalizer_Q_low_III  ;
		add_eq_freq_2500=  ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_III ;
		add_eq_gain_low_mid=  ADD_menu_b1_equalizer_gain_low_mid_III  ;
		add_eq_Q_low_mid=  ADD_menu_b1_equalizer_Q_low_mid_III ;
		add_eq_freq_10700=  ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III  ;
		add_eq_gain_high_mid=  ADD_menu_b1_equalizer_gain_high_mid_III  ;
		add_eq_Q_high_mid=  ADD_menu_b1_equalizer_Q_high_mid_III;
		add_eq_freq_5800=  ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_III  ;
		add_eq_gain_high=  ADD_menu_b1_equalizer_gain_high_III  ;
		add_eq_Q_high=  ADD_menu_b1_equalizer_Q_high_III  ;

		break;
		case NUM_MAN_II_EQU_HEADPHONES:
		add_eq_gain_low=   ADD_menu_b1_equalizer_gain_low_IV ;
		add_eq_band_freq_low_800=  ADD_menu_b1_equalizer_band_freq_low_band_0_800_IV ;
		add_eq_Q_low=  ADD_menu_b1_equalizer_Q_low_IV  ;
		add_eq_freq_2500=  ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_IV ;
		add_eq_gain_low_mid=  ADD_menu_b1_equalizer_gain_low_mid_IV  ;
		add_eq_Q_low_mid=  ADD_menu_b1_equalizer_Q_low_mid_IV ;
		add_eq_freq_10700=  ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_IV  ;
		add_eq_gain_high_mid=  ADD_menu_b1_equalizer_gain_high_mid_IV  ;
		add_eq_Q_high_mid=  ADD_menu_b1_equalizer_Q_high_mid_IV;
		add_eq_freq_5800=  ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_IV  ;
		add_eq_gain_high=  ADD_menu_b1_equalizer_gain_high_IV  ;
		add_eq_Q_high=  ADD_menu_b1_equalizer_Q_high_IV  ;

		break;
		
		default:
		//return;
		break;
	}
	
	switch(NUM_ID)
	{
		
		case NUM_GAIN_LOW	:
		return add_eq_gain_low;
		
		case  NUM_band_freq_low_band_0_800	:
		return add_eq_band_freq_low_800;
		
		case  NUM_gain_Q_low	:
		return add_eq_Q_low;
		
		case NUM_band_freq_low_mid_band_0_2500	:
		return add_eq_freq_2500;
		
		case  NUM_GAIN_LOW_MID	:
		return add_eq_gain_low_mid;
		
		//q low mid
		case NUM_equalizer_band_freq_high_mid_band_60_10700:
		return add_eq_freq_10700;
		
		case NUM_equalizer_gain_high_mid	:
		return add_eq_gain_high_mid;
		
		case NUM_equalizer_gain_high	:
		return add_eq_gain_high;
		
		
		case NUM_band_freq_high_band_1000_5800	:
		return add_eq_freq_5800;
		
		
		case NUM_gain_Q_high	:
		return add_eq_Q_high;

	}
}



void drawslider_equalizer_gain(MenuItem* p_menu_item, byte mode)
{
	
	if(mode==ACTION_FIRST_DRAW)
	{
		
		byte parent_id=ms._p_curr_menu->_menu_components[ms._p_curr_menu->_cur_menu_component_num]->get_name_id();
		DEBUG_STRING_println("FIRST DRAW");
		//p_menu_item->setMemAddress(  get_new_mem_add(parent_id,p_menu_item->get_name_id()));

		menu_b1_equalizer_gain_low.setMemAddress(get_new_mem_add(parent_id,NUM_GAIN_LOW));
		menu_b1_equalizer_band_freq_low_band_0_800.setMemAddress(get_new_mem_add(parent_id,NUM_band_freq_low_band_0_800));
		menu_b1_equalizer_gain_Q_low.setMemAddress(get_new_mem_add(parent_id,NUM_gain_Q_low));
		menu_b1_equalizer_gain_low_mid.setMemAddress(get_new_mem_add(parent_id,NUM_GAIN_LOW_MID));
		menu_b1_equalizer_band_freq_low_mid_band_0_2500.setMemAddress(get_new_mem_add(parent_id,NUM_band_freq_low_mid_band_0_2500));
		menu_b1_equalizer_gain_high_mid.setMemAddress(get_new_mem_add(parent_id,NUM_equalizer_gain_high_mid));
		menu_b1_equalizer_band_freq_high_mid_band_60_10700.setMemAddress(get_new_mem_add(parent_id,NUM_equalizer_band_freq_high_mid_band_60_10700));
		menu_b1_equalizer_gain_high.setMemAddress(get_new_mem_add(parent_id,NUM_equalizer_gain_high));
		menu_b1_equalizer_band_freq_high_band_1000_5800.setMemAddress(get_new_mem_add(parent_id,NUM_band_freq_high_band_1000_5800));
		menu_b1_equalizer_gain_Q_high.setMemAddress(get_new_mem_add(parent_id,NUM_gain_Q_high));
	}
	

	int value;

	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	String name = p_menu_item->get_name();

	/*Serial.println(x);
	Serial.println(y);*/

	int min = 0;
	int max = 127;


	int heigth = 150;


	
	value = p_menu_item->getValue();
	

	value = map(value, 0, 127, 0, heigth);
	
	//y = 10;
	//	x = 10;
	x += zeroX;





	myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
	//myGLCD.fillRoundRect(zeroX + x, y, zeroX + x + 15, y + 140);
	myGLCD.fillRect(x + 1, y , x + 27, y + heigth - value - 1);

	//myGLCD.setColor(line_color[0], line_color[1], line_color[2]);

	set_mode_color(mode);

	myGLCD.fillRect(x + 1, y + heigth - value, x + 27, y + heigth);


	//myGLCD.fillRoundRect(zeroX + x, y+value, zeroX + x + 15, y +140);


	myGLCD.drawRect(x, y - 1, x + 28, y + heigth + 1);
	
	//	Serial.println(p_menu_item->getValue());
	double tmp_val = p_menu_item->getValue();

	tmp_val = map(tmp_val,  0, 127,-120, 120);
	//	tmp_val = -12 + ((double)24 / (double)127)*tmp_val;
	String val = String(tmp_val/10);



	//val = String(p_menu_item->getValue());
	//Serial.println(-12 + ((double)24 / (double)127)*tmp_val);
	//Serial.println(-12 + ((double)24 / (double)127)*tmp_val);

	myGLCD.setFont(mykefont2);
	myGLCD.print(F("+12dB"), x + 35, y);
	myGLCD.print(F("GAIN"), x + 35, y + 30);
	myGLCD.print(F("dB"), x + 35, y + 40);

	String sValue = "     ";
	String intToString = String(val);

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		if (tmp_val> -10 && x > 3)
		break;
		else if (tmp_val<-10 && x>4)
		break;//poreži decimalke
		sValue[x] = intToString[x];
	}

	myGLCD.print(sValue, x + 35, y + 50);
	myGLCD.print(F("-12dB"), x + 35, y + heigth-15);
	
	//if(p_menu_item->getMemAddress()==NUM_GAIN_LOW_MID)
	//myGLCD.drawRoundRect(x - 1, y + heigth + 27, x + 59, y + heigth + 50);//kvadrat za q
	//
	//if(p_menu_item->get_name()==return_name(NUM_GAIN_LOW_MID))
	//myGLCD.drawRoundRect(x - 1, y + heigth + 27, x + 59, y + heigth + 50);//kvadrat za q
	////myGLCD.drawRoundRect(x, y, x + 8, y + heigth); org

	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);


	if (mode != ACTION_REDRAW_COLOR || mode == ACTION_REDRAW_COLOR)
	{
		
		set_mode_color(ACTION_REDRAW_COLOR);
		myGLCD.drawRoundRect(x - 1, y + heigth + 3, x + 59, y + heigth + 25);//kvadrat za freq
		if( p_menu_item->get_name_id()==NUM_equalizer_gain_high_mid||p_menu_item->get_name_id()==NUM_GAIN_LOW_MID)
		myGLCD.drawRoundRect(x - 1, y + heigth + 27, x + 59, y + heigth + 50);//kvadrat za q
		myGLCD.setFont(Retro8x16);
		myGLCD.print(name, x, 220);
	}

	if (mode == ACTION_CLEAR_COLOR)
	{

		set_mode_color(ACTION_CLEAR_COLOR);
		myGLCD.drawRoundRect(x - 1, y + heigth + 3, x + 59, y + heigth + 25);//kvadrat za freq
		if( p_menu_item->get_name_id()==NUM_equalizer_gain_high_mid||p_menu_item->get_name_id()==NUM_GAIN_LOW_MID)
		myGLCD.drawRoundRect(x - 1, y + heigth + 27, x + 59, y + heigth + 50);//kvadrat za q
		myGLCD.setFont(Retro8x16);
		myGLCD.print(name, x, 220);
	}
	
	
	//myGLCD.print(label_1, x +10, y + heigth , 270);

	//Serial.println("volume");
	//Serial.println(value);

	//TODO: preveri touch
	//isTouched = 0;

}

void drawslider_equalizer_freq(MenuItem* p_menu_item,  byte mode)
{
	


	
	//p_menu_item->MenuComponent
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	//int heigth = 225;
	y += 160;
	//x = 10;
	x += zeroX;
	//x += 270;
	String name = p_menu_item->get_name();

	int temp_val = p_menu_item->value;

	if ( p_menu_item->get_name_id() == NUM_band_freq_low_band_0_800)
	{
		temp_val =map(temp_val,  0, 127,0, 250);
		//temp_val = temp_val*(double)800 / 127;
	}
	else if (p_menu_item->get_name_id() == NUM_band_freq_low_mid_band_0_2500)
	{
		temp_val =map(temp_val,  0, 127,109, 1900);
		//temp_val = temp_val*(double)2500 / 127;
	}
	else if (p_menu_item->get_name_id() == NUM_equalizer_band_freq_high_mid_band_60_10700)
	{
		temp_val =map(temp_val,  0, 127,1000, 5000);
		//temp_val = 60+temp_val*(double)10640 / 127;
	}
	else if (p_menu_item->get_name_id() == NUM_band_freq_high_band_1000_5800)
	{
		temp_val =map(temp_val, 0, 127, 2500, 16000);
		//temp_val = 1000+temp_val*(double)5700 / 127;
	}

	name = String(temp_val);

	String sValue = "       ";
	String intToString = String(name);

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		if (x>6)
		break;
		sValue[x] = intToString[x];
	}

	set_mode_color(mode);
	myGLCD.setFont(Retro8x16);
	//myGLCD.print("FREQ", x+35, y-8);
	myGLCD.print(F("HZ"), x + 63, y-1);
	//myGLCD.setFont(arial_bold);


	myGLCD.print(sValue, x + 3, y-1);
}

void drawslider_equalizer_Q(MenuItem* p_menu_item, byte mode)
{

	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	//int heigth = 225;
	y += 170;
	//x = 10;
	x += zeroX;
	//x += 270;
	String name = p_menu_item->get_name();
	int ddd=8;
	double temp_val = p_menu_item->getValue();
	//p_menu_item->getValue();
	//temp_val =map(temp_val, 0, 127, 0.3, 1);
	

	if( p_menu_item->getMemAddress()== ADD_menu_b1_equalizer_select+9339)
	{
		
		if(temp_val<1)
		temp_val=1;
		
		if(temp_val>4)
		{
			p_menu_item->setValue(4);
			temp_val=4;
		}
		EEPROM.write(ADD_menu_b1_equalizer_select,temp_val);
		int add_eq_gain_low,add_eq_band_freq_low_800,add_eq_Q_low,add_eq_freq_2500,add_eq_gain_low_mid,add_eq_Q_low_mid,add_eq_freq_10700,add_eq_gain_high_mid,add_eq_Q_high_mid,add_eq_freq_5800,add_eq_gain_high,add_eq_Q_high;
		
		switch((int)temp_val)
		{
			case 1:
			add_eq_gain_low=   ADD_menu_b1_equalizer_gain_low ;
			add_eq_band_freq_low_800=  ADD_menu_b1_equalizer_band_freq_low_band_0_800 ;
			add_eq_Q_low=  ADD_menu_b1_equalizer_Q_low  ;
			add_eq_freq_2500=  ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500 ;
			add_eq_gain_low_mid=  ADD_menu_b1_equalizer_gain_low_mid  ;
			add_eq_Q_low_mid=  ADD_menu_b1_equalizer_Q_low_mid  ;
			add_eq_freq_10700=  ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700  ;
			add_eq_gain_high_mid=  ADD_menu_b1_equalizer_gain_high_mid  ;
			add_eq_Q_high_mid=  ADD_menu_b1_equalizer_Q_high_mid;
			add_eq_freq_5800=  ADD_menu_b1_equalizer_band_freq_high_band_1000_5800  ;
			add_eq_gain_high=  ADD_menu_b1_equalizer_gain_high  ;
			add_eq_Q_high=  ADD_menu_b1_equalizer_Q_high  ;
			ddd=1;
			break;
			
			case 2:
			add_eq_gain_low=   ADD_menu_b1_equalizer_gain_low_II ;
			add_eq_band_freq_low_800=  ADD_menu_b1_equalizer_band_freq_low_band_0_800_II ;
			add_eq_Q_low=  ADD_menu_b1_equalizer_Q_low_II  ;
			add_eq_freq_2500=  ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_II ;
			add_eq_gain_low_mid=  ADD_menu_b1_equalizer_gain_low_mid_II  ;
			add_eq_Q_low_mid=  ADD_menu_b1_equalizer_Q_low_mid_II ;
			add_eq_freq_10700=  ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_II  ;
			add_eq_gain_high_mid=  ADD_menu_b1_equalizer_gain_high_mid_II  ;
			add_eq_Q_high_mid=  ADD_menu_b1_equalizer_Q_high_mid_II;
			add_eq_freq_5800=  ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_II  ;
			add_eq_gain_high=  ADD_menu_b1_equalizer_gain_high_II  ;
			add_eq_Q_high=  ADD_menu_b1_equalizer_Q_high_II  ;
			ddd=2;
			break;
			case 3:
			add_eq_gain_low=   ADD_menu_b1_equalizer_gain_low_III ;
			add_eq_band_freq_low_800=  ADD_menu_b1_equalizer_band_freq_low_band_0_800_III ;
			add_eq_Q_low=  ADD_menu_b1_equalizer_Q_low_III  ;
			add_eq_freq_2500=  ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_III ;
			add_eq_gain_low_mid=  ADD_menu_b1_equalizer_gain_low_mid_III  ;
			add_eq_Q_low_mid=  ADD_menu_b1_equalizer_Q_low_mid_III ;
			add_eq_freq_10700=  ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III  ;
			add_eq_gain_high_mid=  ADD_menu_b1_equalizer_gain_high_mid_III  ;
			add_eq_Q_high_mid=  ADD_menu_b1_equalizer_Q_high_mid_III;
			add_eq_freq_5800=  ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_III  ;
			add_eq_gain_high=  ADD_menu_b1_equalizer_gain_high_III  ;
			add_eq_Q_high=  ADD_menu_b1_equalizer_Q_high_III  ;
			ddd=3;
			break;
			case 4:
			add_eq_gain_low=   ADD_menu_b1_equalizer_gain_low_IV ;
			add_eq_band_freq_low_800=  ADD_menu_b1_equalizer_band_freq_low_band_0_800_IV ;
			add_eq_Q_low=  ADD_menu_b1_equalizer_Q_low_IV  ;
			add_eq_freq_2500=  ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_IV ;
			add_eq_gain_low_mid=  ADD_menu_b1_equalizer_gain_low_mid_IV  ;
			add_eq_Q_low_mid=  ADD_menu_b1_equalizer_Q_low_mid_IV ;
			add_eq_freq_10700=  ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_IV  ;
			add_eq_gain_high_mid=  ADD_menu_b1_equalizer_gain_high_mid_IV  ;
			add_eq_Q_high_mid=  ADD_menu_b1_equalizer_Q_high_mid_IV;
			add_eq_freq_5800=  ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_IV  ;
			add_eq_gain_high=  ADD_menu_b1_equalizer_gain_high_IV  ;
			add_eq_Q_high=  ADD_menu_b1_equalizer_Q_high_IV  ;
			ddd=4;
			break;
			
			default:
			//return;
			break;
		}
		
		
		

		
		menu_b1_equalizer_gain_low.setMemAddress(add_eq_gain_low);
		menu_b1_equalizer_band_freq_low_band_0_800.setMemAddress(add_eq_band_freq_low_800);
		menu_b1_equalizer_gain_Q_low.setMemAddress(add_eq_Q_low);
		menu_b1_equalizer_gain_low_mid.setMemAddress(add_eq_gain_low_mid);
		menu_b1_equalizer_band_freq_low_mid_band_0_2500.setMemAddress(add_eq_freq_2500);
		menu_b1_equalizer_gain_high_mid.setMemAddress(add_eq_gain_high_mid);
		menu_b1_equalizer_band_freq_high_mid_band_60_10700.setMemAddress(add_eq_freq_10700);
		menu_b1_equalizer_gain_high.setMemAddress(add_eq_gain_high);
		menu_b1_equalizer_band_freq_high_band_1000_5800.setMemAddress(add_eq_freq_5800);
		menu_b1_equalizer_gain_Q_high.setMemAddress(add_eq_Q_high);

		if(mode!=ACTION_CLEAR_COLOR)
		{
			
			menu_b1_equalizer_gain_low.setValue(EEPROM.read(menu_b1_equalizer_gain_low.getMemAddress()));
			menu_b1_equalizer_gain_low.draw_normal();
			
			
			menu_b1_equalizer_band_freq_low_band_0_800.setValue(EEPROM.read(menu_b1_equalizer_band_freq_low_band_0_800.getMemAddress()));
			menu_b1_equalizer_band_freq_low_band_0_800.draw_normal();
			
			
			menu_b1_equalizer_gain_Q_low.setValue(EEPROM.read(menu_b1_equalizer_gain_Q_low.getMemAddress()));
			menu_b1_equalizer_gain_Q_low.draw_normal();
			
			
			menu_b1_equalizer_gain_low_mid.setValue(EEPROM.read(menu_b1_equalizer_gain_low_mid.getMemAddress()));
			menu_b1_equalizer_gain_low_mid.draw_normal();
			
			menu_b1_equalizer_band_freq_low_mid_band_0_2500.setValue(EEPROM.read(menu_b1_equalizer_band_freq_low_mid_band_0_2500.getMemAddress()));
			menu_b1_equalizer_band_freq_low_mid_band_0_2500.draw_normal();
			
			
			menu_b1_equalizer_gain_high_mid.setValue(EEPROM.read(menu_b1_equalizer_gain_high_mid.getMemAddress()));
			menu_b1_equalizer_gain_high_mid.draw_normal();
			
			
			menu_b1_equalizer_band_freq_high_mid_band_60_10700.setValue(EEPROM.read(menu_b1_equalizer_band_freq_high_mid_band_60_10700.getMemAddress()));
			menu_b1_equalizer_band_freq_high_mid_band_60_10700.draw_normal();
			
			
			menu_b1_equalizer_gain_high.setValue(EEPROM.read(menu_b1_equalizer_gain_high.getMemAddress()));
			menu_b1_equalizer_gain_high.draw_normal();
			
			
			menu_b1_equalizer_band_freq_high_band_1000_5800.setValue(EEPROM.read(menu_b1_equalizer_band_freq_high_band_1000_5800.getMemAddress()));
			menu_b1_equalizer_band_freq_high_band_1000_5800.draw_normal();
			
			
			menu_b1_equalizer_gain_Q_high.setValue(EEPROM.read(menu_b1_equalizer_gain_Q_high.getMemAddress()));
			menu_b1_equalizer_gain_Q_high.draw_normal();
		}

		
		
		set_mode_color(mode);
		myGLCD.setFont( arial_bold);
		myGLCD.print(F("-EQ"), x + 15, y+15);
		//myGLCD.setFont(arial_bold);
		myGLCD.print(String(ddd), x , y + 15);
		
		
		return;
	}
	else
	temp_val = temp_val*(double)0.7 / 127+0.31;
	name = String(temp_val);

	String sValue = "    ";
	String intToString = String(name);

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		if (x>3)
		break;
		sValue[x] = intToString[x];
	}

	set_mode_color(mode);
	myGLCD.setFont(Retro8x16);
	myGLCD.print(F("Q"), x + 63, y+13);
	//myGLCD.setFont(arial_bold);
	myGLCD.print(sValue, x + 20, y + 13);
}
#define state_WAITING_START 0
#define state_RECORDING 1
#define state_RECORDED 2
#define state_SAVE_WAIT 3

#define state_STOPED 0
#define state_PLAYING 1


bool play_notri=false;
int play_timer_time=-1;
void draw_PLAY_buttn(MenuItem* p_menu_item, byte mode)
{
	//calculate_free_RAM(5);
	//return;

	
	//if(play_notri==false)
	//return;
	
	int x = p_menu_item->get_x();
	int y=p_menu_item->get_y();
	String name = "";//p_menu_item->get_name();
	String name2="";// = p_menu_item->get_name();
	String name3="";

	DEBUG_print(F("state:"));
	DEBUG_println(p_menu_item->getValue());
	set_mode_color(mode);
	myGLCD.drawRoundRect(zeroX + x, y, zeroX + x + 300, y + button_heigth+60);
	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	
	//if(mode==ACTION_SELECT_COLOR&&p_menu_item->getValue()==state_STOPED)
	//p_menu_item->addValue(1);
	
	//if(mode==ACTION_CHECK_COLOR)
	{
		
		
		if (p_menu_item->getValue()==state_STOPED)//checked
		{
			MIDI_sender.mute_all_sounds();
			name=F("1.START PLAYING");
			name2=F("CLICK TO START PLAYING SELECTED ");
			name3=F("FILE");
			
			if(mode==ACTION_SELECT_COLOR&&SD_work.check_SD_init()==false)
			{
				name=F("1.SD CARD PROBLEM!");
				name2=F("EJECT SD CARD AND INSERT AGAIN");
				name3=F("");
				p_menu_item->setValue(p_menu_item->getValue()-1);
			}
			else if(mode==ACTION_SELECT_COLOR&&SD_work.set_playing(false,FILENAME_PATH)==state_RECORDING)
			{
				name=F("1.ACTIVE RECORDING");
				name2=F("FINISH RECORDING!");
				name3=F("");
				p_menu_item->setValue(p_menu_item->getValue()-1);
			}
			
		}
		else if(p_menu_item->getValue()==state_PLAYING)
		{
			MIDI_sender.mute_all_sounds();
			//p_menu_item->setValue(state_WAITING_START);
			myGLCD.setFont(arial_bold);
			name=F("2.PLAYING FILE");
			name2=FILENAME_PATH;
			name3=F("");
			if(mode==ACTION_SELECT_COLOR&&SD_work.set_playing(true,FILENAME_PATH)==state_RECORDING)
			{
				name=F("1.ACTIVE RECORDING");
				name2=F("FINISH RECORDING!");
				name3=F("");
				p_menu_item->setValue(p_menu_item->getValue()-1);
			}
			if(mode!=ACTION_CLEAR_COLOR)
			menu_PLAY_file.draw_normal();
			//SD_work.set_playing(true,FILENAME_PATH);
		}
	}
	
	for(int x=name.length();x<=17;x++)
	{
		name+=" ";//za brisanje
	}
	for(int x=name2.length();x<=35;x++)
	{
		name2+=" ";//za brisanje
	}
	for(int x=name3.length();x<=35;x++)
	{
		name3+=" ";//za brisanje
	}
	myGLCD.setFont(arial_bold);
	myGLCD.print(name, zeroX + x + 3, y + 10);
	myGLCD.setFont(mykefont2);
	if(mode!=ACTION_CLEAR_COLOR)
	set_mode_color(ACTION_REDRAW_COLOR);
	myGLCD.print(name2, zeroX + x + 5, y + 40);
	myGLCD.print(name3, zeroX + x + 5, y + 55);
	
	name="";
	name2="";
	name3="";

	
	
	
	//myGLCD.setColor(line_color[0], line_color[1], line_color[2]);
	

}

void draw_calibr_buttn(MenuItem* p_menu_item, byte mode)
{
	int x = p_menu_item->get_x();
	int y=p_menu_item->get_y();
	String name = p_menu_item->get_name();


	DEBUG_print(F("state:"));
	DEBUG_println(p_menu_item->getValue());
	

	


	set_mode_color(mode);
	

	set_mode_color(mode);
	//myGLCD.drawRoundRect(zeroX + x, y, zeroX + x + 300, y + button_heigth+60);
	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.setFont(Retro8x16);
	if(mode==ACTION_SELECT_COLOR||mode==ACTION_INFO_COLOR)
	{
		myGLCD.print(F("1. MOVE PEDAL BACKWARD AND PRESS S+10"), zeroX + x + 3, y + 30);
		myGLCD.print(F("2. RELEASE S+10 "), zeroX + x + 3, y + 50);
		myGLCD.print(F("3. MOVE PEDAL FORWARD AND PRESS S+100"), zeroX + x + 3, y + 70);
		myGLCD.print(F("4. RELEASE S+100 "), zeroX + x + 3, y + 90);
		myGLCD.print(F("5. PRESS BACK BUTTON "), zeroX + x + 3, y + 110);
	}
	

	if(mode==ACTION_CLEAR_COLOR)
	{
		set_mode_color(ACTION_CLEAR_COLOR);
		myGLCD.print(F("1. MOVE PEDAL BACKWARD AND PRESS S+10"), zeroX + x + 3, y + 30);
		myGLCD.print(F("2. RELEASE S+10 "), zeroX + x + 3, y + 50);
		myGLCD.print(F("3. MOVE PEDAL FORWARD AND PRESS S+100"), zeroX + x + 3, y + 70);
		myGLCD.print(F("4. RELEASE S+100 "), zeroX + x + 3, y + 90);
		myGLCD.print(F("5. PRESS BACK BUTTON "), zeroX + x + 3, y + 110);
		
	}
	
	if(mode==ACTION_FIRST_DRAW)
	{
		set_mode_color(ACTION_INFO_COLOR);
		myGLCD.print(F("PRESS MENU BUTTON TO CALIBRATE"), zeroX + x + 3, y + 30);
	}
	

	if(mode!=ACTION_CLEAR_COLOR)
	set_mode_color(ACTION_REDRAW_COLOR);
	else
	set_mode_color(ACTION_CLEAR_COLOR);
	
	name="POSITION MAX: ";
	//name=EEPROMReadlong(add_gas1_max);
	name+=EEPROMReadlong(add_gas1_max);
	
	for(int x=name.length();x<=19;x++)
	{
		name+=" ";//za brisanje
	}
	myGLCD.print(name, zeroX + x + 3, y + 170);
	
	name="POSITION MIN: ";
	name+=EEPROMReadlong(add_gas1_min);
	for(int x=name.length();x<=19;x++)
	{
		name+=" ";//za brisanje
	}
	myGLCD.print(name, zeroX + x + 3, y + 190);
	
	myGLCD.setFont(arial_bold);
	myGLCD.print(F("PEDALS CALIBRATION"), zeroX + x + 3, y);


	
	
	//myGLCD.setColor(line_color[0], line_color[1], line_color[2]);
	
}


void draw_RECORD_buttn(MenuItem* p_menu_item, byte mode)
{
	
	int x = p_menu_item->get_x();
	int y=p_menu_item->get_y();
	String name = "";//p_menu_item->get_name();
	String name2="";// = p_menu_item->get_name();
	String name3="";
	/*
	if(p_menu_item->getValue()==state_WAITING_START)
	{
	p_menu_item->setValue(state_RECORDING);
	name=F("STOP RECORDING");
	}
	else if(p_menu_item->getValue()==state_RECORDING)
	{
	p_menu_item->setValue(state_WAITING_START);
	name=F("SAVED");
	//save to sd card
	}
	else
	{
	name=F("check");
	}*/
	
	DEBUG_print(F("state:"));
	DEBUG_println(p_menu_item->getValue());
	
	
	
	
	
	if (p_menu_item->getValue()==state_WAITING_START)//checked
	{
		
		name=F("1.START RECORDING");
		name2=F("CLICK TO START RECORDING, FIRST ");
		name3=F("CHOOSE TRACKNAME BELOW!");
		
		if(SD_work.check_SD_init()==false)
		{
			name=F("1.SD CARD PROBLEM!");
			name2=F("EJECT SD CARD AND INSERT AGAIN");
			name3=F("");
			p_menu_item->setValue(p_menu_item->getValue()-1);
		}
		
		
		
	}
	else if(p_menu_item->getValue()==state_RECORDING)
	{
		//p_menu_item->setValue(state_WAITING_START);
		MIDI_sender.mute_all_sounds();
		myGLCD.setFont(arial_bold);
		name=F("2.RECORDING...");
		name2=F("CLICK TO SAVE RECORDING INTO FILE");
		name3=F("");
		if(mode==ACTION_SELECT_COLOR)
		{
			
			
			if(SD_work.get_is_playing())
			{
				name=F("2.FILE IS PLAYING");
				name2=F("FINISH PLAYING FILE!");
				name3=F("");
				p_menu_item->setValue(p_menu_item->getValue()-1);
			}
			else
			SD_work.set_recording(true);
		}
	}
	else if(p_menu_item->getValue()==state_RECORDED)//checked
	{
		
		name=F("3.SAVED INTO FILE");
		name2=FILENAME_PATH;
		name3=F("CLICK TO CONTINUE");
		
		if(mode==ACTION_SELECT_COLOR)
		{
			
			if(SD_work.save_current_recording(FILENAME_PATH)==false)//poglej tukaj
			{
				name=F("3.PROBLEM SAVING!");
			}
			

			
			SD_work.set_recording(false);
			menu_NUM_timer.draw_selected();//za update funkcijo tmp fix
		}
	}
	else if (p_menu_item->getValue()==state_SAVE_WAIT)//checked
	{
		name=F("4.CLICK FOR FINISH");
		name2=F("FOR NEW RECORDING, DO NOT");
		name3=F("FORGET TO CHOOSE NEW TRACKNAME!!!");


	}
	
	set_mode_color(mode);
	myGLCD.drawRoundRect(zeroX + x, y, zeroX + x + 300, y + button_heigth+60);
	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	
	for(int x=name.length();x<=17;x++)
	{
		name+=" ";//za brisanje
	}
	for(int x=name2.length();x<=35;x++)
	{
		name2+=" ";//za brisanje
	}
	for(int x=name3.length();x<=35;x++)
	{
		name3+=" ";//za brisanje
	}
	
	myGLCD.setFont(arial_bold);
	myGLCD.print(name, zeroX + x + 3, y + 10);
	myGLCD.setFont(mykefont2);
	if(mode!=ACTION_CLEAR_COLOR)
	set_mode_color(ACTION_REDRAW_COLOR);
	myGLCD.print(name2, zeroX + x + 5, y + 40);
	myGLCD.print(name3, zeroX + x + 5, y + 55);
	
	
	//myGLCD.setColor(line_color[0], line_color[1], line_color[2]);
	

}
int timer_time=-1;
bool rec_notri=false;
void draw_timer(MenuItem* p_menu_item, byte mode)
{
	byte drawmode=mode;
	
	if(mode==ACTION_REDRAW_COLOR)
	rec_notri=true;
	
	if(rec_notri==false)
	return;
	
	if(mode==ACTION_CLEAR_COLOR)
	{
		rec_notri=false;
	}
	
	
	

	int calc_time=SD_work.get_recording_time();

	
	if(mode==ACTION_SELECT_COLOR)//uporaba za update funkcijo.. temp fix
	{
		drawmode=ACTION_REDRAW_COLOR;
		if(timer_time==calc_time)
		return;
	}
	
	timer_time=calc_time;
	
	byte _hour=calc_time/3600;
	byte _minute=calc_time/60;
	byte _seconds=calc_time%60;
	
	String s_time="";
	if(_hour<=9)
	s_time+="0";
	s_time+=(String)_hour+":";
	
	if(_minute<=9)
	s_time+="0";
	s_time+=(String)_minute+":";
	
	if(_seconds<=9)
	s_time+="0";
	s_time+=(String)_seconds;
	
	set_mode_color(drawmode);
	myGLCD.setFont(arial_bold);
	myGLCD.print(s_time, zeroX + 3,180);

	
	
}

void draw_play_timer(MenuItem* p_menu_item, byte mode)
{
	byte drawmode=mode;
	
	if(mode==ACTION_REDRAW_COLOR)
	play_notri=true;
	
	if(play_notri==false)
	return;
	
	if(mode==ACTION_CLEAR_COLOR)
	{
		play_notri=false;
	}
	
	
	

	int calc_time=SD_work.get_playing_time();
	
	if(mode==ACTION_SELECT_COLOR)//uporaba za update funkcijo.. temp fix
	{
		drawmode=ACTION_REDRAW_COLOR;
		if(play_timer_time==calc_time)
		return;
	}
	
	play_timer_time=calc_time;
	
	byte _hour=calc_time/3600;
	byte _minute=calc_time/60;
	byte _seconds=calc_time%60;
	
	String s_time="";
	if(_hour<=9)
	s_time+="0";
	s_time+=(String)_hour+":";
	
	if(_minute<=9)
	s_time+="0";
	s_time+=(String)_minute+":";
	
	if(_seconds<=9)
	s_time+="0";
	s_time+=(String)_seconds;
	
	set_mode_color(drawmode);
	myGLCD.setFont(arial_bold);
	myGLCD.print(s_time, zeroX+p_menu_item->get_x(),p_menu_item->get_y());

	
	
}

byte tmp_play_prev=0;
void draw_PLAY_FILE_selector(MenuItem* p_menu_item, byte mode)
{
	calculate_free_RAM(1);
	DEBUG_STRING_print("val:");
	DEBUG_print(p_menu_item->getValue());
	DEBUG_STRING_print(" __exram loc:");
	DEBUG_println(ADD_filestrings+p_menu_item->getValue()*13);
	
	if(p_menu_item->getValue()>=SD_work.files_count)
	{p_menu_item->setValue(SD_work.files_count-1);}
	
	
	//if(p_menu_item->getValue()>=exRAM.read_byte(ADD_filestrings)-1)//tmp fix
	//p_menu_item->setValue(exRAM.read_byte(ADD_filestrings)-1);
	
	char ram_file_name[13];
	exRAM.read_stream(ADD_filestrings+p_menu_item->getValue()*15,ram_file_name,13);

	int this_track_time=exRAM.read_int(ADD_filestrings+p_menu_item->getValue()*15+13);
	//SD.exists(track_name);

	FILENAME_PATH=F("/TRACKS/");
	FILENAME_PATH+=ram_file_name;
	
	DEBUG_println(FILENAME_PATH);
	
	bool file_exist_warning=true;
	
	while(file_exist_warning)
	{
		
		if (SD.exists(ram_file_name))
		{

			file_exist_warning=true;
			DEBUG_println(F("DA"));
			DEBUG_println(ram_file_name);
			break;
		}else
		{
			file_exist_warning=false;
			DEBUG_println(F("NE"));
			DEBUG_println(ram_file_name);
			break;
		}
	}


	//FILENAME_PATH=ram_file_name;
	if(mode!=ACTION_CLEAR_COLOR)
	{
		set_mode_color(ACTION_REDRAW_COLOR);
	}
	myGLCD.setFont(arial_bold);
	//String name="CHOOSEN";
	//myGLCD.print(name, zeroX + 3,110);
	myGLCD.print(F("TRACKNAME:"), zeroX + 3,130);
	myGLCD.print(F("LENGTH:"), zeroX + 3,150);
	myGLCD.print(F("PLAY TIME:"), zeroX + 3,200);
	unsigned long calc_time=this_track_time;
	if(calc_time>3600*24)
	calc_time=0;
	byte _hour=calc_time/3600;
	byte _minute=calc_time/60;
	byte _seconds=calc_time%60;
	
	String s_time="";
	if(_hour<=9)
	s_time+="0";
	s_time+=(String)_hour+":";
	
	if(_minute<=9)
	s_time+="0";
	s_time+=(String)_minute+":";
	
	if(_seconds<=9)
	s_time+="0";
	s_time+=(String)_seconds;
	
	set_mode_color(mode);
	myGLCD.setFont(arial_bold);
	myGLCD.print(s_time, zeroX + 170,150);
	
	char out_name[12];
	String tmp_s=ram_file_name;
	//memcpy(out_name, ram_file_name, 10);
	//
	//
	//out_name=ram_file_name;
	tmp_s.remove(tmp_s.length()-4,4);

	for(int x=tmp_s.length();x<=15;x++)
	{
		tmp_s+=" ";//za brisanje
	}
	set_mode_color(mode);
	myGLCD.setFont(arial_normal);
	myGLCD.print(tmp_s, zeroX + 170,130);



	set_mode_color(mode);
	myGLCD.setFont(mykefont2);


	//
	//if(file_exist_warning&&mode!=ACTION_CLEAR_COLOR)
	//{
	//set_mode_color(ACTION_INFO_COLOR);
	//myGLCD.print("available!", zeroX + 120,170);
	//}
	//else
	//{
	//set_mode_color(ACTION_CLEAR_COLOR);
	//myGLCD.print("available!", zeroX + 120,170);
	//}

	set_mode_color(ACTION_INFO_COLOR);


	//name="";
	//myGLCD.print(name, zeroX + 1,150);

	calculate_free_RAM(1);

}
void draw_PLAY_FILE_selector2(MenuItem* p_menu_item, byte mode)
{
	calculate_free_RAM(1);

	FILENAME_PATH=F("/TRACKS/FILE_");
	FILENAME_PATH+=(String)p_menu_item->getValue();
	FILENAME_PATH+=".acc";

	//SD.exists(track_name);

	bool file_exist_warning=true;
	
	while(file_exist_warning)
	{
		
		if (SD.exists(FILENAME_PATH))
		{

			file_exist_warning=true;
			DEBUG_println(F("DA"));
			DEBUG_println(FILENAME_PATH);
			break;
		}else
		{
			file_exist_warning=false;
			DEBUG_println(F("NE"));
			DEBUG_println(FILENAME_PATH);
			break;
		}
	}



	if(mode!=ACTION_CLEAR_COLOR)
	{
		set_mode_color(ACTION_REDRAW_COLOR);
	}
	myGLCD.setFont(arial_bold);
	String name="SELECT";
	myGLCD.print(name, zeroX + 3,110);
	myGLCD.print(F("TRACKNAME:"), zeroX + 3,130);
	myGLCD.print(F("PLAY TIME:"), zeroX + 3,160);
	unsigned long calc_time=SD_work.Var_track_time();
	byte _hour=calc_time/3600;
	byte _minute=calc_time/60;
	byte _seconds=calc_time%60;
	
	String s_time="";
	if(_hour<=9)
	s_time+="0";
	s_time+=(String)_hour+":";
	
	if(_minute<=9)
	s_time+="0";
	s_time+=(String)_minute+":";
	
	if(_seconds<=9)
	s_time+="0";
	s_time+=(String)_seconds;
	
	set_mode_color(mode);
	myGLCD.setFont(arial_bold);
	myGLCD.print(s_time, zeroX + 150,180);
	name="FILE_";
	name+=(String)p_menu_item->getValue();
	for(int x=name.length();x<=15;x++)
	{
		name+=" ";//za brisanje
	}
	set_mode_color(mode);
	myGLCD.setFont(arial_normal);
	myGLCD.print(name, zeroX + 170,130);



	set_mode_color(mode);
	myGLCD.setFont(mykefont2);



	if(file_exist_warning&&mode!=ACTION_CLEAR_COLOR)
	{
		set_mode_color(ACTION_INFO_COLOR);
		myGLCD.print(F("available!"), zeroX + 150,150);
	}
	else
	{
		set_mode_color(ACTION_CLEAR_COLOR);
		myGLCD.print(F("available!"), zeroX + 150,150);
	}




	//name="";
	//myGLCD.print(name, zeroX + 1,150);

	calculate_free_RAM(1);

}
void draw_REC_FILE_selector(MenuItem* p_menu_item, byte mode)
{

	FILENAME_PATH=F("/TRACKS/FILE_");
	FILENAME_PATH+=(String)p_menu_item->getValue();
	FILENAME_PATH+=".acc";
	
	//SD.exists(track_name);
	
	bool file_exist_warning=false;
	
	if (SD.exists(FILENAME_PATH))
	{

		file_exist_warning=true;
		DEBUG_println(F("DA"));
		DEBUG_println(FILENAME_PATH);
	}else
	{
		file_exist_warning=false;
		DEBUG_println(F("NE"));
		DEBUG_println(FILENAME_PATH);
	}


	

	if(mode!=ACTION_CLEAR_COLOR)
	{
		set_mode_color(ACTION_REDRAW_COLOR);
	}
	myGLCD.setFont(arial_bold);
	String name="CHOOSE";
	myGLCD.print(name, zeroX + 3,110);
	myGLCD.print(F("TRACKNAME:"), zeroX + 3,130);
	myGLCD.print(F("REC TIME:"), zeroX + 3,160);
	
	name="FILE_";
	name+=(String)p_menu_item->getValue();
	for(int x=name.length();x<=15;x++)
	{
		name+=" ";//za brisanje
	}
	set_mode_color(mode);
	myGLCD.setFont(hallfetica_normal);
	myGLCD.print(name, zeroX + 170,130);
	
	
	
	set_mode_color(mode);
	myGLCD.setFont(mykefont2);
	

	
	if(file_exist_warning&&mode!=ACTION_CLEAR_COLOR)
	{
		set_mode_color(ACTION_INFO_COLOR);
		myGLCD.print(F("ALREADY EXIST!"), zeroX + 150,150);
	}
	else
	{
		set_mode_color(ACTION_CLEAR_COLOR);
		myGLCD.print(F("ALREADY EXIST!"), zeroX + 150,150);
	}
	

	
	
	//name="";
	//myGLCD.print(name, zeroX + 1,150);

	calculate_free_RAM(1);
	
}

void draw_main_screen_background(MenuItem* p_menu_item, byte mode)
{

	//	myGLCD.setFont(OCR_A_Extended_M);
	myGLCD.setFont(arial_bold);
	set_mode_color(mode);
	//myGLCD.setFont(Sinclair_M);
	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	myGLCD.drawRect(zeroX + 3, 120, zeroX + 280, 122);
	myGLCD.print(F("REVERB:"), 8+zeroX, 155);
	myGLCD.print(F("TRANSPOSE:"), 8+zeroX, 180);
	#ifdef  MODEL_GRANDIOSO_232T
	myGLCD.print(F("GRANDIOSO 232 T"), 8+zeroX, 25);
	#endif
	
	#ifdef  MODEL_FESTOSO_232T
	myGLCD.print(F("FESTOSO 232 T"), 8+zeroX, 25);
	#endif

}
void draw_theme_selector(MenuItem* p_menu_item, byte mode)
{
	DEBUG_println(F("theme::"));
	String name;// = p_menu_item->get_name();
	int value = p_menu_item->getValue();
	EEPROM.write(ADD_menu_b8_theme_1,value);
	setTheme(value);
	switch (value)
	{
		case 0:
		name = F("1 ACCENT");
		break;
		case 1:
		name = F("2 DARK BLUE");
		break;
		case 2:
		name = F("3 AUTUMN");
		break;
		case 3:
		name = F("4 ICY");
		break;
		case 4:
		name = F("5 TEST");
		break;

		default:
		break;
	}

	String sValue = "                    ";

	for (int x = 0; x < name.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = name[x];
	}


	myGLCD.setFont(arial_normal);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();


	int min = -127;
	int max = 127;

	value = p_menu_item->getValue() + 1;

	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX;//zamik 4 crke - 4*16

	set_mode_color(mode);
	//myGLCD.setFont(Sinclair_M);
	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);

	myGLCD.print(F("THEME:"), x, y+30);
	myGLCD.print(sValue, x+100, y+30);
	
	if(mode!=ACTION_CLEAR_COLOR)
	set_mode_color(ACTION_REDRAW_COLOR);
	
	myGLCD.setFont(arial_bold);
	myGLCD.print(F("SET BUTTONS COLOR:"), x, 85);

	//sValue = "  ";
	//String intToString = String(value);
	//
	//for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	//{
	//if (x>2)
	//break;
	//sValue[x] = intToString[x];
	//}
	//
	//myGLCD.print(sValue, x + 100, y);
	//myGLCD.print(F("- 5"), x + 150, y);

}

void draw_style_selector(MenuItem* p_menu_item, byte mode)
{
	String name = p_menu_item->get_name();
	int value = p_menu_item->getValue();
	
	switch (value)
	{
		case 0:
		name = F("1 ACCENT");
		break;
		case 1:
		name = F("2 ACCENT BLUE");
		break;
		case 2:
		name = F("3 AUTUMN");
		break;
		case 3:
		name = F("4 ICY");
		break;
		case 4:
		name = F("5 TEST");
		break;

		default:
		break;
	}

	String sValue = "                    ";

	for (int x = 0; x < name.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = name[x];
	}

	myGLCD.setFont(arial_bold);
	//myGLCD.setFont(OCR_A_Extended_M);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	

	int min = -127;
	int max = 127;

	value = p_menu_item->getValue()+1;

	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX;//zamik 4 crke - 4*16

	set_mode_color(mode);
	//myGLCD.setFont(Sinclair_M);
	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	
	myGLCD.print(F("STYLE:"),x, y);
	myGLCD.print(sValue, x, y+30);

	sValue = "  ";
	String intToString = String(value);

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		if (x>2)
		break;
		sValue[x] = intToString[x];
	}
	
	myGLCD.print(sValue, x+100, y);
	myGLCD.print(F("- 5"), x + 150, y);

}
void draw_mem_bank_selector(MenuItem* p_menu_item, byte mode)
{
	String name = p_menu_item->get_name();
	int value = p_menu_item->getValue();

	switch (value)
	{
		case 0:
		name = "1";
		break;
		case 1:
		name = "2";
		break;
		case 2:
		name = "3";
		break;
		case 3:
		name = "4";
		break;
		case 4:
		name = "5";
		break;;
		case 5:
		name = "6";
		break;
		case 6:
		name = "7";
		break;
		case 7:
		name = "8";
		break;
		case 8:
		name = "9";
		break;
		case 9:
		name = "10";
		break;
		case 10:
		name = "11";
		break;
		case 11:
		name = "12";
		break;
		
		default:
		name = "bug!";
		break;
	}
	
	
	
	USER_ID=value;

	String sValue = "  ";

	for (int x = 0; x < name.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = name[x];
	}

	myGLCD.setFont(arial_bold);
	//	myGLCD.setFont(OCR_A_Extended_M);

	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();


	int min = -127;
	int max = 127;

	value = p_menu_item->getValue() + 1;

	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX;//zamik 4 crke - 4*16

	
	//myGLCD.setFont(Sinclair_M);
	
	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
	set_mode_color(mode);
	if(mode!=ACTION_CLEAR_COLOR)
	{
		set_mode_color(ACTION_REDRAW_COLOR);
	}
	myGLCD.print(F("ORGANIST"), x+90, y+30);
	//myGLCD.print(sValue, x, y + 30);
	set_mode_color(mode);
	myGLCD.setFont(GroteskBold24x48);
	myGLCD.print(sValue, x + 140, 100);
	return;

	sValue = "  ";
	String intToString = String(value);

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		if (x>2)
		break;
		sValue[x] = intToString[x];
	}

	myGLCD.print(sValue, x + 170, y);
	myGLCD.print(F("- 8"), x + 220, y);
}
void draw_hist_selector(MenuItem* p_menu_item, byte mode)
{
	String name = p_menu_item->get_name();
	int value = p_menu_item->getValue();

	TEMPER_SELECTED=value;
	switch (value)
	{
		case 0:
		name = H_neutral;
		break;
		case 1:
		name = H_natuerlich_harmo;
		break;
		case 2:
		name = H_mitteltoenig;
		break;
		case 3:
		name = H_mittel_muriorg;
		break;
		case 4:
		name = H_ho_cheng_thien;
		break;;
		case 5:
		name = H_joung;
		break;
		case 6:
		name = H_praetorious;
		break;
		case 7:
		name = H_pytagoras;
		break;
		case 8:
		name = H_gramathaeus_orgel;
		break;
		case 9:
		name = H_ganassi;
		break;
		case 10:
		name = H_schlick;
		break;
		case 11:
		name = H_werckmeister_3;
		break;
		case 12:
		name = H_silberman_1;
		break;
		case 13:
		name = H_silberman_2;
		break;
		case 14:
		name = H_bach_billeter;
		break;
		case 15:
		name = H_back_woltemp;
		break;
		case 16:
		name = H_billeter_orgel;
		break;
		case 17:
		name = H_kimberger_1;
		break;
		case 18:
		name = H_kimberger_2;
		break;
		case 19:
		name = H_kimberger_3;
		break;
		case 20:
		name = H_kelletal_1966;
		break;
		case 21:
		name = H_kelletal_1977;
		break;
		case 22:
		name = H_werckmeister_2;
		break;

		default:
		break;
	}

	
	String sValue = "                    ";

	for (int x = 0; x < name.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = name[x];
	}


	
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();


	int min = -127;
	int max = 127;

	value = p_menu_item->getValue() + 1;

	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX;//zamik 4 crke - 4*16

	set_mode_color(mode);
	//myGLCD.setFont(Sinclair_M);
	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);

	myGLCD.setFont(arial_bold);
	myGLCD.print(F("TEMPERAMENT:"), x, y+22);
	myGLCD.setFont(arial_normal);
	if(mode!=ACTION_CLEAR_COLOR)
	set_mode_color(ACTION_REDRAW_COLOR);
	myGLCD.print(sValue, x, y + 40);

	sValue = "  ";
	String intToString = String(value);

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		if (x>2)
		break;
		sValue[x] = intToString[x];
	}


	//myGLCD.print(sValue, x + 190, y);
	//myGLCD.print(F("- 23"), x + 220, y);

}

void draw_tone_selector(MenuItem* p_menu_item, byte mode)
{
	myGLCD.setFont(arial_normal);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();
	String name = p_menu_item->get_name();

	int min = 0;
	int max = 127;
	

	
	int value = p_menu_item->getValue();
	
	if(value>=127)
	value=127;

	//Serial.println("drawSlider single label");

	int width = 40;
	int map_value = map(value, min, max, 0, width);


	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX + 200;//zamik 4 crke - 4*16

	//if(p_menu_item->get_name_id()==NUM_tone_selector)
	{
		map_value = map(value, min, max, 0, width);


		String sValue = "       ";
		String intToString = String(map_value);

		
		byte offset=30;
		myGLCD.setColor(back_color[0], back_color[1], back_color[2]);
		myGLCD.fillRect(x-offset, y + 1, x + map_value - 1-offset, y + 7);//kvadrat za brisanje prejšnje slike
		myGLCD.fillRect(x-offset + map_value  + 1, y + 1, x + width-offset, y + 7);//kvadrat za brisanje prejšnje slike

		set_mode_color(mode);

		myGLCD.fillRect(x-offset + map_value, y + 1, x + map_value -offset, y + 7);//sredinski kvadrat

		myGLCD.drawRoundRect(x - 2-offset, y, x + width + 2-offset, y + 8);//okvir

		myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);
		myGLCD.print(name, x - 200, y - 4);
		
		name=String(get_tone_name(MIDI_sender.LAST_sended_tone));
		DEBUG_println(name);
		myGLCD.setFont(arial_bold);
		myGLCD.print(name, x - 100, y - 4);
		

		sValue = "    ";
		intToString = String(value);

		for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
		{
			if (x>4)
			break;
			sValue[x] = intToString[x];
		}
		
		myGLCD.setFont(hallfetica_normal);
		myGLCD.print(sValue, x + width-20, y - 4);

		return;

	}

}

void draw_FILE_SD_selector(MenuItem* p_menu_item, byte mode)
{
	int y_loc;
	calculate_free_RAM(1);
	DEBUG_STRING_print("nameid:");
	DEBUG_print(p_menu_item->get_name_id());
	DEBUG_STRING_print(" __exram loc:");
	DEBUG_println(ADD_filestrings+p_menu_item->getValue()*13);

	char ram_file_name[13];
	exRAM.read_stream(ADD_filestrings+p_menu_item->getValue()*15,ram_file_name,13);

	int this_track_time=exRAM.read_int(ADD_filestrings+p_menu_item->getValue()*15+13);
	//SD.exists(track_name);
	String tmp_s;

	if(!SD.exists("/SETTER"))
	{
		DEBUG_println(F("NE OBSTAJA"));
		SD.mkdir("/SETTER");
	}
	if(!SD.exists("/SETTINGS"))
	{
		DEBUG_println(F("NE OBSTAJA"));
		SD.mkdir("/SETTINGS");
	}

	if(p_menu_item->get_name_id()==NUM_dest_file)
	{
		FILENAME_PATH=F("/SETTINGS/");
		tmp_s="FILE_";
		FILENAME_PATH+="FILE_";
		y_loc=100;
	}
	else if(p_menu_item->get_name_id()==NUM_dest_file_setter)
	{
		FILENAME_PATH=F("/SETTER/");
		FILENAME_PATH+="COMB_";
		tmp_s="COMB_";
		y_loc=50;
	}


	FILENAME_PATH+=(String)p_menu_item->getValue();
	//FILENAME_PATH+=".set";

	DEBUG_println(FILENAME_PATH);

	bool file_exist_warning=true;
	
	if (SD.exists(FILENAME_PATH))
	{

		file_exist_warning=true;
		DEBUG_println(F("DA"));
		DEBUG_println(FILENAME_PATH);

	}else
	{
		file_exist_warning=false;
		DEBUG_println(F("NE"));
		DEBUG_println(FILENAME_PATH);

	}
	if(p_menu_item->getValue()==0)//quick fix
	file_exist_warning=false;
	//file_exist_warning=true;


	//FILENAME_PATH=ram_file_name;
	if(mode!=ACTION_CLEAR_COLOR)
	{
		set_mode_color(ACTION_REDRAW_COLOR);
	}
	else
	set_mode_color(ACTION_CLEAR_COLOR);

	myGLCD.setFont(arial_bold);
	//String name="CHOOSEN";
	//myGLCD.print(name, zeroX + 3,110);
	myGLCD.print(F("SELECT FILE:"), zeroX + 3,y_loc);
	//myGLCD.print(F("FILE:"), zeroX + 3,150);


	set_mode_color(mode);
	myGLCD.setFont(arial_bold);

	char out_name[12];

	if(p_menu_item->getValue()==0&&p_menu_item->get_name_id()==NUM_dest_file_setter)
	tmp_s="CLEAR MEM";
	else
	tmp_s+=(String)p_menu_item->getValue();


	for(int x=tmp_s.length();x<=15;x++)
	{
		tmp_s+=" ";//za brisanje
	}
	set_mode_color(mode);
	myGLCD.setFont(arial_normal);
	myGLCD.print(tmp_s, zeroX+8 ,y_loc+22);

	set_mode_color(mode);
	myGLCD.setFont(mykefont2);


	if(file_exist_warning&&mode!=ACTION_CLEAR_COLOR)
	{
		set_mode_color(ACTION_INFO_COLOR);
		myGLCD.print(F("available!"), zeroX + 170,y_loc+25);
	}
	else
	{
		set_mode_color(ACTION_CLEAR_COLOR);
		myGLCD.print(F("available!"), zeroX + 170,y_loc+25);
	}


	set_mode_color(ACTION_INFO_COLOR);
}
void draw_FILE_INTERNAL_selector(MenuItem* p_menu_item, byte mode)
{
	int y_loc;
	calculate_free_RAM(1);
	DEBUG_STRING_print("nameid:");
	DEBUG_print(p_menu_item->get_name_id());
	DEBUG_STRING_print(" __exram loc:");
	DEBUG_println(ADD_filestrings+p_menu_item->getValue()*13);

	char ram_file_name[13];
	exRAM.read_stream(ADD_filestrings+p_menu_item->getValue()*15,ram_file_name,13);

	int this_track_time=exRAM.read_int(ADD_filestrings+p_menu_item->getValue()*15+13);
	//SD.exists(track_name);
	String tmp_s;

	if(p_menu_item->get_name_id()==NUM_dest_file)
	{
		FILENAME_PATH=F("/SETTINGS/");
		tmp_s="ERROR";
		FILENAME_PATH+="FILE_";
	}
	else if(p_menu_item->get_name_id()==NUM_src_file_setter)
	{
		FILENAME_PATH=F("/SETTER/");
		FILENAME_PATH+="COMB_";
		tmp_s="ORGANIST ";
		y_loc=100;
	}


	FILENAME_PATH+=(String)p_menu_item->getValue();
	FILENAME_PATH+=".set";

	DEBUG_println(FILENAME_PATH);

	

	//FILENAME_PATH=ram_file_name;
	if(mode!=ACTION_CLEAR_COLOR)
	{
		set_mode_color(ACTION_REDRAW_COLOR);
	}
	else
	set_mode_color(ACTION_CLEAR_COLOR);

	myGLCD.setFont(arial_bold);
	//String name="CHOOSEN";
	//myGLCD.print(name, zeroX + 3,110);
	myGLCD.print(F("SELECT PROFILE:"), zeroX + 3,y_loc);
	//myGLCD.print(F("FILE:"), zeroX + 3,150);


	set_mode_color(mode);
	myGLCD.setFont(arial_bold);

	char out_name[12];

	tmp_s+=(String)p_menu_item->getValue();


	for(int x=tmp_s.length();x<=15;x++)
	{
		tmp_s+=" ";//za brisanje
	}
	set_mode_color(mode);
	myGLCD.setFont(arial_normal);
	myGLCD.print(tmp_s, zeroX+8 ,y_loc+22);

	set_mode_color(mode);
	myGLCD.setFont(mykefont2);

	set_mode_color(ACTION_INFO_COLOR);
	
}
void test_procent_load(byte val)
{
	#ifdef vkljuci_menije

	if(val%2==0)
	myGLCD.print((String)val+"%", zeroX + menu_load_buttn_dialog.get_x() + 80,  menu_load_buttn_dialog.get_y() + 10);
	#endif
}
void test_procent_save(byte val)
{
		#ifdef vkljuci_menije
	if(val%2==0)
	myGLCD.print((String)val+"%", zeroX + menu_save_buttn_dialog.get_x() + 80,  menu_save_buttn_dialog.get_y() + 10);
	#endif
}

void draw_SAVE_BUTTN_selector(MenuItem* p_menu_item, byte mode)
{
		#ifdef vkljuci_menije
	SD_work._update_trigger=test_procent_save;
	int x = p_menu_item->get_x();
	int y=p_menu_item->get_y();
	String name = "";//p_menu_item->get_name();
	String name2="";// = p_menu_item->get_name();
	String name3="";

	DEBUG_print(F("state:"));
	DEBUG_println(p_menu_item->getValue());
	set_mode_color(mode);
	myGLCD.drawRoundRect(zeroX + x, y, zeroX + x + 150, y + button_heigth+30);
	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);

	
	name=F("SAVE");
	if(p_menu_item->get_name_id()==NUM_save_buttn_dialog)
	{
		
		name2=F("SAVE PROFILE");
		name3=F("TO SD CARD FILE");
	}
	else
	{
		name2=F("SAVE SETTINGS");
		name3=F("TO SD CARD FILE");
	}

	if(mode==ACTION_SELECT_COLOR)
	{
		myGLCD.setFont(arial_bold);
		
		myGLCD.print(F("WAIT"), zeroX + x + 3, y + 10);
		name2="";
		for(byte c=0;c<17;c++)
		name2+=F(" ");
		myGLCD.setFont(mykefont2);
		myGLCD.print(name2, zeroX + x + 5, y + 35);
		myGLCD.print(name2, zeroX + x + 5, y + 50);
		//myGLCD.setFont(mykefont2);
		myGLCD.setFont(arial_bold);
		

		name=F("SAVED");
		if(p_menu_item->get_name_id()==NUM_save_buttn_dialog)
		{
			FILENAME_PATH=F("/SETTER/");
			FILENAME_PATH+="COMB_";
			FILENAME_PATH+=(String)menu_dest_file_organist.getValue();

			SD_work.save_profile_to_file(FILENAME_PATH,menu_src_file_organist.getValue());
			name2=F("ON SD CARD FILE:");
			name3=FILENAME_PATH;
			
		}
		else
		{
			FILENAME_PATH=F("/SETTINGS/");
			FILENAME_PATH+="FILE_";
			FILENAME_PATH+=(String)menu_dest_file.getValue();

			SD_work.save_settings_to_file(FILENAME_PATH);
			
			name2=F("ON SD CARD FILE:");
			name3=FILENAME_PATH;
		}
		
	}
	

	for(int x=name.length();x<=8;x++)
	{
		name+=" ";//za brisanje
	}
	for(int x=name2.length();x<=17;x++)
	{
		name2+=" ";//za brisanje
	}
	for(int x=name3.length();x<=17;x++)
	{
		name3+=" ";//za brisanje
	}
	if(mode!=ACTION_CLEAR_COLOR)
	set_mode_color(ACTION_REDRAW_COLOR);

	myGLCD.setFont(arial_bold);
	myGLCD.print(name, zeroX + x + 3, y + 10);
	myGLCD.setFont(mykefont2);

	myGLCD.print(name2, zeroX + x + 5, y + 35);
	myGLCD.print(name3, zeroX + x + 5, y + 50);
	name="";
	name2="";
	name3="";
	#endif
}

void draw_LOAD_BUTTN_selector(MenuItem* p_menu_item, byte mode)
{
		#ifdef vkljuci_menije
	SD_work._update_trigger=test_procent_load;
	int x = p_menu_item->get_x();
	int y=p_menu_item->get_y();
	String name = "";//p_menu_item->get_name();
	String name2="";// = p_menu_item->get_name();
	String name3="";

	DEBUG_print(F("state:"));
	DEBUG_println(p_menu_item->getValue());
	set_mode_color(mode);
	myGLCD.drawRoundRect(zeroX + x, y, zeroX + x + 150, y + button_heigth+30);
	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);

	//if(mode==ACTION_SELECT_COLOR&&p_menu_item->getValue()==state_STOPED)
	//p_menu_item->addValue(1);

	//if(mode==ACTION_CHECK_COLOR)
	{
		
		
		if(p_menu_item->get_name_id()==NUM_load_buttn_dialog)
		name=F("LOAD");
		else
		name=F("LOAD");
		
		if(p_menu_item->get_name_id()==NUM_load_buttn_dialog)
		{
			name2=F("LOAD PROFILE");
			name3=F("FROM SD CARD FILE");
			
			
		}
		else
		{
			name2=F("LOAD SETTINGS");
			name3=F("FROM SD CARD FILE");
		}
		
		
		if(mode==ACTION_SELECT_COLOR)
		{
			myGLCD.setFont(arial_bold);
			
			myGLCD.print(F("WAIT"), zeroX + x + 3, y + 10);
			name2="";
			for(byte c=0;c<17;c++)
			name2+=F(" ");
			myGLCD.setFont(mykefont2);
			myGLCD.print(name2, zeroX + x + 5, y + 35);
			myGLCD.print(name2, zeroX + x + 5, y + 50);
			//myGLCD.setFont(mykefont2);
			myGLCD.setFont(arial_bold);

			

			name=F("LOADED");
			if(p_menu_item->get_name_id()==NUM_load_buttn_dialog)
			{
				//SD_work.load_profile("test.txt",2);
				FILENAME_PATH=F("/SETTER/");
				FILENAME_PATH+="COMB_";
				FILENAME_PATH+=(String)menu_dest_file_organist.getValue();

				SD_work.load_profile(FILENAME_PATH,menu_src_file_organist.getValue());
				
				name2=F("INTO ORGANIST ");
				name2+=(String)menu_src_file_organist.getValue();
			}
			else
			{
				//SD_work.load_profile("test.txt",2);
				FILENAME_PATH=F("/SETTINGS/");
				FILENAME_PATH+="FILE_";
				FILENAME_PATH+=(String)menu_dest_file.getValue();

			if(	SD_work.load_settings(FILENAME_PATH))
			{
				name2=F("DEFAULT SETTINGS");
				name3=F("INTO MEMORY");
			}
			else
			{
				name2=F("ERROR ");
				name3=F("LOADING");
			}
			}
			
			
		}
	}

	for(int x=name.length();x<=8;x++)
	{
		name+=" ";//za brisanje
	}
	for(int x=name2.length();x<=17;x++)
	{
		name2+=" ";//za brisanje
	}
	for(int x=name3.length();x<=17;x++)
	{
		name3+=" ";//za brisanje
	}
	
	if(mode!=ACTION_CLEAR_COLOR)
	set_mode_color(ACTION_REDRAW_COLOR);
	myGLCD.setFont(arial_bold);
	
	if(p_menu_item->get_name_id()==NUM_load_buttn_dialog)
	myGLCD.print(F("MEMORY BANK"), zeroX+3,10);
	else
	myGLCD.print(F("ORGAN SETTINGS"), zeroX+3,10);
	
	if(mode!=ACTION_CLEAR_COLOR)
	set_mode_color(ACTION_REDRAW_COLOR);
	
	myGLCD.drawRect(zeroX + 3, 29, zeroX + 250, 31);
	
	myGLCD.setFont(arial_bold);
	myGLCD.print(name, zeroX + x + 3, y + 10);
	myGLCD.setFont(mykefont2);

	myGLCD.print(name2, zeroX + x + 5, y + 35);
	myGLCD.print(name3, zeroX + x + 5, y + 50);
	name="";
	name2="";
	name3="";
	
	#endif

}
void draw_stop_selector(MenuItem* p_menu_item, byte mode)
{
		#ifdef vkljuci_menije
	//myGLCD.fillRect(x, y + 40, x + 200, y + 40);
	myGLCD.setFont(arial_bold);
	String name ;//= p_menu_item->get_name();
	int value = p_menu_item->getValue();
	if(value>83)
	{
		p_menu_item->setValue(0);
		p_menu_item->draw_normal();
		return;
	}

	name=get_stop_name(value);
	
	int mem_add=STOPS_START_ADDRESSES+(value*5);//p_menu_item->getMemAddress();
	
	menu_b1_PAN_leftright.setMemAddress(mem_add+1);
	byte value1=EEPROM.read(mem_add+1);
	byte value2=EEPROM.read(mem_add+2);
	byte value3=EEPROM.read(mem_add+3);
	byte value4=EEPROM.read(mem_add+4);
	//if(value1>127)
	//value1=64;
	//if(value2>127)
	//value2=100;
	//if(value3>127)
	//value3=0;
	//if(value4>127)
	//value3=0;
	
	menu_b1_PAN_leftright.setValue(value1);
	if(ms.get_selected1()->get_name_id()==menu_b1_PAN_leftright.get_name_id())
	menu_b1_PAN_leftright.draw_selected();
	else
	menu_b1_PAN_leftright.draw_normal();
	
	menu_b1_stop_level.setMemAddress(mem_add+2);
	menu_b1_stop_level.setValue(value2);
	if(ms.get_selected1()->get_name_id()==menu_b1_stop_level.get_name_id())
	menu_b1_stop_level.draw_selected();
	else
	menu_b1_stop_level.draw_normal();
	
	menu_b1_tvf_resonance.setMemAddress(mem_add+3);
	menu_b1_tvf_resonance.setValue(value3);
	if(ms.get_selected1()->get_name_id()==menu_b1_tvf_resonance.get_name_id())
	menu_b1_tvf_resonance.draw_selected();
	else
	menu_b1_tvf_resonance.draw_normal();
	
	menu_b1_tvf_cutoff.setMemAddress(mem_add+4);
	menu_b1_tvf_cutoff.setValue(value4);
	if(ms.get_selected1()->get_name_id()==menu_b1_tvf_cutoff.get_name_id())
	menu_b1_tvf_cutoff.draw_selected();
	else
	menu_b1_tvf_cutoff.draw_normal();
	
	//menu_b1_tone_selector.setValue(exEEPROM.read(value*200+MIDI_sender.LAST_sended_tone));
	//if(ms.get_selected1()->get_name_id()==menu_b1_tone_selector.get_name_id())
	//menu_b1_tone_selector.draw_selected();
	//else
	//menu_b1_tone_selector.draw_normal();
	
	String sValue = "                  ";

	for (int x = 0; x < name.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		sValue[x] = name[x];
	}

	myGLCD.setFont(arial_bold);
	//	myGLCD.setFont(OCR_A_Extended_M);
	int x = p_menu_item->get_x();
	int y = p_menu_item->get_y();


	int min = -127;
	int max = 127;

	value = p_menu_item->getValue() + 1;

	int px = 4;
	y += 4;//poravnava sliderja na sredino èrke
	x += zeroX;//zamik 4 crke - 4*16

	set_mode_color(mode);
	//myGLCD.setFont(Sinclair_M);
	myGLCD.setBackColor(back_color[0], back_color[1], back_color[2]);

	myGLCD.print(sValue+":", x+45, y+20 );

	sValue = "  ";
	String intToString = String(value);

	for (int x = 0; x < intToString.length(); x++)//TODO:temp fix, uporabi kazalce
	{
		if (x>2)
		break;
		sValue[x] = intToString[x];
	}

	//	myGLCD.setFont(arial_normal);
	myGLCD.print(sValue, x , y+20);
	

	//myGLCD.print(F("- 40"), x + 220+50, y);
#endif
}

void draw_text(int x, int y, String value, String text){
	myGLCD.setFont(arial_bold);
	//int heigth = 225;
	x += zeroX;
	//x += 270;

	set_mode_color(ACTION_SELECT_COLOR);
	myGLCD.print(text, x, y, 0);
	myGLCD.print(F("   "), x + 80, y, 0);
	myGLCD.print((String)value, x + 80, y, 0);

}
void draw_text(int x, int y, String value, String text, byte font,byte mode){

	
	if(mode!=ACTION_CLEAR_COLOR)
	set_mode_color(ACTION_REDRAW_COLOR);
	else
	set_mode_color(mode);
	
	//int heigth = 225;
	x += zeroX;
	//x += 270;


	myGLCD.setFont(arial_bold);

	myGLCD.print(F("SOFTWARE INFO:") , x, y, 0);
	myGLCD.setFont(arial_normal);

	y = y + 30;
	myGLCD.print(F("ACCENT ORGANS") , x, y, 0);
	myGLCD.print(F("SERIAL NUMBER:000023"), x, y + 20, 0);
	myGLCD.print(F("SW INFO: V1.687"), x, y + 40, 0);
	myGLCD.print(F("REL DATE: 3.4.2018"), x, y + 60, 0);
	//myGLCD.print((String)__DATE__, x+100, y + 60, 0);
	
}

void call_item_mode(MenuItem* p_menu_item, byte mode)
{


	switch  (p_menu_item->get_type())
	{
		//case type_button:
		//drawButtonSelect(p_menu_item, mode);
		//break;
		case type_boolean_slider:
		drawBooleanLabel(p_menu_item, 1, mode);
		break;
		
		case type_BASIC_value_label:
		drawSlider_type_BASIC_value_label(p_menu_item, 1, mode);
		break;
		
		case type_BASIC_slider_with_negative_value:
		drawSlider_negative_single_label(p_menu_item, 1, mode);
		break;
		
		case type_BASIC_slider_with_value :
		drawSlider_double_label(p_menu_item, 1, mode);
		break;
		
		case type_selector:
		drawSelector(p_menu_item, p_menu_item->get_x(), p_menu_item->get_y(), p_menu_item->get_name(), p_menu_item->get_name(), 100, 0, 127, mode);
		break;
		
		case type_slider_volume:
		drawSlider(p_menu_item, 20, mode);
		break;
		
		case type_label_info:
		drawLabelInfo(p_menu_item, MASTER_VOLUME, mode);
		break;
		
		//case type_label:
		//drawLabel(p_menu_item,p_menu_item->getValue(), mode);
		//break;
		//
		case type_big_label:
		if(ms.is_root())
		drawBigLabel(p_menu_item, MASTER_VOLUME, mode);
		break;
		
		case type_tiny_label:
		drawTinyLabel(p_menu_item, MASTER_VOLUME, mode);
		break;
		
		case type_slider_equ_gain:
		drawslider_equalizer_gain(p_menu_item, mode);
		break;
		
		case type_slider_equ_freq:
		drawslider_equalizer_freq(p_menu_item, mode);
		break;
		
		case type_slider_equ_Q:
		drawslider_equalizer_Q(p_menu_item, mode);
		break;
		
		case type_style_selector:
		draw_style_selector(p_menu_item, mode);
		break;
		
		case type_mem_bank_selector:
		draw_mem_bank_selector(p_menu_item, mode);
		
		break;
		
		case type_hist_selector:
		draw_hist_selector(p_menu_item, mode);
		break;
		
		case type_tiny_text:
		draw_text(p_menu_item->get_x(), p_menu_item->get_y(), "", p_menu_item->get_name(), 1, mode);
		break;
		
		//case type_normal_text:
		//draw_text(p_menu_item->get_x(), p_menu_item->get_y(), "", p_menu_item->get_name(), 0, mode);
		//break;
		
		case type_stop_selector:
		draw_stop_selector(p_menu_item, mode);
		break;
		
		case type_RGB_slider:
		drawRGBselector(p_menu_item, mode);
		break;
		
		case  type_custom_value_slider:
		drawCustomValueSlider(p_menu_item, mode);
		break;
		
		case  type_theme_selector:
		draw_theme_selector(p_menu_item, mode);
		break;
		
		case  type_REC_buttn:
		draw_RECORD_buttn(p_menu_item, mode);
		break;
		
		case  type_REC_file_selector:
		draw_REC_FILE_selector(p_menu_item, mode);
		break;
		
		case  type_Timer:
		draw_timer(p_menu_item, mode);
		break;
		
		case  type_PLAY_buttn:
		draw_PLAY_buttn(p_menu_item, mode);
		break;
		
		case  type_PLAY_file_selector:
		draw_PLAY_FILE_selector(p_menu_item, mode);
		break;
		
		case  type_play_Timer:
		draw_play_timer(p_menu_item, mode);
		break;
		
		case type_tuning_cent:
		drawSlider_tune_cents(p_menu_item, 1, mode);
		break;
		
		case type_swell_calibration:
		draw_calibr_buttn(p_menu_item, mode);
		break;
		
		case type_mainscreen_labels:
		draw_main_screen_background(p_menu_item, mode);
		break;
		
		case type_tone_selector:
		draw_tone_selector(p_menu_item, mode);
		break;
		
		case type_FILE_sd_selector:
		draw_FILE_SD_selector(p_menu_item, mode);
		break;
		
		case type_FILE_INTERNAL_selector:
		draw_FILE_INTERNAL_selector(p_menu_item, mode);
		break;
		
		case type_save_buttn:
		draw_SAVE_BUTTN_selector(p_menu_item, mode);
		break;
		
		case type_LOAD_buttn:
		draw_LOAD_BUTTN_selector(p_menu_item, mode);
		break;
	}




	
	
}


void on_item_select(MenuItem* p_menu_item,byte id_mode)
{
	switch (id_mode)
	{
		case ON_SELECT:
		call_item_mode(p_menu_item, ACTION_SELECT_COLOR);
		break;
		
		case ON_DRAW_ENABLED:
		call_item_mode(p_menu_item, ACTION_EDITING_COLOR);
		break;
		
		case ON_DRAW_DISABLED:
		call_item_mode(p_menu_item, ACTION_REDRAW_COLOR);
		break;
		
		case ON_CLEAR:
		call_item_mode(p_menu_item, ACTION_CLEAR_COLOR);
		break;
		
		case ON_FIRST_DRAW:
		call_item_mode(p_menu_item, ACTION_FIRST_DRAW);
		break;
		
	}
	
}

void on_item_draw_enabled(MenuItem* p_menu_item)
{
	call_item_mode(p_menu_item, ACTION_EDITING_COLOR);
}

void on_item_draw_disabled(MenuItem* p_menu_item)
{
	call_item_mode(p_menu_item, ACTION_REDRAW_COLOR);

}
void on_item_clear(MenuItem* p_menu_item)
{
	call_item_mode(p_menu_item, ACTION_CLEAR_COLOR);
}


void on_menu_selected(Menu* p_menu,byte id_mode)
{
	switch (id_mode)
	{
		case ON_SELECT:
		if (p_menu->get_type() == type_menu)
		drawButtonMenu(p_menu, ACTION_SELECT_COLOR);
		if(p_menu->get_name_id()==NUM_PLAY_menu)
		{
			SD_work.sd_files_refresh();
		}
		break;
		
		case ON_DRAW_ENABLED:
		drawButtonMenu(p_menu, ACTION_EDITING_COLOR);
		break;
		
		case ON_DRAW_DISABLED:
		drawButtonMenu(p_menu, ACTION_REDRAW_COLOR);
		break;
		
		case ON_CLEAR:
		drawButtonMenu(p_menu, ACTION_CLEAR_COLOR);
		break;
		
		case ON_FIRST_DRAW:
		DEBUG_STRING_println("FIRST DRAW!!!!");
		drawButtonMenu(p_menu, ACTION_FIRST_DRAW);
		break;
		
		
		
	}
	
	//myGLCD.fillScr(back_color[0], back_color[1], back_color[2]);
}


void on_menu_draw_enabled(Menu* p_menu)
{
	drawButtonMenu(p_menu, ACTION_EDITING_COLOR);
}

void on_menu_draw_disabled(Menu* p_menu)
{
	drawButtonMenu(p_menu, ACTION_REDRAW_COLOR);
}

void on_menu_clear(Menu* p_menu)
{
	drawButtonMenu(p_menu, ACTION_CLEAR_COLOR);
}



extern unsigned int Anton_Skrabl[];


int temp_var = 0;
byte temp_vol = 0;
byte gas1_tmp = 0;
byte gas2_tmp = 0;
int princValue = 50;
bool first = true;

bool redraw = true;
bool direction = true;
int nav_direction_old = -1;

int currentLevel = -1;
int knobEnterStateOld = 1;
int knobBackStateOld = 1;

int buttonState_enter = 0;         // current state of the button
int lastButtonState_enter = 0;     // previous state of the button

int buttonState_back = 0;         // current state of the button
int lastButtonState_Back = 0;     // previous state of the button

int knob_old = -10;
Encoder knob(ENCODER_PIN_1, ENCODER_PIN_2);




void menu_mgr::check_reverb(String string_name, byte tempVar)
{
	
	byte midi_out=MIDI_1;
	bool send = false;
	
	
	switch (ms.get_selected1()->getMemAddress())
	{
		case add_VALUE_reverb_type:
		if (tempVar > 7)
		tempVar = 7;
		//ms.get_selected1()->setValue(tempVar);
		send = true;

		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x30);
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_reverb_time_ms), 0x34);
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_pre_LPF), 0x32);

		delay(2000);
		
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_characterI), 0x32);
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_REVERB), 0x33);
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_predelay_time), 0x37);
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_delay_send), 0x5B);
		break;
		
		case add_VALUE_reverb_type_II:
		if (tempVar > 7)
		tempVar = 7;
		//ms.get_selected1()->setValue(tempVar);
		send = true;

		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x30);
		MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_reverb_time_ms), 0x34);
		MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_pre_LPF), 0x32);

		delay(2000);
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_characterII), 0x32);
		MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_REVERB), 0x33);
		MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_predelay_time), 0x37);
		MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_delay_send), 0x5B);
		break;
		
		case add_VALUE_pre_LPF:
		
		if (tempVar > 7)
		tempVar = 7;
		//ms.get_selected1()->setValue(tempVar);
		send = true;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x32);
		break;
		
		case add_VALUE_pre_LPF_II:
		if (tempVar > 7)
		tempVar = 7;
		//ms.get_selected1()->setValue(tempVar);
		send = true;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x32);
		break;
		
		case add_VALUE_REVERB:
		send = true;
		temp_var = temp_var * 2;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x33);
		break;
		
		case add_VALUE_REVERB_II:
		send = true;
		temp_var = temp_var * 2;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x33);
		break;
		
		case add_VALUE_reverb_time_ms:
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x34);
		
		break;
		case add_VALUE_reverb_time_ms_II:
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x34);
		
		break;
		case add_VALUE_delay_feedback:
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x35);
		break;
		
		case add_VALUE_delay_feedback_II:
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x35);
		break;
		
		case add_VALUE_predelay_time:
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x37);
		break;
		
		case add_VALUE_predelay_time_II:
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x37);
		break;
		
		case add_VALUE_delay_send:
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x5B);
		break;
		
		case add_VALUE_delay_send_II:
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x5B);
		break;
		
		case add_VALUE_characterI:
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x31);
		break;
		
		case add_VALUE_characterII:
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x31);
		break;
		
		
		
		
	}
	
	

	

	send = false;
	if (send)
	{
		if(midi_out==MIDI_1)
		{
			
			MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_reverb_type), 0x30);
			MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_pre_LPF), 0x32);
			MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_REVERB), 0x33);
			MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_reverb_time_ms), 0x34);
			//Z_S_mgr.send_reverb(EEPROM.read(add_VALUE_delay_feedback), 0x35);
			MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_predelay_time), 0x37);
			MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_delay_send), 0x5B);
		}
		if(midi_out==MIDI_2)
		{
			
			MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_reverb_type_II), 0x30);
			MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_pre_LPF_II), 0x32);
			MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_REVERB_II), 0x33);
			MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_reverb_time_ms_II), 0x34);
			//Z_S_mgr.send_reverb(EEPROM.read(add_VALUE_delay_feedback), 0x35);
			MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_predelay_time_II), 0x37);
			MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_delay_send_II), 0x5B);
		}
		
	}

	//
	byte midi_ch;
	byte tmp1;
	
	switch (ms.get_selected1()->get_name_id())
	{
		case NUM_tremulant1:
		MIDI_sender.send_MIDI_test(TEST_A,tempVar,1);
		return;
		MIDI_sender.send_tremulant_key(tempVar, STOP_mgr.id(0), true, MANUAL_2, true);
		break;
		
		case NUM_tremulant1_depth:
		MIDI_sender.send_MIDI_test(TEST_B,tempVar,1);
		return;
		MIDI_sender.send_tremulant_key(tempVar, STOP_mgr.id(0), true, MANUAL_2, true);
		break;
		
		case NUM_TEST_A:
		MIDI_sender.send_MIDI_test(TEST_A,tempVar,1);
		break;
		
		case NUM_TEST_B:
		MIDI_sender.send_MIDI_test(TEST_B,tempVar,1);
		break;
		
		case NUM_TEST_C:
		MIDI_sender.send_MIDI_test(TEST_C,tempVar,1);
		break;
		
		case NUM_TEST_D:
		MIDI_sender.send_MIDI_test(TEST_D,tempVar,1);
		break;
		
		case NUM_LEFT:
		tmp1=menu_b1_PAN_stop_select.getValue();
		if(tmp1>=43)
		tmp1-=43;
		
		midi_ch=	STOP_mgr.id(tmp1)->get_MIDI_CH();
		midi_out=	STOP_mgr.id(tmp1)->get_MIDI_out_numb();
		MIDI_sender.send_MIDI_code(CODE_PAN,tempVar,midi_ch,midi_out);
		break;
		
		case NUM_LEVEL:
		tmp1=menu_b1_PAN_stop_select.getValue();
		if(tmp1>=43)
		tmp1-=43;
		
		midi_ch=	STOP_mgr.id(tmp1)->get_MIDI_CH();
		midi_out=	STOP_mgr.id(tmp1)->get_MIDI_out_numb();
		MIDI_sender.send_MIDI_code(CODE_STOP_VOL,tempVar,midi_ch,midi_out);
		
		break;
		
		case NUM_TVF_RESONANCE:

		midi_ch=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_CH();
		midi_out=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_out_numb();
		MIDI_sender.send_MIDI_code(CODE_TVF_RESONANCE,tempVar,midi_ch,midi_out);
		break;
		
		case NUM_TVF_CUTOFF:
		
		midi_ch=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_CH();
		midi_out=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_out_numb();
		MIDI_sender.send_MIDI_code(CODE_TVF_CUTOFF,tempVar,midi_ch,midi_out);
		break;
		
		
		
	}

	return;

	//////////


	if (ms.get_selected1()->getMemAddress()==add_VALUE_reverb_type)//TODO: temp fix
	{
		if (tempVar > 7)
		tempVar = 7;
		ms.get_selected1()->setValue(tempVar);
		send = true;

		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x30);
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_reverb_time_ms), 0x34);
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_pre_LPF), 0x32);

		delay(2000);
		
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_characterI), 0x32);
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_REVERB), 0x33);
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_predelay_time), 0x37);
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_delay_send), 0x5B);
		
		
	}
	else if (ms.get_selected1()->getMemAddress()==add_VALUE_reverb_type_II)//TODO: temp fix
	{
		if (tempVar > 7)
		tempVar = 7;
		ms.get_selected1()->setValue(tempVar);
		send = true;

		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x30);
		MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_reverb_time_ms), 0x34);
		MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_pre_LPF), 0x32);

		delay(2000);
		MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_characterII), 0x32);
		MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_REVERB), 0x33);
		MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_predelay_time), 0x37);
		MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_delay_send), 0x5B);
		
		
	}

	else if (ms.get_selected1()->getMemAddress()==add_VALUE_pre_LPF)//TODO: temp fix
	{
		if (tempVar > 7)
		tempVar = 7;
		ms.get_selected1()->setValue(tempVar);
		send = true;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x32);

	}
	else if (ms.get_selected1()->getMemAddress()==add_VALUE_pre_LPF_II)//TODO: temp fix
	{
		if (tempVar > 7)
		tempVar = 7;
		ms.get_selected1()->setValue(tempVar);
		send = true;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x32);

	}


	else if (ms.get_selected1()->getMemAddress()==add_VALUE_REVERB)//TODO: temp fix
	{
		send = true;
		temp_var = temp_var * 2;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x33);

	}
	else if (ms.get_selected1()->getMemAddress()==add_VALUE_REVERB_II)//TODO: temp fix
	{
		send = true;
		temp_var = temp_var * 2;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x33);

	}

	else if (ms.get_selected1()->getMemAddress()==add_VALUE_pre_LPF)//TODO: temp fix
	{
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x34);

		
	}else if (ms.get_selected1()->getMemAddress()==add_VALUE_pre_LPF_II)//TODO: temp fix
	{
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x34);

		
	}

	else if (ms.get_selected1()->getMemAddress()==add_VALUE_delay_feedback)//TODO: temp fix
	{
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x35);

	}
	else if (ms.get_selected1()->getMemAddress()==add_VALUE_delay_feedback_II)//TODO: temp fix
	{
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x35);

	}

	else if (ms.get_selected1()->getMemAddress()==add_VALUE_predelay_time)//TODO: temp fix
	{
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x37);

	}
	else if (ms.get_selected1()->getMemAddress()==add_VALUE_predelay_time_II)//TODO: temp fix
	{
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x37);

	}

	else if (ms.get_selected1()->getMemAddress()==add_VALUE_delay_send)//TODO: temp fix
	{
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x5B);
	}
	else if (ms.get_selected1()->getMemAddress()==add_VALUE_delay_send_II)//TODO: temp fix
	{
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x5B);
	}
	else if (ms.get_selected1()->getMemAddress()==add_VALUE_characterI)//TODO: temp fix
	{
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_1,tempVar, 0x31);
	}
	else if (ms.get_selected1()->getMemAddress()==add_VALUE_characterII)//TODO: temp fix
	{
		temp_var = temp_var * 2;
		send = true;
		MIDI_sender.send_reverb(MIDI_2,tempVar, 0x31);
	}


	send = false;
	if (send)
	{
		if(midi_out==MIDI_1)
		{
			
			MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_reverb_type), 0x30);
			MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_pre_LPF), 0x32);
			MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_REVERB), 0x33);
			MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_reverb_time_ms), 0x34);
			//Z_S_mgr.send_reverb(EEPROM.read(add_VALUE_delay_feedback), 0x35);
			MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_predelay_time), 0x37);
			MIDI_sender.send_reverb(MIDI_1,EEPROM.read(add_VALUE_delay_send), 0x5B);
		}
		if(midi_out==MIDI_2)
		{
			
			MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_reverb_type_II), 0x30);
			MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_pre_LPF_II), 0x32);
			MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_REVERB_II), 0x33);
			MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_reverb_time_ms_II), 0x34);
			//Z_S_mgr.send_reverb(EEPROM.read(add_VALUE_delay_feedback), 0x35);
			MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_predelay_time_II), 0x37);
			MIDI_sender.send_reverb(MIDI_2,EEPROM.read(add_VALUE_delay_send_II), 0x5B);
		}
		
	}


	if (ms.get_selected1()->get_name_id() == NUM_tremulant1)//TODO: temp fix
	{
		//MIDI_sender.send_MIDI_TREMULANT(1,1,MANUAL_2);
		//return;
		MIDI_sender.send_MIDI_test(TEST_A,tempVar,1);
		return;
		MIDI_sender.send_tremulant_key(tempVar, STOP_mgr.id(0), true, MANUAL_2, true);
	}
	if (ms.get_selected1()->get_name_id() == NUM_tremulant1_depth)//TODO: temp fix
	{
		//MIDI_sender.send_MIDI_TREMULANT(1,1,MANUAL_2);
		//return;
		MIDI_sender.send_MIDI_test(TEST_B,tempVar,1);
		return;
		MIDI_sender.send_tremulant_key(tempVar, STOP_mgr.id(0), true, MANUAL_2, true);
	}
	if (ms.get_selected1()->get_name_id() == 255)//TODO: temp fix
	{
		MIDI_sender.send_tremulant_key(tempVar, STOP_mgr.id(0), true, MANUAL_3, true);
	}
	if (ms.get_selected1()->get_name_id() == NUM_TEST_A)//TODO: temp fix
	{
		MIDI_sender.send_MIDI_test(TEST_A,tempVar,1);
	}
	if (ms.get_selected1()->get_name_id() == NUM_TEST_B)//TODO: temp fix
	{
		MIDI_sender.send_MIDI_test(TEST_B,tempVar,1);
	}
	if (ms.get_selected1()->get_name_id() == NUM_TEST_C)//TODO: temp fix
	{
		MIDI_sender.send_MIDI_test(TEST_C,tempVar,1);
	}
	if (ms.get_selected1()->get_name_id() == NUM_TEST_D)//TODO: temp fix
	{
		MIDI_sender.send_MIDI_test(TEST_D,tempVar,1);
	}
	if (ms.get_selected1()->get_name_id() == NUM_LEFT)
	{
		
		byte midi_ch=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_CH();
		byte midi_out=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_out_numb();
		MIDI_sender.send_MIDI_code(CODE_PAN,tempVar,midi_ch,midi_out);
	}
	if (ms.get_selected1()->get_name_id() == NUM_LEVEL)
	{
		byte midi_ch=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_CH();
		byte midi_out=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_out_numb();
		MIDI_sender.send_MIDI_code(CODE_STOP_VOL,tempVar,midi_ch,midi_out);
	}
	if (ms.get_selected1()->get_name_id() == NUM_TVF_RESONANCE)
	{
		byte midi_ch=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_CH();
		byte midi_out=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_out_numb();
		MIDI_sender.send_MIDI_code(CODE_TVF_RESONANCE,tempVar,midi_ch,midi_out);
	}
	if (ms.get_selected1()->get_name_id() == NUM_TVF_CUTOFF)
	{
		byte midi_ch=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_CH();
		byte midi_out=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_out_numb();
		MIDI_sender.send_MIDI_code(CODE_TVF_CUTOFF,tempVar,midi_ch,midi_out);
	}
	if (ms.get_selected1()->get_name_id() == NUM_tone_selector)
	{
		byte midi_ch=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_CH();
		byte midi_out=	STOP_mgr.id(menu_b1_PAN_stop_select.getValue())->get_MIDI_out_numb();
		//MIDI_sender.send_MIDI_code(CODE_TVF_CUTOFF,tempVar,midi_ch,midi_out);
	}

}

void menu_mgr::send_startup_reverb(byte MIDI_out, byte tempVar)
{

	if(MIDI_out==MIDI_1)
	{
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_reverb_type), 0x30);
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_reverb_time_ms), 0x34);
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_pre_LPF), 0x32);
		delay(2000);
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_REVERB), 0x33);
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_predelay_time), 0x37);
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_delay_feedback), 0x35);
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_delay_send), 0x5B);
		//MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_characterI), 0x5B);
	}
	if(MIDI_out==MIDI_2)
	{
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_reverb_type_II), 0x30);
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_reverb_time_ms_II), 0x34);
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_pre_LPF_II), 0x32);
		delay(2000);
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_REVERB_II), 0x33);
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_predelay_time_II), 0x37);
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_delay_feedback_II), 0x35);
		MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_delay_send_II), 0x5B);
		//	MIDI_sender.send_reverb(MIDI_out,EEPROM.read(add_VALUE_characterII), 0x5B);
	}
}


void menu_mgr::resend_notes()
{

	
	for (int i = 0; i < 90; i++){
		if (G_bit(k_MAN_I_L,i)==true)
		{
			//int key, bool on_off, int manual, byte velocity
			//MIDI_sender.send_note_DREAM(i,note_on_off,stop->get_active_on_manual(),note_on_off);
			MIDI_sender.sendNote_MIDI_out(1,i,127,1,true);
			MIDI_sender.sendNote_MIDI_out(2,i,127,2,true);
			//	DEBUG_println(F("KEY "));
			//	DEBUG_println(i);
		}
		if (G_bit(k_MAN_II_L,i)==true)
		{
			//int key, bool on_off, int manual, byte velocity
			//MIDI_sender.send_note_DREAM(i,note_on_off,stop->get_active_on_manual(),note_on_off);
			MIDI_sender.sendNote_MIDI_out(3,i,127,2,true);
			MIDI_sender.sendNote_MIDI_out(4,i,127,2,true);
			//	DEBUG_println(F("KEY "));
			//	DEBUG_println(i);
		}
		if (G_bit(k_PED,i)==true)
		{
			//int key, bool on_off, int manual, byte velocity
			//MIDI_sender.send_note_DREAM(i,note_on_off,stop->get_active_on_manual(),note_on_off);
			MIDI_sender.sendNote_MIDI_out(1,i,127,2,true);
			//	DEBUG_println(F("KEY "));
			//	DEBUG_println(i);
		}
	}
}
void menu_mgr::resend_notes_with_on_off()
{

	
	for (int i = 0; i < 90; i++){
		if (G_bit(k_MAN_I_L,i)==true)
		{
			//int key, bool on_off, int manual, byte velocity
			//MIDI_sender.send_note_DREAM(i,note_on_off,stop->get_active_on_manual(),note_on_off);
			MIDI_sender.sendNote_MIDI_out(1,i,127,1,false);
			MIDI_sender.sendNote_MIDI_out(2,i,127,2,false);
			MIDI_sender.sendNote_MIDI_out(1,i,127,1,true);
			MIDI_sender.sendNote_MIDI_out(2,i,127,2,true);
			//	DEBUG_println(F("KEY "));
			//	DEBUG_println(i);
		}
		if (G_bit(k_MAN_II_L,i)==true)
		{
			//int key, bool on_off, int manual, byte velocity
			//MIDI_sender.send_note_DREAM(i,note_on_off,stop->get_active_on_manual(),note_on_off);
			MIDI_sender.sendNote_MIDI_out(3,i,127,2,false);
			MIDI_sender.sendNote_MIDI_out(4,i,127,2,false);
			MIDI_sender.sendNote_MIDI_out(3,i,127,2,true);
			MIDI_sender.sendNote_MIDI_out(4,i,127,2,true);
			//	DEBUG_println(F("KEY "));
			//	DEBUG_println(i);
		}
		if (G_bit(k_PED,i)==true)
		{
			//int key, bool on_off, int manual, byte velocity
			//MIDI_sender.send_note_DREAM(i,note_on_off,stop->get_active_on_manual(),note_on_off);
			MIDI_sender.sendNote_MIDI_out(1,i,127,2,false);
			MIDI_sender.sendNote_MIDI_out(1,i,127,2,true);
			//	DEBUG_println(F("KEY "));
			//	DEBUG_println(i);
		}
	}
}
byte _loc_prev_tone;
byte _loc_prev_stop;
byte _loc_prev_tone_volume;

void menu_mgr::display_menu()
{
	
	//int temp_vol = analogRead(MASTER_VOLUME_PIN);
	
	//temp_vol=map(temp_vol, 0, 1023, 0, 127);
	#ifdef CRESCENDO_PEDAL_DISPLAY
	if (GAS2_refresh)
	{
		menu_main_screen1_crescendo_slider.setValue(GAS_PED_2);//v vsakem primeru spremeni vrednost
		if (ms.is_root())
		{
			menu_main_screen1_crescendo_slider.draw_normal();
		}
		GAS2_refresh = false;
	}
	if (GAS2_ped_refresh)
	{
		menu_main_screen1_crescendo_slider.setValue(GAS_PED_man2);//v vsakem primeru spremeni vrednost
		if (ms.is_root())
		{
			menu_main_screen1_crescendo_slider.draw_normal();
		}
		GAS2_ped_refresh = false;
	}
	#endif

	if (GAS1_refresh)
	{
		menu_main_screen1_exp_ped__slider.setValue(GAS_PED_man2);//v vsakem primeru spremeni vrednost
		if (ms.is_root())
		{
			menu_main_screen1_exp_ped__slider.draw_normal();
		}
		GAS1_refresh = false;
	}

	if (MASTER_VOL_refresh)
	{
		temp_vol = MASTER_VOLUME;// map(temp_vol, 0, 1023, 0, 127);
		menu_main_screen1_volume.setValue(MASTER_VOLUME);//v vsakem primeru spremeni vrednost

		if (ms.is_root())
		{
			menu_main_screen1_volume.draw_normal();
		}
		MASTER_VOL_refresh = false;
	}

	if (ms.is_root())
	{
		

		if (COMBINATION_LABEL_FIRST_letter != COMBINATION_LABEL_FIRST_letter_old)
		{
			last_time_interacted_zecer=millis();
			//__FlashStringHelper* C_a2 = (__FlashStringHelper*)"wwww";
			//menu_main_screen1_zecer_label.clear_component();
			menu_main_screen1_zecer_label.draw_normal();
			//menu_main_screen1_zecer_label.temp_value = COMBINATION_LABEL_TEXT;
			//COMBINATION_LABEL_TEXT_old = COMBINATION_LABEL_TEXT;
			COMBINATION_LABEL_FIRST_letter_old = COMBINATION_LABEL_FIRST_letter;


			//menu_main_screen1_zecer_label.draw_normal();

		}
		if(COMBINATION_LABEL_FIRST_letter[0]=='0')//da reset zgine po 5 sekundah
		{
			DEBUG_println(millis()-last_time_interacted_zecer);
			if(millis()-last_time_interacted_zecer>5000)
			{
				COMBINATION_LABEL_FIRST_letter=" ";
				//DEBUG_STRING_println("bris bris");
			}
		}
		if (USER_ID != USER_ID_old)//traspose label
		{
			//__FlashStringHelper* C_a2 = (__FlashStringHelper*)"wwww";
			menu_main_screen1_zecer_LABEL_Z.clear_component();
			//menu_main_screen1_zecer_label.temp_value = COMBINATION_LABEL_TEXT;
			USER_ID_old=USER_ID;
			menu_main_screen1_zecer_LABEL_Z.draw_normal();

		}
		//if (TRANSPOSE_LABEL_TEXT != TRANSPOSE_LABEL_TEXT_old)//traspose label
		//{
		////__FlashStringHelper* C_a2 = (__FlashStringHelper*)"wwww";
		//menu_main_screen1_zecer_label_TRANSPOSE.clear_component();
		////menu_main_screen1_zecer_label.temp_value = COMBINATION_LABEL_TEXT;
		//TRANSPOSE_LABEL_TEXT_old = TRANSPOSE_LABEL_TEXT;
		//menu_main_screen1_zecer_label_TRANSPOSE.draw_normal();
		//
		//}
		//if (REVERB_LABEL_TEXT != REVERB_LABEL_TEXT_old)//traspose label
		//{
		////__FlashStringHelper* C_a2 = (__FlashStringHelper*)"wwww";
		//menu_main_screen1_zecer_label_TRANSPOSE.clear_component();
		////menu_main_screen1_zecer_label.temp_value = COMBINATION_LABEL_TEXT;
		//REVERB_LABEL_TEXT_old = REVERB_LABEL_TEXT;
		//menu_main_screen1_zecer_label_TRANSPOSE.draw_normal();
		//
		//}

	}
	else
	last_time_interacted_zecer=millis();
	//read button enter and back
	buttonState_enter = digitalRead2(ENCODER_PIN_ENTER);
	buttonState_back = digitalRead2(ENCODER_PIN_BACK);



	
	
	if(ZECER.id(BUTTN_SET_1)->GetState()==true&&ZECER.id(BUTTN_10_1)->GetState()==true&&ms.get_selected1()->get_name_id()==NUM_swell_calibration)
	{
		Z_S_mgr.calibrate_gas1_min(0);
		ms.get_selected1()->draw_selected();
		return;
	}
	else if(ZECER.id(BUTTN_SET_1)->GetState()==true&&ZECER.id(BUTTN_100_1)->GetState()==true&&ms.get_selected1()->get_name_id()==NUM_swell_calibration)
	{
		Z_S_mgr.calibrate_gas1_max(0);
		ms.get_selected1()->draw_selected();
		return;
	}


	if (buttonState_enter != lastButtonState_enter) {
		if (buttonState_enter == LOW) {
			if(ms.get_selected1()!=NULL&&ms.get_selected1()->get_name_id()==NUM_REC_buttn)
			{
				ms.get_selected1()->addValue(1);
				if(ms.get_selected1()->getValue()==3)
				ms.get_selected1()->setValue(0);
				
				ms.get_selected1()->draw_selected();

			}
			else if(ms.get_selected1()!=NULL&&ms.get_selected1()->get_name_id()==NUM_PLAY_buttn)
			{
				ms.get_selected1()->addValue(1);
				if(ms.get_selected1()->getValue()==2)
				ms.get_selected1()->setValue(0);
				
				ms.get_selected1()->draw_selected();
			}
			else
			{
				ms.select();
			}
			last_time_interacted=millis();
			
		}
		//	delay(20);
	}

	lastButtonState_enter = buttonState_enter;

	if (buttonState_back != lastButtonState_Back) {
		if (buttonState_back == LOW) {
			
			if (buttonState_enter == LOW) {//izpiši velocity na serial monitor
				
				#ifdef SET_KEYS
				print_note_velocity(Z_S_mgr.Stops_list[0]);
				#endif
				ms.select();
				last_time_interacted=millis();
				
			}

			if (ms.get_selected1() != NULL)
			{
				//ms.select();
			}
			if(ms.get_selected1()!=NULL&&ms.get_selected1()->get_name_id()==NUM_REC_buttn||ms.get_selected1()->get_name_id()==NUM_PLAY_buttn)
			{
				ms.next(1,false);
				last_time_interacted=millis();
			}
			else
			{
				ms.back();
				last_time_interacted=millis();
			}
			

		}
		//	delay(20);
	}
	if(ms.is_root()==false&&millis()-last_time_interacted>15000)
	{
		//	ms.reset();
		
		
		if(false==(ms.get_current_menu()->get_name_id()==NUM_REC_menu||ms.get_current_menu()->get_name_id()==NUM_PLAY_menu))//ignore play/rec meni
		{
			ms._p_curr_menu->clear_current_display();
			ms.refresh();
		}
		//while(ms.is_root()==false)
		{
			//	ms.back();
		}
		last_time_interacted=millis();
		
	}
	
	lastButtonState_Back = buttonState_back;

	byte id_temp_stop = -1;
	byte brisi_var = 10;
	bool cancel = false;
	bool write_wtop = true;
	//read encoder



	int enc_ticks=0;
	int tmp_val=0;
	tmp_val=knob.read();
	
	byte tmp_id_stop=255;
	bool refresh_send_tone=true;


	if(ms.get_current_menu()!=NULL&&ms.get_current_menu()->get_name_id()==NUM_intonation_menu)
	{
		
		if(STOP_mgr.CURRENT_stop!=STOP_mgr.PREV_stop)
		{
			
			exEEPROM.write(STOP_mgr.PREV_stop*200+MIDI_sender.LAST_sended_tone,menu_b1_tone_selector.getValue());

			
			
			STOP_mgr.PREV_stop=STOP_mgr.CURRENT_stop;
			menu_b1_PAN_stop_select.setValue(STOP_mgr.CURRENT_stop);
			
			if(ms.get_selected1()!=NULL&&ms.get_selected1()->get_name_id()==menu_b1_PAN_stop_select.get_name_id())
			menu_b1_PAN_stop_select.draw_selected();
			else
			menu_b1_PAN_stop_select.draw_normal();
			
			menu_b1_tone_selector.setValue(exEEPROM.read(STOP_mgr.CURRENT_stop*200+MIDI_sender.LAST_sended_tone));
			
			if(ms.get_selected1()!=NULL)
			{
				if(ms.get_selected1()->get_name_id()==NUM_tone_selector)
				{
					menu_b1_tone_selector.draw_first_time();
					menu_b1_tone_selector.draw_selected();
				}
			}
			else
			menu_b1_tone_selector.draw_normal();
		}
		
		if(MIDI_sender.PREV_tone!=MIDI_sender.LAST_sended_tone)
		{
			menu_b1_tone_selector.setValue(exEEPROM.read(STOP_mgr.CURRENT_stop*200+MIDI_sender.LAST_sended_tone));
			if(ms.get_selected1()!=NULL&&ms.get_selected1()->get_name_id()==NUM_tone_selector)
			{
				menu_b1_tone_selector.draw_selected();
			}
			else
			{
				menu_b1_tone_selector.draw_normal();
			}
			MIDI_sender.PREV_tone=MIDI_sender.LAST_sended_tone;
			refresh_send_tone=false;
		}
		
	}

	if (tmp_val > 3||tmp_val < -3)
	{
		
		//COMBINATION_LABEL_TEXT = ""+(String)test_counter++; //kao sprememba
		//COMBINATION_LABEL_FIRST_letter=test_counter;
		//COMBINATION_LABEL_TEXT1 = (String)test_counter;
		//	 terer = (String)test_counter;
		//COMBINATION_LABEL_TEXT = ""+22;

		//calculate_free_RAM(33);
		//if(ms.get_selected1()->get_type()==type_save_buttn||ms.get_selected1()->get_type()==type_LOAD_buttn)
		
		if (ms.get_selected1() != NULL&&(ms.get_selected1()->get_type()==type_save_buttn||ms.get_selected1()->get_type()==type_LOAD_buttn)==false)
		{
			
			last_time_interacted=millis();
			knob.write(tmp_val%4);
			enc_ticks=-1*(tmp_val/4);
			

			
			//Serial.print("+");
			
			//DEBUG_println(ms.get_selected1()->getValue());
			byte tmp_val=	ms.get_selected1()->getValue();
			
			if(false==(ms.get_selected1()->get_name_id()==NUM_REC_buttn||ms.get_selected1()->get_name_id()==NUM_PLAY_buttn))
			{
				ms.get_selected1()->addValue(enc_ticks);
			}
			else
			{
				//DEBUG_println(F("name:---------------------------------------------"));
				DEBUG_println(ms.get_selected1()->get_name_id());
			}
			
			
			if(tmp_val!=ms.get_selected1()->getValue())
			{
				tmp_val=	ms.get_selected1()->getValue();
				ms.get_selected1()->draw_selected();
				
				//if (ms.get_selected1()->get_name_id() == NUM_transpose)//TODO: temp fix da omejiš transpose
				if(ms.get_selected1()->get_name_id()==NUM_tone_selector)
				{
					//byte tmp_tone=	ms.get_selected1()->getValue();
					if(enc_ticks!=0)
					{
						calculate_free_RAM(999);
						byte stop_selected=menu_b1_PAN_stop_select.getValue();
						
						DEBUG_STRING_print("NOTE loc: ");
						DEBUG_println(STOP_mgr.CURRENT_stop*200+MIDI_sender.LAST_sended_tone);
						
						exEEPROM.write(STOP_mgr.CURRENT_stop*200+MIDI_sender.LAST_sended_tone,tmp_val);
						menu_b1_tone_selector.setValue(tmp_val);
						menu_b1_tone_selector.draw_selected();
						
						MIDI_sender.send_stop_notes_volume(STOP_mgr.CURRENT_stop,0x20);
						
						//MIDI_sender.mute_all_sounds();
						resend_notes_with_on_off();
					}
					
				}
				else
				if (ms.get_selected1()->getMemAddress() == add_VALUE_TRANSPOSE)//TODO: temp fix da omejiš transpose
				{
					DEBUG_println(value_TRANSPOSE);
					MIDI_sender.mute_all_sounds();
					value_TRANSPOSE = ms.get_selected1()->getValue();
					DEBUG_println(value_TRANSPOSE);
					//resend_notes();
					//for (int i = 0; i < 90; i++){
					//
					//S_bit(k_MAN_I_L,i,false);
					//S_bit(k_MAN_II_L,i,false);
					//S_bit(k_MAN_III_L,i,false);
					//S_bit(k_PED,i,false);
					//
					//}
					//dokler se FW ne zrihta
					MIDI_sender.refresh_notes();

				}else if (ms.get_selected1()->get_type() == type_slider_equ_gain || ms.get_selected1()->get_type() == type_slider_equ_freq || ms.get_selected1()->get_type() == type_slider_equ_Q)
				{
					MIDI_sender.equalizer_set(ms.get_selected1()->getMemAddress(), ms.get_selected1()->getValue());
				}
				
				else if (ms.get_selected1()->get_type() == type_hist_selector)
				{

					MIDI_sender.change_style(tmp_val);
				}
				else if(ms.get_selected1()->get_type() == type_PLAY_file_selector)
				{
					return;
					ms.get_selected1()->addValue(enc_ticks);
					
					bool checker=false;
					File chc_file;
					
					while(checker)
					{
						//DEBUG_print(F("TUKI NESME PRIDIT "));
						//DEBUG_println(ms.get_selected1()->getValue());
						if(ms.get_selected1()->getValue()>=SD_work.files_count)
						break;
						if(ms.get_selected1()->getValue()==0)
						break;
						if (!SD.exists(("/TRACKS/FILE_")+(String)ms.get_selected1()->getValue()+(".acc")))
						{
							ms.get_selected1()->addValue(enc_ticks);
							
						}
						else
						{
							checker=false;
						}
					}
					
				}

				else
				{
					//return;

					
					if(ms.get_selected1()->get_name_id()==NUM_reverb_type_||ms.get_selected1()->get_name_id()==NUM_reverb_type_II)
					{
						//ms.get_selected1()->setValue(tmp_val);
						set_mode_color(ACTION_SELECT_COLOR);
						myGLCD.setFont(arial_bold);
						myGLCD.print(F("WAIT 3 sec..."), 100,210);
					}
					
					check_reverb(ms.get_selected1()->get_name(), tmp_val);
					
					if(ms.get_selected1()->get_name_id()==NUM_reverb_type_||ms.get_selected1()->get_name_id()==NUM_reverb_type_II)
					{
						set_mode_color(ACTION_CLEAR_COLOR);
						myGLCD.setFont(arial_bold);
						myGLCD.print(F("WAIT 3 sec..."), 100,210);
					}
					
					set_mode_color(ACTION_EDITING_COLOR);
				}
				
			}
			
			
			
			return;
		}
		else
		{

			if(tmp_val < -3){
			ms.next(1, true);knob.write(tmp_val%4);last_time_interacted=millis();}
			else if(knob.read() > 3)
			{ms.prev(1, true);knob.write(tmp_val%4);last_time_interacted=millis();}
			
		}
		//knob.write(knob.read() - 4);
		
		


	}

	if(SD_work.get_is_recording())
	{
		menu_NUM_timer.draw_selected();
	}
	else if(SD_work.get_is_playing())
	{
		if(SD_work.read_send_midi_event()==false)
		{
			menu_PLAY_buttn.setValue(0);
			menu_PLAY_buttn.draw_normal();
		}
		
		menu_NUM_play_timer.draw_selected();
		//calculate_free_RAM(334);
	}
	
}