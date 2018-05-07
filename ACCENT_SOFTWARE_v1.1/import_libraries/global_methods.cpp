//
//
//

#include "global_methods.h"
#include <SoftwareSerial.h>
#include <MIDI.h>
#include "EEPROM.h"
#include "global_variables.h"
#include "PROGMEM_labels.h"
#include <avr\pgmspace.h>
#include "Definitions.h"
#include "MemoryFree.h"
#include "Stop.h"





//#include <Arduino.h>
//#include <virtmem.h>
//#include <SPI.h>
//#include <serialram.h>
//#include <alloc/spiram_alloc.h>
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio






//7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8, 23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24,
#ifdef _RODGERS
const unsigned char map_tabela_zecer[64] PROGMEM= {
24,25,26,27,28,29,30,31,16,17,18,19,20,21,22,23,8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7, 39, 38, 37, 36, 35, 34, 33, 32, 47, 46, 45, 44, 43, 42, 41, 40, 55, 54, 53, 52, 51, 50, 49, 48, 63, 62, 61, 60, 59, 58, 57, 56 };
const unsigned char map_tabela_Z[64] PROGMEM= {
7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8, 23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24, 39, 38, 37, 36, 35, 34, 33, 32, 47, 46, 45, 44, 43, 42, 41, 40, 55, 54, 53, 52, 51, 50, 49, 48, 63, 62, 61, 60, 59, 58, 57, 56 };
#else
const unsigned char map_tabela_zecer[64] PROGMEM = {
7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8, 23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24, 39, 38, 37, 36, 35, 34, 33, 32, 47, 46, 45, 44, 43, 42, 41, 40, 55, 54, 53, 52, 51, 50, 49, 48, 63, 62, 61, 60, 59, 58, 57, 56 };

//const unsigned char map_tabela_Z[64] PROGMEM = {
//	7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8, 23, 22, 21, 20, 19, 18, 17, 16, 31, 30, 29, 28, 27, 26, 25, 24, 39, 38, 37, 36, 35, 34, 33, 32, 47, 46, 45, 44, 43, 42, 41, 40, 55, 54, 53, 52, 51, 50, 49, 48, 63, 62, 61, 60, 59, 58, 57, 56 };


const unsigned char map_tabela_Z[128] PROGMEM = {
	7, 6, 5, 4, 3, 2, 1, 0,
	15, 14, 13, 12, 11, 10, 9, 8,
	23, 22, 21, 20, 19, 18, 17, 16,
	31, 30, 29, 28, 27, 26, 25, 24,
	39, 38, 37, 36, 35, 34, 33, 32,
	47, 46, 45, 44, 43, 42, 41, 40,
	55, 54, 53, 52, 51, 50, 49, 48,
	63, 62, 61, 60, 59, 58, 57, 56
	, 71, 70, 69, 68, 67, 66, 65, 64
	, 79, 78, 77, 76, 75, 74, 73, 72
	, 87, 86, 85, 84, 83, 82, 81, 80
	, 95, 94, 93, 92, 91, 90, 89, 88
	, 103, 102, 101, 100, 99, 98, 97, 96
	, 111, 110, 109, 108, 107, 106, 105, 104
	, 119, 118, 117, 116, 115, 114, 113, 112
	, 127, 126, 125, 124, 123, 122, 121, 120
};

#endif // _RODGERS

const unsigned char map_setter_buttn[77] PROGMEM = {7, 3, 2, 1, 0, 15, 14, 13, 12, 9, 23, 21, 20, 18, 17, 16, 31, 30, 29, 25, 39, 35, 34, 33, 32, 47, 46, 45, 44, 41, 55, 53, 52, 50, 49, 48, 63, 62, 61, 57, 71, 67, 66, 65, 64, 79, 78, 77, 7, 73, 87, 85, 84, 82, 81, 80, 95, 94, 93, 89, 99, 100, 101, 102, 103, 109, 108, 107, 106, 110, 111, 97, 98, 105, 104, 119, 118 };

