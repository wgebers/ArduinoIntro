#include "Arduino.h"
#include "Display.h"

Display::Display(int ipin)
{
	pinMode(ipin, OUTPUT);
	_iPin = ipin;
}

void Display::update()
{
	int iIntensity = map(_iValue,0,1023,0,255);
	analogWrite(iIntensity, _iPin);
}

void Display::set(int iValue)
{
	_iValue = iValue;
}
