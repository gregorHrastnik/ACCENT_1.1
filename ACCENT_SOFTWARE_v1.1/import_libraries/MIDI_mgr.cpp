/*
* MIDI_mgr.cpp
*
* Created: 30.3.2017 9:58:30
* Author: Greg
*/

//
//
//

#include "MIDI_mgr.h"
#include <MIDI.h>
#include "global_variables.h"
#include <SoftwareSerial.h>
#include "arduino2.h"
#include "EEPROM.h"
#include "SD_mgr.h"
#include <avr\pgmspace.h>
#include "PROGMEM_labels.h"
#include "Definitions_pins.h"
#include "global_methods.h"


struct MIDI_settings : public midi::DefaultSettings
{
	//static const long BaudRate = 31250;
	#ifdef MIDI_OX_OUTPUT
	static const long BaudRate = 32150;
	//static const long BaudRate = 160000;

	#else

	#ifdef TOTTER_DUAL_output
	static const long BaudRate = 160000;
	#endif // TOTTER_DUAL_output

	#ifdef TOTTER_SINGLE_output
	static const long BaudRate = 160000;
	#endif // TOTTER_SINGLE_output

	#ifdef _GRAND_ORGUE_output
	static const long BaudRate = 32150;
	#endif // TOTTER_SINGLE_output DREAM_OUTPUT
	
	#ifdef DREAM_OUTPUT
	static const long BaudRate = 32150;
	#endif // TOTTER_SINGLE_output

	#endif // MIDI_OX_OUTPUT

};


//extern SoftwareSerial mySerial(0, 1); // RX, TX
extern MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial1, MIDI, MIDI_settings);

// extern SoftwareSerial mySerial(A9, 18); // RX, TX
//MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial1, MIDI, MIDI_settings);

//extern SoftwareSerial mySerial2(19, 18); // RX, TX
extern MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI2, MIDI_settings);
//extern MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial2, MIDI3, MIDI_settings);
extern MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial3, MIDI3, MIDI_settings);
extern MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial2, MIDI4, MIDI_settings);
//extern SoftwareSerial mySerial3(19, 18); // RX, TX
//extern MIDI_CREATE_CUSTOM_INSTANCE(SoftwareSerial, mySerial3, MIDI3, MIDI_settings);

//extern SoftwareSerial mySerial4(19, 18); // RX, TX
//extern MIDI_CREATE_CUSTOM_INSTANCE(SoftwareSerial, mySerial4, MIDI4, MIDI_settings);


void MIDI_mgr::MIDI_mgr_init()
{
	MIDI.begin();
	MIDI2.begin();
	//MIDI.sendNoteOff(11, 11, 3);
	MIDI3.begin();
	MIDI4.begin();
}
#define test_preklop

byte cur_selected_board=10;
byte MIDI_mgr::MIDI_preklop(byte MIDI_out)
{
	#ifdef test_preklop
	byte cmdtmp[] =  {0xF5,0x01,0x00};

	//preklop_MIDI1[0]==0x5F;
	//preklop_MIDI1[1]=0x05;
	
	
	if(cur_selected_board==MIDI_out)
	return false;
	
	cur_selected_board=MIDI_out;

	switch (MIDI_out)
	{
		case 0:
		cmdtmp[1]=1;
		break;
		case 2:
		cmdtmp[1]=2;
		break;
		case 3:
		cmdtmp[1]=3;
		break;
		case 4:
		cmdtmp[1]=4;
		break;
	};
	MIDI.sendSysEx(2, cmdtmp, true);
	return false;
	#endif

	
	#ifdef ONE_WIRE_MIDI

	if(cur_selected_board==MIDI_out)
	return false;
	
	cur_selected_board=MIDI_out;
	
	//byte cmdtmp[] =  {240,245, 2,100,5,247};
	
	//return true;
	
	//MIDI.send(InvalidType,preklop_MIDI1[0],preklop_MIDI1[1])
	
	switch (MIDI_out)
	{
		case 0:
		MIDI.sendSysEx(2, preklop_MIDI1, true);
		break;
		case 2:
		MIDI.sendSysEx(2, preklop_MIDI2, true);
		break;
		case 3:
		MIDI.sendSysEx(2, preklop_MIDI3, true);;
		break;
		case 4:
		MIDI.sendSysEx(2, preklop_MIDI4, true);
		break;
	};
	//MIDI_preklop(ID_MIDI_1, MIDI_SW_1);
	
	DEBUG_STRING_println("preklop ");
	DEBUG_println(MIDI_out);
	#endif
}

byte MIDI_mgr::get_midi_id(int midi_sw)
{


	#ifdef TOTTER_SINGLE_output
	switch (midi_sw)
	{
		case MIDI_SW_1:
		return ID_MIDI_1;
		break;
		case MIDI_SW_2:
		return ID_MIDI_1;
		break;
		case MIDI_SW_3:
		return ID_MIDI_1;
		break;
		case MIDI_SW_4:
		return ID_MIDI_1;
		break;
		case MIDI_SW_5:
		return ID_MIDI_1;
		break;
		case MIDI_SW_6:
		return ID_MIDI_1;
		break;
		default:
		return 0;
		break;
	}

	#endif // TOTTER_SINGLE_output

	DEBUG_print(F("switch case for "));
	DEBUG_print(midi_sw);
	DEBUG_print(F(" -> "));
	#ifdef TOTTER_DUAL_output
	switch (midi_sw)
	{
		case MIDI_SW_1:
		DEBUG_println(ID_MIDI_1);
		return ID_MIDI_1;
		break;
		case MIDI_SW_2:
		DEBUG_println(ID_MIDI_1);
		return ID_MIDI_1;
		break;
		case MIDI_SW_3:
		DEBUG_println(ID_MIDI_2);
		return ID_MIDI_2;
		break;
		case MIDI_SW_4:
		DEBUG_println(ID_MIDI_2);
		return ID_MIDI_2;
		break;
		default:
		return 0;
		break;
	}

	#endif // TOTTER_SINGLE_output

}




void MIDI_mgr::sendSysEx_MIDI_out(byte MIDI_out,byte data1, byte *data2, byte data3)
{

	#ifdef ONE_WIRE_MIDI
	MIDI_sender.MIDI_preklop(MIDI_out);
	MIDI.sendSysEx(data1, data2, data3);
	return;
	#endif

	switch (MIDI_out)
	{
		case 1:
		MIDI.sendSysEx(data1, data2, data3);
		break;
		case 2:
		MIDI2.sendSysEx(data1, data2, data3);
		break;
		case 3:
		MIDI3.sendSysEx(data1, data2, data3);
		break;
		case 4:
		MIDI4.sendSysEx(data1, data2, data3);
		break;
	};
	

}
void MIDI_mgr::sendControlChange_MIDI_out(byte MIDI_out,byte data1, byte data2, byte data3)
{
	#ifdef ONE_WIRE_MIDI
	MIDI_sender.MIDI_preklop(MIDI_out);
	MIDI.sendControlChange(data1, data2, data3);
	return;
	#endif
	
	switch (MIDI_out)
	{
		case 1:
		MIDI.sendControlChange(data1, data2, data3);
		break;
		case 2:
		MIDI2.sendControlChange(data1, data2, data3);
		break;
		case 3:
		MIDI3.sendControlChange(data1, data2, data3);
		break;
		case 4:
		MIDI4.sendControlChange(data1, data2, data3);
		break;
	};
	return;
	DEBUG_print(F("CC MIDI out: "));
	DEBUG_print(MIDI_out);
	DEBUG_print(F(" STOP id: "));
	DEBUG_print(data1);
	DEBUG_print(F(" STOP id: "));
	DEBUG_print(data2);
	DEBUG_print(F(" ch: "));
	DEBUG_println(data3);
	
}

void MIDI_mgr::sendControlChange_via_stop(Stop *stop, byte data1, byte data2, byte data3)
{
	switch (stop->get_MIDI_out_numb())
	{
		case 1:
		MIDI.sendControlChange(data1, data2, data3);
		break;
		case 2:
		MIDI2.sendControlChange(data1, data2, data3);
		break;
		case 3:
		MIDI3.sendControlChange(data1, data2, data3);
		break;
		case 4:
		MIDI4.sendControlChange(data1, data2, data3);
		break;
	};

	
}


void MIDI_mgr::sendProgramChange_MIDI_out(byte MIDI_out, byte data1, byte data2)
{
	//DEBUG_print(F("PC MIDI out: "));
	//DEBUG_print(MIDI_out);
	//DEBUG_print(F(" STOP id: "));
	//DEBUG_print(data1);
	//DEBUG_print(F(" CH: "));
	//DEBUG_println(data2);
	#ifdef ONE_WIRE_MIDI
	MIDI_sender.MIDI_preklop(MIDI_out);
	MIDI.sendProgramChange(data1, data2);
	return;
	#endif
	
	switch (MIDI_out)
	{
		case 1:
		MIDI.sendProgramChange(data1, data2);
		break;
		case 2:
		MIDI2.sendProgramChange(data1, data2);
		break;
		case 3:
		MIDI3.sendProgramChange(data1, data2);
		break;
		case 4:
		MIDI4.sendProgramChange(data1, data2);
		break;
	};
	
	return;


}

void MIDI_mgr::rec_note_helper(int key,byte velocity,bool on_off,byte manual)
{
	byte midi_event[3];
	midi_event[1]=key+23;
	midi_event[2]=velocity;
	if(on_off)
	midi_event[0]=144;
	else
	midi_event[0]=128;
	
	#ifdef INCLUDE_KEY_INFO
	DEBUG_print(F("outKEY "));
	DEBUG_print(key);
	DEBUG_print(F(" VELO: "));
	DEBUG_println(velocity);

	#endif
	
	switch (manual)
	{
		case PEDAL:
		SD_work.rec_midi_event(midi_event,1,3);
		break;
		
		case MANUAL_1:
		midi_event[0]+=1;
		SD_work.rec_midi_event(midi_event,1,3);
		break;
		
		case MANUAL_2:
		midi_event[0]+=2;
		SD_work.rec_midi_event(midi_event,1,3);
		break;
		
		case MANUAL_3:
		midi_event[0]+=3;
		SD_work.rec_midi_event(midi_event,1,3);
		break;
		
		case MANUAL_4:
		midi_event[0]+=4;
		SD_work.rec_midi_event(midi_event,1,3);
		break;
		
		case MANUAL_5:
		midi_event[0]+=5;
		SD_work.rec_midi_event(midi_event,1,3);
		break;
	}
}

void MIDI_mgr::play_note_input_inject_helper(int key,byte velocity,bool on_off,byte manual)
{
	//DEBUG_print(" INJECT KEY: ");
	//DEBUG_print(key);
	//DEBUG_print(" ON_OFF:");
	//DEBUG_print(on_off);
	//DEBUG_print(" MAN:");
	//DEBUG_println(manual);
	switch(manual)
	{
		case MANUAL_1:
		//S_bit(k_MAN_I_L_old,key,false) ;
		S_bit(k_MAN_I_L_recorder,key,on_off) ;
		break;
		case MANUAL_2:
		//	S_bit(k_MAN_II_L_old,key,!on_off) ;
		S_bit(k_MAN_II_L_recorder,key,on_off) ;
		break;
		case MANUAL_3:
		//S_bit(k_MAN_III_L,key,!on_off) ;
		S_bit(k_MAN_III_L_recorder,key,on_off) ;
		break;
		
		case PEDAL:
		//	S_bit(k_PED_old,key,!on_off) ;
		S_bit(k_PED_recorder,key,on_off) ;
		break;
	}
}

//void help_record_key_input(byte *buttn_tab_HIGH, byte *buttn_tab_old_HIGH,byte *buttn_tab_LOW, byte *buttn_tab_old_LOW, byte _MANUAL)
//{
//for(int x=0;x<key_arr_size;x++)
//{
//if(buttn_tab_LOW[x]!=buttn_tab_old_LOW[x])//pojdi najprej primerjat bajt, šele potem bite v tem bajtu: okoli 4 do 8x hitreje
//{
//for (int i = x*8; i < (x+1)*8; i++)
//{
//
//if (G_bit(buttn_tab_LOW,i)==true){
//if ((G_bit(buttn_tab_LOW,i) !=G_bit(buttn_tab_old_LOW,i)))
//{
//
//SD_work.recording_add_note(_MANUAL,i,true);
////MIDI_sender.send_note_DREAM(i, true, _MANUAL,127);
//S_bit(buttn_tab_old_LOW,i,G_bit(buttn_tab_LOW,i)) ;
//}
//}
//else
//{
//if ((G_bit(buttn_tab_LOW,i) !=G_bit(buttn_tab_old_LOW,i)))
//{
//SD_work.recording_add_note(_MANUAL,i,false);
////MIDI_sender.send_note_DREAM(i, false, _MANUAL,0);
//S_bit(buttn_tab_old_LOW,i,G_bit(buttn_tab_LOW,i));
//}
//}
//}
//}
//}
//}

