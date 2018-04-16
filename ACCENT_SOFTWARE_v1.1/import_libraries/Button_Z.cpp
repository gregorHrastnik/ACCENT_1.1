//
//
//

#include "Button_Z.h"
#include <EEPROM.h>
#include "global_variables.h"
#include "global_methods.h"
#include "arduino.h"


byte Button_z::read_PROGMEM_info(byte id_data)
{
	byte var = pgm_read_byte(&(buttns_info[_id][id_data]));
	return var;
}

void Button_z::select(bool on_off)
{
	//if(on_off)
	//{
	//DEBUG_println(get_temp_state());
	//DEBUG_println(get_id_class());
	//DEBUG_println(get_state());
	//}

	//set_state(true);
	//set_temp_state(true);
	
	//	DEBUG_println(get_temp_state());
	//	return;
	
	//1-SET, 2-kombinacija, 3-plus, 4--minus,5-fix combination,6-reset
	if(get_id_class() == class_ON_OFF)
	{
		
		
		
		if (get_temp_state() != on_off)
		{
			if (on_off == true)
			{
				if (get_state() == true)
				{
					set_state(false);
					
					if (_on_event != NULL)
					{
						_on_event(this,false);
						DEBUG_print(F("stop on->"));
						
					}
					else
					DEBUG_println(F("null"));
					
				}
				else if (get_state() == false)
				{
					set_state(true);
					if (_on_event != NULL)
					_on_event(this,true);
				}

			}
			set_temp_state(on_off);
		}
		
	}
	else if (get_temp_state() != on_off)
	{

		/*DEBUG_print("id->");
		DEBUG_println(_id);
		*/
		//_on_select(this);

		if (get_id_class() == class_SET || get_id_class() == class_PLUS || get_id_class() == class_MINUS || get_id_class() == class_RESET || get_id_class() == class_10 || get_id_class() == class_100)
		{
			if (on_off == true)
			{
				set_state(true);
				
				if (_on_event != NULL)
				_on_event(this,true);
				
				/*
				rint("ON tipka->");
				DEBUG_println(_id);*/
				//DEBUG_print(F("ON tipka->"));
				//DEBUG_println(_id);
			}

			else
			{
				set_state(false);
				
				if (_on_event != NULL)
				_on_event(this,false);
//
				//DEBUG_print(F("OFF tipka->"));
				//DEBUG_println(_id);

			}
			set_temp_state(on_off);
		}
		else if (get_id_class() == class_COMBINATION || get_id_class() == class_FIX_COMBINATION_MAN_1 || get_id_class() == class_FIX_COMBINATION_MAN_2 || get_id_class() == class_FIX_COMBINATION_MAN_3  || get_id_class() == class_FOOT_FIXED)
		{

			if (on_off == true)
			{
				set_state(true);

				if (_on_event != NULL)
				_on_event(this,true);

				/*DEBUG_print("ON tipka->");
				DEBUG_println(_id);*/
			}

			set_temp_state(on_off);
		}

	}



}

void Button_z::SetState(bool on_off)
{
	if(get_id()==BUTTN_DUMMY)
	return;
	
	set_state(on_off);
	//SetState(on_off);
	if (get_state() == true)
	{
		if (_on_event != NULL)
		_on_event(this,true);
	}
	else
	{
		if (_on_event != NULL)
		_on_event(this,false);
	}
}
bool Button_z::GetState()
{
	return get_state();
}
int ADD_USER_MEM= 12000;
#define user_mem_sum 12000