//tabela mapiranje tipk klaviatur
const unsigned char map_key[64] PROGMEM = {
	0, 8, 16, 24, 32, 40, 48, 56, 1, 9, 17, 25, 33, 41, 49, 57, 2, 10, 18, 26, 34, 42, 50, 58, 3, 11, 19, 27, 35, 43, 51, 59, 4, 12, 20, 28, 36, 44, 52, 60, 5, 13, 21, 29, 37, 45, 53, 61, 6, 14, 22, 30, 38, 46, 54, 62, 7, 15, 23, 31, 39, 47, 55, 63
};
//const unsigned char map_key1[64] PROGMEM = {
////0
////1
////2
////3
////4
////5
////6
////7
////8
////9
////0
////11
////12
//33,//13
//41,//14
//49,//15
//57,//16
//0,//17
//8,//18
//16,//19
//25,//20
//34,//21
//42,//22
//50,//23
//58,//24
//1,//25
//9,//26
//17,//27
//26,//28
//35,//29
//43,//30
//51,//31
//59,//32
//2,//33
//10,//34
//19,//35
//27,//36
//36,//37
//44,//38
//52,//39
//60,//40
//3,//41
//11,//42
//20,//43
//28,//44
//37,//45
//45,//46
//53,//47
//61,//48
//4,//49
//12,//50
//21,//51
//29,//52
//38,//53
//46,//54
//54,//55
////56
//5,//57
//13,//58
//22,//59
//30,//60
//39,//61
//47,//62
//55,//63
////64
//6,//65
//14,//66
//23,//67
//31//68
//40,//69
//48,//70
//56,//71
////72
//7,//73
//15,//74
//24,//75
//32//76
//};
//za seter kombinacije kak si sledijo po vrsti
const unsigned char map_setter_num_buttn[] PROGMEM = {3, 2, 1, 0, 15, 14, 13, 12, 35, 34, 33, 32, 47, 46, 45, 44, 67, 66, 65, 64, 79, 78, 77, 76 };

byte get_map_Z_buttn_id(int position)
{
	return pgm_read_word_near(map_setter_num_buttn + position);
}
byte get_map_tabela_zecer(int position)
{
	return pgm_read_word_near(map_tabela_zecer + position);
}
byte get_map_tabela_Z(int position)
{
	return pgm_read_word_near(map_tabela_Z + position);
}
byte read_map_setter(int position)
{
	return pgm_read_word_near(map_setter_buttn + position);
}
byte get_key_map(int position)
{
	
	byte out_p=pgm_read_word_near(map_key + position);
	
	if(out_p>31)
	return out_p-32;
	else
	return out_p+32;
}

bool _readBit_stop(byte variable[], int position)
{
	//_readBit(variable, position);
	//return;

	if (bitRead(variable[position / 8],position % 8) == true)
	return true;
	else
	return false;


	if (bitRead(variable[get_map_tabela_Z(position) / 8], get_map_tabela_Z(position) % 8) == true)
	return true;
	else
	return false;
}

//Zecer_stop_mgr Z_S_mgr;
bool _readBit(byte variable[], int position)
{
	//position--;
	byte num = position % 8;

	switch (num)
	{
		case 0:
		num = 7;
		break;
		case 1:
		num = 6;
		break;
		case 2:
		num = 5;
		break;
		case 3:
		num = 4;
		break;
		case 4:
		num = 3;
		break;
		case 5:
		num = 2;
		break;
		case 6:
		num = 1;
		break;
		case 7:
		num = 0;
		break;

		default:
		break;
	}


	if (bitRead(variable[position / 8], num) == true)
	return true;
	else
	return false;


	//if (bitRead(variable[map_tabela_Z[position] / 8], map_tabela_Z[position] % 8) == true)
	//	return true;
	//else
	//	return false;
}


bool _writeBit_stop(byte variable[], int position, bool state)
{
	if (position == 200)
	return true;

	bitWrite(variable[position / 8], (position % 8), state);
	return true;
	//bitWrite(variable[position / 8], position % 8, state);
	bitWrite(variable[get_map_tabela_Z(position) / 8], get_map_tabela_Z(position) % 8, state);
	return true;
}

bool _readBit_normal(byte variable[], int position)
{
	if (bitRead(variable[position / 8], position % 8) == true)
	return true;
	else
	return false;
}
bool _writeBit(byte variable[], int position, bool state)
{
	DEBUG_print(F(" WRITE_to_OUT_id-> "));
	DEBUG_println(position);
	
	if (position == 200)
	return true;
	

	bitWrite(variable[get_map_tabela_Z(position) / 8], get_map_tabela_Z(position) % 8, state);

	//for (int i = 0; i < ZECER_num - 1; i++)
	//{
	//if (_readBit(variable, i) == true)
	//{
	//DEBUG_print(F("1"));
	//}
	//else
	//{
	//DEBUG_print(F("0"));
	//}
	//
	//}
	//DEBUG_println("");
	return true;

	DEBUG_println(position);
	bitWrite(variable[position / 8], position % 8, state);

	for (int i = 0; i < ZECER_num - 1; i++)
	{
		if (_readBit(variable, i) == true)
		{
			DEBUG_print(F("1"));
		}
		else
		{
			DEBUG_print(F("0"));
		}
		
	}
	DEBUG_print(F(" WRITE_to_OUT_id-> "));
	DEBUG_println(position);
	return true;
}

