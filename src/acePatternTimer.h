/*
 Name:		acePatternTimer.h
 Created:	11/30/2021 6:03:16 AM
 Author:	Korisnik
 Editor:	http://www.visualmicro.com
*/

#ifndef _acePatternTimer_h
#define _acePatternTimer_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


class acePatternTimer
{

	protected:

		byte step_id = 0;

		bool is_active = false;

		unsigned long since_last_step = 0;
		unsigned long last_step_ms = 0;
		unsigned long this_step_ms = 0;
		unsigned long _step_ms = 0;
	public:

		byte pattern = 0x00000000;

		int step_delay_ms = 100;

		void restart(bool IsActive) 
		{
			is_active = IsActive;
			since_last_step = 0;
			last_step_ms = micros();
			step_id = 0;
		}

		void setActive(bool IsActive) 
		{
			is_active = IsActive;
		}
		

		/* Returns value at curent step index */
		uint8_t read() 
		{
			return bitRead(pattern, step_id);
		}

		/* Returns true if the step index was moved */
		bool loop() 
		{
			
			if (!is_active) return false;

			this_step_ms = micros();

			if (this_step_ms < last_step_ms) // managing the overflow situation
			{
				last_step_ms = this_step_ms;
				return false;  
			}

			_step_ms = last_step_ms - this_step_ms;

			if (_step_ms > step_delay_ms)
			{
				last_step_ms = this_step_ms;
				step_id++;
				return true;
			}
			else {
				return false;
			}
			
		}
};


#endif

