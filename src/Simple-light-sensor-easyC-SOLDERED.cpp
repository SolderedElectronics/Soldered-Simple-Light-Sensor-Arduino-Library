/**
 **************************************************
 *
 * @file        Simple-light-sensor-easyC-SOLDERED.cpp
 * @brief       Example functions to overload in base class.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Goran Juric @ soldered.com
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
 * @brief       Function for reading value of LDR
 *
 * @return      value of LDR
 */
uint32_t SimpleLightSensor::getValue()
{
    if (!native)
    {
        readRegister(ANALOG_READ_REG, raw, 2 * sizeof(uint8_t));
        return raw[0] | (raw[1]) << 8;
    }
    return analogRead(pin);
}

/**
 * @brief       Function for calculating resistance of LDR
 *
 * @return      resistance of LDR
 */
float SimpleLightSensor::getResistance()
{
    uint16_t temp = getValue();
    if (temp != 0)
    {
        return R * temp / (float)(ADC_width - temp);
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
