#include "zecer_stop_mgr.h"
#include "global_variables.h"
#include "global_methods.h"
#include <SoftwareSerial.h>
#include <MIDI.h>
#include "arduino2.h"
#include "EEPROM.h"
#include "SD_mgr.h"
#include <avr\pgmspace.h>
#include "PROGMEM_labels.h"
#include "Stop_mgr.h"
#include <Adafruit_NeoPixel.h>




#define  GPIO2_PREFER_SPEED    0 //0-> default digitalwrite  1-> fast digitalwrite




byte old_gas_ped_1 = -1;
byte old_gas_ped_2 = -1;
byte old_gas_ped_man2 = -1;
byte _z_state;
bool GAS1_refresh = false;
bool GAS2_refresh = false;
bool GAS2_ped_refresh = false;
bool MASTER_VOL_refresh = false;


SD_mgr  SD_work;

//Zecer_stop_mgr Z_S_mgr;
MIDI_mgr MIDI_sender;
Stop_mgr STOP_mgr;
Zecer_mgr  ZECER;




unsigned long start_time;
unsigned long temp_time;

byte output_temp[10];
byte manubri_temp[20];
byte temp_stop_list_array[20];
byte previous_stop_list_array[20];
byte mag_out_stop_list_array[20];

#include "SPIEEP.h"
#define EEPROM_CSPIN A7

void Zecer_stop_mgr::Zecer_stop_mgr_init()
{
	 RGB_SETTER_OUT = Adafruit_NeoPixel(ZECER_num, DATA_595_Z, NEO_GRB + NEO_KHZ800);

	//Serial.println("eeprotestm");

#ifdef RGB_LED_OUTPUT_setter
RGB_SETTER_OUT.begin();

for (int i = 0; i < ZECER_num; i++)
{
	RGB_SETTER_OUT.setPixelColor(i, RGB_SETTER_OUT.Color(70,0,0));
	
}
RGB_SETTER_OUT.show();
#endif
	exEEPROM.begin_spi(EEPROM_CSPIN);
	delayMicroseconds(100);
	exEEPROM.wakeup();
	extern_eeprom_ok=false;
	byte b;
	byte tmp=42;
	tmp=exEEPROM.read(0x0010);
	
	tmp=42;
	exEEPROM.write(0x0010,tmp);
	b = exEEPROM.read(0x0010);

	b++;
	if (!exEEPROM.write(0x0010, b))
	{
		DEBUG_STRING_println("------------------EXTERNAL EEPROM PROBLEM!");

	}
	else
	{
		DEBUG_STRING_println("++++++++++++++++EXTERNAL EEPROM OK");
		extern_eeprom_ok=true;
	}

	// Write it to the serial port
	for (byte i = 0; i < 255; i++) {
		exRAM.write_byte(i,i);
	}
	
	for (byte i = 0; i < 255; i++) {
		if(	exRAM.read_byte(i)!=i)
		{
			DEBUG_STRING_println("------------------EXTERNAL RAM PROBLEM!");
			break;
		}
		if(i==254)
		{
			DEBUG_STRING_println("++++++++++++++++EXTERNAL RAM OK");
		}
	}
	
	calculate_free_RAM(10);
	STOP_mgr.Stop_mgr_init(on_stop_EVENT, on_stop_OFF, on_stop_OFF, on_stop_tremulant_ON, on_stop_tremulant_OFF);
	MIDI_sender.MIDI_mgr_init();	
	ZECER.Zecer_mgr_init(on_buttn_EVENT);//novi naèin zaradi rama
calculate_free_RAM(11);

	manubri_na_nulo();
	#ifdef RGB_LED_OUTPUT
	RGB_STOP1_OUT.begin();
	
	for (int i = 0; i < STOP_num; i++)
	{
		RGB_STOP1_OUT.setPixelColor(i, RGB_STOP1_OUT.Color(0,0,0));
	}
	#endif


	//	1 - 2 - 2 - 3 - 4 - 4 - 4 - 4 - 4
	//write_mem_velocity_from_PROGMEM(Stops_list[0]);// odkomentiraj za prepis iz progmem
}

bool testbool=false;

void load_ordinary_stop_output(Stop* stop)
{

	digitalWrite(STOP1_OUT_ENABLE, HIGH);

	digitalWrite2(SS_595_STOPS1, LOW);
	//reverse
	for (int i = STOP_num - 1; i >= 0; i--)
	{
		digitalWrite(CLK_STOPS1, 0);
		digitalWrite2(MOSI_595_STOPS1, HIGH);
		if(STOP_mgr.CHECK_stop_init(get_map_tabela_Z(i))==false)
		{
			digitalWrite2(MOSI_595_STOPS1, LOW);
		}
		else if (STOP_mgr.linked_id(get_map_tabela_Z(i))->GetState() == true)
		{
			DEBUG_print(F("refresh linked id "));
			DEBUG_print(i);
			DEBUG_print((" "));
			DEBUG_println(STOP_mgr.linked_id(get_map_tabela_Z(i))->ID);
			
			digitalWrite2(MOSI_595_STOPS1, HIGH);
		}
		else
		digitalWrite2(MOSI_595_STOPS1, LOW);
		digitalWrite(CLK_STOPS1, 1);

	}
	digitalWrite2(SS_595_STOPS1, HIGH);
}

byte color=100;
byte color1=100;
byte color2=100;



void load_RGB_stop_output(Stop* stop)
{


	#ifdef RGB_LED_OUTPUT

	for (int i = 0; i < STOP_num; i++)
	{
		if(STOP_mgr.CHECK_stop_init(get_map_tabela_Z(i))==false)
		{
			RGB_STOP1_OUT.setPixelColor(i, RGB_STOP1_OUT.Color(0,0,0));

		}
		else if (STOP_mgr.linked_id(get_map_tabela_Z(i))->GetState() == true)
		{
			RGB_STOP1_OUT.setPixelColor(i, RGB_STOP1_OUT.Color(EEPROM.read(ADD_menu_b8_theme_R)*2,EEPROM.read(ADD_menu_b8_theme_G)*2,EEPROM.read(ADD_menu_b8_theme_B)*2));
		}
		else
		RGB_STOP1_OUT.setPixelColor(i, RGB_STOP1_OUT.Color(0,0,0)); // Moderately bright green color.

	}
	RGB_STOP1_OUT.show();
	#endif
}

void load_RGB_setter_output(Stop* stop)
{

//
//
	//#ifdef RGB_LED_OUTPUT
//
	//for (int i = 0; i < STOP_num; i++)
	//{
		//if(STOP_mgr.CHECK_stop_init(get_map_tabela_Z(i))==false)
		//{
			//RGB_SETTER_OUT.setPixelColor(i, RGB_SETTER_OUT.Color(0,0,0));
//
		//}
		//else if (STOP_mgr.linked_id(get_map_tabela_Z(i))->GetState() == true)
		//{
			//RGB_SETTER_OUT.setPixelColor(i, RGB_SETTER_OUT.Color(EEPROM.read(ADD_menu_b8_theme_R)*2,EEPROM.read(ADD_menu_b8_theme_G)*2,EEPROM.read(ADD_menu_b8_theme_B)*2));
		//}
		//else
		//RGB_SETTER_OUT.setPixelColor(i, RGB_SETTER_OUT.Color(0,0,0)); // Moderately bright green color.
//
	//}
	//RGB_SETTER_OUT.show();
	//#endif
}

bool Zecer_stop_mgr::_readBit(byte variable[], int position)
{
	if (bitRead(variable[get_map_tabela_Z(position) / 8], get_map_tabela_Z(position) % 8) == true)
	return true;
	else
	return false;
}

bool Zecer_stop_mgr::_writeBit(byte variable[], int position, bool state)
{
	bitWrite(variable[get_map_tabela_Z(position) / 8], get_map_tabela_Z(position) % 8, state);
	return true;
}
void on_buttn_EVENT(Button_z* buttn,bool ON_OFF)
{
	//DEBUG_print(buttn->get_id());
	//DEBUG_print(F("event CLASS"));
	//DEBUG_println(buttn->get_id_class());
	//DEBUG_println(ON_OFF);
	
	//return;
	switch (buttn->get_id_class())
	{
		case class_SET:
		
		if(ON_OFF)
		on_buttn_SET(buttn);
		else
		on_buttn_SET_deselect(buttn);
		break;
		
		case class_COMBINATION:
		if(ON_OFF)
		on_buttn_combination(buttn);
		else
		on_buttn_combination_deselect(buttn);
		break;
		
		case class_PLUS :
		if(ON_OFF)
		on_buttn_PLUS(buttn);
		else
		on_buttn_PLUS_deselect(buttn);
		break;
		
		case class_MINUS :
		if(ON_OFF)
		on_buttn_MINUS(buttn);
		else
		on_buttn_MINUS_deselect(buttn);
		break;
		
		case class_FIX_COMBINATION_MAN_1 :
		if(ON_OFF)
		on_buttn_combination(buttn);
		else
		on_buttn_combination_deselect(buttn);
		break;
		
		case class_FIX_COMBINATION_MAN_2 :
		if(ON_OFF)
		on_buttn_combination(buttn);
		else
		on_buttn_combination_deselect(buttn);
		break;
		
		case class_FIX_COMBINATION_MAN_3 :
		if(ON_OFF)
		on_buttn_combination(buttn);
		else
		on_buttn_combination_deselect(buttn);
		break;
		
		case class_RESET :
		if(ON_OFF)
		on_buttn_RESET(buttn);
		else
		on_buttn_RESET_deselect(buttn);
		break;
		
		case class_10 :
		if(ON_OFF)
		on_buttn_10(buttn);
		else
		on_buttn_10_deselect(buttn);
		break;
		
		case class_100 :
		if(ON_OFF)
		on_buttn_100(buttn);
		else
		on_buttn_100_deselect(buttn);
		break;
		
		case class_FOOT_LINK :
		if(ON_OFF)
		on_foot_piston(buttn);
		else
		on_foot_piston_deselect(buttn);
		break;
		
		case class_ON_OFF :
		if(ON_OFF)
		on_buttn_on_off(buttn);
		else
		on_buttn_on_off_deselect(buttn);
		break;
		
		
	}

}
void on_buttn_on_off(Button_z* buttn)
{
	//DEBUG_print(buttn->get_id());
	//DEBUG_println(F(" com deselect"));
	//_writeBit(ZECER.OUT_array, buttn->_id_out, false);
	buttn->set_out_state(true);
	/*_writeBit(output_temp, buttn->_id, false);
	load_zecer_output(output_temp);*/

}
void on_buttn_on_off_deselect(Button_z* buttn)
{
	//DEBUG_print(buttn->get_id());
	//DEBUG_println(F(" com deselect"));
	//_writeBit(ZECER.OUT_array, buttn->_id_out, false);
	buttn->set_out_state(false);
	/*_writeBit(output_temp, buttn->_id, false);
	load_zecer_output(output_temp);*/

}

void on_buttn_SET(Button_z* buttn)
{
	calculate_free_RAM(21);
	if (CRESCENDO_STATE)
	return;
	DEBUG_println(F("SET"));
	String myString = String(buttn->get_id());
	buttn->set_out_state(true);
	//_writeBit(ZECER.OUT_array, buttn->_id_out, true);
	//_writeBit(output_temp, buttn->_id, true);
	//load_zecer_output(output_temp);

}
void on_buttn_SET_deselect(Button_z* buttn)
{
	String myString = String(buttn->get_id());
	buttn->set_out_state(false);
	//COMBINATION_LABEL_TEXT = "";
	//DEBUG_println(F("chars->")); DEBUG_println(myString);
	//_writeBit(ZECER.OUT_array, buttn->_id_out, false);
	//_writeBit(output_temp, buttn->_id, false);
	//load_zecer_output(output_temp);

}

