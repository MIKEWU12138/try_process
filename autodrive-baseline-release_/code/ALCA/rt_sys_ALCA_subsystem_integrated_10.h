/*
 * File: rt_sys_ALCA_subsystem_integrated_10.h
 *
 * Code generated for Simulink model 'ALCA_subsystem_integrated'.
 *
 * Model version                  : 1.6591
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:34:22 2020
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

#ifndef RTW_HEADER_rt_sys_ALCA_subsystem_integrated_10_h_
#define RTW_HEADER_rt_sys_ALCA_subsystem_integrated_10_h_
#ifndef ALCA_subsystem_integrated_COMMON_INCLUDES_
# define ALCA_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* ALCA_subsystem_integrated_COMMON_INCLUDES_ */

#include "ALCA_subsystem_integrated_types.h"

/* Block states (auto storage) for system '<S22>/Chart' */
typedef struct
{
  uint16_T temporalCounter_i1;         /* '<S22>/Chart' */
  uint8_T is_active_c8_ALCA_subsystem_int;/* '<S22>/Chart' */
  uint8_T is_c8_ALCA_subsystem_integrated;/* '<S22>/Chart' */
}
DW_Chart_ALCA_subsystem_integ_T;

extern void ALCA_subsystem_integ_Chart_Init(DW_Chart_ALCA_subsystem_integ_T
  *localDW);
extern void ALCA_subsystem_inte_Chart_Reset(DW_Chart_ALCA_subsystem_integ_T
  *localDW);
extern void ALCA_subsystem_integrated_Chart(boolean_T rtu_in, real32_T
  rtu_delay_time, boolean_T *rty_y, uint8_T *rty_state,
  DW_Chart_ALCA_subsystem_integ_T *localDW);

#endif                                 /* RTW_HEADER_rt_sys_ALCA_subsystem_integrated_10_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
