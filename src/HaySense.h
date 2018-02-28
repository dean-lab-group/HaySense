#pragma once
/*
HaySense library by Markus Kreitzer
*/

// This will load the definition for common Particle variable types.
#include "Particle.h"
#include "FreqPeriodCounter.h"

// All my defs
#define BATTERY_PIN A5  //Power from HaySense feather.
#define MOISTURE_PIN D4 //Pin on feather where moisture frequency is read.
#define TEMPERATURE_PIN D5 // Pin on feather where temperature frequency is read.
#define SENSOR_POWER_PIN D6  //Power line for actual sensors
#define POWER_ON_DELAY 10 // Delay before sensors are powered on.
#define TIMER_PERIOD 1000 // One second in milis

// This is your main class that users will import into their application
class HaySense
{
public:
  HaySense();
  float get_temperature_freq(void);
  float get_moisture_freq(void);
  void power_on_sensors(void);
  void power_off_sensors(void);
  void counterISR();

private:
  //void detect_pulse(void);
  float get_battery_voltage(void);
};

class Converter
{
public:
  Converter(float *moist_constants, float *temp_constants);
  float GetMoisture(float moist_hz, float temp_hz);
  float GetTemperature(float temp_hz);

private:
  float *moisture_constants;
  float *temperature_constants;
  float temperature_hz;
  float y_0();
  float y_100();
  float slope_prime(void);
  float intercept_prime(void);
};
