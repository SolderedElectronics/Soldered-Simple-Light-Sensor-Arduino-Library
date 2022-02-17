/**
 **************************************************

   @file        Read_values_easyC.ino
   @brief       Example for using the digital and analog read functions for Simple light sensor with easyC


 	product: www.solde.red/333076

   @authors     Goran Juric for Soldered.com
 ***************************************************/

#include "Simple-light-sensor-easyC-SOLDERED.h"

// Declare the sensor object
SimpleLightSensor sensor;

void setup()
{
  // Initialize the serial communication via UART with 115200 baud rate
  //and it is needed to set same baud rate in serial monitor if it is used
  Serial.begin(115200);

  // Initialize the sensor for use
  sensor.begin();

}

void loop()
{
  Serial.print("Resistance of a LDR: "); // Print information message
  Serial.print(sensor.getResistance());  // Prints percent value of light sensor
  Serial.println(" Ohms.");              // Print information message

  Serial.print("Light intensity: "); // Print information message
  Serial.print(sensor.getLux());     // Prints raw value of light sensor
  Serial.println(" lux.");           // Print information message

  delay(1000);
}
