/*
* MIDI_recplay.h
*
* Created: 12.2.2018 13:17:49
* Author: Greg
*/


#ifndef __MIDI_RECPLAY_H__
#define __MIDI_RECPLAY_H__

#include "SD_lib/SD.h"
#include <SPI.h>
#include "Midifile_cmd.h"

class MIDI_recplay
{
	//variables
	public:
	byte MIDI_format;
	byte MIDI_track_count;
	byte MIDI_speed;
	int  TRACK_length;
	int  loaded_count=0;
	unsigned long  var_last_add;
	unsigned long  time_count;
	unsigned long var_byte_count;
	unsigned long REC_time;
	unsigned long PLAY_time;
	unsigned long NEXT_time;
	unsigned long var_cmd_count=0;
	protected:
	private:

	//functions
	public:
	MIDI_recplay();
	~MIDI_recplay();
	bool start_playing(File &work_file);
	bool start_recording (File &work_file);
	bool save_midi_cmd(Midifile_cmd midi_cmd);
	bool ping_playing();
	boolean load_into_RAM_cmd(Midifile_cmd cmd_);
	protected:
	Midifile_cmd read_next_cmd();
	int get_cmd_size(char readed_char);
	String cmd_to_read(int size);
	void print_debug_Hex_string(String val);
	int read_var_length();
	private:
	uint32_t current_address;
	byte last_status;
	File work_file;

	MIDI_recplay( const MIDI_recplay &c );
	MIDI_recplay& operator=( const MIDI_recplay &c );

}; //MIDI_recplay

#endif //__MIDI_RECPLAY_H__
