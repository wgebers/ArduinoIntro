#include "Arduino.h"
#include "Sound.h"

Sound::Sound(int ipin)
{
	pinMode(ipin, INPUT);
	_ipin = ipin;
}

void Sound::read()
{
	_ivalue = analogRead(_ipin);
}

int Sound::getValue()
{
	return _ivalue;
}
void Sound::serial_print()
{
	Serial.print("Sensor value: ");
	Serial.println(_ivalue);
}
