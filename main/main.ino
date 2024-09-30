
#include <cstring>
#include <cstdint>
#include <SD.h>
#include <Wire.h>

#include "sd_controller.h"

#define I2C_ADDRESS 0x13

sd_controller extruder_sd;

void setup()
{
    
    Serial.begin(9600);
    
    Wire.begin(I2C_ADDRESS);       
    Wire.onReceive(i2c_receive_event_handler);
    Wire.onRequest(i2c_request_event_handler);
    
    extruder_sd.uptime_counter_begin_ms_count();
    extruder_sd.initialize();
}

void loop()
{
    extruder_sd.uptime_counter_update();
}


void i2c_receive_event_handler(int count)
{
  
}

void i2c_request_event_handler()
{

}
