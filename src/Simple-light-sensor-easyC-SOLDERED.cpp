/**
 **************************************************
 *
 * @file        Simple-light-sensor-easyC-SOLDERED.cpp
 * @brief       Example functions to overload in base class.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Goran Juric, Karlo Leksic for soldered.com
 ***************************************************/


#include "Simple-light-sensor-easyC-SOLDERED.h"

/**
 * @brief                   Default constructor.
 *
 */
SimpleLightSensor::SimpleLightSensor()
{
}

/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Pin on which is sensor connected.
 */
SimpleLightSensor::SimpleLightSensor(int _pin)
{
    pin = _pin;
    native = 1;
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize sensor specific.
 */
void SimpleLightSensor::initializeNative()
{
}

/**
 * @brief       Function for reading raw value of LDR
 *
 * @return      Raw value of LDR (0 - 1023)
 */
uint16_t SimpleLightSensor::getRawValue()
{
    if (!native)
    {
        // Read bytes of raw potentiometer data
        char data[2];
        readData(data, 2);

        // Convert it to uint16_t
        uint16_t value = 0;
        value = *(uint16_t *)data;

        // Return converted value
        return value;
    }
    return analogRead(pin);
}

/**
 * @brief       Function for reading value of LDR
 *
 * @return      Value of LDR in percent (0 - 100%)
 */
float SimpleLightSensor::getValue()
{
    return (getRawValue() / float(1023) * 100);
}

/**
 * @brief       Function for calculating resistance of LDR
 *
 * @return      Resistance of LDR
 */
float SimpleLightSensor::getResistance()
{
    uint16_t temp = getRawValue();
    if (temp != 0)
    {
        return R * (temp / (float)(ADC_width - temp));
    }
    return 0;
}

/**
 * @brief       Function for calculating value of light intensity in Lux
 *
 * @return      light intensity in lux
 */
float SimpleLightSensor::getLux()
{
    uint16_t temp = getResistance();
    if (temp != 0)
    {
        return 6750000.0 * pow(temp, -1.4);
    }
    return 0;
}

/**
 * @brief       Function for setting ADC bit width of microcontroller
 *
 * @param       uint8_t _ADC_width ADC bit width in bits
 */
void SimpleLightSensor::setADCWidth(uint8_t _ADC_width)
{
    ADC_width = pow(2, _ADC_width) - 1;
}

/**
 * @brief       Function to set threshold value to turn on the LED
 *
 * @param       float _threshold value in %
 */
void SimpleLightSensor::setThreshold(float _threshold)
{
    // Check if the threshold is the proper value
    if (_threshold < 0 || _threshold > 100)
    {
        return;
    }

    // Convert percentage threshold to raw value and send it
    uint16_t rawThreshold = _threshold * 0.01 * 1024;
    setRawThreshold(rawThreshold);
}

/**
 * @brief       Function to set raw threshold value to turn on the LED
 *
 * @param       uint16_t _treshold raw value (0 - 1023)
 */
void SimpleLightSensor::setRawThreshold(uint16_t _treshold)
{
    // Check if the threshold is the proper value
    if (_treshold < 0 || _treshold > 1023)
    {
        return;
    }

    // Convert raw threshold value into 2 bytes for sending
    uint8_t *rawThreshold = (uint8_t *)&_treshold;

    // Send raw threshold
    sendData(rawThreshold, 2);
}