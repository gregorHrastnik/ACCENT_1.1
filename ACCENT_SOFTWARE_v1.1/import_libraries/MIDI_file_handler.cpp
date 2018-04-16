/*
* MIDI_file_handler.cpp
*
* Created: 11.9.2017 14:47:13
* Author: Greg
*/


#include "MIDI_file_handler.h"
#include "global_variables.h"
#include "Midifile_cmd.h"
#include "global_methods.h"

MIDI_file_handler::MIDI_file_handler(File &file_to_read)
{

	
	work_file=file_to_read;
	char buff_big[4];
	work_file.readBytes(buff_big,4);
	if(strncmp(buff_big, "MThd",4) != 0)
	{
		DEBUG_print(buff_big);
		DEBUG_STRING_println("MIDI FILE ERROR!");
		
		//break;
	}
	work_file.readBytes(buff_big,4);
	
	
	work_file.readBytes(buff_big,2);
	MIDI_format = buff_big[1] | buff_big[0] << 8;//2 bajta v int
	
	work_file.readBytes(buff_big,2);
	MIDI_track_count = buff_big[1] | buff_big[0] << 8;//2 bajta v int
	
	DEBUG_STRING_print("tmp read 1:");
	DEBUG_println((byte)buff_big[0]);
	DEBUG_STRING_print("tmp read 2:");
	DEBUG_println((byte)buff_big[1]);
	
	work_file.readBytes(buff_big,2);
	MIDI_speed = buff_big[0] | buff_big[1] << 8;//2 bajta v int

	DEBUG_STRING_print("MIDI_format:");
	DEBUG_println(MIDI_format);
	DEBUG_STRING_print("MIDI_track_count:");
	DEBUG_println(MIDI_track_count);
	DEBUG_STRING_print("MIDI_speed:");
	DEBUG_println(MIDI_speed);




	//if(MIDI_format==0)
	{
		work_file.readBytes(buff_big,4);
		if(strncmp(buff_big, "MTrk",4) != 0)
		{
			DEBUG_STRING_print("hdr info:");
			DEBUG_print(buff_big);
			DEBUG_STRING_println("MIDI FILE ERROR 2!");
			//break;
		}
		
		work_file.readBytes(buff_big,4);

		TRACK_length=return_float(buff_big);
		DEBUG_STRING_print("TRACK_length:");
		DEBUG_println(TRACK_length);
	}
	
	Midifile_cmd _command;
	
	for(int x=0;x<50;x++)
	//	for(;;)
	{
		DEBUG_STRING_print("POSITION: ");
		DEBUG_print(work_file.position());
		DEBUG_STRING_print(" ");
		if(work_file.position()<work_file.size())
		{
			_command=read_next_cmd();
			SD_work.load_into_RAM_cmd(_command);
		}
		else
		break;
	}
	
DEBUG_STRING_println("konec");
	
	
}

// default destructor
MIDI_file_handler::~MIDI_file_handler()
{
} //~MIDI_file_handler

String MIDI_file_handler::cmd_to_read(int size)
{
	String command="";
	//char _buffer[size];
	byte byte_in;
	for (int x=0;x<size;x++)
	{
		byte_in = work_file.read();
		//_buffer[x]=byte_in;
		command+=(char)byte_in;
	}
	return command;
}

int MIDI_file_handler::read_var_length()
{
	uint32_t ret = 0;
	uint8_t byte_in;
	for (;;)
	{
		byte_in = work_file.read();
		ret = (ret << 7) | (byte_in & 0x7f);
		if (!(byte_in & 0x80))
		{
			//DEBUG_STRING_print("DELTA TIME:");
			//DEBUG_print_HEX(ret);
			//DEBUG_println();
			
			return ret;
			//return "";
		}
		
	}
}

void MIDI_file_handler::print_debug_Hex_string(String val)
{
	for(int x=0;x<val.length();x++)
	{
		DEBUG_print_HEX((byte)val[x]);
		DEBUG_STRING_print(" ");
	}
	//DEBUG_println();
}

