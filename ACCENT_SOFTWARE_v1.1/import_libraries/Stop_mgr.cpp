//
//
//



#include "Stop_mgr.h"
#include "Stop.h"
#include "global_methods.h"
#include "Definitions_settings.h"


//void Stop_mgr::add_stop(Stop* button)
//{
//	STOPS = (Stop**)realloc(STOPS,
//		(_num_buttons_Stops + 1)
//		* sizeof(Stop*));
//
//	if (STOPS == NULL)
//		return;
//
//	STOPS[_num_buttons_Stops] = button;
//	_num_buttons_Stops++;
//
//
//
//}
void Stop_mgr::set_disposition(byte model_name)
{
	
	#ifdef NAVADNA_REGISTRACIJA
	link_id(BASSFLOTE_8, 4);
	link_id(BORDUN_16, 12);
	link_id(CHORALBASS_4, 3);
	link_id(CLARION_4, 18);
	link_id(FAGOTT,36 );
	link_id(FLAGEOLET, 39);
	link_id(FLUTE_HARMONIQ, 10);
	link_id(GAMBE, 28);
	link_id(GEIGEN_PRINZIPAL,26 );
	link_id(LARIGOT, 37);
	link_id(MIXTUR_4F, 38);
	link_id(PEDAL_MIXTUR_2F, 2);
	link_id(MIXTUR_5F,20 );
	link_id(NASAT,24 );
	link_id(OBOE,35 );
	link_id(OKTAVBASS_8, 5);
	link_id(OKTAVE_4,8 );
	link_id(PORTUNAL_FLOTE, 29);
	link_id(POSAUNE_16,1 );
	link_id(PRINZIPAL_2, 21);
	link_id(PRINZIPAL_8, 11);
	link_id(PRINZIPAL_BASS_16,7 );
	
	link_id(QUINTE,22 );
	link_id(SALICIONAL,9 );
	link_id(SCHALMEI,33 );
	link_id(SPITZFLOTE,23 );
	link_id(SUBBASS_8, 6);
	link_id(TRAVERS_FLUTE,25 );
	link_id(TROMPETE_8, 19);
	link_id(TROMPETE_8_ped, 0);
	link_id(TROMPETE_HARMONIQ, 34);
	link_id(VOX_COELESTIS,27 );
	link_id(SUPER_I,31 );
	link_id(SUB_I, 16);
	link_id(SUPER_II,46 );
	link_id(SUB_II, 47);
	link_id(II_I, 17);
	link_id(II_PED,14 );
	link_id(I_PED, 15);
	link_id(TREMULANT_II, 32);

	
	#endif
	
	


	#ifdef _AMERIKA_DEMO
	link_id(BASSFLOTE_8, 28);
	link_id(BORDUN_16, 47);
	link_id(BORDUN_8, 16);
	link_id(CHORALBASS_4, 27);
	link_id(CLARION_4, 37);
	link_id(FAGOTT, 12);
	link_id(FLAGEOLET, 6);
	link_id(FLUTE_HARMONIQ, 45);
	link_id(GAMBE, 1);
	link_id(GEIGEN_PRINZIPAL, 20);
	link_id(GEMSHORN_2, 20);
	link_id(KRUMHORN, 8);
	link_id(LARIGOT, 11);
	link_id(MIXTUR_4F, 7);
	link_id(MIXTUR_5F, 39);
	link_id(NASAT, 5);
	link_id(OBOE, 13);
	link_id(OKTAVBASS_8, 29);
	link_id(OKTAVE_4, 2);
	link_id(PEDAL_MIXTUR_2F, 26);
	link_id(PICCOLO, 22);
	link_id(PORTUNAL_FLOTE, 0);
	link_id(POSAUNE_16, 25);
	link_id(PRESTANT_4, 17);
	link_id(PRINZIPAL_2, 40);
	link_id(PRINZIPAL_8, 46);
	link_id(PRINZIPAL_BASS_16, 31);
	link_id(QUINTE, 41);
	link_id(QUINTE_m3, 19);
	link_id(ROHRFLOTE_4, 18);
	link_id(SALICIONAL, 44);
	link_id(SCHALMEI, 15);
	link_id(SCHARF_3F, 23);
	link_id(SPITZFLOTE, 1);
	link_id(SUBBASS_8, 30);
	link_id(TERZE_m3, 21);
	link_id(TRAVERS_FLUTE, 19);
	link_id(TROMPETE_8, 38);
	link_id(TROMPETE_8_ped, 24);
	link_id(TROMPETE_HARMONIQ, 14);
	link_id(VOX_COELESTIS, 2);


	link_id(TREMULANT_II, 10);
	link_id(TREMULANT_I, 9);

	link_id(SUPER_III, 57);
	link_id(SUPER_II, 59);
	link_id(SUB_II, 58);
	link_id(SUB_III, 56);
	link_id(III_II, 60);
	link_id(III_I, 52);
	link_id(SUPER_I, 54);
	link_id(SUB_I, 55);
	link_id(II_I, 53);
	link_id(III_PED, 50);
	link_id(II_PED, 61);
	link_id(I_PED, 51);

	#endif // DEBUG

	#ifdef GRANDIOSO_232T
	link_id(BASSFLOTE_8, 32);
	link_id(BORDUN_16, 38);
	link_id(CHORALBASS_4, 33);
	link_id(CLARION_4, 16);
	link_id(FAGOTT, 14);
	link_id(FLAGEOLET, 11);
	link_id(FLUTE_HARMONIQ, 24);
	link_id(GAMBE, 22);
	link_id(GEIGEN_PRINZIPAL, 8);
	link_id(LARIGOT, 13);
	link_id(MIXTUR_4F, 12);
	link_id(MIXTUR_5F, 30);
	link_id(NASAT, 10);
	link_id(OKTAVBASS_8, 47);
	link_id(OKTAVE_4, 26);
	link_id(OBOE, 15);
	link_id(PEDAL_MIXTUR_2F, 34);
	link_id(PORTUNAL_FLOTE, 21);
	link_id(POSAUNE_16, 35);
	link_id(PRINZIPAL_2, 29);
	link_id(PRINZIPAL_8, 39);
	link_id(PRINZIPAL_BASS_16, 45);
	link_id(QUINTE, 0);
	link_id(SALICIONAL, 25);
	link_id(SCHALMEI, 1);
	link_id(SPITZFLOTE, 27);
	link_id(SUBBASS_8, 46);
	link_id(TRAVERS_FLUTE, 9);
	link_id(TROMPETE_8, 31);
	link_id(TROMPETE_8_ped, 36);
	link_id(TROMPETE_HARMONIQ,0);
	link_id(VOX_COELESTIS, 23);
	link_id(TREMULANT_I, 2);
	link_id(SUPER_II, 6);
	link_id(SUB_II, 5);
	link_id(SUPER_I, 19);
	link_id(SUB_I, 18);
	link_id(II_I, 3);
	link_id(II_PED, 4);
	link_id(I_PED, 17);
	#endif
	#ifdef FESTOSO_232T
	link_id(BASSFLOTE_8, 34);
	link_id(BORDUN_16, 7);
	link_id(CHORALBASS_4, 33);
	link_id(CLARION_4, 13);
	link_id(FAGOTT, 31);
	link_id(FLAGEOLET, 18);
	link_id(FLUTE_HARMONIQ, 5);
	link_id(GAMBE, 23);
	link_id(GEIGEN_PRINZIPAL, 21);
	link_id(LARIGOT, 16);
	link_id(MIXTUR_4F, 17);
	link_id(PEDAL_MIXTUR_2F, 32);
	link_id(MIXTUR_5F, 9);
	link_id(NASAT, 19);
	link_id(OBOE, 30);
	link_id(OKTAVBASS_8, 35);
	link_id(OKTAVE_4, 3);
	link_id(PORTUNAL_FLOTE, 8);
	link_id(POSAUNE_16, 47);
	link_id(PRINZIPAL_2, 15);
	link_id(PRINZIPAL_8, 6);
	link_id(PRINZIPAL_BASS_16, 37);
	link_id(QUINTE, 1);
	link_id(SALICIONAL, 4);
	link_id(SCHALMEI, 28);
	link_id(SPITZFLOTE, 2);
	link_id(SUBBASS_8, 36);
	link_id(TRAVERS_FLUTE, 20);
	link_id(TROMPETE_8, 10);
	link_id(TROMPETE_8_ped, 46);
	link_id(TROMPETE_HARMONIQ, 29);
	link_id(VOX_COELESTIS, 22);
	link_id(SUPER_I, 10);
	link_id(SUB_I, 11);
	link_id(II_I, 26);
	link_id(II_PED, 25);
	link_id(I_PED, 12);
	link_id(TREMULANT_II, 27);
	link_id(SUPER_III, 39);
	link_id(SUB_III, 24);

	#endif // DEBUG

	#ifdef _DRAW_KNOB
	link_id(BASSFLOTE_8, 2);
	link_id(BORDUN_16, 10);
	link_id(BORDUN_8, 52);
	link_id(CHORALBASS_4, 1);
	link_id(CLARION_4, 15);
	link_id(FAGOTT, 48);
	link_id(FLAGEOLET, 51);
	link_id(FLUTE_HARMONIQ, 8);
	link_id(GAMBE, 38);
	link_id(GEIGEN_PRINZIPAL, 35);
	link_id(GEMSHORN_2, 43);
	link_id(KRUMHORN, 44);
	link_id(LARIGOT, 49);
	link_id(MIXTUR_4F, 50);
	link_id(MIXTUR_5F, 14);
	link_id(NASAT, 34);
	link_id(OBOE, 32);
	link_id(OKTAVBASS_8, 3);
	link_id(OKTAVE_4, 21);
	link_id(PEDAL_MIXTUR_2F, 0);
	link_id(PICCOLO, 47);
	link_id(PORTUNAL_FLOTE, 39);
	link_id(POSAUNE_16, 6);
	link_id(PRESTANT_4, 53);
	link_id(PRINZIPAL_2, 13);
	link_id(PRINZIPAL_8, 9);
	link_id(PRINZIPAL_BASS_16, 4);
	link_id(QUINTE, 14);
	link_id(QUINTE_m3, 55);
	link_id(ROHRFLOTE_4, 54);
	link_id(SALICIONAL, 22);
	link_id(SCHALMEI, 41);
	link_id(SCHARF_3F, 46);
	link_id(SPITZFLOTE, 20);
	link_id(SUBBASS_8, 5);
	link_id(TERZE_m3, 45);
	link_id(TRAVERS_FLUTE, 36);
	link_id(TROMPETE_8, 13);
	link_id(TROMPETE_8_ped, 7);
	link_id(TROMPETE_HARMONIQ, 33);
	link_id(VOX_COELESTIS, 37);

	link_id(TREMULANT_II, 42);
	link_id(TREMULANT_I, 40);
	link_id(SUPER_III, 29);
	link_id(SUPER_II, 28);
	link_id(SUB_II, 26);
	link_id(SUB_III, 27);
	link_id(III_II, 25);
	link_id(III_I, 24);
	link_id(SUPER_I, 19);
	link_id(SUB_I, 18);
	link_id(II_I, 17);
	link_id(III_PED, 16);
	link_id(II_PED, 30);
	link_id(I_PED, 31);
	
	


	#endif

}
void Stop_mgr::add_stop(Stop* stop)
{
	
	if (stop->get_ID() == NULL_address)
	{
		//DEBUG_println(stop->get_MIDI_CH());
		STOPS[stop->get_MIDI_CH()] = stop;
	}
	else
	STOPS[stop->get_ID()] = stop;
	
	


	
}