#include <MemoryFree.h>
//samo za ugasnat pri ostalih kombinacijah
void on_buttn_combination(Button_z* buttn)
{
	DEBUG_print(F("buttn:"));
	DEBUG_println(buttn->get_id_num());
	
	bool force_save_ = false;
	
	if (CRESCENDO_STATE)
	return;

	String id_string = "";
	


	bool load = true;

	bool fix_combi = false;
	//SETTER_combination = buttn->get_id_num();
	if (buttn->get_id_class() == class_COMBINATION)
	{
		COMBINATION_LABEL_FIRST_letter = (buttn->get_id_num());
		SETTER_combination = buttn->get_id_num();
	}
	else if (buttn->get_id_class() == class_FIX_COMBINATION_MAN_1)
	{

		COMBINATION_LABEL_FIRST_letter = "M1 " + (String)(buttn->get_id_num());
		
		switch (buttn->get_id_num())
		{
			#ifdef ZECER_2X_AMERIKA
			
			case COM_MAN_I_1:
			id_string = "M1 1";
			break;
			case COM_MAN_I_2:
			id_string = "M1 2";
			break;
			case COM_MAN_I_3:
			id_string = "M1 3";
			break;
			case COM_MAN_I_4:
			id_string = "M1 4";
			break;
			case COM_MAN_I_5:
			id_string = "M1 5";
			break;
			case COM_MAN_I_6:
			id_string = "M1 6";
			break;
			default:
			id_string = "";
			break;
			#endif
			
			
			#ifdef ZECER_1X
			
			case COM_MAN_I_1:
			id_string = "PP";
			break;
			case COM_MAN_I_2:
			id_string = "P";
			break;
			case COM_MAN_I_3:
			id_string = "MF";
			break;
			case COM_MAN_I_4:
			id_string = "F";
			break;
			case COM_MAN_I_5:
			id_string = "FF";
			break;
			case COM_MAN_I_6:
			id_string = "T";
			break;
			default:
			id_string = "";
			break;
			
			#endif
		}
		force_save_ = true;

		COMBINATION_LABEL_FIRST_letter = id_string;
		
	}
	else if (buttn->get_id_class() == class_FIX_COMBINATION_MAN_2)
	{
		switch (buttn->get_id_num())
		{
			case COM_MAN_II_1:
			id_string = "1";
			break;
			case COM_MAN_II_2_:
			id_string = "2";
			break;
			case COM_MAN_II_3:
			id_string = "3";
			break;
			case COM_MAN_II_4:
			id_string = "4";
			break;
			case COM_MAN_II_5:
			id_string = "5";
			break;
			case COM_MAN_II_6:
			id_string = "6";
			break;
			default:
			id_string = "";
			break;
		}
		DEBUG_print(F("pride m2:"));
		DEBUG_println(buttn->get_id_class());
		COMBINATION_LABEL_FIRST_letter = "M2 " + id_string;
	}
	else if (buttn->get_id_class() == class_FIX_COMBINATION_MAN_3)
	{
		DEBUG_print(F("pride m3:"));
		DEBUG_println(buttn->get_id_class());
		COMBINATION_LABEL_FIRST_letter = "M3 " + (String)(buttn->get_id_num());
	}
	




	//return;
	//DEBUG_println(F("buttn comb: "));
	//DEBUG_println(buttn->get_id_num());
	load = true;


	id_string = COMBINATION_LABEL_FIRST_letter;

	for (int x = 0; x < ZECER_num; x++)
	{
		//ZECER.id(x)->SetState(false);

		if (ZECER.linked_id(x)->get_id_class() == 2 && ZECER.linked_id(x)->get_id() != buttn->get_id()&&ZECER.linked_id(x)->GetState() == true || ZECER.linked_id(x)->get_id_class() == 6 || ZECER.linked_id(x)->get_id_class() == class_FIX_COMBINATION_MAN_1 || ZECER.linked_id(x)->get_id_class() == class_FIX_COMBINATION_MAN_2 || ZECER.linked_id(x)->get_id_class() == class_FIX_COMBINATION_MAN_3 || ZECER.linked_id(x)->get_id_class() == class_FOOT_FIXED)
		ZECER.linked_id(x)->SetState(false);
	}

	if (ZECER.id(BUTTN_SET_1)->GetState()||ZECER.id(BUTTN_SET_2)->GetState())
	{
		//DEBUG_print("write STOP ");

		if (load){


			for (int x = 0; x < STOP_mgr.Stop_count; x++)
			{
				if (buttn->get_id_class() == class_COMBINATION || buttn->get_id_class() == class_FOOT_FIXED || force_save_)//da shrani
				{
					//DEBUG_print(F("stop state: "));
					//DEBUG_print(STOP_mgr.id(x)->GetState());
					//DEBUG_print(F(" ID: "));
					//DEBUG_print(x);
					//DEBUG_print(F(" ;;link ID: "));
					//DEBUG_println(STOP_mgr.linked_id(x)->get_ID());
					

					if (STOP_mgr.id(x)->GetState() == true)//TODO: temp fix, negiraj izhode
					_writeBit_stop(temp_stop_list_array, x, true);
					else
					_writeBit_stop(temp_stop_list_array, x, false);
				}
				else if (buttn->get_id_class() == class_FIX_COMBINATION_MAN_3 || buttn->get_id_class() == class_FIX_COMBINATION_MAN_2 || buttn->get_id_class() == class_FIX_COMBINATION_MAN_1)
				{

					if (STOP_mgr.id(x)->GetState() == true)//TODO: temp fix, negiraj izhode
					{
						if (buttn->get_id_class() == class_FIX_COMBINATION_MAN_1&& STOP_mgr.id(x)->get_active_on_manual() == MANUAL_1)
						_writeBit_stop(temp_stop_list_array, x, true);
						else	if (buttn->get_id_class() == class_FIX_COMBINATION_MAN_2&&  STOP_mgr.id(x)->get_active_on_manual() == MANUAL_2)
						_writeBit_stop(temp_stop_list_array, x, true);
						else	if (buttn->get_id_class() == class_FIX_COMBINATION_MAN_3&&  STOP_mgr.id(x)->get_active_on_manual() == MANUAL_3)
						_writeBit_stop(temp_stop_list_array, x, true);
						else
						_writeBit_stop(temp_stop_list_array, x, false);
					}
					else
					_writeBit_stop(temp_stop_list_array, x, false);
				}
			}

			
			{
				buttn->write_mem(temp_stop_list_array);//iz eeproma
				COMBINATION_LABEL_FIRST_letter = id_string + " SAVED";
			}





		}
	}
	else
	{

		//preberi iz flasha

		if (STOP_type == LED_MANUBRI)
		{
			if (load){
				
				{
					buttn->read_mem(temp_stop_list_array);
					check_previous_combination();
				}
				
			}
			//Z_S_mgr.allow_refresh=false;
			for (int y = 0; y < STOP_mgr.Stop_count; y++)
			{
				if (_readBit_stop(temp_stop_list_array, y) == true)
				{
					//DEBUG_print(F("stop state: "));
					//DEBUG_print(STOP_mgr.id(y)->GetState());
					//DEBUG_print(F(" ID: "));
					//DEBUG_print(y);
					//DEBUG_print(F(" ;;link ID: "));
					//DEBUG_println(STOP_mgr.linked_id(y)->get_ID());
					//DEBUG_print(y);
					//STOP_mgr.linked_id(y)->SetState(true);
					STOP_mgr.id(y)->SetState(true);

				}
				else
				{
					STOP_mgr.id(y)->SetState(false);
				}
			}
			//Z_S_mgr.allow_refresh=true;
			//Z_S_mgr.help_refresh_note_ALL();
		}
		else if (STOP_type == SDK_MANUBRI)
		{
			if (load){
				
				buttn->read_mem(temp_stop_list_array);
			}
			/*		byte converted_out_array[20];
			for (int y = 0; y < ALL_STOP; y++)
			{
			if (_readBit_stop(temp_stop_list_array, y) == true)
			{
			
			_writeBit_stop(converted_out_array, get_map_tabela_Z(y), true);

			}
			else
			{
			_writeBit_stop(converted_out_array, get_map_tabela_Z(y), false);
			}
			}
			*/
			load_SDK_output(temp_stop_list_array);
		}

	}



	for (int x = 0; x < ZECER_num; x++)
	{

		if (ZECER.linked_id(x)->get_id_class() == 6)// && ZECER.id(x)->GetState() == true)
		{
			ZECER.linked_id(x)->SetState(false);

		}
	}

	buttn->set_out_state(true);
	//_writeBit(ZECER.OUT_array, buttn->_id_out, true);

	//_writeBit(output_temp, buttn->_id, true);
	//load_zecer_output(output_temp);

}

void on_buttn_combination_deselect(Button_z* buttn)
{

	//_writeBit(ZECER.OUT_array, buttn->_id_out, false);
	buttn->set_out_state(false);
	/*_writeBit(output_temp, buttn->_id, false);
	load_zecer_output(output_temp);*/

}

byte find_first_num()
{
	for (int x = 0; x < ZECER.BUTTN_NUM; x++)
	{
		if (ZECER.id(x)->get_id_class() == class_COMBINATION)
		{
			return x;
		}
	}
}
byte find_last_num()
{
	byte id = 0;
	for (int x = 0; x < ZECER.BUTTN_NUM; x++)
	{
		if (ZECER.id(x)->get_id_class() == class_COMBINATION)
		{
			id = x;
		}
	}
	return id;
}
byte find_next_num(byte id_chosen)
{
	byte id = 255;
	for (int x = id_chosen + 1; x < ZECER.BUTTN_NUM; x++)
	{
		if (ZECER.id(x)->get_id_class() == class_COMBINATION)
		{
			id = x;
			DEBUG_print(F("next "));
			DEBUG_println(id);
			return id;
		}
	}

	

	if (id == 255){
		DEBUG_print(F("next "));
		DEBUG_println(id);
		return find_first_num();
	}
	
}
byte find_prev_num(byte id_chosen)
{
	byte id = 255;
	if (id_chosen<1)
	return 0;

	for (int x = id_chosen-1; x > 0; x--)
	{
		if (ZECER.id(x)->get_id_class() == class_COMBINATION)
		{
			id = x;
			DEBUG_print(F("next "));
			DEBUG_println(id);
			return id;
		}
	}
}

void check_previous_combination()
{
	bool load_previous=true;
	for(int x=0;x<20;x++)
	{
		if(temp_stop_list_array[x]!=0)
		{
			load_previous=false;
			break;
		}
		
	}

	if(load_previous==true)
	{
		
		
		for (int x = 0; x < STOP_mgr.Stop_count; x++)
		{
			if (STOP_mgr.id(x)->GetState() == true)//TODO: temp fix, negiraj izhode
			_writeBit_stop(temp_stop_list_array, x, true);
			else
			_writeBit_stop(temp_stop_list_array, x, false);
		}

	}
}

void on_buttn_PLUS(Button_z* buttn)
{
	buttn->set_out_state(true);


	#ifdef ZECER_2X_AMERIKA
	byte num_count = 16;
	#endif
	
	#ifdef ZECER_1X
	byte num_count = 8;
	#endif

	if (CRESCENDO_STATE)
	return;


	for (int x = 0; x < ZECER_num; x++)//ugasni gumbe
	{
		if (ZECER.linked_id(x)->get_id_class() == class_FIX_COMBINATION_MAN_1 || ZECER.linked_id(x)->get_id_class() == class_FIX_COMBINATION_MAN_2 || ZECER.linked_id(x)->get_id_class() == class_FIX_COMBINATION_MAN_3)
		ZECER.linked_id(x)->SetState(false);
	}


	if ((ZECER.id(BUTTN_SET_1)->GetState()||ZECER.id(BUTTN_SET_2)->GetState()) && (buttn->get_id_class() != class_FIX_COMBINATION_MAN_1 || buttn->get_id_class() != class_FIX_COMBINATION_MAN_2 || buttn->get_id_class() != class_FIX_COMBINATION_MAN_3))
	{
		//DEBUG_print("write STOP ");

		for (int x = 0; x < STOP_mgr.Stop_count; x++)
		{
			//DEBUG_print(F("stop state: "));
			//DEBUG_print(STOP_mgr.id(x)->GetState());
			//DEBUG_print(F(" ID: "));
			//DEBUG_print(x);
			//DEBUG_print(F(" ;;link ID: "));
			//DEBUG_println(STOP_mgr.linked_id(x)->get_ID());


			if (STOP_mgr.id(x)->GetState() == true)//TODO: temp fix, negiraj izhode
			_writeBit_stop(temp_stop_list_array, x, true);
			else
			_writeBit_stop(temp_stop_list_array, x, false);
		}

		for (int x = 0; x < ZECER_num; x++)
		{
			if (ZECER.linked_id(x)->get_id_class() == 6 && ZECER.linked_id(x)->GetState() == true)
			{
				ZECER.linked_id(x)->SetState(false);

			}
		}

		if (SETTER_combination > num_count){//prej 8

			//if (SD_work._connection == true)
			//{
			//SD_work.Write_zecer_combination(USER_ID, 0, SETTER_combination, temp_stop_list_array);
			//COMBINATION_LABEL_FIRST_letter = (String)SETTER_combination + " SAVED";
			//}
			//else
			{
				

				ZECER.id(0)->set_mem_location( ADDRESS_note + SETTER_combination * 10);
				ZECER.id(0)->write_mem(temp_stop_list_array);
				DEBUG_print(F("pise naprej"));
				DEBUG_println(ZECER.id(0)->get_mem_location());

				COMBINATION_LABEL_FIRST_letter = (String)SETTER_combination + " SAVED";
				//buttn->write_mem(temp_stop_list_array);//iz eeproma
			}
		}

		DEBUG_println(F("sem pride"));
		return;
	}



	SETTER_combination++;

	if (ZECER.id(BUTTN_10_1)->GetState() == true ||ZECER.id(BUTTN_10_2)->GetState() == true)
	{
		SETTER_combination = SETTER_combination + 9;
	}
	else if (ZECER.id(BUTTN_100_1)->GetState() == true||ZECER.id(BUTTN_100_2)->GetState() == true )
	{
		SETTER_combination = SETTER_combination + 99;
	}
	if (SD_work._connection == false)
	{
		if (SETTER_combination > 999)
		SETTER_combination = 999;
	}
	else if (SD_work._connection == true)
	{
		if (SETTER_combination > 999)
		SETTER_combination = 999;
	}

	if (SETTER_combination <= num_count)
	{
		ZECER.id(SETTER_combination)->SetState(true);
		return;
	}

	for (int x = 0; x < ZECER_num; x++)//temp fix
	{
		if (ZECER.linked_id(x)->get_id_class() == class_COMBINATION && ZECER.linked_id(x)->GetState() == true)
		{
			ZECER.linked_id(x)->SetState(false);
		}
	}


	if (STOP_type == LED_MANUBRI)
	{
		//if (SD_work._connection == true)
		//SD_work.Read_zecer_combination(USER_ID, buttn->get_id_class(), SETTER_combination, temp_stop_list_array);
		//else
		{
			ZECER.id(0)->set_mem_location( ADDRESS_note + SETTER_combination*10);
			//ZECER.id(0)->_mem_location = ADDRESS_note + SETTER_combination * 10;
			
			//pusti spodaj
			ZECER.id(0)->read_mem(temp_stop_list_array);
			check_previous_combination();

		}
		COMBINATION_LABEL_FIRST_letter = (String)SETTER_combination;
		
		for (int y = 0; y < STOP_mgr.Stop_count; y++)
		{
			if (_readBit_stop(temp_stop_list_array, y) == true)
			{
				//DEBUG_print(F("stop state: "));
				//DEBUG_print(STOP_mgr.id(y)->GetState());
				//DEBUG_print(F(" ID: "));
				//DEBUG_print(y);
				//DEBUG_print(F(" ;link ID: "));
				//DEBUG_println(STOP_mgr.linked_id(y)->get_ID());
				STOP_mgr.id(y)->SetState(true);
			}
			else
			{
				STOP_mgr.id(y)->SetState(false);
			}
		}
	}
	else if (STOP_type == SDK_MANUBRI)
	{
		ZECER.id(0)->set_mem_location( ADDRESS_note + SETTER_combination * 10);
		//ZECER.id(0)->_mem_location = ADDRESS_note + SETTER_combination * 10;
		ZECER.id(0)->read_mem(temp_stop_list_array);
		check_previous_combination();

		COMBINATION_LABEL_FIRST_letter = (String)SETTER_combination;

		DEBUG_print(F("bere naprej"));
		DEBUG_println(250 + SETTER_combination * 10);

		load_SDK_output(temp_stop_list_array);
	}




	//_writeBit(ZECER.OUT_array, buttn->_id_out, true);
	//_writeBit(output_temp, buttn->_id, true);
	//load_zecer_output(output_temp);

}
void on_buttn_PLUS_deselect(Button_z* buttn)
{
	buttn->set_out_state(false);
	//_writeBit(ZECER.OUT_array, buttn->_id_out, false);
	//_writeBit(output_temp, buttn->_id, false);
	//load_zecer_output(output_temp);
}

