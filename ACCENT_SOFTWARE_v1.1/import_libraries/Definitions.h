// Definitions.h

#ifndef _DEFINITIONS_h
#define _DEFINITIONS_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif



#include "arduino2.h"

#define SetBit(data,y)    data |= (1 << y)
#define ClearBit(data,y)  data &= ~(1 << y)
#define BitVal(data,y) ( (data>>y) & 1)      /** Return Data.Y value   **/

//totter ukazi
#define OKTAV_SINGLE_NOTE 19
#define OKTAV_SUP_NOTE 20
#define OKTAV_SUB_NOTE 21
#define OKTAV_SUB_and_SUP_NOTE 22

#define MIDI_2 2
#define MIDI_2 2

#define MIDI_VOLUME 1
#define MIDI_MODULATION_MAN_I 2
#define MIDI_MANUAL_VOLUME 3
#define MIDI_VOLUME_man2 4
#define MIDI_MODULATION_MAN_II 5
#define MIDI_MODULATION_MAN_III 6
#define MIDI_MODULATION_MAN_II_depth 7

#define MIDI_PORT_1 1
#define MIDI_PORT_2 2

#define MIDI_CH_1 1
#define MIDI_CH_2 2
#define MIDI_CH_3 3
#define MIDI_CH_4 4
#define MIDI_CH_5 5
#define MIDI_CH_6 6
#define MIDI_CH_7 7
#define MIDI_CH_8 8
#define MIDI_CH_9 9
#define MIDI_CH_10 10
#define MIDI_CH_11 11
#define MIDI_CH_12 12
#define MIDI_CH_13 13
#define MIDI_CH_14 14
#define MIDI_CH_15 15
#define MIDI_CH_16 16



#define COMMON_MIDI_CH1 1
#define COMMON_MIDI_CH2 2
#define COMMON_MIDI_CH3 3
#define MIDI_1 1
#define MIDI_2 2
#define MIDI_3 3
#define MIDI_4 4

#define MANUAL_1 2
#define MANUAL_3 3
#define MANUAL_2 4
#define MANUAL_4 5
#define MANUAL_5 6

#define cmd_CH1 128
#define cmd_CH2 129
#define cmd_CH3 130
#define cmd_CH4 131
#define cmd_CH5 132
#define cmd_CH6 133

//TODO mogoèe je tule problem
//#ifdef SWAP_MAN3_to_MAN2
//#define MANUAL_3 2
//#define MANUAL_2 3
//#else
//#define MANUAL_3 3
//#define MANUAL_2 2
//#endif


#define PEDAL 1


#define ACTION_CLEAR_COLOR 0
#define ACTION_REDRAW_COLOR 1
#define ACTION_SELECT_COLOR 2
#define ACTION_EDITING_COLOR 3
#define ACTION_INFO_COLOR 4
#define ACTION_FIRST_DRAW 6

#define COLOR1 4
#define COLOR2 5


//ne spreminjaj, ker je ID odvisen od tabel za razmerja


#define BORDUN_16 0
#define PRINZIPAL_8 1
#define FLUTE_HARMONIQ 2
#define SALICIONAL 3
#define OKTAVE_4 4
#define SPITZFLOTE 5
#define QUINTE 6
#define PRINZIPAL_2 7
#define MIXTUR_5F 8
#define TROMPETE_8 9
#define CLARION_4 10
#define BORDUN_8 11
#define PRESTANT_4 12
#define ROHRFLOTE_4 13
#define QUINTE_m3 14
#define GEMSHORN_2 15
#define TERZE_m3 16
#define PICCOLO 17
#define SCHARF_3F 18
#define KRUMHORN 19
#define PORTUNAL_FLOTE  20
#define GAMBE 21
#define VOX_COELESTIS 22
#define GEIGEN_PRINZIPAL 23
#define TRAVERS_FLUTE 24
#define NASAT 25
#define FLAGEOLET 26
#define MIXTUR_4F 27
#define LARIGOT 28
#define FAGOTT 29
#define OBOE 30
#define TROMPETE_HARMONIQ 31
#define SCHALMEI 32
#define PRINZIPAL_BASS_16 33
#define SUBBASS_8 34
#define OKTAVBASS_8 35
#define BASSFLOTE_8 36
#define CHORALBASS_4  37
#define PEDAL_MIXTUR_2F 38
#define POSAUNE_16 39
#define TROMPETE_8_ped 40


#define head_BORDUN_16 43
#define head_PRINZIPAL_8 44
#define head_FLUTE_HARMONIQ 45
#define head_SALICIONAL 46
#define head_OKTAVE_4 47
#define head_SPITZFLOTE 48
#define head_QUINTE 49
#define head_PRINZIPAL_2 50
#define head_MIXTUR_5F 51
#define head_TROMPETE_8 52
#define head_CLARION_4 53
#define head_BORDUN_8 54
#define head_PRESTANT_4 55
#define head_ROHRFLOTE_4 56
#define head_QUINTE_m3 57
#define head_GEMSHORN_2 58
#define head_TERZE_m3 59
#define head_PICCOLO 60
#define head_SCHARF_3F 61
#define head_KRUMHORN 62
#define head_PORTUNAL_FLOTE  63
#define head_GAMBE 64
#define head_VOX_COELESTIS 65
#define head_GEIGEN_PRINZIPAL 66
#define head_TRAVERS_FLUTE 67
#define head_NASAT 68
#define head_FLAGEOLET 69
#define head_MIXTUR_4F 70
#define head_LARIGOT 71
#define head_FAGOTT 72
#define head_OBOE 73
#define head_TROMPETE_HARMONIQ 74
#define head_SCHALMEI 75
#define head_PRINZIPAL_BASS_16 76
#define head_SUBBASS_8 77
#define head_OKTAVBASS_8 78
#define head_BASSFLOTE_8 79
#define head_CHORALBASS_4  80
#define head_PEDAL_MIXTUR_2F 81
#define head_POSAUNE_16 82
#define head_TROMPETE_8_ped 83



#define II_I 41
#define II_PED 42
#define SUB_II 43
#define SUPER_II 44
#define SUPER_III 45
#define SUB_III 46
#define III_PED 47
#define III_II 48
#define III_I 49
#define I_PED 50
#define SUB_I 51
#define SUPER_I 52
#define TREMULANT_I 53
#define TREMULANT_II 54
#define EMPTY 55