bool _writeBit_normal(byte variable[], int position, bool state)
{

	bitWrite(variable[map_tabela_Z[position] / 8], map_tabela_Z[position] % 8, state);
	return true;
}

bool write_mem(int _mem_location,byte *variable)
{

	//EEPROM.write(_mem_location, );
	DEBUG_print(F("write loc"));
	DEBUG_println(_mem_location);
	EEPROM.write(_mem_location, variable[0]);
	EEPROM.write(_mem_location + 1, variable[1]);
	EEPROM.write(_mem_location + 2, variable[2]);
	EEPROM.write(_mem_location + 3, variable[3]);
	EEPROM.write(_mem_location + 4, variable[4]);
	EEPROM.write(_mem_location + 5, variable[5]);
	EEPROM.write(_mem_location + 6, variable[6]);
	EEPROM.write(_mem_location + 7, variable[7]);
	EEPROM.write(_mem_location + 8, variable[8]);
	EEPROM.write(_mem_location + 9, variable[9]);

	/*for (int x = 0; x < 8; x++)
	{

	if (bitRead(variable[x / 8], x % 8) == true)
	{
	DEBUG_print(x);
	DEBUG_println(" ON");
	}
	else
	{
	DEBUG_print(x);
	DEBUG_println(" OFF");
	}


	}*/

	return true;
}
void calculate_free_RAM(int id)
{
	//-return;
	DEBUG_print(id);
	DEBUG_print(F(" <- id ::free mem-> "));
	DEBUG_print(freeMemory());
	DEBUG_println(F(" Byte"));

}

void EEPROMWriteLong(int address, long value)
{
	byte four = (value & 0xFF);
	byte three = ((value >> 8) & 0xFF);
	byte two = ((value >> 16) & 0xFF);
	byte one = ((value >> 24) & 0xFF);

	//Write the 4 bytes into the eeprom memory.
	EEPROM.write(address, four);
	EEPROM.write(address + 1, three);
	EEPROM.write(address + 2, two);
	EEPROM.write(address + 3, one);
}

long EEPROMReadlong(long address)
{
	//Read the 4 bytes from the eeprom memory.
	long four = EEPROM.read(address);
	long three = EEPROM.read(address + 1);
	long two = EEPROM.read(address + 2);
	long one = EEPROM.read(address + 3);

	return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}
#define red 0
#define green 1
#define blue 2
#define white 3
#define black 4
#define yellow 5
#define orange 5

void set_color(byte color, byte* color_array)
{
	if (color == red)
	{
		color_array[0] = 255;
		color_array[1] = 0;
		color_array[2] = 0;
	}
	else if (color == green)
	{
		color_array[0] = 0;
		color_array[1] = 255;
		color_array[2] = 0;
	}
	else if (color == blue)
	{
		color_array[0] = 0;
		color_array[1] = 200;
		color_array[2] = 255;
	}
	else if (color == black)
	{
		color_array[0] = 0;
		color_array[1] = 0;
		color_array[2] = 0;
	}
	else if (color == white)
	{
		color_array[0] = 255;
		color_array[1] = 255;
		color_array[2] = 255;
	}
	else if (color == yellow)
	{
		color_array[0] = 255;
		color_array[1] = 255;
		color_array[2] = 0;
	}
	else if (color == orange)
	{
		color_array[0] = 255;
		color_array[1] = 128;
		color_array[2] = 0;
	}
}
void setTheme(int theme)
{
	
	if (theme > 4)
	theme = 0;

	if (theme == 0)
	{
		set_color(green, check_color);
		set_color(red, select_color);
		//select_color[0]=255;
		//select_color[1]=0;
		//select_color[2]=50;
		
		set_color(black, back_color);
		set_color(white, line_color);
		
	}
	else if (theme == 1)
	{
		set_color(green, check_color);
		set_color(red, select_color);
		set_color(black, back_color);
		set_color(blue, line_color);
	}
	else if (theme == 2)
	{
		set_color(green, check_color);
		set_color(red, select_color);
		set_color(black, back_color);
		set_color(yellow, line_color);
	}
	else if (theme == 3)
	{
		set_color(green, check_color);
		set_color(orange, select_color);
		set_color(black, back_color);
		set_color(blue, line_color);
	}
	else if (theme == 4)
	{
		set_color(red, check_color);
		set_color(orange, select_color);
		set_color(black, back_color);
		set_color(blue, line_color);
	}
}