void on_buttn_MINUS(Button_z* buttn)
{
	buttn->set_out_state(true);
	
	#ifdef ZECER_2X_AMERIKA
	byte num_count = 16;
	#endif
	
	#ifdef ZECER_1X
	byte num_count = 8;
	#endif

	if (CRESCENDO_STATE)
	return;


	SETTER_combination--;

	if (SETTER_combination == num_count)
	{
		DEBUG_println(F("tu vrže ven"));
		ZECER.id(num_count)->SetState(true);
		buttn->set_out_state(true);
		return;
	}




	if (ZECER.id(BUTTN_10_1)->GetState() == true ||ZECER.id(BUTTN_10_2)->GetState() == true)
	{
		SETTER_combination = SETTER_combination - 9;
	}
	else if (ZECER.id(BUTTN_100_1)->GetState() == true || ZECER.id(BUTTN_100_2)->GetState() == true)
	{
		SETTER_combination = SETTER_combination - 99;
	}
	
	if (SETTER_combination < 0)
	SETTER_combination = 1;

	if (SETTER_combination < num_count)
	{
		if (SETTER_combination == 0)
		{
			SETTER_combination = 1;
			ZECER.id(1)->SetState(true);
		}
		else
		ZECER.id(SETTER_combination)->SetState(true);
		return;
	}

	for (int x = 0; x < ZECER_num; x++)//temp fix
	{
		if (ZECER.linked_id(x)->get_id_class() == class_COMBINATION && ZECER.linked_id(x)->GetState() == true)
		{
			ZECER.linked_id(x)->SetState(false);
		}
	}


	if (STOP_type == LED_MANUBRI)
	{
		//if (SD_work._connection == true)
		//SD_work.Read_zecer_combination(USER_ID, buttn->get_id_class(), SETTER_combination, temp_stop_list_array);
		//else
		{
			ZECER.id(0)->set_mem_location( ADDRESS_note + SETTER_combination * 10);
			//ZECER.id(0)->_mem_location = ADDRESS_note + SETTER_combination * 10;
			ZECER.id(0)->read_mem(temp_stop_list_array);
			check_previous_combination();
			//DEBUG_print(F("setter comb: "));
			//DEBUG_println(SETTER_combination);
			//DEBUG_print(F("location: "));
			//DEBUG_println(ADDRESS_note + SETTER_combination * 10);
		}
		COMBINATION_LABEL_FIRST_letter = (String)SETTER_combination;

		for (int y = 0; y < STOP_mgr.Stop_count; y++)
		{
			if (_readBit_stop(temp_stop_list_array, y) == true)
			{
				STOP_mgr.id(y)->SetState(true);
			}
			else
			{
				STOP_mgr.id(y)->SetState(false);
			}
		}
	}
	else if (STOP_type == SDK_MANUBRI)
	{
		ZECER.id(0)->set_mem_location(ADDRESS_note + SETTER_combination * 10);
		//ZECER.id(0)->_mem_location = ADDRESS_note + SETTER_combination * 10;
		ZECER.id(0)->read_mem(temp_stop_list_array);
		check_previous_combination();

		COMBINATION_LABEL_FIRST_letter = (String)SETTER_combination;

		DEBUG_print(F("bere naprej"));
		DEBUG_println(250 + SETTER_combination * 10);

		load_SDK_output(temp_stop_list_array);
	}



	buttn->set_out_state(true);
}
void on_buttn_MINUS_deselect(Button_z* buttn)
{
	buttn->set_out_state(false);
}

void on_buttn_FIX_COMBINATION(Button_z* buttn)
{
	buttn->set_out_state(true);
}
void on_buttn_FIX_COMBINATION_deselect(Button_z* buttn)
{
	buttn->set_out_state(false);
}

void on_buttn_RESET(Button_z* buttn)
{

	if (CRESCENDO_STATE)
	return;
	COMBINATION_LABEL_FIRST_letter = "0";

	for (int x = 0; x < 10; x++)
	{
		temp_stop_list_array[x] = pgm_read_word_near(array_Reset + x);
	}

	for (int x = 0; x < ZECER.BUTTN_NUM; x++)
	//for (int x = 0; x < B; x++)
	{
		//DEBUG_println(ZECER.id(x));
		//DEBUG_println(ZECER.id(x)->GetState());
		if (ZECER.linked_id(x)->get_id_class() == 2 || ZECER.linked_id(x)->get_id_class() == class_FIX_COMBINATION_MAN_1 ||ZECER.linked_id(x)->get_id_class() == class_FIX_COMBINATION_MAN_2 || ZECER.linked_id(x)->get_id_class() == class_FIX_COMBINATION_MAN_3)// && ZECER.id(x)->GetState() == true)
		{
			ZECER.linked_id(x)->SetState(false);
		}
	}

	if (STOP_type == LED_MANUBRI)
	{

		for (int x = 0; x < STOP_mgr.Stop_count; x++)
		{
			//èe je že vklopljen ga ne vklapljaj ponovno
			if (STOP_mgr.id(x)->GetState() != false)
			STOP_mgr.id(x)->SetState(false);
		}
	}
	else if (STOP_type == SDK_MANUBRI)
	{

		load_SDK_output(temp_stop_list_array);
	}

	buttn->set_out_state(true);
}
void on_buttn_RESET_deselect(Button_z* buttn)
{
	//DEBUG_println(F("reset deselect"));
	buttn->set_out_state(false);
}
void temptest()
{}
void on_Stop_select_function(Stop* stop)
{

}
void on_Stop_deselect_function(Stop* stop)
{
	
}

//STOPS methods
void on_Stop_dummy(Stop* stop)
{
}
//STOPS methods
byte state_TROMPETE_8;
byte state_CLARION_4;
byte state_POSAUNE_16;
byte state_TROMPETE_8_ped;
byte state_KRUMHORN;
byte state_SCHALMEI;
byte state_TROMPETE_HARMONIQ;
byte state_OBOE;
byte state_FAGOTT;

void chech_Z(Stop* stop)
{
	switch (stop->get_ID())
	{
		case TROMPETE_8:
		state_TROMPETE_8 = true;
		stop->SetState_only(false);
		break;
		case CLARION_4:
		state_CLARION_4 = true;
		stop->SetState_only(false);
		break;
		case POSAUNE_16:
		state_POSAUNE_16 = true;
		stop->SetState_only(false);
		break;
		case TROMPETE_8_ped:
		state_TROMPETE_8_ped = true;
		stop->SetState_only(false);
		break;
		case KRUMHORN:
		state_KRUMHORN = true;
		stop->SetState_only(false);
		break;
		case SCHALMEI:
		state_SCHALMEI = true;
		stop->SetState_only(false);
		break;
		case TROMPETE_HARMONIQ:
		state_TROMPETE_HARMONIQ = true;
		stop->SetState_only(false);
		break;
		case OBOE:
		state_OBOE = true;
		stop->SetState_only(false);
		break;
		case FAGOTT:
		state_FAGOTT = true;
		stop->SetState_only(false);
		break;
		default:

		break;
	}
}



bool midi_out=false;
byte prev_transpose_val=0;

void transpose_keychecker(byte *buttn_tab_HIGH, byte *buttn_tab_old_HIGH,byte *buttn_tab_LOW, byte *buttn_tab_old_LOW, byte _MANUAL)
{
	for(int x=0;x<key_arr_size;x++)
	{
		//if(buttn_tab_LOW[x]!=buttn_tab_old_LOW[x])//pojdi najprej primerjat bajt, šele potem bite v tem bajtu: okoli 4 do 8x hitreje
		{
			for (int i = x*8; i < (x+1)*8; i++)
			{
				
				if (G_bit(buttn_tab_LOW,i)==true){
					//if ((G_bit(buttn_tab_LOW,i) !=G_bit(buttn_tab_old_LOW,i)))
					{
						if(i>=37-6&&i<=37+6)
						{
							
							value_TRANSPOSE=i-37+TRANS_adjust;
							if(value_TRANSPOSE==prev_transpose_val)
							return;
							DEBUG_STRING_print("TRANS VAL");
							DEBUG_println(value_TRANSPOSE);
							EEPROM.update(add_VALUE_TRANSPOSE, value_TRANSPOSE);
							
							MENU_mgr.quick_fix_TRANSPOSE(value_TRANSPOSE);
							
							MIDI_sender.mute_all_sounds();
							
							MENU_mgr.resend_notes();
							for (int i = 0; i < 90; i++){
								
								S_bit(k_MAN_I_L,i,false);
								S_bit(k_MAN_II_L,i,false);
								S_bit(k_MAN_III_L,i,false);
								S_bit(k_PED,i,false);
								
							}
							prev_transpose_val=value_TRANSPOSE;
							return;
						}
						
						//menu_main_screen1_zecer_label_TRANSPOSE.draw_normal();
					}
				}
				
				
				
			}
		}
	}
	
	
	
}


void help_keysender(byte *buttn_tab_HIGH, byte *buttn_tab_old_HIGH,byte *buttn_tab_LOW, byte *buttn_tab_old_LOW, byte _MANUAL)
{
	for(int x=0;x<key_arr_size;x++)
	{
		if(buttn_tab_LOW[x]!=buttn_tab_old_LOW[x])//pojdi najprej primerjat bajt, šele potem bite v tem bajtu: okoli 4 do 8x hitreje
		{
			for (int i = x*8; i < (x+1)*8; i++)
			{
				
				if (G_bit(buttn_tab_LOW,i)==true){
					if ((G_bit(buttn_tab_LOW,i) !=G_bit(buttn_tab_old_LOW,i)))
					{
						
						MIDI_sender.send_note_DREAM(i, true, _MANUAL,127);
						S_bit(buttn_tab_old_LOW,i,G_bit(buttn_tab_LOW,i)) ;
					}
				}
				else
				{
					if ((G_bit(buttn_tab_LOW,i) !=G_bit(buttn_tab_old_LOW,i)))
					{
						
						MIDI_sender.send_note_DREAM(i, false, _MANUAL,0);
						S_bit(buttn_tab_old_LOW,i,G_bit(buttn_tab_LOW,i));
					}
				}
			}
		}
	}
	
	
	
}

void help_record_key_input(byte *buttn_tab_HIGH, byte *buttn_tab_old_HIGH,byte *buttn_tab_LOW, byte *buttn_tab_old_LOW, byte _MANUAL)
{
	for(int x=0;x<key_arr_size;x++)
	{
		if(buttn_tab_LOW[x]!=buttn_tab_old_LOW[x])//pojdi najprej primerjat bajt, šele potem bite v tem bajtu: okoli 4 do 8x hitreje
		{
			for (int i = x*8; i < (x+1)*8; i++)
			{
				
				if (G_bit(buttn_tab_LOW,i)==true){
					if ((G_bit(buttn_tab_LOW,i) !=G_bit(buttn_tab_old_LOW,i)))
					{
						
						SD_work.recording_add_note(_MANUAL,i,true);
						//MIDI_sender.send_note_DREAM(i, true, _MANUAL,127);
						S_bit(buttn_tab_old_LOW,i,G_bit(buttn_tab_LOW,i)) ;
					}
				}
				else
				{
					if ((G_bit(buttn_tab_LOW,i) !=G_bit(buttn_tab_old_LOW,i)))
					{
						SD_work.recording_add_note(_MANUAL,i,false);
						//MIDI_sender.send_note_DREAM(i, false, _MANUAL,0);
						S_bit(buttn_tab_old_LOW,i,G_bit(buttn_tab_LOW,i));
					}
				}
			}
		}
	}
}

void help_keysender1(byte *buttn_tab_LOW, byte *buttn_tab_old_LOW, byte _MANUAL)
{
	
	
	for(int x=0;x<key_arr_size;x++)
	{
		if(buttn_tab_LOW[x]!=buttn_tab_old_LOW[x])//ponosen na tale trik :) -pojdi najprej primerjat bajt, šele potem bite v tem bajtu: okoli 4 do 8x hitreje
		{
			for (int i = x*8; i < (x+1)*8; i++)
			{
				
				if (G_bit(buttn_tab_LOW,i)==true){
					if ((G_bit(buttn_tab_LOW,i) !=G_bit(buttn_tab_old_LOW,i)))
					{
						
						MIDI_sender.send_note_DREAM(i, true, _MANUAL,127);
						S_bit(buttn_tab_old_LOW,i,G_bit(buttn_tab_LOW,i)) ;
					}
				}
				else
				{
					if ((G_bit(buttn_tab_LOW,i) !=G_bit(buttn_tab_old_LOW,i)))
					{
						
						MIDI_sender.send_note_DREAM(i, false, _MANUAL,0);
						S_bit(buttn_tab_old_LOW,i,G_bit(buttn_tab_LOW,i));
					}
				}
			}
		}
	}
	return;
	for (int i = 0; i < 90; i++){
		
		if (G_bit(buttn_tab_LOW,i)==true){
			if ((G_bit(buttn_tab_LOW,i) !=G_bit(buttn_tab_old_LOW,i)))
			{
				MIDI_sender.send_note_DREAM(i, true, _MANUAL,127);
				S_bit(buttn_tab_old_LOW,i,G_bit(buttn_tab_LOW,i)) ;
			}
		}
		else
		{
			if ((G_bit(buttn_tab_LOW,i) !=G_bit(buttn_tab_old_LOW,i)))
			{
				MIDI_sender.send_note_DREAM(i, false, _MANUAL,0);
				S_bit(buttn_tab_old_LOW,i,G_bit(buttn_tab_LOW,i)) ;
			}

		}
		
	}
	
}


void help_edit_array_SUB_SUP(byte stop_id,byte copy_low_array[], byte high_array[],byte high_array_old[],byte low_array[],byte low_array_old[],byte ini_start_value,byte ini_end_value,byte sum_number)
{
	return;
	if (STOP_mgr.id(stop_id)->GetState() == true)
	{
		if(sum_number==sum_SUP)
		{
			for (int i = 76; i >= 12; i--)
			{
				if (copy_low_array[i] > 0)
				{
					high_array[i+12] = high_array[i];
					low_array[i+12]=low_array[i];
					high_array_old[i+12] = high_array_old[i];
					low_array_old[i+12]=low_array_old[i];
				}
			}

		}
		else if(sum_number==sum_SUB)
		{
			for  (int i = 12 ; i < 76; i++)
			{
				if (copy_low_array[i] > 0)
				{
					high_array[i-12] = high_array[i];
					low_array[i-12]=low_array[i];
					high_array_old[i-12] = high_array_old[i];
					low_array_old[i-12]=low_array_old[i];
				}
			}

		}
	}
	
}


