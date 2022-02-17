/**
 **************************************************
 *
 * @file        Simple-light-sensor-easyC-SOLDERED.h
 * @brief       Header file for sensor specific code.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Goran Juric @ soldered.com
 ***************************************************/

#ifndef _SIMPLE_LIGHT_SENSOR_EASYC_
#define _SIMPLE_LIGHT_SENSOR_EASYC_

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.hpp"
#include "math.h"

#define R 10000

class SimpleLightSensor : public SIMPLE_LIGHT_SENSOR_EASYC::EasyC
{
  public:
    SimpleLightSensor();
    SimpleLightSensor(int);
    uint32_t getValue(void);
    float getResistance(void);
    float getLux(void);
    void setADCWidth(uint8_t);

  protected:
    void initializeNative();

  private:
    int pin;
    uint16_t ADC_width = 1023;
    char raw[2];
};

#endif