byte return_oktav_mode(Stop* stop)
{
	byte oktav_mode = 0;
	if (stop->get_active_on_manual() == MANUAL_1 && STOP_mgr.id(SUPER_I)->GetState() && STOP_mgr.id(SUB_I)->GetState())
	{
		oktav_mode = OKTAV_SUB_and_SUP_NOTE;
	}
	else if (stop->get_active_on_manual() == MANUAL_2 && STOP_mgr.id(SUPER_II)->GetState() && STOP_mgr.id(SUB_II)->GetState())
	{
		oktav_mode = OKTAV_SUB_and_SUP_NOTE;
	}
	else if (stop->get_active_on_manual() == MANUAL_3 && STOP_mgr.id(SUPER_III)->GetState() && STOP_mgr.id(SUB_III)->GetState())
	{
		oktav_mode = OKTAV_SUB_and_SUP_NOTE;
	}
	else if (stop->get_active_on_manual() == MANUAL_1 && STOP_mgr.id(SUPER_I)->GetState())//|| STOP_mgr.id(SUB_I)->GetState())
	{
		oktav_mode = OKTAV_SUP_NOTE;
	}
	else if (stop->get_active_on_manual() == MANUAL_1 &&  STOP_mgr.id(SUB_I)->GetState())
	{
		oktav_mode = OKTAV_SUB_NOTE;
	}
	else if (stop->get_active_on_manual() == MANUAL_2 && STOP_mgr.id(SUPER_II)->GetState())
	{
		oktav_mode = OKTAV_SUP_NOTE;
	}
	else if (stop->get_active_on_manual() == MANUAL_2 &&  STOP_mgr.id(SUB_II)->GetState())
	{
		oktav_mode = OKTAV_SUB_NOTE;
	}
	else if (stop->get_active_on_manual() == MANUAL_3 && STOP_mgr.id(SUPER_III)->GetState())
	{
		oktav_mode = OKTAV_SUP_NOTE;
	}
	else if (stop->get_active_on_manual() == MANUAL_3 &&  STOP_mgr.id(SUB_III)->GetState())
	{

		oktav_mode = OKTAV_SUB_NOTE;
	}
	return oktav_mode;
}


void print_note_velocity(Stop *stop)
{
	Serial.println(F("const unsigned char razmerja_tonov[3600] PROGMEM = {"));
		for (int i = 0; i < STOP_num; i++)
		{
			if (STOP_mgr.id(i)->get_ID() != NULL_address)//da skipne
			{
				
				Serial.print(F("/*"));
				Serial.print(STOP_mgr.id(i)->GetNAME());
				Serial.print(F(" :ID-> "));
				Serial.print(STOP_mgr.id(i)->get_ID());
				Serial.print(F("*/ "));

				for (int x = 0; x < 90; x++)
				{
					//DEBUG_print(x);
					if (x == 300)
					{
						//Serial.print(",");
						//Serial.print(read_STOP_velocity(STOP_mgr.stop(i]));
						//Serial.print("");
					}
					else {
						Serial.print(F(","));
						Serial.print(read_mem_velocity(STOP_mgr.id(i), x));
						Serial.print(F(""));
					}
					
				}
				Serial.println(F(""));
			}

		}

	Serial.println(F("}"));
}


byte write_to_EEPROM_from_PROGMEM(int* location,int destination_eeprom,int length)
{
	char myChar;
	for (int x = 0; x < length; x++)
	{
		myChar = pgm_read_byte_near(location + x);
		EEPROM.write(destination_eeprom + x, myChar);
	}

	return 0;
}



#ifdef neki_test



