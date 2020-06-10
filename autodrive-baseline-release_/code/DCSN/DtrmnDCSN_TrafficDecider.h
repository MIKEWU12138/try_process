/*
 * File: DtrmnDCSN_TrafficDecider.h
 *
 * Code generated for Simulink model 'DCSN_subsystem_integrated'.
 *
 * Model version                  : 1.602
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:40:58 2020
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

#ifndef RTW_HEADER_DtrmnDCSN_TrafficDecider_h_
#define RTW_HEADER_DtrmnDCSN_TrafficDecider_h_
#include <math.h>
#ifndef DCSN_subsystem_integrated_COMMON_INCLUDES_
# define DCSN_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* DCSN_subsystem_integrated_COMMON_INCLUDES_ */

#include "DCSN_subsystem_integrated_types.h"
#include "rt_nonfinite.h"

/* Block signals for system '<S78>/If Action Subsystem' */
typedef struct
{
  real32_T Divide2;                    /* '<S103>/Divide2' */
}
B_IfActionSubsystem_DCSN_subs_T;

/* Block states (auto storage) for system '<S78>/If Action Subsystem' */
typedef struct
{
  real32_T Delay_DSTATE;               /* '<S103>/Delay' */
  uint8_T icLoad;                      /* '<S103>/Delay' */
}
DW_IfActionSubsystem_DCSN_sub_T;

extern void DCSN_sub_IfActionSubsystem_Init(DW_IfActionSubsystem_DCSN_sub_T
  *localDW);
extern void DCSN_subsyste_IfActionSubsystem(real32_T rtu_timegap, real32_T
  rtu_para, real32_T rtu_para_ldlm, real32_T rtu_para_dgjl, real32_T
  rtu_para_lj5q, real32_T rtu_para_i1xy, real32_T rtu_para_pnkv, real32_T
  rtu_step_size, const real32_T rtu_sample_point[8], real32_T *rty_avg_curvature,
  B_IfActionSubsystem_DCSN_subs_T *localB, DW_IfActionSubsystem_DCSN_sub_T
  *localDW);
extern void DCSN_subsyst_IfActionSubsystem1(real32_T *rty_largest_curvature);
extern void D_DtrmnDCSN_TrafficDecider_Init(void);
extern void DCSN_s_DtrmnDCSN_TrafficDecider(void);

#endif                                 /* RTW_HEADER_DtrmnDCSN_TrafficDecider_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