#define sum_SUB 13
#define sum_SUP 12

#define type_NORMAL_STOP 66
#define type_COUPLER 67
#define type_SUBOKTAVA 68
#define type_SUPEROKTAVA 69
#define type_TREMULANT 70

#define typeB_SET 70
#define typeB_10 70
#define typeB_100 70
#define typeB_RESET 70

#define MIDI_II_I 0
#define MIDI_II_PED 1
#define MIDI_SUB_II 2
#define MIDI_SUPER_II 3
#define MIDI_SUPER_III 4
#define MIDI_SUB_III 5
#define MIDI_III_PED 6
#define MIDI_III_II 7
#define MIDI_III_I 8
#define MIDI_I_PED 9
#define MIDI_SUB_I 10
#define MIDI_SUPER_I 11
#define MIDI_TREMULANT_I 12
#define MIDI_TREMULANT_II 13

//TODO: temp fix- koda vezana na ID manubrija zaradi hitrejšega lociranja v polju// samo pri vezavah
#define NULL_address 200



#define SDK_MANUBRI 2
#define LED_MANUBRI 3
#define LDK_MANUBRI 4

#define class_NULL 53
#define class_SET 1
#define class_COMBINATION 2
#define class_PLUS 3
#define class_MINUS 4
#define class_FIX_COMBINATION_MAN_1 5
#define class_FIX_COMBINATION_MAN_2 10
#define class_FIX_COMBINATION_MAN_3 11
#define class_RESET 6
#define class_10 7
#define class_100 8
#define class_FOOT_LINK 12
#define class_ON_OFF 13

#define BUTTN_MANUAL_COMBINATION 9
#define BUTTN_dummy 0
#define class_FOOT_FIXED 12

//


#define ID_MIDI_1 1
#define ID_MIDI_2 2
#define ID_MIDI_3 3
#define ID_MIDI_1 4


#define MIDI_SW_1 1
#define MIDI_SW_2 2
#define MIDI_SW_3 3
#define MIDI_SW_4 4
//trojni totter v prihodnosti
#define MIDI_SW_5 5
#define MIDI_SW_6 6
///other definitions
#define  type_button 0
#define  type_BASIC_value_label 1
//#define  type_slider_stop_label 2
#define  type_BASIC_slider_with_value 3
#define  type_slider_volume 4
#define  type_selector 5
#define  type_label 6
#define  type_big_label 7
//#define  type_pipe 8
#define  type_label_info 9
#define  type_tiny_label 10
#define  type_buttn_symbol 11
#define  type_slider_volume_h 12
#define  type_BASIC_slider_with_negative_value 13
#define  type_slider_equ_gain 14
#define  type_slider_equ_freq 15
#define  type_slider_equ_Q 16
#define  type_style_selector 17
#define  type_tiny_text 18
//#define  type_normal_text 19
#define  type_hist_selector 20
#define  type_theme_selector 21
#define  type_mem_bank_selector 22
#define  type_stop_selector 23
#define  type_RGB_slider 24
#define  type_custom_value_slider 25
#define  type_REC_buttn 26
#define  type_PLAY_buttn 27
#define  type_PLAY_file_selector 28
#define  type_REC_file_selector 29
#define  type_Timer 30
#define  type_play_Timer 31
#define  type_tuning_cent 32
#define  type_swell_calibration 33
#define  type_mainscreen_labels 34
#define  type_tone_selector 35
#define  type_FILE_sd_selector 36
#define  type_FILE_INTERNAL_selector 37
#define  type_save_buttn 38
#define  type_LOAD_buttn 39
#define  type_boolean_slider 40






#define  type_menu 1
#define  type_menu_item 2

//addresi fixnih kombinacij in ostalega
#define ADD_filestrings 127740
#define add_gas1_min  4
#define add_gas1_max  8
#define add_gas2_min  12
#define add_gas2_max  16

#define add_vol_min  20
#define add_vol_max  24

//#define add_FIRST_COMB  520
//#define add_buttn_RESET  170
//#define add_buttn_PP  180
//#define add_buttn_P  190
//#define add_buttn_MF  200
//#define add_buttn_F  210
//#define add_buttn_FF  220
//#define add_buttn_T  3000

#define ADDRESS_ROOT  200
#define STOPS_START_ADDRESSES  3000

#define ADDRESS_note  990

#define JUST_INFO  9999

#define TRANS_adjust 6

#define add_VALUE_TRANSPOSE  30
#define add_VALUE_REVERB  31
#define add_VALUE_reverb_type  32
#define add_VALUE_pre_LPF  33
#define add_VALUE_SELECTED_USER  34
#define add_VALUE_reverb_time_ms  35
#define add_VALUE_delay_feedback  36
#define add_VALUE_predelay_time  37
#define add_VALUE_hist_temp  38
#define add_VALUE_tremulnat1  39
#define add_VALUE_tremulnat2  40
#define add_VALUE_tremulnat1_depth  41

#define add_VALUE_delay_send  42


#define add_VALUE_REVERB_II  44
#define add_VALUE_reverb_type_II  45
#define add_VALUE_pre_LPF_II  46
#define add_VALUE_master_level_II 47 //tole daj stran
#define add_VALUE_reverb_time_ms_II  48
#define add_VALUE_delay_feedback_II  49
#define add_VALUE_predelay_time_II  50
#define add_VALUE_delay_send_II  51
#define add_VALUE_characterI  56
#define add_VALUE_characterII  57

#define add_VALUE_testA  52
#define add_VALUE_testB  53
#define add_VALUE_testC  54
#define add_VALUE_testD  55



#define  ADD_menu_b1_equalizer_select  60

#define  ADD_menu_b1_equalizer_gain_low  61
#define  ADD_menu_b1_equalizer_band_freq_low_band_0_800  62
#define  ADD_menu_b1_equalizer_Q_low  63

#define  ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500  64
#define  ADD_menu_b1_equalizer_gain_low_mid  65
#define  ADD_menu_b1_equalizer_Q_low_mid  66

#define  ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700  67
#define  ADD_menu_b1_equalizer_gain_high_mid  68
#define  ADD_menu_b1_equalizer_Q_high_mid  69

#define  ADD_menu_b1_equalizer_band_freq_high_band_1000_5800  70
#define  ADD_menu_b1_equalizer_gain_high  71
#define  ADD_menu_b1_equalizer_Q_high  72