byte read_mem_velocity(Stop *stop, byte note)
{
	#ifndef SET_KEYS
	return read_mem_velocity_progmem(stop,note);
	#endif // SET_KEYS

	
	//COMBINATION_LABEL_TEXT = (String)EEPROM.read(ADDRESS_note + stop->ID * 90  + note);
	byte _var = EEPROM.read(ADDRESS_note + (stop->ID * 90 + note));
	if (_var > 127)
	_var = 127;
	return _var;
}
byte read_STOP_velocity(Stop *stop)
{
	#ifndef SET_KEYS
	return read_STOP_velocity_progmem(stop);
	#endif // SET_KEYS
	//COMBINATION_LABEL_TEXT = (String)EEPROM.read(ADDRESS_note + stop->ID * 90  + note);
	byte _var = EEPROM.read(ADDRESS_note + (stop->ID * 90));
	if (_var > 127)
	_var = 127;
	return _var;
}
byte read_mem_velocity_progmem(Stop *stop, byte note)
{
	//COMBINATION_LABEL_TEXT = (String)EEPROM.read(ADDRESS_note + stop->ID * 90  + note);
	//byte _var = EEPROM.read(ADDRESS_note + (1 + stop->ID * 90 + note));

	byte _var = pgm_read_byte_near(razmerja_tonov_new + (stop->ID * 90 + note));
	if (_var > 127)
	_var = 127;
	return _var;
}
byte read_STOP_velocity_progmem(Stop *stop)
{
	//COMBINATION_LABEL_TEXT = (String)EEPROM.read(ADDRESS_note + stop->ID * 90  + note);
	//byte _var = EEPROM.read(ADDRESS_note + (stop->ID * 90));
	byte _var = pgm_read_byte_near(razmerja_tonov_new + ((stop->ID * 90)));

	if (_var > 127)
	_var = 127;
	return _var;
}

#endif // neki_test

void write_STOP_velocity(Stop *stop,byte velocity,byte oktav_mode)
{
	byte add = 0;
	if (oktav_mode == OKTAV_SINGLE_NOTE)
	add = 0;
	if (oktav_mode == OKTAV_SUB_NOTE)
	add = 1;
	if (oktav_mode == OKTAV_SUP_NOTE)
	add = 2;
	if (oktav_mode == OKTAV_SUB_and_SUP_NOTE)
	add = 3;
	//COMBINATION_LABEL_TEXT = (String)EEPROM.read(ADDRESS_note + stop->ID * 90  + note);
	//return EEPROM.read(ADDRESS_note + (stop->ID * 90));
	EEPROM.write(ADDRESS_note + (stop->get_ID() * 90)+add, velocity);
}

bool write_mem_velocity_b(Stop *stop, byte velocity)
{
	EEPROM.write(ADDRESS_note + (stop->get_ID() * 90),velocity);
}

bool write_mem_velocity(Stop *stop, byte note, byte velocity)
{
	if (velocity > 127)
	velocity = 127;

	if (velocity < 0)
	velocity = 1;

	DEBUG_print(F(" STOP-> "));
	DEBUG_print(stop->GetNAME());

	EEPROM.update(ADDRESS_note + (stop->get_ID() * 90 + note), velocity);//+1 zato ker je na prvem mestu glasnost registra

	DEBUG_print(F("write Location note->"));
	DEBUG_print(ADDRESS_note + (stop->get_ID() * 90 + note));
	DEBUG_print(F(" velocity->"));
	DEBUG_println(velocity);
	DEBUG_print(F("   takoj prebrano->"));
	DEBUG_println(EEPROM.read(ADDRESS_note + (stop->get_ID() * 90 + note)));

	DEBUG_print(F("   nota->"));
	DEBUG_println(note);

	//COMBINATION_LABEL_TEXT = (String)EEPROM.read(ADDRESS_note + stop->ID * 90 + note);

}
extern char razmerja_tonov[];

byte write_mem_velocity_from_PROGMEM(Stop *stop)
{
	//DEBUG_print(F(" STOP-> "));
	//DEBUG_print(stop->_name);
	byte readTest;
	int ton_int;

	for (int x = 0; x < STOP_num; x++)
	{
		if (STOP_mgr.id(x)->get_ID() != NULL_address)
		{
			for (int y = 0; y < 90; y++)
			{
				ton_int = atoi(razmerja_tonov);
				readTest = pgm_read_byte_near(razmerja_tonov + STOP_mgr.id(x)->get_ID() * 90 + y);

				//DEBUG_print(F(" "));
				//DEBUG_print(ADDRESS_note+ton_int + STOP_mgr.stop(x]->ID * 90 + y);
				//DEBUG_print(F(" ="));
				//DEBUG_print(readTest);

				if (readTest > 127)
				readTest = 127;
				EEPROM.update(ADDRESS_note + STOP_mgr.id(x)->get_ID() * 90 + y, readTest);

			}
		}
	}
	return readTest;

	//return EEPROM.read(test);//glasnost tipke
}

bool _readBit_k(byte variable[], int position)
{
	
	if (bitRead(variable[position / 8], position % 8) == true)
	return true;
	else
	return false;


}


