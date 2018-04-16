//
//
//

#include "Stop.h"
#include "global_variables.h"
#include "EEPROM.h"




byte Stop::read_PROGMEM_info(byte id_data)
{
	byte var = pgm_read_byte(&(stops_info[ID][id_data]));
	byte test =read_PROGMEM_eeprom_info(3);
	
	//for(int x=0;x<10;x++)
	//{
	//var = pgm_read_byte(&(buttns_info[x][0]));
	//DEBUG_print("id ");
	//DEBUG_print(var);
	//var = pgm_read_byte(&(buttns_info[x][1]));
	//DEBUG_print("ch ");
	//DEBUG_print(var);
	//var = pgm_read_byte(&(buttns_info[x][2]));
	//DEBUG_print("out ");
	//DEBUG_print(var);
	//var = pgm_read_byte(&(buttns_info[x][3]));
	//DEBUG_print("common ");
	//DEBUG_println(var);
	//}
	//
	//
	//delay(100000);
	return var;
}


byte Stop::read_PROGMEM_eeprom_info(byte id_data)
{
	byte var = pgm_read_byte(&(stops_additional_data[ID][id_data]));
}

Stop::Stop(byte id, byte id_ch, byte MIDI_out_numb_, byte midi_common_ch_, byte active_on_manual_, char* name, char* size, void(*on_select)(Stop*,bool))
{
	//
	ID = id;
	
	if(id==NULL_address)
	{
		ID=id_ch;
	}
	//MIDI_id_ch = id_ch;
	//MIDI_out_numb = MIDI_out_numb_;
	//active_on_manual = active_on_manual_;
	////_name = "";
	//
	//midi_common_ch = midi_common_ch_;
	//_size = size;


	_on_event = on_select;

	//_on_deselect = on_deselect;
	set_state(false);
	//_state = false;
}


byte Stop::get_eeprom_left_right(bool get_headphone_info)
{
	if(get_headphone_info==false)
	return read_PROGMEM_eeprom_info(1);
	else
	return read_PROGMEM_eeprom_info(5);
}

byte Stop::get_eeprom_level(bool get_headphone_info)
{
	if(get_headphone_info==false)
	return read_PROGMEM_eeprom_info(2);
	else
	return read_PROGMEM_eeprom_info(6);
}

byte Stop::get_eeprom_tvf_gain(bool get_headphone_info)
{
	if(get_headphone_info==false)
	return read_PROGMEM_eeprom_info(3);
	else
	return read_PROGMEM_eeprom_info(8);
}

byte Stop::get_eeprom_tvf_cutoff(bool get_headphone_info)
{
	if(get_headphone_info==false)
	return read_PROGMEM_eeprom_info(4);
	else
	return read_PROGMEM_eeprom_info(9);
}



byte  Stop::get_ID()
{

	return read_PROGMEM_info(0);
	//return ID;
}

byte  Stop::get_MIDI_CH()
{
	return read_PROGMEM_info(1);
	//return MIDI_id_ch;
}

byte  Stop::get_MIDI_out_numb()
{
	return read_PROGMEM_info(2);
	//return MIDI_out_numb;
}

byte  Stop::get_active_on_manual()
{
	return read_PROGMEM_info(4);
	//return active_on_manual;
}

byte  Stop::get_midi_common_ch()
{
	return read_PROGMEM_info(3);
	//return midi_common_ch;
}

bool Stop::GetState()
{
	return get_state();
}
String Stop::GetNAME()
{
	return (String)get_ID();
}

void Stop::select(bool on_off)
{
	#ifdef _RODGERS
	selectOrdinary(on_off);
	return;
	#endif // _RODGERS


	//return;//odkomentiraj


	if (STOP_type == LED_MANUBRI)
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
	else if (STOP_type == SDK_MANUBRI)
	{
		if (get_state() != on_off)
		{
			if (on_off == false)
			{
				set_state(false);
				if (_on_event != NULL)
				_on_event(this,false);
			}
			else if (on_off == true)
			{
				set_state(true);
				if (_on_event != NULL)
				_on_event(this,true);
			}

		}
	}


}


