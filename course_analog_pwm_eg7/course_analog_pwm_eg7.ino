// What is the purpose of this script?
/* @description: Read an analogue input and print to the serial port
*  and then to the LED PWM output
*  This example uses functions
*  This is a demonstration script for a course being run on Arduino
*  
*
*
*/

// @author: William Gebers
// @created: 24-05-2013
// @license: GNU Public License


// Include header libraries here
#include "Display.h"
#include "Sound.h"

// Create global variables here
double d_lastUpdate;         // Variable to remember when we last updated the PWM (in mS)
double d_period;       // How long should we wait between updates in mS

Sound sound(A0);             // Create an instance of the Sound measurement object
Display disp(6);          // Create an instance of the display object

// The code that runs when you hit start / restart goes here
void setup()
{
  d_period = 100;
  Serial.begin(9600);                 // Setup the serial port at a baud rate of 9600
  Serial.println("Script starts");    // Send us some information to know the program is running  
}


// It just goes on, and on, and on, and on....
void loop()
{
    if(millis()-d_lastUpdate > d_period)           // Check if we need to update
    {
    sound.read();                                  // Call the function to read the ADC
    sound.serial_print();
    disp.set(sound.getValue());
    disp.update();
    d_lastUpdate = millis();                       // Update the timer
    }
}

