// What is the purpose of this script?
/* @description: Drive an LED with Pulse Width Modulation
*  This is a demonstration script for a course being run on Arduino
*
*
*
*/

// @author: William Gebers
// @created: 24-05-2013
// @license: GNU Public License


// Include header libraries here
// No header libraries required

// Create global variables here
int i_intensity;         // Variable storing the current intensity of the LED
const int i_ledPin = 6;  // Which pin number we are using NB only some pins can do PWM

// The code that runs when you hit start / restart goes here

void setup()
{
  i_intensity = 0;                     // Good practise to initialise a variable
  pinMode(i_ledPin,OUTPUT);            // Set the pin mode correctly
  analogWrite(i_ledPin,i_intensity);   // Set the output to 0
}


// It just goes on, and on, and on, and on....
void loop()
{
    analogWrite(i_ledPin,i_intensity); // Update the brightness
    delay(10);                         // Wait 10 milliseconds
    i_intensity++;                     // Increase the intensity
}