void Zecer_stop_mgr::help_refresh_note(Stop* stop,bool note_on_off)
{
	
	
	return;
	DEBUG_println(stop->get_ID());
	//
	//for (int i = 0; i < 90; i++){
	//if (G_bit(k_MAN_I_L,i)==true)
	//{
	//MIDI_sender.sendNote_MIDI_out(stop->get_MIDI_out_numb(),i+23,127,1,note_on_off);
	//DEBUG_println(F("KEY "));
	//DEBUG_println(i);
	//}
	//}
	//
	//
	//return;

	
	DEBUG_println(F("refresh note"));
	byte *buttn_tab=k_MAN_I_L;
	byte man;
	
	
	switch (stop->get_active_on_manual())
	{
		case MANUAL_1:
		buttn_tab=k_MAN_I_L;
		break;
		case MANUAL_2:
		buttn_tab=k_MAN_II_L;
		break;
		case MANUAL_3:
		buttn_tab=k_MAN_III_L;
		break;
		case MANUAL_4:
		break;
		case MANUAL_5:
		break;
		case PEDAL:
		buttn_tab=k_PED;
		break;
	};
	
	for (int i = 0; i < 90; i++){
		if (G_bit(buttn_tab,i)==true)
		{
			//int key, bool on_off, int manual, byte velocity
			//MIDI_sender.send_note_DREAM(i,note_on_off,stop->get_active_on_manual(),note_on_off);
			//	MIDI_sender.rec_note_helper(i,127,true,stop->get_active_on_manual());
			MIDI_sender.sendNote_MIDI_out(stop->get_MIDI_out_numb(),i,127,stop->get_MIDI_CH(),note_on_off);
			//	DEBUG_println(F("KEY "));
			//	DEBUG_println(i);
		}
	}

}
void help_refresh_note_manual(byte MANUAL_ID,byte OUT_ID,byte COMMON_CH)
{

	byte *buttn_tab=k_MAN_I_L;


	switch (MANUAL_ID)
	{
		case MANUAL_1:
		buttn_tab=k_MAN_I_L;
		break;
		case MANUAL_2:
		buttn_tab=k_MAN_II_L;
		break;
		case MANUAL_3:
		buttn_tab=k_MAN_III_L;
		break;
		case MANUAL_4:
		break;
		case MANUAL_5:
		break;
		case PEDAL:
		buttn_tab=k_PED;
		break;
	};

	
	for (int i = 0; i < 90; i++)
	{
		if (G_bit(buttn_tab,i)==true)
		{
			DEBUG_print(F("key "));
			DEBUG_println(i);
			MIDI_sender.rec_note_helper(i,127,true,MANUAL_ID);
			MIDI_sender.sendNote_MIDI_out(OUT_ID,i,127,COMMON_CH,true);
			//	DEBUG_println(F("KEY "));
			//	DEBUG_println(i);
		}
	}

	
}
void Zecer_stop_mgr::Stop_headphones_change(boolean on_off)
{

	if(on_off)
	HEADPHONE_FIX=41;
	else
	HEADPHONE_FIX=0;
	
	//DEBUG_println(F("refresh ALL"));
	byte *buttn_tab=k_MAN_I_L;
	Stop *temp_stop;

	for(int x=0;x<=40;x++)
	{
		
		temp_stop=STOP_mgr.id(x);
		switch (temp_stop->get_active_on_manual())
		{
			case MANUAL_1:
			buttn_tab=k_MAN_I_L;
			break;
			case MANUAL_2:
			buttn_tab=k_MAN_II_L;
			break;
			case MANUAL_3:
			buttn_tab=k_MAN_III_L;
			break;
			case MANUAL_4:
			break;
			case MANUAL_5:
			break;
			case PEDAL:
			buttn_tab=k_PED;
			break;
		};
		bool on_off=temp_stop->GetState();
		
		if(on_off==true)
		{
			temp_stop->SetState(false);
			temp_stop->SetState(true);
		}
		//return;
		//
		//for (int i = 0; i < 90; i++)
		//{
		//if (G_bit(buttn_tab,i)==on_off)
		//{
		//DEBUG_print(F("key "));
		//DEBUG_println(i);
		//MIDI_sender.sendNote_MIDI_out(temp_stop->get_MIDI_out_numb(),i+23,127,temp_stop->get_MIDI_CH(),on_off);
		////	DEBUG_println(F("KEY "));
		////	DEBUG_println(i);
		//}
		//}

		
	}
	//if(HEADPHONE_FIX!=0)
	//{
	//for(int x=0;x<41;x++)
	//{
	//int mem_add=STOPS_START_ADDRESSES+((x+HEADPHONE_FIX+2)*5);//p_menu_item->getMemAddress();
	//
	//byte midi_channel=STOP_mgr.id(x)->get_MIDI_CH();
	//byte midi_out=STOP_mgr.id(x)->get_MIDI_out_numb();
	//
	//if(midi_out!=0)
	//{
	//byte value1=EEPROM.read(mem_add+1);
	//byte value2=EEPROM.read(mem_add+2);
	//byte value3=EEPROM.read(mem_add+3);
	//byte value4=EEPROM.read(mem_add+4);
	//
	//DEBUG_STRING_print("mem read->");
	//DEBUG_println(mem_add);
	//
	////EEPROM.write(START_ADD+42+x,64);
	////EEPROM.write(START_ADD+84+x,127);
	////EEPROM.write(START_ADD+84+42+x,0x40);
	////EEPROM.write(START_ADD+84+84+x,0x40);
	//
	//MIDI_sender.send_MIDI_code(CODE_PAN,value1,midi_channel,midi_out);
	//MIDI_sender.send_MIDI_code(CODE_STOP_VOL,value2,midi_channel,midi_out);
	//MIDI_sender.send_MIDI_code(CODE_TVF_RESONANCE,value3,midi_channel,midi_out);
	//MIDI_sender.send_MIDI_code(CODE_TVF_CUTOFF,value4,midi_channel,midi_out);
	//}
	//}
	//
	//}else
	//if(HEADPHONE_FIX==0)
	{
		for(int x=0;x<41;x++)
		{
			int mem_add=STOPS_START_ADDRESSES+((x+HEADPHONE_FIX)*5);//p_menu_item->getMemAddress();

			byte midi_channel=STOP_mgr.id(x)->get_MIDI_CH();
			byte midi_out=STOP_mgr.id(x)->get_MIDI_out_numb();
			
			if(midi_out!=0)
			{
				byte value1=EEPROM.read(mem_add+1);
				byte value2=EEPROM.read(mem_add+2);
				byte value3=EEPROM.read(mem_add+3);
				byte value4=EEPROM.read(mem_add+4);

				//DEBUG_STRING_print("stop->");
				//DEBUG_println(get_stop_name(x));
				//DEBUG_STRING_print(" mem read->");
				//DEBUG_println(mem_add);
				
				

				MIDI_sender.send_MIDI_code(CODE_PAN,value1,midi_channel,midi_out);
				
				double procenti;
				
				if(STOP_mgr.id(x)->get_active_on_manual()==MANUAL_1)
				procenti=EEPROM.read(ADD_menu_b1_man_I_lvl);
				else if(STOP_mgr.id(x)->get_active_on_manual()==MANUAL_2)
				procenti=EEPROM.read(ADD_menu_b1_man_II_lvl);
				else if(STOP_mgr.id(x)->get_active_on_manual()==PEDAL)
				procenti=EEPROM.read(ADD_menu_b1_man_PED_lvl);
				
				
				double calc_var=(double)value2*(double)procenti/100;
				
				MIDI_sender.send_MIDI_code(CODE_STOP_VOL,calc_var,midi_channel,midi_out);
				MIDI_sender.send_MIDI_code(CODE_TVF_RESONANCE,value3,midi_channel,midi_out);
				MIDI_sender.send_MIDI_code(CODE_TVF_CUTOFF,value4,midi_channel,midi_out);
			}
		}
		
		
		
	}
	
}

void on_stop_EVENT(Stop* stop,bool ON_OFF)
{
	//DEBUG_print(F("stop event->"));
	//DEBUG_println(ON_OFF);
	
	STOP_mgr.refresh_STOP_OUTPUT=true;
	
	if (SD_work.get_is_recording())
	SD_work.recording_add_stop_change(stop, ON_OFF);
	
	if(stop->get_STOP_type()==type_NORMAL_STOP)
	{
		if(ON_OFF)
		{
			on_stop_ON(stop);
			STOP_mgr.CURRENT_stop=stop->get_ID();
		}
		else
		on_stop_OFF(stop);
	}
	else if(stop->get_STOP_type()==type_COUPLER)
	{
		if(ON_OFF)
		on_stop_ON(stop);
		else
		on_stop_OFF(stop);
	}
	else if(stop->get_STOP_type()==type_SUBOKTAVA)
	{
		if(ON_OFF)
		on_stop_ON(stop);
		else
		on_stop_OFF(stop);
	}
	else if(stop->get_STOP_type()==type_SUPEROKTAVA)
	{
		if(ON_OFF)
		on_stop_ON(stop);
		else
		on_stop_OFF(stop);
	}
	else if(stop->get_STOP_type()==type_TREMULANT)
	{
		if(ON_OFF)
		on_stop_tremulant_ON(stop);
		else
		on_stop_tremulant_OFF(stop);
	}
}

#define ADD_COUNT 41

void set_rank_mode(byte MODUL_OUT_ID,bool state)
{
	switch (MODUL_OUT_ID)
	{
		case MIDI_1:
		MODUL_1_ranks_LOW_MODE=state;
		break;
		
		case MIDI_2:
		MODUL_2_ranks_LOW_MODE=state;
		break;
		
		case MIDI_3:
		MODUL_3_ranks_LOW_MODE=state;
		break;
		
		case MIDI_4:
		MODUL_4_ranks_LOW_MODE=state;
		break;
	}
}


bool rank_limiter_help(byte MODUL_OUT_ID,byte COOMON_CHANNEL, byte counter)
{

	if(counter>STOP_LIMIT)
	{
		switch (MODUL_OUT_ID)
		{
			case MIDI_1:
			if(MODUL_1_ranks_LOW_MODE==true)
			{
				
				return false;
			}
			
			break;
			
			case MIDI_2:
			if(MODUL_2_ranks_LOW_MODE==true)
			return false;
			break;
			
			case MIDI_3:
			if(MODUL_3_ranks_LOW_MODE==true)
			{
				DEBUG_println(F("low mode"));
				return false;
			}
			break;
			
			case MIDI_4:
			if(MODUL_4_ranks_LOW_MODE==true)
			return false;
			break;
		}
		

		Stop *temp_stop;
		MIDI_sender.sendControlChange_MIDI_out(MODUL_OUT_ID,123, 0,COOMON_CHANNEL);
		for(int x=0;x<STOP_mgr.Stop_count;x++)
		{
			
			temp_stop=STOP_mgr.id(x);
			if(temp_stop->get_MIDI_out_numb()==MODUL_OUT_ID&&temp_stop->GetState()&&temp_stop->get_midi_common_ch()==COMMON_MIDI_CH1)
			{
				if(temp_stop->get_midi_common_ch()==COOMON_CHANNEL)
				{
					MIDI_sender.sendProgramChange_MIDI_out(temp_stop->get_MIDI_out_numb(),temp_stop->get_ID()+1+ADD_COUNT,temp_stop->get_MIDI_CH());
				}
			}

			bool on_off=temp_stop->GetState();
			
		}
		
		return true;
	}
	else
	{
		set_rank_mode(MODUL_OUT_ID,false);
		return false;
	}
	
	
	
}

bool rank_limiter_help_off(byte MODUL_OUT_ID,byte COOMON_CHANNEL, byte counter)
{

	if(counter<=STOP_LIMIT)
	{
		switch (MODUL_OUT_ID)
		{
			case MIDI_1:
			if(MODUL_1_ranks_LOW_MODE==true)
			{
				DEBUG_println(F("ni ok"));
				return false;
			}
			
			break;
			
			case MIDI_2:
			if(MODUL_2_ranks_LOW_MODE==true)
			return false;
			break;
			
			case MIDI_3:
			if(MODUL_3_ranks_LOW_MODE==true)
			{
				DEBUG_println(F("low mode"));
				return false;
			}
			break;
			
			case MIDI_4:
			if(MODUL_4_ranks_LOW_MODE==true)
			return false;
			break;
		}
		
		DEBUG_println(F("PREKLOPI NAZAJ"));
		
		Stop *temp_stop;
		MIDI_sender.sendControlChange_MIDI_out(MODUL_OUT_ID,123, 0,COOMON_CHANNEL);
		for(int x=0;x<STOP_mgr.Stop_count;x++)
		{
			
			temp_stop=STOP_mgr.id(x);
			if(temp_stop->get_MIDI_out_numb()==MODUL_OUT_ID&&temp_stop->GetState()&&temp_stop->get_midi_common_ch()==COMMON_MIDI_CH1)
			{
				if(temp_stop->get_midi_common_ch()==COOMON_CHANNEL)
				{
					MIDI_sender.sendProgramChange_MIDI_out(temp_stop->get_MIDI_out_numb(),temp_stop->get_ID()+1,temp_stop->get_MIDI_CH());
				}
			}

			bool on_off=temp_stop->GetState();
			
		}
		
		return true;
	}
	else
	{
		set_rank_mode(MODUL_OUT_ID,false);
		return false;
	}
	
	
	
}

