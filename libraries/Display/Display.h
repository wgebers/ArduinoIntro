/* Display.h - Library to display PWM data through an LED
 * Created: 24-05-2013
 * Author: William Gebers
 * Contact: wgebers@gmail.com
 * License: GNU Public
 */ 
#ifndef Display_h
#define Display_h

#include "Arduino.h"

class Display
{
	private: 
		int _iValue;
		int _iPin;
	public:
		Display(int iPin);
		void set(int ivalue);
		void update();
};
#endif