bool _writeBit_k(byte variable[], int position,bool _state)
{
	//position--;
	//byte num = position % 8;
	byte num=0;

	//bitWrite(variable[0], 0,0);

	//if(_state)
	SetBit(variable[pgm_read_byte(&(calc_bit_array[position][0]))], pgm_read_byte(&(calc_bit_array[position][1])));

	bitWrite(variable[pgm_read_byte(&(calc_bit_array[position][0]))], pgm_read_byte(&(calc_bit_array[position][1])),_state);
	//bitWrite(variable[position / 8], position % 8,_state);
	//
	//DEBUG_println(tmp1);
	//DEBUG_println(tmp2);
	//DEBUG_println(pgm_read_byte(&(calc_bit_array[key][0])));
	//DEBUG_println(pgm_read_byte(&(calc_bit_array[key][1])));
	//DEBUG_println();
	//

	//if (bitRead(variable[map_tabela_Z[position] / 8], map_tabela_Z[position] % 8) == true)
	//	return true;
	//else
	//	return false;
	return true;
}

byte G_bit(byte *_array,byte key)
{
	return BitVal(_array[pgm_read_byte(&(calc_bit_array[key][0]))], pgm_read_byte(&(calc_bit_array[key][1])));
	//if(sizeof(_array)==14)
	return bitRead(_array[pgm_read_byte(&(calc_bit_array[key][0]))], pgm_read_byte(&(calc_bit_array[key][1])));
	return (_readBit_k(_array,key));
	
	return _array[key];
}


void test_bit(byte key)
{
	SetBit(k_MAN_III_L[0],key);
}

#define BitVal(data,y) ( (data>>y) & 1)
void S_bit(byte *_array,byte key,byte _state)
{
	//SetBit(k_MAN_III_L[0],key);

	if(_state)
	SetBit(_array[pgm_read_byte(&(calc_bit_array[key][0]))], pgm_read_byte(&(calc_bit_array[key][1])));
	else
	ClearBit(_array[pgm_read_byte(&(calc_bit_array[key][0]))], pgm_read_byte(&(calc_bit_array[key][1])));
	return;
	
	bitWrite(_array[pgm_read_byte(&(calc_bit_array[key][0]))], pgm_read_byte(&(calc_bit_array[key][1])),_state);//hitrejše //temp rešitev
	return;
	(_writeBit_k(_array,key,_state));

}




void manubri_na_nulo()
{
	//return;
	#ifdef RGB_LED_OUTPUT
	return;
	#endif
	digitalWrite(STOP1_OUT_ENABLE, HIGH);
	digitalWrite2(SS_595_STOPS1, LOW);
	//reverse
	for (int i = STOP_num - 1; i >= 0; i--)
	{
		digitalWrite(CLK_STOPS1, 0);
		//digitalWrite2(MOSI_595_STOPS1, HIGH);
		digitalWrite2(MOSI_595_STOPS1, LOW);
		digitalWrite(CLK_STOPS1, 1);

	}
	digitalWrite2(SS_595_STOPS1, HIGH);


}
void zecer_na_nulo()
{

	//digitalWrite2(LOAD_595_Z, LOW);
	//
	//shiftOut(DATA_595_R, CLK_STOPS1, LSBFIRST, 0);
	//shiftOut(DATA_595_R, CLK_STOPS1, LSBFIRST, 0);
	//
	//shiftOut(DATA_595_R, CLK_STOPS1, LSBFIRST, 0);
	//shiftOut(DATA_595_R, CLK_STOPS1, LSBFIRST, 0);
	//
	//shiftOut(DATA_595_R, CLK_STOPS1, LSBFIRST, 0);
	//shiftOut(DATA_595_R, CLK_STOPS1, LSBFIRST, 0);
	//
	//digitalWrite2(LOAD_595_Z, HIGH);
	//
	//
	
	
	

	digitalWrite2(LOAD_595_Z, LOW);

	for (int i = ZECER_num - 1; i >= 0; i--)
	{
		digitalWrite2(CLK_ZECER, 0);


		digitalWrite2(DATA_595_Z, LOW);
		

		digitalWrite2(CLK_ZECER, 1);
	}
	digitalWrite2(LOAD_595_Z, HIGH);

	digitalWrite(ZECER_OUT_ENABLE,HIGH);
	

	//for (int x = 0; x < STOP_mgr.Stop_count; x++)
	//{
		//DEBUG_print(F("state: "));
		//DEBUG_print(x);
		//DEBUG_print(F(" : "));
		//DEBUG_println(STOP_mgr.id(x)->GetState());
		//STOP_mgr.id(x)->SetState(false);
		////STOP_mgr.id(x)->(false);
	//}
	
	
}