void MIDI_mgr::sendNote_MIDI_out(byte MIDI_out, byte key, byte velocity,byte midi_ch,bool on_off)
{
	
	
	

	byte midi_event[3];
	midi_event[0]=127+midi_ch;
	midi_event[1]=key+23;
	midi_event[2]=velocity;
	
	//SD_work.rec_midi_event(midi_event,MIDI_out,3);

	if(on_off==false)
	velocity=0;
	//key += value_TRANSPOSE-12;
	key+=value_TRANSPOSE-TRANS_adjust+23;
	//key += value_TRANSPOSE-12;
	//send_midi_key_grand_orgue(key, stop, on_off, manual, force_skip_check);
	
	
	
	//DEBUG_println(value_TRANSPOSE);

	#ifdef ONE_WIRE_MIDI
	MIDI_preklop(MIDI_out);
	MIDI.sendNoteOn(key, velocity, midi_ch);
	return;
	#endif

	
	switch (MIDI_out)
	{
		case 1:
		MIDI.sendNoteOn(key, velocity, midi_ch);
		break;
		case 2:
		MIDI2.sendNoteOn(key, velocity, midi_ch);
		break;
		case 3:
		MIDI3.sendNoteOn(key, velocity, midi_ch);
		break;
		case 4:
		MIDI4.sendNoteOn(key, velocity, midi_ch);
		break;
	};
	


}

void MIDI_mgr::refresh_notes()
{
	for (int i = 0; i < key_arr_old_size; i++){
		k_MAN_I_L_old[i]=0;
		k_MAN_II_L_old[i]=0;
		k_MAN_III_L_old[i]=0;
		k_PED_old[i]=0;
	}
}





void MIDI_mgr::mute_all_sounds()
{
	//
	MIDI_sender.sendControlChange_MIDI_out(MIDI_1,123, 0,1);
	MIDI_sender.sendControlChange_MIDI_out(MIDI_1,123, 0,2);
	MIDI_sender.sendControlChange_MIDI_out(MIDI_2,123, 0,1);
	MIDI_sender.sendControlChange_MIDI_out(MIDI_2,123, 0,2);
	MIDI_sender.sendControlChange_MIDI_out(MIDI_3,123, 0,1);
	MIDI_sender.sendControlChange_MIDI_out(MIDI_3,123, 0,2);
	MIDI_sender.sendControlChange_MIDI_out(MIDI_4,123, 0,1);
	MIDI_sender.sendControlChange_MIDI_out(MIDI_4,123, 0,2);


	for (int i = 0; i < 90; i++){
		MIDI_sender.sendNote_MIDI_out(1,i,127,1,false);
		MIDI_sender.sendNote_MIDI_out(1,i,127,2,false);
		MIDI_sender.sendNote_MIDI_out(2,i,127,2,false);
		MIDI_sender.sendNote_MIDI_out(3,i,127,2,false);
		MIDI_sender.sendNote_MIDI_out(4,i,127,2,false);
	}

	
	
	
}



void MIDI_mgr::send_reverb(byte midi_out,byte value_, byte REVERB_command)
{
	if (value_ > 127)
	value_ = 127;
	
	if(REVERB_command==0x33)//temp fix reverb za procente
	{
		double procent=EEPROM.read(add_VALUE_REVERB_procent);
		//DEBUG_STRING_print("eeprom val: ");
		//DEBUG_print(procent);
		//DEBUG_STRING_print("rvr org: ");
		//DEBUG_print(value_);
		
		double out_val=(double)value_*procent/100;
		value_=out_val;
		//DEBUG_STRING_print(" rev %:");
		//DEBUG_println(value_);
	}
	
	//value_=127;

	if(REVERB_command==0x5B)
	{
		byte cmdtmp[] =  {0xB0, 0x5B,value_};
		if(midi_out==MIDI_1)
		{
			sendSysEx_MIDI_out(MIDI_1, 3, cmdtmp, false);
			sendSysEx_MIDI_out(MIDI_2, 3, cmdtmp, false);
		}
		if(midi_out==MIDI_2)
		{
			sendSysEx_MIDI_out(MIDI_3, 3, cmdtmp, false);
			sendSysEx_MIDI_out(MIDI_4, 3, cmdtmp, false);
		}
		
		return;
	}
	byte GS_command[] = { 0xF0, 0x41, 0x00, 0x42, 0x12, 0x40, 0x01, REVERB_command, value_, 0x00, 0xF7 };
	byte reverb_var = EEPROM.read(add_VALUE_REVERB);
	reverb_var=0;
	//MIDI_preklop(ID_MIDI_1, MIDI_SW_1);
	//MIDI.sendSysEx(2, preklop_MIDI1, false);
	
	if(midi_out==MIDI_1)
	{
		sendSysEx_MIDI_out(MIDI_1, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 11, GS_command, true);
	}
	if(midi_out==MIDI_2)
	{
		sendSysEx_MIDI_out(MIDI_3, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 11, GS_command, true);
	}
	if (REVERB_command == 0x30)
	delay(1000);
	else
	delay(50);

	//DEBUG_print(F("reverb "));
	//DEBUG_print(REVERB_command);
	//DEBUG_STRING_print(" ");
	//DEBUG_println(value_);


}


void MIDI_mgr::equalizer_set(int ADDRESS_id, int value)
{

	byte manual_OUT=0;

	//byte GS_command[] = { 0xF0, 0x41, 0x00, 0x42, 0x12, 0x40, 0x02,0x00, value, 0x00, 0xF7 };

	//if(value%2==1)
	//value=127;
	//else
	//value=0;
	
	
	
	//return;
	if(ADDRESS_id==ADD_menu_b1_equalizer_Q_high||ADDRESS_id==ADD_menu_b1_equalizer_Q_high_II||ADDRESS_id==ADD_menu_b1_equalizer_Q_high_III||ADDRESS_id==ADD_menu_b1_equalizer_Q_high_IV)
	{
		if(value>114)
		value=114;
	}
	
	byte command_id=0;
	
	byte command_1[] = { 0xB0, 0x63, 0x37,
		0xB0, 0x62, command_id,
	0xB0, 0x06, value  };
	byte command_2[] = { 0xB0, 0x62, command_id };
	byte command_3[] = { 0xB0, 0x06, value };

	switch (ADDRESS_id)
	{
		case ADD_menu_b1_equalizer_gain_low:
		command_1[5]=0x08;manual_OUT=MIDI_1;
		break;
		case ADD_menu_b1_equalizer_gain_low_mid:
		command_1[5]=0x09;manual_OUT=MIDI_1;
		break;
		case ADD_menu_b1_equalizer_gain_high_mid:
		command_1[5]=0x0A;manual_OUT=MIDI_1;
		break;
		
		case  ADD_menu_b1_equalizer_gain_high:
		command_1[5]=0x0B;manual_OUT=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_band_0_800:
		command_1[5]=0x0C;manual_OUT=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500:
		command_1[5]=0x0D;manual_OUT=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700:
		command_1[5]=0x0E;manual_OUT=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_band_1000_5800:
		command_1[5]=0x0F;manual_OUT=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_Q_low:
		command_1[5]=0x10;manual_OUT=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_mid:
		command_1[5]=0x10;manual_OUT=MIDI_1;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_mid:
		command_1[5] = 0x11;manual_OUT=MIDI_1;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high:
		command_1[5] = 0x11;manual_OUT=MIDI_1;
		break;
		
		//////////////
		case ADD_menu_b1_equalizer_gain_low_II:
		command_1[5]=0x08;manual_OUT=MIDI_2;
		break;
		case ADD_menu_b1_equalizer_gain_low_mid_II:
		command_1[5]=0x09;manual_OUT=MIDI_2;
		break;
		case ADD_menu_b1_equalizer_gain_high_mid_II:
		command_1[5]=0x0A;manual_OUT=MIDI_2;
		break;
		
		case  ADD_menu_b1_equalizer_gain_high_II:
		command_1[5]=0x0B;manual_OUT=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_band_0_800_II:
		command_1[5]=0x0C;manual_OUT=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_II:
		command_1[5]=0x0D;manual_OUT=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_II:
		command_1[5]=0x0E;manual_OUT=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_II:
		command_1[5]=0x0F;manual_OUT=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_II:
		command_1[5]=0x10;manual_OUT=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_mid_II:
		command_1[5]=0x10;manual_OUT=MIDI_2;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_mid_II:
		command_1[5] = 0x11;manual_OUT=MIDI_2;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_II:
		command_1[5] = 0x11;manual_OUT=MIDI_2;
		break;
		
		//////////////
		case ADD_menu_b1_equalizer_gain_low_III:
		command_1[5]=0x08;manual_OUT=MIDI_1;
		break;
		case ADD_menu_b1_equalizer_gain_low_mid_III:
		command_1[5]=0x09;manual_OUT=MIDI_1;
		break;
		case ADD_menu_b1_equalizer_gain_high_mid_III:
		command_1[5]=0x0A;manual_OUT=MIDI_1;
		break;
		
		case  ADD_menu_b1_equalizer_gain_high_III:
		command_1[5]=0x0B;manual_OUT=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_band_0_800_III:
		command_1[5]=0x0C;manual_OUT=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_III:
		command_1[5]=0x0D;manual_OUT=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III:
		command_1[5]=0x0E;manual_OUT=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_III:
		command_1[5]=0x0F;manual_OUT=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_III:
		command_1[5]=0x10;manual_OUT=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_mid_III:
		command_1[5]=0x10;manual_OUT=MIDI_1;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_mid_III:
		command_1[5] = 0x11;manual_OUT=MIDI_1;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_III:
		command_1[5] = 0x11;manual_OUT=MIDI_1;
		break;
		//////////////
		case ADD_menu_b1_equalizer_gain_low_IV:
		command_1[5]=0x08;manual_OUT=MIDI_2;
		break;
		case ADD_menu_b1_equalizer_gain_low_mid_IV:
		command_1[5]=0x09;manual_OUT=MIDI_2;
		break;
		case ADD_menu_b1_equalizer_gain_high_mid_IV:
		command_1[5]=0x0A;manual_OUT=MIDI_2;
		break;
		
		case  ADD_menu_b1_equalizer_gain_high_IV:
		command_1[5]=0x0B;manual_OUT=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_band_0_800_IV:
		command_1[5]=0x0C;manual_OUT=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_IV:
		command_1[5]=0x0D;manual_OUT=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_IV:
		command_1[5]=0x0E;manual_OUT=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_IV:
		command_1[5]=0x0F;manual_OUT=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_IV:
		command_1[5]=0x10;manual_OUT=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_mid_IV:
		command_1[5]=0x10;manual_OUT=MIDI_2;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_mid_IV:
		command_1[5] = 0x11;manual_OUT=MIDI_2;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_IV:
		command_1[5] = 0x11;manual_OUT=MIDI_2;
		break;
		default:
		break;
	}
	
	//DEBUG_STRING_print("EQU MAN: ");
	//DEBUG_print(manual_OUT);
	//DEBUG_STRING_print(" CMD: ");
	//DEBUG_print_HEX(command_1[5]);
	//DEBUG_STRING_print(" val_DEC:");
	//DEBUG_print(value);
	//DEBUG_STRING_print(" val_HEX:");
	//DEBUG_print_HEX(value);
	//DEBUG_println();
	
	switch (manual_OUT)
	{
		case MIDI_1:
		sendSysEx_MIDI_out(MIDI_1, 9, command_1, false);
		sendSysEx_MIDI_out(MIDI_2, 9, command_1, false);
		break;
		
		case MIDI_2:
		sendSysEx_MIDI_out(MIDI_3, 9, command_1, false);
		sendSysEx_MIDI_out(MIDI_4, 9, command_1, false);
		break;
		
		
	}
	
	


}