#define  ADD_menu_b1_equalizer_gain_low_II 73
#define  ADD_menu_b1_equalizer_band_freq_low_band_0_800_II  74
#define  ADD_menu_b1_equalizer_Q_low_II  75

#define  ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_II 76
#define  ADD_menu_b1_equalizer_gain_low_mid_II  77
#define  ADD_menu_b1_equalizer_Q_low_mid_II  78

#define  ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_II  79
#define  ADD_menu_b1_equalizer_gain_high_mid_II  80
#define  ADD_menu_b1_equalizer_Q_high_mid_II  81

#define  ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_II 82
#define  ADD_menu_b1_equalizer_gain_high_II  83
#define  ADD_menu_b1_equalizer_Q_high_II  84

#define  ADD_menu_b1_equalizer_gain_low_III 85
#define  ADD_menu_b1_equalizer_band_freq_low_band_0_800_III  86
#define  ADD_menu_b1_equalizer_Q_low_III  87

#define  ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_III 88
#define  ADD_menu_b1_equalizer_gain_low_mid_III  89
#define  ADD_menu_b1_equalizer_Q_low_mid_III  90

#define  ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III  91
#define  ADD_menu_b1_equalizer_gain_high_mid_III  92
#define  ADD_menu_b1_equalizer_Q_high_mid_III  93

#define  ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_III  94
#define  ADD_menu_b1_equalizer_gain_high_III  95
#define  ADD_menu_b1_equalizer_Q_high_III  96

#define  ADD_menu_b1_equalizer_gain_low_IV 97
#define  ADD_menu_b1_equalizer_band_freq_low_band_0_800_IV  98
#define  ADD_menu_b1_equalizer_Q_low_IV  99

#define  ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_IV 100
#define  ADD_menu_b1_equalizer_gain_low_mid_IV  101
#define  ADD_menu_b1_equalizer_Q_low_mid_IV  102

#define  ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_IV  103
#define  ADD_menu_b1_equalizer_gain_high_mid_IV  104
#define  ADD_menu_b1_equalizer_Q_high_mid_IV  105

#define  ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_IV  106
#define  ADD_menu_b1_equalizer_gain_high_IV  107
#define  ADD_menu_b1_equalizer_Q_high_IV  108

#define  ADD_menu_b1_PAN_stop_select  119
#define ADD_menu_b1_PAN_leftright 109
#define ADD_menu_b1_stop_level 110
#define ADD_menu_b1_tvf_resonance 111
#define ADD_menu_b1_tvf_cutoff 112
#define ADD_menu_hist_temp 113
#define ADD_menu_STYLE 114
#define ADD_menu_mem_bank 115
#define ADD_menu_b3_ROMANTIC 116
#define ADD_menu_b3_TUNING 117
#define ADD_menu_b3_EQUAL 118
#define ADD_menu_b8_organ 119
#define ADD_menu_b8_membankstatus 120
#define ADD_menu_b8_genvolume 121
#define ADD_menu_b8_theme_1 122
#define ADD_menu_b8_theme_R 123
#define ADD_menu_b8_theme_G 124
#define ADD_menu_b8_theme_B 125
#define ADD_menu_b1_man_I_lvl 126
#define ADD_menu_b1_man_II_lvl 127
#define ADD_menu_b1_man_PED_lvl 128

#define ADD_menu_selected_file_play 129
#define ADD_menu_timer 130
#define ADD_menu_tune_cents 131
#define ADD_menu_swell_cal 132
#define add_VALUE_REVERB_procent  133
#define add_TONE_SELECTOR  134
#define add_FILE_selector  135
#define add_FILE2_selector  136
#define add_FILE_selector_setter  137
#define add_FILE2_selector_setter  138
#define add_SWAP_KEYBOARD 139


#define BUTTN_DUMMY 0
#define BUTTN_1 1
#define BUTTN_2 2
#define BUTTN_3 3
#define BUTTN_4 4
#define BUTTN_5 5
#define BUTTN_6 6
#define BUTTN_7 7
#define BUTTN_8 8
#define BUTTN_9 9
#define BUTTN_10 10
#define BUTTN_11 11
#define BUTTN_12 12
#define BUTTN_13 13
#define BUTTN_14 14
#define BUTTN_15 15
#define BUTTN_16 16
#define BUTTN_17 17
#define BUTTN_18 18
#define BUTTN_19 19
#define BUTTN_20 20
#define BUTTN_21 21
#define BUTTN_22 22
#define BUTTN_23 23
#define BUTTN_24 24
#define BUTTN_25 25
#define BUTTN_26 26
#define BUTTN_27 27
#define BUTTN_28 28
#define BUTTN_29 29
#define BUTTN_30 30
#define BUTTN_31 31
#define BUTTN_32 32
#define COM_MAN_I_1 33
#define COM_MAN_I_2 34
#define COM_MAN_I_3 35
#define COM_MAN_I_4 36
#define COM_MAN_I_5 37
#define COM_MAN_I_6 38
#define COM_MAN_II_1 39
#define COM_MAN_II_2_ 40
#define COM_MAN_II_3 41
#define COM_MAN_II_4 42
#define COM_MAN_II_5 43
#define COM_MAN_II_6 44
#define COM_MAN_III_1 45
#define COM_MAN_III_2 46
#define COM_MAN_III_3 47
#define COM_MAN_III_4 48
#define COM_MAN_III_5 49
#define COM_MAN_III_6 50
#define BUTTN_SET_1 51
#define BUTTN_SET_2 52
#define BUTTN_SET_3 53
#define BUTTN_MINUS_1 54
#define BUTTN_MINUS_2 55
#define BUTTN_MINUS_3 56
#define BUTTN_PLUS_1 57
#define BUTTN_PLUS_2 58
#define BUTTN_PLUS_3 59
#define BUTTN_10_1 60
#define BUTTN_10_2 61
#define BUTTN_10_3 62
#define BUTTN_100_1 63
#define BUTTN_100_2 64
#define BUTTN_100_3 65
#define BUTTN_RESET_1 66
#define BUTTN_RESET_2 67
#define BUTTN_RESET_3 68
#define BUTTN_CR_foot 69
#define BUTTN_III_II_foot 70
#define BUTTN_III_I_foot 71
#define BUTTN_II_I_foot 72
#define BUTTN_III_PED_foot 73
#define BUTTN_II_PED_foot 74
#define BUTTN_I_PED_foot 75
#define BUTTN_Z_foot 76
#define BUTTN_PP_foot 77
#define BUTTN_P_foot 78
#define BUTTN_MF_foot 79
#define BUTTN_F_foot 80
#define BUTTN_FF_foot 81
#define BUTTN_T_foot 82
#define BUTTN_PLUS_foot 83
#define BUTTN_MINUS_foot 84
#define BUTTN_RESET_foot 85
#define BUTTN_BASS 86
#define BUTTN_MELODY 87