void Stop_mgr::link_id(byte stop_name, byte connect_to_id)//univerzalno vnašanje registrov, id v tabeli pridobi preko serial monitorja
{
	link_tab[connect_to_id] = stop_name;
	//STOPS[stop_name]->_id_out = connect_to_id;
}


Stop* Stop_mgr::id(int id)
{
	if(id<Stop_count&& STOPS[id]!=NULL)
	return STOPS[id];
	else
	return STOPS[0];
}
Stop* Stop_mgr::linked_id(int stop_name)
{
	if (link_tab[stop_name] == 200)
	{
		
		return  STOPS[link_tab[EMPTY]];
	}
	return STOPS[link_tab[stop_name]];
}
bool Stop_mgr::CHECK_stop_init(int stop_name)
{
	if (link_tab[stop_name] == 200)
	{
		return  false;
	}
	else
	{
		return true;
	}

}


void Stop_mgr::Stop_mgr_init(void(*on_event)(Stop*,bool), void(*on_stop_OFF)(Stop*), void(*on_Stop_oktav_OFF)(Stop*), void(*on_stop_tremulant_ON)(Stop*), void(*on_stop_tremulant_OFF)(Stop*))
{
	for (int i = 0; i < 80; i++)
	{
		link_tab[i] = 200;
	}
	//#ifndef _AMERIKA_DEMO
	//	byte id_MANUAL_2 = MANUAL_3;
	//	byte id_MANUAL_3 = MANUAL_2;
	//#else
	//	byte id_MANUAL_2 = MANUAL_2;
	//	byte id_MANUAL_3 = MANUAL_3;
	//#endif // SWAP_MAN3_to_MAN2

	byte id_MANUAL_2 = MANUAL_3;
	byte id_MANUAL_3 = MANUAL_2;



	#ifdef TOTTER_SINGLE_STOP_MIX

	//VPtr<Stop, SPIRAMVAlloc> IDa = valloc.alloc<Stop>();
	//Stop xxx(TROMPETE_8_ped, 16, MIDI_1, COMMON_MIDI_CH2, PEDAL, "TROMPETE", "8'", on_stop_ON, on_stop_OFF);
	
	
	
	add_stop(new Stop (TROMPETE_8_ped, 16, MIDI_1, COMMON_MIDI_CH1, PEDAL, "TROMPETE", "8'", on_event ));
	add_stop(new Stop (POSAUNE_16, 15, MIDI_1, COMMON_MIDI_CH1, PEDAL, "POSAUNE", "16'", on_event ));
	add_stop(new Stop (PEDAL_MIXTUR_2F, 14, MIDI_1, COMMON_MIDI_CH1, PEDAL, "PEDAL MIXTUR 2F.", "2'", on_event ));
	add_stop(new Stop(CHORALBASS_4, 13, MIDI_1, COMMON_MIDI_CH1, PEDAL, "CHORALBASS", "4'", on_event ));
	add_stop(new Stop (BASSFLOTE_8, 12, MIDI_1, COMMON_MIDI_CH1, PEDAL, "BASSFLOTE", "8'", on_event ));
	add_stop(new Stop (OKTAVBASS_8, 11, MIDI_1, COMMON_MIDI_CH1, PEDAL, "OKTAVBASS", "8'", on_event ));
	add_stop(new Stop (SUBBASS_8, 9, MIDI_1, COMMON_MIDI_CH1, PEDAL, "SUBBASS", "16'", on_event ));
	add_stop(new Stop (PRINZIPAL_BASS_16, 8, MIDI_1, COMMON_MIDI_CH1, PEDAL, "PRINZIPAL BASS", "16'", on_event ));
	add_stop(new Stop (CLARION_4, 8, MIDI_2, COMMON_MIDI_CH1, MANUAL_1, "CLARION", "4'", on_event ));
	add_stop(new Stop (TROMPETE_8, 7, MIDI_2, COMMON_MIDI_CH1, MANUAL_1, "TROMPETE 8", "8'", on_event ));
	add_stop(new Stop (MIXTUR_5F, 6, MIDI_2, COMMON_MIDI_CH1, MANUAL_1, "MIXTUR 5F.", "1 1/3'", on_event ));
	add_stop(new Stop (PRINZIPAL_2,5, MIDI_2, COMMON_MIDI_CH1, MANUAL_1, "PRINZIPAL 2", "8'", on_event ));
	add_stop(new Stop (QUINTE, 4, MIDI_2, COMMON_MIDI_CH1, MANUAL_1, "QUINTE", "2 2/3'", on_event ));//2 quinta sta preveri
	add_stop(new Stop (SPITZFLOTE, 3, MIDI_2, COMMON_MIDI_CH1, MANUAL_1, "SPITZFLOTE", "4'", on_event ));
	add_stop(new Stop (OKTAVE_4, 7, MIDI_1, COMMON_MIDI_CH1, MANUAL_1, "OKTAVE", "4'", on_event ));
	add_stop(new Stop (SALICIONAL, 6, MIDI_1, COMMON_MIDI_CH1, MANUAL_1, "SALICIONAL", "8'", on_event ));
	add_stop(new Stop (FLUTE_HARMONIQ, 5, MIDI_1, COMMON_MIDI_CH1, MANUAL_1, "FLUTE HARMONIQ", "8'", on_event ));
	add_stop(new Stop (PRINZIPAL_8, 4, MIDI_1, COMMON_MIDI_CH1, MANUAL_1, "PRINZIPAL", "8'", on_event ));
	add_stop(new Stop (BORDUN_16, 3, MIDI_1, COMMON_MIDI_CH1, MANUAL_1, "BORDUN", "16'", on_event ));//PREVERI
	add_stop(new Stop (NULL_address, I_PED, 0, 0, 0, "I-PEDAL", "", on_event ));
	add_stop(new Stop (NULL_address, II_PED, 0, 0, 0, "II-PEDAL", "", on_event ));
	add_stop(new Stop (NULL_address, III_PED, 0, 0, 0, "III-PEDAL", "", on_event ));
	add_stop(new Stop (NULL_address, II_I, 0, 0, 0, "II-I", "", on_event ));
	add_stop(new Stop (NULL_address, SUPER_I, 0, 0, MANUAL_1, "SUPER I", "", on_event));
	add_stop(new Stop (NULL_address, SUB_I, 0, 0, MANUAL_1, "SUB I", "", on_event));
	add_stop(new Stop (NULL_address, III_I, 0, 0, 0, "III-I", "", on_event ));
	add_stop(new Stop (NULL_address, III_II, 0, 0, 0, "III-II", "", on_event ));
	add_stop(new Stop(NULL_address, SUB_II, 0, 0, id_MANUAL_2, "SUB II", "", on_event));//poglej to
	add_stop(new Stop(NULL_address, SUB_III, 0, 0, id_MANUAL_3, "SUB III", "", on_event));
	add_stop(new Stop(NULL_address, SUPER_II, 0, 0, id_MANUAL_2, "SUPER II", "", on_event));
	add_stop(new Stop(NULL_address, SUPER_III, 0, 0, id_MANUAL_3, "SUPER III", "", on_event));
	add_stop(new Stop (BORDUN_8, 0, MIDI_2, COMMON_MIDI_CH1, id_MANUAL_2, "BORDUN", "8'", on_event ));
	add_stop(new Stop (PRESTANT_4, 0, MIDI_2, COMMON_MIDI_CH1, id_MANUAL_2, "PRESTANT", "4'", on_event ));
	add_stop(new Stop (ROHRFLOTE_4, 0, MIDI_2, COMMON_MIDI_CH1, id_MANUAL_2, "ROHRFLOTE", "4'", on_event ));
	add_stop(new Stop (QUINTE_m3, 0, MIDI_2, COMMON_MIDI_CH1, id_MANUAL_2, "QUINTE", "2 2/3'", on_event )); //(50, 13, MIDI_1, MIDI_PORT_1, id_MANUAL_3, "SCHALMEI", "4'", on_event ));
	add_stop(new Stop (GEMSHORN_2, 0, MIDI_2, COMMON_MIDI_CH1, id_MANUAL_2, "GEMSHORN", "2'", on_event ));
	add_stop(new Stop (TERZE_m3, 0, MIDI_2, COMMON_MIDI_CH1, id_MANUAL_2, "TERZE", "1 3/5''", on_event ));// (49, TREMULANT_I, 0, 0, 0, "TREMULANT", "manual I", on_event ));
	add_stop(new Stop (PICCOLO, 0, MIDI_2, COMMON_MIDI_CH1, id_MANUAL_2, "PICCOLO", "1'", on_event ));
	add_stop(new Stop (SCHARF_3F, 0, MIDI_2, COMMON_MIDI_CH1, id_MANUAL_2, "SCHARF 3F.", "1'", on_event ));// (48, 15, MIDI_2, MIDI_PORT_1, id_MANUAL_2, "QUINTE", "2 2/3'", on_event ));
	add_stop(new Stop (KRUMHORN, 0, MIDI_2, COMMON_MIDI_CH1, id_MANUAL_2, "KRUMMHORN", "8'", on_event ));
	add_stop(new Stop(NULL_address, TREMULANT_I, 0, 0, id_MANUAL_2, "TREMULANT", "manual I", on_event));
	add_stop(new Stop (PORTUNAL_FLOTE, 3, MIDI_3, COMMON_MIDI_CH1, id_MANUAL_3, "PORTUNAL FLUTE", "8'", on_event ));// (39, TREMULANT_II, 0, 0, 0, "TREMULANT", "manual II", on_Stop_tremulant _tremulant));//TODO: veži funkcijo, ki posebaj pošlje ukaz
	add_stop(new Stop (GAMBE, 4, MIDI_3, COMMON_MIDI_CH1, id_MANUAL_3, "GAMBE", "8'", on_event )); //(40, 4, MIDI_2, MIDI_PORT_2, id_MANUAL_2, "KRUMMHORN", "8'", on_event ));
	add_stop(new Stop (VOX_COELESTIS, 5, MIDI_3, COMMON_MIDI_CH1, id_MANUAL_3, "VOX COELESTIS", "8'", on_event ));// (41, 16, MIDI_2, MIDI_PORT_1, id_MANUAL_2, "GEMSHORN", "2'", on_event ));
	add_stop(new Stop (GEIGEN_PRINZIPAL, 6, MIDI_3, COMMON_MIDI_CH1, id_MANUAL_3, "GEIGEN PRINZIPAL", "4'", on_event ));// (43, 3, MIDI_2, MIDI_PORT_2, id_MANUAL_2, "SCHARF 3F.", "1'", on_event ));
	add_stop(new Stop (TRAVERS_FLUTE, 7, MIDI_3, COMMON_MIDI_CH1, id_MANUAL_3, "TRAVERS FLUTE", "4'", on_event ));// (42, 1, MIDI_2, MIDI_PORT_2, id_MANUAL_2, "TERZE", "1 3/5''", on_event ));
	add_stop(new Stop (NASAT, 8, MIDI_3, COMMON_MIDI_CH1, id_MANUAL_3, "NASAT", "2 2/3'", on_event )); //(44, 2, MIDI_2, MIDI_PORT_2, id_MANUAL_2, "PICCOLO", "1'", on_event ));
	add_stop(new Stop (FLAGEOLET, 9, MIDI_3, COMMON_MIDI_CH1, id_MANUAL_3, "FLAGEOLET", "2'", on_event ));
	add_stop(new Stop (MIXTUR_4F, 3, MIDI_4, COMMON_MIDI_CH1, id_MANUAL_3, "MIXTUR 4F.", "2'", on_event ));
	add_stop(new Stop (LARIGOT, 4, MIDI_4, COMMON_MIDI_CH1, id_MANUAL_3, "LARIGOT", "1 1/3'", on_event ));
	add_stop(new Stop (FAGOTT, 5, MIDI_4, COMMON_MIDI_CH1, id_MANUAL_3, "FAGOTT", "16'", on_event ));// (33, 5, MIDI_1, MIDI_PORT_1, id_MANUAL_3, "TRAVERS FLUTE", "4'", on_event ));
	add_stop(new Stop (OBOE, 6, MIDI_4, COMMON_MIDI_CH1, id_MANUAL_3, "OBOE", "8'", on_event ));// (46, 13, MIDI_2, MIDI_PORT_1, id_MANUAL_2, "PRESTANT", "4'", on_event ));
	add_stop(new Stop (TROMPETE_HARMONIQ, 7, MIDI_4, COMMON_MIDI_CH1, id_MANUAL_3, "TROMPETE HARMONIQE", "8'", on_event ));// (45, 12, MIDI_2, MIDI_PORT_1, id_MANUAL_2, "BORDON", "8'", on_event ));
	add_stop(new Stop (SCHALMEI, 8, MIDI_4, COMMON_MIDI_CH1, id_MANUAL_3, "SCHALMEI", "4'", on_event ));
	add_stop(new Stop(NULL_address, TREMULANT_II, 0, 0, id_MANUAL_3, "TREMULANT", "manual II", on_event));
	add_stop(new Stop(EMPTY, NULL_address, NULL_address, NULL_address, NULL_address, "dummy", "", on_event ));

	

	#endif

	set_disposition(0);
	/*	for (int x = 0; x < _num_buttons_Stops; x++)
	{
	DEBUG_print(F("LINKED "));
	DEBUG_print(x);
	DEBUG_print(F(" -> "));
	DEBUG_print(link_tab[x]);

	}*/

	/*buttn_COMBINATION_1.set_NUM(1);
	buttn_COMBINATION_2.set_NUM(2);
	buttn_COMBINATION_3.set_NUM(3);
	buttn_COMBINATION_4.set_NUM(4);
	buttn_COMBINATION_5.set_NUM(5);
	buttn_COMBINATION_6.set_NUM(6);
	buttn_COMBINATION_7.set_NUM(7);
	buttn_COMBINATION_8.set_NUM(8);

	buttn_COMBINATION_9.set_NUM(9);
	buttn_COMBINATION_10.set_NUM(10);
	buttn_COMBINATION_11.set_NUM(11);
	buttn_COMBINATION_12.set_NUM(12);
	buttn_COMBINATION_13.set_NUM(13);
	buttn_COMBINATION_14.set_NUM(14);
	buttn_COMBINATION_15.set_NUM(15);
	buttn_COMBINATION_16.set_NUM(16);

	buttn_COMBINATION_17.set_NUM(17);
	buttn_COMBINATION_18.set_NUM(18);
	buttn_COMBINATION_19.set_NUM(19);
	buttn_COMBINATION_20.set_NUM(20);
	buttn_COMBINATION_21.set_NUM(21);
	buttn_COMBINATION_22.set_NUM(22);
	buttn_COMBINATION_23.set_NUM(23);
	buttn_COMBINATION_24.set_NUM(24);

	buttn_PP.set_NUM(1);
	buttn_P.set_NUM(2);
	buttn_MF.set_NUM(3);
	buttn_F.set_NUM(4);
	buttn_FF.set_NUM(5);
	buttn_T.set_NUM(6);

	buttn_COMBINATION_1_2.set_NUM(1);
	buttn_COMBINATION_2_2.set_NUM(2);
	buttn_COMBINATION_3_2.set_NUM(3);
	buttn_COMBINATION_4_2.set_NUM(4);
	buttn_COMBINATION_5_2.set_NUM(5);
	buttn_COMBINATION_6_2.set_NUM(6);

	buttn_COMBINATION_1_3.set_NUM(1);
	buttn_COMBINATION_2_3.set_NUM(2);
	buttn_COMBINATION_3_3.set_NUM(3);
	buttn_COMBINATION_4_3.set_NUM(4);
	buttn_COMBINATION_5_3.set_NUM(5);
	buttn_COMBINATION_6_3.set_NUM(6);

	buttn_PP_foot.set_NUM(100);
	buttn_P_foot.set_NUM(101);
	buttn_MF_foot.set_NUM(102);
	buttn_F_foot.set_NUM(103);
	buttn_FF_foot.set_NUM(104);
	buttn_T_foot.set_NUM(105);*/
}

