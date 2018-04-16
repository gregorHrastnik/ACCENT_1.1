/* 
* MIDI_mgr.h
*
* Created: 30.3.2017 9:58:30
* Author: Greg
*/
#ifndef _MIDI_MGR_h
#define _MIDI_MGR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Stop.h"

#define NOTE_ON 1
#define NOTE_OFF 2
#define MUTE_CH 3
#define MUTE_ALL 4
#define VOLUME_CH 5
#define VOLUME_MASTER 6


class MIDI_mgr
{
	public:
	//MIDI_mgr();
	//MIDI_mgr(byte TX, byte RX);
	void MIDI_mgr_init();
	byte MIDI_preklop(byte MIDI_out);
	//bool send_code(byte MIDI_id,byte value,byte channel);
	//bool send_code(byte MIDI_id, byte value);
	//byte get_midi_switch(Stop *stop);
	byte get_midi_id(int midi_sw);
	//void sendNoteOff(Stop *stop, byte data1, byte data2, byte data3);
	//void sendNoteOn(Stop *stop, byte data1, byte data2, byte data3);
	void send_note_DREAM(int key, bool on_off, int manual,byte velocity);
	//void sendControlChange(byte MIDI_SW, byte data1, byte data2, byte data3);
	//void sendSysEx(byte MIDI_SW, byte data1, byte *data2, byte data3);
	//void sendSysEx(byte data1, byte *data2, byte data3);
	void sendSysEx_MIDI_out(byte MIDI_out,byte data1, byte *data2, byte data3);
	void sendControlChange_MIDI_out(byte MIDI_out, byte data1, byte data2, byte data3);
	void sendProgramChange_MIDI_out(byte MIDI_out, byte data1, byte data2);
	void rec_note_helper(int key,byte velocity,bool on_off,byte manual);
	void play_note_input_inject_helper(int key,byte velocity,bool on_off,byte manual);
	void sendNote_MIDI_out(byte MIDI_out, byte key, byte velocity,byte midi_ch,bool on_off);
	void refresh_notes();
	//void sendControlChange(byte data1, byte data2, byte data3);
	//void sendProgramChange(byte data1, byte data2);
	void sendControlChange_via_stop(Stop *stop, byte data1, byte data2, byte data3);
	
//	void set_stop_ch(byte MIDI_num, byte id_ch, byte id_instrument, byte mode_oktava);
//	void init_TOTTER();
//	void mute_manual(byte manual);
	void mute_all_sounds();
	void send_reverb(byte midi_out,byte value_, byte REVERB_command);
	void equalizer_set(int ADDRESS_id, int value);
	void equalizer_set_pedal(int ADDRESS_id, int value);
	void tuning_send();
	void equalizer_startup_send();
	void equalizer_headphones_send();
	bool send_stop_notes_volume(byte stop_id,byte ID_modul);
	void startup_pan_send();
	void load_style_key(const int* location, byte* key_set);
	void change_style(byte style);
	void send_style_vars(byte* key_set);
	void send_note_on_output(byte MIDI_out,byte note,bool on_off,byte velocity,byte channel);
	//void send_midi_key(int key, Stop *stop, bool on_off, int manual, bool force_skip_check);
	//void send_midi_key_universal(int key, Stop *stop, bool on_off, int manual, bool force_skip_check, byte _volume);
	//void send_midi_key_totter_single(int key, Stop *stop, bool on_off, int manual, bool force_skip_check, byte _volume);
	//void send_midi_key_totter_single_backup(int key, Stop *stop, bool on_off, int manual, bool force_skip_check, byte _volume);
	void send_midi_key_grand_orgue(int key, Stop *stop, bool on_off, int manual, bool force_skip_check);
	//void send_midi_key_totter_dual(int key, Stop *stop, bool on_off, int manual, bool force_skip_check, byte _volume);
	void send_MIDI_function(int key, bool on_off, int manual, int MIDI_code);
	void send_MIDI_test(int MIDI_code, int value,int manual);
	void send_MIDI_code(int MIDI_code, int value,int parameter_extra,int parameter_extra_2);
	//void send_MIDI_TREMULANT(int MIDI_code, int value,int manual);
	void setup_stop_disposition(byte disposition,byte katera_plata);
	//void send_STOP_state(byte ID, byte midi_kanal);
	void send_midi_MASTER_volume_change();
	void send_midi_active_sense();
	void send_midi_volume_change(Stop *stop, byte volume);
	void send_midi_volume_change_man2(Stop *stop, byte volume);
	void send_midi_volume_change_manual(byte _manual, byte volume);
	
	void send_tremulant_key(int key, Stop *stop_in, bool on_off, int manual, bool force_skip_check);
	


	//void reset_key_counter();
	//int MAN1_key_count;
	//int MAN2_key_count;
	//int MAN3_key_count;
	//int MAN_ped_key_count;
//
	//byte MIDI_1_switch = 0;
	//byte MIDI_2_switch = 0;
//
	//byte MAN_1_last_mode = -1;
	//byte MAN_2_last_mode = -1;
	//byte MAN_3_last_mode = -1;
	byte LAST_sended_tone=0;
	byte PREV_tone=0;

};
#endif