#ifdef tmp_za_brisat
void MIDI_mgr::equalizer_set(int ADDRESS_id, int value)
{
	byte midi_out=0;

	//byte GS_command[] = { 0xF0, 0x41, 0x00, 0x42, 0x12, 0x40, 0x02,0x00, value, 0x00, 0xF7 };

	//if(value%2==1)
	//value=127;
	//else
	//value=0;
	
	
	
	//return;
	if(ADDRESS_id==ADD_menu_b1_equalizer_Q_high||ADDRESS_id==ADD_menu_b1_equalizer_Q_high_II||ADDRESS_id==ADD_menu_b1_equalizer_Q_high_III||ADDRESS_id==ADD_menu_b1_equalizer_Q_high_IV)
	{
		if(value>114)
		value=114;
	}
	
	byte command_id=0;
	
	byte command_1[] = { 0xB0, 0x63, 0x37,
		0xB0, 0x62, command_id,
	0xB0, 0x06, value  };
	byte command_2[] = { 0xB0, 0x62, command_id };
	byte command_3[] = { 0xB0, 0x06, value };

	switch (ADDRESS_id)
	{
		case ADD_menu_b1_equalizer_gain_low:
		command_1[5]=0x08;midi_out=MIDI_1;
		break;
		case ADD_menu_b1_equalizer_gain_low_mid:
		command_1[5]=0x09;midi_out=MIDI_1;
		break;
		case ADD_menu_b1_equalizer_gain_high_mid:
		command_1[5]=0x0A;midi_out=MIDI_1;
		break;
		
		case  ADD_menu_b1_equalizer_gain_high:
		command_1[5]=0x0B;midi_out=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_band_0_800:
		command_1[5]=0x0C;midi_out=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500:
		command_1[5]=0x0D;midi_out=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700:
		command_1[5]=0x0E;midi_out=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_band_1000_5800:
		command_1[5]=0x0F;midi_out=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_Q_low:
		command_1[5]=0x10;midi_out=MIDI_1;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_mid:
		command_1[5]=0x10;midi_out=MIDI_1;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_mid:
		command_1[5] = 0x11;midi_out=MIDI_1;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high:
		command_1[5] = 0x11;midi_out=MIDI_1;
		break;
		
		//////////////
		case ADD_menu_b1_equalizer_gain_low_II:
		command_1[5]=0x08;midi_out=MIDI_2;
		break;
		case ADD_menu_b1_equalizer_gain_low_mid_II:
		command_1[5]=0x09;midi_out=MIDI_2;
		break;
		case ADD_menu_b1_equalizer_gain_high_mid_II:
		command_1[5]=0x0A;midi_out=MIDI_2;
		break;
		
		case  ADD_menu_b1_equalizer_gain_high_II:
		command_1[5]=0x0B;midi_out=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_band_0_800_II:
		command_1[5]=0x0C;midi_out=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_II:
		command_1[5]=0x0D;midi_out=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_II:
		command_1[5]=0x0E;midi_out=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_II:
		command_1[5]=0x0F;midi_out=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_II:
		command_1[5]=0x10;midi_out=MIDI_2;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_mid_II:
		command_1[5]=0x10;midi_out=MIDI_2;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_mid_II:
		command_1[5] = 0x11;midi_out=MIDI_2;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_II:
		command_1[5] = 0x11;midi_out=MIDI_2;
		break;
		
		//////////////
		case ADD_menu_b1_equalizer_gain_low_III:
		command_1[5]=0x08;midi_out=MIDI_3;
		break;
		case ADD_menu_b1_equalizer_gain_low_mid_III:
		command_1[5]=0x09;midi_out=MIDI_3;
		break;
		case ADD_menu_b1_equalizer_gain_high_mid_III:
		command_1[5]=0x0A;midi_out=MIDI_3;
		break;
		
		case  ADD_menu_b1_equalizer_gain_high_III:
		command_1[5]=0x0B;midi_out=MIDI_3;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_band_0_800_III:
		command_1[5]=0x0C;midi_out=MIDI_3;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_III:
		command_1[5]=0x0D;midi_out=MIDI_3;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III:
		command_1[5]=0x0E;midi_out=MIDI_3;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_III:
		command_1[5]=0x0F;midi_out=MIDI_3;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_III:
		command_1[5]=0x10;midi_out=MIDI_3;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_mid_III:
		command_1[5]=0x10;midi_out=MIDI_3;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_mid_III:
		command_1[5] = 0x11;midi_out=MIDI_3;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_III:
		command_1[5] = 0x11;midi_out=MIDI_3;
		break;
		//////////////
		case ADD_menu_b1_equalizer_gain_low_IV:
		command_1[5]=0x08;midi_out=MIDI_4;
		break;
		case ADD_menu_b1_equalizer_gain_low_mid_IV:
		command_1[5]=0x09;midi_out=MIDI_4;
		break;
		case ADD_menu_b1_equalizer_gain_high_mid_IV:
		command_1[5]=0x0A;midi_out=MIDI_4;
		break;
		
		case  ADD_menu_b1_equalizer_gain_high_IV:
		command_1[5]=0x0B;midi_out=MIDI_4;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_band_0_800_IV:
		command_1[5]=0x0C;midi_out=MIDI_4;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_IV:
		command_1[5]=0x0D;midi_out=MIDI_4;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_IV:
		command_1[5]=0x0E;midi_out=MIDI_4;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_IV:
		command_1[5]=0x0F;midi_out=MIDI_4;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_IV:
		command_1[5]=0x10;midi_out=MIDI_4;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_mid_IV:
		command_1[5]=0x10;midi_out=MIDI_4;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_mid_IV:
		command_1[5] = 0x11;midi_out=MIDI_4;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_IV:
		command_1[5] = 0x11;midi_out=MIDI_4;
		break;
		default:
		break;
	}
	
	switch (midi_out)
	{
		case MIDI_1:
		sendSysEx_MIDI_out(MIDI_1, 9, command_1, false);
		break;
		
		case MIDI_2:
		sendSysEx_MIDI_out(MIDI_2, 9, command_1, false);
		break;
		
		case MIDI_3:
		sendSysEx_MIDI_out(MIDI_3, 9, command_1, false);
		break;
		
		case MIDI_4:
		sendSysEx_MIDI_out(MIDI_4, 9, command_1, false);
		break;
		
		
	}
	
	

	
	return;
	//
	//if (ADDRESS_id == ADD_menu_b1_equalizer_gain_low)
	//{
	////command_2[2] = 0x08;
	//command_2[2] = 0x0C;
	//
	//
	//}
	//else if (ADDRESS_id == ADD_menu_b1_equalizer_gain_low_mid)
	//{
	////command_2[2] = 0x09;
	//command_2[2] = 0x0D;
	//}
	//else if (ADDRESS_id == ADD_menu_b1_equalizer_gain_high_mid)
	//{
	////command_2[2] = 0x0A;
	//command_2[2] = 0x0E;
	//}
	//else if (ADDRESS_id == ADD_menu_b1_equalizer_gain_high)
	//{
	////command_2[2] = 0x0B;
	//command_2[2] = 0x0F;
	//}
	//else if (ADDRESS_id == ADD_menu_b1_equalizer_band_freq_low_band_0_800)
	//{
	////command_2[2] = 0x0C;
	//command_2[2] = 0x08;
	//}
	//else if (ADDRESS_id == ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500)
	//{
	////command_2[2] = 0x0D;
	//command_2[2] = 0x09;
	//}
	//else if (ADDRESS_id == ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700)
	//{
	////command_2[2] = 0x0E;
	//command_2[2] = 0x0A;
	//}
	//else if (ADDRESS_id == ADD_menu_b1_equalizer_band_freq_high_band_1000_5800)
	//{
	////command_2[2] = 0x0F;
	//command_2[2] = 0x0B;
	//}
	//else if (ADDRESS_id == ADD_menu_b1_equalizer_Q_low)
	//{
	//command_2[2] = 0x10;
	//}
	//else if (ADDRESS_id == ADD_menu_b1_equalizer_Q_low_mid)
	//{
	//command_2[2] = 0x10;
	//}
	//else if (ADDRESS_id == ADD_menu_b1_equalizer_Q_high_mid)
	//{
	//command_2[2] = 0x11;
	//}
	//else if (ADDRESS_id == ADD_menu_b1_equalizer_Q_high)
	//{
	//command_2[2] = 0x11;
	//}

	sendSysEx_MIDI_out(MIDI_1, 3, command_1, false);
	sendSysEx_MIDI_out(MIDI_1, 3, command_2, false);
	sendSysEx_MIDI_out(MIDI_1, 3, command_3, false);

	sendSysEx_MIDI_out(MIDI_2, 3, command_1, false);
	sendSysEx_MIDI_out(MIDI_2, 3, command_2, false);
	sendSysEx_MIDI_out(MIDI_2, 3, command_3, false);

	sendSysEx_MIDI_out(MIDI_3, 3, command_1, false);
	sendSysEx_MIDI_out(MIDI_3, 3, command_2, false);
	sendSysEx_MIDI_out(MIDI_3, 3, command_3, false);

	sendSysEx_MIDI_out(MIDI_4, 3, command_1, false);
	sendSysEx_MIDI_out(MIDI_4, 3, command_2, false);
	sendSysEx_MIDI_out(MIDI_4, 3, command_3, false);

	return;

}
#endif

void MIDI_mgr::equalizer_set_pedal(int ADDRESS_id, int value)
{
	//return;
	//DEBUG_print(F("EQU ADDRESS>"));
	//DEBUG_print(ADDRESS_id);
	//DEBUG_print(F(" VALUE> "));
	//DEBUG_println(value);
	//byte GS_command[] = { 0xF0, 0x41, 0x00, 0x42, 0x12, 0x40, 0x02,0x00, value, 0x00, 0xF7 };

	//if(value%2==1)
	//value=127;
	//else
	//value=0;
	
	
	
	//return;
	byte command_id=0;
	
	byte command_1[] = { 0xB0, 0x63, 0x37,
		0xB0, 0x62, command_id,
	0xB0, 0x06, value  };
	byte command_2[] = { 0xB0, 0x62, command_id };
	byte command_3[] = { 0xB0, 0x06, value };

	switch (ADDRESS_id)
	{
		case ADD_menu_b1_equalizer_gain_low:
		command_1[5]=0x08;
		break;
		case ADD_menu_b1_equalizer_gain_low_mid:
		command_1[5]=0x09;
		break;
		case ADD_menu_b1_equalizer_gain_high_mid:
		command_1[5]=0x0A;
		break;
		
		case  ADD_menu_b1_equalizer_gain_high:
		command_1[5]=0x0B;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_band_0_800:
		command_1[5]=0x0C;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500:
		command_1[5]=0x0D;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700:
		command_1[5]=0x0E;
		break;
		
		case ADD_menu_b1_equalizer_band_freq_high_band_1000_5800:
		command_1[5]=0x0F;
		break;
		
		case ADD_menu_b1_equalizer_Q_low:
		command_1[5]=0x10;
		break;
		
		case ADD_menu_b1_equalizer_Q_low_mid:
		command_1[5]=0x10;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high_mid:
		command_2[2] = 0x11;
		return;
		break;
		
		case ADD_menu_b1_equalizer_Q_high:
		command_2[2] = 0x11;
		break;
		
		default:
		break;
	}
	
	sendSysEx_MIDI_out(MIDI_3, 9, command_1, false);
	sendSysEx_MIDI_out(MIDI_4, 9, command_1, false);
	return;


}


void MIDI_mgr::tuning_send()
{
	
	byte style=TEMPER_SELECTED;
	
	byte key_set[12];

	if (style == 0)
	load_style_key(STYLE_neutral, key_set);
	if (style == 1)
	load_style_key(STYLE_natuerlich_harmo, key_set);
	else if (style == 2)
	load_style_key(STYLE_mitteltoenig, key_set);
	else if (style == 3)
	load_style_key(STYLE_mittel_muriorg, key_set);
	else if (style == 4)
	load_style_key(STYLE_ho_cheng_thien, key_set);
	else if (style == 5)
	load_style_key(STYLE_joung, key_set);
	else if (style == 6)
	load_style_key(STYLE_praetorious, key_set);
	else if (style == 7)
	load_style_key(STYLE_pytagoras, key_set);
	else if (style == 8)
	load_style_key(STYLE_gramathaeus_orgel, key_set);
	else if (style == 9)
	load_style_key(STYLE_ganassi, key_set);
	else if (style == 10)
	load_style_key(STYLE_schlick, key_set);
	else if (style == 11)
	load_style_key(STYLE_werckmeister_3, key_set);
	else if (style == 12)
	load_style_key(STYLE_silberman_1, key_set);
	else if (style == 13)
	load_style_key(STYLE_silberman_2, key_set);
	else if (style == 14)
	load_style_key(STYLE_bach_billeter, key_set);
	else if (style == 15)
	load_style_key(STYLE_back_woltemp, key_set);
	else if (style == 16)
	load_style_key(STYLE_billeter_orgel, key_set);
	else if (style == 17)
	load_style_key(STYLE_kimberger_1, key_set);
	else if (style == 18)
	load_style_key(STYLE_kimberger_2, key_set);
	else if (style == 19)
	load_style_key(STYLE_kimberger_3, key_set);
	else if (style == 20)
	load_style_key(STYLE_kelletal_1966, key_set);
	else if (style == 21)
	load_style_key(STYLE_kelletal_1977, key_set);
	else if (style == 22)
	load_style_key(STYLE_werckmeister_2, key_set);

	int test_var=0;
	bool stop_tune=false;
	
	for(int x=0;x<12;x++)
	{
		test_var=(int)key_set[x]+HERTZ_SELECTED*4;
		if(test_var<0)
		{
			stop_tune=true;
			break;
		}
		
		key_set[x]+=HERTZ_SELECTED*4;
	}
	if(stop_tune)
	return;
	

	
	send_style_vars(key_set);
	
	DEBUG_print("                     TUNNING:");
	
	for(int x=0;x<12;x++)
	{
		
		DEBUG_print(key_set[x]);
		DEBUG_STRING_print(" ");
	}
	DEBUG_println();
	
	
	
	MIDI_sender.mute_all_sounds();

	for (int i = 0; i < 90; i++){
		if (G_bit(k_MAN_I_L,i)==true)
		{
			//int key, bool on_off, int manual, byte velocity
			//MIDI_sender.send_note_DREAM(i,note_on_off,stop->get_active_on_manual(),note_on_off);
			MIDI_sender.sendNote_MIDI_out(1,i,127,1,true);
			MIDI_sender.sendNote_MIDI_out(2,i,127,1,true);
			//	DEBUG_println(F("KEY "));
			//	DEBUG_println(i);
		}
		if (G_bit(k_MAN_II_L,i)==true)
		{
			//int key, bool on_off, int manual, byte velocity
			//MIDI_sender.send_note_DREAM(i,note_on_off,stop->get_active_on_manual(),note_on_off);
			MIDI_sender.sendNote_MIDI_out(3,i,127,1,true);
			MIDI_sender.sendNote_MIDI_out(4,i,127,1,true);
			//	DEBUG_println(F("KEY "));
			//	DEBUG_println(i);
		}
		if (G_bit(k_PED,i)==true)
		{
			//int key, bool on_off, int manual, byte velocity
			//MIDI_sender.send_note_DREAM(i,note_on_off,stop->get_active_on_manual(),note_on_off);
			MIDI_sender.sendNote_MIDI_out(1,i,127,2,true);
			//	DEBUG_println(F("KEY "));
			//	DEBUG_println(i);
		}
	}
	for (int i = 0; i < 90; i++){
		
		S_bit(k_MAN_I_L,i,false);
		S_bit(k_MAN_II_L,i,false);
		S_bit(k_MAN_III_L,i,false);
		S_bit(k_PED,i,false);
		
	}

}

