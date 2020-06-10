/*
 * File: ALCA_subsystem_integrated_data.c
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

#include "ALCA_subsystem_integrated.h"
#include "ALCA_subsystem_integrated_private.h"

/* Invariant block signals (auto storage) */
const ConstB_ALCA_subsystem_integra_T ALCA_subsystem_integrate_ConstB =
{
  8U,                                  /* '<S50>/Data Type Conversion1' */
  4U,                                  /* '<S50>/Data Type Conversion4' */
  2U,                                  /* '<S50>/Data Type Conversion3' */
  1U,                                  /* '<S50>/Bitwise Operator3' */
  1U,                                  /* '<S49>/Data Type Conversion' */
  EnumALCA_inform_reason_low_cipv      /* '<S19>/Constant1' */
};

/* Constant parameters (auto storage) */
const ConstP_ALCA_subsystem_integra_T ALCA_subsystem_integrate_ConstP =
{
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S24>/Logic'
   *   '<S56>/Logic'
   *   '<S57>/Logic'
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
