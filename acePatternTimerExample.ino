/*
 Name:		acePatternTimerExample.ino
 Created:	11/30/2021 6:14:22 AM
 Author:	Korisnik
*/

#include "aceMultiPatternPinControl.h"
#include "src/acePatternTimer.h"

acePatternTimer led_pattern_timer;

// the setup function runs once when you press reset or power the board
void setup() {

	led_pattern_timer.pattern = 0x00110011;
	led_pattern_timer.restart(true);
}

// the loop function runs over and over again until power down or reset
void loop() 
{

	if (led_pattern_timer.loop()) {
		digitalWrite(PIN6, led_pattern_timer.read());
	}

	delay(1);
}
