// What is the purpose of this script?
/* @description: Read an analogue input and print to the serial port
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
double d_lastUpdate;         // Variable to remember when we last updated the PWM (in mS)
const double d_period = 100; // How long should we wait between updates (in mS)
const int i_inputPin = A0;   // A0 is defined in the core library - We are using it as an input pin
int i_analogValue;           // Somewhere to store the value we read on the inputPin
// The code that runs when you hit start / restart goes here

void setup()
{
  pinMode(i_inputPin,INPUT);       // Set the pin mode correctly
  int i_analogValue = 0;           // Make sure we don't read random memory value to start with
  Serial.begin(9600);              // Setup the serial port at a baud rate of 9600
  Serial.println("Script starts"); // Send us some information to know the program is running  
  
}


// It just goes on, and on, and on, and on....
void loop()
{
    if(millis()-d_lastUpdate > d_period)
    {
    i_analogValue = analogRead(i_inputPin);    // Read the input from the ADC
    Serial.print("Sensor value: ");            // Send the information to the serial terminal
    Serial.println(i_analogValue);
    d_lastUpdate = millis();                   // Update the timer
    }
}