bool Button_z::write_mem(byte *variable)
{
	long calc_address;
	long tmp_add=USER_ID+1;
	
	long pristej_add=ADD_USER_MEM*tmp_add;
	

	switch(get_id())
	{
		case COM_MAN_I_1:
		calc_address=pristej_add-10;
		break;
		case COM_MAN_I_2:
		calc_address=pristej_add-20;
		break;
		case COM_MAN_I_3:
		calc_address=pristej_add-30;
		break;
		case COM_MAN_I_4:
		calc_address=pristej_add-40;
		break;
		case COM_MAN_I_5:
		calc_address=pristej_add-50;
		break;
		case COM_MAN_I_6:
		calc_address=pristej_add-60;
		break;
		
		default:
		calc_address=get_mem_location()+pristej_add;
		break;
	}

	
	if(extern_eeprom_ok==true)
	{
		
		DEBUG_print(F("WRITE COMBINATION;"));
		DEBUG_println(calc_address);
		byte var_out=~variable[0];
		exEEPROM.write(calc_address + 0,var_out);var_out=~variable[1];
		exEEPROM.write(calc_address + 1,var_out);var_out=~variable[2];
		exEEPROM.write(calc_address + 2,var_out);var_out=~variable[3];
		exEEPROM.write(calc_address + 3,var_out);var_out=~variable[4];
		exEEPROM.write(calc_address + 4,var_out);var_out=~variable[5];
		exEEPROM.write(calc_address + 5,var_out);var_out=~variable[6];
		exEEPROM.write(calc_address + 6,var_out);var_out=~variable[7];
		exEEPROM.write(calc_address + 7,var_out);var_out=~variable[8];
		exEEPROM.write(calc_address + 8,var_out);var_out=~variable[9];
		exEEPROM.write(calc_address + 9,var_out);
	}
	else
	{
		EEPROM.write(calc_address, variable[0]);
		EEPROM.write(calc_address + 1, variable[1]);
		EEPROM.write(calc_address + 2, variable[2]);
		EEPROM.write(calc_address + 3, variable[3]);
		EEPROM.write(calc_address + 4, variable[4]);
		EEPROM.write(calc_address + 5, variable[5]);
		EEPROM.write(calc_address + 6, variable[6]);
		EEPROM.write(calc_address + 7, variable[7]);
		EEPROM.write(calc_address + 8, variable[8]);
		EEPROM.write(calc_address + 9, variable[9]);
	}
	
	

	return true;
}

bool  Button_z::read_mem(byte *variable)
{

	
	//	check_previous_combination();
	//int _mem_location;
	long calc_address;
	long tmp_add=USER_ID+1;
	
	long pristej_add=ADD_USER_MEM*tmp_add;
	
	if(extern_eeprom_ok==true)
	{
		switch(get_id())
		{
			case COM_MAN_I_1:
			calc_address=pristej_add-10;
			break;
			case COM_MAN_I_2:
			calc_address=pristej_add-20;
			break;
			case COM_MAN_I_3:
			calc_address=pristej_add-30;
			break;
			case COM_MAN_I_4:
			calc_address=pristej_add-40;
			break;
			case COM_MAN_I_5:
			calc_address=pristej_add-50;
			break;
			case COM_MAN_I_6:
			calc_address=pristej_add-60;
			break;
			
			default:
			calc_address=get_mem_location()+pristej_add;
			break;
		}
		DEBUG_print(F("READ COMBINATION;"));
		//	DEBUG_println(get_mem_location());
		DEBUG_println(calc_address);
		
		
		variable[0] = ~exEEPROM.read(calc_address);
		variable[1] = ~exEEPROM.read(calc_address + 1);
		variable[2] = ~exEEPROM.read(calc_address + 2);
		variable[3] = ~exEEPROM.read(calc_address + 3);
		variable[4] = ~exEEPROM.read(calc_address + 4);
		variable[5] = ~exEEPROM.read(calc_address + 5);
		variable[6] = ~exEEPROM.read(calc_address + 6);
		variable[7] = ~exEEPROM.read(calc_address + 7);
		variable[8] = ~exEEPROM.read(calc_address + 8);
		variable[9] = ~exEEPROM.read(calc_address + 9);
	}
	else
	{
		
		variable[0] = EEPROM.read(calc_address);
		variable[1] = EEPROM.read(calc_address + 1);
		variable[2] = EEPROM.read(calc_address + 2);
		variable[3] = EEPROM.read(calc_address + 3);
		variable[4] = EEPROM.read(calc_address + 4);
		variable[5] = EEPROM.read(calc_address + 5);
		variable[6] = EEPROM.read(calc_address + 6);
		variable[7] = EEPROM.read(calc_address + 7);
		variable[8] = EEPROM.read(calc_address + 8);
		variable[9] = EEPROM.read(calc_address + 9);
	}




	
	return true;
}

