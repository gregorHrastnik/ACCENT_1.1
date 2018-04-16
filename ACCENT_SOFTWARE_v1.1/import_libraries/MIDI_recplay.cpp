/*
* MIDI_recplay.cpp
*
* Created: 12.2.2018 13:17:49
* Author: Greg
*/


#include "MIDI_recplay.h"
#include "global_variables.h"
#include "Midifile_cmd.h"
#include "global_methods.h"

// default constructor
MIDI_recplay::MIDI_recplay()
{
} //MIDI_recplay

// default destructor
MIDI_recplay::~MIDI_recplay()
{
} //~MIDI_recplay

bool MIDI_recplay::start_playing(File &work_file)
{

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
	

}


bool MIDI_recplay::start_recording(File &work_file)
{

}

bool MIDI_recplay::save_midi_cmd(Midifile_cmd midi_cmd)
{
	char buffs[midi_cmd.midi_cmd_length];
	midi_cmd.midi_cmd.toCharArray(buffs, midi_cmd.midi_cmd_length);

	work_file.write(buffs,midi_cmd.midi_cmd_length);
}

Midifile_cmd cmd_tmp;
bool MIDI_recplay::ping_playing()
{
	if(loaded_count==0)//èe je buffer prazen ga naloži
	{
		uint32_t tmp_pos;
		
		while(true)
		{
			tmp_pos=work_file.position();//shrani trenutno pozicijo
			
			if(tmp_pos<work_file.size())
			{
				cmd_tmp=read_next_cmd();
				if(cmd_tmp.midi_cmd_delta_time>1)
				{
					work_file.seek(tmp_pos);
					break;
				}
				else
				{
					load_into_RAM_cmd(cmd_tmp);
					//exRAM.write_stream(current_address,cmd_tmp.midi_cmd,cmd_tmp.midi_cmd_length);
					loaded_count++;
				}
			}
		}
	}
	
	
}

 boolean MIDI_recplay::load_into_RAM_cmd(Midifile_cmd cmd_)
 {
	 time_count+=cmd_.midi_cmd_delta_time;
	 
	 byte midi_out;
	 byte cmd_length;
	 int delta_time;

	 
	 long next_cmd_add=current_address+9+cmd_length;//da ve kje v ramu prebrati naslednjo komando
	 long timestamp = time_count;
	 
	 
	 char rec_cmd[9+cmd_length];
	 var_byte_count+=9+cmd_length;//zapiši št vseh bajtov
	 
	 
	 rec_cmd[0] = (next_cmd_add & 0xFF);
	 rec_cmd[1] = ((next_cmd_add >> 8) & 0xFF);
	 rec_cmd[2] = ((next_cmd_add >> 16) & 0xFF);
	 rec_cmd[3] = ((next_cmd_add >> 24) & 0xFF);

	 rec_cmd[4] = (timestamp & 0xFF);
	 rec_cmd[5] = ((timestamp >> 8) & 0xFF);
	 rec_cmd[6] = ((timestamp >> 16) & 0xFF);
	 rec_cmd[7] = ((timestamp >> 24) & 0xFF);
	 
	 rec_cmd[8] = midi_out;
	 

	 #ifdef SERIAL_MONITOR_DEBUG

	 DEBUG_print(F(" HEX CMD: "));
	 softSerial.print((byte)cmd_.midi_cmd[0],HEX);
	 // DEBUG_print((byte)cmd[0],HEX);
	 DEBUG_print(F(" ::"));
	 softSerial.print((byte)cmd_.midi_cmd[1],HEX);
	 DEBUG_print(F(" :: "));
	 softSerial.print((byte)cmd_.midi_cmd[2],HEX);
	 #endif
	 
	 DEBUG_print(F("  ;DEC CMD: "));
	 for(byte x=9;x<cmd_length+9;x++)
	 
	 {
		 rec_cmd[x] = cmd_.midi_cmd[x-9];
		 
		 DEBUG_print(F(" :: "));
		 DEBUG_print((byte)rec_cmd[x]);
	 }
	 DEBUG_println(F(" "));
	 exRAM.write_stream(current_address,rec_cmd,9+cmd_length);

	 DEBUG_print(F("cmd length: "));
	 DEBUG_print(cmd_length);

	 DEBUG_print(F(" curr add: "));
	 DEBUG_print(current_address);

	 DEBUG_print(F(" next add: "));
	 DEBUG_print(next_cmd_add);

	 DEBUG_print(F(" cmd time: "));
	 DEBUG_print(timestamp);

	 NEXT_time=  exRAM.read_long(current_address+4);
	 DEBUG_print(F(" prebrani time:"));
	 DEBUG_print(NEXT_time);


	 DEBUG_print(F(" midi_out: "));
	 DEBUG_println(rec_cmd[8]);


	 var_last_add=current_address;//zadnji ukaz add
	 current_address+=(9+cmd_length);
	 var_cmd_count++;
	 
	 return true;
 }

Midifile_cmd MIDI_recplay::read_next_cmd()
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



int MIDI_recplay::get_cmd_size(char readed_char)
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
String MIDI_recplay::cmd_to_read(int size)
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
void MIDI_recplay::print_debug_Hex_string(String val)
{
	for(int x=0;x<val.length();x++)
	{
		DEBUG_print_HEX((byte)val[x]);
		DEBUG_STRING_print(" ");
	}
	//DEBUG_println();
}
int MIDI_recplay::read_var_length()
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