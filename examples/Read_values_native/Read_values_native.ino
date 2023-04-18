/**
 **************************************************

   @file        Read_values_native.ino
   @brief       Example for using the digital and analog read functions for Simple Light sensor

                For this example, you will need any Dasduino board and a Simple light sensor.
                Don't have Dasduino? Get it here: https://soldered.com/categories/dasduino-arduino/dasduino-boards/ 

                This example will show you how to get the values from the sensor.
                Open the Serial Monitor at 115200 baud rate to see what's happening.

    product: www.solde.red/333078

   @authors     Goran Juric for Soldered.com
 ***************************************************/

// Connecting diagram
//
// Breakout      Arduino
// |-------------|
// D0------------D9
// A0------------A0
// GND-----------GND
// VCC-----------5V

// Include Soldered library for Simple sensor
// If you don't have a library, get it here:
// https://github.com/SolderedElectronics/Soldered-Simple-Light-Sensor-Arduino-Library
#include "Simple-light-sensor-easyC-SOLDERED.h"

#define ANALOG_PIN  A0 // Pin for analog read
#define DIGITAL_PIN 9  // Pin for digital read

// Declare the sensor object and set pin on which sensor is connected
SimpleLightSensor sensor(ANALOG_PIN);

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
    Serial.print("Resistance of a LDR: "); // Print information message
    Serial.print(sensor.getResistance());  // Prints percent value of light sensor
    Serial.println(" Ohms.");              // Print information message

    Serial.print("Light intensity: "); // Print information message
    Serial.print(sensor.getLux());     // Prints raw value of light sensor
    Serial.println(" lux.");           // Print information message

    // You can adjust treshold light intesity using potentiometer on breakout board
    Serial.println(digitalRead(DIGITAL_PIN) ? "Treshold light intesity is past." : "Treshold intensity is not past.");

    // Wait a bit before next reading
    delay(200);
}
