/**
 **************************************************

   @file        Read_values_easyC.ino
   @brief       Example for using the digital and analog read functions for Simple light sensor with easyC

                For this example, you will need any Dasduino board, a USB-c cable, a Simple light sensor with easyC, and easyC cable. 
                Don't have Dasduino? Get it here: https://soldered.com/categories/dasduino-arduino/dasduino-boards/ 
                Don't have easyC cable? Get it here: https://soldered.com/categories/easyc-2/easyc-cables-adapters/

                This example will show you how to set a threshold to LED and get values from the sensor.
                Open the Serial Monitor at 115200 baud rate to see the values.

    product: www.solde.red/333076

   @authors     Goran Juric, Karlo Leksic for Soldered.com
 ***************************************************/

// Include Soldered library for Simple sensor
// If you don't have a library, get it here: https://github.com/SolderedElectronics/Soldered-Simple-Light-Sensor-Arduino-Library
#include "Simple-light-sensor-easyC-SOLDERED.h"

// Declare the sensor object
SimpleLightSensor sensor;

void setup()
{
    // Initialize the serial communication via UART with 115200 baud rate
    // and it is needed to set same baud rate in serial monitor if it is used
    Serial.begin(115200);

    // Initialize the sensor
    // Start I2C communication on default address (0x30)
    sensor.begin();

    // If you want another I2C address, enter it in the bracket
    // You can set another I2C address (0x31 - 0x37) by changing address switches on the breakout
    // NOTE: You have to restart breakout to apply the address change by unplugging and plugging
    // the easyC or USB-c from the Dasduino 
    // sensor.begin(0x31);

    // Set threshold value to turn on the LED
    sensor.setThreshold(10); // (10%) or
    // sensor.setRawThreshold(100); // if you set threshold as raw value
}

void loop()
{
    Serial.print("Analog value of LDR: "); // Print information message
    Serial.print(sensor.getValue());       // Print percent value of the LDR
    Serial.print("% ");
    Serial.println(sensor.getRawValue()); // Print raw value of the LDR

    Serial.print("Resistance of a LDR: "); // Print information message
    Serial.print(sensor.getResistance());  // Prints percent value of light sensor
    Serial.println(" Ohms.");              // Print information message

    Serial.print("Light intensity: "); // Print information message
    Serial.print(sensor.getLux());     // Prints raw value of light sensor
    Serial.println(" lux.");           // Print information message
    Serial.println();

    // Wait a bit before next reading
    delay(200);
}
