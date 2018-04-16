// SD_mgr.h

#ifndef _SD_MGR_h
#define _SD_MGR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"

#include "SD_lib/SD.h"
#include <SPI.h>

#else
#include "WProgram.h"


#endif
void copy_file();

#include "MIDI_file_handler.h"
#include "Stop.h"

#define  state_IDLING 0
#define state_RECORDING 1
#define  state_PLAYING 2
#define end_of_rec 254


class SD_mgr
{
	public:
	SD_mgr();
	void printDirectory1(File dir, int numTabs);

	void SD_mgr_init();

	boolean Read_zecer_combination(byte user, byte button, int combination_num, byte* combination);
	boolean Read_zecer_combination_backup(byte button, byte combination_num, byte* combination);
	boolean Write_zecer_combination(byte user, byte button, int combination_num, byte* combination);
	boolean Write_zecer_combination_backup(byte button, byte combination_num, byte* combination);
	boolean copyFile(char* path_name, char* path_name_tmp, byte limit_current, int combination_num, char* tempC);
	boolean create_blank_file(byte user);
	boolean load_exRAM(String path);
	boolean midi_file_testing(String path);
	boolean sd_files_refresh();
	byte files_count;
	bool _connection=false;
	//boolean Start_recording();
	//boolean Stop_recording();

	//boolean List_files(File* files);
	//File file_A;
	//File file_REC;
	//File file_B;
	boolean refresh();
	boolean check_SD_init();
	byte set_recording(bool ON_OFF);
	byte set_playing(bool ON_OFF,String path);
	boolean get_is_recording();
	boolean get_is_playing();
	boolean load_exRAM_part(String path);
	boolean save_current_recording(String path);
	
	boolean recording_rec_gas_pedal(byte manual,byte value);
	boolean recording_add_note(byte manual,byte note,bool on_off);
	//boolean write_cmd(byte* cmd);
	boolean rec_midi_event(byte* cmd,byte midi_out,byte cmd_length);
	boolean read_send_midi_event();
	boolean recording_add_stop_change(Stop* stop,bool ON_OFF);
	boolean load_into_RAM_cmd(Midifile_cmd cmd_);
	//boolean stop_Recording(byte* midi_code);
	
	unsigned long sd_read_long(unsigned long location);
	bool save_settings_to_file(String path);
	bool load_settings(String path);
	bool save_profile_to_file(String path,byte id_profile);
	bool load_profile(String path,byte id_profile);
	unsigned long REC_time;
	unsigned long PLAY_time;
	unsigned long NEXT_time;
	unsigned long get_timestamp(byte state);
	unsigned long get_current_address();
	unsigned long  time_count;
	
	void(*_update_trigger)(byte value);
	
	int get_filecount();
	int get_recording_time();
	int get_playing_time();

	unsigned long Var_track_time() const { return var_track_time; }
	void Var_track_time(unsigned long val) { var_track_time = val; }
	private:
	byte state_rec_play =  state_IDLING;
	unsigned long current_address;
	unsigned long var_cmd_count=0;
	unsigned long PLAY_cmd_count=0;
	int recording_timer=0;
	
	
	unsigned long var_byte_count;
	unsigned long var_last_add;
	unsigned long var_track_time;

	bool sd_opened=false;
	File SD_master;
	int loaded_cmd_counter;
};

#endif

