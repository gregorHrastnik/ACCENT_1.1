//
//
//

#include "Zecer_mgr.h"
#include "arduino2.h"
#include "global_methods.h"
#include "EEPROM.h"



void Zecer_mgr::link_id(byte stop_name, byte connect_to_id)//univerzalno vnašanje registrov, id v tabeli pridobi preko serial monitorja
{
	link_tab[connect_to_id] = stop_name;
	//_BUTTNS[stop_name]->_id_out = connect_to_id;
}

void Zecer_mgr::set_disposition(byte zecer_model)
{
	#ifdef ZECER_1X
	link_id(BUTTN_DUMMY, NOT_USED);
	link_id(BUTTN_1, 3);
	link_id(BUTTN_2, 2);
	link_id(BUTTN_3, 1);
	link_id(BUTTN_4, 0);
	link_id(BUTTN_5, 15);
	link_id(BUTTN_6, 14);
	link_id(BUTTN_7, 13);
	link_id(BUTTN_8, 12);
	link_id(BUTTN_9, 35);
	link_id(BUTTN_10, 34);
	link_id(BUTTN_11, 33);
	link_id(BUTTN_12, 32);
	link_id(BUTTN_13, 47);
	link_id(BUTTN_14, 46);
	link_id(BUTTN_15, 45);
	link_id(BUTTN_16, 44);
	link_id(BUTTN_17, NOT_USED);
	link_id(BUTTN_18, NOT_USED);
	link_id(BUTTN_19, NOT_USED);
	link_id(BUTTN_20, NOT_USED);
	link_id(BUTTN_21, NOT_USED);
	link_id(BUTTN_22, NOT_USED);
	link_id(BUTTN_23, NOT_USED);
	link_id(BUTTN_24, NOT_USED);
	link_id(BUTTN_25, NOT_USED);
	link_id(BUTTN_26, NOT_USED);
	link_id(BUTTN_27, NOT_USED);
	link_id(BUTTN_28, NOT_USED);
	link_id(BUTTN_29, NOT_USED);
	link_id(BUTTN_30, NOT_USED);
	link_id(BUTTN_31, NOT_USED);
	link_id(BUTTN_32, NOT_USED);
	link_id(COM_MAN_I_1, 18);
	link_id(COM_MAN_I_2, 17);
	link_id(COM_MAN_I_3, 16);
	link_id(COM_MAN_I_4, 31);
	link_id(COM_MAN_I_5, 30);
	link_id(COM_MAN_I_6, 29);
	link_id(COM_MAN_II_1, 50);//50
	link_id(COM_MAN_II_2_, 49);//preveri problem
	link_id(COM_MAN_II_3, 48);
	link_id(COM_MAN_II_4, 63);
	link_id(COM_MAN_II_5, 62);
	link_id(COM_MAN_II_6, 61);
	link_id(COM_MAN_III_1, NOT_USED);
	link_id(COM_MAN_III_2, NOT_USED);
	link_id(COM_MAN_III_3, NOT_USED);
	link_id(COM_MAN_III_4, NOT_USED);
	link_id(COM_MAN_III_5, NOT_USED);
	link_id(COM_MAN_III_6, NOT_USED);
	link_id(BUTTN_SET_1, 7);
	link_id(BUTTN_SET_2, 39);
	link_id(BUTTN_SET_3, NOT_USED);
	link_id(BUTTN_MINUS_1, 9);
	link_id(BUTTN_MINUS_2, 41);
	link_id(BUTTN_MINUS_3, NOT_USED);
	link_id(BUTTN_PLUS_1, 23);
	link_id(BUTTN_PLUS_2, 55);
	link_id(BUTTN_PLUS_3, NOT_USED);
	link_id(BUTTN_10_1, 21);
	link_id(BUTTN_10_2, 53);
	link_id(BUTTN_10_3, NOT_USED);
	link_id(BUTTN_100_1, 20);
	link_id(BUTTN_100_2, 52);
	link_id(BUTTN_100_3, NOT_USED);
	link_id(BUTTN_RESET_1, 25);
	link_id(BUTTN_RESET_2, 57);
	link_id(BUTTN_RESET_3, NOT_USED);
	link_id(BUTTN_CR_foot, NOT_USED);
	link_id(BUTTN_III_II_foot, NOT_USED);
	link_id(BUTTN_III_I_foot, NOT_USED);
	link_id(BUTTN_II_I_foot, NOT_USED);
	link_id(BUTTN_III_PED_foot, NOT_USED);
	link_id(BUTTN_II_PED_foot, NOT_USED);
	link_id(BUTTN_I_PED_foot, NOT_USED);
	link_id(BUTTN_Z_foot, NOT_USED);
	link_id(BUTTN_PP_foot, NOT_USED);
	link_id(BUTTN_P_foot, NOT_USED);
	link_id(BUTTN_MF_foot, NOT_USED);
	link_id(BUTTN_F_foot, NOT_USED);
	link_id(BUTTN_FF_foot, NOT_USED);
	link_id(BUTTN_T_foot, NOT_USED);
	link_id(BUTTN_MELODY, 27);
	link_id(BUTTN_BASS, 5);
	#endif
	
	#ifdef   ZECER_2X_AMERIKA
	DEBUG_println(F("2x amerika zec"));
	link_id(BUTTN_DUMMY, NOT_USED);
	link_id(BUTTN_1, 3);
	link_id(BUTTN_2, 2);
	link_id(BUTTN_3, 1);
	link_id(BUTTN_4, 0);
	link_id(BUTTN_5, 15);
	link_id(BUTTN_6, 14);
	link_id(BUTTN_7, 13);
	link_id(BUTTN_8, 12);
	link_id(BUTTN_9, 35);
	link_id(BUTTN_10, 34);
	link_id(BUTTN_11, 33);
	link_id(BUTTN_12, 32);
	link_id(BUTTN_13, 47);
	link_id(BUTTN_14, 46);
	link_id(BUTTN_15, 45);
	link_id(BUTTN_16, 44);
	link_id(BUTTN_17, NOT_USED);
	link_id(BUTTN_18, NOT_USED);
	link_id(BUTTN_19, NOT_USED);
	link_id(BUTTN_20, NOT_USED);
	link_id(BUTTN_21, NOT_USED);
	link_id(BUTTN_22, NOT_USED);
	link_id(BUTTN_23, NOT_USED);
	link_id(BUTTN_24, NOT_USED);
	link_id(BUTTN_25, NOT_USED);
	link_id(BUTTN_26, NOT_USED);
	link_id(BUTTN_27, NOT_USED);
	link_id(BUTTN_28, NOT_USED);
	link_id(BUTTN_29, NOT_USED);
	link_id(BUTTN_30, NOT_USED);
	link_id(BUTTN_31, NOT_USED);
	link_id(BUTTN_32, NOT_USED);
	link_id(COM_MAN_I_1, 18);
	link_id(COM_MAN_I_2, 17);
	link_id(COM_MAN_I_3, 16);
	link_id(COM_MAN_I_4, 31);
	link_id(COM_MAN_I_5, 30);
	link_id(COM_MAN_I_6, 29);
	link_id(COM_MAN_II_1, 50);//50
	link_id(COM_MAN_II_2_, 49);//preveri problem
	link_id(COM_MAN_II_3, 48);
	link_id(COM_MAN_II_4, 63);
	link_id(COM_MAN_II_5, 62);
	link_id(COM_MAN_II_6, 61);
	link_id(COM_MAN_III_1, NOT_USED);
	link_id(COM_MAN_III_2, NOT_USED);
	link_id(COM_MAN_III_3, NOT_USED);
	link_id(COM_MAN_III_4, NOT_USED);
	link_id(COM_MAN_III_5, NOT_USED);
	link_id(COM_MAN_III_6, NOT_USED);
	link_id(BUTTN_SET_1, 7);
	link_id(BUTTN_SET_2, 39);
	link_id(BUTTN_SET_3, NOT_USED);
	link_id(BUTTN_MINUS_1, 9);
	link_id(BUTTN_MINUS_2, 41);
	link_id(BUTTN_MINUS_3, NOT_USED);
	link_id(BUTTN_PLUS_1, 23);
	link_id(BUTTN_PLUS_2, 55);
	link_id(BUTTN_PLUS_3, NOT_USED);
	link_id(BUTTN_10_1, 21);
	link_id(BUTTN_10_2, 53);
	link_id(BUTTN_10_3, NOT_USED);
	link_id(BUTTN_100_1, 20);
	link_id(BUTTN_100_2, 52);
	link_id(BUTTN_100_3, NOT_USED);
	link_id(BUTTN_RESET_1, 25);
	link_id(BUTTN_RESET_2, 57);
	link_id(BUTTN_RESET_3, NOT_USED);
	link_id(BUTTN_CR_foot, NOT_USED);
	link_id(BUTTN_III_II_foot, NOT_USED);
	link_id(BUTTN_III_I_foot, NOT_USED);
	link_id(BUTTN_II_I_foot, NOT_USED);
	link_id(BUTTN_III_PED_foot, NOT_USED);
	link_id(BUTTN_II_PED_foot, NOT_USED);
	link_id(BUTTN_I_PED_foot, NOT_USED);
	link_id(BUTTN_Z_foot, NOT_USED);
	link_id(BUTTN_PP_foot, NOT_USED);
	link_id(BUTTN_P_foot, NOT_USED);
	link_id(BUTTN_MF_foot, NOT_USED);
	link_id(BUTTN_F_foot, NOT_USED);
	link_id(BUTTN_FF_foot, NOT_USED);
	link_id(BUTTN_T_foot, NOT_USED);
	link_id(BUTTN_MELODY, 27);
	link_id(BUTTN_BASS, 5);
	
	//link_id(BUTTN_DUMMY, NOT_USED);
	//link_id(BUTTN_1, 3);
	//link_id(BUTTN_2, 2);
	//link_id(BUTTN_3, 1);
	//link_id(BUTTN_4, 0);
	//link_id(BUTTN_5, 15);
	//link_id(BUTTN_6, 14);
	//link_id(BUTTN_7, 13);
	//link_id(BUTTN_8, 12);
	//
	//link_id(BUTTN_9, 35);
	//link_id(BUTTN_10, 34);
	//link_id(BUTTN_11, 33);
	//link_id(BUTTN_12, 32);
	//link_id(BUTTN_13, 47);
	//link_id(BUTTN_14, 46);
	//link_id(BUTTN_15, 45);
	//link_id(BUTTN_16, 44);
	//link_id(BUTTN_17, NOT_USED);
	//link_id(BUTTN_18, NOT_USED);
	//link_id(BUTTN_19, NOT_USED);
	//link_id(BUTTN_20, NOT_USED);
	//link_id(BUTTN_21, NOT_USED);
	//link_id(BUTTN_22, NOT_USED);
	//link_id(BUTTN_23, NOT_USED);
	//link_id(BUTTN_24, NOT_USED);
	//link_id(BUTTN_25, NOT_USED);
	//link_id(BUTTN_26, NOT_USED);
	//link_id(BUTTN_27, NOT_USED);
	//link_id(BUTTN_28, NOT_USED);
	//link_id(BUTTN_29, NOT_USED);
	//link_id(BUTTN_30, NOT_USED);
	//link_id(BUTTN_31, NOT_USED);
	//link_id(BUTTN_32, NOT_USED);
	//link_id(COM_MAN_I_1, 18);
	//link_id(COM_MAN_I_2, 17);
	//link_id(COM_MAN_I_3, 16);
	//link_id(COM_MAN_I_4, 31);
	//link_id(COM_MAN_I_5, 30);
	//link_id(COM_MAN_I_6, 29);
	//link_id(COM_MAN_II_1, 50);//50
	//link_id(COM_MAN_II_2, 49);//49
	//link_id(COM_MAN_II_3, 48);
	//link_id(COM_MAN_II_4, 63);
	//link_id(COM_MAN_II_5, 62);
	//link_id(COM_MAN_II_6, 61);
	//link_id(COM_MAN_III_1, NOT_USED);
	//link_id(COM_MAN_III_2, NOT_USED);
	//link_id(COM_MAN_III_3, NOT_USED);
	//link_id(COM_MAN_III_4, NOT_USED);
	//link_id(COM_MAN_III_5, NOT_USED);
	//link_id(COM_MAN_III_6, NOT_USED);
	//link_id(BUTTN_SET_1, 7);
	//link_id(BUTTN_SET_2, 39);
	//link_id(BUTTN_SET_3, NOT_USED);
	//link_id(BUTTN_MINUS_1, 9);
	////link_id(BUTTN_MINUS_2, 41);
	//link_id(BUTTN_MINUS_3, NOT_USED);
	//link_id(BUTTN_PLUS_1, 23);
	////link_id(BUTTN_PLUS_2, 55);
	//link_id(BUTTN_PLUS_3, NOT_USED);
	//link_id(BUTTN_10_1, 21);
	//link_id(BUTTN_10_2, 53);
	//link_id(BUTTN_10_3, NOT_USED);
	//link_id(BUTTN_100_1, 20);
	////link_id(BUTTN_100_2, 52);
	//link_id(BUTTN_100_3, NOT_USED);
	//link_id(BUTTN_RESET_1, 25);
	////link_id(BUTTN_RESET_2, 57);
	//link_id(BUTTN_RESET_3, NOT_USED);
	//link_id(BUTTN_CR_foot, NOT_USED);
	//link_id(BUTTN_III_II_foot, NOT_USED);
	//link_id(BUTTN_III_I_foot, NOT_USED);
	//link_id(BUTTN_II_I_foot, NOT_USED);
	//link_id(BUTTN_III_PED_foot, NOT_USED);
	//link_id(BUTTN_II_PED_foot, NOT_USED);
	//link_id(BUTTN_I_PED_foot, NOT_USED);
	//link_id(BUTTN_Z_foot, NOT_USED);
	//link_id(BUTTN_PP_foot, NOT_USED);
	//link_id(BUTTN_P_foot, NOT_USED);
	//link_id(BUTTN_MF_foot, NOT_USED);
	//link_id(BUTTN_F_foot, NOT_USED);
	//link_id(BUTTN_FF_foot, NOT_USED);
	//link_id(BUTTN_T_foot, NOT_USED);
	//link_id(BUTTN_MELODY, 27);
	//link_id(BUTTN_BASS, 5);
	
	
	#endif


}

