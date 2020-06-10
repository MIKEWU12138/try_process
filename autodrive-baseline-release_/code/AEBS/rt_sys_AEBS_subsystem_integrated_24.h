/*
 * File: rt_sys_AEBS_subsystem_integrated_24.h
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

#ifndef RTW_HEADER_rt_sys_AEBS_subsystem_integrated_24_h_
#define RTW_HEADER_rt_sys_AEBS_subsystem_integrated_24_h_
#ifndef AEBS_subsystem_integrated_COMMON_INCLUDES_
# define AEBS_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* AEBS_subsystem_integrated_COMMON_INCLUDES_ */

#include "AEBS_subsystem_integrated_types.h"

/* Block states (auto storage) for system '<S85>/Chart' */
typedef struct
{
  uint32_T temporalCounter_i1;         /* '<S85>/Chart' */
  uint8_T is_active_c4_AEBS_subsystem_int;/* '<S85>/Chart' */
  uint8_T is_c4_AEBS_subsystem_integrated;/* '<S85>/Chart' */
}
DW_Chart_AEBS_subsystem__jbmw_T;

extern void AEBS_subsystem__Chart_k51z_Init(DW_Chart_AEBS_subsystem__jbmw_T
  *localDW);
extern void AEBS_subsystem_integ_Chart_fmkq(boolean_T rtu_in, uint32_T
  rtu_delay_time, boolean_T *rty_y, uint8_T *rty_state,
  DW_Chart_AEBS_subsystem__jbmw_T *localDW);

#endif                                 /* RTW_HEADER_rt_sys_AEBS_subsystem_integrated_24_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
