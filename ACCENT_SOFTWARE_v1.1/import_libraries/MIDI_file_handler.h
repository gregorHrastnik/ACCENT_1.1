/* 
* MIDI_file_handler.h
*
* Created: 11.9.2017 14:47:13
* Author: Greg
*/


#ifndef __MIDI_FILE_HANDLER_H__
#define __MIDI_FILE_HANDLER_H__

#include "SD_lib/SD.h"
#include <SPI.h>
#include "Midifile_cmd.h"

class MIDI_file_handler
{
//variables
public:
byte MIDI_format;
byte MIDI_track_count;
byte MIDI_speed;
int  TRACK_length;
protected:
private:
File work_file;

//functions
public:
	MIDI_file_handler(File &file_to_read);
	~MIDI_file_handler();
	
	String cmd_to_read(int size);
	int read_var_length();
	void print_debug_Hex_string(String val);
	Midifile_cmd read_next_cmd();//return next command
	boolean check_if_cmd(char readed_char);
	int get_cmd_size(char readed_char);
protected:
private:
	MIDI_file_handler( const MIDI_file_handler &c );
	MIDI_file_handler& operator=( const MIDI_file_handler &c );

}; //MIDI_file_handler

#endif //__MIDI_FILE_HANDLER_H__