void Stop_mgr::read_stopsNormal()
{
	//return;
	//DEBUG_print(F("LOAD_165_R_r "));
	//DEBUG_println(LOAD_165_R_r);
	//DEBUG_print(F("STOP_num "));
	//DEBUG_println(STOP_num);
	//DEBUG_print(F("CLK_stop_pin "));
	//DEBUG_println(CLK_stop_pin);
	//DEBUG_print(F("DATA_165_R_r "));

	//delay(1000);
	
	
	//bool temp_var_array[80];
	//check stops
	digitalWrite2(LOAD_165_STOPS1, 0);
	digitalWrite2(LOAD_165_STOPS1, 1);

	for (int i = 0; i < STOP_num; i++)
	{
		//DEBUG_STRING_print("link id test_  ");
		//DEBUG_print(STOP_mgr.link_tab[i]);
		//DEBUG_STRING_print(" link id test_ ");
		//DEBUG_println(STOP_mgr.linked_id(i)->get_active_on_manual());
		//
		
		digitalWrite(CLK_STOPS1, 0);
		if (digitalRead2(MISO_165_STOPS1))
		{
			//	_writeBit(button_R, i, true);
			if (STOP_mgr.link_tab[i] != 200)
			STOP_mgr.linked_id(i)->select(true);
			//refresh_STOP_OUTPUT=true;
			//DEBUG_print(1);
			//	temp_var_array[i] = true;
			//Stops_list[map_tabela_Z[i]]->select(true);
		}
		else
		{
			if (STOP_mgr.link_tab[i] != 200)
			STOP_mgr.linked_id(i)->select(false);
			//DEBUG_print(0);
			//temp_var_array[i] = false;
			//Stops_list[map_tabela_Z[i]]->select(false);
			//_writeBit(button_R, i, false);
		}

		digitalWrite(CLK_STOPS1, 1);
	}
	digitalWrite2(LOAD_165_STOPS1, 0);

	//DEBUG_println();

	//for (byte i = 0; i < STOP_num; i++)
	//{
	//if (temp_var_array[i] == true)
	//{
	//
	////if (i != 42 && i != 41)//ker ni upora oz so odrezane
	//{
	////
	////DEBUG_print(F("ID za LINK-> "));
	////DEBUG_print(i);
	////DEBUG_print(F(" ::STOP NAME: "));
	////DEBUG_println(STOP_mgr.link_tab[i]);
	//
	//
	//
	//if (STOP_mgr.link_tab[i] != 200)
	//STOP_mgr.linked_id(i)->select(true);
	//
	//}
	//
	//
	//}
	//else
	//{
	//
	//if (STOP_mgr.link_tab[i] != 200)
	//STOP_mgr.linked_id(i)->select(false);
	//
	//}
	//
	//}
	
}

