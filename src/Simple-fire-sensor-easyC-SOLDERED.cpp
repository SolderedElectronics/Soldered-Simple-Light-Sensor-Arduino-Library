/**
 **************************************************
 *
 * @file        Simple-fire-sensor-easyC-SOLDERED.cpp
 * @brief       Example functions to overload in base class.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Goran Juric @ soldered.com
 ***************************************************/


#include "Simple-fire-sensor-easyC-SOLDERED.h"

/**
 * @brief                   Default constructor.
 *
 */
SimpleFireSensor::SimpleFireSensor()
{
}

/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Pin on which is sensor connected.
 */
SimpleFireSensor::SimpleFireSensor(int _pin)
{
    pin = _pin;
    native = 1;
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize sensor specific.
 */
void SimpleFireSensor::initializeNative()
{
    pinMode(pin, INPUT);
}

/**
 * @brief       Function for reading value of IR light sensor
 *
 * @return      value of IR light sensor
 */
uint16_t SimpleFireSensor::getValue()
{
    if (!native)
    {
        readRegister(ANALOG_READ_REG, raw, 2 * sizeof(uint8_t));
        return raw[0] | (raw[1]) << 8;
    }
    return analogRead(pin);
}

/**
 * @brief       Function for calculating resistance of IR light sensor
 *
 * @return      resistance of IR light sensor
 */
float SimpleFireSensor::getResistance()
{
    uint16_t temp = getValue();
    if (temp != 0)
    {
        return R * (ADC_width - temp) / (float)temp;
    }
    return 0;
}

/**
 * @brief       Function for setting ADC bit width of microcontroller
 *
 * @param       uint8_t _ADC_width ADC bit width in bits
 */
void SimpleFireSensor::setADCWidth(uint8_t _ADC_width)
{
    ADC_width = pow(2, _ADC_width) - 1;
}