void Zecer_mgr::Zecer_mgr_init(void(*on_event_B)(Button_z*,bool))
{
	for (int i = 0; i < 100; i++)
	{
		link_tab[i] = 200;
	}



calculate_free_RAM(111);

	add_buttn(new Button_z(BUTTN_DUMMY, 0, class_ON_OFF,on_event_B));
	add_buttn(new Button_z(BUTTN_1, 100, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_2, 110, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_3, 120, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_4, 130, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_5, 140, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_6, 150, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_7, 160, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_8, 170, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_9, 180, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_10, 190, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_11, 200, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_12, 210, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_13, 220, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_14, 230, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_15, 240, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_16, 250, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_17, 260, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_18, 270, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_19, 280, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_20, 290, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_21, 300, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_22, 310, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_23, 320, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_24, 330, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_25, 340, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_26, 350, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_27, 360, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_28, 370, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_29, 380, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_30, 390, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_31, 400, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(BUTTN_32, 410, class_COMBINATION,on_event_B));
	add_buttn(new Button_z(COM_MAN_I_1, 3500,  class_FIX_COMBINATION_MAN_1,on_event_B));
	add_buttn(new Button_z(COM_MAN_I_2, 3510,  class_FIX_COMBINATION_MAN_1,on_event_B));
	add_buttn(new Button_z(COM_MAN_I_3, 3520,  class_FIX_COMBINATION_MAN_1,on_event_B));
	add_buttn(new Button_z(COM_MAN_I_4, 3530,  class_FIX_COMBINATION_MAN_1,on_event_B));
	add_buttn(new Button_z(COM_MAN_I_5, 3540,  class_FIX_COMBINATION_MAN_1,on_event_B));
	add_buttn(new Button_z(COM_MAN_I_6, 3550,  class_FIX_COMBINATION_MAN_1,on_event_B));
	add_buttn(new Button_z(COM_MAN_II_1, 480,  class_FIX_COMBINATION_MAN_2,on_event_B));
	add_buttn(new Button_z(COM_MAN_II_2_, 490,  class_FIX_COMBINATION_MAN_2,on_event_B));
	add_buttn(new Button_z(COM_MAN_II_3, 500,  class_FIX_COMBINATION_MAN_2,on_event_B));
	add_buttn(new Button_z(COM_MAN_II_4, 510,  class_FIX_COMBINATION_MAN_2,on_event_B));
	add_buttn(new Button_z(COM_MAN_II_5, 520,  class_FIX_COMBINATION_MAN_2,on_event_B));
	add_buttn(new Button_z(COM_MAN_II_6, 530,  class_FIX_COMBINATION_MAN_2,on_event_B));
	add_buttn(new Button_z(COM_MAN_III_1, 540,  class_FIX_COMBINATION_MAN_3,on_event_B));
	add_buttn(new Button_z(COM_MAN_III_2, 550,  class_FIX_COMBINATION_MAN_3,on_event_B));
	add_buttn(new Button_z(COM_MAN_III_3, 560,  class_FIX_COMBINATION_MAN_3,on_event_B));
	add_buttn(new Button_z(COM_MAN_III_4, 570,  class_FIX_COMBINATION_MAN_3,on_event_B));
	add_buttn(new Button_z(COM_MAN_III_5, 580,  class_FIX_COMBINATION_MAN_3,on_event_B));
	add_buttn(new Button_z(COM_MAN_III_6, 590,  class_FIX_COMBINATION_MAN_3,on_event_B));
	add_buttn(new Button_z(BUTTN_SET_1, noMEM , class_SET,on_event_B));
	add_buttn(new Button_z(BUTTN_SET_2, noMEM , class_SET,on_event_B));
	add_buttn(new Button_z(BUTTN_SET_3, noMEM , class_SET,on_event_B));
	add_buttn(new Button_z(BUTTN_MINUS_1, noMEM,class_MINUS,on_event_B));
	add_buttn(new Button_z(BUTTN_MINUS_2, noMEM ,class_MINUS,on_event_B));
	add_buttn(new Button_z(BUTTN_MINUS_3, noMEM ,class_MINUS,on_event_B));
	add_buttn(new Button_z(BUTTN_PLUS_1, noMEM ,  class_PLUS,on_event_B));
	add_buttn(new Button_z(BUTTN_PLUS_2, noMEM ,class_PLUS,on_event_B));
	add_buttn(new Button_z(BUTTN_PLUS_3, noMEM ,class_PLUS,on_event_B));
	add_buttn(new Button_z(BUTTN_10_1, noMEM ,class_10,on_event_B));
	add_buttn(new Button_z(BUTTN_10_2, noMEM ,class_10,on_event_B));
	add_buttn(new Button_z(BUTTN_10_3, noMEM ,class_10,on_event_B));
	add_buttn(new Button_z(BUTTN_100_1, noMEM ,class_100,on_event_B));
	add_buttn(new Button_z(BUTTN_100_2, noMEM ,class_100,on_event_B));
	add_buttn(new Button_z(BUTTN_100_3, noMEM ,class_100,on_event_B));
	add_buttn(new Button_z(BUTTN_RESET_1, noMEM ,class_RESET,on_event_B));
	add_buttn(new Button_z(BUTTN_RESET_2, noMEM ,class_RESET,on_event_B));
	add_buttn(new Button_z(BUTTN_RESET_3, noMEM ,class_RESET,on_event_B));
	add_buttn(new Button_z(BUTTN_CR_foot, noMEM , class_FOOT_LINK,on_event_B));
	add_buttn(new Button_z(BUTTN_III_II_foot, noMEM , class_FOOT_LINK,on_event_B));
	add_buttn(new Button_z(BUTTN_III_I_foot, noMEM , class_FOOT_LINK,on_event_B));
	add_buttn(new Button_z(BUTTN_II_I_foot, noMEM , class_FOOT_LINK,on_event_B));
	add_buttn(new Button_z(BUTTN_III_PED_foot, noMEM , class_FOOT_LINK,on_event_B));
	add_buttn(new Button_z(BUTTN_II_PED_foot, noMEM , class_FOOT_LINK,on_event_B));
	add_buttn(new Button_z(BUTTN_I_PED_foot, noMEM , class_FOOT_LINK,on_event_B));
	add_buttn(new Button_z(BUTTN_Z_foot, noMEM , class_FOOT_LINK,on_event_B));
	add_buttn(new Button_z(BUTTN_PP_foot, noMEM ,class_FIX_COMBINATION_MAN_1,on_event_B));
	add_buttn(new Button_z(BUTTN_P_foot, noMEM ,class_FIX_COMBINATION_MAN_1,on_event_B));
	add_buttn(new Button_z(BUTTN_MF_foot, noMEM ,class_FIX_COMBINATION_MAN_1,on_event_B));
	add_buttn(new Button_z(BUTTN_F_foot, noMEM ,class_FIX_COMBINATION_MAN_1,on_event_B));
	add_buttn(new Button_z(BUTTN_FF_foot, noMEM ,class_FIX_COMBINATION_MAN_1,on_event_B));
	add_buttn(new Button_z(BUTTN_T_foot, noMEM ,class_FIX_COMBINATION_MAN_1,on_event_B));
	add_buttn(new Button_z(BUTTN_PLUS_foot, noMEM, class_FOOT_FIXED,on_event_B));    //pazi neki problemi so tule
	add_buttn(new Button_z(BUTTN_MINUS_foot, noMEM,class_FOOT_FIXED,on_event_B));
	add_buttn(new Button_z(BUTTN_RESET_foot, noMEM, class_FOOT_FIXED,on_event_B));
	add_buttn(new Button_z(BUTTN_BASS, noMEM , class_ON_OFF,on_event_B));
	add_buttn(new Button_z(BUTTN_MELODY, noMEM , class_ON_OFF,on_event_B));
	
	//_BUTTNS[COM_MAN_II_2_] = new Button_z(COM_MAN_II_2_, 490,  class_FIX_COMBINATION_MAN_2,on_event_B);
	//add_buttn(new Button_z(COM_MAN_II_2_, 490,  class_FIX_COMBINATION_MAN_2,on_event_B));

	set_disposition(0);
calculate_free_RAM(113);
}


void Zecer_mgr::add_buttn(Button_z* buttn)
{
	//DEBUG_println(buttn->get_id());
	_BUTTNS[buttn->get_id()] = buttn;
}

Button_z* Zecer_mgr::id(int id)
{
	return _BUTTNS[id];
}

Button_z* Zecer_mgr::linked_id(int buttn_name)
{
	if(buttn_name>99)
	{
		DEBUG_println(F("error!"));
		return _BUTTNS[BUTTN_DUMMY];
	}

	
	if (link_tab[buttn_name] == 200)
	{
		//DEBUG_println(F("dummy"));
		return _BUTTNS[BUTTN_DUMMY];
	}
	if(_BUTTNS[link_tab[buttn_name]]!=NULL)
	return _BUTTNS[link_tab[buttn_name]];
	else
	{
			DEBUG_println(F("BUG ZECER!"));
		return _BUTTNS[BUTTN_DUMMY];
	}
}
//void Zecer_mgr::temp_set_outArray(byte *Array)
//{
//	for (int x = 0; x < BUTTN_NUM; x++)
//	{
//		_BUTTNS[x]->set_list(Array, NULL);
//	}
//
//}
bool tictac=false;
bool buttn_prev_plus=false;
bool buttn_prev_minus=false;
void Zecer_mgr::read_input()
{
	bool refresh_OUTPUT=false;
	//bool temp_var_array[120];
	digitalWrite2(LOAD_165_Z, 0);
	digitalWrite2(LOAD_165_Z, 1);

	for (byte i = 0; i < ZECER_num; i++)
	{
		digitalWrite2(CLK_ZECER, 0);

		if (digitalRead2(DATA_165_Z))
		{
			if (link_tab[i] != 200)
			linked_id(i)->select(true);
			refresh_OUTPUT=true;
			//temp_var_array[i] = true;
		}
		else
		{
			if (link_tab[i] != 200)
			linked_id(i)->select(false);
			//temp_var_array[i] = false;
		}

		digitalWrite2(CLK_ZECER, 1);
	}


	//for (byte i = 0; i < ZECER_num; i++)
	//{
	//if (temp_var_array[i] == true)
	//{
	////DEBUG_print(F("ZECER BUTTN ID-> "));
	////DEBUG_print(i);
	////DEBUG_print(F(" linked-> "));
	////DEBUG_println(link_tab[i]);
	//
	////Button_Z_list[get_map_tabela_zecer(i)]->select(true);
	//if (link_tab[i] != 200)
	//linked_id(i)->select(true);
	//
	//}
	//else
	//{
	//if (link_tab[i] != 200)
	//linked_id(i)->select(false);
	//
	//}
	//
	//}
	//if(refresh_OUTPUT==false)
	//return;

	
	
	//digitalWrite2(LOAD_165_STOPS1, LOW);
	//
	//for (int i = ZECER_num - 1; i >= 0; i--)
	//{
	//digitalWrite2(CLK_STOPS1, 0);
	//
	//if (link_tab[get_map_tabela_Z(i)] != 200)
	//{
	//
	//if (linked_id(get_map_tabela_Z(i))->get_out_state() == true)
	//{
	////DEBUG_print(F("1"));
	//digitalWrite2(MOSI_595_STOPS1, HIGH);
	//}
	//else
	//{
	////DEBUG_print(F("0"));
	//digitalWrite2(MOSI_595_STOPS1, LOW);
	//}
	//}
	//else
	//{
	//digitalWrite2(MOSI_595_STOPS1, LOW);
	//}
	//
	//digitalWrite2(CLK_STOPS1, 1);
	//}
	//digitalWrite2(LOAD_165_STOPS1, HIGH);
	//
	//
	//return;

	//DEBUG_STRING_println("LOAD REFRESH STOPS");



	#ifdef RGB_LED_OUTPUT
return;
	for (int c= 0; c < 20; c++)
	{
		
		//
		//if (link_tab[i] != 200)
		//{
			//if (true == true)
			//{
				////Z_S_mgr.
				//Z_S_mgr.RGB_SETTER_OUT.setPixelColor(i, Z_S_mgr.RGB_SETTER_OUT.Color(EEPROM.read(ADD_menu_b8_theme_R)*2,EEPROM.read(ADD_menu_b8_theme_G)*2,EEPROM.read(ADD_menu_b8_theme_B)*2));
				////Z_S_mgr.RGB_SETTER_OUT.setPixelColor(i, Z_S_mgr.RGB_SETTER_OUT.Color(60,20,40));
			//}
			//else
			//{
				////Z_S_mgr.RGB_SETTER_OUT
				//
				//Z_S_mgr.RGB_SETTER_OUT.setPixelColor(i, Z_S_mgr.RGB_SETTER_OUT.Color(0,0,0));
			//}
		//}
		//else
		//Z_S_mgr.RGB_SETTER_OUT.setPixelColor(i, Z_S_mgr.RGB_SETTER_OUT.Color(0,0,0));

	RGB_SETTER_OUT.setPixelColor(c, RGB_SETTER_OUT.Color(EEPROM.read(ADD_menu_b8_theme_R)*2,EEPROM.read(ADD_menu_b8_theme_G)*2,EEPROM.read(ADD_menu_b8_theme_B)*2));


	}
	//RGB_SETTER_OUT.show();
	//calculate_free_RAM(44);
return;
	#else



	digitalWrite2(LOAD_595_Z, LOW);

	for (int i = ZECER_num - 1; i >= 0; i--)
	{
		digitalWrite2(CLK_ZECER, 0);

		if (link_tab[get_map_tabela_Z(i)] != 200)
		{
			
			if (linked_id(get_map_tabela_Z(i))->get_out_state() == true)
			{
				//DEBUG_print(F("1"));
				digitalWrite2(DATA_595_Z, HIGH);
			}
			else
			{
				//DEBUG_print(F("0"));
				digitalWrite2(DATA_595_Z, LOW);
			}
		}
		else
		{
			digitalWrite2(DATA_595_Z, LOW);
		}

		digitalWrite2(CLK_ZECER, 1);
	}
	digitalWrite2(LOAD_595_Z, HIGH);
	#endif


	if(digitalRead2(INPUT_FOOT_PISTON_UP)==false&&buttn_prev_plus==false)
	{
		_BUTTNS[BUTTN_PLUS_1]->select(true);
		buttn_prev_plus=true;
	}
	else if(digitalRead2(INPUT_FOOT_PISTON_UP)==true)
	{
		buttn_prev_plus=false;
	}
	else
	{
		_BUTTNS[BUTTN_PLUS_1]->select(false);
	}
	
	
	
	if(digitalRead2(INPUT_FOOT_PISTON_DOWN)==false&&buttn_prev_minus==false)
	{
		_BUTTNS[BUTTN_MINUS_1]->select(true);
		buttn_prev_minus=true;
	}
	else if(digitalRead2(INPUT_FOOT_PISTON_DOWN)==true)
	{
		buttn_prev_minus=false;
	}
	else
	{
		_BUTTNS[BUTTN_MINUS_1]->select(false);
	}
	

	
}

