/* Sound.h - LIbrary for reading a microphone input
 * Created: 24-05-2013
 * Author: William Gebers
 * Contact: wgebers@gmail.com
 * License: GNU Public
 */

#ifndef Sound_h
#define Sound_h

#include "Arduino.h"

class Sound
{
	private:
		int _ipin;
		int _ivalue;
	public:
		Sound(int pin);
		void read();
		int getValue();
		void serial_print();
};

#endif
