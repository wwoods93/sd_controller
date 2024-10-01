
#include <cstdint>
#include <cstring>
#include <stdio.h>
#include <SD.h>

#include "global.h"
#include "sd_controller.h"


void sd_controller::initialize()
{

    write_buffer.reserve(BUFFER_SIZE);
    
    if (SD.begin(SD_CARD_CHIP_SELECT) == false)
    {
        Serial.println("sd card access failed at initialization");
    }
    
    SD.remove(FILE_NAME_SD_LOG);
    SD.remove(FILE_NAME_MC_LOG);
    SD.remove(FILE_NAME_COM_LOG);
    SD.remove(FILE_NAME_MTR_LOG);
    
    sd_log = SD.open(FILE_NAME_SD_LOG, FILE_WRITE);

    if (sd_log)
    {
        sd_log.write(FILE_NAME_SD_LOG, FILE_NAME_LEN_SD_LOG);
        sd_log.write("\n\n", 2); 
        sd_log.close(); 
        sd_log_append(SD_LOG_EVENT, SD_CREATE_SD_LOG_EVENT_TEXT); 
        Serial.println("sd_log.txt created!");
        
    }
    else
    {
        Serial.println("failed to create SD_LOG.TXT");
    }

    mc_log = SD.open(FILE_NAME_MC_LOG, FILE_WRITE);

    if (mc_log)
    {
        mc_log.write(FILE_NAME_MC_LOG, FILE_NAME_LEN_MC_LOG);
        mc_log.write("\n\n", 2);
        mc_log.close();
        sd_log_append(SD_LOG_EVENT, SD_CREATE_MC_LOG_EVENT_TEXT);
        Serial.println("mc_log.txt created!");
    }
    else
    {
        sd_log_append(SD_LOG_ERROR, SD_CREATE_MC_LOG_ERROR_TEXT);
    }


    com_log = SD.open(FILE_NAME_COM_LOG, FILE_WRITE);

    if (com_log)
    { 
        com_log.write(FILE_NAME_COM_LOG, FILE_NAME_LEN_COM_LOG);
        com_log.write("\n\n", 2);
        com_log.close();
        sd_log_append(SD_LOG_EVENT, SD_CREATE_COM_LOG_EVENT_TEXT);
        Serial.println("com_log.txt created!");
    }
    else
    {
        sd_log_append(SD_LOG_ERROR, SD_CREATE_COM_LOG_ERROR_TEXT);
    }

    mtr_log = SD.open(FILE_NAME_MTR_LOG, FILE_WRITE);

    if (mtr_log)
    { 
        mtr_log.write(FILE_NAME_MTR_LOG, FILE_NAME_LEN_MTR_LOG);
        mtr_log.write("\n\n", 2);
        mtr_log.close();  
        sd_log_append(SD_LOG_EVENT, SD_CREATE_MTR_LOG_EVENT_TEXT);
        Serial.println("mtr_log.txt created!");        
    }
    else
    {
        sd_log_append(SD_LOG_ERROR, SD_CREATE_MTR_LOG_ERROR_TEXT);
    }

}

void sd_controller::sd_log_append(const char* arg_entry_type, const char* arg_event_description)
{
    uint32_t time_stamp = uptime_counter_get_count();

    char buffer_tmp[WRITE_SIZE_MAX];
    sprintf(buffer_tmp, "%s%s%d%s%s%s", arg_entry_type, SD_LOG_TIME_STAMP_LABEL, time_stamp, ARROW, arg_event_description, NEWLINE);
    write_buffer += buffer_tmp;
    sd_log = SD.open(FILE_NAME_SD_LOG, FILE_WRITE);
    if (sd_log)
    {
        sd_log.write(write_buffer.c_str(), write_buffer.length());
        sd_log.close();
        write_buffer.remove(0);
    }
    
}

void sd_controller::uptime_counter_begin_ms_count()
{
    uptime_counter_update_time = millis();
}

void sd_controller::uptime_counter_update()
{
    if (millis() - uptime_counter_update_time > uptime_counter_update_period)
    {
        ++uptime_count;
        uptime_counter_update_time = millis();
    }
}

uint32_t sd_controller::uptime_counter_get_count()
{
    return uptime_count;
}
