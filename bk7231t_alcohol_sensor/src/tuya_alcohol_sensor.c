#include "uni_log.h"
#include "tuya_gpio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "uni_thread.h"

#include "app_adc.h"
#include "tuya_alcohol_sensor.h"
#include "tuya_dp_process.h"

USHORT_T alcohol_adc_value;

VOID_T get_alcohol_value_task(VOID_T)
{
    while(1) {
        get_adc_value(&alcohol_adc_value);
        PR_NOTICE("alcohol_adc_value:%d", alcohol_adc_value);
        alcohol_sensor_state.alcohol_value = alcohol_adc_value;
        hw_report_all_dp_status();

        tuya_hal_system_sleep(1000);
    }
}

VOID_T alcohol_sensor_init(VOID_T)
{
    adc_init();

    

    tuya_hal_thread_create(NULL, "get value", 512 * 4, TRD_PRIO_2, get_alcohol_value_task, NULL);

}
