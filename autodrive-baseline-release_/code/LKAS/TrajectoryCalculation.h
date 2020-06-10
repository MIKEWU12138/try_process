/*
 * File: TrajectoryCalculation.h
 *
 * Code generated for Simulink model 'LKAS_subsystem_integrated'.
 *
 * Model version                  : 1.102
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 11:05:35 2020
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

#ifndef RTW_HEADER_TrajectoryCalculation_h_
#define RTW_HEADER_TrajectoryCalculation_h_
#include <math.h>
#ifndef LKAS_subsystem_integrated_COMMON_INCLUDES_
# define LKAS_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LKAS_subsystem_integrated_COMMON_INCLUDES_ */

#include "LKAS_subsystem_integrated_types.h"

/* Block states (auto storage) for system '<S243>/Chart' */
typedef struct
{
  boolean_T flag;                      /* '<S243>/Chart' */
}
DW_Chart_LKAS_subsystem_integ_T;

extern void LKAS_subsystem_integ_Chart_Init(boolean_T *rty_out,
  DW_Chart_LKAS_subsystem_integ_T *localDW);
extern void LKAS_subsystem_integrated_Chart(boolean_T rtu_in, boolean_T
  rtu_init_val, boolean_T *rty_out, DW_Chart_LKAS_subsystem_integ_T *localDW);
extern void LKAS_subsystem_integrat_calc_dt(real32_T rtu_am, real32_T rtu_a0,
  real32_T rtu_ae, real32_T rtu_dv, real32_T *rty_dt);
extern void LKAS_subsystem_integ_UseDefault(boolean_T *rty_TrajectoryFound,
  real32_T rty_ITC_dt[2], real32_T rty_ITC_cp[8], real32_T
  *rty_MaxLateralAcceleration, real32_T *rty_MaxLateralJerk);
extern void LKAS_TrajectoryCalculation_Init(void);
extern void LKAS_subs_TrajectoryCalculation(void);

#endif                                 /* RTW_HEADER_TrajectoryCalculation_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
