// aceMultiPatternPinControl.h

#ifndef _ACEMULTIPATTERNPINCONTROL_h
#define _ACEMULTIPATTERNPINCONTROL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "acePatternTimer.h"

class aceMultiPatternPinControl 
{
 protected:


 public:

	 acePatternTimer pattern_timer;

	 void setup() 
	 {

	 }

	 byte target_pin = 0;
	 byte patterns[8] = 
	 {
		 0x11110000, // pattern 0
		 0x11000000, // pattern 1
		 0x11001100, // pattern 2
		 0x11111100, // pattern 3
		 0x10101010, // pattern 4
		 0x11111110, // pattern 5
		 0x11101010, // pattern 6
		 0x11111111, // pattern 7
	 };

	 void selectPattern(byte _index) 
	 {
		 if (_index > 7) { _index = 7; }
		 pattern_timer.pattern = patterns[_index];
	 }

	 
	 void loop() {
		 
		 if (pattern_timer.loop()) 
		 {
			 digitalWrite(target_pin, pattern_timer.read());
			 //
		 }
		 else {
			 //
		 }
		 
	 }
};

//extern AceMultiPatternPinControlClass AceMultiPatternPinControl;

#endif