void MIDI_mgr::equalizer_startup_send()
{
	

	
	equalizer_set(ADD_menu_b1_equalizer_gain_low,EEPROM.read(ADD_menu_b1_equalizer_gain_low));
	equalizer_set(ADD_menu_b1_equalizer_gain_low_mid,EEPROM.read(ADD_menu_b1_equalizer_gain_low_mid));
	equalizer_set(ADD_menu_b1_equalizer_gain_high_mid,EEPROM.read(ADD_menu_b1_equalizer_gain_high_mid));
	equalizer_set(ADD_menu_b1_equalizer_gain_high,EEPROM.read(ADD_menu_b1_equalizer_gain_high));
	
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_low_band_0_800,HEAD_freq_low_band_0_800);
	equalizer_set(ADD_menu_b1_equalizer_band_freq_low_band_0_800,EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_band_0_800));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500,EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700,EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800,EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800));
	
	equalizer_set(ADD_menu_b1_equalizer_Q_low,EEPROM.read(ADD_menu_b1_equalizer_Q_low));
	equalizer_set(ADD_menu_b1_equalizer_Q_high,EEPROM.read(ADD_menu_b1_equalizer_Q_high));
	
	
	////////////////
	equalizer_set(ADD_menu_b1_equalizer_gain_low_II,EEPROM.read(ADD_menu_b1_equalizer_gain_low_II));
	equalizer_set(ADD_menu_b1_equalizer_gain_low_mid_II,EEPROM.read(ADD_menu_b1_equalizer_gain_low_mid_II));
	equalizer_set(ADD_menu_b1_equalizer_gain_high_mid_II,EEPROM.read(ADD_menu_b1_equalizer_gain_high_mid_II));
	equalizer_set(ADD_menu_b1_equalizer_gain_high_II,EEPROM.read(ADD_menu_b1_equalizer_gain_high_II));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_low_band_0_800_II,EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_band_0_800_II));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_II,EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_II));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_II,EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_II));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_II,EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_II));
	equalizer_set(ADD_menu_b1_equalizer_Q_low_II,EEPROM.read(ADD_menu_b1_equalizer_Q_low_II));
	equalizer_set(ADD_menu_b1_equalizer_Q_high_II,EEPROM.read(ADD_menu_b1_equalizer_Q_high_II));
	
	return;
	////////////////
	equalizer_set(ADD_menu_b1_equalizer_gain_low_III,EEPROM.read(ADD_menu_b1_equalizer_gain_low_III));
	equalizer_set(ADD_menu_b1_equalizer_gain_low_mid_III,EEPROM.read(ADD_menu_b1_equalizer_gain_low_mid_III));
	equalizer_set(ADD_menu_b1_equalizer_gain_high_mid_III,EEPROM.read(ADD_menu_b1_equalizer_gain_high_mid_III));
	equalizer_set(ADD_menu_b1_equalizer_gain_high_III,EEPROM.read(ADD_menu_b1_equalizer_gain_high_III));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_low_band_0_800_III,EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_band_0_800_III));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_III,EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_III));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III,EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_III,EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_III));
	equalizer_set(ADD_menu_b1_equalizer_Q_low_III,EEPROM.read(ADD_menu_b1_equalizer_Q_low_III));
	equalizer_set(ADD_menu_b1_equalizer_Q_high_III,EEPROM.read(ADD_menu_b1_equalizer_Q_high_III));
	
	////////////////
	equalizer_set(ADD_menu_b1_equalizer_gain_low_IV,EEPROM.read(ADD_menu_b1_equalizer_gain_low_IV));
	equalizer_set(ADD_menu_b1_equalizer_gain_low_mid_IV,EEPROM.read(ADD_menu_b1_equalizer_gain_low_mid_IV));
	equalizer_set(ADD_menu_b1_equalizer_gain_high_mid_IV,EEPROM.read(ADD_menu_b1_equalizer_gain_high_mid_IV));
	equalizer_set(ADD_menu_b1_equalizer_gain_high_IV,EEPROM.read(ADD_menu_b1_equalizer_gain_high_IV));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_low_band_0_800_IV,EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_band_0_800_IV));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_IV,EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_IV));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_IV,EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_IV));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_IV,EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_IV));
	equalizer_set(ADD_menu_b1_equalizer_Q_low_IV,EEPROM.read(ADD_menu_b1_equalizer_Q_low_IV));
	equalizer_set(ADD_menu_b1_equalizer_Q_high_IV,EEPROM.read(ADD_menu_b1_equalizer_Q_high_IV));
	
}




void MIDI_mgr::equalizer_headphones_send()
{
	//return;
	//equalizer_set(ADD_menu_b1_equalizer_gain_low,EEPROM.read(HEAD_gain_low);
	//equalizer_set(ADD_menu_b1_equalizer_gain_low_mid,EEPROM.read(HEAD_gain_low_mid);
	//equalizer_set(ADD_menu_b1_equalizer_gain_high_mid,HEAD_gain_high_mid);
	//equalizer_set(ADD_menu_b1_equalizer_gain_high,HEAD_gain_high);
	//
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_low_band_0_800,HEAD_freq_low_band_0_800);
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500,HEAD_freq_low_mid_band_0_2500);
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700,HEAD_freq_high_mid__band_60_10700);
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800,HEAD_freq_high_band_1000_5800);
	//
	//equalizer_set(ADD_menu_b1_equalizer_Q_low,HEAD_Q_low);
	//equalizer_set(ADD_menu_b1_equalizer_Q_high,HEAD_Q_high);
	//
	///////////
	//equalizer_set(ADD_menu_b1_equalizer_gain_low_II,HEAD_gain_low);
	//equalizer_set(ADD_menu_b1_equalizer_gain_low_mid_II,HEAD_gain_low_mid);
	//equalizer_set(ADD_menu_b1_equalizer_gain_high_mid_II,HEAD_gain_high_mid);
	//equalizer_set(ADD_menu_b1_equalizer_gain_high_II,HEAD_gain_high);
	//
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_low_band_0_800_II,HEAD_freq_low_band_0_800);
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_II,HEAD_freq_low_mid_band_0_2500);
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_II,HEAD_freq_high_mid__band_60_10700);
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_II,HEAD_freq_high_band_1000_5800);
	//
	//equalizer_set(ADD_menu_b1_equalizer_Q_low_II,HEAD_Q_low);
	//equalizer_set(ADD_menu_b1_equalizer_Q_high_II,HEAD_Q_high);
	//
	//////////////////
	//equalizer_set(ADD_menu_b1_equalizer_gain_low_III,HEAD_gain_low_II);
	//equalizer_set(ADD_menu_b1_equalizer_gain_low_mid_III,HEAD_gain_low_mid_II);
	//equalizer_set(ADD_menu_b1_equalizer_gain_high_mid_III,HEAD_gain_high_mid_II);
	//equalizer_set(ADD_menu_b1_equalizer_gain_high_III,HEAD_gain_high_II);
	//
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_low_band_0_800_III,HEAD_freq_low_band_0_800_II);
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_III,HEAD_freq_low_mid_band_0_2500_II);
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III,HEAD_freq_high_mid__band_60_10700_II);
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_III,HEAD_freq_high_band_1000_5800_II);
	//
	//equalizer_set(ADD_menu_b1_equalizer_Q_low_III,HEAD_Q_low_II);
	//equalizer_set(ADD_menu_b1_equalizer_Q_high_III,HEAD_Q_high_II);
	//
	//////////////////
	//equalizer_set(ADD_menu_b1_equalizer_gain_low_IV,HEAD_gain_low_II);
	//equalizer_set(ADD_menu_b1_equalizer_gain_low_mid_IV,HEAD_gain_low_mid_II);
	//equalizer_set(ADD_menu_b1_equalizer_gain_high_mid_IV,HEAD_gain_high_mid_II);
	//equalizer_set(ADD_menu_b1_equalizer_gain_high_IV,HEAD_gain_high_II);
	//
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_low_band_0_800_IV,HEAD_freq_low_band_0_800_II);
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_IV,HEAD_freq_low_mid_band_0_2500_II);
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_IV,HEAD_freq_high_mid__band_60_10700_II);
	//equalizer_set(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_IV,HEAD_freq_high_band_1000_5800_II);
	//
	//equalizer_set(ADD_menu_b1_equalizer_Q_low_IV,HEAD_Q_low_II);
	//equalizer_set(ADD_menu_b1_equalizer_Q_high_IV,HEAD_Q_high_II);
	//return;

	//byte a=EEPROM.read(ADD_menu_b1_equalizer_gain_low);DEBUG_println(a);119
	//a=EEPROM.read(ADD_menu_b1_equalizer_gain_low_mid);DEBUG_println(a);60
	//a=EEPROM.read(ADD_menu_b1_equalizer_gain_high_mid);DEBUG_println(a);48
	//a=EEPROM.read(ADD_menu_b1_equalizer_gain_high);DEBUG_println(a);35
	//a=EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_band_0_800);DEBUG_println(a);8
	//a=EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500);DEBUG_println(a);24
	//a=EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700);DEBUG_println(a);8
	//a=EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800);DEBUG_println(a);127
	//a=EEPROM.read(ADD_menu_b1_equalizer_Q_low);DEBUG_println(a);21
	//a=EEPROM.read(ADD_menu_b1_equalizer_Q_high);DEBUG_println(a);64
	
	

	
	////////////////

	equalizer_set(ADD_menu_b1_equalizer_gain_low_III,EEPROM.read(ADD_menu_b1_equalizer_gain_low_III));
	equalizer_set(ADD_menu_b1_equalizer_gain_low_mid_III,EEPROM.read(ADD_menu_b1_equalizer_gain_low_mid_III));
	equalizer_set(ADD_menu_b1_equalizer_gain_high_mid_III,EEPROM.read(ADD_menu_b1_equalizer_gain_high_mid_III));
	equalizer_set(ADD_menu_b1_equalizer_gain_high_III,EEPROM.read(ADD_menu_b1_equalizer_gain_high_III));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_low_band_0_800_III,EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_band_0_800_III));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_III,EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_III));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III,EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_III,EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_III));
	equalizer_set(ADD_menu_b1_equalizer_Q_low_III,EEPROM.read(ADD_menu_b1_equalizer_Q_low_III));
	equalizer_set(ADD_menu_b1_equalizer_Q_high_III,EEPROM.read(ADD_menu_b1_equalizer_Q_high_III));
	
	////////////////
	equalizer_set(ADD_menu_b1_equalizer_gain_low_IV,EEPROM.read(ADD_menu_b1_equalizer_gain_low_IV));
	equalizer_set(ADD_menu_b1_equalizer_gain_low_mid_IV,EEPROM.read(ADD_menu_b1_equalizer_gain_low_mid_IV));
	equalizer_set(ADD_menu_b1_equalizer_gain_high_mid_IV,EEPROM.read(ADD_menu_b1_equalizer_gain_high_mid_IV));
	equalizer_set(ADD_menu_b1_equalizer_gain_high_IV,EEPROM.read(ADD_menu_b1_equalizer_gain_high_IV));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_low_band_0_800_IV,EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_band_0_800_IV));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_IV,EEPROM.read(ADD_menu_b1_equalizer_band_freq_low_mid_band_0_2500_IV));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_IV,EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_IV));
	equalizer_set(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_IV,EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_band_1000_5800_IV));
	equalizer_set(ADD_menu_b1_equalizer_Q_low_IV,EEPROM.read(ADD_menu_b1_equalizer_Q_low_IV));
	equalizer_set(ADD_menu_b1_equalizer_Q_high_IV,EEPROM.read(ADD_menu_b1_equalizer_Q_high_IV));

}