//#define noMEM 9999
//#define NOT_USED 200


#define noMEM 255
#define NOT_USED 200

#define on_buttn_combination_f 1
#define on_buttn_combination_deselect_f 2
#define on_buttn_SET_f 4
#define on_buttn_SET_deselect_f 5
#define on_buttn_MINUS_f 6
#define on_buttn_MINUS_deselect_f 7
#define on_buttn_PLUS_f 8
#define on_buttn_PLUS_deselect_f 9
#define on_buttn_10_f 10
#define on_buttn_10_deselect_f 11
#define on_buttn_100_f 12
#define on_buttn_100_deselect_f 13
#define on_buttn_RESET_f 14
#define on_buttn_RESET_deselect_f 15
#define on_foot_piston_f 16
#define on_foot_piston_deselect_f 17


#define TEST_A 1
#define TEST_B 2
#define TEST_C 3
#define TEST_D 4
#define CODE_PAN 5
#define CODE_STOP_VOL 6
#define CODE_TVF_RESONANCE 7
#define CODE_TVF_CUTOFF 8






//////////////////MENU DEFINITIONS




#define XXX 9999
#define M_MEN 1
#define M_ITM 2
#define M_ROT 0
#define M_DIS 3
#define M_SPECIAL_PLAY_REC 4
#define DEF_000 0
#define DEF_127 127
#define DEF_TICK 1
#define DEF_RNG_MIN 0
#define DEF_RNG_MAX 127


#define		 NUM_enter_menu	0
#define		 NUM_VOLUME_SLIDER	1
#define		 NUM_VOL_label	2
#define		 NUM_Z_COMBINATION	3
#define		 NUM_Setter_combination	4
#define		 NUM_transpose_1	5
#define		 NUM_transpose_label	6
#define		 NUM_MAIN_STATIC_LABEL	7
#define		 NUM_REVERB_VALUE	8
#define		 NUM_Z_LABEL	9
#define		 NUM_cr_ped	10
#define		 NUM_exp_ped_1	11
#define		 NUM_exp_ped	12
#define		 NUM_exp_ped_label	13
#define		 NUM_cr_ped_label	14
#define		 NUM_styles_menu	15
#define		 NUM_transpose_menu	16
#define		 NUM_hist_temperament_menu	17
#define		 NUM_EFFECT_menu	18
#define		 NUM_utility_menu	19
#define		 NUM_tremulant_menu	20
#define		 NUM_EQUALIZER_menu	21
#define		 NUM_mem_bank_menu	22
#define		 NUM_intonation_menu	23

#define		 NUM_transpose	24
#define		 NUM_hist_temperament_1	25
#define		 NUM_REVERB_1_menu	26
#define		 NUM_REVERB_2_menu	27
#define		 NUM_master_level	28
#define		 NUM_reverb_type_	29
#define		 NUM_pre_LPF	30
#define		 NUM_reverb_time_ms	31
#define		 NUM_predelay_time	32
#define		 NUM_delay_feedback	33
#define		 NUM_reverb_send	34
#define		 NUM_master_level_II	35
#define		 NUM_reverb_type_II	36
#define		 NUM_pre_LPF_II	37
#define		 NUM_reverb_time_ms_II	38
#define		 NUM_predelay_time_II	39
#define		 NUM_delay_feedback_II	40
#define		 NUM_reverb_send_II	41
#define		 NUM_tremulant1	42
#define		 NUM_tremulant1_depth	43
#define		 NUM_GAIN_LOW	44
#define		 NUM_band_freq_low_band_0_800	45
#define		 NUM_gain_Q_low	46
#define		 NUM_GAIN_LOW_MID	47
#define		NUM_band_freq_low_mid_band_0_2500	48
#define		NUM_EQ_SELECT	49
#define		NUM_equalizer_gain_high_mid	50
#define		NUM_equalizer_band_freq_high_mid_band_60_10700	51
#define		NUM_equalizer_gain_high	52
#define		NUM_band_freq_high_band_1000_5800	53
#define		NUM_gain_Q_high	54
#define		 NUM_STOP_SELECT_menu	55
#define		 NUM_STOP_SELECTOR	56
#define		 NUM_LEFT	57
#define		 NUM_LEVEL	58
#define		 NUM_TVF_RESONANCE	59
#define		 NUM_TVF_CUTOFF	60
#define		 NUM_hist_temperament	61
#define		 NUM_STYLE	62
#define		 NUM_mem_bank	63
#define		 NUM_ROMANTIC	64
#define		 NUM_TUNING	65
#define		 NUM_EQUAL	66
#define		 NUM_theme	67
#define		 NUM_about	68
#define		 NUM_organ	69
#define		 NUM_crescendo	70
#define		 NUM_gen_volume	71
#define		 NUM_white_black	72
#define		 NUM_RGB_R	73
#define		 NUM_RGB_G	74
#define		 NUM_RGB_B	75
#define		 NUM_en_us	76
#define		  NUM_TEST_A	77
#define		   NUM_TEST_B	78
#define		  NUM_TEST_C	79
#define		  NUM_TEST_D	80
#define		 NUM_reverb_character_I	81
#define		 NUM_reverb_character_II	82
#define		 NUM_root	83
#define		 NUM_MAN_I_EQU	84
#define		 NUM_MAN_II_EQU	85
#define		 NUM_EQU_HEADPHONES	86
#define		 NUM_EQU_SPEAKERS	87
#define		 NUM_MAN_I_EQU_HEADPHONES	88
#define		 NUM_MAN_II_EQU_HEADPHONES	89
#define		 NUM_PRESETS_menu 90
#define		 NUM_PRESETS 91
#define		NUM_MAN_I_LVL 92
#define		NUM_MAN_II_LVL 93
#define		NUM_MAN_PED_LVL 94
#define		NUM_STOPS_LVLS_menu 95
#define		NUM_REC_menu 96
#define		NUM_PLAY_menu 97
#define		NUM_REC_buttn 98
#define		NUM_PLAY_buttn 99
#define		NUM_PLAY_file 100
#define		NUM_REC_file 101
#define		NUM_REC_PLAY_menu 102
#define     NUM_timer 103
#define     NUM_play_timer 104
#define     NUM_tune_cent 105
#define     NUM_special 106
#define     NUM_swell_calibration 107
#define     NUM_calibration 108
#define     NUM_hw_pedal 109
#define     NUM_sw_pedal 110
#define     NUM_pos_pedal 111
#define     NUM_crescendo_pedal 112
#define     NUM_calibration_menu 113
#define     NUM_tone_selector 114
#define     NUM_save_load 115
#define     NUM_settings 116
#define     NUM_organist 117
#define     NUM_save_buttn_dialog 118
#define     NUM_load_buttn_dialog 119
#define     NUM_src_file 120
#define     NUM_dest_file 121
#define     NUM_src_file_setter 122
#define     NUM_dest_file_setter 123
#define     NUM_save_buttn_settings 124
#define     NUM_load_buttn_settings 125
#define     NUM_swap_keyboard 126

