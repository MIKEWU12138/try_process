/*
 * File: DCSN_subsystem_integrated_data.c
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

#include "DCSN_subsystem_integrated.h"
#include "DCSN_subsystem_integrated_private.h"

/* Invariant block signals (auto storage) */
const ConstB_DCSN_subsystem_integra_T DCSN_subsystem_integrate_ConstB =
{
  0.0F,                                /* '<S86>/Constant' */
  200.0F,                              /* '<S86>/Constant2' */
  0.0F,                                /* '<S84>/Constant' */
  200.0F                               /* '<S84>/Constant2' */
};

/* Constant parameters (auto storage) */
const ConstP_DCSN_subsystem_integra_T DCSN_subsystem_integrate_ConstP =
{
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S42>/Logic'
   *   '<S43>/Logic'
   *   '<S190>/Logic'
   */
  {
    0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0
  }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