void on_stop_ON(Stop* stop)
{
	DEBUG_print(F("stop on->"));
	DEBUG_println(stop->get_ID());
	//switch(stop->get_MIDI_out_numb())
	
	if (_z_state == false)
	{
		switch (stop->get_ID())
		{
			case TROMPETE_8:
			state_TROMPETE_8 = true;
			break;
			case CLARION_4:
			state_CLARION_4 = true;
			break;
			case POSAUNE_16:
			state_POSAUNE_16 = true;
			break;
			case TROMPETE_8_ped:
			state_TROMPETE_8_ped = true;
			break;
			case KRUMHORN:
			state_KRUMHORN = true;
			break;
			case SCHALMEI:
			state_SCHALMEI = true;
			break;
			case TROMPETE_HARMONIQ:
			state_TROMPETE_HARMONIQ = true;
			break;
			case OBOE:
			state_OBOE = true;
			break;
			case FAGOTT:
			state_FAGOTT = true;
			break;
			default:

			break;
		}

	}
	else
	{
		switch (stop->get_ID())
		{
			case TROMPETE_8:
			stop->SetState_only(false);
			break;
			case CLARION_4:
			stop->SetState_only(false);
			break;
			case POSAUNE_16:
			stop->SetState_only(false);
			break;
			case TROMPETE_8_ped:
			stop->SetState_only(false);
			break;
			case KRUMHORN:
			stop->SetState_only(false);
			break;
			case SCHALMEI:
			stop->SetState_only(false);
			break;
			case TROMPETE_HARMONIQ:
			stop->SetState_only(false);
			break;
			case OBOE:
			stop->SetState_only(false);
			break;
			case FAGOTT:
			stop->SetState_only(false);
			break;
			default:

			break;
		}
		return;
	}



	#ifdef SET_KEYS
	byte oktav_mode = return_oktav_mode(stop);
	stop_LABEL_TEXT = ((String)read_STOP_velocity(stop, oktav_mode));
	#endif // SET_KEYS



	//MIDI_sender.sendSysEx(2, preklop_MIDI2, false);
	MIDI_sender.sendProgramChange_MIDI_out(stop->get_MIDI_out_numb(),stop->get_ID()+1+HEADPHONE_FIX,stop->get_MIDI_CH());//PROGRAM CHANGE 0 , MIDI KANAL 1  //DOLOÈIŠ DA JE REGISTER (id od registra) NA KANALU id od registra (trenutno samo za test je stop id enak midi kanalu)
	byte midi_event[3];
	midi_event[0]=95+stop->get_MIDI_CH();
	midi_event[1]=stop->get_ID()+1;
	//midi_event[2]=velocity;
	
	//SD_work.rec_midi_event(midi_event,stop->get_MIDI_out_numb(),2);
	
	Z_S_mgr.help_refresh_note(stop,true);
	//byte talk_to_board[]= { 0xF5,1};//NASTAVI NA PRVO PLATO ZA TEST

	//for(int x=1;x<=4;x++)
	//{
	//talk_to_board[1]= x;
	//MIDI_sender.sendSysEx(2, talk_to_board, false);
	//
	//MIDI_sender.sendProgramChange(stop->ID,stop->ID);
	//
	//help_keysender_resend(k_MAN_I,k_MAN_I_old,1,true);
	//}
	
	//for(int x=30;x<50;x++)
	//{
	//MIDI_sender.send_note_DREAM(x,true,MANUAL_1,127);
	//}
	//
	//delay(100);
	//for(int x=30;x<50;x++)
	//{
	//MIDI_sender.send_note_DREAM(x,false,MANUAL_1,127);
	//}
	
}
byte prev_SUB_1 = -1;
byte prev_SUPER_1 = -1;
byte prev_SUB_2 = -1;
byte prev_SUPER_2 = -1;
byte prev_SUB_3 = -1;
byte prev_SUPER_3 = -1;


void on_stop_OFF(Stop* stop)
{
	//switch(stop->get_MIDI_out_numb())
	
	
	MIDI_sender.sendProgramChange_MIDI_out(stop->get_MIDI_out_numb(),0x0,stop->get_MIDI_CH());
	Z_S_mgr.help_refresh_note(stop,false);

	
}





bool first_read = true;

void  Zecer_stop_mgr::read_gas_pedal()
{
	//return;
	if (first_read)
	{
		DEBUG_println(F("first read"));
		gas1_max = EEPROMReadlong(add_gas1_max);
		gas1_min = EEPROMReadlong(add_gas1_min);

		gas2_max = EEPROMReadlong(add_gas2_max);
		gas2_min = EEPROMReadlong(add_gas2_min);
		first_read=false;
	}
	MIDI_sender.send_midi_active_sense();
	gas1_temp = analogRead(GAS1_pin);
	gas2_temp = analogRead(GAS2_pin);

	#ifdef DEMO_BOARD
	//gas1_temp = 127;
	gas2_temp = 127;
	#endif // DEMO_BOARD

	

	
	
	if (gas2_temp > gas2_max)
	{
		EEPROMWriteLong(add_gas2_max, gas2_temp);DEBUG_println(2);
	}
	if (vol_temp > vol_max)
	{
		//EEPROMWriteLong(add_vol_max, vol_temp);DEBUG_println(3);
		vol_temp=vol_max;
	}

	if (gas1_temp > gas1_max && (digitalRead2(ENCODER_PIN_ENTER) == false && digitalRead2(ENCODER_PIN_BACK) == false))//nastavi limite
	{
		EEPROMWriteLong(add_gas1_max, gas1_temp);
		//DEBUG_println(1);
	}
	
	if (gas2_temp > gas2_max)
	{
		EEPROMWriteLong(add_gas2_max, gas2_temp);DEBUG_println(2);
	}
	if (vol_temp > vol_max)
	{
		//EEPROMWriteLong(add_vol_max, vol_temp);DEBUG_println(3);
		vol_temp=vol_max;
	}

	if (gas1_temp < gas1_min)
	{
		EEPROMWriteLong(add_gas1_min, gas1_temp);DEBUG_println(4);
	}
	
	//pomembno da pustiš takole
	gas1_max = EEPROMReadlong(add_gas1_max);
	gas2_max = EEPROMReadlong(add_gas2_max);

	gas1_min = EEPROMReadlong(add_gas1_min);
	gas2_min = EEPROMReadlong(add_gas2_min);

	if (gas1_temp <= gas1_min)
	gas1_temp = gas1_min;
	if (gas1_temp >= gas1_max)
	gas1_temp = gas1_max;

	if (gas2_temp <= gas2_min)
	gas2_temp = gas2_min;
	if (gas2_temp >= gas2_max)
	gas2_temp = gas2_max;

	if (vol_temp <= vol_min)
	vol_temp = vol_min;
	if (vol_temp >= vol_max)
	vol_temp = vol_max;



	GAS_PED_1 = map(gas1_temp, gas1_max, gas1_min, 127, 60);//od do
	GAS_PED_man2 = map(gas1_temp, gas1_max, gas1_min, 127, 0);//od do
	//GAS_PED_man2 = map(gas2_temp, gas2_max, gas2_min, 127, 60);//od do
	GAS_PED_2 = map(gas2_temp, gas2_max, gas2_min, 127,0);//od do
	byte GAS_PED_2_local = map(gas2_temp, gas2_max, gas2_min, 15, 0);//od do
	
	
	//DEBUG_println(GAS_PED_1);
	#ifdef _RODGERS
	GAS_PED_1 = 127;
	#endif // RODGER

		

	if (CRESCENDO_STATE == true && (GAS_PED_2 > old_gas_ped_2 + 1 || GAS_PED_2 < old_gas_ped_2 - 1 || GAS_PED_2 == 0 && old_gas_ped_2 != 0 || GAS_PED_2 == 127 && old_gas_ped_2 != 127))
	{
		old_gas_ped_2 = GAS_PED_2;
		GAS2_refresh = true;
	}

	if(CRESCENDO_STATE == false && (GAS_PED_man2 > old_gas_ped_man2 + 1 || GAS_PED_man2 < old_gas_ped_man2 - 1 || GAS_PED_man2 == 0 && old_gas_ped_man2 != 0 || GAS_PED_man2 == 127 && old_gas_ped_man2 != 127))
	{
		//MIDI_sender.send_midi_volume_change_manual(MANUAL_2, GAS_PED_2);
		old_gas_ped_man2 = GAS_PED_man2;
		GAS2_ped_refresh = true;
	}

	if (GAS_PED_1 > old_gas_ped_1 + 1 || GAS_PED_1 < old_gas_ped_1 - 1 || GAS_PED_1 == 0 && old_gas_ped_1 != 0 || GAS_PED_1 == 127 && old_gas_ped_1 != 127)
	{
	DEBUG_STRING_print("gas ");
	DEBUG_println(GAS_PED_1);
		MIDI_sender.send_midi_volume_change_manual(MANUAL_2, GAS_PED_1);
		old_gas_ped_1 = GAS_PED_1;
		GAS1_refresh = true;
	}


}
byte old_MASTER_VOLUME = -1;

void Zecer_stop_mgr::on_test(String text)
{

	//	DEBUG_println(text);
	if (SD_work._connection == true)
	SD_work.Read_zecer_combination(USER_ID, 10, 20, temp_stop_list_array);
}
void Zecer_stop_mgr::read_master_volume()
{
	vol_temp = analogRead(MASTER_VOLUME_PIN);
	//DEBUG_println(vol_temp);
	MASTER_VOLUME = map(vol_temp, 1023, 0, 127, 0);//od do


	if (old_MASTER_VOLUME != MASTER_VOLUME)
	{

		
		MIDI_sender.send_midi_MASTER_volume_change();
		old_MASTER_VOLUME = MASTER_VOLUME;
		MASTER_VOL_refresh = true;
	}


}

void load_SDK_output(byte* output)
{
	


	//start_time = millis();
	//
	//load_SDK_output_all(output);
	//
	//DEBUG_println(millis() - start_time);
	//DEBUG_println(F(" ->time: "));
	//return;
	//
	//
	//
	//for (int x = 0; x < 20; x++)
	//{
	//mag_out_stop_list_array[x] = 0;
	//manubri_temp[x] = 0;
	//}
	////preberi iz flasha
	//
	//for (int x = 0; x < 10; x++)
	//{
	//if (bitRead(output[x], 4) == false)
	//bitWrite(output[x], 4, true);
	//else if (bitRead(output[x], 4) == true)
	//bitWrite(output[x], 4, false);
	//
	//if (bitRead(output[x], 5) == false)
	//bitWrite(output[x], 5, true);
	//else if (bitRead(output[x], 5) == true)
	//bitWrite(output[x], 5, false);
	//}
	//
	//mag_out_stop_list_array[0] = ~output[0];
	//mag_out_stop_list_array[1] = output[0];//inverted
	//
	//mag_out_stop_list_array[2] = ~output[1];
	//mag_out_stop_list_array[3] = output[1];//inverted
	//
	//mag_out_stop_list_array[9] = output[4];//inverted
	//
	//mag_out_stop_list_array[4] = ~output[2];
	//mag_out_stop_list_array[5] = output[2];//inverted
	//
	//mag_out_stop_list_array[6] = ~output[3];
	//mag_out_stop_list_array[7] = output[3];//inverted
	//
	//mag_out_stop_list_array[8] = ~output[4];
	//mag_out_stop_list_array[10] = ~output[5];
	//mag_out_stop_list_array[11] = output[5];//inverted
	//
	//mag_out_stop_list_array[12] = ~output[6];
	//mag_out_stop_list_array[13] = output[6];//inverted
	//
	//mag_out_stop_list_array[14] = ~output[7];
	//mag_out_stop_list_array[15] = output[7];//inverted
	//
	//mag_out_stop_list_array[16] = ~output[8];
	//mag_out_stop_list_array[17] = output[8];//inverted
	//
	//mag_out_stop_list_array[18] = ~output[9];
	//mag_out_stop_list_array[19] = output[9];//inverted
	//
	//
	//for (int x = 0; x <= 12; x = x + 2)
	//{
	////DEBUG_println();
	////briši/nastavi polje na 0
	//for (int t = 0; t < 20; t++)
	//{
	//manubri_temp[t] = 0;
	//}
	//
	//switch (x)
	//{
	//case 0:
	//manubri_temp[0] = mag_out_stop_list_array[0];
	//manubri_temp[1] = mag_out_stop_list_array[1];
	//
	//manubri_temp[6] = mag_out_stop_list_array[6];
	//manubri_temp[7] = mag_out_stop_list_array[7];
	//break;
	//case 2:
	//manubri_temp[2] = mag_out_stop_list_array[2];
	//manubri_temp[3] = mag_out_stop_list_array[3];
	//
	//manubri_temp[8] = mag_out_stop_list_array[8];
	//manubri_temp[9] = mag_out_stop_list_array[9];
	//break;
	//case 4:
	//manubri_temp[4] = mag_out_stop_list_array[4];
	//manubri_temp[5] = mag_out_stop_list_array[5];
	//
	//manubri_temp[10] = mag_out_stop_list_array[10];
	//manubri_temp[11] = mag_out_stop_list_array[11];
	//break;
	//case 6:
	//
	//manubri_temp[12] = mag_out_stop_list_array[12];
	//manubri_temp[13] = mag_out_stop_list_array[13];
	//break;
	//
	//default:
	//break;
	//}
	//
	//
	//manubri_na_nulo();
	//
	////t.stop(0);
	////manubri right
	//digitalWrite(SS_595_STOPS1, LOW);
	//
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[13]);
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[12]);
	//
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[11]);
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[10]);
	//
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[9]);
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[8]);
	//
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[7]);
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[6]);
	//
	//digitalWrite(SS_595_STOPS1, HIGH);
	//
	//
	////manubri left
	//
	//digitalWrite(SS_595_STOPS1, LOW);
	//
	//shiftOut(MOSI_595_STOPS1, CLK_STOPS1, LSBFIRST, manubri_temp[5]);
	//shiftOut(MOSI_595_STOPS1, CLK_STOPS1, LSBFIRST, manubri_temp[4]);
	//
	//shiftOut(MOSI_595_STOPS1, CLK_STOPS1, LSBFIRST, manubri_temp[3]);
	//shiftOut(MOSI_595_STOPS1, CLK_STOPS1, LSBFIRST, manubri_temp[2]);
	//
	//shiftOut(MOSI_595_STOPS1, CLK_STOPS1, LSBFIRST, manubri_temp[1]);
	//shiftOut(MOSI_595_STOPS1, CLK_STOPS1, LSBFIRST, manubri_temp[0]);
	//
	//digitalWrite(SS_595_STOPS1, HIGH);
	//
	//
	////delay(30);
	//start_time = millis();
	//
	//while (true)
	//{
	////delay(1);
	//Z_S_mgr.read_Keyboards();
	////read_Keyboards();
	//Z_S_mgr.read_MIDIC_pedal();
	//
	//if (millis() - start_time > 33)
	//break;
	//}
	//
	////t.after(30, manubri_na_nulo);
	//manubri_na_nulo();
	//
	//}
	//
	//
	//manubri_na_nulo();

}