#define L_gape 23

#define L1_X 5
//#define L1_Y 3
#define L1_Y 5

#define L2_X 5
#define L2_Y L1_Y+L_gape
//#define L2_Y 28

#define L3_X 5
#define L3_Y L2_Y+L_gape
//#define L3_Y 53

#define L4_X 5
#define L4_Y L3_Y+L_gape
//#define L4_Y 78

#define L5_X 5
#define L5_Y L4_Y+L_gape
//#define L5_Y 103

#define L6_X 5
#define L6_Y L5_Y+L_gape
//#define L6_Y 128

#define L7_X 5
#define L7_Y L6_Y+L_gape
//#define L7_Y 153

#define L8_X 5
#define L8_Y L7_Y+L_gape
//#define L8_Y 178

#define L9_X 5
#define L9_Y L8_Y+L_gape
//#define L9_Y 203

#define L10_X 160
#define L10_Y L9_Y+L_gape
//#define L10_Y 228

#define L11_X 160
#define L11_Y L10_Y+L_gape
//#define L11_Y 128

#define L12_X 160
#define L12_Y L11_Y+L_gape
//#define L12_Y 148

#define B_GAPE 40

#define B1_X 5
#define B1_Y 3
//#define B1_Y 3
//
#define B2_X 5
#define B2_Y B1_Y+B_GAPE

#define B3_X 5
#define B3_Y B2_Y+B_GAPE

#define B4_X 5
#define B4_Y B3_Y+B_GAPE

#define B5_X 5
#define B5_Y B4_Y+B_GAPE

#define B6_X 5
#define B6_Y B5_Y+B_GAPE

#define B7_X 160
#define B7_Y B1_Y

#define B8_X 160
#define B8_Y B1_Y+B_GAPE

#define B9_X 160
#define B9_Y B2_Y+B_GAPE

#define B10_X 160
#define B10_Y B3_Y+B_GAPE

#define B11_X 160
#define B11_Y B4_Y+B_GAPE

