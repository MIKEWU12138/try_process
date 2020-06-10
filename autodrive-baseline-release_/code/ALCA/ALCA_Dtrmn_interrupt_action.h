/*
 * File: ALCA_Dtrmn_interrupt_action.h
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

#ifndef RTW_HEADER_ALCA_Dtrmn_interrupt_action_h_
#define RTW_HEADER_ALCA_Dtrmn_interrupt_action_h_
#ifndef ALCA_subsystem_integrated_COMMON_INCLUDES_
# define ALCA_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* ALCA_subsystem_integrated_COMMON_INCLUDES_ */

#include "ALCA_subsystem_integrated_types.h"

extern void ALC_ALCA_Dtrmn_interrupt_action(boolean_T rtu_touched_new_lane,
  boolean_T rtu_interrupt, const ALCA_MPFU_Info *rtu_mpfu_info, const
  ALCA_VehState *rtu_veh_state, EnumALCA_interrupt_type rtu_interrupt_type,
  const real32_T rtu_RelativeSpeed_X[15], const real32_T rtu_VehSpeed_Y[8],
  const real32_T rtu_RangeFront_V[120], const real32_T rtu_RangeRear_V[120],
  uint8_T *rty_interrupt_action);

#endif                                 /* RTW_HEADER_ALCA_Dtrmn_interrupt_action_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