bool MIDI_mgr::send_stop_notes_volume(byte stop_id,byte ID_modul)
{
	if(STOP_mgr.id(stop_id)->get_ID()==NULL_address||STOP_mgr.id(stop_id)->get_ID()==EMPTY)
	return false;
	
	byte notes[126];
	for(byte x=0;x<126;x++)
	{
		notes[x]=127;
	}
	//notes[0]=0xF0;
	notes[0]=0;
	notes[1]=ID_modul;
	notes[2]=0;
	notes[3]=0x5A;
	notes[4]=stop_id+1;
	//notes[127]=0xF7;
	//calculate_free_RAM(12);
	for(byte x=0;x<84;x++)
	{
		//exEEPROM.write((stop_id*200)+x,(byte)0x64);
		//exEEPROM.write(stop_selected*200+MIDI_sender.PREV_tone,ms.get_selected1()->getValue());
		notes[x+5+23]=exEEPROM.read((stop_id*200)+x);
		if(notes[x+5+23]>127)
		notes[x+5+23]=127;
		//notes[x+5+23]=0x64;
	}
	byte midi_out=STOP_mgr.id(stop_id)->get_MIDI_out_numb();
	
	sendSysEx_MIDI_out(midi_out, 126, notes, false);
	DEBUG_STRING_print("STARTUP NOTES VOL:: ");
	DEBUG_println(get_stop_name(stop_id));
	
	return true;
}

void MIDI_mgr::startup_pan_send()
{
	
}

void MIDI_mgr::load_style_key(const int* location, byte* key_set)
{
	for (int x = 0; x < 12; x++)
	{
		key_set[x] = pgm_read_word_near(location + x) + 64;
	}
}
void MIDI_mgr::change_style(byte style)
{
	if (style>22)
	return;

	byte key_set[12];

	if (style == 0)
	load_style_key(STYLE_neutral, key_set);
	if (style == 1)
	load_style_key(STYLE_natuerlich_harmo, key_set);
	else if (style == 2)
	load_style_key(STYLE_mitteltoenig, key_set);
	else if (style == 3)
	load_style_key(STYLE_mittel_muriorg, key_set);
	else if (style == 4)
	load_style_key(STYLE_ho_cheng_thien, key_set);
	else if (style == 5)
	load_style_key(STYLE_joung, key_set);
	else if (style == 6)
	load_style_key(STYLE_praetorious, key_set);
	else if (style == 7)
	load_style_key(STYLE_pytagoras, key_set);
	else if (style == 8)
	load_style_key(STYLE_gramathaeus_orgel, key_set);
	else if (style == 9)
	load_style_key(STYLE_ganassi, key_set);
	else if (style == 10)
	load_style_key(STYLE_schlick, key_set);
	else if (style == 11)
	load_style_key(STYLE_werckmeister_3, key_set);
	else if (style == 12)
	load_style_key(STYLE_silberman_1, key_set);
	else if (style == 13)
	load_style_key(STYLE_silberman_2, key_set);
	else if (style == 14)
	load_style_key(STYLE_bach_billeter, key_set);
	else if (style == 15)
	load_style_key(STYLE_back_woltemp, key_set);
	else if (style == 16)
	load_style_key(STYLE_billeter_orgel, key_set);
	else if (style == 17)
	load_style_key(STYLE_kimberger_1, key_set);
	else if (style == 18)
	load_style_key(STYLE_kimberger_2, key_set);
	else if (style == 19)
	load_style_key(STYLE_kimberger_3, key_set);
	else if (style == 20)
	load_style_key(STYLE_kelletal_1966, key_set);
	else if (style == 21)
	load_style_key(STYLE_kelletal_1977, key_set);
	else if (style == 22)
	load_style_key(STYLE_werckmeister_2, key_set);

	
	send_style_vars(key_set);
	//F0h 41h 00h 42h 12h 40h 1ph 40h t1....t12 xx f7h
	//byte midi_var[] = { 0xF0, 0x41, 0x00, 0x42, 0x12, 0x40, 0x1, 0x40, 0x0, 0x0, 0xf7 };
	
	//MIDI_1_switch = 4;
}
void MIDI_mgr::send_style_vars(byte* key_set)
{
	byte midi_var[] = {
	0xF0, 0x41, 0x00, 0x42, 0x12, 0x40, 0x10, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xF7 };


	//  F0h 41h 00h 42h 12h 40h  10h 40h 100h 90h 80h 70h 60h 50h 40h 30h 20h 10h 20h 30h 00h f7h

	//byte midi_var[] = { 0, 0x65, 0x00, 0x64, 0x01, 0x06, 0 };



	midi_var[6] = 0x10;
	
	for(int x=1;x<4;x++)
	{
		for (int part = 0; part < 15; part++)
		{
			

			midi_var[6] = 0x10 + part;
			midi_var[8] = key_set[0];
			midi_var[9] = key_set[1];
			midi_var[10] = key_set[2];
			midi_var[11] = key_set[3];
			midi_var[12] = key_set[4];
			midi_var[13] = key_set[5];
			midi_var[14] = key_set[6];
			midi_var[15] = key_set[7];
			midi_var[16] = key_set[8];
			midi_var[17] = key_set[9];
			midi_var[18] = key_set[10];
			midi_var[19] = key_set[11];

			sendSysEx_MIDI_out(x, 22, midi_var, true);
			//MIDI.sendSysEx(22, midi_var, true);


			/*midi_var[6] = part;
			midi_var[8] = t;
			midi_var[9] = key_set[t];

			MIDI.sendSysEx(11, midi_var, true);*/
			//MIDI2.sendSysEx(11, midi_var, true);
			/*for (int y = 0; y < 22; y++)
			{
			Serial.print(midi_var[y],HEX);
			Serial.print(" ");
			}
			Serial.println(" ");*/
			
		}
	}
}


byte note_var[2];
byte note_on_count;
byte count_for_pause;


//#define INCLUDE_KEY_INFO


//void MIDI_mgr::send_note_DREAM(int key, bool on_off, int manual, byte velocity)
//{
//if(velocity>127)
//velocity=80;
//
//key += value_TRANSPOSE-12;
////send_midi_key_grand_orgue(key, stop, on_off, manual, force_skip_check);
//
//#ifdef INCLUDE_KEY_INFO
//DEBUG_print(F("KEY "));
//DEBUG_print(key);
//DEBUG_print(F(" VELO: "));
//DEBUG_print(velocity);
//DEBUG_print(F(" MANUAL: "));
//DEBUG_print(manual);
//DEBUG_print(F(" TRANSPOSE: "));
//DEBUG_println(value_TRANSPOSE-12);
//#endif
//
//
//byte mapped_vol=velocity;
//
//
//if(manual==MANUAL_1)
//{
//if (on_off)
//{
//MIDI.sendNoteOn(key + 23,mapped_vol , 1);
//MIDI2.sendNoteOn(key + 23,mapped_vol , 1);
//}
//else
//{
//MIDI.sendNoteOff(key + 23, 0, 1);
//MIDI2.sendNoteOff(key + 23, 0, 1);
//}
//
//}
//else if(manual==MANUAL_2)
//{
//if (on_off)
//{
//MIDI3.sendNoteOn(key + 23, mapped_vol, 1);
//
//}
//else
//{
//MIDI3.sendNoteOff(key + 23, 0, 1);
//
//}
//
//
//}
//else if(manual==MANUAL_3)
//{
//if (on_off)
//{
//DEBUG_println(F("ni ga"));
////MIDI4.sendNoteOn(key + 23, map(127, 0, 127, 0, MASTER_VOLUME), 1);
//
//}
//else
//{
////MIDI4.sendNoteOff(key + 23, 0, 1);
//
//}
//}else if(manual==PEDAL)
//{
//if (on_off)
//{
////sendSysEx_MIDI_out(1,2,preklop_MIDI2,false)
////MIDI1.sendNoteOn(key + 23, mapped_vol, 1);
//MIDI4.sendNoteOn(key + 23, mapped_vol, 1);
//
//}
//else
//{
////MIDI1.sendNoteOff(key + 23, 0, 1);
//MIDI4.sendNoteOff(key + 23, 0, 1);
//
//}
//}
//
//}

#ifdef NEW_DISPOSITION

void MIDI_mgr::send_note_on_output(byte MIDI_out,byte note,bool on_off,byte velocity,byte channel)
{
	MIDI_preklop(MIDI_out);
	
	if(on_off)
	MIDI.sendNoteOn(note ,velocity , channel);
	else
	MIDI.sendNoteOff(note ,0 , channel);
}

void MIDI_mgr::send_note_DREAM(int key, bool on_off, int manual, byte velocity)
{
	if(on_off==true)
	LAST_sended_tone=key;
	last_time_interacted=millis();
	//DEBUG_println(key);
	
	if(velocity>127)
	velocity=80;
	
	byte mapped_vol=velocity;
	
	byte midi_event[3];
	midi_event[1]=key+23;
	midi_event[2]=mapped_vol;
	if(on_off)
	midi_event[0]=144;
	else
	midi_event[0]=128;
	
	switch (25)
	{
		case PEDAL:
		SD_work.rec_midi_event(midi_event,1,3);
		break;
		
		case MANUAL_1:
		midi_event[0]+=1;
		SD_work.rec_midi_event(midi_event,1,3);
		break;
		
		case MANUAL_2:
		midi_event[0]+=2;
		SD_work.rec_midi_event(midi_event,1,3);
		break;
		
		case MANUAL_3:
		midi_event[0]+=3;
		SD_work.rec_midi_event(midi_event,1,3);
		break;
		
		case MANUAL_4:
		midi_event[0]+=4;
		SD_work.rec_midi_event(midi_event,1,3);
		break;
		
		case MANUAL_5:
		midi_event[0]+=5;
		SD_work.rec_midi_event(midi_event,1,3);
		break;
	}
	
	
	key += value_TRANSPOSE-TRANS_adjust;
	//send_midi_key_grand_orgue(key, stop, on_off, manual, force_skip_check);

	#ifdef INCLUDE_KEY_INFO
	DEBUG_print(F("KEY "));
	DEBUG_print(key);
	//DEBUG_print(F(" VEL: "));
	//DEBUG_print(velocity);
	DEBUG_print(F(" MAN: "));
	DEBUG_println(manual);
	//DEBUG_print(F(" TRANSPOSE: "));
	//DEBUG_println(value_TRANSPOSE);
	#endif
	//calculate_free_RAM(10);

	
	
	
	

	

	if(manual==MANUAL_1)
	{
		#ifdef ONE_WIRE_MIDI
		send_note_on_output(MIDI_1,key + 23,on_off,mapped_vol,COMMON_MIDI_CH1);
		send_note_on_output(MIDI_2,key + 23,on_off,mapped_vol,COMMON_MIDI_CH1);
		
		#else
		
		if (on_off)
		{
			midi_event[0]=144;
			MIDI.sendNoteOn(key + 23,mapped_vol , COMMON_MIDI_CH1);
			MIDI2.sendNoteOn(key + 23,mapped_vol , COMMON_MIDI_CH2);
		}
		else
		{
			midi_event[0]=128;
			MIDI.sendNoteOff(key + 23, 0, COMMON_MIDI_CH1);
			MIDI2.sendNoteOff(key + 23, 0, COMMON_MIDI_CH2);
		}
		
		#endif
	}
	else if(manual==MANUAL_2)
	{
		//midi_event[0]=144;
		//SD_work.rec_midi_event(midi_event,3,3);
		//SD_work.rec_midi_event(midi_event,4,3);
		#ifdef ONE_WIRE_MIDI
		send_note_on_output(MIDI_3,key + 23,on_off,mapped_vol,COMMON_MIDI_CH1);
		send_note_on_output(MIDI_4,key + 23,on_off,mapped_vol,COMMON_MIDI_CH1);
		
		#else
		
		if (on_off)
		{
			MIDI3.sendNoteOn(key + 23, mapped_vol, COMMON_MIDI_CH2);
			MIDI4.sendNoteOn(key + 23, mapped_vol, COMMON_MIDI_CH2);
			
		}
		else
		{
			MIDI3.sendNoteOff(key + 23, 0, COMMON_MIDI_CH2);
			MIDI4.sendNoteOff(key + 23, 0, COMMON_MIDI_CH2);
			
		}
		#endif

	}
	else if(manual==MANUAL_3)
	{
		if (on_off)
		{
			DEBUG_println(F("ni ga"));
			//MIDI4.sendNoteOn(key + 23, map(127, 0, 127, 0, MASTER_VOLUME), 1);
			
		}
		else
		{
			
			//MIDI4.sendNoteOff(key + 23, 0, 1);
			
		}

	}else if(manual==PEDAL)
	{
		//midi_event[0]=127+2;
		//SD_work.rec_midi_event(midi_event,1,3);
		#ifdef ONE_WIRE_MIDI
		send_note_on_output(MIDI_1,key + 23,on_off,mapped_vol,COMMON_MIDI_CH2);
		
		#else
		
		if (on_off)
		{
			//midi_event[0]=145;
			//sendSysEx_MIDI_out(1,2,preklop_MIDI2,false)
			//MIDI1.sendNoteOn(key + 23, mapped_vol, 1);
			MIDI.sendNoteOn(key + 23, mapped_vol, COMMON_MIDI_CH2);
			
		}
		else
		{
			//midi_event[0]=128;
			//MIDI1.sendNoteOff(key + 23, 0, 1);
			MIDI.sendNoteOff(key + 23, 0, COMMON_MIDI_CH2);
			
		}
		//SD_work.rec_midi_event(midi_event,1,3);
		#endif
	}

}