byte last_status;
Midifile_cmd MIDI_file_handler::read_next_cmd()
{
	byte tmp_buffer[10];
	
	uint32_t ret = 0;
	uint8_t byte_in;
	Midifile_cmd midi_cmd;


	for (;;)
	{
		byte_in = work_file.read();
		
		ret = (ret << 7) | (byte_in & 0x7f);
		if (!(byte_in & 0x80))
		{
			DEBUG_STRING_print(" DELTA :");
			DEBUG_print_HEX(ret);
			DEBUG_STRING_print("   ");
			//DEBUG_println();
			midi_cmd.midi_cmd_delta_time=ret;
			break;
			//	return ret;
			//return "";
		}
		
	}
	
	byte_in = work_file.read();
	DEBUG_STRING_print("STATUS: ");
	DEBUG_print_HEX(byte_in);
	DEBUG_STRING_print("   ");
	if(byte_in==0xF0)
	{
		DEBUG_STRING_print("==SYSEX:");
		//midi_cmd.midi_cmd=cmd_to_read(read_var_length());
		//String temps=cmd_to_read(read_var_length());
		print_debug_Hex_string(cmd_to_read(read_var_length()));
		//calculate_free_RAM(111);
		
	}
	else if(byte_in<0xFF)
	{
		byte buff_mid[3];
		byte size_cmd;
		bool use_last_status=false;
		
		if(byte_in<=0x80)//use or set last status byte
		{
			use_last_status=true;
			midi_cmd.midi_cmd+=(char)last_status;
			midi_cmd.midi_cmd+=(char)byte_in;
			size_cmd=get_cmd_size(last_status)-2;
			DEBUG_STRING_print("CPY: ");
			DEBUG_print_HEX(last_status);

			
		}
		else
		{
			last_status=byte_in;
			size_cmd=get_cmd_size(last_status)-1;
			midi_cmd.midi_cmd+=(char)last_status;
			DEBUG_STRING_print("NEW: ");
			DEBUG_print_HEX(last_status);
			
		}
		DEBUG_STRING_print(" SIZE: ");
		DEBUG_print(size_cmd);
		
		
		for (byte x=0;x<size_cmd;x++)
		{
			if(work_file.peek()<=0x80)
			{
				byte tmpc=work_file.read();
				//DEBUG_STRING_print(" ");
				//DEBUG_print_HEX(tmpc);
				midi_cmd.midi_cmd+=(char)tmpc;//work_file.read();
			}
			else break;
		}
		
		DEBUG_STRING_print("  CMD: ");

		print_debug_Hex_string(midi_cmd.midi_cmd);
		//DEBUG_STRING_print("CMD: ");
		//DEBUG_print_HEX(midi_cmd.midi_cmd[0]);
		//DEBUG_STRING_print(" ");
		//DEBUG_print_HEX(midi_cmd.midi_cmd[1]);
		//DEBUG_STRING_print(" ");
		//DEBUG_print_HEX(midi_cmd.midi_cmd[2]);
		
	}
	else if(byte_in==0xFF)//eden izmed eventov
	{
		switch(work_file.read())
		{
			case 0x00:	//Sequence number
			if(	work_file.read()==0x02)
			{
				DEBUG_STRING_print("SEQ NUM");
				DEBUG_print_HEX(work_file.read());
			}
			break;
			case 0x01:	//Text event
			DEBUG_STRING_print("==TEXT EVENT:");
			DEBUG_println(cmd_to_read(read_var_length()));
			break;
			case 0x02:	//Copyright notice
			DEBUG_STRING_print("==COPYRIGTH EVENT:");
			DEBUG_println(cmd_to_read(read_var_length()));
			break;
			case 0x03:	//Sequence or track name
			DEBUG_STRING_print("==TRACK NAME:");
			DEBUG_println(cmd_to_read(read_var_length()));
			break;
			case 0x04:	//Instrument name
			DEBUG_STRING_print("==INSTRUMENT NAME:");
			DEBUG_println(cmd_to_read(read_var_length()));
			break;
			case 0x05:	//Lyric text
			DEBUG_STRING_print("==LYRICS:");
			DEBUG_println(cmd_to_read(read_var_length()));
			break;
			case 0x06:	//Marker text
			DEBUG_STRING_print("==MARKER:");
			DEBUG_println(cmd_to_read(read_var_length()));
			break;
			case 0x07:	//Cue point
			DEBUG_STRING_print("==CUE:");
			DEBUG_println(cmd_to_read(read_var_length()));
			break;
			case 0x20:	//MIDI channel prefix assignment
			if(	work_file.read()==0x01)
			{
				DEBUG_STRING_print("==MIDI CH PREFIX:");
				DEBUG_println(work_file.read());
			}
			break;
			case 0x2F:	//End of track
			if(	work_file.read()==0x01)
			{
				DEBUG_STRING_print("==END OF TRACK:");
				DEBUG_println(work_file.read());
			}
			break;
			case 0x51:	//Tempo setting FF 51 03 tt tt tt
			DEBUG_STRING_print("==TEMPO:");
			if(	work_file.read()==0x03)
			{
				byte tempo[3];
				work_file.readBytes(tempo,3);
				float tempo_=return_float_from_3_byte(tempo);
				DEBUG_print(tempo_);
				// MIDI_speed
				
				
			}
			break;
			case 0x54:	//SMPTE offset
			DEBUG_STRING_print("==SMPTE offset:");
			work_file.readBytes(tmp_buffer,6);
			break;
			case 0x58:	//Time signature
			DEBUG_STRING_print("==TIME SIGN:");
			if(	work_file.read()==0x04)
			{
				work_file.readBytes(tmp_buffer,4);
				DEBUG_STRING_print(" NUM:");
				DEBUG_print(tmp_buffer[0]);
				DEBUG_STRING_print(" DENUM:");
				DEBUG_print(tmp_buffer[1]);
				DEBUG_STRING_print(" NUM:");
				DEBUG_print(tmp_buffer[2]);
				DEBUG_STRING_print(" NUM2:");
				DEBUG_print(tmp_buffer[3]);
			}
			break;
			case 0x59:	//Key signature
			DEBUG_STRING_print("==KEY SIGN:");
			work_file.readBytes(tmp_buffer,3);
			break;
			case 0x7F:	//Sequencer specific event
			DEBUG_STRING_print("==MANUF EVENT:");
			DEBUG_println(cmd_to_read(read_var_length()));
			break;
			
			default:
			DEBUG_STRING_println("TOLE SE NE SME ZGODITI...");
			break;
			
		}
		//FF 01 <len> <text>
		
		
	}

	
	DEBUG_println();
	
	return midi_cmd;
	
	
}

boolean MIDI_file_handler::check_if_cmd(char readed_char)
{
	if(readed_char>=0x80&&readed_char<=0xFF)
	return true;
	else
	return false;
}

int MIDI_file_handler::get_cmd_size(char readed_char)
{
	if(readed_char>=0x80&&readed_char<=0xBF)
	return 3;
	
	if(readed_char>=0xC0&&readed_char<=0xDF)
	return 2;
	
	if(readed_char>=0xE0&&readed_char<=0xEF)
	return 3;
	
	if(readed_char>=0xF0)
	return 0;
	
	return -1;
}

