/*
 * File: rt_sys_AEBS_subsystem_integrated_30.h
 *
 * Code generated for Simulink model 'AEBS_subsystem_integrated'.
 *
 * Model version                  : 1.3091
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 16:35:01 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Safety precaution
 *    3. Execution efficiency
 *    4. RAM efficiency
 *    5. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rt_sys_AEBS_subsystem_integrated_30_h_
#define RTW_HEADER_rt_sys_AEBS_subsystem_integrated_30_h_
#ifndef AEBS_subsystem_integrated_COMMON_INCLUDES_
# define AEBS_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* AEBS_subsystem_integrated_COMMON_INCLUDES_ */

#include "AEBS_subsystem_integrated_types.h"

/* Block states (auto storage) for system '<S79>/Stop_Moving_Estimation' */
typedef struct
{
  uint32_T temporalCounter_i1;         /* '<S79>/Stop_Moving_Estimation' */
  uint8_T is_active_c5_AEBS_subsystem_int;/* '<S79>/Stop_Moving_Estimation' */
  uint8_T is_c5_AEBS_subsystem_integrated;/* '<S79>/Stop_Moving_Estimation' */
}
DW_Stop_Moving_Estimation_AEB_T;

extern void AEB_Stop_Moving_Estimation_Init(boolean_T *rty_vehicle_standstill,
  DW_Stop_Moving_Estimation_AEB_T *localDW);
extern void AEBS_sub_Stop_Moving_Estimation(real32_T rtu_speed_act, real32_T
  rtu_standstill_threshold_speed, real32_T rtu_delta_standstill_threshold_,
  uint32_T rtu_speed_debounce_time, boolean_T *rty_vehicle_standstill,
  DW_Stop_Moving_Estimation_AEB_T *localDW);

#endif                                 /* RTW_HEADER_rt_sys_AEBS_subsystem_integrated_30_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