#endif

#ifdef TESTED_DISPOSITION


void MIDI_mgr::send_note_DREAM(int key, bool on_off, int manual, byte velocity)
{
	if(velocity>127)
	velocity=80;
	
	key += value_TRANSPOSE-TRANS_adjust-13;
	//send_midi_key_grand_orgue(key, stop, on_off, manual, force_skip_check);
	
	#ifdef INCLUDE_KEY_INFO
	DEBUG_print(F("KEY "));
	DEBUG_print(key);
	DEBUG_print(F(" VELO: "));
	DEBUG_print(velocity);
	DEBUG_print(F(" MANUAL: "));
	DEBUG_print(manual);
	DEBUG_print(F(" TRANSPOSE: "));
	DEBUG_println(value_TRANSPOSE-TRANS_adjust);
	#endif
	
	
	byte mapped_vol=velocity;


	if(manual==MANUAL_1)
	{
		if (on_off)
		{
			MIDI.sendNoteOn(key + 23,mapped_vol , 1);
			MIDI2.sendNoteOn(key + 23,mapped_vol , 1);
		}
		else
		{
			MIDI.sendNoteOff(key + 23, 0, 1);
			MIDI2.sendNoteOff(key + 23, 0, 1);
		}
		
	}
	else if(manual==MANUAL_2)
	{
		if (on_off)
		{
			MIDI3.sendNoteOn(key + 23, mapped_vol, 1);
			
		}
		else
		{
			MIDI3.sendNoteOff(key + 23, 0, 1);
			
		}
		

	}
	else if(manual==MANUAL_3)
	{
		if (on_off)
		{
			DEBUG_println(F("ni ga"));
			//MIDI4.sendNoteOn(key + 23, map(127, 0, 127, 0, MASTER_VOLUME), 1);
			
		}
		else
		{
			//MIDI4.sendNoteOff(key + 23, 0, 1);
			
		}
	}else if(manual==PEDAL)
	{
		if (on_off)
		{
			//sendSysEx_MIDI_out(1,2,preklop_MIDI2,false)
			//MIDI1.sendNoteOn(key + 23, mapped_vol, 1);
			MIDI4.sendNoteOn(key + 23, mapped_vol, 1);
			
		}
		else
		{
			//MIDI1.sendNoteOff(key + 23, 0, 1);
			MIDI4.sendNoteOff(key + 23, 0, 1);
			
		}
	}

}

#endif

float _start_time = 0;


void MIDI_mgr::send_MIDI_function(int key, bool on_off, int manual, int MIDI_code)//pazi dvojna zanka !
{


	if (MIDI_code == MIDI_MODULATION_MAN_II)
	{
		
		//nova verzija, test
		
		if(on_off)
		{
			
			byte cmdtmp[] =  {0xB0, 0x4C, EEPROM.read(add_VALUE_tremulnat1)};
			sendSysEx_MIDI_out(MIDI_3, 3,cmdtmp, false);
			sendSysEx_MIDI_out(MIDI_4, 3,cmdtmp, false);
			
			byte cmdtmp2[] =  {0xB0, 0x4D,EEPROM.read(add_VALUE_tremulnat1_depth)};
			sendSysEx_MIDI_out(MIDI_3, 3,cmdtmp2, false);
			sendSysEx_MIDI_out(MIDI_4, 3,cmdtmp2, false);
			
			byte cmdtmp3[] =  {0xB0, 0x4E,60};
			sendSysEx_MIDI_out(MIDI_3, 3,cmdtmp3, false);
			sendSysEx_MIDI_out(MIDI_4, 3,cmdtmp3, false);
			
			return;
			
			sendControlChange_MIDI_out(3, 1, key, 1);
			sendControlChange_MIDI_out(4, 1, key, 1);
			return;
			
			for(int x=0;x<16;x++)
			{
				byte command_1[] = { 0xB+x, 0x63, 0x01,0x62,0x08,0x06,key };
				byte command_2[] = { 0xB+x, 0x63, 0x01,0x62,0x09,0x06,EEPROM.read(add_VALUE_tremulnat1_depth) };//debth
				//byte command_3[] = { 0xB0, 0x63, 0x01,0x62,0x0A,0x06,TREMULANT_I };
				
				sendSysEx_MIDI_out(MIDI_3, 7, command_1, false);
				sendSysEx_MIDI_out(MIDI_3, 7, command_2, false);
				//	sendSysEx_MIDI_out(MIDI_3, 7, command_3, false);
			}
			
			return;
		}
		else
		{
			
			byte cmdtmp[] =  {0xB0, 0x4C,40};
			byte cmdtmp2[] =  {0xB0, 0x4D,40};
			sendSysEx_MIDI_out(MIDI_3, 3,cmdtmp, false);
			sendSysEx_MIDI_out(MIDI_4, 3,cmdtmp, false);
			sendSysEx_MIDI_out(MIDI_3, 3,cmdtmp2, false);
			sendSysEx_MIDI_out(MIDI_4, 3,cmdtmp2, false);
			return;
			
			sendControlChange_MIDI_out(3, 1, 0, 1);
			sendControlChange_MIDI_out(4, 1, 0, 1);
		}
		
		
		
	}
	if (MIDI_code == MIDI_MODULATION_MAN_II_depth)
	{
		//byte command_1[] = { 0xB0, 0x63, 0x01,0x62,0x08,0x06,key };
		//byte command_2[] = { 0xB0, 0x63, 0x01,0x62,0x09,0x06,key };//debth
		//byte command_3[] = { 0xB0, 0x63, 0x01,0x62,0x0A,0x06,TREMULANT_I };
		
		//byte command_1[] = { 0x41, 0x00, 0x42,0x12,0x40,0x2,0x03,key,0 };//debth tole dela
		byte command_1[] = { 0x41, 0x00, 0x42,0x12,0x40,0x2,0x02,key,0 };//debth tole dela
		//sendSysEx_MIDI_out(MIDI_3, 7, command_1, false);
		sendSysEx_MIDI_out(MIDI_3, 9, command_1, false);
		//	sendSysEx_MIDI_out(MIDI_3, 7, command_3, false);
		
		//sendControlChange_MIDI_out(3, 1, key, 1);
		
	}
	if (MIDI_code == MIDI_VOLUME)
	{
		sendControlChange_MIDI_out(1, 11, key, 1);
		//sendControlChange(out_id, 11, GAS_PED_1, stop->get_MIDI_CH());
	}
	if (MIDI_code == MIDI_VOLUME_man2)
	{
		sendControlChange_MIDI_out(1, 11, GAS_PED_1, 1);
		//sendControlChange(out_id, 11, GAS_PED_2, stop->get_MIDI_CH());
	}

}



void MIDI_mgr::send_MIDI_code(int MIDI_code, int value,int parameter_extra,int parameter_extra_2)
{
	
	
	if(MIDI_code==CODE_PAN)
	{
		//if(value%2==1)
		//value=127;
		//else
		//value=0;
		
		byte midi_ch=parameter_extra;
		byte midi_out=parameter_extra_2;
		
		//byte midi_ch=	STOP_mgr.id(menu_b1_PAN_stop_select->getValue())->get_MIDI_CH();
		//byte midi_out=	STOP_mgr.id(menu_b1_PAN_stop_select->getValue())->get_MIDI_out_numb();
		//
		byte GS_command[] = { 0xB0+midi_ch-1, 0x0A, value };
		
		sendSysEx_MIDI_out(midi_out, 3, GS_command, true);
		//sendSysEx_MIDI_out(MIDI_2, 3, GS_command, true);
		//sendSysEx_MIDI_out(MIDI_3, 3, GS_command, true);
		//sendSysEx_MIDI_out(MIDI_4, 3, GS_command, true);

	}
	else if(MIDI_code==CODE_STOP_VOL)
	{
		//DEBUG_print(F("VALUE:"));
		//DEBUG_print(value);
		//DEBUG_print(F(" MIDI CH:"));
		//DEBUG_print(parameter_extra);
		//DEBUG_print(F("  OUT:"));
		//DEBUG_println(parameter_extra_2);
		
		byte midi_ch=parameter_extra;
		byte midi_out=parameter_extra_2;
		byte GS_command[] = { 0xB0+midi_ch-1, 0x07, value };
		
		sendSysEx_MIDI_out(midi_out, 3, GS_command, true);
		//byte midi_ch=parameter_extra-1;
		//byte midi_out=parameter_extra_2;
		//sendControlChange_MIDI_out(midi_out, 7, value, midi_ch);
	}
	else if(MIDI_code==CODE_TVF_RESONANCE)
	{
		return;
		
		byte midi_ch=parameter_extra;
		byte midi_out=parameter_extra_2;
		byte GS_command[] = { 0xB0+midi_ch-1, 0x4A , value };
		
		
		sendSysEx_MIDI_out(midi_out, 3, GS_command, true);
		
		GS_command[2]=value+20;
		//delay(50);
		sendSysEx_MIDI_out(midi_out, 3, GS_command, true);
		//sendSysEx_MIDI_out(midi_out, 3, GS_command, true);
		//sendSysEx_MIDI_out(MIDI_1, 3, GS_command, true);
		//sendSysEx_MIDI_out(MIDI_2, 3, GS_command, true);
		//sendSysEx_MIDI_out(MIDI_3, 3, GS_command, true);
		//sendSysEx_MIDI_out(MIDI_4, 3, GS_command, true);
		return;
	}
	else if(MIDI_code==CODE_TVF_CUTOFF)
	{
		//return;
		byte midi_ch=parameter_extra;
		byte midi_out=parameter_extra_2;
		byte GS_command[] = { 0xB0+midi_ch-1, 0x47, value };
		
		sendSysEx_MIDI_out(midi_out, 3, GS_command, true);
		//sendSysEx_MIDI_out(midi_out, 3, GS_command, true);
		//sendSysEx_MIDI_out(MIDI_1, 3, GS_command, true);
		//sendSysEx_MIDI_out(MIDI_2, 3, GS_command, true);
		//sendSysEx_MIDI_out(MIDI_3, 3, GS_command, true);
		//sendSysEx_MIDI_out(MIDI_4, 3, GS_command, true);
		return;
	}
}

