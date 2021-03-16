#ifndef __TUYA_DP_PROCESS_H__
#define __TUYA_DP_PROCESS_H__

#include "tuya_cloud_com_defs.h"
#include "tuya_cloud_types.h"

/* DP define */
typedef UINT8_T ALCOHOL_SENSOR_DP_T;
#define DP_ID_ALCOHOL_VALUE 101

typedef struct  {
    ALCOHOL_SENSOR_DP_T dp_id_alcohol_value;

    UINT16_T alcohol_value;
}ALCOHOL_SENSOR_STATE_T;

extern ALCOHOL_SENSOR_STATE_T alcohol_sensor_state;

VOID_T hw_report_all_dp_status(VOID_T);
VOID_T deal_dp_proc(IN CONST TY_OBJ_DP_S *root);

#endif /* __TUYA_DP_PROCESS */