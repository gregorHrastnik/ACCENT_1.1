#ifndef SPIPRM_h
#define SPIPRM_h

#include "Arduino.h"

class SPIPRM{
	public:
	SPIPRM(uint16_t pagesize, uint32_t totalsize, uint8_t cspin);
	void SPIset();
	void writeStart(uint16_t addr);
	void writeData(uint8_t data);
	void endCmd();
	void write16(uint16_t data);
	void readStart(uint16_t addr);
	uint8_t readData();
	uint16_t read16();
	void wren() ;
	void rdid();
	void rdsr();

	uint16_t lastPage;
	uint32_t pointer;
	//????ret;

	private:

	uint16_t _pagesize;
	uint32_t _highestaddr;
	uint8_t _cspin;

};

#endif