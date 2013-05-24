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
// No header libraries required

// Create global variables here
int i_intensity;             // Variable storing the current intensity of the LED
double d_lastUpdate;         // Variable to remember when we last updated the PWM (in mS)
const double d_period = 100; // How long should we wait between updates (in mS)
const int i_ledPin = 6;      // Which pin number we are using NB only some pins can do PWM
const int i_inputPin = A0;   // A0 is defined in the core library - We are using it as an input pin
int i_analogValue;           // Somewhere to store the value we read on the inputPin

// The code that runs when you hit start / restart goes here
void setup()
{
  i_intensity = 0;                    // Good practise to initialise a variable
  pinMode(i_ledPin,OUTPUT);           // Set the pin mode correctly
  analogWrite(i_ledPin,i_intensity);  // Set the output to 0
  pinMode(i_inputPin,INPUT);          // Set the pin mode correctly
  Serial.begin(9600);                 // Setup the serial port at a baud rate of 9600
  Serial.println("Script starts");    // Send us some information to know the program is running  
  int i_analogValue = 0;              // Initialize the variable
}


// It just goes on, and on, and on, and on....
void loop()
{
    if(millis()-d_lastUpdate > d_period)           // Check if we need to update
    {
    readSensor();                                  // Call the function to read the ADC
    updateDisplay();                               // Call the function to update the LED output
  
    d_lastUpdate = millis();                       // Update the timer
    }
}

void readSensor()
{
    i_analogValue = analogRead(i_inputPin);        // Read the input from the ADC
    Serial.print("Sensor value: ");                // Send the information to the serial terminal
    Serial.println(i_analogValue);                 // Send us the data
}

void updateDisplay()
{
    i_intensity = map(i_analogValue,0,1023,0,255); // Analogue read value is 1023, so we need to reduce it to 255
    analogWrite(i_ledPin,i_intensity);             // Update the brightness
}