#define	Ce	0
#define	Cis	1
#define	De	2
#define	Dis	3
#define	Ee	4
#define	Fe	5
#define	Fis	6
#define	Ge	7
#define	Gis	8
#define	Ae	9
#define	Aeis 10
#define	Be	11
String get_tone_name(int id)
{
	id--;
	String name="";
	int cmp=id%12;
	DEBUG_STRING_print("ton:");
	DEBUG_print(cmp);
	
	switch (cmp)
	{
		case Ce:
		name=F("C");
		break;
		case Cis:
		name=F("C#");
		break;
		case De:
		name=F("D");
		break;
		case Dis:
		name=F("D#");
		break;
		case Ee:
		name=F("E");
		break;
		case Fe:
		name=F("F");
		break;
		case Fis:
		name=F("F#");
		break;
		case Ge:
		name=F("G");
		break;
		case Gis:
		name=F("G#");
		break;
		case Ae:
		name=F("A");
		break;
		case Aeis:
		name=F("A#");
		break;
		case Be:
		name=F("B");
		break;
		default:
		name=F("X");
		break;
	};
	int num_count=(id/12)-2;
	if(num_count>=0)
	name+=String(num_count);
	DEBUG_STRING_print(" ost:");
	DEBUG_print(num_count);
	if(name.length()==2)
	name+=F(" ");
	else if(name.length()==1)
	name+=F("  ");
	
	return name;
}