void MIDI_mgr::send_MIDI_test(int MIDI_code, int value,int manual)
{
	byte  command[] = {0xF0, 0xB0, 0x63, 0x01,0x62,0x08,0x06,value,0xF7};
	
	if(MIDI_code==TEST_A)
	{
		byte cmdtmp[] =  {0xB0, 0x4C, value};
		sendSysEx_MIDI_out(MIDI_3, 3,cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_4, 3,cmdtmp, false);
		
		byte cmdtmp2[] =  {0xB0, 0x4D,EEPROM.read(add_VALUE_tremulnat1_depth)};
		sendSysEx_MIDI_out(MIDI_3, 3,cmdtmp2, false);
		sendSysEx_MIDI_out(MIDI_4, 3,cmdtmp2, false);
		return;
	}
	if(MIDI_code==TEST_B)
	{
		byte cmdtmp[] =  {0xB0, 0x4C,EEPROM.read(add_VALUE_tremulnat1)};
		sendSysEx_MIDI_out(MIDI_3, 3,cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_4, 3,cmdtmp, false);
		
		byte cmdtmp2[] =  {0xB0, 0x4D,value};
		sendSysEx_MIDI_out(MIDI_3, 3,cmdtmp2, false);
		sendSysEx_MIDI_out(MIDI_4, 3,cmdtmp2, false);
		return;
	}
	
	if(MIDI_code==TEST_A)
	{
		byte GS_command[] = { 0xF0, 0x41, 0x00, 0x42, 0x12, 0x40, 0x02,0x00, value, 0x00, 0xF7 };
		
		
		sendSysEx_MIDI_out(MIDI_1, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 11, GS_command, true);
		GS_command[7]=0x1;
		sendSysEx_MIDI_out(MIDI_1, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 11, GS_command, true);
		GS_command[7]=0x2;
		sendSysEx_MIDI_out(MIDI_1, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 11, GS_command, true);
		GS_command[7]=0x3;
		sendSysEx_MIDI_out(MIDI_1, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 11, GS_command, true);
		return;
		
		byte cmdtmp[] =  {0xB0, 0x4C,value};
		
		sendSysEx_MIDI_out(MIDI_1, 3, cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_2, 3, cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_3, 3, cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_4, 3, cmdtmp, false);
		return;
		//byte cmdtmp[] =  {0xF0, 0xB0, 0x63, 0x01,0x62,0x08,0x06,value,0xF7};
		//memcpy(command, cmdtmp, 9);
	}
	

	
	if(MIDI_code==TEST_B)
	{
		
		
		
		byte cmdtmp[] =  {0xB0, 0x4C, EEPROM.read(add_VALUE_tremulnat1)};
		sendSysEx_MIDI_out(MIDI_3, 3,cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_4, 3,cmdtmp, false);
		
		byte cmdtmp2[] =  {0xB0, 0x4D,EEPROM.read(add_VALUE_tremulnat1_depth)};
		sendSysEx_MIDI_out(MIDI_3, 3,cmdtmp2, false);
		sendSysEx_MIDI_out(MIDI_4, 3,cmdtmp2, false);
		byte GS_command[] = { 0xF0, 0x41, 0x00, 0x42, 0x12, 0x40, 0x02,0x01, value, 0x00, 0xF7 };
		
		
		sendSysEx_MIDI_out(MIDI_1, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 11, GS_command, true);
		GS_command[7]=0x1;
		sendSysEx_MIDI_out(MIDI_1, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 11, GS_command, true);
		GS_command[7]=0x2;
		sendSysEx_MIDI_out(MIDI_1, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 11, GS_command, true);
		GS_command[7]=0x3;
		sendSysEx_MIDI_out(MIDI_1, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 11, GS_command, true);
		return;
		//byte cmdtmp[] =  {0xB0, 0x4D,value};
		//
		//sendSysEx_MIDI_out(MIDI_1, 3, cmdtmp, false);
		//sendSysEx_MIDI_out(MIDI_2, 3, cmdtmp, false);
		//sendSysEx_MIDI_out(MIDI_3, 3, cmdtmp, false);
		//sendSysEx_MIDI_out(MIDI_4, 3, cmdtmp, false);
		//return;
		//byte cmdtmp[] =  {0xF0, 0xB0, 0x63, 0x01,0x62,0x09,0x06,value,0xF7};
		//memcpy(command, cmdtmp, 9);
	}
	if(MIDI_code==TEST_C)
	{
		//if(value%2==1)
		//value=127;
		//else
		//value=0;
		//
		
		
		
		//byte midi_ch=	STOP_mgr.id(menu_b1_PAN_stop_select->getValue())->get_MIDI_CH();
		//byte midi_out=	STOP_mgr.id(menu_b1_PAN_stop_select->getValue())->get_MIDI_out_numb();
		//
		byte GS_command[] = { 0xB0, 0x4A, value };
		
		//sendSysEx_MIDI_out(midi_out, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_1, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 3, GS_command, true);
		return;
		return;
		GS_command[7]=0x1;
		sendSysEx_MIDI_out(MIDI_1, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 3, GS_command, true);
		GS_command[7]=0x2;
		sendSysEx_MIDI_out(MIDI_1, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 3, GS_command, true);
		GS_command[7]=0x3;
		sendSysEx_MIDI_out(MIDI_1, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 3, GS_command, true);
		return;
		byte cmdtmp[] =  {0xB0, 0x4E,value};
		
		sendSysEx_MIDI_out(MIDI_1, 3, cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_2, 3, cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_3, 3, cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_4, 3, cmdtmp, false);
		return;
		//byte cmdtmp[] =  {0xF0, 0xB0, 0x63, 0x01,0x62,0x0A,0x06,value,0xF7};
		//memcpy(command, cmdtmp, 9);
	}
	if(MIDI_code==TEST_D)
	{
		//if(value%2==1)
		//value=127;
		//else
		//value=0;
		
		
		
		//byte midi_ch=	STOP_mgr.id(menu_b1_PAN_stop_select->getValue())->get_MIDI_CH();
		//byte midi_out=	STOP_mgr.id(menu_b1_PAN_stop_select->getValue())->get_MIDI_out_numb();
		//
		byte GS_command[] = { 0xB0, 0x47, value };
		
		//sendSysEx_MIDI_out(midi_out, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_1, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 3, GS_command, true);
		return;
		
		
		
		//byte GS_command[] =  {0xF0, 0xB0, 0x63, 0x01,0x62,0x20,0x06,value,0xF7};
		
		
		sendSysEx_MIDI_out(MIDI_1, 9, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 9, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 9, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 9, GS_command, true);
		return;
		
		
		sendSysEx_MIDI_out(MIDI_1, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 11, GS_command, true);
		GS_command[7]=0x1;
		sendSysEx_MIDI_out(MIDI_1, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 11, GS_command, true);
		GS_command[7]=0x2;
		sendSysEx_MIDI_out(MIDI_1, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 11, GS_command, true);
		GS_command[7]=0x3;
		sendSysEx_MIDI_out(MIDI_1, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 11, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 11, GS_command, true);
		return;
		byte cmdtmp[] =  {0xB0, 0x5B,value};
		
		sendSysEx_MIDI_out(MIDI_1, 3, cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_2, 3, cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_3, 3, cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_4, 3, cmdtmp, false);
		return;
	}
	
	if(MIDI_code==TEST_C)
	{
		if(value%2==1)
		value=127;
		else
		value=0;
		
		byte GS_command[] = { 0xB0, 0x0A, value };
		
		
		sendSysEx_MIDI_out(MIDI_1, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 3, GS_command, true);
		GS_command[7]=0x1;
		sendSysEx_MIDI_out(MIDI_1, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 3, GS_command, true);
		GS_command[7]=0x2;
		sendSysEx_MIDI_out(MIDI_1, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 3, GS_command, true);
		GS_command[7]=0x3;
		sendSysEx_MIDI_out(MIDI_1, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_2, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_3, 3, GS_command, true);
		sendSysEx_MIDI_out(MIDI_4, 3, GS_command, true);
		return;
		byte cmdtmp[] =  {0xB0, 0x4E,value};
		
		sendSysEx_MIDI_out(MIDI_1, 3, cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_2, 3, cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_3, 3, cmdtmp, false);
		sendSysEx_MIDI_out(MIDI_4, 3, cmdtmp, false);
		return;
		//byte cmdtmp[] =  {0xF0, 0xB0, 0x63, 0x01,0x62,0x0A,0x06,value,0xF7};
		//memcpy(command, cmdtmp, 9);
	}
	
}