void load_SDK_output_all(byte* output)
{

	//for (int x = 0; x < 20; x++)
	//{
	//mag_out_stop_list_array[x] = 0;
	//manubri_temp[x] = 0;
	//}
	////preberi iz flasha
	//
	//for (int x = 0; x < 10; x++)
	//{
	//if (bitRead(output[x], 4) == false)
	//bitWrite(output[x], 4, true);
	//else if (bitRead(output[x], 4) == true)
	//bitWrite(output[x], 4, false);
	//
	//if (bitRead(output[x], 5) == false)
	//bitWrite(output[x], 5, true);
	//else if (bitRead(output[x], 5) == true)
	//bitWrite(output[x], 5, false);
	//}
	//
	//mag_out_stop_list_array[0] = ~output[0];
	//mag_out_stop_list_array[1] = output[0];//inverted
	//
	//mag_out_stop_list_array[2] = ~output[1];
	//mag_out_stop_list_array[3] = output[1];//inverted
	//
	//mag_out_stop_list_array[9] = output[4];//inverted
	//
	//mag_out_stop_list_array[4] = ~output[2];
	//mag_out_stop_list_array[5] = output[2];//inverted
	//
	//mag_out_stop_list_array[6] = ~output[3];
	//mag_out_stop_list_array[7] = output[3];//inverted
	//
	//mag_out_stop_list_array[8] = ~output[4];
	//mag_out_stop_list_array[10] = ~output[5];
	//mag_out_stop_list_array[11] = output[5];//inverted
	//
	//mag_out_stop_list_array[12] = ~output[6];
	//mag_out_stop_list_array[13] = output[6];//inverted
	//
	//mag_out_stop_list_array[14] = ~output[7];
	//mag_out_stop_list_array[15] = output[7];//inverted
	//
	//mag_out_stop_list_array[16] = ~output[8];
	//mag_out_stop_list_array[17] = output[8];//inverted
	//
	//mag_out_stop_list_array[18] = ~output[9];
	//mag_out_stop_list_array[19] = output[9];//inverted
	//
	//
	//for (int x = 0; x <= 2; x = x + 2)
	//{
	////DEBUG_println();
	////briši/nastavi polje na 0
	//
	//for (int t = 0; t < 20; t++)
	//{
	//manubri_temp[t] = 0;
	//}
	//
	//switch (x)
	//{
	//case 0:
	//manubri_temp[0] = mag_out_stop_list_array[0];
	//manubri_temp[1] = mag_out_stop_list_array[1];
	//
	//manubri_temp[4] = mag_out_stop_list_array[4];
	//manubri_temp[5] = mag_out_stop_list_array[5];
	//
	//manubri_temp[6] = mag_out_stop_list_array[6];
	//manubri_temp[7] = mag_out_stop_list_array[7];
	//
	//manubri_temp[12] = mag_out_stop_list_array[12];
	//manubri_temp[13] = mag_out_stop_list_array[13];
	//
	//
	//break;
	//
	//case 2:
	//manubri_temp[2] = mag_out_stop_list_array[2];
	//manubri_temp[3] = mag_out_stop_list_array[3];
	//
	//manubri_temp[8] = mag_out_stop_list_array[8];
	//manubri_temp[9] = mag_out_stop_list_array[9];
	//
	//manubri_temp[10] = mag_out_stop_list_array[10];
	//manubri_temp[11] = mag_out_stop_list_array[11];
	//break;
	//
	//default:
	//break;
	//}
	//
	//
	//manubri_na_nulo();
	//
	////t.stop(0);
	////manubri right
	//digitalWrite(SS_595_STOPS1, LOW);
	//
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[13]);
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[12]);
	//
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[11]);
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[10]);
	//
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[9]);
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[8]);
	//
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[7]);
	//shiftOut(MOSI_595_STOPS1, CLK_stop_pin_r, LSBFIRST, manubri_temp[6]);
	//
	//digitalWrite(SS_595_STOPS1, HIGH);
	//
	//
	////manubri left
	//
	//digitalWrite(LOAD_595_R, LOW);
	//
	//shiftOut(DATA_595_R, CLK_STOPS1, LSBFIRST, manubri_temp[5]);
	//shiftOut(DATA_595_R, CLK_STOPS1, LSBFIRST, manubri_temp[4]);
	//
	//shiftOut(DATA_595_R, CLK_STOPS1, LSBFIRST, manubri_temp[3]);
	//shiftOut(DATA_595_R, CLK_STOPS1, LSBFIRST, manubri_temp[2]);
	//
	//shiftOut(DATA_595_R, CLK_STOPS1, LSBFIRST, manubri_temp[1]);
	//shiftOut(DATA_595_R, CLK_STOPS1, LSBFIRST, manubri_temp[0]);
	//
	//digitalWrite(LOAD_595_R, HIGH);
	//
	//
	////delay(30);
	//start_time = millis();
	//
	//while (true)
	//{
	////delay(1);
	//Z_S_mgr.read_Keyboards();
	////read_Keyboards();
	//Z_S_mgr.read_MIDIC_pedal();
	//
	//if (millis() - start_time > 30)
	//break;
	//}
	//
	////t.after(30, manubri_na_nulo);
	//manubri_na_nulo();
	//
	//}
	//
	//
	//manubri_na_nulo();

}

//void Zecer_stop_mgr::test_array(bool orgArray[])
//{
//calculate_free_RAM(77);
//delay(300);
//for (int i = 0; i < 90; i++)
//{
//DEBUG_print(orgArray[i]);
//
//if (orgArray[i] == true)
//{
//DEBUG_print("X");
//}
//
//}
//DEBUG_println();
//}


#define NOT_PLAY 250
#define novi_bass1
#ifdef novi_bass




bool refresh_test=FALSE;


#define id_FIRST 0
#define id_SEC 1
#define id_THIRD 2
#define id_CURRENT 0
#define id_PREV 1
#define id_OLD 2
byte note_lowest=NOT_PLAY;
bool note_activated=false;

