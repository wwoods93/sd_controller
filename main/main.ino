
#include <cstring>
#include <cstdint>
#include <SD.h>
#include <Wire.h>

#include "sd_controller.h"

#define I2C_ADDRESS 0x13
#define I2C_BUFFER_SIZE     32U
#define I2C_TX_SIZE         2U

#define I2C_STOP      1U
#define I2C_RESTART   0U

uint8_t i2c_buffer_index = 0U;
uint8_t i2c_bytes_received = 0U;
uint8_t i2c_request_received = 0U;
uint8_t i2c_tx_buffer[I2C_BUFFER_SIZE];
uint8_t i2c_rx_buffer[I2C_BUFFER_SIZE];

union float_to_bytes
{
    uint8_t bytes[4];
    float value;
};

union uint32_to_bytes
{
    uint8_t bytes[4];
    uint32_t value;
};


union float_to_bytes float_converter;
union uint32_to_bytes int_converter;


sd_controller extruder_sd;

void setup()
{
    
    Serial.begin(9600);

    i2c_tx_buffer[0] = 0xAA;
    i2c_tx_buffer[1] = 0xBB;
    Wire.begin(I2C_ADDRESS);       
    Wire.onReceive(i2c_receive_event_handler);
    Wire.onRequest(i2c_request_event_handler);
    
    extruder_sd.uptime_counter_begin_ms_count();
    extruder_sd.initialize();
}

void loop()
{
    extruder_sd.uptime_counter_update();
    if (i2c_bytes_received == 1U)
    {
        Serial.print("first 10 rx bytes:");
        for (uint8_t index = 0U; index < 10U; ++index)
        {
           Serial.print("\t");
           Serial.print(i2c_rx_buffer[index]);
           i2c_rx_buffer[index] = 0;
        }
        Serial.println();
        i2c_bytes_received = 0U;
    }
    if (i2c_request_received == 1U)
    {
        i2c_request_received = 0U;
    }
}


void i2c_receive_event_handler(int count)
{
    i2c_buffer_index = 0U;
    while (Wire.available())
    {
        i2c_rx_buffer[i2c_buffer_index++] = Wire.read();
    }
    i2c_bytes_received = 1U;
}

void i2c_request_event_handler()
{
    Wire.beginTransmission(0x10);
    Wire.write(i2c_tx_buffer, I2C_TX_SIZE);
    Wire.endTransmission(I2C_STOP);
    i2c_request_received = 1U;
}
