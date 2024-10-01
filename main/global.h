


// i2c packet format  | global id    | data size    | data type   | data byte 1     | data byte 2     | ...     | data byte n    | checksum   |
    

namespace global
{
  
    static constexpr uint8_t DATA_TYPE_UINT32                                 = 0x00;
    static constexpr uint8_t DATA_TYPE_FLOAT                                  = 0x01;
    static constexpr uint8_t DATA_TYPE_STRING                                 = 0x02;

    static constexpr uint8_t SPI_ERROR                                        = 0x00;
    static constexpr uint8_t I2C_ERROR                                        = 0x01;
    static constexpr uint8_t UART_ERROR                                       = 0x02;
    static constexpr uint8_t ICAP_ERROR                                       = 0x03;
    static constexpr uint8_t OCMP_ERROR                                       = 0x04;
    static constexpr uint8_t GPIO_ERROR                                       = 0x05;

    static constexpr uint8_t MAIN_CONTROLLER_TIME_STAMP                       = 0x00;
    
    static constexpr uint8_t ZONE_1_TEMP                                      = 0x01;
    static constexpr uint8_t ZONE_2_TEMP                                      = 0x02;
    static constexpr uint8_t ZONE_3_TEMP                                      = 0x03;
    
    static constexpr uint8_t ZONE_1_POWER                                     = 0x04;
    static constexpr uint8_t ZONE_2_POWER                                     = 0x05;
    static constexpr uint8_t ZONE_3_POWER                                     = 0x06;
    
    static constexpr uint8_t STEPPER_MOTOR_RPM                                = 0x07;
    
    static constexpr uint8_t I2C_PACKETS_FROM_COM_TO_DISP_1_SENT              = 0x08;
    static constexpr uint8_t I2C_PACKETS_FROM_COM_TO_DISP_1_RECEIVED          = 0x09;

    static constexpr uint8_t I2C_PACKETS_FROM_COM_TO_DISP_2_SENT              = 0x0A;
    static constexpr uint8_t I2C_PACKETS_FROM_COM_TO_DISP_2_RECEIVED          = 0x0B;

    static constexpr uint8_t I2C_PACKETS_FROM_COM_TO_SD_SENT                  = 0x0C;
    static constexpr uint8_t I2C_PACKETS_FROM_COM_TO_SD_RECEIVED              = 0x0D;
    
    static constexpr uint8_t I2C_PACKETS_FROM_DISP_1_TO_COM_SENT              = 0x0E;
    static constexpr uint8_t I2C_PACKETS_FROM_DISP_1_TO_COM_RECEIVED          = 0x0F;

    static constexpr uint8_t I2C_PACKETS_FROM_DISP_2_TO_COM_SENT              = 0x10;
    static constexpr uint8_t I2C_PACKETS_FROM_DISP_2_TO_COM_RECEIVED          = 0x11;
    
    static constexpr uint8_t I2C_PACKETS_FROM_SD_TO_COM_REQUESTS_SENT         = 0x12;
    static constexpr uint8_t I2C_PACKETS_FROM_COM_TO_SD_REQUESTS_FULFILLED    = 0x13;
    
    static constexpr uint8_t SPI_PACKETS_FROM_MAIN_TO_COM_SENT                = 0x14;
    static constexpr uint8_t SPI_PACKETS_FROM_MAIN_TO_COM_RECEIVED            = 0x15;

    static constexpr uint8_t SPI_PACKETS_FROM_MAIN_TO_RTD_REQUESTS_SENT       = 0x16;
    static constexpr uint8_t SPI_PACKETS_FROM_RTD_TO_MAIN_REQUESTS_FULFILLED  = 0x17; 
    
    static constexpr uint8_t MAIN_CONTROLLER_EVENT                            = 0x18;
    static constexpr uint8_t MAIN_CONTROLLER_ERROR                            = 0x19;
    static constexpr uint8_t COM_CONTROLLER_EVENT                             = 0x1A;
    static constexpr uint8_t COM_CONTROLLER_ERROR                             = 0x1B;
    static constexpr uint8_t MOTOR_CONTROLLER_EVENT                           = 0x1C;
    static constexpr uint8_t MOTOR_CONTROLLER_ERROR                           = 0x1D;
    static constexpr uint8_t DISPLAY_1_CONTROLLER_EVENT                       = 0x1E;
    static constexpr uint8_t DISPLAY_1_CONTROLLER_ERROR                       = 0x1F;
    static constexpr uint8_t DISPLAY_2_CONTROLLER_EVENT                       = 0x20;
    static constexpr uint8_t DISPLAY_2_CONTROLLER_ERROR                       = 0x21; 



      
    
}
