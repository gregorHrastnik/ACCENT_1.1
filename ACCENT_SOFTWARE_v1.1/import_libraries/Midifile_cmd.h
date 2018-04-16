/* 
* Midifile_cmd.h
*
* Created: 11.9.2017 15:25:07
* Author: Greg
*/


#ifndef __MIDIFILE_CMD_H__
#define __MIDIFILE_CMD_H__
#include "Arduino.h"

class Midifile_cmd
{
//variables
public:
String midi_cmd;
byte midi_cmd_length;
int midi_cmd_delta_time;
protected:
private:

//functions
public:
	Midifile_cmd();
	~Midifile_cmd();
protected:
private:
//	Midifile_cmd( const Midifile_cmd &c );
//	Midifile_cmd& operator=( const Midifile_cmd &c );

}; //Midifile_cmd

#endif //__MIDIFILE_CMD_H__