#define B12_X 160
#define B12_Y B5_Y+B_GAPE
#define FALSE false
#define TRUE true
static const unsigned char menu_item_info[127][13] PROGMEM = {//object_type,name_id,x,y,type,address,enabled,range_midi_min,midi_max, slider_tick_speed, min_tick,max_tick,extra_parameter
	
	
	
	
	
	
	
	{M_DIS	,	 NUM_enter_menu	,	50	,	100	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	XXX	,	XXX	,	XXX	,	false},
	{M_DIS	,	 NUM_VOLUME_SLIDER	,	548	,	L1_Y+3	,	 type_slider_volume	,	XXX	,	FALSE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_DIS	,	 NUM_VOL_label	,	300	,	183	,	 type_tiny_label	,	XXX	,	FALSE	,	XXX	,	XXX	,	 XXX	,	XXX	,	XXX	,	false},
	{M_DIS	,	 NUM_Z_COMBINATION	,	15	,	60	,	 type_big_label	,	XXX 	,	FALSE	,	XXX	,	XXX	,	DEF_TICK	,	DEF_000	,	1000	,	false},
	{M_DIS	,	 NUM_Setter_combination	,	8	,	25	,	 type_label_info	,	XXX	,	FALSE	,	XXX	,	XXX	,	 XXX	,	XXX	,	XXX	,	false},
	{M_DIS	,	 NUM_transpose	,	8	,	180	,	 type_label_info	,	 XXX	,	FALSE	,	XXX	,	XXX	,	 XXX	,	XXX	,	XXX	,	false},
	{M_DIS	,	 NUM_transpose_label	,	170	,	180	,	 type_label_info	,	 add_VALUE_TRANSPOSE	,	TRUE	,DEF_000	,	12	,	DEF_TICK	,	DEF_000	,	12	,	false},
	{M_DIS	,	 NUM_MAIN_STATIC_LABEL	,	8	,	155	,	 type_mainscreen_labels	,	XXX	,	FALSE	,	XXX	,	XXX	,	 XXX	,	XXX	,	XXX	,	false},
	{M_DIS	,	 NUM_REVERB_VALUE	,	170	,	155	,	 type_label_info	,	 add_VALUE_REVERB_procent	,	TRUE	,	DEF_000	,	100	,	DEF_TICK	,	DEF_000	,	100	,	false},
	{M_DIS	,	 NUM_Z_LABEL	,	8	,	130	,	 type_label_info	,	XXX	,	FALSE	,	XXX	,	XXX	,	 XXX	,	XXX	,	XXX	,	false},
	{M_DIS	,	 NUM_cr_ped	,	510	,	 L1_Y + 128	,	 type_slider_volume	,	XXX	,	FALSE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_DIS	,	 NUM_exp_ped	,	495	,	 L1_Y + 128	,	 type_slider_volume	,	XXX	,	FALSE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_DIS	,	 NUM_exp_ped	,	515	,	 L1_Y + 128	,	 type_slider_volume	,	XXX	,	FALSE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_DIS	,	 NUM_exp_ped_label	,	270	,	163	,	 type_tiny_label	,	XXX	,	FALSE	,	XXX	,	XXX	,	 XXX	,	XXX	,	XXX	,	false},
	{M_DIS	,	 NUM_cr_ped_label	,	245	,	163	,	 type_tiny_label	,	 XXX	,	FALSE	,	XXX	,	XXX	,	 XXX	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_styles_menu	,	 B1_X	,	 B2_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_transpose_menu	,	 B3_X	,	 B3_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_hist_temperament_menu	,	 B4_X	,	 B4_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_EFFECT_menu	,	 B7_X	,	 B7_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_utility_menu	,	 B1_X	,	 B1_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_tremulant_menu	,	 B1_X	,	 B2_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_EQUALIZER_menu	,	 B11_X	,	 B11_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_mem_bank_menu	,	 B6_X	,	 B6_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_intonation_menu	,	 B12_X	,	 B12_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_ITM	,	 NUM_transpose	,	 B1_X	,	 B1_Y	,	 type_BASIC_slider_with_negative_value	,	 add_VALUE_TRANSPOSE	,	TRUE	,	0	,	12	,	DEF_TICK	,	0	,	12	,	false},
	{M_ITM	,	 NUM_hist_temperament	,	 B1_X	,	 B1_Y	,	 type_BASIC_slider_with_negative_value	,	 add_VALUE_hist_temp	,	TRUE	,	0	,	22	,	DEF_TICK	,	0	,	22	,	false},
	{M_MEN	,	 NUM_REVERB_1_menu	,	 B1_X	,	 B1_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_REVERB_2_menu	,	 B1_X	,	 B2_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_ITM	,	 NUM_master_level	,	 L1_X	,	 L1_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_REVERB	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_reverb_type_	,	 L2_X	,	 L2_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_reverb_type	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_pre_LPF	,	 L3_X	,	 L3_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_pre_LPF	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_reverb_time_ms	,	 L4_X	,	 L4_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_reverb_time_ms	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_predelay_time	,	 L5_X	,	 L5_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_predelay_time	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_delay_feedback	,	 L6_X	,	 L6_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_delay_feedback	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_reverb_send	,	 L7_X	,	 L7_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_delay_send	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_master_level_II	,	 L1_X	,	 L1_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_REVERB_II	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_reverb_type_II	,	 L2_X	,	 L2_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_reverb_type_II	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_pre_LPF_II	,	 L3_X	,	 L3_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_pre_LPF_II	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_reverb_time_ms_II	,	 L4_X	,	 L4_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_reverb_time_ms_II	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	255	,	false},
	{M_ITM	,	 NUM_predelay_time_II	,	 L5_X	,	 L5_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_predelay_time_II	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_delay_feedback_II	,	 L6_X	,	 L6_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_delay_feedback_II	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_reverb_send_II	,	 L7_X	,	 L7_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_delay_send_II	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_tremulant1	,	 L2_X	,	 L2_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_tremulnat1	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_tremulant1_depth	,	 L3_X	,	 L3_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_tremulnat1_depth	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_GAIN_LOW	,	0	,	10	,	 type_slider_equ_gain	,	 ADD_menu_b1_equalizer_gain_low	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_band_freq_low_band_0_800	,	0	,	10	,	 type_slider_equ_freq	,	 ADD_menu_b1_equalizer_band_freq_low_band_0_800	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_gain_Q_low	,	80	,	10	,	 type_slider_equ_Q	,	 ADD_menu_b1_equalizer_Q_low	,	TRUE	,	DEF_000	,	126	,	DEF_TICK	,	DEF_000	,	126	,	false},
	{M_ITM	,	 NUM_GAIN_LOW_MID	,	80	,	10	,	 type_slider_equ_gain	,	ADD_menu_b1_equalizer_gain_low_mid	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	NUM_band_freq_low_mid_band_0_2500	,	80	,	10	,	 type_slider_equ_freq	,	ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500 	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_EQ_SELECT	,	5	,	10	,	 type_slider_equ_Q	,	 ADD_menu_b1_equalizer_select	,	TRUE	,	DEF_000	,	4	,	DEF_TICK	,	DEF_000	,	4	,	false},
	{M_ITM	,	NUM_equalizer_gain_high_mid	,	160	,	10	,	 type_slider_equ_gain	,	 ADD_menu_b1_equalizer_gain_high_mid	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	NUM_equalizer_band_freq_high_mid_band_60_10700	,	160	,	10	,	 type_slider_equ_freq	,	ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700 	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	NUM_equalizer_gain_high	,	240	,	10	,	 type_slider_equ_gain	,	ADD_menu_b1_equalizer_gain_high 	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	NUM_band_freq_high_band_1000_5800	,	240	,	10	,	 type_slider_equ_freq	,	ADD_menu_b1_equalizer_band_freq_high_band_1000_5800	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	NUM_gain_Q_high	,	160	,	10	,	 type_slider_equ_Q	,	 ADD_menu_b1_equalizer_Q_high	,	TRUE	,	DEF_000	,	126	,	DEF_TICK	,	DEF_000	,	126	,	false},
	{M_MEN	,	 NUM_STOP_SELECT_menu	,	 B1_X	,	 B1_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	 XXX	,	XXX	,	XXX	,	false},
	{M_ITM	,	 NUM_STOP_SELECTOR	,	 B1_X	,	 B1_Y	,	 type_stop_selector	,	 STOPS_START_ADDRESSES	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_LEFT	,	 L4_X	,	 L4_Y	,	 type_BASIC_slider_with_value	,	 ADD_menu_b1_PAN_leftright	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_LEVEL	,	 L5_X	,	 L5_Y	,	 type_BASIC_slider_with_value	,	 ADD_menu_b1_stop_level	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_TVF_RESONANCE	,	 L6_X	,	 L6_Y	,	 type_BASIC_slider_with_value	,	 ADD_menu_b1_tvf_resonance	,	TRUE	,	DEF_000	,	20	,	DEF_TICK	,	DEF_000	,	20	,	false},
	{M_ITM	,	 NUM_TVF_CUTOFF	,	 L7_X	,	 L7_Y	,	 type_BASIC_slider_with_value	,	 ADD_menu_b1_tvf_cutoff	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_hist_temperament	,	 L4_X	,	 L4_Y	,	 type_hist_selector	,	 ADD_menu_hist_temp	,	TRUE	,	DEF_000	,	22	,	DEF_TICK	,	DEF_000	,	22	,	false},
	{M_ITM	,	 NUM_STYLE	,	 B1_X	,	 B1_Y	,	 type_style_selector	,	 ADD_menu_STYLE	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_mem_bank	,	 B1_X	,	 B1_Y	,	 type_mem_bank_selector	,	 add_VALUE_SELECTED_USER	,	TRUE	,	DEF_000	,	8	,	DEF_TICK	,	DEF_000	,	8	,	false},
	{M_ITM	,	 NUM_ROMANTIC	,	 B1_X	,	 B2_Y	,	 type_button	,	 ADD_menu_b3_ROMANTIC	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_TUNING	,	 B3_X	,	 B3_Y	,	 type_button	,	 ADD_menu_b3_TUNING	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_MEN	,	 NUM_EQUAL	,	 B4_X	,	 B4_Y	,	 type_button	,	 ADD_menu_b3_EQUAL	,	TRUE	,	XXX	,	XXX	,	 XXX	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_theme	,	 B1_X	,	 B1_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	 XXX	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_about	,	 B8_X	,	 B8_Y 	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	 XXX	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_organ	,	 B4_X	,	 B4_Y	,	 type_BASIC_value_label	,	 ADD_menu_b8_organ	,	TRUE	,	XXX	,	XXX	,	 XXX	,	XXX	,	XXX	,	false},
	{M_ITM	,	 NUM_crescendo	,	 B5_X	,	 B5_Y	,	 type_BASIC_value_label 	,	ADD_menu_b8_membankstatus	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_gen_volume	,	 B6_X	,	 B6_Y	,	 type_BASIC_value_label	,	 ADD_menu_b8_genvolume	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_white_black	,	 L1_X	,	 L1_Y	,	 type_theme_selector	,	 ADD_menu_b8_theme_1	,	TRUE	,	DEF_000	,	4	,	DEF_TICK	,	DEF_000	,	4	,	false},
	{M_ITM	,	 NUM_RGB_R	,	 L5_X	,	 L5_Y+15	,	 type_RGB_slider	,	 ADD_menu_b8_theme_R	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_RGB_G	,	 L6_X	,	 L6_Y+15	,	 type_RGB_slider	,	 ADD_menu_b8_theme_G	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_RGB_B	,	 L7_X	,	 L7_Y+15	,	 type_RGB_slider	,	 ADD_menu_b8_theme_B	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_en_us	,	 B1_X	,	 B1_Y	,	 type_tiny_text	,	XXX	,	FALSE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	  NUM_TEST_A	,	 L3_X	,	 L3_Y	,	 type_BASIC_slider_with_negative_value	,	 ADD_menu_b8_theme_R	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	   NUM_TEST_B	,	 L4_X	,	 L4_Y	,	 type_BASIC_slider_with_negative_value	,	 ADD_menu_b8_theme_G	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	  NUM_TEST_C	,	 L5_X	,	 L5_Y	,	 type_BASIC_slider_with_negative_value	,	 ADD_menu_b8_theme_B	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	  NUM_TEST_D	,	 L6_X	,	 L6_Y	,	 type_BASIC_slider_with_negative_value	,	 ADD_menu_b8_theme_B	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_reverb_character_I	,	 L8_X	,	 L8_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_characterI	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_reverb_character_II	,	 L8_X	,	 L8_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_characterII	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_MEN	,	 NUM_root	,	10	,	10	,	XXX	,	XXX	,	FALSE	,	XXX	,	XXX	,	XXX	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_EQU_SPEAKERS	,	 B1_X	,	 B2_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_EQU_HEADPHONES	,	 B2_X	,	 B1_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_MAN_I_EQU	,	 B1_X	,	 B1_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_MAN_II_EQU	,	 B2_X	,	 B2_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_MAN_I_EQU_HEADPHONES	,	 B1_X	,	 B1_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_MAN_II_EQU_HEADPHONES	,	 B2_X	,	 B2_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_MEN	,	 NUM_PRESETS_menu	,	 B1_X	,	 B1_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_ITM	,	 NUM_PRESETS	,	 L1_X	,	 L1_Y	,	 type_BASIC_slider_with_value	,	 add_VALUE_characterII	,	TRUE	,	DEF_000	,	5	,	DEF_TICK	,	0,	5	,	false},
	{M_ITM	,	 NUM_MAN_I_LVL	,	 L2_X	,	 L2_Y	,	 type_custom_value_slider	,	 ADD_menu_b1_man_I_lvl	,	TRUE	,	DEF_000	,	120	,	DEF_TICK	,	10	,	120	,	false},
	{M_ITM	,	 NUM_MAN_II_LVL	,	 L3_X	,	 L3_Y	,	 type_custom_value_slider	,	 ADD_menu_b1_man_II_lvl	,	TRUE	,	DEF_000	,	120	,	DEF_TICK	,	10 ,	120	,	false},
	{M_ITM	,	 NUM_MAN_PED_LVL	,	 L1_X	,	 L1_Y	,	 type_custom_value_slider	,	 ADD_menu_b1_man_PED_lvl	,	TRUE	,	DEF_000	,	120	,	DEF_TICK	,	10	,	120	,	false},
	{M_MEN	,	 NUM_STOPS_LVLS_menu	,	 B6_X+70	,	 B6_Y-5	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	true},
	{M_MEN	,	 NUM_REC_menu	,	 B1_X	,	 B1_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	true},
	{M_MEN	,	 NUM_PLAY_menu	,	 B2_X	,	 B2_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	true},
	{M_SPECIAL_PLAY_REC	,	 NUM_REC_buttn	,	 L1_X	,	 L1_Y	,	 type_REC_buttn	,	 ADD_menu_selected_file_play	,	TRUE	,	DEF_000	,	4	,	DEF_TICK	,	DEF_000	,	4	,	false},
	{M_SPECIAL_PLAY_REC	,	 NUM_PLAY_buttn	,	 L1_X	,	 L1_Y	,	 type_PLAY_buttn	, ADD_menu_selected_file_play 	,	TRUE	,	DEF_000	,	4	,	DEF_TICK	,	DEF_000	,	4	,	false},
	{M_ITM	,	 NUM_PLAY_file	,	 L2_X	,	 L2_Y	,	 type_PLAY_file_selector	,	 ADD_menu_selected_file_play	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	255	,	false},
	{M_ITM	,	 NUM_REC_file	,	 L2_X	,	 L2_Y	,	 type_REC_file_selector	, ADD_menu_selected_file_play 	,	TRUE	,	DEF_000	,	5	,	DEF_TICK	,	DEF_000	,	5	,	false},
	{M_MEN	,	 NUM_REC_PLAY_menu	, B5_X	,	 B5_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	true},
	{M_ITM	,	 NUM_timer	,	 15	,	 150	,	 type_Timer	, ADD_menu_timer 	,	FALSE	,	DEF_000	,	127	,	DEF_TICK	,	DEF_000	,	127	,	false},
	{M_ITM	,	 NUM_play_timer	,	 170	,	 200	,	 type_play_Timer	, ADD_menu_timer 	,	FALSE	,	DEF_000	,	127	,	DEF_TICK	,	DEF_000	,	127	,	false},
	{M_ITM	,	 NUM_tune_cent	,	 L2_X	,	 L2_Y	,	 type_tuning_cent	, ADD_menu_tune_cents 	,	TRUE	,	DEF_000	,	30	,	DEF_TICK	,	DEF_000	,	30	,	false},
	{M_MEN	,	 NUM_special	,	 B3_X	,	 B3_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	true},
	{M_ITM	,	 NUM_swell_calibration	,	 L2_X	,	 L2_Y	,	 type_swell_calibration	, ADD_menu_swell_cal 	,	TRUE	,	DEF_000	,	4	,	DEF_TICK	,	DEF_000	,	4	,	false},
	{M_ITM	,	 NUM_calibration	,	 L2_X	,	 L2_Y	,	 type_swell_calibration	, ADD_menu_swell_cal 	,	TRUE	,	DEF_000	,	4	,	DEF_TICK	,	DEF_000	,	4	,	false},
	{M_MEN	,	 NUM_hw_pedal	,	 B1_X	,	 B1_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	true},
	{M_MEN	,	 NUM_sw_pedal	,	 B2_X	,	 B2_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	true},
	{M_MEN	,	 NUM_pos_pedal	,	 B3_X	,	 B3_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	true},
	{M_MEN	,	 NUM_crescendo_pedal	,	 B4_X	,	 B4_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	true},
	{M_MEN	,	 NUM_calibration_menu	, B8_X	,	 B8_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	false},
	{M_ITM	,	 NUM_tone_selector	, L8_X	,	 L8_Y	,type_tone_selector	,	 add_TONE_SELECTOR	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_MEN	,	 NUM_save_load	,	 B8_X	,	 B8_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	true},
	{M_MEN	,	 NUM_settings	,	 B9_X	,	 B9_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	true},
	{M_MEN	,	 NUM_organist	,	 B2_X	,	 B2_Y	,	XXX	,	XXX	,	TRUE	,	XXX	,	XXX	,	DEF_TICK	,	XXX	,	XXX	,	true},
	{M_ITM	,	 NUM_save_buttn_dialog	, B10_X	,	 B5_Y	,type_save_buttn	,	 add_TONE_SELECTOR	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_load_buttn_dialog	, B4_X,	 B5_Y	,type_LOAD_buttn	,	 add_TONE_SELECTOR	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_src_file	, B4_X	,	 B3_Y	,type_FILE_INTERNAL_selector	,	 add_FILE_selector	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_dest_file	, B4_X	,	 B2_Y	,type_FILE_sd_selector	,	 add_FILE2_selector	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_src_file_setter	, B4_X	,	 B4_Y	,type_FILE_INTERNAL_selector	,	 add_FILE_selector_setter	,	TRUE	,	1	,	9	,	DEF_TICK	,	1	,	9	,	false},
	{M_ITM	,	 NUM_dest_file_setter	, B4_X	,	 B5_Y	,type_FILE_sd_selector	,	 add_FILE2_selector_setter	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_save_buttn_settings	, B10_X	,	 B5_Y	,type_save_buttn	,	 add_TONE_SELECTOR	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_load_buttn_settings	, B4_X	,	 B5_Y	,type_LOAD_buttn	,	 add_TONE_SELECTOR	,	TRUE	,	DEF_000	,	DEF_127	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false},
	{M_ITM	,	 NUM_swap_keyboard	,	 L3_X	,	 L3_Y	,	 type_boolean_slider	, add_SWAP_KEYBOARD 	,	TRUE	,	DEF_000	,	1	,	DEF_TICK	,	DEF_000	,	1	,	false}




	//#define     NUM_save_buttn_dialog 118
	//#define     NUM_load_buttn_dialog 119
	//#define     NUM_save_buttn_settings 120
	//#define     NUM_load_buttn_settings 121
	//#define     NUM_src_file 122
	//#define     NUM_dest_file 123





	//{M_ITM	,	 NUM_PRESETS	,	 L1_X	,	 L1_Y	,	 type_slider_double_label	,	 add_VALUE_characterII	,	TRUE	,	DEF_000	,	5	,	DEF_TICK	,	DEF_000	,	5	,	false},






	//{M_DIS	,	 NUM_user_label	,	170	,	135	,	 type_label_info	,	 add_VALUE_TRANSPOSE	,	FALSE	,	 XXX	,	XXX	,	XXX	,	 XXX	,	XXX	,	false},
	//{M_DIS	,	 NUM_user_label_value_	,	170	,	135	,	 type_label_info	,	 add_VALUE_TRANSPOSE	,	FALSE	,	 XXX	,	XXX	,	XXX	,	 XXX	,	XXX	,	false}
	//			{M_ITM	,	 NUM_reverb_character_II	,	 L8_X	,	 L8_Y	,	 type_slider_double_label	,	 add_VALUE_characterII	,	TRUE	,	DEF_000	,	255	,	DEF_TICK	,	DEF_000	,	DEF_127	,	false}

};




#define HEAD_gain_low 127
#define HEAD_gain_low_mid 21
#define HEAD_gain_high_mid 89
#define HEAD_gain_high 13
#define HEAD_freq_low_band_0_800 33
#define HEAD_freq_low_mid_band_0_2500 127
#define HEAD_freq_high_mid__band_60_10700 127
#define HEAD_freq_high_band_1000_5800 56
#define HEAD_Q_low 16
#define HEAD_Q_high 0


#define HEAD_gain_low_II 127
#define HEAD_gain_low_mid_II 21
#define HEAD_gain_high_mid_II 89
#define HEAD_gain_high_II 13
#define HEAD_freq_low_band_0_800_II 33
#define HEAD_freq_low_mid_band_0_2500_II 127
#define HEAD_freq_high_mid__band_60_10700_II 127
#define HEAD_freq_high_band_1000_5800_II 56
#define HEAD_Q_low_II 16
#define HEAD_Q_high_II 0

#endif