void MIDI_mgr::setup_stop_disposition(byte disposition,byte katera_plata)
{
	/*
	Stop *this_stop=STOP_mgr.id(0);
	MIDI_sender.sendSysEx_MIDI_out(1,2, preklop_MIDI1, false);
	
	byte common_ch_cmd[] = { 0x41,0x00,0x42,0x12,0x40,0x11,0x02,0x00,0x00 };//DA DOLOÈIŠ DA SO LINKANE NA KANAL

	for(int x=0;x<40;x++)
	{
	this_stop=STOP_mgr.id(x);
	
	if(this_stop->MIDI_id_ch!=0 && this_stop->MIDI_out_numb==1)
	{
	switch (this_stop->midi_common_ch)
	{
	case COMMON_MIDI_CH1:
	common_ch_cmd[7]=0;
	break;
	case COMMON_MIDI_CH2:
	common_ch_cmd[7]=1;
	break;
	case COMMON_MIDI_CH3:
	common_ch_cmd[7]=2;
	break;
	}
	common_ch_cmd[5]=10+this_stop->MIDI_id_ch;//nastavi midi kanal
	
	MIDI_sender.sendSysEx_MIDI_out(this_stop->MIDI_out_numb,2, preklop_MIDI1, false);
	MIDI_sender.sendSysEx_MIDI_out(this_stop->MIDI_out_numb,9, common_ch_cmd, false);
	MIDI_sender.sendProgramChange_MIDI_out(this_stop->MIDI_out_numb,this_stop->ID+1,this_stop->MIDI_id_ch);
	}
	}
	*/
	//STOP_mgr.STOPS[
	DEBUG_println(F("SETUP DISPOSITION 1"));

	//byte talk_to_board[]= { 0xF5,0x01};//DA DOLOÈIŠ DA JE PLATA 1
	//MIDI_sender.sendSysEx(2, talk_to_board, false);
	//
	//byte command_1[] = { 0x41,0x00,0x42,0x12,0x40,0x11,0x02,0x00,0x00 };//DA DOLOÈIŠ DA SO LINKANE NA KANAL
	//MIDI_sender.sendSysEx(9, command_1, false);//
	//
	//byte command_2[] = { 0x41,0x00,0x42,0x12,0x40,0x11,0x02,0x01,0x00 };
	//MIDI_sender.sendSysEx(9, command_2, false);
	//
	//byte command_3[] = { 0x41,0x00,0x42,0x12,0x40,0x11,0x02,0x02,0x00 };
	//MIDI_sender.sendSysEx(9, command_3, false);
	//
	//byte command_4[] = { 0x41,0x00,0x42,0x12,0x40,0x11,0x02,0x03,0x00 };
	//MIDI_sender.sendSysEx(9, command_4, false);
	//
	//byte command_5[] = { 0x41,0x00,0x42,0x12,0x40,0x11,0x02,0x04,0x00 };
	//MIDI_sender.sendSysEx(9, command_5, false);
	//
	//byte command_6[] = { 0x41,0x00,0x42,0x12,0x40,0x11,0x02,0x05,0x00 };
	//MIDI_sender.sendSysEx(9, command_6, false);
	//
	//byte command_7[] = { 0x41,0x00,0x42,0x12,0x40,0x11,0x02,0x06,0x00 };
	//MIDI_sender.sendSysEx(9, command_7, false);
	//
	//byte command_8[] = { 0x41,0x00,0x42,0x12,0x40,0x11,0x02,0x07,0x00 };
	//MIDI_sender.sendSysEx(9, command_8, false);
	//
	//byte command_9[] = { 0x41,0x00,0x42,0x12,0x40,0x11,0x02,0x08,0x00 };
	//MIDI_sender.sendSysEx(9, command_9, false);
	//
	//
	
	//MIDI_sender.sendNote_MIDI_out(1,33,33,1,true);//
	//MIDI_sender.sendNote_MIDI_out(1,33,33,1,true);//
	//
	//MIDI_sender.sendSysEx_MIDI_out(1,2, preklop_MIDI2, false);
	//MIDI_sender.sendSysEx_MIDI_out(2,2, preklop_MIDI2, false);
	//MIDI_sender.sendSysEx_MIDI_out(3,2, preklop_MIDI2, false);
	//
	byte out_midi=0;

	out_midi=1;
	
	byte common_ch=0x02;
	
	
	//byte command_1[] = { 0x41,0x00,0x42,0x12,0x40,16,0x02,common_ch,0x00 };//DA DOLOÈIŠ DA SO LINKANE NA KANAL
	//MIDI_sender.sendSysEx_MIDI_out(out_midi,9, command_1, false);//
	//
	byte command_2[] = { 0x41,0x00,0x42,0x12,0x40,15,0x01,common_ch,0x00 };
	MIDI_sender.sendSysEx_MIDI_out(out_midi,9, command_2, false);

	byte command_3[] = { 0x41,0x00,0x42,0x12,0x40,14,0x01,common_ch,0x00 };
	MIDI_sender.sendSysEx_MIDI_out(out_midi,9, command_3, false);
	
	byte command_4[] = { 0x41,0x00,0x42,0x12,0x40,13,0x01,common_ch,0x00 };
	MIDI_sender.sendSysEx_MIDI_out(out_midi,9, command_4, false);
	
	byte command_5[] = { 0x41,0x00,0x42,0x12,0x40,12,0x01,common_ch,0x00 };
	MIDI_sender.sendSysEx_MIDI_out(out_midi,9, command_5, false);
	
	byte command_6[] = { 0x41,0x00,0x42,0x12,0x40,11,0x01,common_ch,0x00 };
	MIDI_sender.sendSysEx_MIDI_out(out_midi,9, command_6, false);
	
	byte command_7[] = { 0x41,0x00,0x42,0x12,0x40,10,0x01,common_ch,0x00 };
	MIDI_sender.sendSysEx_MIDI_out(out_midi,9, command_7, false);
	
	byte command_8[] = { 0x41,0x00,0x42,0x12,0x40,9,0x01,common_ch,0x00 };
	MIDI_sender.sendSysEx_MIDI_out(out_midi,9, command_8, false);
	
	//byte command_9[] = { 0x41,0x00,0x42,0x12,0x40,33,0x02,common_ch,0x00 };
	//MIDI_sender.sendSysEx_MIDI_out(out_midi,9, command_9, false);
	//
	//byte command_10[] = { 0x41,0x00,0x42,0x12,0x40,34,0x02,common_ch,0x00 };
	//MIDI_sender.sendSysEx_MIDI_out(out_midi,9, command_9, false);
	//

	

	
	
	
	
	//MIDI_sender.sendProgramChange(12,1);//PROGRAM CHANGE 0 , MIDI KANAL 1//tale je verjetno tihi register
	/*
	MIDI_sender.sendProgramChange(13,2);//PROGRAM CHANGE 1, MIDI KANAL 2
	MIDI_sender.sendProgramChange(14,3);//PROGRAM CHANGE 2, MIDI KANAL 3
	MIDI_sender.sendProgramChange(15,4);//PROGRAM CHANGE 3, MIDI KANAL 4
	MIDI_sender.sendProgramChange(16,5);//PROGRAM CHANGE 4, MIDI KANAL 5
	MIDI_sender.sendProgramChange(17,6);//PROGRAM CHANGE 5, MIDI KANAL 6
	MIDI_sender.sendProgramChange(18,7);//PROGRAM CHANGE 6, MIDI KANAL 7
	MIDI_sender.sendProgramChange(19,8);//PROGRAM CHANGE 5, MIDI KANAL 8
	MIDI_sender.sendProgramChange(20,9);//PROGRAM CHANGE 6, MIDI KANAL 9
	*/
	/*
	byte id_start=10;
	MIDI_sender.sendProgramChange(1,2);//PROGRAM CHANGE 1, MIDI KANAL 2
	MIDI_sender.sendProgramChange(2,3);//PROGRAM CHANGE 2, MIDI KANAL 3
	MIDI_sender.sendProgramChange(3,4);//PROGRAM CHANGE 3, MIDI KANAL 4
	MIDI_sender.sendProgramChange(4,5);//PROGRAM CHANGE 4, MIDI KANAL 5
	MIDI_sender.sendProgramChange(5,6);//PROGRAM CHANGE 5, MIDI KANAL 6
	MIDI_sender.sendProgramChange(6,7);//PROGRAM CHANGE 6, MIDI KANAL 7
	MIDI_sender.sendProgramChange(7,8);//PROGRAM CHANGE 5, MIDI KANAL 8
	MIDI_sender.sendProgramChange(8,9);//PROGRAM CHANGE 6, MIDI KANAL 9
	MIDI_sender.sendProgramChange(9,10);//PROGRAM CHANGE 2, MIDI KANAL 3
	MIDI_sender.sendProgramChange(10,11);//PROGRAM CHANGE 3, MIDI KANAL 4
	MIDI_sender.sendProgramChange(11,12);//PROGRAM CHANGE 4, MIDI KANAL 5
	MIDI_sender.sendProgramChange(12,13);//PROGRAM CHANGE 5, MIDI KANAL 6
	MIDI_sender.sendProgramChange(13,14);//PROGRAM CHANGE 6, MIDI KANAL 7
	MIDI_sender.sendProgramChange(14,15);//PROGRAM CHANGE 5, MIDI KANAL 8
	MIDI_sender.sendProgramChange(15,16);//PROGRAM CHANGE 6, MIDI KANAL 9
	*/


	//byte talk_to_board[]= { 0xF5,2};//da doloèiš da je upoštevana plata x
	//MIDI_sender.sendSysEx(2, talk_to_board, false);


	//byte command_1[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x00,0x00 };
	//MIDI.sendSysEx(8, command_1, false);
	//byte command_2[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x01,0x00 };
	//MIDI.sendSysEx(8, command_2, false);
	////byte command_3[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x02,0x00 };
	////MIDI.sendSysEx(8, command_3, false);
	////byte command_4[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x03,0x00 };
	////MIDI.sendSysEx(8, command_4, false);
	////byte command_5[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x04,0x00 };
	////MIDI.sendSysEx(8, command_5, false);
	////byte command_6[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x05,0x00 };
	////MIDI.sendSysEx(8, command_6, false);
	////byte command_7[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x06,0x00 };
	////MIDI.sendSysEx(8, command_7, false);
	////byte command_8[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x07,0x00 };
	////MIDI.sendSysEx(8, command_8, false);
	////byte command_9[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x08,0x00 };
	////MIDI.sendSysEx(8, command_9, false);
	//
	//MIDI.sendProgramChange(0x0,1);
	//MIDI.sendProgramChange(0x01,2);
	//MIDI.sendProgramChange(0x05,5);
	//MIDI.sendProgramChange(0x06,6);
	//MIDI.sendProgramChange(0x07,7);
	//MIDI.sendProgramChange(0x08,8);
	//MIDI.sendProgramChange(0,10);
	//MIDI.sendProgramChange(0,11);
	//
	//byte command_10[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x00,0x00 };
	//MIDI.sendSysEx(8, command_10, false);
	//byte command_11[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x00,0x00 };
	//MIDI.sendSysEx(8, command_11, false);
	//command_1[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x00,0x00 };
	//MIDI.sendSysEx(8, command_1, false);
	//command_1[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x00,0x00 };
	//MIDI.sendSysEx(8, command_1, false);
	//command_1[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x00,0x00 };
	//MIDI.sendSysEx(8, command_1, false);
	//command_1[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x00,0x00 };
	//MIDI.sendSysEx(8, command_1, false);
	//command_1[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x00,0x00 };
	//MIDI.sendSysEx(8, command_1, false);
	//command_1[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x00,0x00 };
	//MIDI.sendSysEx(8, command_1, false);
	//command_1[] = { 0x41,0x00,0x12,0x40,0x11,0x02,0x00,0x00 };
	//MIDI.sendSysEx(8, command_1, false);
	
	
}

void MIDI_mgr::send_midi_active_sense()
{
	return;
	byte command_1[] = { 0, 0, 0 };
	MIDI.sendSysEx(2, command_1, false);
	MIDI2.sendSysEx(2, command_1, false);
	
	//MIDI.sendControlChange(data1, data2, data3);
}
void MIDI_mgr::send_midi_MASTER_volume_change()
{

	//sendControlChange_MIDI_out(1, 7, MASTER_VOLUME, 1);
	//sendControlChange_MIDI_out(2, 7, MASTER_VOLUME, 1);
	//sendControlChange_MIDI_out(3, 7, MASTER_VOLUME, 1);
	//sendControlChange_MIDI_out(4, 7, MASTER_VOLUME, 1);
	//return;
	//softSerial.println(F("vol"));
	byte command_1[] = { 0xB0, 0x63, 0x37 };
	byte command_2[] = { 0xB0, 0x62, 0x07 };
	byte command_3[] = { 0xB0, 0x06, MASTER_VOLUME };

	sendSysEx_MIDI_out(MIDI_1, 3, command_1, false);
	sendSysEx_MIDI_out(MIDI_1, 3, command_2, false);
	sendSysEx_MIDI_out(MIDI_1, 3, command_3, false);

	sendSysEx_MIDI_out(MIDI_2, 3, command_1, false);
	sendSysEx_MIDI_out(MIDI_2, 3, command_2, false);
	sendSysEx_MIDI_out(MIDI_2, 3, command_3, false);

	sendSysEx_MIDI_out(MIDI_3, 3, command_1, false);
	sendSysEx_MIDI_out(MIDI_3, 3, command_2, false);
	sendSysEx_MIDI_out(MIDI_3, 3, command_3, false);

	sendSysEx_MIDI_out(MIDI_4, 3, command_1, false);
	sendSysEx_MIDI_out(MIDI_4, 3, command_2, false);
	sendSysEx_MIDI_out(MIDI_4, 3, command_3, false);

}
void MIDI_mgr::send_midi_volume_change(Stop *stop, byte volume)
{
	#ifndef MANUAL_num_3
	send_MIDI_function(0,  false, MANUAL_2, MIDI_MANUAL_VOLUME);
	#endif // RODGERS

	#ifdef MANUAL_num_3
	send_MIDI_function(0,  false, MANUAL_3, MIDI_MANUAL_VOLUME);
	#endif // RODGERS
	
}
void MIDI_mgr::send_midi_volume_change_manual(byte _manual, byte volume)
{
	sendControlChange_MIDI_out(3, 11, volume, COMMON_MIDI_CH1);//temp fix za manual 2 out modul
	sendControlChange_MIDI_out(4, 11, volume, COMMON_MIDI_CH1);
	
	//return;
	//
	if(digitalRead(75))
	{
		int map_val2=map(volume, 60, 127, 0,HEAD_gain_high_mid);
		//equalizer_set_pedal(ADD_menu_b1_equalizer_gain_high_mid,map_val2);
		int map_val3=map(volume, 60, 127,0,HEAD_gain_high);
		equalizer_set_pedal(ADD_menu_b1_equalizer_gain_high,map_val2);
		
		int map_val4=map(volume, 60, 127,0,HEAD_freq_high_mid__band_60_10700);
		equalizer_set_pedal(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III,map_val4);
		return;
	}
	//
	int map_val2=map(volume, 60, 126, 0,EEPROM.read(ADD_menu_b1_equalizer_gain_high_mid));
	equalizer_set_pedal(ADD_menu_b1_equalizer_gain_high_mid,map_val2);
	int map_val3=map(volume, 60, 126,0,EEPROM.read(ADD_menu_b1_equalizer_gain_high));
	equalizer_set_pedal(ADD_menu_b1_equalizer_gain_high,map_val2);
	
	int map_val4=map(volume, 60, 126,0,EEPROM.read(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III));
	equalizer_set_pedal(ADD_menu_b1_equalizer_band_freq_high_mid__band_60_10700_III,map_val4);
}
byte previous = 1;
void MIDI_mgr::send_midi_volume_change_man2(Stop *stop, byte volume)
{
	#ifndef MANUAL_num_3
	//send_MIDI_function(0, stop, false, MANUAL_2, MIDI_MANUAL_VOLUME);
	#endif // RODGERS

	#ifdef MANUAL_num_3
	if (previous != volume)
	{
		send_MIDI_function(0,false, MANUAL_2, MIDI_VOLUME_man2);
		previous = volume;
	}

	#endif // RODGERS

}
void MIDI_mgr::send_tremulant_key(int key, Stop *stop_in, bool on_off, int manual, bool force_skip_check)
{




	//if(manual==MANUAL_1)
	send_MIDI_function(key, on_off, manual, MIDI_MODULATION_MAN_II);
	return;
	if(stop_in->get_active_on_manual()==MANUAL_1)
	send_MIDI_function(key, on_off, manual, MIDI_MODULATION_MAN_I);
	
	if(stop_in->get_active_on_manual()==MANUAL_1)
	send_MIDI_function(key, on_off, manual, MIDI_MODULATION_MAN_I);
}



void MIDI_mgr::send_midi_key_grand_orgue(int key, Stop *stop, bool on_off, int manual, bool force_skip_check)
{
	//
	//("key-> ");
	//DEBUG_println(key);
	//key + transpose;

	//if ((stop->GetState() == true || force_skip_check))// && manual == stop->active_on_manual)
	{

		DEBUG_print(F("2 ON key-> "));
		DEBUG_print(key + 23);
		DEBUG_print(F(" ch->"));
		DEBUG_print(stop->get_MIDI_CH());
		DEBUG_print(F(" MIDI no->"));
		DEBUG_print(stop->get_MIDI_out_numb());
		DEBUG_print(F(" manual->"));
		DEBUG_print(manual);
		DEBUG_print(F(" port->"));
		DEBUG_println(stop->get_midi_common_ch());

		byte channel = 0;
		switch (manual)
		{
			case PEDAL:
			channel = 6;
			break;
			case MANUAL_1:
			channel = 1;
			break;
			case MANUAL_2:
			channel = 2;
			break;
			case MANUAL_3:
			channel = 3;
			break;
			case MANUAL_4:
			channel = 4;
			break;
			case MANUAL_5:
			channel = 5;
			break;
			default:
			break;
		}
		//channel=0;
		//channel=1;//midi kanal 0 verjetno rene misli kot kanal 1
		//if (stop->active_on_manual == MANUAL_1)
		{
			//MASTER_VOLUME=100;

			if (on_off)
			{
				MIDI.sendNoteOn(key + 23, map(127, 0, 127, 0, MASTER_VOLUME), channel);
			}
			else
			{
				MIDI.sendNoteOff(key + 23, 0, channel);
			}

		}

	}
}