//za navadni register
void Stop::selectOrdinary(bool on_off)
{

	if (get_temp_state() != on_off)
	{
		if (on_off == true)
		{
			if (get_state() == true)
			{
				set_state(false);
				if (_on_event != NULL)
				_on_event(this,false);
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

void Stop::SetState(bool on_off)
{
	if (get_state() == on_off)
	return;

	set_state(on_off);
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
byte Stop::get_midi_switch()
{
	//if (MIDI_out_numb == 1)
	//{
	//if (midi_port == 1)
	//{
	//return MIDI_SW_1;
	//}
	//else if (midi_port == 2)
	//{
	//return MIDI_SW_2;
	//}
	//}
	//else if (MIDI_out_numb == 2)
	//{
	//if (midi_port == 1)
	//{
	//return MIDI_SW_3;
	//}
	//else if (midi_port == 2)
	//{
	//return MIDI_SW_4;
	//}
	//}
	//else {
	
	//return 0;
	//
	//}
	return 0;

}

void Stop::SetState_only(bool on_off)
{
	if (get_state() == on_off)
	return;

	set_state(on_off);

}
//void Stop::set_stop_list(byte *stop_list_array, Stop **stop_list)
void Stop::set_stop_list(Stop **stop_list)
{
	//_stop_list = stop_list;
	//velocity = 127;
	//_stop_list_array = stop_list_array;
}

byte Stop::get_STOP_type()
{
	if(get_MIDI_CH()>=1&&get_MIDI_CH()<=16)
	{
		return type_NORMAL_STOP;
	}
	if(get_MIDI_CH()==TREMULANT_I)
	{
		return type_TREMULANT;
	}
	else if(get_MIDI_CH()==TREMULANT_II)
	{
		return type_TREMULANT;
	}
	
	switch (get_MIDI_CH())
	{
		case II_I:
		return type_COUPLER;
		case II_PED:
		return type_COUPLER;
		case SUB_II:
		return type_SUBOKTAVA;
		case SUPER_II:
		return type_SUPEROKTAVA;
		case SUPER_III:
		return type_SUPEROKTAVA;
		case SUB_III:
		return type_SUBOKTAVA;
		case III_PED:
		return type_COUPLER;
		case III_II:
		return type_COUPLER;
		case III_I:
		return type_COUPLER;
		case I_PED:
		return type_COUPLER;
		case SUB_I:
		return type_SUBOKTAVA;
		case SUPER_I:
		return type_SUPEROKTAVA;
	};
	return 244;

}

byte  Stop::note_vol(byte note, byte oktav_mode)
{

	float _volume = read_note_correction(note); //read_note_velocity(stop, key);
	float stop_volume = read_STOP_correction(oktav_mode);

	_volume=127;
	stop_volume=127;

	DEBUG_print(F("corr note-> "));
	DEBUG_print(_volume);
	DEBUG_print(F("corr stop-> "));
	DEBUG_println(stop_volume);
	


	float gen_vol = stop_volume / 127;
	_volume = _volume*gen_vol;

	float final_volume = _volume;// *((float)MASTER_VOLUME / 127);

	//float final_volume = _volume*((float)MASTER_VOLUME / 127); backup
	_volume = final_volume;

	if (oktav_mode == OKTAV_SUB_NOTE)//da je prva oktava tišja
	{
		final_volume = final_volume*1.9;
		if (final_volume>127)
		_volume = 127;
		else
		_volume = final_volume;
	}
	else
	{
		final_volume = final_volume * 1.2;
		if (final_volume>127)
		_volume = 127;
		else
		_volume = final_volume;
	}
	return _volume;
}

byte Stop::read_STOP_correction(byte oktav_mode)
{
	byte _var;
	byte add = 0;
	#ifndef SET_KEYS
	add = 0;
	if (oktav_mode == OKTAV_SINGLE_NOTE)
	add = 0;
	if (oktav_mode == OKTAV_SUB_NOTE)
	add = 1;
	if (oktav_mode == OKTAV_SUP_NOTE)
	add = 2;
	if (oktav_mode == OKTAV_SUB_and_SUP_NOTE)
	add = 3;

	_var = pgm_read_byte_near(note_corrections + ((get_ID() * 90) + add));
	if (_var > 127)
	_var = 127;
	return _var;
	#endif // SET_KEYS

	//COMBINATION_LABEL_TEXT = (String)EEPROM.read(ADDRESS_note + stop->ID * 90  + note);
	add = 0;
	if (oktav_mode == OKTAV_SINGLE_NOTE)
	add = 0;
	if (oktav_mode == OKTAV_SUB_NOTE)
	add = 1;
	if (oktav_mode == OKTAV_SUP_NOTE)
	add = 2;
	if (oktav_mode == OKTAV_SUB_and_SUP_NOTE)
	add = 3;

	add = 0;//TODO temp fix

	_var = EEPROM.read(ADDRESS_note + (get_ID() * 90) + add);
	if (_var > 127)
	_var = 127;
	return _var;
}
byte Stop::read_note_correction(byte note)
{
	byte _var;
	#ifndef SET_KEYS
	_var = pgm_read_byte_near(note_corrections + (get_ID() * 90 + note));
	if (_var > 127)
	_var = 127;
	return _var;
	#endif // SET_KEYS
	_var = EEPROM.read(ADDRESS_note + (get_ID() * 90 + note));
	if (_var > 127)
	_var = 127;
	return _var;
}

void Stop::set_state(bool ON_OFF)
{
	bitWrite(multi_var, 0, ON_OFF);
}
void Stop::set_temp_state(bool ON_OFF)
{
	bitWrite(multi_var, 1, ON_OFF);
}
bool Stop::get_state()
{
	if (bitRead(multi_var, 0) == true)
	return true;
	else
	return false;

}
bool Stop::get_temp_state()
{
	if (bitRead(multi_var, 1) == true)
	return true;
	else
	return false;
}