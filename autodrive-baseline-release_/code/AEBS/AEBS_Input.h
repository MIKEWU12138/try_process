/*
 * File: AEBS_Input.h
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

#ifndef RTW_HEADER_AEBS_Input_h_
#define RTW_HEADER_AEBS_Input_h_
#ifndef AEBS_subsystem_integrated_COMMON_INCLUDES_
# define AEBS_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* AEBS_subsystem_integrated_COMMON_INCLUDES_ */

#include "AEBS_subsystem_integrated_types.h"

/* Block states (auto storage) for system '<S18>/Chart' */
typedef struct
{
  uint16_T temporalCounter_i1;         /* '<S18>/Chart' */
  uint8_T is_active_c10_AEBS_subsystem_in;/* '<S18>/Chart' */
  uint8_T is_c10_AEBS_subsystem_integrate;/* '<S18>/Chart' */
}
DW_Chart_AEBS_subsystem_integ_T;

extern void AEBS_subsystem_integ_Chart_Init(DW_Chart_AEBS_subsystem_integ_T
  *localDW);
extern void AEBS_subsystem_integrated_Chart(boolean_T rtu_in, real32_T
  rtu_delay_time, boolean_T *rty_y, uint8_T *rty_state,
  DW_Chart_AEBS_subsystem_integ_T *localDW);
extern void AEBS_subsystem_inte_DividByZero(real32_T rtu_u, real32_T *rty_y);
extern void AEBS_subsystem__AEBS_Input_Init(void);
extern void AEBS_subsystem_AEBS_Input_Const(void);
extern void AEBS_subsystem_integ_AEBS_Input(void);

#endif                                 /* RTW_HEADER_AEBS_Input_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
