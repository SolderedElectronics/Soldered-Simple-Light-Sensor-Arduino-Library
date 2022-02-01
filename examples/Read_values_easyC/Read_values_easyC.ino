/**
 **************************************************
 *
 *  @file        Read_values_easyC.ino
 *  @brief       Example for using the digital and analog read functions for Simple fire sensor with easyC
 *
 *
 * 	product: www.solde.red/333077
 *
 *  @authors     Goran Juric for Soldered.com
 ***************************************************/

#include "Simple-light-sensor-easyC-SOLDERED.h"

#define TRESHHOLD 255

// Declare the sensor object
SimpleLightSensor sensor;

void setup()
{
  // Initialize the serial communication via UART
  Serial.begin(115200);

  // Initialize the sensor
  sensor.begin();

  // If different microcontroller with different bit width
  // is used, it should be set using this function
  sensor.setADCWidth(10);
}

void loop()
{

  Serial.print("IR light sensor reading: "); // Print information message
  Serial.println(sensor.getValue());  // Prints percent value of slider potentiometer

  if (sensor.getValue() < TRESHOLD)
  {
    Serial.println("Fire is detected!!");
  }

  else
  {
    Serial.println("Fire is not detected.");
  }
  delay(1000);

}