byte history[3][3] = {
	{NOT_PLAY,NOT_PLAY,NOT_PLAY},
	{NOT_PLAY,NOT_PLAY,NOT_PLAY},
	{NOT_PLAY,NOT_PLAY,NOT_PLAY}};


	void Zecer_stop_mgr::help_edit_for_BASS(byte *orgArray,byte *destArray,byte ini_start_value,byte ini_end_value)
	{
		
		byte bass_FIRST=NOT_PLAY;
		byte bass_SEC=NOT_PLAY;
		byte bass_THIRD=NOT_PLAY;
		bool found_bass1=false;
		bool found_bass2=false;
		bool found_bass3=false;
		
		for (int i = ini_start_value; i <= ini_end_value; i++)
		{

			if (G_bit(orgArray,i) > 0)
			{
				if(!found_bass1)
				{
					bass_FIRST=i;
					found_bass1=true;
				}
				else if(!found_bass2)
				{
					bass_SEC=i;
					found_bass2=true;

				}
				else if(!found_bass3)
				{
					bass_THIRD=i;
					break;
				}

			}
			
		}
		
		if(history[id_CURRENT][id_FIRST]!=bass_FIRST||
		history[id_CURRENT][id_SEC]!=bass_SEC||
		history[id_CURRENT][id_THIRD]!=bass_THIRD)
		{
			
			memcpy( history[id_OLD], history[id_PREV],3 );//2 v 3
			memcpy( history[id_PREV], history[id_CURRENT],3 );//2 v 3
			
			history[id_CURRENT][id_FIRST]=bass_FIRST;
			history[id_CURRENT][id_SEC]=bass_SEC;
			history[id_CURRENT][id_THIRD]=bass_THIRD;
			
			refresh_test=true;
		}

		if(history[id_CURRENT][id_FIRST]<=history[id_PREV][id_FIRST]&&
		history[id_CURRENT][id_FIRST]<=note_lowest)
		{
			//DEBUG_STRING_print("  1N:");
			//DEBUG_print(history[id_CURRENT][id_FIRST]);
			//DEBUG_STRING_print("  2N:");
			//DEBUG_print(history[id_CURRENT][id_SEC]);
			//DEBUG_STRING_print("  3N:");
			//DEBUG_println(history[id_CURRENT][id_THIRD]);
			//
			//DEBUG_STRING_print("  1P:");
			//DEBUG_print(history[id_PREV][id_FIRST]);
			//DEBUG_STRING_print("  2P:");
			//DEBUG_print(history[id_PREV][id_SEC]);
			//DEBUG_STRING_print("  3P:");
			//DEBUG_println(history[id_PREV][id_THIRD]);
			//
			note_lowest=history[id_CURRENT][id_FIRST];
			
			
			S_bit(destArray,history[id_CURRENT][id_FIRST],true);//DEBUG_STRING_print("     IF1:");
		}
		
		else if(history[id_CURRENT][id_FIRST]==history[id_PREV][id_SEC])
		{

			if(history[id_CURRENT][id_FIRST]-history[id_PREV][id_FIRST]<=2)
			{
				if(history[id_CURRENT][id_FIRST]!=history[id_OLD][id_FIRST])
				{
					if(history[id_PREV][id_SEC]!=history[id_OLD][id_THIRD])
					{
						S_bit(destArray,history[id_CURRENT][id_FIRST],true);
						
						if(refresh_test)
						{
							refresh_test=false;
							
							DEBUG_STRING_print("  1NOW:");
							DEBUG_print(history[id_CURRENT][id_FIRST]);
							DEBUG_STRING_print("  1PRE:");
							DEBUG_print(history[id_PREV][id_FIRST]);
							DEBUG_STRING_print("  1OLD:");
							DEBUG_println(history[id_OLD][id_FIRST]);
							
							DEBUG_STRING_print("  2NOW:");
							DEBUG_print(history[id_CURRENT][id_SEC]);
							DEBUG_STRING_print("  2NPRE:");
							DEBUG_print(history[id_PREV][id_SEC]);
							DEBUG_STRING_print("  2OLD:");
							DEBUG_println(history[id_OLD][id_SEC]);
							
							
							DEBUG_STRING_print("  3NOW:");
							DEBUG_print(history[id_CURRENT][id_THIRD]);
							
							DEBUG_STRING_print("  3PRE:");
							DEBUG_print(history[id_PREV][id_THIRD]);
							
							DEBUG_STRING_print("  3OLD:");
							DEBUG_println(history[id_OLD][id_THIRD]);
							DEBUG_println();
						}
					}
				}
				
			}
			
		}
		if(refresh_test)
		{
			refresh_test=false;
			
			DEBUG_STRING_print("  1NOW:");
			DEBUG_print(history[id_CURRENT][id_FIRST]);
			DEBUG_STRING_print("  1PRE:");
			DEBUG_print(history[id_PREV][id_FIRST]);
			DEBUG_STRING_print("  1OLD:");
			DEBUG_println(history[id_OLD][id_FIRST]);
			
			DEBUG_STRING_print("  2NOW:");
			DEBUG_print(history[id_CURRENT][id_SEC]);
			DEBUG_STRING_print("  2NPRE:");
			DEBUG_print(history[id_PREV][id_SEC]);
			DEBUG_STRING_print("  2OLD:");
			DEBUG_println(history[id_OLD][id_SEC]);
			
			
			DEBUG_STRING_print("  3NOW:");
			DEBUG_print(history[id_CURRENT][id_THIRD]);
			
			DEBUG_STRING_print("  3PRE:");
			DEBUG_print(history[id_PREV][id_THIRD]);
			
			DEBUG_STRING_print("  3OLD:");
			DEBUG_println(history[id_OLD][id_THIRD]);
			DEBUG_println();
		}
		if(!found_bass1)
		{
			note_activated=false;
			note_lowest=NOT_PLAY;
		}
		if(!found_bass2)
		{
			note_lowest=bass_FIRST;
		}
		
		
		if(history[id_CURRENT][id_FIRST]==history[id_OLD][id_SEC])
		note_activated=true;
		
		return;
		
		if(bass_FIRST!=history[id_OLD][id_SEC])
		{note_activated=false;
			delay(100);
		}else
		note_activated=true;
	}
	#endif

	#define stari_bass
	#ifdef stari_bass

	float last_bass_time=0;

	void Zecer_stop_mgr::help_edit_for_BASS(byte *orgArray,byte *destArray,byte ini_start_value,byte ini_end_value)
	{
		byte exception_plus1=255;
		byte exception_plus2=255;
		
		for (int i = ini_start_value; i <= ini_end_value; i++)
		{

			if (G_bit(orgArray,i) > 0)
			{
				
				if(i<_bass_1+2)
				{
					if(millis()-last_bass_time<300)
					{
						exception_plus1=i;
					}
				}
				
				if(exception_plus1!=255)
				_bass_1=exception_plus1;
				
				if(i>_bass_1&&_bass_1!=255)
				_bass_1=255;
				
				
				
				
				if(G_bit(k_MAN_I_L_old,i) == 0)
				{
					_bass_1=i;
					last_bass_time=millis();
					
				}
				if(_bass_1!=255)
				S_bit(destArray,_bass_1,true);
				return;
			}
		}
		
		_bass_1=255;
		
	}

	#endif
	void Zecer_stop_mgr::help_edit_for_MELODY(byte *orgArray,byte *destArray,byte ini_start_value,byte ini_end_value)
	{
		bool found1=false;
		bool found2=false;
		
		for (int i = ini_start_value; i >= ini_end_value; i--)
		{
			if (G_bit(orgArray,i) > 0)
			{
				if(found1==false)
				{
					_melod_1=i;
					
					if(_melod_1==_melod_2)
					return;
					found1=true;
				}

				else if(found2==false)
				{
					_melod_2=i;
					found2=true;
					S_bit(destArray,_melod_1,G_bit(orgArray,_melod_1));
					return;
				}
				else
				{
					S_bit(destArray,_melod_1,G_bit(orgArray,_melod_1));
					return;
				}
				//DEBUG_println(i);
				
			}
			
		}
		if(found1==true)
		{
			S_bit(destArray,_melod_1,G_bit(orgArray,_melod_1));
		}
		else
		_melod_1=255;
		
		_melod_2=255;
	}

	void Zecer_stop_mgr::help_edit_array(byte stop_id,byte *orgArray,byte *destArray,byte ini_start_value,byte ini_end_value)
	{
		if (STOP_mgr.id(stop_id)->GetState() == true)
		{
			for (int i = ini_start_value; i >= ini_end_value; i--)
			{
				if (G_bit(orgArray,i) > 0)
				{
					S_bit(destArray,i,G_bit(orgArray,i));
					//destArray[i] = orgArray[i];
				}
			}
		}
		
	}

	//void Zecer_stop_mgr::help_edit_array_SUB_SUP_MANUAL_I(byte stop_id,byte copy_low_array[], byte high_array1[],byte high_array_old1[],byte low_array2[],byte low_array_old2[],byte ini_start_value,byte ini_end_value,byte sum_number)
	//{
	//
	//if (STOP_mgr.id(stop_id)->GetState() == true)
	//{
	//if(sum_number==sum_SUP)
	//{
	//for (int i = 63; i >= 0; i--)
	//{
	//if (G_bit(copy_low_array,i) > 0)
	//{
	//S_bit(low_array,i+12,G_bit(copy_low_array,i));
	////destArray[i] = orgArray[i];
	//}
	//}
	//
	//}
	//else if(sum_number==sum_SUB)
	//{
	//for  (int i = 25 ; i < 76; i++)
	//{
	//if (G_bit(copy_low_array,i) > 0)
	//{
	//S_bit(low_array,i-12,G_bit(copy_low_array,i));
	////destArray[i] = orgArray[i];
	//}
	//}
	//
	//}
	//}
	//
	//}
	//

	void Zecer_stop_mgr::help_edit_array_SUB_SUP(byte stop_id,byte copy_low_array[], byte high_array[],byte high_array_old[],byte low_array[],byte low_array_old[],byte ini_start_value,byte ini_end_value,byte sum_number)
	{
		
		if (STOP_mgr.id(stop_id)->GetState() == true)
		{
			if(sum_number==sum_SUP)
			{
				for (int i = 63; i >= 0; i--)
				{
					if (G_bit(copy_low_array,i) > 0)
					{
						S_bit(low_array,i+12,G_bit(copy_low_array,i));
						//destArray[i] = orgArray[i];
					}
				}

			}
			else if(sum_number==sum_SUB)
			{
				for  (int i = 25 ; i < 76; i++)
				{
					if (G_bit(copy_low_array,i) > 0)
					{
						S_bit(low_array,i-12,G_bit(copy_low_array,i));
						//destArray[i] = orgArray[i];
					}
				}

			}
		}
		
	}

	#define BitVal(data,y) ( (data>>y) & 1)      /** Return Data.Y value   **/
	#define SetBit(data,y)    data |= (1 << y)    /** Set Data.Y   to 1    **/
	#define ClearBit(data,y)  data &= ~(1 << y)   /** Clear Data.Y to 0    **/
	#define TogleBit(data,y)     (data ^=BitVal(y))     /** Togle Data.Y  value  **/
	#define Togle(data)   (data =~data )         /** Togle Data value     **/


	const GPIO_pin_t DATA_164_keyboard_FAST = DP7;
	const GPIO_pin_t CLK_164_keyboard_FAST = DP3;
	const GPIO_pin_t DATA_165_keyboard_FAST = DP8;
	const GPIO_pin_t LOAD_165_keyboard_FAST = DP9;
	const GPIO_pin_t CLK_pin_FAST = DP2;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool finish_playing_fix=false;
	void Zecer_stop_mgr::read_Keyboards()
	{

		if(SD_work.get_is_playing())
		{
			if(SD_work.read_send_midi_event()==false)
			finish_playing_fix=true;
			memcpy( k_MAN_I_L, k_MAN_I_L_recorder,sizeof(k_MAN_I_L));//ne spreminjaj
			memcpy( k_MAN_II_L,k_MAN_II_L_recorder, sizeof(k_MAN_II_L));
			memcpy( k_MAN_III_L, k_MAN_III_L_recorder,sizeof(k_MAN_III_L));
			memcpy( k_PED,k_PED_recorder, sizeof(k_PED));
			
			//DEBUG_STRING_println("test 333");
			//menu_NUM_play_timer.draw_selected();
		}
		else
		{
			
			
			//timer_blinker.update();
			//briši zaradi superoktav
			
			
			
			for (int x = 0; x < 13; x++)
			{
				S_bit(k_PED,x,0);
				S_bit(k_MAN_I_H,x,0);
				S_bit(k_MAN_II_H,x,0);
				S_bit(k_MAN_III_H,x,0);

				S_bit(k_PED,89 - x,0);
				S_bit(k_MAN_I_H,89 - x,0);
				S_bit(k_MAN_II_H,89 - x,0);
				S_bit(k_MAN_III_H,89 - x,0);
				//k_MAN_IV[x] = 0;
				//k_MAN_V[x] = 0;


				//k_MAN_IV[89 - x] = 0;
				//k_MAN_V[89 - x] = 0;

			}
			int calc_id=0;
			
			//return;
			if(EEPROM.read(add_SWAP_KEYBOARD)>1)
			EEPROM.write(add_SWAP_KEYBOARD,0);
			
			bool swap_manual=EEPROM.read(add_SWAP_KEYBOARD);
			
			
			for (int j = 0; j < 8; ++j) //for 0 - 7 do
			{
				
				shiftOut(DATA_164_keyboard, CLK_164_keyboard, MSBFIRST, 1 << j); // bit shift a logic high (1) value by i
				digitalWrite2f(LOAD_165_keyboard_FAST, 0);
				digitalWrite2f(LOAD_165_keyboard_FAST, 1);
				//digitalWrite2(LOAD_165_keyboard, 0);
				//digitalWrite2(LOAD_165_keyboard, 1);


				for (int i = 0; i < 40; i++){
					digitalWrite2f(CLK_pin_FAST, 0);
					//if(i<40)
					S_bit(k_readPin,(39 - i), digitalRead2f(DATA_165_keyboard_FAST));
					digitalWrite2f(CLK_pin_FAST, 1);
					//digitalWrite2(CLK_pin, 1);
				}

				
				
				//for (int i = 16; i < 24; i++){
				//calc_id=get_key_map((j * 8 + (i - 16))) + 13;
				//S_bit(k_MAN_III_L,calc_id,G_bit(k_readPin,i));
				//}
				
				//for (int i = 64; i < 72; i++){
				//calc_id=get_key_map((j * 8 + (i - 24))) + 13;
				//S_bit(k_MAN_II_L,calc_id,G_bit(k_readPin,i));
				//}
				//for (int i = 72; i < 80; i++){
				//calc_id=get_key_map((j * 8 + (i - 32))) + 13;
				//S_bit(k_MAN_II_L,calc_id,G_bit(k_readPin,i));
				//}
				if(swap_manual==false)
				{
					for (int i = 24; i < 32; i++){
						calc_id=get_key_map((j * 8 + (i - 24))) + 13;
						S_bit(k_MAN_II_L,calc_id,G_bit(k_readPin,i));
					}
					for (int i = 32; i < 40; i++){
						calc_id=get_key_map((j * 8 + (i - 32))) + 13;
						S_bit(k_MAN_I_L,calc_id,G_bit(k_readPin,i));
					}
				}
				else
				{
					for (int i = 24; i < 32; i++){
						calc_id=get_key_map((j * 8 + (i - 24))) + 13;
						S_bit(k_MAN_I_L,calc_id,G_bit(k_readPin,i));
					}
					for (int i = 32; i < 40; i++){
						calc_id=get_key_map((j * 8 + (i - 32))) + 13;
						S_bit(k_MAN_II_L,calc_id,G_bit(k_readPin,i));
					}
				}
				
				
				
			}
			
			//return;
			
			//kopiraj èe so vkljuèene vezave, sup,suboktave itd
			//	help_edit_array(II_I,k_MAN_I,k_MAN_II,76,12);
			
			memcpy(k_MAN_I_L_recorder, k_MAN_I_L, sizeof(k_MAN_I_L));//ne spreminjaj
			memcpy(k_MAN_II_L_recorder, k_MAN_II_L, sizeof(k_MAN_II_L));
			memcpy(k_MAN_III_L_recorder, k_MAN_III_L, sizeof(k_MAN_III_L));
			memcpy(k_PED_recorder, k_PED, sizeof(k_PED));
			
		}
		if(SD_work.get_is_recording())//sam test
		{
			
			
			help_record_key_input(k_MAN_I_H, k_MAN_I_H_old,k_MAN_I_L_recorder, k_MAN_I_L_old_recorder, MANUAL_1);
			help_record_key_input(k_MAN_II_H, k_MAN_II_H_old,k_MAN_II_L_recorder, k_MAN_II_L_old_recorder,MANUAL_2);
			help_record_key_input(k_MAN_III_H, k_MAN_III_H_old,k_MAN_III_L_recorder, k_MAN_III_L_old_recorder, MANUAL_3);
			help_record_key_input(k_PED, k_PED_old,k_PED_recorder, k_PED_old_recorder, PEDAL);
		}
		
		help_edit_array(II_I,k_MAN_I_L,k_MAN_II_L,76,12);
		

		help_edit_array(III_I,k_MAN_I_L,k_MAN_III_L,76,12);

		help_edit_array(III_II,k_MAN_II_L,k_MAN_III_L,76,12);
		
		help_edit_array(I_PED,k_PED,k_MAN_I_L,63,0);//tole bo treba naredit še vezave na high
		help_edit_array(II_PED,k_PED,k_MAN_II_L,63,0);
		help_edit_array(III_PED,k_PED,k_MAN_III_L,63,0);
		


		memcpy(tempButton, k_MAN_I_L, sizeof(k_MAN_I_L));//ne spreminjaj

		help_edit_array_SUB_SUP(SUB_I,tempButton,k_MAN_II_H,k_MAN_II_H_old, k_MAN_II_L,k_MAN_II_L_old,12,76,sum_SUB);
		help_edit_array_SUB_SUP(SUPER_I,tempButton,k_MAN_II_H,k_MAN_II_H_old, k_MAN_II_L,k_MAN_II_L_old,12,76,sum_SUP);
		
		//	help_edit_array_SUB_SUP(SUB_I,tempButton,k_MAN_I_H,k_MAN_I_H_old, k_MAN_I_L,k_MAN_I_L_old,12,76,sum_SUB);
		//	help_edit_array_SUB_SUP(SUPER_I,tempButton,k_MAN_I_H,k_MAN_I_H_old, k_MAN_I_L,k_MAN_I_L_old,12,76,sum_SUP);
		

		if(ZECER.id(BUTTN_BASS)->GetState()==true)//to briši
		{
			//DEBUG_println(F("BASS edit"));
			help_edit_for_BASS(k_MAN_I_L,k_PED,0,42);
		}
		memcpy(bass_prev, k_MAN_I_L, sizeof(k_MAN_I_L));//ne spreminjaj

		if(ZECER.id(BUTTN_MELODY)->GetState()==true)
		{
			//DEBUG_println(F("melody edit"));
			help_edit_for_MELODY(k_MAN_I_L,k_MAN_II_L,90,42);
		}
		
		
		memcpy(tempButton, k_MAN_II_L, sizeof(k_MAN_II_L));//ne spreminjaj
		help_edit_array_SUB_SUP(SUB_II,tempButton,k_MAN_II_H,k_MAN_II_H_old, k_MAN_II_L,k_MAN_II_L_old,12,76,sum_SUB);
		help_edit_array_SUB_SUP(SUPER_II,tempButton,k_MAN_II_H,k_MAN_II_H_old, k_MAN_II_L,k_MAN_II_L_old,12,76,sum_SUP);
		
		memcpy(tempButton, k_MAN_III_L, sizeof(k_MAN_III_L));//ne spreminjaj
		help_edit_array_SUB_SUP(SUB_III,tempButton,k_MAN_III_H,k_MAN_III_H_old, k_MAN_III_L,k_MAN_III_L_old,12,76,sum_SUB);
		help_edit_array_SUB_SUP(SUPER_III,tempButton,k_MAN_III_H,k_MAN_III_H_old, k_MAN_III_L,k_MAN_III_L_old,12,76,sum_SUP);
		
		
		
		//EEPROM.update(add_VALUE_TRANSPOSE,8);
		//value_TRANSPOSE=8;
		//MENU_mgr.quick_fix_TRANSPOSE(value_TRANSPOSE);

		
		//menu_main_screen1_zecer_label_TRANSPOSE.draw_normal();


		help_keysender(k_MAN_I_H, k_MAN_I_H_old,k_MAN_I_L, k_MAN_I_L_old, MANUAL_1);//to briši
		help_keysender(k_MAN_II_H, k_MAN_II_H_old,k_MAN_II_L, k_MAN_II_L_old,MANUAL_2);
		help_keysender(k_MAN_III_H, k_MAN_III_H_old,k_MAN_III_L, k_MAN_III_L_old, MANUAL_3);
		
		help_keysender1(k_PED, k_PED_old, PEDAL);//tole popravi ker je treba negirati
		
		if(ZECER.id(BUTTN_SET_1)->GetState())
		{
			
			transpose_keychecker(k_MAN_I_H, k_MAN_I_H_old,k_MAN_I_L, k_MAN_I_L_old, MANUAL_1);
		}
		
		if(finish_playing_fix==true)
		{
			//SD_work.set_playing(false,"");
			finish_playing_fix=false;
		}
		
		return;



		//help_keysender(k_PED, k_MAN_III_old,k_MAN_III_L, k_MAN_III_old_L, PEDAL);
		
		//help_keysender(k_MAN_III, k_MAN_III_old,k_MAN_III_L, k_MAN_III_old_L, MANUAL_3);
		
		
		//help_keysender(k_MAN_IV, k_MAN_IV_old,MANUAL_4);
		//help_keysender(k_MAN_V, k_MAN_V_old, MANUAL_5);
		//help_keysender(k_PED, k_PED_old, 6);//tole popravi ker je treba negirati
		
		//help_keysender(k_MAN_I, k_MAN_I_old, 1);
		//help_keysender(k_MAN_II, k_MAN_II_old,2);
		//help_keysender(k_MAN_III, k_MAN_III_old, 3);
		//
		//help_keysender(k_MAN_I_L, k_MAN_I_old_L, 11);
		//help_keysender(k_MAN_II_L, k_MAN_II_old_L,12);
		//help_keysender(k_MAN_III_L, k_MAN_III_old_L, 13);
		
		//help_checher(k_MAN_III_L, k_MAN_III_old_L, 13);

	}


	void on_buttn_10(Button_z* buttn)//copy
	{
		
		
		DEBUG_println(F("buttn 10: "));
		DEBUG_println(buttn->get_id());
		buttn->set_out_state(true);
		//_writeBit(ZECER.OUT_array, buttn->_id_out, true);
	}
	void on_buttn_10_deselect(Button_z* buttn)
	{
		buttn->set_out_state(false);
		//_writeBit(ZECER.OUT_array, buttn->_id_out, false);
	}
	void on_buttn_100(Button_z* buttn)
	{

		DEBUG_println(F("buttn 100: "));
		DEBUG_println(buttn->get_id());
		buttn->set_out_state(true);
		//_writeBit(ZECER.OUT_array, buttn->_id_out, true);
	}
	void on_buttn_100_deselect(Button_z* buttn)
	{
		//_writeBit(ZECER.OUT_array, buttn->_id_out, false);
		buttn->set_out_state(false);
	}

	void on_buttn_PP(Button_z* buttn)
	{
		COMBINATION_LABEL_FIRST_letter = "PP";
	}
	void on_buttn_PP_deselect(Button_z* buttn)
	{

	}
	void on_buttn_P(Button_z* buttn)
	{
		COMBINATION_LABEL_FIRST_letter = "P";
	}
	void on_buttn_P_deselect(Button_z* buttn)
	{

	}
	void on_buttn_MF(Button_z* buttn)
	{
		COMBINATION_LABEL_FIRST_letter = "MF";
	}
	void on_buttn_MF_deselect(Button_z* buttn)
	{

	}
	void on_buttn_F(Button_z* buttn)
	{
		COMBINATION_LABEL_FIRST_letter = "F";
	}
	void on_buttn_F_deselect(Button_z* buttn)
	{

	}
	void on_buttn_FF(Button_z* buttn)
	{
		COMBINATION_LABEL_FIRST_letter = "FF";
	}
	void on_buttn_FF_deselect(Button_z* buttn)
	{

	}
	void on_buttn_T(Button_z* buttn)
	{
		COMBINATION_LABEL_FIRST_letter = "T";
	}
	void on_buttn_T_deselect(Button_z* buttn)
	{

	}
	void dummy_method(Button_z* buttn)
	{

		DEBUG_println(F("dummy: "));
		DEBUG_println(buttn->get_id());

	}

	void help_method_1(byte stop_name, byte* custom_array)
	{
		if (STOP_mgr.id(stop_name)->GetState() == true)
		_writeBit_stop(custom_array, STOP_mgr.id(stop_name)->get_ID(), false);
		else
		_writeBit_stop(custom_array, STOP_mgr.id(stop_name)->get_ID(), true);
	}
	void help_method_2(byte stop_name,byte state_check, byte* custom_array)
	{
		if (STOP_mgr.id(stop_name)->GetState() == state_check)
		_writeBit_stop(custom_array, STOP_mgr.id(stop_name)->get_ID(), false);
		else
		_writeBit_stop(custom_array, STOP_mgr.id(stop_name)->get_ID(), true);
	}

	void on_foot_piston(Button_z* buttn)
	{
		bool status_ = false;
		DEBUG_print(F("ID buttn foot->"));
		DEBUG_println(buttn->get_id());
		//return;
		byte custom_array[10];

		for (int x = 0; x < STOP_num; x++)
		{

			if (STOP_mgr.id(x)->GetState() == true)
			{
				//DEBUG_print("1");
				_writeBit_stop(custom_array, x, true);
			}
			else
			{
				//DEBUG_print("0");
				_writeBit_stop(custom_array, x, false);
			}

		}
		//DEBUG_println();

		//byte comp = (byte)BUTTN_10;

		switch (buttn->get_id())
		{
			case (byte)BUTTN_CR_foot://CR
			if (CRESCENDO_STATE)
			{
				CRESCENDO_STATE = false;
				COMBINATION_LABEL_FIRST_letter = "";
				MIDI_sender.send_midi_volume_change_manual(MANUAL_2, GAS_PED_man2);//zaradi vklopa/izklopa crescenda da deluje kot zaluzija
			}
			else
			{
				CRESCENDO_STATE = true;
				COMBINATION_LABEL_FIRST_letter = "CRESCENDO";
				MIDI_sender.send_midi_volume_change_manual(MANUAL_2, 127);
			}
			break;

			case (byte)BUTTN_Z_foot://Z

			if (Z_STATE == false)
			{
				Z_STATE = true;
				//COMBINATION_LABEL_Z_letter = "Z off";
			}
			else
			{
				Z_STATE = false;
				//COMBINATION_LABEL_Z_letter = "Z on";
			}
			_z_state = Z_STATE;// = _z_state;



			if (_z_state == true)
			status_ = false;
			else
			status_ = true;


			if (_z_state == false)
			{
				STOP_mgr.id(TROMPETE_8)->SetState(state_TROMPETE_8);
				STOP_mgr.id(CLARION_4)->SetState(state_CLARION_4);
				STOP_mgr.id(POSAUNE_16)->SetState(state_POSAUNE_16);
				STOP_mgr.id(TROMPETE_8_ped)->SetState(state_TROMPETE_8_ped);
				STOP_mgr.id(KRUMHORN)->SetState(state_KRUMHORN);
				STOP_mgr.id(SCHALMEI)->SetState(state_SCHALMEI);
				STOP_mgr.id(TROMPETE_HARMONIQ)->SetState(state_TROMPETE_HARMONIQ);
				STOP_mgr.id(OBOE)->SetState(state_OBOE);
				STOP_mgr.id(FAGOTT)->SetState(state_FAGOTT);
				help_method_2(TROMPETE_8, state_TROMPETE_8, custom_array);
				help_method_2(CLARION_4, state_CLARION_4, custom_array);
				help_method_2(POSAUNE_16, state_POSAUNE_16, custom_array);
				help_method_2(TROMPETE_8_ped, state_TROMPETE_8_ped, custom_array);
				help_method_2(KRUMHORN, state_KRUMHORN, custom_array);
				help_method_2(SCHALMEI, state_SCHALMEI, custom_array);
				help_method_2(TROMPETE_HARMONIQ, state_TROMPETE_HARMONIQ, custom_array);
				help_method_2(OBOE, state_OBOE, custom_array);
				help_method_2(FAGOTT, state_FAGOTT, custom_array);
			}
			else
			{
				STOP_mgr.id(TROMPETE_8)->SetState(false);
				STOP_mgr.id(CLARION_4)->SetState(false);
				STOP_mgr.id(POSAUNE_16)->SetState(false);
				STOP_mgr.id(TROMPETE_8_ped)->SetState(false);
				STOP_mgr.id(KRUMHORN)->SetState(false);
				STOP_mgr.id(SCHALMEI)->SetState(false);
				STOP_mgr.id(TROMPETE_HARMONIQ)->SetState(false);
				STOP_mgr.id(OBOE)->SetState(false);
				STOP_mgr.id(FAGOTT)->SetState(false);
				help_method_2(TROMPETE_8, false, custom_array);
				help_method_2(CLARION_4, false, custom_array);
				help_method_2(POSAUNE_16, false, custom_array);
				help_method_2(TROMPETE_8_ped, false, custom_array);
				help_method_2(KRUMHORN, false, custom_array);
				help_method_2(SCHALMEI, false, custom_array);
				help_method_2(TROMPETE_HARMONIQ, false, custom_array);
				help_method_2(OBOE, false, custom_array);
				help_method_2(FAGOTT, false, custom_array);
			}

			break;

			case (byte)BUTTN_III_II_foot://III-II

			STOP_mgr.id(III_II)->select(true);
			help_method_1(III_II, custom_array);

			break;
			case BUTTN_III_PED_foot://III-PED
			STOP_mgr.id(III_PED)->select(true);
			help_method_1(III_PED, custom_array);
			break;

			case BUTTN_III_I_foot://III-I
			STOP_mgr.id(III_I)->select(true);
			help_method_1(III_I, custom_array);
			break;

			case BUTTN_II_PED_foot://II-PED
			STOP_mgr.id(II_PED)->select(true);
			help_method_1(II_PED, custom_array);
			break;

			case BUTTN_II_I_foot://II-I
			STOP_mgr.id(II_I)->select(true);
			help_method_1(II_I, custom_array);
			break;

			case BUTTN_I_PED_foot://I-PED
			STOP_mgr.id(I_PED)->select(true);
			help_method_1(I_PED, custom_array);
			break;


			case BUTTN_PP_foot:
			ZECER.id(COM_MAN_I_1)->SetState(true);
			break;
			case BUTTN_P_foot:
			ZECER.id(COM_MAN_I_2)->SetState(true);
			break;
			case BUTTN_MF_foot:
			ZECER.id(COM_MAN_I_3)->SetState(true);
			break;
			case BUTTN_F_foot:
			ZECER.id(COM_MAN_I_4)->SetState(true);
			break;
			case BUTTN_FF_foot:
			ZECER.id(COM_MAN_I_5)->SetState(true);
			break;
			case BUTTN_T_foot:
			ZECER.id(COM_MAN_I_6)->SetState(true);
			break;


			default:
			break;
		}

		//load_SDK_output(custom_array);
		//_writeBit(custom_array, x, false);


	}
	void on_foot_piston_deselect(Button_z* buttn)
	{
		//DEBUG_print(F("buttn->"));
		//DEBUG_println(buttn->_id);
	}


	void on_stop_tremulant_ON(Stop* stop)
	{
		MIDI_sender.send_tremulant_key(EEPROM.read(add_VALUE_tremulnat2), stop, true, stop->get_active_on_manual(), true);
		return;
		byte midi_event[3];
		midi_event[0]=95+stop->get_MIDI_CH();
		midi_event[1]=stop->get_ID()+1;
		//midi_event[2]=velocity;
		
		
		
		SD_work.rec_midi_event(midi_event,stop->get_MIDI_out_numb(),2);
	}
	void on_stop_tremulant_OFF(Stop* stop)
	{
		MIDI_sender.send_tremulant_key(0, stop, false, stop->get_active_on_manual(), true);
	}
	//1-SET, 2-kombinacija, 3-plus, 4--minus,5-fix combination,6-reset,7- 10_100 ten,0- dummy

	void test_stops()
	{
		//#define CLK_STOPS1  84
		//#define LOAD_165_STOPS1 A8
		//#define MISO_165_STOPS1  A9
		//#define SS_595_STOPS1  A10
		//#define MOSI_595_STOPS1  12
		
		DEBUG_print(F("OUT stops:"));
		digitalWrite2(LOAD_165_STOPS1, LOW);


		for (int i = ZECER_num - 1; i >= 0; i--)
		{
			digitalWrite2(CLK_STOPS1, 0);

			
			if (ZECER.linked_id(get_map_tabela_Z(i))->GetState() == true)
			{
				digitalWrite2(MOSI_595_STOPS1, HIGH);// DEBUG_print(F("1"));
			}
			else
			{
				digitalWrite2(MOSI_595_STOPS1, LOW);// DEBUG_print(F("0"));
			}

			digitalWrite2(CLK_STOPS1, 1);
		}
		digitalWrite2(LOAD_165_STOPS1, HIGH);
	}

	void load_zecer_output()
	{
		test_stops();
		return;
		
		DEBUG_print(F("OUT:"));
		digitalWrite2(LOAD_595_Z, LOW);


		for (int i = ZECER_num - 1; i >= 0; i--)
		{
			digitalWrite2(CLK_pin, 0);

			
			if (ZECER.linked_id(get_map_tabela_Z(i))->GetState() == true)
			{
				digitalWrite2(DATA_595_Z, HIGH);// DEBUG_print(F("1"));
			}
			else
			{
				digitalWrite2(DATA_595_Z, LOW);// DEBUG_print(F("0"));
			}

			digitalWrite2(CLK_pin, 1);
		}
		digitalWrite2(LOAD_595_Z, HIGH);

		
	}



	void Zecer_stop_mgr::read_MIDIC_pedal()
	{
		
		
		
		bool cancel_bass_check=false;
		
		digitalWrite2(LOAD_165_pedal, 0);
		digitalWrite2(LOAD_165_pedal, 1);

		for (byte i = 0; i < 32; i++)
		{
			digitalWrite2(CLOCK_pedal, 0);

			if (!digitalRead2(DATA_165_pedal))
			{
				//DEBUG_println(i);
				S_bit(k_PED,(get_map_tabela_Z(i) + 13),true);
			}
			
			else
			{
				
				S_bit(k_PED,(get_map_tabela_Z(i) + 13),false);
			}
			
			if (i == 25)//ignore blind pin without resistor
			{
				S_bit(k_PED,(get_map_tabela_Z(i) + 13),false);
			}
			if (i == 24)
			{
				S_bit(k_PED,(get_map_tabela_Z(i) + 13),false);
			}
			
			digitalWrite2(CLOCK_pedal, 1);
		}
		digitalWrite2(LOAD_165_pedal, 0);

	}



	extern int tmpvalue1 = 0;

	int Zecer_stop_mgr::calibrate_gas1_min(int value)
	{
		DEBUG_println(gas1_temp);
		DEBUG_println(analogRead(GAS1_pin));
		EEPROMWriteLong(add_gas1_min, analogRead(GAS1_pin));
		gas1_min = EEPROMReadlong(add_gas1_min);
		return gas1_min;
	}

	byte temp_knob_var[2];


	int Zecer_stop_mgr::calibrate_gas1_max(int value)
	{
		EEPROMWriteLong(add_gas1_max, analogRead(GAS1_pin));
		gas1_max = EEPROMReadlong(add_gas1_max);
		return gas1_max;
	}

	byte counter = 0;
	byte first_time = 0;




	void Zecer_stop_mgr::inputCheck()
	{

		
		counter=4;

		if (counter == 4)
		{
			if (STOP_type == LED_MANUBRI)
			{
				STOP_mgr.read_stopsNormal();
				//if(STOP_mgr.refresh_STOP_OUTPUT==true)
				{
					//DEBUG_STRING_println("LOAD REFRESH STOPS");
					#ifdef RGB_LED_OUTPUT
					load_RGB_stop_output(STOP_mgr.id(0));
					#else
					load_ordinary_stop_output(STOP_mgr.id(0));
					#endif
					STOP_mgr.refresh_STOP_OUTPUT=false;
				}
				
				//
			}

			
			ZECER.read_input();//todo temp izklop
			counter = 0;
		}
		
		

	}



	//
	//int Zecer_stop_mgr::return_stop_by_id(int id)
	//{
	//	for (int x = 0; x < STOP_num; x++)
	//	{
	//		if (Stops_list[x]->_id == id)
	//			return x;
	//	}
	//	return -1;
	//}



