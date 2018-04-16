 
 
 

 #include "SD_mgr.h"
 #include "global_methods.h"
 #include <MemoryFree.h>
 #include "EEPROM.h"
 unsigned char  chipSelect = 53;
 // #define Strings_ADD 900000
 



 
 SD_mgr::SD_mgr()
 {

	 //if (!SD.begin(chipSelect)) {
	 //COMBINATION_LABEL_TEXT = F("NO SD CARD");
	 //DEBUG_println(F("initialization failed!"));
	 //return;
	 //}
	 //pinMode(SS, OUTPUT);
	 //if (!SD.begin(chipSelect)) {
	 //COMBINATION_LABEL_TEXT = "NO SD CARD";
	 
	 //}
	 //else
	 //_connection = true;

 }
 
 void SD_mgr::printDirectory1(File dir, int numTabs) {
	 while (true) {
		 File entry =  dir.openNextFile();
		 if (! entry) {
			 
			 entry.close();
			 break;
		 }
		 DEBUG_println(entry.name());
		 
		 //exRAM.write_stream(Strings_ADD+)
		 
		 entry.close();
	 }
 }
 
 
 void SD_mgr::SD_mgr_init()
 {

	 _connection = false;
	 exRAM.write_byte(20,45);
	 pinMode(SS, OUTPUT);
	 if (!SD.begin(SS)) {
		 //COMBINATION_LABEL_TEXT = F("NO SD CARD");
		 DEBUG_println(F("initialization failed!"));
		 return;
	 }
	 else
	 DEBUG_println(F("YAY DELA SD ++++++++++++"));
	 
	 _connection = true;
	 if(!SD.exists("/TRACKS"))
	 {
		 DEBUG_println(F("NE OBSTAJA"));
		 SD.mkdir("/TRACKS");
	 }
	 
	 
	 // File tmp=SD.open("/TRACKS");
	 sd_files_refresh();
	 // printDirectory(tmp,0);
	 calculate_free_RAM(123);
	 
 }
 void ByteToChar(byte* bytes, char* chars, unsigned int count){
	 for (unsigned int i = 0; i < count; i++)
	 chars[i] = (char)bytes[i];
 }
 void CharToByte(char* chars, byte* bytes, unsigned int count){
	 for (unsigned int i = 0; i < count; i++)
	 bytes[i] = (byte)chars[i];
 }

 char* itob(int val, char* buf, size_t n)
 {
	 char* bp = buf + n;
	 do {
		 *--bp = (val % 10) + '0';
		 val = val / 10;
	 } while (bp != buf);
	 return (buf);
 }

 void printDirectory(File dir, int numTabs) {
	 

 }

 boolean SD_mgr::Read_zecer_combination(byte user, byte button_num, int combination_num, byte* combination)
 {

 }


 boolean SD_mgr::Write_zecer_combination(byte user, byte button, int combination_num, byte* combination)
 {
	 return true;
 }

 boolean SD_mgr::create_blank_file(byte user)
 {

 }

 boolean SD_mgr::Write_zecer_combination_backup(byte button, byte combination_num, byte* combination)
 {

	 return false;
 }


 boolean SD_mgr::copyFile(char* path_name, char* path_name_tmp, byte limit_current, int combination_num, char* tempC)//-1 za copy file
 {
	 

	 
	 return true;
 }
 unsigned long SD_mgr::get_timestamp(byte state)
 {
	 if(state==state_RECORDING&&state_rec_play==state_RECORDING)
	 return millis() - REC_time;
	 else if(state== state_PLAYING&&state_rec_play==state_PLAYING)
	 return millis() - PLAY_time;
	 else
	 return 0;
 }

 boolean SD_mgr::refresh()
 {
	 return true;
 }

 boolean SD_mgr::check_SD_init()
 {
	 // return true;
	 if (SD.exists("test.txt"))
	 {
		 SD.remove("test.txt");//prepišiž
		 return true;
	 }
	 
	 File init_checker=SD.open("test.txt",FILE_WRITE);
	 if (SD.exists("test.txt"))
	 {
		 init_checker.close();
		 SD.remove("test.txt");//prepišiž
		 
		 return true;
	 }
	 init_checker.close();
	 
	 return false;
	 SD.root.close();
	 SD.begin(SS);
	 init_checker=SD.open("test.txt",FILE_WRITE);
	 if (SD.exists("test.txt"))
	 {
		 init_checker.close();
		 SD.remove("test.txt");//prepišiž
		 return true;
	 }
	 init_checker.close();
	 return false;
 }
 #define POS_byte_count 0
 #define POS_last_add 4
 #define POS_cmd_count 8
 #define POS_track_time 12
 #define POS_first_cmd 16
 byte SD_mgr::set_recording(bool ON_OFF)
 {
	 byte cmp_state= state_IDLING;

	 if(ON_OFF==true)
	 cmp_state=state_RECORDING;
	 else
	 {
		 //recording_add_note(MANUAL_1,1,false);
		 cmp_state= state_IDLING;
		 byte tmp_cm[3];
		 // rec_midi_event(tmp_cm,end_of_rec,3);
	 }


	 if(state_rec_play==cmp_state)
	 return state_rec_play;//problemi, snemanje aktivno
	 
	 if(cmp_state==state_RECORDING)
	 {
		 if(SD.exists(FILENAME_PATH))
		 SD.remove(FILENAME_PATH);
		 
		 SD_master=SD.open(FILENAME_PATH,FILE_WRITE);
		 SD_master.seek(0);
		 state_rec_play=state_RECORDING;
		 for(int x=0;x<16;x++)
		 {
			 SD_master.write('0');
		 }
	 }
	 else if(cmp_state==state_IDLING)
	 {
		 SD_master.close();
		 state_rec_play= state_IDLING;
		 SD_work.sd_files_refresh();
	 }
	 time_count=0;
	 REC_time=millis();
	 current_address=POS_first_cmd;
	 exRAM.write_float(POS_byte_count,0);
	 exRAM.write_float(POS_last_add,0);
	 exRAM.write_float(POS_cmd_count,0);
	 exRAM.write_float(POS_first_cmd,0);
	 //file_REC.close();
	 //file_REC = SD.open(path_name, FILE_WRITE);//open
	 //REC_time = millis();
	 for(int x=0;x<STOP_mgr.Stop_count;x++)
	 {
		 if( STOP_mgr.id(x)->GetState()==true)
		 {
			 STOP_mgr.id(x)->SetState(false);
			 STOP_mgr.id(x)->SetState(true);
		 }
		 
	 }
	 
	 
	 return state_rec_play;
 }
 #define NOTE 10

 byte SD_mgr::set_playing(bool ON_OFF,String path)
 {
	 
	 if(state_rec_play==state_RECORDING)
	 return state_RECORDING;//problemi, snemanje aktivno
	 
	 byte cmp_state= state_IDLING;

	 if(ON_OFF==true)
	 cmp_state= state_PLAYING;
	 else
	 {
		 cmp_state= state_IDLING;
		 SD_master.close();
	 }

	 
	 if(state_rec_play==cmp_state)
	 return state_rec_play;//problemi, snemanje aktivno
	 


	 if(cmp_state== state_PLAYING)
	 {
		 state_rec_play= state_PLAYING;
		 
		 // midi_file_testing(path);
		 load_exRAM(path);
		 
	 }
	 else
	 state_rec_play= state_IDLING;
	 
	 
	 PLAY_time=millis();
	 
	 // current_address=POS_first_cmd;
	 //for(int x=0;x<100;x++)
	 //{
	 //NEXT_time=sd_read_long(x);
	 //DEBUG_print(x);
	 //DEBUG_STRING_print("next :");
	 //DEBUG_println(NEXT_time);
	 //}
	 
	 NEXT_time=sd_read_long(20);
	 //DEBUG_STRING_print("next time:");
	 //DEBUG_println(NEXT_time);
	 //delay(10000000);
	 // NEXT_time= exRAM.read_long(current_address+4);//èas prvega ukaza
	 var_cmd_count=0;
	 
	 for(int x=0;x<STOP_mgr.Stop_count;x++)
	 {
		 STOP_mgr.id(x)->SetState(false);
	 }


	 return state_rec_play;
 }

 boolean SD_mgr::get_is_recording()
 {
	 if(state_rec_play==state_RECORDING)
	 return true;
	 else
	 return false;
 }
 boolean SD_mgr::get_is_playing()
 {
	 if(state_rec_play== state_PLAYING)
	 return true;
	 else
	 return false;
 }

 #define STOP 20

 unsigned long sd_position;
 boolean  SD_mgr::load_exRAM_part(String path)
 {
	 //File SD_reader=SD.open(FILENAME_PATH,FILE_READ);
	 //long tmp_add=0;
	 //if(SD_reader.available())
	 //{
	 //}
	 //
	 DEBUG_println(F("LOAD exRAM"));
	 long file_size=0;
	 

	 DEBUG_println(F("FILE OK"));
	 // File SD_reader=SD.open(FILENAME_PATH,FILE_READ);
	 SD_master.seek(sd_position);
	 long tmp_add=POS_first_cmd;
	 

	 // read from the file until there's nothing else in it:
	 byte tmp_read;
	 while (SD_master.available())
	 {
		 
		 //byte dummy=SD_reader.read();
		 //  tmp_read=SD_reader.read();
		 exRAM.write_byte(tmp_add,SD_master.read());
		 //softSerial.print(tmp_read,HEX);
		 tmp_add++;
		 loaded_cmd_counter++;
		 
	 }


	 current_address=16;
	 return true;
	 
	 return false;
 }


 boolean  SD_mgr::load_exRAM(String path)
 {
	 //File SD_reader=SD.open(FILENAME_PATH,FILE_READ);
	 //long tmp_add=0;
	 //if(SD_reader.available())
	 //{
	 //}
	 //
	 DEBUG_println(F("LOAD exRAM"));
	 long file_size=0;
	 
	 if (SD.exists(path))
	 {
		 DEBUG_println(F("FILE OK"));
		 SD_master=SD.open(FILENAME_PATH,FILE_READ);
		 long tmp_add=POS_first_cmd;
		 

		 
		 if (SD_master) {
			 
			 char float_combined[4];
			 if(SD_master.available())
			 {
				 if(SD_master.size()>=16)
				 {
					 SD_master.readBytes(float_combined,4);
					 file_size=return_float(float_combined);
					 
					 SD_master.readBytes(float_combined,4);
					 var_last_add=return_float(float_combined);
					 
					 SD_master.readBytes(float_combined,4);
					 PLAY_cmd_count=return_float(float_combined);
					 
					 SD_master.readBytes(float_combined,4);
					 Var_track_time(return_float(float_combined));
					 
					 DEBUG_STRING_print("file size:");
					 DEBUG_println(file_size);
					 
					 DEBUG_STRING_print("var_last_add:");
					 DEBUG_println(var_last_add);
					 
					 DEBUG_STRING_print("PLAY_cmd_count:");
					 DEBUG_println(PLAY_cmd_count);
					 
					 DEBUG_STRING_print("var_track_time:");
					 DEBUG_println(Var_track_time());
					 
				 }
			 }
			 sd_position=SD_master.position();
			 // SD_reader.close();
			 current_address=16;
			 return false;
			 
			 //ne pozabi

			 
			 
			 
			 
		 }
	 }
 }



 boolean SD_mgr::midi_file_testing(String path)
 {
	 if (SD.exists(path))
	 {
		 DEBUG_println(F("FILE OPENED"));
		 File SD_reader=SD.open(FILENAME_PATH,FILE_READ);
		 // MIDI_file_handler midi_tester(SD_reader);
		 
	 }
 }

 //#define ADD_filestrings_count 127740

 boolean SD_mgr::sd_files_refresh()
 {
	 files_count=0;
	 calculate_free_RAM(9118);
	 int counter=0;
	 long tmp_address=ADD_filestrings;
	 File dir = SD.open("/TRACKS");
	 // File entry = dir.openNextFile();
	 while (true) {
		 File entry =  dir.openNextFile();
		 
		 if (! entry) {
			 
			 entry.close();
			 break;
		 }
		 
		 
		 long tmp_add=POS_first_cmd;
		 int this_track_time;
		 if (entry) {
			 
			 char float_combined[4];
			 if(entry.available())
			 {
				 if(entry.size()>=16)
				 {
					 entry.readBytes(float_combined,12);
					 entry.readBytes(float_combined,4);
					 this_track_time=return_float(float_combined);
					 
					 //DEBUG_STRING_print("var_track_time:");
					 //DEBUG_println(this_track_time);
					 
				 }
			 }
		 }
		 //DEBUG_println(entry.name());
		 String test;
		 String file_name=entry.name();
		 DEBUG_STRING_println("ime fajla ");
		 DEBUG_println( file_name.indexOf("FILE"));
		 DEBUG_println(file_name);
		 
		 if(file_name[0]=='F'&&file_name[1]=='I')
		 {
			 
			 DEBUG_println(file_name);
			 char ram_file_name[13];
			 file_name.toCharArray(ram_file_name,13,0);
			 // DEBUG_println(ram_file_name);
			 
			 //for(int x=file_name.length();x<12;x++)
			 //{
			 //ram_file_name[x]=' ';
			 //}
			 
			 //DEBUG_println(ram_file_name);
			 exRAM.write_stream(tmp_address,ram_file_name,13);
			 
			 char ram_file_name2[13];
			 exRAM.read_stream(tmp_address,ram_file_name2,13);
			 //DEBUG_println(ram_file_name2);
			 tmp_address+=15;

			 exRAM.write_int(tmp_address-2,this_track_time);
			 files_count++;
			 DEBUG_STRING_print("tmp_address ");
			 DEBUG_println(tmp_address);
			 DEBUG_println(files_count);
			 //exRAM.write_stream(Strings_ADD+)
			 counter++;
		 }
		 entry.close();
	 }
	 calculate_free_RAM(9118);
	 dir.close();
	 // exRAM.write_byte(ADD_filestrings_count,counter);//število fajlov
	 
 }

 boolean SD_mgr::save_current_recording(String path)
 {
	 SD_master.seek(0);
	 char  sliced_float[4];
	 get_splited_float_arr(sliced_float,var_byte_count);
	 SD_master.write(sliced_float,4);
	 //last address
	 get_splited_float_arr(sliced_float,var_last_add);
	 SD_master.write(sliced_float,4);
	 //cmd count
	 get_splited_float_arr(sliced_float,var_cmd_count);
	 SD_master.write(sliced_float,4);
	 //track time
	 get_splited_float_arr(sliced_float,get_recording_time());
	 SD_master.write(sliced_float,4);
	 SD_master.flush();
	 return true;
	 calculate_free_RAM(2);
	 //exRAM.write_float(current_address,1000000);

	 if(get_is_recording()==false)
	 return false;
	 
	 if(path.length()<4)
	 {
		 DEBUG_println(F("SD glupo"));
		 DEBUG_println(path);
		 return false;
	 }

	 DEBUG_println(F("saving:"));
	 DEBUG_println(path);
	 
	 if (SD.exists(path))
	 {
		 SD.remove(path);//prepiši
	 }
	 File SD_writter=SD.open(FILENAME_PATH,FILE_WRITE);
	 SD_writter.close();


	 SD_writter=SD.open(FILENAME_PATH,FILE_WRITE);



	 //podatki o datoteki
	 //file length
	 // char  sliced_float[4];
	 get_splited_float_arr(sliced_float,var_byte_count);
	 SD_writter.write(sliced_float,4);
	 //last address
	 get_splited_float_arr(sliced_float,var_last_add);
	 SD_writter.write(sliced_float,4);
	 //cmd count
	 get_splited_float_arr(sliced_float,var_cmd_count);
	 SD_writter.write(sliced_float,4);
	 //track time
	 get_splited_float_arr(sliced_float,get_recording_time());
	 SD_writter.write(sliced_float,4);

	 DEBUG_STRING_print("recording time:");
	 DEBUG_println(get_recording_time());
	 DEBUG_STRING_print("var_byte_count:");
	 DEBUG_println(var_byte_count);
	 DEBUG_STRING_print("var_last_add:");
	 DEBUG_println(var_last_add);
	 DEBUG_STRING_print("var_cmd_count:");
	 DEBUG_println(var_cmd_count);
	 bool _run=true;
	 long position_address=POS_first_cmd;
	 
	 if(var_cmd_count==0)
	 _run=false;
	 
	 
	 int every_num_count=var_cmd_count/100;
	 int counter_byte;
	 byte percent=0;
	 
	 while(_run)
	 {

		 long calc_lenght=exRAM.read_long(position_address)-position_address; //dolžina ukaza
		 char cmd_buff[calc_lenght];//pripravi buffer dolžine ukaza
		 
		 DEBUG_print(F("current_address:"));
		 DEBUG_print(position_address);
		 
		 DEBUG_print(F(" NEXT ADD:"));
		 DEBUG_print(exRAM.read_long(position_address));
		 
		 DEBUG_print(F(" dolzina:"));
		 DEBUG_println(calc_lenght);
		 

		 byte tmp_midi_out=0;
		 tmp_midi_out=exRAM.read_byte(position_address+8);


		 if(tmp_midi_out==end_of_rec)
		 {
			 // break;
		 }//konèaj


		 exRAM.read_stream(position_address,cmd_buff,calc_lenght);//midi ukaz
		 
		 DEBUG_print(F("  cmd:"));
		 DEBUG_print((byte)cmd_buff[0]);
		 DEBUG_print(F("  cmd2:"));
		 DEBUG_print((byte)cmd_buff[1]);
		 DEBUG_print(F("  cmd3:"));
		 DEBUG_print((byte)cmd_buff[2]);
		 
		 position_address=exRAM.read_long(position_address);//nastavi naslednji addres za branje
		 
		 if(tmp_midi_out!=end_of_rec)
		 {
			 SD_writter.write(cmd_buff,calc_lenght);
		 }
		 else
		 {
			 SD_writter.write(cmd_buff,calc_lenght);
			 SD_writter.close();
			 break;
		 }


		 if(position_address>=current_address)
		 {
			 SD_writter.close();
			 break;
		 }
		 
		 counter_byte++;
		 if(counter_byte>=every_num_count)
		 {
			 
			 
			 counter_byte=0;
			 percent++;
			 if(percent<=100)
			 MENU_mgr.draw_text_string(String(percent)+"%",0,80,true);
			 //DEBUG_STRING_print(" ---add ");
			 //DEBUG_print(tmp_add);
			 //DEBUG_STRING_print(" ---% ");
			 //DEBUG_println(percent);
		 }
		 
		 
		 

	 }
	 MENU_mgr.draw_text_string("100%",0,80,false);
	 var_byte_count=0;
	 var_cmd_count=0;
	 state_rec_play=state_IDLING;
	 SD_work.sd_files_refresh();
	 return true;
 }


 boolean SD_mgr::recording_rec_gas_pedal(byte manual,byte value)
 {
	 byte midi_event[3];
	 
	 midi_event[0]=0xB0;
	 midi_event[1]=0x0B;
	 midi_event[1]=value;
	 SD_work.rec_midi_event(midi_event,1,3);
 }


 boolean SD_mgr::recording_add_note(byte manual,byte note,bool on_off)
 {
	 byte midi_event[3];
	 midi_event[1]=note;
	 
	 if(on_off)
	 {
		 midi_event[0]=144;
		 midi_event[2]=127;
	 }
	 else
	 {
		 midi_event[0]=128;
		 midi_event[2]=0;
	 }
	 

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



 boolean SD_mgr::recording_add_stop_change(Stop* stop,bool ON_OFF)//byte manual, byte id, bool on_off
 {
	 // stop->get_active_on_manual(), stop->get_ID()
	 
	 
	 
	 byte midi_msg[3];
	 
	 if( stop->get_STOP_type()==type_NORMAL_STOP)
	 {
		 midi_msg[0]=176;//control change 1. kanal
		 
		 if(ON_OFF)
		 midi_msg[1]=110;
		 else
		 midi_msg[1]=111;
		 
		 midi_msg[2]=stop->get_ID();
	 }
	 else
	 {
		 midi_msg[0]=177;
		 if(ON_OFF)
		 midi_msg[1]=110;
		 else
		 midi_msg[1]=111;
		 
		 switch(stop->get_MIDI_CH())
		 {
			 case II_I:
			 midi_msg[2]=MIDI_II_I;break;
			 case II_PED:
			 midi_msg[2]=MIDI_II_PED;break;
			 case SUB_II:
			 midi_msg[2]=MIDI_SUB_II;break;
			 case SUPER_II:
			 midi_msg[2]=MIDI_SUPER_II;break;
			 case SUPER_III:
			 midi_msg[2]=MIDI_SUPER_III;break;
			 case SUB_III:
			 midi_msg[2]=MIDI_SUB_III;break;
			 case III_PED:
			 midi_msg[2]=MIDI_III_PED;break;
			 case III_II:
			 midi_msg[2]=MIDI_III_II;break;
			 case III_I:
			 midi_msg[2]=MIDI_III_I;break;
			 case I_PED:
			 midi_msg[2]=MIDI_I_PED;break;
			 case SUB_I:
			 midi_msg[2]=MIDI_SUB_I;break;
			 case SUPER_I:
			 midi_msg[2]=MIDI_SUPER_I;break;
			 case TREMULANT_I:
			 midi_msg[2]=MIDI_TREMULANT_I;break;
			 case TREMULANT_II:
			 midi_msg[2]=MIDI_TREMULANT_II;break;
			 default:
			 DEBUG_STRING_println("problem ne zazna");
			 DEBUG_print(stop->get_MIDI_CH());
			 break;
		 }
	 }
	 
	 rec_midi_event(midi_msg,0,3);
	 return true;
 }

 int count_rec_test;



 byte percent_test;

 boolean SD_mgr::rec_midi_event(byte* cmd,byte midi_out,byte cmd_length)
 {
	 //MIDI_sender.sendNote_MIDI_out(1,1,1,1,1);
	 if(state_rec_play != state_RECORDING)
	 return false;
	 
	 //if(current_address>127740)//zaradi velikosti rama..
	 //return false;
	 
	 if(count_rec_test>=1277)
	 {
		 count_rec_test=0;
		 percent_test++;
		 // MENU_mgr.draw_text_string(String(percent_test)+"%",0,80,true);
	 }
	 long next_cmd_add=current_address+9+cmd_length;//da ve kje v ramu prebrati naslednjo komando
	 long timestamp = get_timestamp(state_RECORDING);
	 
	 
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
	 //
	 //rec_cmd[8] = (next_cmd_add & 0xFF);
	 //rec_cmd[7] = ((next_cmd_add >> 8) & 0xFF);
	 //rec_cmd[6] = ((next_cmd_add >> 16) & 0xFF);
	 //rec_cmd[5] = ((next_cmd_add >> 24) & 0xFF);
	 //
	 //rec_cmd[4] = (timestamp & 0xFF);
	 //rec_cmd[3] = ((timestamp >> 8) & 0xFF);
	 //rec_cmd[2] = ((timestamp >> 16) & 0xFF);
	 //rec_cmd[1] = ((timestamp >> 24) & 0xFF);
	 //
	 //rec_cmd[0] = midi_out;
	 
	 #ifdef SERIAL_MONITOR_DEBUG

	 DEBUG_print(F(" HEX CMD: "));
	 softSerial.print((byte)cmd[0],HEX);
	 // DEBUG_print((byte)cmd[0],HEX);
	 DEBUG_print(F(" ::"));
	 softSerial.print((byte)cmd[1],HEX);
	 DEBUG_print(F(" :: "));
	 softSerial.print((byte)cmd[2],HEX);
	 #endif
	 
	 DEBUG_print(F("  ;DEC CMD: "));
	 for(byte x=9;x<cmd_length+9;x++)
	 {
		 rec_cmd[x] = cmd[x-9];
		 
		 DEBUG_print(F(" :: "));
		 DEBUG_print((byte)rec_cmd[x]);
	 }
	 DEBUG_println(F(" "));
	 DEBUG_print(F("FILE SIZE: "));
	 DEBUG_print(SD_master.size());
	 DEBUG_print(F(" SD POSITION: "));
	 DEBUG_println(SD_master.position());
	 
	 SD_master.write(rec_cmd,9+cmd_length);
	 //exRAM.write_stream(get_current_address(),rec_cmd,9+cmd_length);

	 DEBUG_print(F("cmd length: "));
	 DEBUG_print(cmd_length);

	 DEBUG_print(F(" ADD: "));
	 DEBUG_print(current_address);

	 DEBUG_print(F(" NEXT_ADD: "));
	 DEBUG_print(next_cmd_add);

	 DEBUG_print(F(" TIME: "));
	 DEBUG_print(timestamp);

	 // NEXT_time=  exRAM.read_long(current_address+4);
	 unsigned long tmp_add1=SD_master.position();
	 NEXT_time=sd_read_long(current_address+4);
	 SD_master.seek(tmp_add1);
	 //char float_combined[4];
	 //SD_master.readBytes(float_combined,4);
	 //NEXT_time=return_float(float_combined);
	 
	 DEBUG_print(F(" NEX_TIME:"));
	 DEBUG_println(NEXT_time);

	 DEBUG_STRING_println("==================");



	 var_last_add=current_address;//zadnji ukaz add
	 current_address+=(9+cmd_length);
	 var_cmd_count++;
	 
	 count_rec_test+=9+cmd_length;
	 return true;
 }
 
 boolean SD_mgr::read_send_midi_event()
 {
	 // test:
	 //if(get_is_playing()==false)
	 //return false;
	 
	 //if(var_cmd_count>=PLAY_cmd_count)
	 //{
	 //return false;
	 //DEBUG_STRING_println("IZKLOPPPPPPPPPPPP");
	 //set_playing(false,"");
	 //return false;
	 //}
	 
	 SD_master.seek(current_address);
	 
	 //long calc_lenght=exRAM.read_long(current_address)-current_address; //dolžina ukaza
	 long calc_lenght=sd_read_long(current_address)-current_address; //dolžina ukaza
	 char cmd_buff[calc_lenght-9];//pripravi buffer dolžine ukaza
	 byte manual=1;
	 boolean on_off=false;
	 
	 //if(loaded_count==0)//èe je buffer prazen ga naloži
	 //{
	 //uint32_t tmp_pos;
	 //
	 //while(true)
	 //{
	 //tmp_pos=work_file.position();//shrani trenutno pozicijo
	 //
	 //if(tmp_pos<work_file.size())
	 //{
	 //cmd_tmp=read_next_cmd();
	 //if(cmd_tmp.midi_cmd_delta_time>1)
	 //{
	 //work_file.seek(tmp_pos);
	 //break;
	 //}
	 //else
	 //{
	 //load_into_RAM_cmd(cmd_tmp);
	 ////exRAM.write_stream(current_address,cmd_tmp.midi_cmd,cmd_tmp.midi_cmd_length);
	 //loaded_count++;
	 //}
	 //}
	 //}
	 //}
	 
	 
	 while(true)
	 {
		 
		 
		 if(!(get_timestamp(state_PLAYING)>=NEXT_time))
		 {
			 
			 //DEBUG_print(get_timestamp(state_PLAYING));
			 //DEBUG_STRING_print(" next:: ");
			 //DEBUG_print(get_timestamp(NEXT_time));
			 //DEBUG_STRING_println("return ");
			 return true;
		 }
		 
		 // calc_lenght=exRAM.read_long(current_address)-current_address; //dolžina ukaza
		 calc_lenght=sd_read_long(current_address)-current_address; //dolžina ukaza
		 // DEBUG_STRING_println("calc length ");
		 //DEBUG_print(calc_lenght);
		 cmd_buff[calc_lenght-9];//pripravi buffer dolžine ukaza
		 
		 
		 
		 // NEXT_time= exRAM.read_long(current_address+4);//èas ukaza
		 NEXT_time=sd_read_long(current_address+4);
		 byte tmp_midi_out=0;
		 // tmp_midi_out=exRAM.read_byte(current_address+8);
		 tmp_midi_out=sd_read_long(current_address+8);
		 
		 SD_master.seek(current_address+9);
		 SD_master.readBytes(cmd_buff,calc_lenght-9);
		 // exRAM.read_stream(current_address+9,cmd_buff,calc_lenght-9);//midi ukaz
		 
		 current_address=sd_read_long(current_address);
		 //current_address=exRAM.read_long(current_address);//nastavi naslednji addres za branje
		 NEXT_time=sd_read_long(current_address+4);
		 // NEXT_time= exRAM.read_long(current_address+4);//èas naslednjega ukaza
		 
		 //DEBUG_STRING_print("pride sem3");
		 //if(cmd_buff[0]==0xB0)
		 //{
		 //MIDI_sender.send_midi_volume_change_manual(MANUAL_2, cmd_buff[2]);
		 //}
		 //else
		 if(cmd_buff[0]==177)
		 {
			 DEBUG_STRING_println("STOP spec CHANGE ");
			 DEBUG_print_HEX(cmd_buff[2]);
			 DEBUG_STRING_print(" : ");
			 byte tmp_stop_id=0;
			 switch(cmd_buff[2])
			 {
				 case MIDI_II_I:
				 tmp_stop_id=II_I;break;
				 case MIDI_II_PED:
				 tmp_stop_id=II_PED;break;
				 case MIDI_SUB_II:
				 tmp_stop_id=SUB_II;break;
				 case MIDI_SUPER_II:
				 tmp_stop_id=SUPER_II;break;
				 case MIDI_SUPER_III:
				 tmp_stop_id=SUPER_III;break;
				 case MIDI_SUB_III:
				 tmp_stop_id=SUB_III;break;
				 case MIDI_III_PED:
				 tmp_stop_id=III_PED;break;
				 case MIDI_III_II:
				 tmp_stop_id=III_II;break;
				 case MIDI_III_I:
				 tmp_stop_id=III_I;break;
				 case MIDI_I_PED:
				 tmp_stop_id=I_PED;break;
				 case MIDI_SUB_I:
				 tmp_stop_id=SUB_I;break;
				 case MIDI_SUPER_I:
				 tmp_stop_id=SUPER_I;break;
				 case MIDI_TREMULANT_I:
				 tmp_stop_id=TREMULANT_I;break;
				 case MIDI_TREMULANT_II:
				 tmp_stop_id=TREMULANT_II;break;
				 
				 DEBUG_println(tmp_stop_id);
			 }
			 if(cmd_buff[1]==110)
			 {
				 STOP_mgr.id(tmp_stop_id)->SetState(true);
			 }
			 else if(cmd_buff[1]==111)
			 {
				 STOP_mgr.id(tmp_stop_id)->SetState(false);
			 }
		 }
		 else if(cmd_buff[0]==176)
		 {
			 DEBUG_STRING_println("STOP CHANGE or vol");
			 DEBUG_println((byte)cmd_buff[1]);
			 if(cmd_buff[1]==110)
			 {
				 if(cmd_buff[2]<=STOP_mgr.Stop_count)
				 STOP_mgr.id(cmd_buff[2])->SetState(true);
			 }
			 else if(cmd_buff[1]==111)
			 {
				 if(cmd_buff[2]<=STOP_mgr.Stop_count)
				 STOP_mgr.id(cmd_buff[2])->SetState(false);
			 }
			 else if(cmd_buff[1]==0x0B)
			 {
				 MIDI_sender.send_midi_volume_change_manual(MANUAL_2, cmd_buff[2]);
			 }
		 }
		 else if(cmd_buff[0]>=128 &&cmd_buff[0]<=160)
		 {
			 manual=1;
			 on_off=false;
			 
			 if( cmd_buff[0]>=128&& cmd_buff[0]<144)
			 {
				 
				 switch(cmd_buff[0])
				 {
					 case 128:
					 manual=PEDAL;
					 break;
					 case 129:
					 manual=MANUAL_1;
					 break;
					 case 130:
					 manual=MANUAL_2;
					 break;
					 case 131:
					 manual=MANUAL_3;
					 break;
					 case 132:
					 manual=MANUAL_4;
					 break;
					 case 133:
					 manual=MANUAL_5;
					 break;
				 }
				 on_off=false;
				 
				 
			 }
			 else if( cmd_buff[0]>=144&& cmd_buff[0]<=160)
			 {
				 switch(cmd_buff[0])
				 {
					 case 144:
					 manual=PEDAL;
					 break;
					 case 145:
					 manual=MANUAL_1;
					 break;
					 case 146:
					 manual=MANUAL_2;
					 break;
					 case 147:
					 manual=MANUAL_3;
					 break;
					 case 148:
					 manual=MANUAL_4;
					 break;
					 case 149:
					 manual=MANUAL_5;
					 break;
				 }
				 on_off=true;
			 }
			 DEBUG_print(F("===========;DEC CMD: "));
			 for(byte x=0;x<calc_lenght-9;x++)
			 {
				 cmd_buff[x] = cmd_buff[x];
				 
				 DEBUG_print(F(" :: "));
				 DEBUG_print((byte)cmd_buff[x]);
			 }
			 
			 MIDI_sender.play_note_input_inject_helper(cmd_buff[1],127,on_off,manual);
			 
			 // MIDI_sender.send_note_DREAM(cmd_buff[1]-23,on_off,manual,cmd_buff[2]);//-23 nujno
		 }

		 DEBUG_print(F(" time:"));
		 DEBUG_print(get_timestamp(state_PLAYING));
		 
		 //DEBUG_STRING_print("var_cmd_count:");
		 //DEBUG_print(var_cmd_count);
		 DEBUG_STRING_print(" count:");
		 DEBUG_print(var_cmd_count);
		 var_cmd_count++;
		 
		 if(var_cmd_count>=PLAY_cmd_count)
		 {
			 set_playing(false,"");
			 return false;
		 }
	 }
	 return true;
	 // goto test;
	 // read_send_midi_event();
	 // return;
 }
 


 unsigned long SD_mgr::get_current_address()
 {
	 return	current_address;
 }

 int SD_mgr::get_filecount()
 {
	 //SD.open()
	 return -1;
 }

 int SD_mgr::get_recording_time()
 {
	 return get_timestamp(state_RECORDING)/1000;
 }

 int SD_mgr::get_playing_time()
 {
	 
	 return get_timestamp(state_PLAYING)/1000;
 }


 boolean SD_mgr::Read_zecer_combination_backup(byte button_num, byte combination_num, byte* combination)
 {
	 return false;
	 
 }


 boolean SD_mgr::load_into_RAM_cmd(Midifile_cmd cmd_)
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
	 exRAM.write_stream(get_current_address(),rec_cmd,9+cmd_length);

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

 unsigned long SD_mgr::sd_read_long(unsigned long location)
 {
	 ////DEBUG_STRING_print("file obstaja");
	 ////DEBUG_println( SD_master.available());
	 ////DEBUG_println(SD_master.name());
	 ////
	 char float_combined[4];
	 SD_master.seek(location);
	 SD_master.readBytes(float_combined,4);
	 
	 char float_combined_tmp[4];
	 float_combined_tmp[0]=float_combined[3];
	 float_combined_tmp[1]=float_combined[2];
	 float_combined_tmp[2]=float_combined[1];
	 float_combined_tmp[3]=float_combined[0];
	 
	 return return_float(float_combined_tmp);
 }
 //void SD_mgr::sd_read_bytes(unsigned long location)
 //{
 //char float_combined[4];
 //SD_master.seek(location);
 //SD_master.readBytes(float_combined,4);
 //return return_float(float_combined);
 //}
 
 bool SD_mgr::save_settings_to_file(String path)
 {
	 DEBUG_STRING_print("SETTINGS->");

	 DEBUG_STRING_print(" FILE PATH SAVE:");
	 DEBUG_println(path);
	 

	

	 long start_add=0;
	 byte buff;


	 _update_trigger(0);

	 if(SD_master.available()==false)
	 {
		 if (SD.exists(path))
		 {
			 SD.remove(path);//prepišiž
		 }
	 }
	 else
	 return false;

	 if(SD_master.available()==false)
	 SD_master=SD.open(path,FILE_WRITE);
	 byte izpis;
	 byte procent=0;

	 DEBUG_STRING_print("START ADDRESS:");
	 DEBUG_println(start_add);

	 for(long x=start_add;x<start_add+4000;x++)
	 {
		 buff=EEPROM.read(x);
		 SD_master.write(buff);
		 

		 if(izpis==40)
		 {
			 procent++;
			 _update_trigger(procent);
			 // DEBUG_println();
			 izpis=0;
		 }
		 izpis++;
		 
	 }

	 DEBUG_STRING_print("file size:");
	 DEBUG_println(SD_master.size());
	 SD_master.close();
	 return true;


 }
 bool SD_mgr::load_settings(String path)
 {
	 DEBUG_STRING_print("PROFILE->");

	 DEBUG_STRING_print(" FILE PATH LOAD:");
	 DEBUG_println(path);
	 // id_profile=2;

	 
	 long start_add=0;
	 long end_add=start_add+4000;
	 
	 byte buff;
	 
	 
	 
	 if(SD_master.available()==false)
	 {
		 if (SD.exists(path))
		 {
			 DEBUG_STRING_println("OBSTAJA FAJL!");
			 SD_master=SD.open(path,FILE_READ);
			 // if(SD_master.size()!=12000)
			 // return false;
		 }
		 else
		 DEBUG_STRING_println("NE OBSTAJA FAJL!");
	 }
	 
	 
	 DEBUG_STRING_print("file size:");
	 DEBUG_println(SD_master.size());

	 // byte buffer[120];
	 byte count=0;
	 byte buff_min;
	 byte izpis;
	 byte procent=0;
	 
	 if(SD_master.size()!=4000)
	 {
		 DEBUG_print(SD_master.size());
		 DEBUG_STRING_println(" -size FAJL!");
		 SD_master.close();
		 return true;
	 }
	 
	 
	 // while (SD_master.available())
	 for(long i=0;i<SD_master.size();i++)
	 {
		 // DEBUG_STRING_print("current ");
		 
		 
		 if(count==40)
		 {
			 procent++;
			 _update_trigger(procent);
			 
			 
			 // exEEPROM.writen(start_add-count,buffer,count);
			 count=0;
		 }
		 
		 buff_min=SD_master.read();
		 //buffer[count]=buff_min;
		 
		 //exEEPROM.write(start_add,buff_min);
		 EEPROM.write(start_add,buff_min);
		 DEBUG_println(start_add);
		 // DEBUG_print_HEX(buff_min);
		 // DEBUG_STRING_print(" ");
		 
		 if(izpis==20)
		 {
			 //	 DEBUG_println();
			 izpis=0;
		 }
		 
		 
		 count++;
		 start_add++;
		 izpis++;
		 
		 
	 }

	 
	 DEBUG_STRING_print("end file ");
	 DEBUG_println(start_add);
	 
	 SD_master.close();
	 return true;
 }
 bool SD_mgr::save_profile_to_file(String path,byte id_profile)
 {
	 DEBUG_STRING_print("PROFILE->");
	 DEBUG_print(id_profile);
	 DEBUG_STRING_print(" FILE PATH SAVE:");
	 DEBUG_println(path);
	 
	 // id_profile=1;
	 if(id_profile<1)
	 return false;
	 
	 long start_add=(long)id_profile*12000;
	 byte buff;
	 
	 //DEBUG_STRING_print("aval ");
	 //DEBUG_println(SD_master.available());
	 //DEBUG_println(start_add);
	 //DEBUG_println(start_add*2);
	 
	 _update_trigger(0);
	 
	 if(SD_master.available()==false)
	 {
		 if (SD.exists(path))
		 {
			 SD.remove(path);//prepišiž
		 }
	 }
	 else
	 return false;
	 
	 if(SD_master.available()==false)
	 SD_master=SD.open(path,FILE_WRITE);
	 byte izpis;
	 byte procent;
	 
	 DEBUG_STRING_print("START ADDRESS:");
	 DEBUG_println(start_add);
	 
	 for(long x=start_add;x<start_add+12000;x++)
	 {
		 buff=exEEPROM.read(x);
		 SD_master.write(buff);
		 
		 // DEBUG_print_HEX(buff);
		 // DEBUG_STRING_print(" ");
		 if(izpis==120)
		 {
			 procent++;
			 _update_trigger(procent);
			 // DEBUG_println();
			 izpis=0;
		 }
		 izpis++;
		 
	 }

	 DEBUG_STRING_print("file size:");
	 DEBUG_println(SD_master.size());
	 SD_master.close();
	 return true;
	 SD_master.close();
	 return true;
 }
 
 bool SD_mgr::load_profile(String path,byte id_profile)
 {
	 bool blank_file=false;
	 DEBUG_STRING_print("PROFILE->");
	 DEBUG_print(id_profile);
	 DEBUG_STRING_print(" FILE PATH LOAD:");
	 DEBUG_println(path);
	 // id_profile=2;
	 if(id_profile<1)
	 return false;
	 
	 long start_add=(long)id_profile*12000;
	 long end_add=(long)start_add+12000;
	 
	 byte buff;
	 
	 DEBUG_STRING_print("data ");
	 DEBUG_println(id_profile);
	 DEBUG_println(start_add);
	 DEBUG_println(end_add);
	 
	 if(SD_master.available()==false)
	 {
		 if (SD.exists(path))
		 {
			 DEBUG_STRING_println("OBSTAJA FAJL!");
			 SD_master=SD.open(path,FILE_READ);
			 blank_file=false;
			 // if(SD_master.size()!=12000)
			 // return false;
		 }
		 else
		 {
			 DEBUG_STRING_println("NE OBSTAJA FAJL!");
			 blank_file=true;
		 }
		 
	 }
	 
	 DEBUG_STRING_print("START ADDRESS:");
	 DEBUG_println(start_add);
	 DEBUG_STRING_print("file size:");
	 DEBUG_println(SD_master.size());

	 byte buffer[24];
	 byte count=0;
	 byte buff_min;
	 byte izpis;
	 byte procent=0;
	 
	 
	 // while (SD_master.available())
	 calculate_free_RAM(123);
	 if(blank_file==true)
	 {
		 DEBUG_STRING_print("clear mem from");
		 DEBUG_print(start_add);
		 for(long i=0;i<12000;i++)
		 {
			 if(count==24)
			 {
				 izpis++;
				 //procent++;
				 if(izpis==5)
				 {
					 procent++;
					 _update_trigger(procent);
					 izpis=0;
				 }
				 
				 
				 //  DEBUG_println(start_add-count);
				 exEEPROM.writen(start_add-count,buffer,count);
				 count=0;
			 }
			 
			 buffer[count]=255;
			 //  exEEPROM.write(start_add, 255);
			 //exEEPROM.writen(start_add-count,buffer,count);
			 count++;
			 start_add++;
		 }
		 DEBUG_STRING_print(" to ");
		 DEBUG_println(start_add);
	 }
	 else
	 {
		 DEBUG_STRING_print("write mem from");
		 DEBUG_print(start_add);
		 
		 for(long i=0;i<SD_master.size();i++)
		 //	 for(long i=0;i<50;i++)
		 {
			 // DEBUG_STRING_print("current ");
			 
			 
			 
			 
			 buff_min=SD_master.read();
			 buffer[count]=buff_min;
			 
			 // exEEPROM.write(start_add,buff_min);
			 //DEBUG_println(start_add);
			 // DEBUG_print_HEX(buff_min);
			 // DEBUG_print_HEX(buff_min);
			 // DEBUG_STRING_print(" ");
			 
			 count++;
			 start_add++;
			 
			 if(count==24)
			 {
				 izpis++;
				 //procent++;
				 if(izpis==5)
				 {
					 procent++;
					 _update_trigger(procent);
					 izpis=0;
				 }
				 
				 
				 DEBUG_println(start_add-count);
				 exEEPROM.writen(start_add-count,buffer,count);
				 count=0;
			 }
			 
			 
		 }
		 
		 DEBUG_STRING_print(" to ");
		 DEBUG_println(start_add);
		 
		 SD_master.close();
	 }
	 
	 
	 
	 return true;
 }