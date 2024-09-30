//
// sd_controller.h
//

#include <SD.h>
#include <cstring>
#include <cstdint>


class sd_controller
{
    public:
    
        void initialize();
        void uptime_counter_begin_ms_count();
        void uptime_counter_update();

    private:

        static constexpr uint8_t  SD_CARD_CHIP_SELECT             = 4U;
        static constexpr uint16_t WRITE_SIZE_MAX                  = 64U;
        static constexpr uint16_t BUFFER_SIZE                     = 128U;

        static constexpr uint8_t  FILE_NAME_LEN_SD_LOG            = 10U;
        static constexpr uint8_t  FILE_NAME_LEN_MC_LOG            = 10U;
        static constexpr uint8_t  FILE_NAME_LEN_COM_LOG           = 11U;
        static constexpr uint8_t  FILE_NAME_LEN_MTR_LOG           = 11U;

        static constexpr char     FILE_NAME_SD_LOG[]              = "SD_LOG.TXT";
        static constexpr char     FILE_NAME_MC_LOG[]              = "MC_LOG.TXT";
        static constexpr char     FILE_NAME_COM_LOG[]             = "COM_LOG.TXT";
        static constexpr char     FILE_NAME_MTR_LOG[]             = "MTR_LOG.TXT";

        static constexpr char     SD_OPEN_ERROR_TEXT[]            = "failed to open: ";
        static constexpr char     SD_CLOSE_ERROR_TEXT[]           = "failed to close: ";
        static constexpr char     SD_READ_ERROR_TEXT[]            = "failed to read: ";
        static constexpr char     SD_WRITE_ERROR_TEXT[]           = "failed to write: ";
        static constexpr char     SD_MKDIR_ERROR_TEXT[]           = "failed to create dir: ";
        static constexpr char     SD_RMDIR_ERROR_TEXT[]           = "failed to remove dir: ";

        static constexpr char     SD_CREATE_SD_LOG_EVENT_TEXT[]   = "sd_log.txt created";
        static constexpr char     SD_CREATE_MC_LOG_EVENT_TEXT[]   = "mc_log.txt created";
        static constexpr char     SD_CREATE_COM_LOG_EVENT_TEXT[]  = "com_log.txt created";
        static constexpr char     SD_CREATE_MTR_LOG_EVENT_TEXT[]  = "mtr_log.txt created";

        static constexpr char     SD_CREATE_MC_LOG_ERROR_TEXT[]   = "failed to create mc_log.txt";
        static constexpr char     SD_CREATE_COM_LOG_ERROR_TEXT[]  = "failed to create com_log.txt";
        static constexpr char     SD_CREATE_MTR_LOG_ERROR_TEXT[]  = "failed to create mtr_log.txt";

        static constexpr char     SD_LOG_EVENT[]                  = "### sd_event ";
        static constexpr char     SD_LOG_ERROR[]                  = "### sd_error ";
        static constexpr char     SD_LOG_TIME_STAMP_LABEL[]       = "@ t=";
        static constexpr char     NEWLINE[]                       = "\n";
        static constexpr char     ARROW[]                         = " -> ";

        File        sd_log;
        File        mc_log;
        File        com_log;
        File        mtr_log;
        String      write_buffer;
        String      read_buffer;
        uint16_t    active_write_size;
        uint32_t    uptime_counter_update_time = 0U;
        uint32_t    uptime_counter_update_period = 1000U;
        uint32_t    uptime_count = 0U;
        
        void sd_log_append(const char* arg_entry_type, const char* arg_event_description);
        uint32_t uptime_counter_get_count();
        
  
};