String get_stop_name(byte id)
{

	switch (id)
	{
		case BORDUN_16 :
		return F("BORDUN 16");
		break;
		case PRINZIPAL_8:
		return F("PRINZIPAL 8");
		break;
		case FLUTE_HARMONIQ :
		return F("FLUTE HARMO");
		break;
		case SALICIONAL :
		return F("SALICIONAL");
		break;
		case OKTAVE_4 :
		return F("OKTAVE 4");
		break;
		case SPITZFLOTE :
		return F("SPITZFLOTE");
		break;
		case QUINTE :
		return F("QUINTE");
		break;
		case PRINZIPAL_2 :
		return F("PRINZIPAL 2");
		break;
		case MIXTUR_5F :
		return F("MIXTUR 5F");
		break;
		case TROMPETE_8 :
		return F("TROMPETE 8");
		break;
		case CLARION_4 :
		return F("CLARION 4");
		break;
		case BORDUN_8 :
		return F("BORDUN 8");
		break;
		case PRESTANT_4:
		return F("PRESTANT 4");
		break;
		case ROHRFLOTE_4 :
		return F("ROHRFLOTE");
		break;
		case QUINTE_m3 :
		return F("QUINTE");
		break;
		case GEMSHORN_2 :
		return F("GEMSHORN");
		break;
		case TERZE_m3 :
		return F("LARIGOT");
		break;
		case PICCOLO :
		return F("PICCOLO");
		break;
		case SCHARF_3F :
		return F("SHARF 3F");
		break;
		case KRUMHORN :
		return F("KRUMHORN");
		break;
		case PRINZIPAL_BASS_16 :
		return F("PRINZ BASS 16");
		break;
		case SUBBASS_8 :
		return F("SUBBASS");
		break;
		case OKTAVBASS_8 :
		return F("OKTAVBASS");
		break;
		case BASSFLOTE_8 :
		return F("BASSFLOTE");
		break;
		case CHORALBASS_4  :
		return F("CHORALBASS");
		break;
		case PEDAL_MIXTUR_2F :
		return F("PED MIX 2F");
		break;
		case POSAUNE_16 :
		return F("POSAUNE");
		break;
		case TROMPETE_8_ped :
		return F("PED TROMPETE");
		break;
		case PORTUNAL_FLOTE  :
		return F("PORTUNAL FLOTE");
		break;
		case GAMBE :
		return F("GAMBE");
		break;
		case VOX_COELESTIS :
		return F("VOX COELESTIS");
		break;
		case GEIGEN_PRINZIPAL :
		return F("GEIGEN PRINZIPAL");
		break;
		case TRAVERS_FLUTE :
		return F("TRAVERS FLUTE");
		break;
		case NASAT :
		return F("NASAT");
		break;
		case FLAGEOLET :
		return F("FLAGEOLET");
		break;
		case MIXTUR_4F :
		return F("MIXTUR 4F");
		break;
		case LARIGOT :
		return F("TERZE 2/3");
		break;
		case FAGOTT :
		return F("FAGOT");
		break;
		case OBOE :
		return F("OBOE");
		break;
		case TROMPETE_HARMONIQ :
		return F("TRMOP HARMONIQ");
		break;
		case SCHALMEI :
		return F("SCHALMEI");
		break;
		
		//////////////
		case head_BORDUN_16 :
		return F("EXT BORDUN 16");
		break;
		case head_PRINZIPAL_8:
		return F("EXT PRINZIPAL 8");
		break;
		case head_FLUTE_HARMONIQ :
		return F("EXT FLUTE HARMO");
		break;
		case head_SALICIONAL :
		return F("EXT SALICIONAL");
		break;
		case head_OKTAVE_4 :
		return F("EXT OKTAVE 4");
		break;
		case head_SPITZFLOTE :
		return F("EXT SPITZFLOTE");
		break;
		case head_QUINTE :
		return F("EXT QUINTE");
		break;
		case head_PRINZIPAL_2 :
		return F("EXT PRINZIPAL 2");
		break;
		case head_MIXTUR_5F :
		return F("EXT MIXTUR 5F");
		break;
		case head_TROMPETE_8 :
		return F("EXT TROMPETE 8");
		break;
		case head_CLARION_4 :
		return F("EXT CLARION 4");
		break;
		case head_BORDUN_8 :
		return F("EXT BORDUN 8");
		break;
		case head_PRESTANT_4:
		return F("EXT PRESTANT 4");
		break;
		case head_ROHRFLOTE_4 :
		return F("EXT ROHRFLOTE");
		break;
		case head_QUINTE_m3 :
		return F("EXT QUINTE");
		break;
		case head_GEMSHORN_2 :
		return F("EXT GEMSHORN");
		break;
		case head_TERZE_m3 :
		return F("EXT LARIGOT");
		break;
		case head_PICCOLO :
		return F("EXT PICCOLO");
		break;
		case head_SCHARF_3F :
		return F("EXT SHARF 3F");
		break;
		case head_KRUMHORN :
		return F("EXT KRUMHORN");
		break;
		case head_PRINZIPAL_BASS_16 :
		return F("EXT PRINZ BASS 16");
		break;
		case head_SUBBASS_8 :
		return F("EXT SUBBASS");
		break;
		case head_OKTAVBASS_8 :
		return F("EXT OKTAVBASS");
		break;
		case head_BASSFLOTE_8 :
		return F("EXT BASSFLOTE");
		break;
		case head_CHORALBASS_4  :
		return F("EXT CHORALBASS");
		break;
		case head_PEDAL_MIXTUR_2F :
		return F("EXT PED MIX 2F");
		break;
		case head_POSAUNE_16 :
		return F("EXT POSAUNE");
		break;
		case head_TROMPETE_8_ped :
		return F("EXT PED TROMPETE");
		break;
		case head_PORTUNAL_FLOTE  :
		return F("EXT PORTUNAL FLOTE");
		break;
		case head_GAMBE :
		return F("EXT GAMBE");
		break;
		case head_VOX_COELESTIS :
		return F("EXT VOX COELESTIS");
		break;
		case head_GEIGEN_PRINZIPAL :
		return F("EXT GEIGEN PRINZIPAL");
		break;
		case head_TRAVERS_FLUTE :
		return F("EXT TRAVERS FLUTE");
		break;
		case head_NASAT :
		return F("EXT NASAT");
		break;
		case head_FLAGEOLET :
		return F("EXT FLAGEOLET");
		break;
		case head_MIXTUR_4F :
		return F("EXT MIXTUR 4F");
		break;
		case head_LARIGOT :
		return F("EXT TERZE 2/3");
		break;
		case head_FAGOTT :
		return F("EXT FAGOT");
		break;
		case head_OBOE :
		return F("EXT OBOE");
		break;
		case head_TROMPETE_HARMONIQ :
		return F("EXT TRMOP HARMONIQ");
		break;
		case head_SCHALMEI :
		return F("EXT SCHALMEI");
		break;
		default:
		return F(" empty slot");
		break;
	}

}

void get_splited_float_arr(char *splitted_float,long value)
{
	splitted_float[0] = value >> 24;
	splitted_float[1] = value >> 16;
	splitted_float[2] = value >> 8;
	splitted_float[3] = value;
}
long return_float(char *splitted_float)
{
	unsigned long highWord = word(splitted_float[0], splitted_float[1]);
	unsigned long lowWord = word(splitted_float[2], splitted_float[3]);
	return highWord << 16 | lowWord;
}
unsigned long return_float_from_3_byte(byte *splitted)
{
	unsigned int tempo = (splitted[2] & 0xff) << 16 | (splitted[1] & 0xff) << 8 | (splitted[0] & 0xff);
	unsigned int bpm = 60000000 / tempo;
	
	return tempo;

}