//neuporabljeno
bool Button_z::write_mem_num_location(byte *variable, byte num_combination, int first_mem_location)
{
	long tmp_add=USER_ID+1;


	long pristej_add=ADD_USER_MEM*tmp_add;

	if(extern_eeprom_ok==true)
	{
		exEEPROM.write(first_mem_location+pristej_add + num_combination * 10 , variable[0]);
		exEEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 1, variable[1]);
		exEEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 2, variable[2]);
		exEEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 3, variable[3]);
		exEEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 4, variable[4]);
		exEEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 5, variable[5]);
		exEEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 6, variable[6]);
		exEEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 7, variable[7]);
		exEEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 8, variable[8]);
		exEEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 9, variable[9]);
	}
	else
	{
		EEPROM.write(first_mem_location+pristej_add + num_combination * 10 , variable[0]);
		EEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 1, variable[1]);
		EEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 2, variable[2]);
		EEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 3, variable[3]);
		EEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 4, variable[4]);
		EEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 5, variable[5]);
		EEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 6, variable[6]);
		EEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 7, variable[7]);
		EEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 8, variable[8]);
		EEPROM.write(first_mem_location+pristej_add + num_combination * 10 + 9, variable[9]);
	}
	return true;
}
bool  Button_z::read_mem_num_location(byte *variable , byte num_combination, int first_mem_location)
{
	//SD_work.Read_zecer_combination(0, 10, variable);
	//return true;
	long tmp_add=USER_ID+1;


	long pristej_add=ADD_USER_MEM*tmp_add;
	
	if(extern_eeprom_ok==true)
	{
		DEBUG_print(F("WRITE COMBINATION;"));
		DEBUG_println(first_mem_location);
		variable[0] = exEEPROM.read(first_mem_location+pristej_add + num_combination * 10);
		variable[1] = exEEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 1);
		variable[2] = exEEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 2);
		variable[3] = exEEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 3);
		variable[4] = exEEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 4);
		variable[5] = exEEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 5);
		variable[6] = exEEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 6);
		variable[7] = exEEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 7);
		variable[8] = exEEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 8);
		variable[9] = exEEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 9);
	}
	else
	{
		variable[0] = EEPROM.read(first_mem_location+pristej_add + num_combination * 10);
		variable[1] = EEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 1);
		variable[2] = EEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 2);
		variable[3] = EEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 3);
		variable[4] = EEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 4);
		variable[5] = EEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 5);
		variable[6] = EEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 6);
		variable[7] = EEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 7);
		variable[8] = EEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 8);
		variable[9] = EEPROM.read(first_mem_location+pristej_add + num_combination * 10 + 9);
	}
	return true;
}



byte Button_z::get_id()
{
	return _id;
}

byte  Button_z::get_id_class()
{
	return read_PROGMEM_info(5);
}
bool  Button_z::get_out_state()
{
	if (bitRead(multi_var, 2) == true)
	return true;
	else
	return false;
}
void Button_z::set_out_state(bool ON_OFF)
{
	bitWrite(multi_var, 2, ON_OFF);
}
byte  Button_z::get_id_num()
{
	return read_PROGMEM_info(2);
}
int  Button_z::get_mem_location()
{
	if(get_id_num()==NOT_USED)
	return _mem_location;
	
	if(get_id_num()!=noMEM)
	return read_PROGMEM_info(1);
	
	return read_PROGMEM_info(1);
	
	//return _mem_location;
}
void Button_z::set_mem_location(int address)
{
	_mem_location=address;
}
//int  Button_z::get_mem_location()
//{
//return read_PROGMEM_info(1)*10;
//}
bool  Button_z::set_NUM(byte number)
{
	//_id_num = number;
	return true;
}
byte Button_z::get_BUTTN_type()
{
	return  read_PROGMEM_info(5);
}

void Button_z::set_state(bool ON_OFF)
{
	bitWrite(multi_var, 0, ON_OFF);
}
void Button_z::set_temp_state(bool ON_OFF)
{
	bitWrite(multi_var, 1, ON_OFF);
}
bool Button_z::get_state()
{
	if (bitRead(multi_var, 0) == true)
	return true;
	else
	return false;

}
bool Button_z::get_temp_state()
{
	if (bitRead(multi_var, 1) == true)
	return true;
	else
	return false;
}

Button_z::Button_z(byte id, int mem_location, byte set_class, void(*on_select)(Button_z*,bool))
{
	_id = id;
	_on_event=on_select;
	//_mem_location = mem_location;
	//_on_select = on_select;
	//_on_deselect = on_deselect;
	//id_class = set_class;
	//set_state(false);
}
